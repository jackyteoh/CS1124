#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

void printIt(int n) {
	if (n == 0) {
		return;
	}
	printIt(n - 1);
	cout << n << endl;
}

void LList::printIt(Node* ptr) {
	if (ptr == nullptr) {
		return;
	}
	cout << ptr->data << endl;
	printIt(ptr->next);
}

int factorial(int n) {
	if (n == 0) {
		return 1;
	}
	return n * factorial(n - 1);
}

int main() {
	printIt(5); // Prints out 1 2 3 4 5
}

/*
Steps for Recursion to work:
1) Identify the Base Case:
2) Identify the Single Case - what you do inside the instance, the loop
Takes care of one iteration of this algorithm
Everytime you iterate, the next time you work with a smaller set (n => n-1)
3) Reduce the set by the single case, working towards the base case.

Activation Record = 1 Function Call
Point of Return when complete
Return value
Parameters
Local Variables
*/