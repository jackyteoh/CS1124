#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Person {
	string name;
	Person* spouse;
public:
	// Person* spouse; // Not a good idea
	Person(string newName = " ") : name(newName), spouse(nullptr) {}
	void setName(string newName) {
		name = newName;
	}
	string getName() const {
		return name;
	}
	bool marry(Person& p);
	bool isMarried() const {
		return spouse != nullptr;
	}
	void divorce();
};

bool Person::marry(Person& p) {
	// if (p == *this)          // This is not okay. Can't compare objects, but can compare pointers (to addresses)
								// Comparing pointers tell you if they're the same person, they can have the same name.
	if (&p == this) {
		return false;           // YOU CANNOT MARRY YOURSELF.
	}
	if (spouse != nullptr) {
		return false;           // Already married!
	}
	if (p.spouse != nullptr) {
		return false;           // Spouse is already married !
	}
	spouse = &p;
	p.spouse = this;            // Points p.spouse BACK to p
	return true;
}

void Person::divorce() {
	if (spouse) { // if (spouse != nullptr)
		spouse->spouse = nullptr;   // Spouse pointing to spouse pointer becomes nullptr
		(*spouse).spouse = nullptr; // This is dereferencing nullptr. 
		spouse = nullptr;           // Then 
	}
}

class DynArray {
public:
	DynArray() : data(new int[5]), capacity(5), numOfElements(0) {}
	void push_back(int newValue);
	int pop_back();
	void resize(int newSize);
	int size() const {
		return numOfElements;
	}
	int getAtPosition(int index) {
		return data[index];
	}
private:
	int numOfElements;
	int capacity;
	int* data;
};

void DynArray::push_back(int newValue) {
	if (numOfElements == capacity) { // no more room
		resize(numOfElements * 2);
	}
	data[numOfElements++] = newValue;
}

int DynArray::pop_back() {
	if (numOfElements > 0) {
		return data[--numOfElements];
	}
	return 0;                       // ?????????? Ask a stupid question, get a stupid answer
}

void DynArray::resize(int newSize) {

}

int main() {
	Person* pptr;
	pptr = new Person("Jack");
	Person p("Jill");

}

/*
Left side of the arrow operator must be a pointer.
Right side of the arrow must be a member function.
Every object of every class has a special pointer called "this"
"This" is a pointer to the calling object.
Jack.marry(Jill)
this pointer points to Jack object
Jill.marry(Jack)
this pointer points to Jill object
This will point to the left side of the . operator.

Jack.divorce()
this = Jack
Jack's spouse points to Jill's spouse pointer.
Sets Jill's spouse pointer to nullptr (Deletes Jack in Jill object, Jill no longer pointing to Jack)
Then sets Jack's spouse pointer to nullptr (Not pointing to Jill anymore)
*/

/*
const int* ptr = new int(17);
int* const ptr2 = new int(23);
const int* const ptr3 = new int(42);

Placement new: Memory Banks

Virtual Inheritance:
class Animal{
public:
	Animal::breathe();
	virtual Animal::live();
}

class FinnedAnimal:virtual public Animal{
	FinnedAnimal::Breathe();
	Animal::breathe();
};

class Mammal: virtual public Animal{
	Mammal::breathe();
	Animal::breathe();
};

class Whale: Mammal, FinnedAnimal { // Virtual inheritance is defaultly inherited
	Whale.breathe(); AMBIGUITY. calls both FinnedAnimal and Mammal breathe if it inherits from both.
	Animal::breathe();
};

class Base{
public:
	Base(int){}
};

class Derived : (virtual public) Base{
public:
	Derived() : Base(42) {}
	Base::Base(int);
};

class SubDerived : Derived{
public:
	SubDerived() : (Derived::Base(36)) {}
};

class Base{
public:
void a();
void b();
virtual void c();

};

class Der:Base{
public:
void c();

};

Base* b;
Der d;
b = &d;
b->c();
b->a();

kvm237@nyu.edu
*/