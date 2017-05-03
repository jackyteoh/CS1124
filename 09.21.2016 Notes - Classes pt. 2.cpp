#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

class Card { // if functions inside the class are more than 2 lines, write them outside the class.
public:
	Card(); // Constructor (A default constructor because it takes no parameters)
	Card(char newSuit, int newValue); // Constructor
	int getValue() const {
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

class DeckOfCards {
public:
	DeckOfCards(int numOfCards = 52) : originalNumber(numOfCards) { // Member initialization list(?)
		shuffle();
	} // Default AND one argument constructor
	void shuffle();
	Card deal();
	int remaining() const {
		return cards.size();
	}
private:
	int originalNumber;
	vector<Card> cards;
	// vector<bool> dealt;
};

void DeckOfCards::shuffle() {
	cards.clear();
	string suits = "DCHS";
	int cardNum = 0;
	while (cardNum < originalNumber) {
		Card temp(suits[(cardNum % 52)/13], (cardNum % 13) + 1);
		cards.push_back(temp);
		cardNum++;
	}
/*
	for (int i = 0; i < suits.size(); i++) { // iterates over the suits string, adds one of each suit to the deck
		for (int j = 1; j <= 13; j++) { // iterates over 1-13, adds it to deck 
			Card temp(suits[i], j);
			cards.push_back(temp); // adds one card of each suit of each value to the deck.
		}
	}
*/
}

Card DeckOfCards::deal() {
	int num = rand() % cards.size(); // sets num equal to number in range of deck size
	Card retVal = cards[num]; // sets variable retVal equal to index of the deck
	cards[num] = cards[cards.size() - 1]; // sets index to the last card in the deck
	cards[cards.size() - 1] = retVal; // not really necessary
	cards.pop_back(); // removes last card in the deck.
	return retVal;
}

int main() {
	Card c;
	// cout << c.value << endl;     Encapsulation, trying to access private values. CANNOT DO.
	cout << c.getValue() << endl; // Will be Ace of Spades because no parameters (Default Constructor was called)
	Card other('H', 10);
	cout << other.getSuit() << " " << other.getValue() << endl; // Will be H 10 because constructor with parameters

	DeckOfCards d;
	srand(time(NULL));
	while (d.remaining() != 0) {
		Card temp = d.deal();
		cout << temp.getSuit() << "/ " << temp.getValue() << endl;
	}
}

/*
Pre/Post Incrementation:

int x = 5;
int y;
y = x++;              Stores/Returns ORIGINAL value of x into y (5)
cout << x << endl;    x = 6
cout << y << endl;    y = 5

int x = 5;
int y;
y = ++x;              Stores/Returns NEW value of x into y (6)
cout << x << endl;    x = 6
cout << y << endl;    y = 6


09.23.2016 Lab Notes:
Struct is by default public
Classes are by default private

Constructors:
1) No return types
2) Same name as the class name
3) Make constructors public

*/