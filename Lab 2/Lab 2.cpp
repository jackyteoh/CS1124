/*
Jacky Teoh - jt2908
CS1124
Recitation 2 - Structs with Vector fields
rec2.cpp
*/

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// created a struct, molecule, with diff attributes of a molecule:
// name of a molecule, in a vector of strings, because there are multiple molecule names with the same molecule contents
// # of carbons, stored in an int
// # of hydrogens, stored in an int
struct molecule {
	vector<string> moleculeName;
	int noCarbons;
	int noHydrogens;
};

// printVector function, which takes in a vector of type struct molecule, passed by reference to save memory
// iterates over the vector, and prints out # of carbons and # of hydrogens
// then iterates again over the vector of strings within the vector being iterated
// then prints out the vector of molecule names 
void printVector(const vector<molecule>& x) {
	for (int i = 0; i < x.size(); i++) {
		cout << "C" << x[i].noCarbons << "H" << x[i].noHydrogens << "  " << " ";
		for (int j = 0; j < x[i].moleculeName.size(); j++) {
			cout << x[i].moleculeName[j] << ", ";
		}
		cout << endl;
	}
}

int main() {
	// Tests to see if the file opened successfully or not
	ifstream ifs("hydrocarbons.txt");
	if (ifs.is_open()) {
		cout << "The file has successfully opened!" << endl << endl;
	}
	else {
		cout << "Error in opening the file." << endl;
	}

	// things to check the file for
	string name;
	char anyChar;
	char nextChar;
	int numberOfCarbons;
	int numberOfHydrogens;
	bool isFound = false;

	// creating a vector of the data type molecule.
	vector<molecule> vectorOfMolecules;

	/* 
	when checking the file, since the task asks to have one unique molecular formula along with all names
	for that formula, 
	first iterates over the vector and if the # of carbons and the # of hydrogens from the file are the same,
	creates a new molecule, w/ the formula, and adds the name of the formula from the file to the vector of names.
	This way all the molecules with the same formula will be on one line with the same name.
	*/
	while (ifs >> name >> anyChar >> numberOfCarbons >> nextChar >> numberOfHydrogens) {
		for (int i = 0; i < vectorOfMolecules.size(); i++) {
			if (vectorOfMolecules[i].noCarbons == numberOfCarbons && vectorOfMolecules[i].noHydrogens == numberOfHydrogens) {
				vectorOfMolecules[i].moleculeName.push_back(name);
				isFound = true;
				break;
			}
		}
		/*
		however, if this is not the case where the # of carbon and hydrogen are the same, 
		it will create a new molecule with respective formula, and adds the name to that molecule.
		*/
		if (isFound == false) {
			molecule m;
			m.noCarbons = numberOfCarbons;
			m.noHydrogens = numberOfHydrogens;
			m.moleculeName.push_back(name);
			vectorOfMolecules.push_back(m);
		}
	}

	// calling the printVector function, passing in vector vectorOfMolecules.
	printVector(vectorOfMolecules);

	// closes the file
	ifs.close();

	system("pause");

}