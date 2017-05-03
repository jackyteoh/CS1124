#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

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

int binarys(int* arr, int start, int end, int toFind) {
	if (start > end) {
		return -1; // not found
	}
	int middle = (start + end) / 2;
	if (arr[middle] == toFind) {
		return middle;
	}
	else if (arr[middle] < toFind) {
		return binarys(arr, middle + 1, end, toFind);
	}
	else{
		return binarys(arr, start, middle - 1, toFind);
	}
}

double fib(int n) {
	if (n < 2) {
		return 1;
	}
	return fib(n - 1) + fib(n - 2);
}

double betterFib(int n) {
	double* temp;
	if (n < 2) {
		return 1;
	}
	temp = new double[n + 1];
	temp[0] = 1;
	temp[1] = 1;
	for (int i = 2; i <= n; i++) {
		temp[i] = temp[i - 1] + temp[i - 2];
	}
	double retVal = temp[n];
	delete[] temp;
	return retVal;
}

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


	printShit(120);

	printMoreShit(3, 'a', 'b');
	cout << endl;

	printEvenMoreShit(100);
	cout << endl;
}

/*
0  1  2  3  4  5  6  7  8  9  10  11
2  6  9  11 13 15 16 17 20 21 23  25

middle = beginning + end / 2;
if ( arr[middle] == search){
return middle;
else if ( arr[middle] < value){
return search(middle+1, end);
}
ekse if (arr[middle] > value){
return search(beginning, middle-1);
}

*/

/*
NOT ON
void towers(char start, char temp, char end, int disks) {
if (disks == 1)
cout << "Move one disk from" << start << " to " << end << endl;
else {
towers(start, end, temp, disks - 1);
towers(start, temp, end, 1);
towers(temp, start, end, disks - 1);
}
}

class Timer {
double start;
public:
Timer() { start = clock(); }
void reset() { start = clock(); }
double elapsed() { return (clock() - start) / CLOCKS_PER_SEC; }
};
*/