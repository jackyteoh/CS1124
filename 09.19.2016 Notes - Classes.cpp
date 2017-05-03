#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Card { // if functions inside the class are more than 2 lines, write them outside the class.
public:
	Card(); // Constructor (A default constructor because it takes no parameters)
	Card(char newSuit, int newValue); // Constructor
	int getValue() const{
		return value;
	}
	char getSuit() const;
	bool setValue(int newVal);
private:
	char suit; // D, C, H, S
	int value; // J = 11, Q = 12, K = 13, A = 1
};

Card::Card() { // Default constructor
	value = 1;
	suit = 'S';
}

Card::Card(char newSuit, int newValue) {
	if (newSuit != 'D' && newSuit != 'C' && newSuit != 'H' && newSuit != 'S') {
		suit = 'S';
	}
	else {
		suit = newSuit;
	}
	if (newValue > 13 || newValue <= 0) {
		newValue = 1;
	}
	else {
		value = newValue;
	}
}

bool Card::setValue(int newValue) { // return is FAIL flag
	if (newValue <= 13 && newValue > 0) {
		value = newValue;
		return false;
	}
	return true;
}

char Card::getSuit() const { // getSuit function from Card class. Qualified by dataType className::function 
	return suit;
}

int main() {
	Card c;
	// cout << c.value << endl;     Encapsulation, trying to access private values. CANNOT DO.
	cout << c.getValue() << endl; // Will be Ace of Spades because no parameters (Default Constructor was called)
	Card other('H', 10);
	cout << other.getSuit() << " " << other.getValue() << endl; // Will be H 10 because constructor with parameters

}

/*
Properties:
Vector of cards
Dealt/ Undealt

Actions:
Shuffle
Deal
Count
Remaining (Undealt)

Types of Functions:
Accessor functions : Getter functions 
Getter functions simply return the values

Mutator functions : Setter functions
Setter functions SET initial (?) values

:: is the Scope Resolution Operator
function const{} = calling object will remain const, will not change

char Card::getSuit() const{
return suit;
}

void func(const Card& c){
cout << c.getSuit();
c.setValue(100); <-- not const
*/