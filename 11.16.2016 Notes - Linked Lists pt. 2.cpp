#include <iostream>
#include <string>
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
	LListItr(LListNode* newPtr = nullptr) : ptr(newPtr) {}
	bool isValid() const {
		return ptr != nullptr;
	}
	LListItr& operator++();
	LListItr operator++(int);
	bool operator==(const LListItr& rhs) const;
	bool operator!=(const LListItr& rhs) const;
	int& operator*() { return ptr->data; }
	int operator*() const { return ptr->data; }
	friend class LList;
private:
	LListNode* ptr;
};

LListItr& LListItr::operator++() {
	if (ptr != nullptr) {
		ptr = ptr->next;
	}
	return *this;
}

LListItr LListItr::operator++(int) {
	LListItr temp = *this;
	if (ptr != nullptr) {
		ptr = ptr->next;
	}
	return temp;
}

bool LListItr::operator==(const LListItr& rhs) const {
	return ptr == rhs.ptr;
}

bool LListItr::operator!=(const LListItr& rhs) const {
	return ptr != rhs.ptr;
}
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
	int removeAfter(LListItr point);
	void clear() {
		while (!isEmpty()) {
			pop_front();
		}
	}
private:
	LListNode* head;
};

LList& LList::operator=(const LList& rhs) {
	if (this == &rhs) {
		return *this;
	}
	else {
		clear();
		LListNode* rhsTemp = rhs.head;
		LListNode* thisTemp = nullptr;
		if (rhsTemp != nullptr) {
			push_front(rhsTemp->data);
			thisTemp = head;
			rhsTemp = rhsTemp->next;
		}
		while (rhsTemp != nullptr) {
			thisTemp->next = new LListNode(rhsTemp->data);
			thisTemp = thisTemp->next;
			rhsTemp = rhsTemp->next;
		}
		// Inefficient Solution
		//LListNode* temp = rhs.head;
		//while (temp != nullptr) {
		//	push_back(temp->data);
		//}
		return *this;
	}
}

int LList::pop_back() {
	if (isEmpty()) {
		return 0;
	}
	else if (head->next == nullptr) { // Only one element 
		return pop_front();
	}
	LListNode* temp = head;
	while (temp->next->next != nullptr) { // Gotta figure out which node to stop on !!
		temp = temp->next;
	}
	return removeAfter(temp);
}

int LList::removeAfter(LListItr point) {
	if (point.ptr != nullptr && point.ptr->next != nullptr) {
		int retVal = point.ptr->next->data;
		LListNode* temp = point.ptr->next;
		point.ptr->next = temp->next;
		delete temp;
		return retVal;
	}
	return 0;
}

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
	LList l;
	for (int i = 0; i < 10; i++) {
		l.push_front(i);
	}

	for (LListItr i = l.begin(); i != l.end; i++) { // prints out 9-0, push front
		cout << *i << endl;
	}
}

/*

*/