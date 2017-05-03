#include <iostream>
#include <string>
#include <vector>

using namespace std;

class FAI {
public:
	FAI() : feet(new int(0)), inches(new double(0)) {}
	FAI(double newInches) : feet(new int(0)), inches(new double(newInches)) {
		normalize();
	}
	FAI(int newFeet, double newInches) : feet(new int(newFeet)), inches(new double(newInches)) {}
	double getInches() const {
		return (*feet) * 12 + *inches;
	}
	double getFeet() const {
		return (*feet) + (*inches) / 12;
	}
	virtual ~FAI() {
		delete feet;
		delete inches;
	}
	FAI(const FAI& rhs) : feet(new int(0)), inches(new double(0)) { *this = rhs; }
	FAI& operator=(const FAI& rhs);
	friend std::ostream& operator<<(std::ostream& os, const FAI& rhs);
	friend std::istream& operator>>(std::istream& is, FAI& rhs);
	FAI& operator+=(const FAI& rhs);
	FAI& operator-=(const FAI& rhs);
	FAI& operator*=(double amount);
	FAI& operator/=(double amount);
	FAI& operator%=(const FAI& rhs);
	FAI& operator++();
	FAI operator++(int);
	FAI& operator--();
	FAI operator--(int);
private:
	int* feet;
	double* inches;
	void normalize();
};

FAI& FAI::operator=(const FAI& rhs) {
	if (this == &rhs) {
		return *this;
	}
	*feet = *(rhs.feet);
	*inches = *(rhs.inches);
	return *this;
}

std::ostream& operator<<(std::ostream& os, const FAI& rhs) {
	os << *rhs.feet << "' " << *rhs.inches << "''" << endl;
	return os;
}
std::istream& operator>>(std::istream& is, FAI& rhs) {
	char junk;
	is >> *rhs.feet >> junk >> *rhs.inches >> junk;
	return is;
}

FAI& FAI::operator+=(const FAI& rhs) {
	*feet += *rhs.feet;
	*inches += *rhs.inches;
	normalize();
	return *this;
}

FAI& FAI::operator-=(const FAI& rhs) {
	*feet -= *rhs.feet;
	*inches -= *rhs.feet;
	normalize();
	return *this;
}

FAI& FAI::operator*=(double amount) {
	*inches = getInches() * amount;
	*feet = 0;
	normalize();
	return *this;
}

FAI& FAI::operator/=(double amount) {
	*inches = getInches() / amount;
	*feet = 0;
	normalize();
	return *this;
}

FAI& FAI::operator%=(const FAI& rhs) {
	*inches = fmod(getInches(), rhs.getInches());
	*feet = 0;
	normalize();
	return *this;
}

FAI operator+(const FAI& lhs, const FAI& rhs) {
	FAI temp = lhs;
	temp += rhs;
	return temp;
}
FAI operator-(const FAI& lhs, const FAI& rhs) {
	FAI temp = lhs;
	temp -= rhs;
	return temp;
}
FAI operator*(const FAI& lhs, int amount) {
	FAI temp = lhs;
	temp *= amount;
	return temp;
}
FAI operator/(const FAI& lhs, int amount) {
	FAI temp = lhs;
	temp /= amount;
	return temp;
}
FAI operator%(const FAI& lhs, const FAI& rhs) {
	FAI temp = lhs;
	temp %= rhs;
	return temp;
}

FAI& FAI::operator++() {
	(*inches)++;
	normalize();
	return *this;
}

FAI& FAI::operator--() {
	(*inches)--;
	normalize();
	return *this;
}

FAI FAI::operator++(int) {
	(*inches)++;
	normalize();
	return *this;
}

FAI FAI::operator--(int) {
	(*inches)--;
	normalize();
	return *this;
}

void FAI::normalize() {

}

int main() {

}

/*
class FeetAndInches (FAI)
1 pointer to an int
1 pointer to a double
Read from keyboard
+, -, *, /, %, 
Convert to inches
Convert to feet
++, --
output to screen ( F', I")
Constructors
Copy Constructor
Assignment Operator
Destructor
Normalize_private

*/