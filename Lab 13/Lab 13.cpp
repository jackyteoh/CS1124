#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

int factorial(int n) {
	if (n <= 1) {
		return 1;
	}
	return n*factorial(n - 1);
}

// Task 1
void binary(int n) {
	if (n < 2) {
		cout << n;
		return;
	}
	binary(n / 2);
	cout << n % 2;
}

// Task 2
struct Node {
	Node(int data = 0, Node* link = nullptr) : data(data), link(link) {}
	int data;
	Node* link;
};

Node* listInsertHead(int entry, Node* headPtr) {
	headPtr = new Node(entry, headPtr);
	return headPtr;
}

void listDisplay(Node* headPtr) {
	Node* p = headPtr;
	while (p != nullptr) {
		cout << p->data << ' ';
		p = p->link;
	}
	cout << endl;
}

Node* addLists(Node* head1, Node* head2) {
	if (head1  == nullptr || head2 == nullptr) {
		return nullptr;
	}
	else {
		return listInsertHead(head1->data + head2->data, addLists(head1->link, head2->link));
	}
}

// Task 3
struct TNode {
	TNode(int data = 0, TNode *left = nullptr, TNode *right = nullptr)
		: data(data), left(left), right(right) {}
	int data;
	TNode *left, *right;
};

int max(TNode* root) {
	if (root->right && root->left == nullptr) {
		return root->data;
	}
	else {
		int newMax = root->data;
		if (root->left->data > newMax && root->right->data > newMax) {
			if (root->left->data > root->right->data) {
				return max(root->left);
			}
			else {
				return max(root->right);
			}
		}
		else if (root->left->data > newMax && root->right->data < newMax) {
			return max(root->left);
		}
		else if (root->right->data > newMax && root->left->data < newMax) {
			return max(root->right);
		}
		else 
			return newMax;
		/*
		if (root->left->data > newMax && root->left->data > root->right->data) {
			return newMax = root->left->data;
		}
		if (root->right->data > newMax && root->right->data > root->left->data) {
			return newMax = root->right->data;
		}
		if (root->right->data == root->left->data) {
			return newMax = root->right->data;
		}
		if (root->data > root->left->data && root->data > root->right->data) {
			return newMax = root->data;
		}
		else {
			return newMax;
		}*//*
		return max(root);*/
	}
}

// Task 4
int sum(char* cstring) {
	if (cstring[0] == '\0') {
		return 0;
	}
	else {
		return int(cstring[0]+sum(cstring+1));
	}
}

// Task 5
int binarySearch(char* arr, char search, int low, int high) {
	int mid = (high + low) / 2;
	if (high < low) {
		return -1;
	}

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

// Task 6
void f(int n) {
	if (n > 1) {
		cout << 'a';
		f(n / 2);
		cout << 'b';
		f(n / 2);
	}
	cout << 'c';
}

int main() {
	binary(19);
	cout << endl;
	binary(21);
	cout << endl;

	Node* listOne = new Node(9, nullptr);
	listOne = listInsertHead(7, listOne);
	listOne = listInsertHead(5, listOne);
	cout << "listOne: ";
	listDisplay(listOne);

	Node* listTwo = new Node(2, nullptr);
	listTwo = listInsertHead(3, listTwo);
	listTwo = listInsertHead(6, listTwo);
	cout << "listTwo: ";
	listDisplay(listTwo);

	listDisplay(addLists(listOne, listTwo));
	
	TNode a(1), b(2), c(4), d(8, &a, &b), e(16, &c), f(32, &d, &e);
	cout << max(&f) << endl;

	char cstring[11] = "AB"; 
	cout << sum(cstring) << endl;

	cout << binarySearch(cstring, 'B', 0, 11) << endl;

	system("pause");
}

/*
*/