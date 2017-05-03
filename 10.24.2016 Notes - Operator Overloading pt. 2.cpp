#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class BigInt {
private:
	int data;
public:
	// explicit BigInt(int x = 0) : data(x) {} EXPLICIT makes it so that it won't automatically create a BigInt with an int
	BigInt(int x = 0) : data(x) {}
	BigInt operator+(const BigInt& rhs) const {
		return data + rhs.data;
	}
	BigInt& operator-=(const BigInt& rhs) { // Returns an object REFERENCE, not the object
		data -= rhs.data;
		return *this;
	}
	BigInt operator*(const BigInt& rhs) const {
		return data * rhs.data;
	}
	bool operator<(const BigInt& rhs) const {
		return data < rhs.data;
	}
	bool operator>(const BigInt& rhs) const {
		return rhs < *this;
	}
	bool operator<=(const BigInt& rhs) const {
		return !(rhs < *this);
	}
	bool operator>=(const BigInt& rhs) const {
		return !(*this < rhs);
	}
	bool operator==(const BigInt& rhs) const {
		return !(*this < rhs || rhs < *this);
	}
	bool operator!=(const BigInt& rhs) const {
		return (*this < rhs || rhs < *this);
	}
	BigInt& operator++() { // Pre Increment (++a) operator, returning *this
		data++;
		return *this;
	}
	BigInt operator++(int) { // POST INCREMENT (a++) OPERATOR, TAKES IN AN INT.
		BigInt temp = *this;
		data++;
		return temp;
	}
	int getData() const {
		return data;
	}
	// Square brackets operator overloader MUST be a member of the class
	int operator[](int index) const {
		return data;
	}
	int operator[](int index) {
		return data;
	}
	friend ostream& operator<<(ostream& os, const BigInt& rhs);
	friend istream& operator>>(istream& is, BigInt& rhs);
};

ostream& operator<<(ostream& os, const BigInt& rhs) { // streams are ALWAYS passed by reference. Act of reading/writing from the stream actually changes the stream
													  // returns cout
													  // ((cout << a) << endl);
													  // os << rhs.data << endl;      can't access "data", not a member operator overload UNLESS ITS A FRIEND
													  // "If it's your friend it can touch your privates"
	os << rhs.data << endl;
	return os;
}

istream& operator>>(istream& is, BigInt& rhs) { // BigInt& rhs not const because actually changing BigInt's data member
	is >> rhs.data;
	return is;
}

BigInt operator-(const BigInt& lhs, const BigInt& rhs) {
	// return lhs.getData() - rhs.getData();
	BigInt temp = lhs;
	temp -= rhs;
	return temp;
}

int main() {

}


//	operators:        +-= == */ % != > < >= <= >> << . ++ --[]
//
//	Operators that CANNOT be overloaded :
//				  sizeof
//					  . operator
//					  ? : (conditional)
//					  ::
//					  .*
//
//					  Operators which MUST be members :
//					  =
//					  []
//
//					  Operators that cannot(easily) be overloaded as members :
//				      >>
//					  <<
//					  cout << a
//					  Member operator << would have to be a member of cout
//					  cout.operator<<(a);
/*
a -= b
a = a - b
x = a-= b
C++ Precedence levels:
In CS associativity doesn't work, must be specified (Right to left, or left to right)
(a + b) + c = a + (b + c)
Assignment operator: right to left
x = y = z  is x = (y = z)  NOT  (x = y) = z
epsilon = eps the smallest value that can be stored in a float greater than 0
eps/2 = eps
eps/2 + eps/2 = eps
eps + eps = eps
(1 + eps) + eps =/= 1 + (eps + eps)
1 + 2eps       =/= 1 + eps
++++a = can do
a++++ = cannot do

If you return something that you create on the stack, you just return by value (BigInt)
If you return something that existed prior to your function, return by reference (BigInt&)
Because you're changing the thing that's existing ?

Using only less than operator
a < b  |  a < b
a > b  |  b < a               b is less than a = a is greater than b
a <= b |  !(b < a)            b is less than a is FALSE. that means that a has to be <= b
a >= b |  !(a < b)            a is less than b is FALSE. that means that b has to be <= a
a == b |  !(a < b || b < a)   if a < b or b < a is true, negates that. they are not equal. If either are false (a = b), then negates that, they are equal
a != b |  a < b || b < a      if a < b OR b < a, they are not equal.

a = 5;
x = a++; // a++ returns a COPY of x. returns by value. *this = 5;

x = ++a; // ++a returns by reference. return *this = 6;

++(++a) reference to a  CAN DO
(a++)++ value           CANNOT DO

POST increment operators needs an int as a parameter
PRE increment operators doesn't take any parameters
*/