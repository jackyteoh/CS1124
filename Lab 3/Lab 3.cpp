/*
Jacky Teoh - jt2908
09.23.2016
Rec 03 - Intro to Classes
rec 03.cpp
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Task 1 - Make a sandwich class with sandwich components.
class Sandwich {
public:
	// Task 2 - Display contents of a sandwich, body after class. 
	void displaySandwich() const;
	// Task 4 - Make a sandwich constructor (with member initialization)
	// Task 5 - Customizeable members. Default to the right. One to one.
	Sandwich(int newTomatoes = 2, int newCheese = 1, float newMustard = 0.5, float newMayo = 1, int newBread = 2)
		: bread(newBread), cheese(newCheese), mayo(newMayo), tomatoes(newTomatoes), mustard(newMustard) {}
	// Task 6 - "Getter" methods to find out amounts of certain ingredients
	int getBread() const {
		return bread;
	}
	int getCheese() const{
		return cheese;
	}
	float getMayo() const {
		return mayo;
	}
	int getTomatoes() const {
		return tomatoes;
	}
	float getMustard() const {
		return mustard;
	}
	// Task 7 - "Setter" methods to set new amounts to certain ingredients (Mutators)
	void setBread(int newerBread) {
		bread = newerBread;
	}
	void setCheese(int newerCheese) {
		cheese = newerCheese;
	}
	void setMayo(float newerMayo) {
		mayo = newerMayo;
	}
	void setTomatoes(int newerTomatoes) {
		tomatoes = newerTomatoes;
	}
	void setMustard(float newerMustard) {
		mustard = newerMustard;
	}
private:
	int bread;
	int cheese;
	float mayo;
	int tomatoes;
	float mustard;
};

// Task 2 - Display contents of a sandwich.
void Sandwich::displaySandwich() const {
	cout << bread << " slices of bread" << endl;
	cout << cheese << " slice(s) of cheese" << endl;
	cout << mayo << " ounce(s) of mayonaise" << endl;
	cout << tomatoes << " slice(s) of tomatoes" << endl;
	cout << mustard << " ounce(s) of mustard" << endl;
}

// Task 10 - Make the sandwich truck class
class SandwichTruck {
public:
	vector<Sandwich> sandwiches;
	void insertSandwich(Sandwich& y);
	void checkBeforeLeaving();
};

// Takes in a Sandwich as a parameter, and pushes it back into the sandwiches vector.
void SandwichTruck::insertSandwich(Sandwich& y) {
	sandwiches.push_back(y);
}

// Prints out the sandwich contents of the truck by iterating over the sandwiches vector,
// and then displaying each sandwich inside the vector.
void SandwichTruck::checkBeforeLeaving() {
	cout << "The contents of the truck are: " << endl;
	for (Sandwich& x : sandwiches){ // using ranged for function. 
		cout << endl << "Customer's sandwich: " << endl;
		x.displaySandwich();
	}
}

int main() {
	// Task 11 - Customer scenario
	Sandwich customer1;
	Sandwich customer2;
	Sandwich customer3;
	Sandwich customer4;

	SandwichTruck deliveryTruck;

	// Customer 1 gets a regular sandwich.
	cout << "Customer 1's sandwich has: " << endl;
	customer1.displaySandwich();

	// Customer 2 changes their mind about the mustard, so set the mustard amount to 0.
	customer2.setMustard(0.0);
	cout << endl << "Customer 2's sandwich has: " << endl;
	customer2.displaySandwich(); 

	// Customer 3 wants an extra slice of cheese, so set the cheese amount to 2.
	customer3.setCheese(2);
	cout << endl << "Customer 3's sandwich has: " << endl;
	customer3.displaySandwich();

	// Customer 4 gets a regular sandwich.
	cout << endl << "Customer 4's sandwich has: " << endl;
	customer4.displaySandwich();

	// Pushing back each customer's sandwich into the delivery truck.
	deliveryTruck.insertSandwich(customer1); 
	deliveryTruck.insertSandwich(customer2);
	deliveryTruck.insertSandwich(customer3);
	deliveryTruck.insertSandwich(customer4);

	// Checking the truck before it leaves, calling the checkBeforeLeaving function
	// Which prints out each sandwich that got pushed into the vector of sandwiches.
	cout << endl << "Check the delivery truck before it leaves: " << endl;
	deliveryTruck.checkBeforeLeaving();

	// Checking the amount of mustard in Customer's 2 sandwich because they requested no mustard by calling the getMustard function.
	cout << endl << "Check the amount of mustard in Customer 2's sandwich: " << endl;
	cout << "Customer 2's sandwich has " << customer2.getMustard() << " ounce(s) of mustard." << endl << endl;

	system("pause");
}