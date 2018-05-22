/*
Jacky Teoh
jt2908
CS1124 Lab #1 - Intro To C++ 
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ifstream ifs("jabberwocky (1).txt");
	// test to see if the file successfully opens
	if (ifs.is_open()) {
		cout << "File successfully opened." << endl; 
	}
	else {
		cout << "Error opening file." << endl;
	}

	int linecount = 0;
	int wordcount = 0;
	int charcount = 0;
	int charcountws = 0;

	string line;

	// takes lines from the file, and prints out each line. Also adds one to the line counter.
	while (getline(ifs, line)) {
		linecount++;
		cout << line << endl;
	}

	// return back to the beginning of the file to count again
	ifs.clear();
	ifs.seekg(0);

	string word;

	// checks each word in the file, adds one to word counter every time.
	while (ifs >> word) {
		wordcount++;
	}

	// return back to the beginning of the file to count again
	ifs.clear();
	ifs.seekg(0);

	char somechar;
	ifs >> noskipws;

	// Counts the # of characters WITH white space. Prints out each character in a new line.
	while (ifs >> somechar) {
		cout << somechar << endl;
		charcountws++;
	}

	// return back to the beginning of the file to count again
	ifs.clear();
	ifs.seekg(0);

	char anychar;
	ifs >> skipws;

	// counts the number of characters WITHOUT white spaces. 
	while (ifs >> anychar) {
		charcount++;
	}

	cout << "There are " << linecount << " lines." << endl;
	cout << "There are " << wordcount << " words." << endl;
	cout << "There are " << charcountws << " characters with white spaces." << endl;
	cout << "There are " << charcount << " characters." << endl;

	system("pause");

}