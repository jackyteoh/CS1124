#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

class Number {
	friend ostream& operator<<(ostream& os, const Number& rhs) {
		os << rhs.whole << '.' << rhs.decimal;
		return os;
	}

public:
	Number(int whole = 0, int decimal = 0) : whole(whole), decimal(decimal) {}

	Number& operator+=(const Number& rhs) {
		whole += rhs.whole;
		decimal += rhs.decimal;
		return *this;
	}

	// preincrement
	Number& operator++() {
		whole++;
		return *this;
	}

	// postincrement
	Number operator++(int dummy) {
		Number result(*this);
		whole++;
		return result;
	}

private:
	int whole;
	int decimal;
};

Number operator+(const Number& lhs, const Number& rhs) {
	Number temp(lhs);
	temp += rhs;
	return temp;
}


int main() {
	Number a(1, 2); // 1.2
	Number b(2, 3); // 2.3
	cout << a << endl;
	cout << b << endl;
	a += b; // a.operator+=(b)
	cout << a << endl;
	cout << ++b << endl;
	cout << b++ << endl;
}

// Node
struct Node {
	Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
	int data;
	Node* next;
};

void listDisplay(Node* head) {
	Node* p = head;
	while (p != nullptr) {
		cout << p->data << ' ';
		p = p->next;
	}
	cout << endl;
}

Node* listFindEnd(Node* head) {
	Node* p = head;

	if (p != nullptr) {
		while (p->next != nullptr) {
			p = p->next;
		}
	}

	return p;
}

void listAddToEnd(Node*& head, int data) {
	if (head == nullptr) {
		head = new Node(data);
	}
	else {
		Node* theEnd = listFindEnd(head);
		theEnd->next = new Node(data);
	}
}

// Tree
struct TNode {
	TNode(int data = 0, TNode *left = nullptr, TNode *right = nullptr) : data(data), left(left), right(right) {}

	int data;
	TNode *left, *right;
};

TNode* treeAdd(TNode* root, int x = 0, char direction = 'r') {
	if (direction == 'l') {
		root->left = new TNode(x);
		return root->left;
	}
	else {
		root->right = new TNode(x);
		return root->right;
	}
}

// recursive functions
void displayBinary(int x);
Node* addLists(Node* list1, Node* list2);
int maxInTree(TNode* root);
int sumCString(char* cstring);
int binarySearch(char* arr, char search, int low, int high);

// main
int main() {
	// displayBinary(100);
	// cout << endl;

	// cout << "sumList" << endl;
	// Node* a = new Node(1);
	// listAddToEnd(a, 2);
	// listAddToEnd(a, 3);
	// listAddToEnd(a, 4);
	// listAddToEnd(a, 5);
	// listDisplay(a);

	// Node* b = new Node(6);
	// listAddToEnd(b, 7);
	// listAddToEnd(b, 8);
	// listAddToEnd(b, 9);
	// listAddToEnd(b, 10);
	// listDisplay(b);

	// Node* c = addLists(a, b);
	// listDisplay(c);

	// an int is 32 bits
	// 2^32 = 4294967296
	// -2147483648 <-> 2147483648
	// cout << INT_MIN << endl;

	char arr[] = "I need to pass";
	int len = 14;
}

void displayBinary(int x) {
	if (x < 2) {
		cout << x;
	}
	else {
		displayBinary(x / 2);
		cout << x % 2;
	}
}

// assuming we don't pass in nullptr's 
Node* addLists(Node* list1, Node* list2) {
	if (list1->next == nullptr) {
		return new Node(list1->data + list2->data);
	}
	else {
		Node* next = addLists(list1->next, list2->next);
		return new Node(list1->data + list2->data, next);
	}
}

//    root
//    /  \
//  left right
int maxInTree(TNode* root) {
	if (root == nullptr) {
		return INT_MIN;
	}

	int current = root->data;
	int right = maxInTree(root->right);
	int left = maxInTree(root->left);

	if (right < current && left < current) {
		return current;
	}
	else {
		if (right > left) {
			return right;
		}
		else {
			return left;
		}
	}
}

