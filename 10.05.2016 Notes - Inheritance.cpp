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
	if (newSize < numOfElements) {
		numOfElements = newSize;
	}
	// else if (newSize == capacity) {      // Efficient, but has no use. Doesn't really do anything.
	// 	return;
	// }
	int* temp = new int[newSize];                  // creates new pointer to new array with new size
	for (int i = 0; i < numOfElements; i++) {
		temp[i] = data[i];                         // sets everything in data to the new array, temp.
	}
	delete[] data;                                 // deletes what data is pointing to
	data = temp;								   // makes data point to temp's address
	capacity = newSize;                            // changes capacity to the new size
	// After function, newSize gets deleted, temp gets deleted.
	// *data === data[0] 3 = signs means equivalence. NOT IN C++
	// Impossible to actually resize an array.
}

int main() {
	Person* pptr;
	pptr = new Person("Jack");
	Person p("Jill");

}

/*
Resize function changes where the object pointer is pointing to, not actually changing the array.
You won't know if you hit the end of your array or past the end of your array ?

Inheritance:
class Pet{   // Base class, Super class, Parent class
public:
	Pet() : age(0) {}
	Pet(string newName) : name(newName), age(0) {}
	string getColor() const{
		return color;
	}
	string getName() const{
		return name;
	}
	int getAge() const {
		return age;
	}
	void rename(string newName) {
		name = newName;
	}
	void paint(string newColor) {
		color = newColor;
	}
	void celebrateBirthday() {
		age++;
	}
private:
	string name;
	string color;
	int age;

};

class Dog: public Pet{ // Derived class, sub class, child class

};

int main(){
	Dog d;
	d.rename("Fido");
}

Association, Delegation, Composition:
Lab Section, Lab Worker, Student

*/