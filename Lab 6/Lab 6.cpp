/*
Jacky Teoh - jt2908
CS 1124 - Rec 6 : Inheritance Intro
10.14.2016
rec 06.cpp
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Task 1
class PrintedMaterial {
public:
	// Task 4
	PrintedMaterial(unsigned newNum) : numberOfPages(newNum) {}

	// Task 6
	// void displayNumPages() const {
	//    cout << numberOfPages << endl;
	// }

	// Task 11
	/* virtual void displayNumPages() const {
		cout << numberOfPages << endl;
	}
	*/

	// Task 13 - Pure Virtual
	virtual void displayNumPages() const = 0;

protected:
private:
	// Task 2 & 3
	unsigned numberOfPages;
};

class Magazine : public PrintedMaterial {
public:
	Magazine(unsigned num) : PrintedMaterial(num) {}
	void displayNumPages() const {
		cout << "I am a Magazine, I have: ";
		PrintedMaterial::displayNumPages();
	}
protected:
private:

};

class Book : public PrintedMaterial {
public:
	Book(unsigned num) : PrintedMaterial(num) {}
	void displayNumPages() const {
		cout << "I am a Book, I have: ";
		PrintedMaterial::displayNumPages();
	}
protected:
private:
};

class TextBook : public Book {
public:
	TextBook(unsigned num, unsigned index) : Book(num), numOfIndexPages(index) {}
	// Task 5
	// TextBook(TextBook(unsigned num) : Book(num), PrintedMaterial(num) {}
	void displayNumPages() const{
		// Task 8
		cout << "I am a Textbook." << endl;
		cout << "Number of pages: " << endl;
		PrintedMaterial::displayNumPages();
		cout << "Number of index pages: " << endl;
		cout << numOfIndexPages << endl;
	}
protected:
private:
	// Task 7
	unsigned numOfIndexPages;
};

class Novel : public Book {
public:
	Novel(unsigned num) : Book(num) {}
	// Task 5
	// TextBook(TextBook(unsigned num) : Book(num), PrintedMaterial(num) {}
	void displayNumPages() const {
		cout << "I am a Novel, I have: ";
		PrintedMaterial::displayNumPages();
	}
protected:
private:
};

// Task 12
void displayNumberOfPages(PrintedMaterial& somePM) {
	somePM.displayNumPages();
}


int main() {
	TextBook t(399, 12);
	Novel n(456);
	Magazine m(789);
	t.displayNumPages();
	n.displayNumPages();
	m.displayNumPages();

	// Task 9 , slicing !
	// PrintedMaterial pm = t;
	// pm.displayNumPages();

	// Task 10
	// PrintedMaterial* pmPtr = &t;
	// pmPtr->displayNumPages();

	// Task 12
	// displayNumberOfPages(t);
	// displayNumberOfPages(n);
	// displayNumberOfPages(m);

	// Task 15 - Vector
	vector<PrintedMaterial*> vpm;
	vpm.push_back(&t);
	vpm.push_back(&n);
	vpm.push_back(&m);
	for (size_t i = 0; i < vpm.size(); i++) {
		vpm[i]->displayNumPages();
	}

	system("pause");
}