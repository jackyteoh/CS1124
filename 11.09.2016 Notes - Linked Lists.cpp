#include <iostream>
#include <string>
#include <ctime>
#include <vector>

using namespace std;

class LList;
class LListItr;

class LListNode {
public:
	LListNode(int newData = 0, LListNode* newPtr = nullptr) : data(newData), next(newPtr) {}
	friend class LList;
	friend class LListItr;
private:
	int data;
	LListNode* next;
};

class LListItr {
public:
	LListItr(LListNode* newPtr) : ptr(newPtr) {}
	friend class LList;
private:
	LListNode* ptr;
};

class LList {
public:
	LList() : head(nullptr) {}
	bool isEmpty() const { return head == nullptr; }
	virtual ~LList() { clear(); }
	LList(const LList& rhs) : head(nullptr) { *this = rhs; }
	LListItr begin() const { return head; }
	LListItr end() const { return nullptr; }

	LList& operator=(const LList& rhs);
	int size() const;
	void push_back(const int& newData);
	void push_front(const int& newData);
	int pop_back();
	int pop_front();
	void insertAfter(LListItr point, int item);
	void removeAfter(LListItr point);
	void clear() {
		while (!isEmpty()) {
			pop_front();
		}
	}
private:
	LListNode* head;
};

void LList::push_front(const int& newData) {
	//LListNode* temp = new LListNode(newData); // Creates new node, set data to what we want it to be
	//temp->next = head;						  // Has that new node point to whatever head was pointing to
	//head = temp;							  // Sets head to that new node
	head = new LListNode(newData, head);      // Does that ^ LListNode constructor sets newData to data, next to head
}

int LList::pop_front() {
	if (isEmpty()) {
		return 0;
	}
	else {
		int retVal = head->data;      // retVal = first data
		LListNode* toDelete = head;   // toDelete = first
		head = head->next;            // points to where toDelete's next is pointing to (2nd one)
		delete toDelete;			  // deletes the first one
		return retVal;				  // returns the data from the new head (2nd one)
	}
}

int LList::size() const {
	int counter = 0;			// creates a counter
	LListNode* temp = head;		// sets temp = to beginning node
	while (temp != nullptr) {	// While temp is not equal to nullptr
		counter++;				// Increments counter
		temp = temp->next;		// sets temp = to the next node, checks again.
	}
	return counter;
}

void LList::insertAfter(LListItr point, int item) {
	if (point.ptr != nullptr) {
		point.ptr->next = new LListNode(item, point.ptr->next);
	}
}

void LList::push_back(const int& newData) {
	if (isEmpty()) {
		push_front(newData);
	}
	else {
		LListNode* temp = head;
		while (temp->next != nullptr) {		// Iterates until the one BEFORE the last one (last one's next is nullptr)
			temp = temp->next;
		}
		insertAfter(temp, newData);
	}
}

int main() {

}

/*
Rec 10 Notes:
Operator Overloading
Sandwich a, b;
a + b;
operator+(const Sandwich& rhs);                      // Member
operator+(const Sandwich& lhs, const Sandwich& rhs); // Non member
Person a;
cout << a;

class ostream{
	operator<<(const Person& p);
};
cout << p;

friend ostream& operator<<(ostream& os, const Person& p){ // ostream return type is so you can chain <<

};
cout << p;
*/