int sumCString(char* cstring) {
	if (cstring[0] == '\0') {
		return 0;
	}
	else {
		int total = 0;

		// calls it on the next element of the array
		total += sumCString(cstring + 1);
		total += int(cstring[0]);
		return total;
	}
}

int binarySearch(char* arr, char search, int low, int high) {
	if (high < low) {
		return -1;
	}

	int mid = (high + low) / 2;
	if (arr[mid] == search) {
		return mid;
	}
	else if (search < arr[mid]) {
		return binarySearch(arr, search, low, mid - 1);
	}
	else if (search > arr[mid]) {
		return binarySearch(arr, search, mid + 1, high);
	}
}

//Print 1 to n [in reverse]
void printShit(int n) {
	if (n == 1) {
		cout << n << ' ';
		return;
	}

	cout << n << ' ';
	printShit(n - 1);
}

//Print 1 to n [in regular order]
void printShit(int n) {
	if (n == 1) {
		cout << n << ' ';
		return;
	}

	printShit(n - 1);
	cout << n << ' ';
}

class Number {
	friend ostream& operator<<(ostream& os, const Number& rhs) {
		os << rhs.whole << '.' << rhs.decimal;
		return os;
	}

public:
	Number(int whole = 0, int decimal = 0) : whole(whole), decimal(decimal) {}

	Number& operator+=(const Number& rhs) {
		whole += rhs.whole;
		decimal += rhs.decimal;
		return *this;
	}

	// preincrement
	Number& operator++() {
		whole++;
		return *this;
	}

	// postincrement
	Number operator++(int dummy) {
		Number result(*this);
		whole++;
		return result;
	}

private:
	int whole;
	int decimal;
};

Number operator+(const Number& lhs, const Number& rhs) {
	Number temp(lhs);
	temp += rhs;
	return temp;
}


void printShit(int n) {
	if (n == 1) {
		cout << n << ' ';
		return;
	}

	cout << n << ' ';
	printShit(n - 1);
}

//Print x of one character followed by x of another character aaabbb x = 3, char 1 = a, char 2 = b
void printMoreShit(int x, char uno, char dos) {
	if (x < 1) {
		return;
	}
	else {
		cout << uno;
		printMoreShit(x - 1, uno, dos);
		cout << dos;
	}
}

//Print n to 1 followed by 1 to n
int printEvenMoreShit(int n) {
	if (n == 1) {
		cout << n << ' ';
		return;
	}
}

int main() {
	Number a(1, 2); // 1.2
	Number b(2, 3); // 2.3
	cout << a << endl;
	cout << b << endl;
	a += b; // a.operator+=(b)
	cout << a << endl;
	cout << ++b << endl;
	cout << b++ << endl;

	printShit(120);

	printMoreShit(3, 'a', 'b');
	cout << endl;

	printEvenMoreShit(100);
	cout << endl;
}

/*
operator+(a, b){
	temp c(a);
	c += b;
	return c;
}

DT.operator+(DT);
operator+(DT, DT);
operator+(const DT& a, const DT& b);

explicit DT(int); // Makes the constructor explicit
DT a(5);
operator+(DT);
DT a, b;
a = b + 5; // Works member/non-member
a = 5 + b; // Only works if operator+ is a nonmember

vector<int*> v;
for(int i = 0; i < 10; i++){
	v.push_back(new int(i));
}
v.clear(); <-- MEMORY LEAK. DELETE FIRST, THEN CLEAR. OTHERWISE CAN'T ACCESS HEAP.

for int i = 0; i < v.size(); i++){
	delete v[i];
}
v.clear();

int* i = new int;
delete i; // Dangling pointer. Points to same location
i = nullptr;

DT a(5);
a++;
++a;

DT& operator++(){ // Pre increment
// Increment
return *this;
}

DT operator++(int dummy){ // Post Increment
	DT temp(*this);
	temp++;
	return temp;
}

void func(Base b){

}

void func2(Base& b){

}

int main(){
Base b;
Derived q;
func(b);
func(q); // Slicing
func2(q); // Polymorphism References treated the same as pointers

Copy Constructor:
Copy the RHS
Some construction
no return

Assignment Operator:
Copy the RHS
Test for self assignment.
return *this
*/