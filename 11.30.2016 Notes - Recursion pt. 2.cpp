#include <iostream>

using namespace std;

void countdown(int n){
	if (n == 0) {
		return;
	}
	cout << n << endl;
	countdown(n - 1);
}

void countup(int n) {
	if (n == 0) {
		return;
	}
	countup(n - 1);
	cout << n << endl;
}

int factorial(int n) {
	if (n == 0) {
		return 1;
	}
	return n*factorial(n - 1);
}

double power(int base, int exp) {
	if (exp == 0) {
		return 1;
	}
	if (base == 0) {
		return 0;
	}
	if (exp > 0) {
		return base*power(base, exp - 1);
	}
	else {
		return 1 / power(base, -exp);
	}
}

bool isPalindrome(char* c, int size) {
	if (size <= 1) {
		return true;
	}
	if (!(c[0] >= 'a' && c[0] <= 'z')) {
		return isPalindrome(c + 1, size - 2);
	}
	if (!(c[size - 1] >= 'a' && c[size - 1] <= 'z')) {
		return isPalindrome(c, size - 1);
	}
	if (c[0] != c[size - 1]) {
		return false;
	}
	return isPalindrome(c + 1, size - 2); // Removes last element as well. Size-1 IS the last element.
}

void printab(int n) {
	if (n == 0) {
		return;
	}
	cout << 'a';
	printab(n - 1);
	cout << 'b';
}

int main() {
	countup(5);
	cout << "Factorial(5) = " << factorial(5) << endl;
}