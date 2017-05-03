#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

}

/*
Inheritance pt. 3
TwoD Object (Center, Rotation, Color)
    - Rectangle (Length, Width)
		- Square
	- Circle (Diameter)
	- Triangle
		- Equilateral
		- Isosceles
		- Scalene

virtual void function() = 0; // PURE VIRTUAL FUNCTION.
No code for this function. We don't know how to do it, but it should be there.
Function exists in the base class
Pure Virtual Function makes the class an abstract class. Means you cannot create an instance/object for that class
Only way to access is to get a Base* pointing to a derived class that HAS overrided all pure virtual functions in the base class
If the derived class does not override the pure virtual function from the base class, it also makes the derived class an abstract class

TwoD Object -> draw is pure virtual
Quadrilateral -> draw is also pure virtual. draw would be ambiguous?
Do you have to restate that quadrilateral needs the pure virtual again or is it automatically inherited?

class BigInt{
private:
	int data;
public:
	// explicit BigInt(int x = 0) : data (x) {} EXPLICIT makes it so that it won't automatically create a BigInt with an int
	BigInt(int x = 0) : data(x){}
	BigInt operator+(const BigInt& rhs){ 
		return data + rhs.data; 
	}
	int getData() const { 
		return data; 
	}
};

BigInt operator-(const BigInt& lhs, const BigInt& rhs){
	return lhs.getData() - rhs.getData();
}

int main(){
BigInt a(100), b(200), c;
c = a + b; <-- You can do this by operator overloading
Member				   Non-Member
a.operator+(b)         operator+(a, b)
c = a + b;
c = a + 5; // Member
c = 5 + a; // Non-Member Only

c = a - 5; // Non-Member works
c = 5 - a; // Non-Member works
}

operators:        + - = == * / % != > < >= <= >> << . ++ -- [] 

Operators that CANNOT be overloaded:
sizeof 
. operator
? :  (conditional)
::
.*

Operators which MUST be members:
=
[]

Operators that cannot (easily) be overloaded as members:
>>
<<
cout << a 
Member operator << would have to be a member of cout
cout.operator<<(a);
*/