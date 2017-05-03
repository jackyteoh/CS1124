#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

// THIS IS A FUCKING CLASS
// GOT IT?
class AnObject {
public:
	// this has to be const primarily to indicate that it doesn't modify the given object
	void display() const {
		cout << "I'm constant!" << endl;
	}

	// this is a method
	void nonConstDisplay() {
		cout << "I'm also a constant" << endl;
	}
};

// if you notice here, it's being passed by const reference (the object)
// so calling a method on it has a high chance of changing the object
// by setting the method const, we're  telling the compiler that it's okayto do this!!!!!!
void display(const AnObject& constRefObject) {
	constRefObject.display();
}

// this doesn't have to be const
// passing by const reference for types that are not primitive (int, float, bool, char) is standard practice
// making copy = more work for the computers
// passing by reference is good, but it allows the value to be changed, so we pass it by const ref
// but we don't necessarily have to
// maybe we want to be able to change the value
// but if you do pass it as const ref, you can only call const methods on it

// this is a function
void displayTwo(AnObject& refObject, const int aNum, const string& aString) {
	refObject.nonConstDisplay();
	refObject.display();
}

int main() {
	// THIS IS A FUCKING INSTANCE OF A CLASS
	AnObject objectOne;
	display(objectOne);
	displayTwo(objectOne, 10, "string");

	// this is an instance of the int class
	//int aNum(10);
}

#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class FuckingClass {
public:
	// this is a constructor
	// : means initialization list
	// aka what the variables are assigned when you create the instance
	FuckingClass(int x) : x(x) {}

	void display() const {
		cout << x << endl;
	}
private:
	int x;
};

int main() {
	int x(10);
	int* p = &x; // ???
	cout << &x << endl;
	cout << *p << endl;

	/*
	FuckingClass anInstance;
	FuckingClass* aPointer = &anInstance;
	aPointer-> display();
	*/

	vector<FuckingClass*> aVector;
	// you're trying to add an int to a vector that only takes FuckingCLass pointers
	for (int i = 0; i < 10; i++) {
		// n o
		// newInstance = FuckingClass* aPointer
		// FuckingClass anotherInstance(10);
		//aVector.push_back(&anotherInstance);
		FuckingClass* aPointer = new FuckingClass(i);
		// what's the difference between
		int* const aPointer = new int(10);
		//and
		const int* aPointer = new int(10);
	}
	for (size_t i = 0; i < aVector.size(); i++) {
		cout << aVector[i] << endl;
	}

	vector<FuckingClass> anotherVector;
	for (int i = 0; i < 10; i++) {
		FuckingClass anotherInstance(i);
		anotherVector.push_back(anotherInstance);
	}

	for (FuckingClass& another : anotherVector) {
		another.display();
		cout << &another << endl;
	}
}

/*
Base object = Derived Object <- SLICING. Base not big enough to fit Derived
Base POINTER pointing to derived object will always call the base's function, not the derived function.
However, it will call the derived's function IF the base function is virtual.

class Base{
public:
	// void baseFunc() { cout << "Inside Base's BaseFunc" << endl; }
	virtual void baseFunc() { cout << "Inside Base's BaseFunc" << endl; }
};

class Derived : public Base{
public:
	void baseFunc() { cout << "Inside Derived's BaseFunc" << endl; }
};

int main(){
	Base* b;
	Derived d;
	b = &d;
	b.baseFunc(); -> WILL PRINT OUT BASE'S BASE FUNC. However, when baseFunc is virtual,
	b = &d;
	b.baseFunc(); -> WILL PRINT OUT DERIVED'S BASE FUNC.
}

ifs.clear(); -- clears (failed) flags
ifs.seekg(0); -- brings back to beginning of file

Array:
Created on the stack - must have a static size, must be initialized with a size.
Created on the heap - can have any size we want
int arr[5]; -> creates an array of ints with 5 elements
arr[0] = 100;
arr[1] = 101;
arr[2] = 102;
arr[3] = 103;
arr[4] = 104;
int* arr = new int[x]; <-- creating an array on the heap, with size of "x", any value.
arr[0] = 100;

delete[] arr; <-- when deleting arrays on the heap, signified with delete[]
INT_MAX = largest possible number you can store in an int.
INT_MIN = smallest possible number you can store in an int.

Three errors with pointers:

Dereferencing Null
int* x = nullptr;
*x = 100;
CANNOT DEREFERENCE NULL. THEREFORE CANNOT CHANGE VALUE OF X BY *X = 100;
x = new int(100); <-- this works.
if (x == nullptr) <-- testing to see if x is nullptr

Memory Leak / Dangling Pointers(?)
Pointer that points to some object created on the heap,
then that same pointer points to another object.
The first object cannot be accessed anymore, thus memory leak. (undeleted memory).
int* x = new int(100);
// to fix, delete x; Delete deletes what the pointer is POINTING to. frees up the space on the heap. doesn't delete the actual pointer.
x = new int(200);

Double Delete
int* x = new int(100);
delete x;
delete x; <- x was already deleted and cleared.

int* y = x;
delete x;
delete y; <-- the thing that y is pointing to, x, was already deleted. Cannot delete y AGAIN.

Pointer Arithmetic:
Pointer can point to an array.
int* x = new int[7];
for (int i = 0; i < 7; i++){
	x[i] = i*10;
}
int* y = x + 2;
cout << y[1]; 

[ 0 | 1 | 2 | 3 | 4 | 5 | 6 ]
After for loop:
[ 0 | 10 | 20 | 30 | 40 | 50 | 60 ]
  0   1    2    3    4    5    6 

int* y = x + 2 = x[0] + 2 = x[2] = y[0] = 20.
cout << y[1] = y[0] + 1 = y[1] = x[2] + 1 = x[3] = y[1] = 30.
*/