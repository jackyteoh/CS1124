/*
Jacky Teoh - jt2908
CS 1124 - HW #1 - Caesar Cypher
hw01.cpp
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/* 
If the char is an uppercase character, a punctuation mark, or a space, it returns it as it is.
Task is only to rotate lower case chars
Then takes the char, subtracts the # of steps from it, and also subtracts the value of 'a'
Then checks if the resulting char is less than 0, in the case of if the char is at the beginning of the alphabet,
this helps it to loop back from the end of the alphabet by adding 26.
Then returns x + value of a to get the original letter.
*/
char decryptChar(char anyChar, int steps) { 
	if (isupper(anyChar) || ispunct(anyChar) || isspace(anyChar)) { 
		return anyChar; 
	}     
	char x = anyChar - steps - 'a';     
	if (x < 0) { 
		x += 26; 
	}    
	return x + 'a'; 
}

/*
decryptLine function, takes in the line by reference, and the number of steps as parameters
iterates over the line from the file, and calls the decryptChar function to decrypt the char by the # of steps.
*/
void decryptLine(string& line, int steps) {
	for (int i = 0; i < line.size(); i++) {
		line[i] = decryptChar(line[i], steps);
	}
}

int main() {
	ifstream ifs("encrypted.txt");
	// Test to see if the file successfully opened or not.
	if (ifs.is_open()) {
		cout << "The file has successfully opened!" << endl << endl;
	}
	else {
		cout << "There was an error opening the file, try again." << endl << endl;
	}

	// Setting the number of steps to rotate the char
	int steps;
	ifs >> steps;

	// creating line variable
	// creating vector for the decrypted lines
	string line;
	vector<string> decryptedLines;

	// gets line from file,
	// calls decryptLine function to decrypt each line, which within the decryptLine function, decryptChar is called
	// then pushes back the decrypted line to the decryptedLine vector
	while (getline(ifs, line)) {
		decryptLine(line, steps);
		decryptedLines.push_back(line);
	}

	// to print out the vector, iterates over the vector using the for loop.
	/* 
	however, we need to print it out reversely, since we pushed it back to a vector,
	the first letter of the decrypted word is currently the last letter in the vector.
	So when I initialized it, I started from the back and iterated backwards,
	so when I printed it out, it would be in the correct order.
	*/ 
	for (size_t i = decryptedLines.size() - 1; i > 0; i--){
		cout << decryptedLines[i] << endl;
	}
	
	// closes the file
	ifs.close();

	system("pause");
}
