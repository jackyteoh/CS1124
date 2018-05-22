/*
Jacky Teoh - jt2908
CS 1124 - Rec 09 : Copy Control
11.04.2016
rec 09.cpp
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Position {
public:
	Position(const string& aTitle, double aSalary)
		: title(aTitle), salary(aSalary) {}
	string getTitle() const { return title; }
	double getSalary() const { return salary; }
	void changeSalaryTo(double d) { salary = d; }
private:
	string title;
	double salary;
};

class Entry {
public:
	Entry(const string& aName, unsigned aRoom, unsigned aPhone, Position& aPosition)
		: name(aName), room(aRoom), phone(aPhone), pos(&aPosition) {
	}
	friend ostream& operator<<(ostream& os, const Entry& e) {
		os << e.name << '\n'
			<< e.room << '\n'
			<< e.phone;
		return os;
	}
	string getName() const {
		return name;
	}
	unsigned getPhone() const {
		return phone;
	}
private:
	string name;
	unsigned room;
	unsigned phone;
	Position* pos;
}; // Entry

class Directory {
public:
	Directory()
		: capacity(2), size(0), entries(new Entry*[2])
	{
		for (size_t i = 0; i < capacity; i++) {
			entries[i] = NULL;
		}
	}

	void add(const string& name, unsigned room, unsigned ph, Position& pos) {
		if (size == capacity) {
			Entry** newEntries = new Entry*[capacity *= 2];
			for (size_t i = 0; i < size; i++) {
				newEntries[i] = entries[i];
			}
			delete[] entries;
			entries = newEntries;
		}
		entries[size++] = new Entry(name, room, ph, pos);
	}

	virtual ~Directory() {
		cout << "Directory's Destructor." << endl;
		delete[] entries;
	}

	unsigned operator[](const string& name) {
		for (size_t i = 0; i < size; i++) {
			if (name == entries[i]->getName()) {
				return entries[i]->getPhone();
			}
		}
	}

	friend ostream& operator<<(ostream& os, const Directory& d) {
		for (size_t i = 0; i < d.size; i++) {
			os << *d.entries[i] << endl;
		}
		return os;
	}
	
	Directory& operator=(const Directory& rhs);

	Directory(const Directory& rhs) : entries(nullptr) { 
		cout << "Directory's Copy Control." << endl;
		*this = rhs; // Calls assignment operator
	}

private:
	Entry** entries;
	size_t size;
	size_t capacity;
};

Directory& Directory::operator=(const Directory& rhs) {
	cout << "Directory's Assignment Operator." << endl;
	if (this == &rhs) {
		return *this;
	}
	else {
		delete[] entries;
		entries = new Entry*[rhs.size];
		size = rhs.size;
		for (size_t i = 0; i < size; i++) {
			entries[i] = rhs.entries[i];
		}
		capacity = size;
		return *this;
	}
}

int main() {
	// Model as if there are these four kinds 
	// of position in the problem:
	Position boss("Boss", 3141.59);
	Position pointyHair("Pointy Hair", 271.83);
	Position techie("Techie", 14142.13);
	Position peon("Peonissimo", 34.79);

	// 
	Directory d;
	d.add("Marilyn", 123, 4567, boss);
	cout << "Printing out entries in d: " << endl << d;
	cout << endl << "Printing out Marilyn's number in Directory d: " << d["Marilyn"] << endl;
	Directory d2 = d;	// What function is being used. Copy Constructor which calls Assignment
	d2.add("Gallagher", 111, 2222, techie);
	cout << endl << "Printing out entries in d2: " << endl << d2;
	cout << endl << "Printing out Marilyn's number in Directory d2: " << d2["Marilyn"] << endl;
	cout << "Printing out Gallagher's number in Directory d2: " << d2["Gallagher"] << endl;
	Directory d3;
	d3 = d2;
	cout << endl << "Printing out entries: " << endl << d3;
	cout << endl << "Printing out Marilyn's number in Directory d3: " << d3["Marilyn"] << endl;
	cout << "Printing out Gallagher's number in Directory d3: " << d3["Gallagher"] << endl << endl;

	system("pause");
}