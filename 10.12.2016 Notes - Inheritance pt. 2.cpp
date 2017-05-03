#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Member {
public:
	Member() {
		cout << "Member Default Constructor" << endl;
	}
};

class Base {
public:
	Base() {
		cout << "Base Default constructor" << endl;
	}
	Base(int n) {
		cout << "Base one argument constructor" << endl;
	}
	void BaseFunc() {
		cout << "Inside DerivedFunc." << endl;
	}
private:
	Member m;
};

class Derived : public Base {
public:
	Derived() {
		cout << "Derived Default Constructor." << endl;
	}
	Derived(double n) {
		cout << "Derived one argument constructor." << endl;
	}
	Derived(double n, int y) : Base(y) {
		cout << "Derived two argument constructor." << endl;
	}
	void BaseFunc() {
		cout << "Inside Derived's BaseFunc." << endl;
	}
	void DerivedFunc() {
		cout << "Inside DerivedFunc." << endl;
	}
private:
	Member m2;
};

class Pet {   // Base class, Super class, Parent class
public:
	Pet() : age(0) {}
	Pet(string newName) : name(newName), age(0) {}
	string getColor() const {
		return color;
	}
	string getName() const {
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
protected:
	string color;
private:
	string name;
	int age;

};

class Dog : public Pet { // Derived class, sub class, child class
public:
	Dog(string newName = "") : Pet(newName) { // rename(newName); ----> not good 
	}
	void speak() {
		cout << "Woof" << endl;
	}
	void setBreed(string newBreed) {
		breed = newBreed;
	}
	string getBreed() const {
		return breed;
	}
	void celebrateBirthday(); // OVERRIDE !!!
private:
	string breed;
};

void Dog::celebrateBirthday() {
	Pet::celebrateBirthday(); // Using Scope Resolution Operator to call Base class function
	if (getAge() >= 10) {     // Pet::getAge() optional because it's not being overridden? overrided?
		color = "Gray";       // Can also call Pet::paint("Gray") to change the color of the pet.
	}
}

int main() {
	Dog d;
	d.rename("Fido");

	cout << "Making a derived object." << endl;
	Derived d;
	// First calls base default constructor, THEN derived default constructor.
	// Because you inherited, a parent class constructor implicitly exists.
	cout << "Making a derived object with one parameter." << endl;
	Derived d2(2);
	// First calls base default constructor, THEN derived one parameter constructor.
	// Inherits Base constructor implicitly
	cout << "Making a derived object with two parameters, also initializing Base one param constructor." << endl;
	Derived d3(2, 3);
	// First calls Base one param constructor, THEN derived two Param constructor
	// Activates Base constructor with 2nd parameter

	Base baseObj;
	Derived derivedObj;
	baseObj = derivedObj;

	Base* basePtr = &derivedObj;
	// basePtr->DerivedFunc();		NOT ALLOWED!!!!
	basePtr->BaseFunc();         // Base pointer calls BASE baseFunc, not derived's baseFunc.
}

/*
is a - public inheritance
has a - private inheritance

Access:
		 Public		Private		Protected
Member     X          X             X
Derived    X          NO            X 
Outside    X          NO            NO

Constructors are never derived/inherited automatically

BASE
COMPOSITION
DERIVED

MEMBER
BASE
DERIVED

Base baseObj;
Derived derivedObj;
baseObj = derivedObj; SLICING. Derived contains more than base, so base cannot = all of derived.
							   Just takes what it can, and throws out the rest
derivedObj = baseObj; Not Allowed, right now.

Base* basePtr = &derivedObj;       Polymorphism, always allowed.
Derived* derivedPtr = &baseObj;    NEVER ALLOWED !!!!!!!!!!!!!!!

int x = 0;
double d = 5.5;
x = d;
*/

/*
Lab Notes:
1) Association
2) Composition
3) Inheritance (Is-A relationship)

UML Diagram
Association - drawn with a line, arrow pointing from derived to base
Composition - drawn with a line, with a diamond at the end, from derived to base

class Animal{
public:
	Animal(){}
	double getWeight() const{ return weight; }
private:
	double weight;
};

class Herbivore : public Animal{
public:

private:

};

class Carnivore : public Animal{
public:

private:

};

class Cow : public Herbivore{
public:
	Cow(string newColor, int w) : color(newColor), Animal(w){}
private:
	string color;
};

class Tiger : public Carnivore{
public:

private:

};

class className : specifier className

int main(){
	Cow cow(100, "White");
	Animal* animal = new Cow("White", 100);
	animal->eat(); // Actually prints out the eat from the Animal class. Dereferencing animal does not give you access to cow class.
	animal->eat(); // Will print the eat from the Cow class IF the eat function in the Animal class is VIRTUAL void eat(){}

	print(Animal animal){
	animal.eat();
	}

	print(cow); // Slicing, passing in a bigger class into a smaller parameter. Cow > Animal. Loses the rest of the cow, keeps the Animal part.

	print (Animal& animal){
	animal.eat();
	}
	print(cow); // Passing by reference, would still print out animal's eat, UNLESS animal's eat is virtual.

	Making a method in the class "pure virtual" (only one is needed) makes the class abstract, prevents the main from creating an object from that class
	virtual void eat() = 0; <-- pure virtual.
	If you dont override the function in the derived class, it also becomes a pure virtual class.

}
*/