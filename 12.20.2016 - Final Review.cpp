// 12.20.2016 Final Review
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
#include <list>
#include <fstream>
#include <set>
#include <map>

using namespace std;

// Classes
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
		Card temp(suits[(cardNum % 52) / 13], (cardNum % 13) + 1);
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






/// Pointers

//Pointer does not store the something / value of the integer of the thing it's pointing to.
//It stores the memory address where we can find the data type it's pointing to.
/*
The heap is where we can put things that need to exist for a long time, or change.
Vector is made(? ) on the heap.Dynamic.
Variables on the heap cannot have names, instead we have pointers.
new = storage of data type on the heap. int pointer, create new int. double pointer, create new double, etc.
int* x = new int;
*x = 100;
cout << *x; prints out 100.
delete x; DELETE DOES NOT DO ANYTHING TO THE POINTER.
Instead, deletes what the pointer is pointing to(in this case, the int 100)
x = new int;

Three possible errors with pointers :

1) Dereferencing null(DEREF NULL), program crashes.Illegal to access 0x00000.
int* x = nullptr;
cout << *x;

2) Double Delete, also crashes program.
delete x;
delete x; <--Can't delete the same memory space again if it's already been deleted.
	int* x = new int;
int* y = x; <--points to what x is pointing to, the new int.
	delete x; <--deletes the new int that x is pointing to
	delete y; <--Only creating one new item on the heap, x = new int, so you only need to delete once.
	Therefore you can't delete y because it has already been deleted.

	3) Garbage on the heap / Memory leak :
	Memory leak = memory left on the heap that you can no longer access.
		int* x = new int; // garbage on the heap
	x = new int;
	delete x; <--the first new int is still there that we can't access. Therefore memory leak.
		Memory leaks don't happen instantaneously, happens over time, then crashes.

		int* p = new int(5);
	int* a = new int[3]; // creating an array with size of 3
	delete p;
	delete[] a;
	delete p; <-- double delete, program crashes
		p = nullptr;
	delete p; <--you can delete nullptr safely
		a[0] = 4; undefined, program space
		*p = 5; undefined behavior, don't dereference nullptr
*/

class Person{
public:
	string getName() const {
		return name;
	}
	Person(Person* newMom = nullptr, Person* newDad = nullptr, string newName = "")
		: mom(newMom), dad(newDad), name(newName) {}
	string getMomName() const {
		//return (*mom), name;     Access mom object, gets name from mom object ? ? ?
		//	return (*mom).name;
		return mom->name;
	}
	string getDadName() const {
		return (*dad).name;
		return dad->name;
	}
private:
	int age;
	int height;
	Person* parents; 
	Person* mom;
	Person* dad;
	string name;
};

// Linked Lists
struct Node {
	Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
	int data;
	Node* next;
};

// Lab Question
void splice(Node* loc, Node* sub) {
	Node* subend;
	for (subend = sub; subend->next != nullptr; subend = subend->next) {
		subend->next = loc->next;
		loc->next = sub;
	}
}

// Lab Question
Node* find(Node* begin, Node* sub) {
	for (Node* i = begin; i != nullptr; i = i->next) {
		Node* result = i;
		for (Node* j = sub; i->data == j->data; j = j->next) {
			if (j->next == nullptr) {
				return result;
			}
			if (i->next == nullptr) {
				break;
			}
			if (i->next->data != j->next->data) {
				break;
			}
			i = i->next;
		}
	}
	return nullptr;
}

// (Midterm 3 Question Practice)
void removeEveryNth(Node* head, size_t n) {
	for (size_t i = 1; head != nullptr; i++) {
		if (n == 1) {
			Node* temp = head;
			head = head->next;
			delete temp;
			continue;
		}
		if (i == n - 1) {
			Node* temp = head->next;
			head->next = head->next->next;
			delete temp;
			i = 0;
		}
		head = head->next;
	}
}

// Main
int main() {
	// Hello World (Basics)
	cout << "What is your temperature ? (C/F) " << endl;
	char letter;
	cin >> letter;
	if (letter == 'c' || letter == 'C') {
		double c;
		cout << "What C value? " << endl;
		cin >> c;
		double f = 9.0 / 5 * c + 32;
		cout << "That temperature is " << f << "F" << endl;
	}
	else {
		double f;
		cout << "What F value?" << endl;
		cin >> f;
		double c = 5.0 / 9 * (f - 32);
		cout << "That temperature is " << c << "C" << endl;
	}



	// Files
	ofstream outFile; // creates object
	cout << "What would you like to call the file?" << endl;
	string filename;
	cin >> filename;
	outFile.open(filename); // opens file through object
	ofstream anotherFile(filename); // creates object and opens the file

	outFile << "Hello World" << endl; // putting text in your new text file!

	ifstream inFile;
	inFile.open("input.txt");
	if (!inFile) {
		cout << "THE FILE DOES NOT EXIST!!" << endl;
		return 1;
	}

	char letter;
	while (inFile >> letter) {
		double value;
		inFile >> value;
		if (letter == 'C') {
			outFile << value << endl;
		}
		else if (letter == 'K') {
			outFile << value - 273 << endl;
		}
		else if (letter == 'F') {
			outFile << (value * 5 / 9) + 32 << endl;
		}
	}



	
	// Structs
	struct Date { // By default ALL public.
		int day;
		int month;
		int year;
	};

	struct Person { // Stores different data types
		string name;
		int height; // inches
		double weight;
		Date bday;
		vector<string> childrenNames;
	};

	Person p;
	p.name = "Daniel";
	p.height = 72;
	p.bday.month = 7; // Can access the bday object of the Date struct in the Person struct
	p.bday.day = 9;
	p.childrenNames.push_back("Aidan");
	p.childrenNames.push_back("Sofia");

	vector<Person> vp;
	vp.push_back(p);
	for (Person p : vp) {
		cout << p.name;
		if (p.childrenNames.size() > 0) {
			cout << '\t';
			for (string childName : p.childrenNames) {
				cout << childName << '\t';
			}
		}
	}

	for (int i = 0; i < vp.size(); i++) {
		cout << vp[i].name;
		if (p.childrenNames.size() > 0) {
			cout << ": ";
			for (int j = 0; j < p.childrenNames.size(); j++) {
				cout << vp[i].childrenNames[j] << ", ";
			}
		}
		cout << endl;
	}

	


	// Classes
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


	system("pause");
}

