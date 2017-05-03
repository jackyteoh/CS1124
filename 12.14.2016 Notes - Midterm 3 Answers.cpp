#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
	Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
	int data;
	Node* next;
};

// Midterm 3 : Programming Question 1
/// Recursive
void removeEveryOther(Node* ptr) {
	if (ptr == nullptr || ptr->next == nullptr) {
		return;
	}
	Node* temp = ptr->next;
	ptr->next = ptr->next->next;
	delete temp;
	removeEveryOther(ptr->next);
}

/// Iterative
void removeEveryOtherIterative(Node* ptr) {
	if (ptr == nullptr || ptr->next == nullptr) {
		return;
	}
	Node* temp = ptr;
	Node* toDelete = ptr->next;
	while (temp != nullptr && temp->next != nullptr) {
		toDelete = ptr->next;
		temp->next = toDelete->next;
		delete toDelete;
		temp = temp->next;
	}
}

// Midterm 3 : Programming Question 2
template <class T>
LList<T> LList<T>::operator+(const LList<T>& rhs) {
	LList<T> first = *this;
	LList<T> second = rhs;
	LListNode<T>* temp = first.head;
	if (temp == nullptr) {
		return second;
	}
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	temp->next = second.head;
	second.head = nullptr;
	return first;
}

int main() {

}