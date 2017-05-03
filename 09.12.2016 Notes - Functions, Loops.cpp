#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
	
}

/*
While loop (0, 1, many)
While ( condition ) {
	code
}

tests condition -> if true, executes code -> if false, exits code

Do While loop (1, many)
Do {
	code
} while ( condition ){
	code
}

does code -> tests condition -> if true, loops again -> if false, exits code -> Does at least ONCE

For loop (
for (initialization; test; incrementation){
	code
}

initialization (Where it starts) -> tests -> code -> increments -> true = loop, false = exit

for (int x = 0; x < 10; x++){
	code
}

if( condition ){
	code 
}
else{
	code
} 

The whole if statement is ONE LINE of code, including the else.


C++ Math Operators
+
-
*
/
% (mod)
#include <cmath>
function: pow(base, exponent)

ofstream outFile; // creates object
cout << "What would you like to call the file?" << endl;
string filename;
cin >> filename;
outFile.open(filename); // opens file through object
ofstream anotherFile(filename); // creates object and opens the file

outFile << "Hello World" << endl; // putting text in your new text file!

ifstream inFile;
inFile.open("input.txt");
if (!inFile){
	cout << "THE FILE DOES NOT EXIST!!" << endl;
	return 1;
	}

char letter;
while (inFile >> letter){
	double value;
	inFile >> value;
	if (letter == 'C'){
		outFile << value << endl;
	}
	else if (letter == 'K') {
		outFile << value - 273 << endl;
	}
	else if (letter == 'F') {
		outFile << (value * 5/9) + 32 << endl;

1) Skips leading whitespace
2) Read in "valid" chars
3) Stops when reaching whitespace or "invalid" chars
4) Store result in given variable

int func1(){
	return 5;
}

void display(int x){
	cout << x << endl;
	return;
}

void printIt (int x, int y){
	cout << x << '\t' << y << endl;
}

void swap(int& first, int& second){ // reference parameters ! Pass by reference
	int temp = first;
	first = second;
	second = temp;
}

int x = 100;
int y = 5;
swap (x,y);
cout << "x = " << x << endl;
cout << "y = " << y << endl;
*/