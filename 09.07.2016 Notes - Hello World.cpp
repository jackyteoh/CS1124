#include <iostream>
#include <string>

using namespace std;

int main() {
	int x = 100;

	int y;
	y = 10;

	int z(20);

	cout << "Hello World! " << endl;

	cout << "What is your temperature ? (C/F) " << endl;
	char letter;
	cin >> letter;
	if (letter == 'c' || letter == 'C') {
		double c;
		cout << "What C value? " << endl;
		cin >> c;
		double f = 9.0 / 5 * c + 32;
		cout << "That temperature is " << f << "F" << endl;
	}
	else {
		double f;
		cout << "What F value?" << endl;
		cin >> f;
		double c = 5.0 / 9 * (f - 32);
		cout << "That temperature is " << c << "C" << endl;
	}

	system("pause");
}

/* 
Ctrl A + K + F reformats everything
C++ doesn't care about white spaces.
You must have a semi-colon at the end of each "line"
Variables must be defined as a type before use.
Common types are:
bool, int, double, char, string
If using string, remember to: #include <string>
Strings are delimited by double quotes " "
Characters by single quotes ' '

For loops:
for (initialization, test, incrementation){
code
}

for (int i = 0; i < 10; i++){
	cout << i << endl;
}
*/