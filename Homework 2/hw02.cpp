/*
Jacky Teoh - jt2908
CS1124 - Homework 2 - Warriors
hw02.cpp
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

// Creating Weapon class
class Weapon {
public:
	// Weapon constructor, taking in the name of the weapon and the weapon strength as parameters, initialized
	Weapon(string inputWeapon, int inputStrength) : weaponName(inputWeapon), weaponStrength(inputStrength) {}
	// Weapon name getter
	string getWeapon() const {
		return weaponName;
	}
	// Weapon strength getter
	int getWeaponStrength() const {
		return weaponStrength;
	}
	// Weapon strength setter, used for after battles.
	void setWeaponStrength(int newStrength) {
		weaponStrength = newStrength;
	}
private:
	string weaponName;
	int weaponStrength;
};

// Creating Warrior class
class Warrior {
public:
	// Warrior constructor, taking in warrior name, weapon name, weapon strength,
	// Initializing to warrior, creating a weapon for the warrior using the parameters.
	Warrior(string inputWarrior, string inputWeapon, int inputStrength)
		: warriorName(inputWarrior), warriorsWeapon(inputWeapon, inputStrength) {}
	// Warrior name getter
	string getName() const{
		return warriorName;
	}
	// Getting the name of the weapon FROM the weapon class THROUGH the warrior.
	string getWeaponName() const {
		return warriorsWeapon.getWeapon();
	}
	// Getting the strength of the weapon FROM the weapon class THROUGH the warrior
	int getWeaponStrengthWarrior() const {
		return warriorsWeapon.getWeaponStrength();
	}
	// Setting the strength of the weapon THROUGH the warrior
	void setWeaponStrengthWarrior(int newStrength) {
		warriorsWeapon.setWeaponStrength(newStrength);
	}
private:
	string warriorName;
	Weapon warriorsWeapon;
};

// Displaying the status of every warrior, taking in a vector of Warriors as a parameter.
void displayStatus(vector<Warrior>& x) {
	// Iterates over the vector, for every warrior found, prints out the name, weapon name, and weapon strength of the warrior.
	for (Warrior& w : x) {
		cout << "Warrior: " << w.getName() << ", Weapon: " << w.getWeaponName() << ", " << w.getWeaponStrengthWarrior() << endl;
	}
}

// Battle function, taking in two warriors as parameters.
void battle(Warrior& x, Warrior& y) {
	// Printing out who battles who
	cout << x.getName() << " battles " << y.getName() << endl;
	// Testing if the strength of the first warrior passed is greater than the strength of the second warrior passed.
	// If it's greater, sets the strength of the first warrior to the value of first warrior's strength minus the second warrior's strength
	// Then sets the value of the weaker warrior's strength to 0 because he lost.
	// Then prints out the victor of the battle.
	if (x.getWeaponStrengthWarrior() > y.getWeaponStrengthWarrior()) {
		x.setWeaponStrengthWarrior(x.getWeaponStrengthWarrior() - y.getWeaponStrengthWarrior());
		y.setWeaponStrengthWarrior(0);
		cout << x.getName() << " wins! " << endl;
	}
	// Testing if the strength of the second warrior passed is greater than the strength of the first warrior passed.
	// Does the same as above, stronger - weaker.
	// Sets the strength of the weaker to 0.
	// Then prints out the victor of the battle.
	if (y.getWeaponStrengthWarrior() > x.getWeaponStrengthWarrior()) {
		y.setWeaponStrengthWarrior(y.getWeaponStrengthWarrior() - x.getWeaponStrengthWarrior());
		x.setWeaponStrengthWarrior(0);
		cout << y.getName() << " wins! " << endl;
	}
	// Testing if the strengths of the two warriors passed are equal.
	// Then both their strengths both get reduced to 0 
	// Then prints out that they both lose.
	if (x.getWeaponStrengthWarrior() == y.getWeaponStrengthWarrior()) {
		x.setWeaponStrengthWarrior(0);
		y.setWeaponStrengthWarrior(0);
		cout << x.getName() << " and " << y.getName() << " both lose." << endl;
	}
}

int main() {
	// Checking to see if the file successfully opens or not.
	ifstream ifs("warriors.txt");
	if (ifs.is_open()) {
		cout << "Your file has successfully opened!" << endl << endl;
	}
	else {
		cout << "Error in opening file." << endl << endl;
	}

	// Creating a vector of Warriors called vectorOfWarriors
	vector<Warrior> vectorOfWarriors;

	// Checking the first word in the file to see what we have to do (Create a warrior, Check the status, or battle)
	string task;
	while (ifs >> task) {
		// If "Warrior" is the first word, that means we have to create a warrior.
		// Then sets the following values, which are the name of the warrior, name of the warrior's weapon, and the weapon strength,
		// To variables created, warriorName, warriorWeapon, and weaponPower
		// Then gets passed into the warrior constructor, and pushes back that warrior object into the vector of Warriors.
		if (task == "Warrior") {
			string warriorName;
			string warriorWeapon;
			int weaponPower;
			ifs >> warriorName >> warriorWeapon >> weaponPower;
			Warrior nextWarrior(warriorName, warriorWeapon, weaponPower);
			vectorOfWarriors.push_back(nextWarrior);
		}
		// If "Status" is the first word, it will call the displayStatus function and pass in the vector of Warriors.
		else if (task == "Status") {
			displayStatus(vectorOfWarriors);
		}
		// If "Battle" is the first word, means we have to call the battle function
		// "Battle" is followed by two warrior's names who are designated to battle.
		// Creating variables for warrior1 and warrior2 to store those names.
		// Then variables for the positions of those warriors in the vector are created.
		// Checks the line, inputs the string name of the warriors from the file into the warrior1 and warrior2 variables.
		// Then iterates over the vector of Warriors, if the name matches with the name from the vector,
		// Stores the position of that warrior in positionOfWarrior. This helps us call it later in the battle function because the an index of a vector of warriors is a warrior: vectorOfWarriors[i] is a warrior.
		// Iterates again to check and store the second warrior's name and position.
		// Then calls the battle function, passing in the warriors (The position of the warriors in the vector)
		else if (task == "Battle") {
			string warrior1;
			string warrior2;
			int positionOfWarrior1;
			int positionOfWarrior2;
			ifs >> warrior1 >> warrior2;
			for (int i = 0; i < vectorOfWarriors.size(); i++) {
				if (warrior1 == vectorOfWarriors[i].getName()) {
					positionOfWarrior1 = i;
				}
			}
			for (int j = 0; j < vectorOfWarriors.size(); j++){
				if (warrior2 == vectorOfWarriors[j].getName()) {
					positionOfWarrior2 = j;
				}
			}
			battle(vectorOfWarriors[positionOfWarrior1], vectorOfWarriors[positionOfWarrior2]);
		}
	}

	// Closing the opened file.
	ifs.close();

	system("pause");
}