#include <iostream>
#include <string>

using namespace std;

class Base {
public:
	Base(int newVal = 0) : ptr(new int(newVal)) { cout << "In Base constructor, newVal = " << newVal << endl; }
	virtual ~Base() { 
		cout << "In Base Destructor" << endl; 
		delete ptr; 
	}
	Base(const Base& bo) : ptr(new int(*bo.ptr)) { cout << "In Base Copy Constructor." << endl;  }
	Base& operator=(const Base& bo);
	int getInt() const {
		return *ptr;
	}
	void setInt(int newVal) {
		*ptr = newVal;
	}
private:
	int* ptr;

};

Base& Base::operator=(const Base& bo) {
	cout << "In Base Assignment Operator." << endl;
	if (this == &bo) {
		return *this;
	}
	else {
		*ptr = *bo.ptr;
		return *this;
	}
}

class Derived : public Base {
public:
	Derived(double newDouble = 0) : dPtr(new double(newDouble)) { cout << "Derived's constructor." << endl; }
	~Derived() { 
		cout << "Derived's destructor." << endl;  
		delete dPtr; 
	}
	Derived(const Derived& rhs) : Base(rhs), dPtr(new double(*rhs.dPtr)) { cout << "Derived's copy control." << endl; }
	Derived& operator=(const Derived& rhs);
	double getDouble() const {
		return *dPtr;
	}
	void setDouble(double newDouble) {
		*dPtr = newDouble;
	}

private:
	double* dPtr;
};

Derived& Derived::operator=(const Derived& rhs) {
	cout << "Derived's assignment operator." << endl;
	if (this == &rhs) {
		return *this;
	}
	else {
		Base::operator=(rhs); // Calls Base Assignment Operator
		*dPtr = *rhs.dPtr;
		return *this;
	}
}
int main() {
	Derived d; // Prints out base constructor, then derived constructor, then derived destructor, then base destructor
	Base b;
	Derived d1;
	cout << "Calling assignment operator." << endl;
	b = d; // Base const, derived const, base const, base assignment, base destruc, derived destruc, base destruc
	d.setInt(100); // If you call derived assignment operator, you use deriveds assignment
					// But if you call Base's assignment inside derived's assignment, it changes value.
	d1 = d;

	Base* bPtr = new Derived;
	delete bPtr; // When Base destructor is not virtual, calls Base destructor only.
				// When it is virtual, it calls Base destructor and Derived destructor.
	// DESTRUCTOR. IS. ALWAYS. VIRTUAL.


	/*

	Copy Constructor:
	simpleClass a;
	simpleClass b(a);
	
	SimpleClass a;
	SimpleClass b = a;
	
	SimpleClass(const SimpleClass& rhs){
		p = new int;
		*p = *rhs.p;
	}

	SimpleClass& operator=(const SimpleClass& rhs){
		if (this == &rhs){
			return *this;
		}else{

		
	*/
}