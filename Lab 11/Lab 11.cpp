#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

struct Node {
	Node(int data = 0, Node* link = nullptr) : data(data), link(link) {}
	int data;
	Node* link;
};

Node* listNodeAtIndex(int index, Node* headPtr) {
	int count = 0;
	Node* p = headPtr;
	while (count < index && p != nullptr) {
		count++;
		p = p->link;
	}
	return p;
}

void listInsertHead(int entry, Node*& headPtr) {
	headPtr = new Node(entry, headPtr);
}

void listInsertAfter(int entry, Node* previousPtr) {
	Node* temp = new Node(entry, previousPtr->link);
	previousPtr->link = temp;
}

void listInsertNode(Node* previousPtr, Node* newList) {

	Node* temp = previousPtr->link;
	previousPtr->link = newList;
	Node* temp2 = newList;
	while (temp2->link != nullptr) {
		temp2 = temp2->link;
	}
	temp2->link = temp;

}

void listDisplay(const Node* headPtr) {
	const Node* p = headPtr;
	while (p != nullptr) {
		cout << p->data << ' ';
		p = p->link;
	}
	cout << endl;
}

Node* listSearch(int target, Node* headPtr) {
	Node* p = headPtr;
	while (p != nullptr && p->data != target)
		p = p->link;
	return p;
}

void listSearchMultiple(Node* target, Node* headPtr) {
	listDisplay(target);
	listDisplay(headPtr);
	cout << "****************************" << endl;
	Node* p = target;
	Node* p2 = headPtr;
	if (p->link == nullptr) {
		if (p->data == p2->data) {
			cout << "Found" << endl;
		}
		else {
			cout << "Failed." << endl;
		}
	}
	while (p2 != nullptr && p != nullptr) {/*
		cout << "Big pointer: " << p2->data << endl;
		cout << "Small pointer: " << p->data << endl;*/
		if (p->data == p2->data) {
		/*	cout << "Found a match" << endl;*/
			if (p->link == nullptr) {
				cout << "Finishing." << endl;
				return;
			}
			p = p->link;
			p2 = p2->link;
			/*cout << "Updated pointers." << endl;*/
			
		}
		else {
			/*cout << "Not a match." << endl;*/
			if (p2->link != nullptr) {
			/*	cout << "resetting target" << endl;*/
				p = target;
				p2 = p2->link;
			}
			else {
				cout << "Failed to match." << endl;
				return;
			}
		}
	}
	cout << "Not found" << endl;
	//return p;
}
//
//Node* listSearchMultiple(Node* begin, Node* sub) {
//	for (Node* i = begin; i != nullptr; i = i->link) {
//		Node* result = i;
//		for (Node* j = sub; i->data == j->data; j = j->link) {
//			if (j->link == nullptr) {
//				return result;
//			}
//			if (i->link == nullptr) {
//				break;
//			}
//			if (i->link->data != j->link->data) {
//				break;
//			}
//		}
//		return nullptr;
//	}
//}

int main() {
	cout << "Part 1:" << endl;
	Node* listOne = nullptr;
	Node* listTwo = nullptr;

	listInsertHead(1, listOne);
	listInsertHead(9, listOne);
	listInsertHead(7, listOne);
	listInsertHead(5, listOne);
	cout << "listOne: ";
	listDisplay(listOne);

	listInsertHead(2, listTwo);
	listInsertHead(3, listTwo);
	listInsertHead(6, listTwo);
	cout << "listTwo: ";
	listDisplay(listTwo);

	cout << "Target: 7, 9, 1" << endl;
	Node* x = listSearch(7, listOne);
	listInsertNode(x, listTwo);
	cout << "listOne: ";
	listDisplay(listOne);

	cout << endl << "Part 2: " << endl;
	cout << "Target : 1 2 3 2 3 2 4 5 6" << endl;
	Node* listThree = nullptr;
	listInsertHead(6, listThree);
	listInsertHead(5, listThree);
	listInsertHead(4, listThree);
	listInsertHead(2, listThree);
	listInsertHead(3, listThree);
	listInsertHead(2, listThree);
	listInsertHead(3, listThree);
	listInsertHead(2, listThree);
	listInsertHead(1, listThree);

	//cout << "Attempt match: 1" << endl;
	//Node* attemptOne = nullptr;
	//listInsertHead(1, attemptOne);
	//Node* y = listSearchMultiple(attemptOne, listThree);
	////listDisplay(y);

	//cout << "Attempt match: 3 9" << endl;
	//Node* attemptTwo = nullptr;
	//listInsertHead(9, attemptTwo);
	//listInsertHead(3, attemptTwo);
	// listSearchMultiple(attemptTwo, listThree);

	cout << "Attempt Match: 2 3" << endl;
	Node* attempt3 = nullptr;
	listInsertHead(3, attempt3);
	listInsertHead(2, attempt3);
	listDisplay(listSearchMultiple(attempt3, listThree));

	//cout << "Attempt Match: 2 4 5 6" << endl;
	//Node* attemptFour = nullptr;
	//listInsertHead(6, attemptFour);
	//listInsertHead(5, attemptFour);
	//listInsertHead(4, attemptFour);
	//listInsertHead(2, attemptFour);
	//Node* c = listSearchMultiple(attemptFour, listThree);
	////listDisplay(c);

	//cout << "Attempt Match: 2 3 2 4" << endl;
	//Node* attemptFive = nullptr;
	//listInsertHead(4, attemptFive);
	//listInsertHead(2, attemptFive);
	//listInsertHead(3, attemptFive);
	//listInsertHead(2, attemptFive);
	//Node* d = listSearchMultiple(attemptFive, listThree);
	////listDisplay(d);

	//cout << "Attempt Match: 5 6 7" << endl;
	//Node* attemptSix = nullptr;
	//listInsertHead(7, attemptSix);
	//listInsertHead(6, attemptSix);
	//listInsertHead(5, attemptSix);
	//Node* e = listSearchMultiple(attemptSix, listThree);
	//// listDisplay(e);

	system("pause");
}