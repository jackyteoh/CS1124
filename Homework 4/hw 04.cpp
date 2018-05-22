/*
Jacky Teoh - jt2908
CS 1124 - Homework 4 : Dynamic Memory
hw 04.cpp
10.21.2016
*/

/*
Dear person who is grading my homework,
My code works fine, and the sample output matches my code's output.
However I ran into some sort of bug while I was trying to code the portion for the handling errors part.
As you can see, for the various "tasks" we had to do, the Noble, Warrior, Hire, Fire, and Battle,
They have the "handling errors" portion commented out. The reasoning behind the code makes sense to me,
and when I went to the PTC for help, they noticed that I had the same code as them, and they weren't sure why it wasn't 
working correctly. I also don't know why it's not working correctly.
If you do uncomment the lines of code, you see that it prints out something like "It already exists, you can't create one" MANY times
Or something along those lines.
I understand the concept, you test to see if the vector[i]->getName == name you pass in, but it just doesn't work correctly.
I even tried to put it into a function and then calling the function in main but that didn't work either.
Please let me know what can fix it!! Or if I'm doing anything wrong.
Thank you so much!!
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

// Warrior class
class Warrior {
public:
	// Warrior constructor, taking in a string name, and a float strength.
	Warrior(string givenName, float givenStrength) : warriorName(givenName), warriorStrength(givenStrength) {}
	// Getter function for the Warrior's name
	string getWarriorName() const {
		return warriorName;
	}
	// Getter function for the Warrior's strength
	float getWarriorStrength() const {
		return warriorStrength;
	}
	// Setter function for the Warrior's strength, multiplies his strength by the value passed in, x (Ratio)
	void setWarriorStrength(float x) {
		warriorStrength = warriorStrength * x;
	}
	// Display function
	void display() const;
private:
	string warriorName;
	float warriorStrength;
};

// Display function to display the warrior's name and his strength.
void Warrior::display() const {
	cout << "   " << getWarriorName() << ": " << getWarriorStrength() << endl;
}

// Noble class
class Noble {
public:
	// Noble constructor, taking in a string for the noble's name.
	Noble(string newName) : nobleName(newName) {}
	// Hire function, taking in a warrior by reference, because we're pushing it back into a vector of Warrior pointers.
	void hire(Warrior& h);
	// Fire function, taking in a warrior by reference, because we're removing it from a vector of Warrior pointers.
	void fire(string& warriorName, vector<Warrior*>& x);
	// Display function for nobles
	void display() const;
	// Battle function for nobles, taking in another noble by reference.
	void battle(Noble& n);
	// Getter function for the army strength of the noble.
	float getArmyStrength();
	// Setter function for the army strength of the noble.
	void setArmyStrength(float x);
	// Getter function for the name of the noble.
	string getNobleName() const {
		return nobleName;
	}
private:
	string nobleName;
	// Each noble has an army, which is a vector of Warrior pointers.
	vector<Warrior*> army;
	float armyStrength;
};

// Hire function, takes in a Warrior by reference, pushes it back into the vector of Warrior pointers, army,
// Then adds the strength of the warrior to the total army strength.
void Noble::hire(Warrior& h) {
	army.push_back(&h);
	armyStrength = armyStrength + h.getWarriorStrength();
}

//Fire function, takes in a string for the warrior name, and a vector of warrior Pointers
//then iterates over the vector and checks if the index in the ARMY vector is the same as the name passed in
//then pushes back that warrior in the ARMY vector into the vector passed in
//Then sets the current index in the army to the end of the vector
//then subtracts from the armyStrength the warrior in the army vector.
//Then pops back from the vector because he is no longer in the army.
//Prints out who got fired as well as the noble that fired him.
void Noble::fire(string& warriorName, vector<Warrior*>& x) {
	for (size_t i = 0; i < army.size(); i++) {
		if (army[i]->getWarriorName() == warriorName) {
			x.push_back(army[i]);
			army[i] = army[army.size() - 1];
			armyStrength -= army[i]->getWarriorStrength();
		}
		//else {
		//	cout << "This warrior does not exist in the Noble's army! Please select another warrior to fire!" << endl;
		//}
	}
	army.pop_back();
	cout << warriorName << ", you're fired !! -- " << getNobleName() << endl << endl;
}

// Display function, then prints out the name of the noble, as well as the size of his army vector.
// Then iterates over his army vector, and calls the display function for each warrior in his army
// Which prints out the warrior's name and his strength.
void Noble::display() const {
	cout << getNobleName() << " has an army of " << army.size() << endl;
	for (Warrior* w : army) {
		w->display();
	}
	cout << endl;
}

// Getter function for the army strength of the noble.
float Noble::getArmyStrength() {
	return armyStrength;
}

// Setter function for the army strength of the noble, takes in the battle ratio, float, as a parameter.
// Subtracts the original strength of the warrior from the total army strength,
// Then iterates over the army, and for each warrior, calls the setWarrriorStrength function and passes in x,
// Which is the battle ratio.
// Then adds that new strength back to the total army Strength to get the new updated army strength.
void Noble::setArmyStrength(float x) {
	for (int i = 0; i < army.size(); i++) {
		armyStrength -= army[i]->getWarriorStrength();
		army[i]->setWarriorStrength(x);
		armyStrength += army[i]->getWarriorStrength();
	}
}

// Battle function, taking in another noble by reference,
// First displays which noble is battling who,
// Then checks if the strength of the first noble's army is the same as the second noble's army.
// If both of their strength's are already 0, prints out they're both already dead.
// Otherwise, it prints out that both of the nobles lose, and sets both of their army strengths to 0.
void Noble::battle(Noble& n) {
	cout << endl << this->getNobleName() << " battles " << n.getNobleName() << endl;
	if (this->getArmyStrength() == n.getArmyStrength()) {
		if (this->getArmyStrength() == 0 && n.getArmyStrength() == 0) {
			cout << "Oh, they're both already dead!" << endl;
		}
		else {
			cout << "Both " << this->getNobleName() << " and " << n.getNobleName() << " lose! " << endl;
			this->setArmyStrength(0);
			n.setArmyStrength(0);
		}
	}
	// If the passed in noble's strength is less than the noble's strength who's trying to battle,
	// Prints out that the noble with the lesser strength loses,
	// Then calculates the strength ratio to alter the winner's warriors.
	// If the passed in noble's army already has a strength of 0, he's already dead, and it prints that.
	// If not, calls the setArmyStrength function for the winner and passes in 1 - strengthRatio
	// Also sets the loser's army strength to 0 because he lost.
	if (this->getArmyStrength() > n.getArmyStrength()) {
		cout << n.getNobleName() << " loses!" << endl;
		if (n.getArmyStrength() == 0) {
			cout << "He's already dead, " << this->getNobleName() << endl;
		}
		float strengthRatio;
		if (n.getArmyStrength() > 0) {
			strengthRatio = (n.getArmyStrength() / this->getArmyStrength());
		}
		else if (n.getArmyStrength() <= 0) {
			return;
		}
		this->setArmyStrength(1 - strengthRatio);
		n.setArmyStrength(0);
	}
	// Tests if the second noble's strength is higher than the first noble's.
	// Prints out that the first noble's loses if the test is true.
	// If the first noble tries to battle, but he's dead, prints out that he's already dead.
	// Then calculates the strength ratio to alter the winner's warriors.
	// If the noble's army who is trying to fight already has a strength of 0, he's already dead, and it prints that.
	// If not, calls the setArmyStrength function for the winner and passes in 1 - strengthRatio
	// Also sets the loser's army strength to 0 because he lost.
	if (n.getArmyStrength() > this->getArmyStrength()) {
		cout << this->getNobleName() << " loses!" << endl;
		if (this->getArmyStrength() == 0) {
			cout << "He's already dead, " << n.getNobleName() << endl;
		}
		float strengthRatio;
		if (this->getArmyStrength() > 0) {
			strengthRatio = (this->getArmyStrength() / n.getArmyStrength());
		}
		else if (this->getArmyStrength() <= 0) {
			return;
		}
		n.setArmyStrength(1 - strengthRatio);
		this->setArmyStrength(0);
	}
}

//bool checkNoble(string& y, vector <Noble*> x) {
//	for (size_t i = 0; i < x.size(); i++) {
//		if (x[i]->getNobleName() == y) {
//			return true;
//		}
//	}
//}

int main() {
	// Checking if input file works or not.
	ifstream ifs("nobleWarriors.txt");
	if (ifs.is_open()) {
		cout << "Your file has successfully opened!" << endl << endl;
	}
	else {
		cout << "There was an error opening your file." << endl << endl;
	}

	// Creating a vector of Noble*, vecNobles
	vector<Noble*> vecNobles;

	// Creating a vector of Warrior*, inactiveWarriors. When ANY warrior is created, they get put in here since they are initially
	// all "inactive"
	vector<Warrior*> inactiveWarriors;

	// Creating a string called task, to check for what the file wants to do.
	string task;
	// While it reads in from the file into "task":
	while (ifs >> task) {
		// If the first word is "Noble", creates a string called nobleName and reads in from ifs into nobleName.
		// Then creates a Noble on the heap by passing in nobleName
		// Then that noble gets pushed into the vecNobles.
		if (task == "Noble") {
			string nobleName;
			ifs >> nobleName;
			Noble* heapNoble = new Noble(nobleName);
			vecNobles.push_back(heapNoble);
			
			//if (checkNoble(nobleName, vecNobles)) {
			//		cout << "A Noble with this name already exists! Cannot make a noble with this name!" << endl;
			//}
			//else {
			//		Noble* heapNoble = new Noble(nobleName);
			//		vecNobles.push_back(heapNoble);
			//}

			///Handling errors: If the size of the noble is 0, can't exactly check to see if he already exists,
			//so just adds him to the vector
			//Else, iterates over the vector, checks if his name matches with a noble inside the vector's name
			// prints out he already exists, can't make him.
			// else, creates him on the heap and pushes him back.
			// DOESN'T WORK ???? 

			/*if (vecNobles.size() == 0) {
				Noble* heapNoble = new Noble(nobleName);
				vecNobles.push_back(heapNoble);
			}
			else {
				for (size_t i = 0; i < vecNobles.size(); i++) {
					if (vecNobles[i]->getNobleName() == nobleName) {
						cout << "A Noble with this name already exists! Cannot make a noble with this name!" << endl;
					}
					else {
						Noble* heapNoble = new Noble(nobleName);
						vecNobles.push_back(heapNoble);
					}
				}
			}*/
		}

		// If the first word is "Warrior" :
		// creates a string called warriorName and a float called warriorStrength
		// Then reads in from the file into warriorName and warriorStrength
		// Then creates a warrior on the heap, passing in warriorName and warriorStrength
		// Then pushes back that warrior into the inactiveWarriors vector.
		else if (task == "Warrior") {
			string warriorName;
			float warriorStrength;
			ifs >> warriorName >> warriorStrength;
			Warrior* heapWarrior = new Warrior(warriorName, warriorStrength);
			inactiveWarriors.push_back(heapWarrior);

			///Handling errors: If the size of the vector of warrior is 0, can't exactly check to see if he already exists,
			//so just adds him to the vector
			//Else, iterates over the vector, checks if his name matches with a warrior inside the vector's name
			// prints out he already exists, can't make him.
			// else, creates him on the heap and pushes him back.
			// DOESN'T WORK ???? 
			/*
			if (inactiveWarriors.size() == 0) {
				Warrior* heapWarrior = new Warrior(warriorName, warriorStrength);
				inactiveWarriors.push_back(heapWarrior);
			}
			else {
				for (size_t i = 0; i < inactiveWarriors.size(); i++) {
					if (inactiveWarriors[i]->getWarriorName() == warriorName) {
						cout << "A Warrior with this name already exists! You cannot make a warrior with this name!" << endl;
					}
					else {
						Warrior* heapWarrior = new Warrior(warriorName, warriorStrength);
						inactiveWarriors.push_back(heapWarrior);
					}
				}
			}*/
		}

		// If the first word is "Hire":
		// creates a string, hiringNoble, and another string, warriorToHire.
		// Then reads into hiringNoble and warriorToHire
		// Iterates over the vecNobles to check if the noble actually exists.
		// If yes, then iterates over the inactiveWarriors vector to check if the warrior exists.
		// Then calls the hire function from the noble
		// Sets the warrior that was hired to the back of the vector of inactiveWarriors, then pops back (he's now active)
		else if (task == "Hire") {
			string hiringNoble;
			string warriorToHire;
			ifs >> hiringNoble >> warriorToHire;
			for (size_t i = 0; i < vecNobles.size(); i++) {
				if (vecNobles[i]->getNobleName() == hiringNoble) {
					for (size_t j = 0; j < inactiveWarriors.size(); j++) {
						if (inactiveWarriors[j]->getWarriorName() == warriorToHire) {
							vecNobles[i]->hire(*(inactiveWarriors[j]));
							inactiveWarriors[j] = inactiveWarriors[inactiveWarriors.size() - 1];
							inactiveWarriors.pop_back();
						}
						// If his name could not be found in the inactiveWarrior vector, prints this out. DOESN'T WORK CORRECTLY ??
						//else {
						//	cout << "That warrior does not exist! Please hire another warrior." << endl;
						//}
					}
				}
				// If the calling noble doesn't exist inside the vector of nobles, prints this out. DOESN'T WORK CORRECTLY ??
				//else {
				//	cout << "That noble does not exist! Please select another noble." << endl;
				//}
			}
		}

		// If the first word is "Fire"
		// creates two strings, firingNoble and warriorToFire
		// Reads in from the file into firingNoble and warriorToFire
		// Then iterates over the vecNoble vector, checks if the noble that is trying to fire actually exists.
		// If he exists, calls the fire function from the Noble, passing in the warrior to fire and the vector of inactiveWarriors
		else if (task == "Fire") {
			string firingNoble;
			string warriorToFire;
			ifs >> firingNoble >> warriorToFire;
			for (size_t i = 0; i < vecNobles.size(); i++) {
				if (vecNobles[i]->getNobleName() == firingNoble) {
					vecNobles[i]->fire(warriorToFire, inactiveWarriors);
				}
				// Checks if the calling noble exists, if not, then prints this out. DOESN'T WORK CORRECTLY ??
				/*else {
					cout << "That Noble does not exist, please pick another noble to do the firing." << endl;
				}*/
			}
		}

		// If the first word is "Battle"
		// creates two strings, noble1 and noble2
		// REads in from the file into noble1 and noble2
		// Iterates over the vector of nobles, vecNobles
		// If the first noble exists, then iterates over the vector again to see if the second noble exists.
		// If yes, then calls the first noble to battle the dereference of the second noble (since its a pointer).
		else if (task == "Battle") {
			string noble1;
			string noble2;
			ifs >> noble1 >> noble2;
			for (size_t i = 0; i < vecNobles.size(); i++) {
				if (vecNobles[i]->getNobleName() == noble1) {
					for (size_t j = 0; j < vecNobles.size(); j++) {
						if (vecNobles[j]->getNobleName() == noble2) {
							vecNobles[i]->battle(*(vecNobles[j]));
						}
						// Checks if the second noble exists, if he doesn't, prints this out. DOESN'T WORK ????
						/*else {
							cout << "The second noble does not exist! Please select another noble to battle." << endl;
						}*/
					}
				}
				// Checks if the first noble exists, if he doesn't, can't call the battle. prints this out. DOESN'T WORK CORRECTLY ???
				/*else {
					cout << "The first noble does not exist! Please select another noble to battle." << endl;
				}*/
			}
		}

		// If the first word is "Status"
		// prints out Status, then Nobles
		// Iterates over the vector of Nobles, vecNobles, and calls the display function for each noble
		// If there aren't any nobles, prints out NONE (extra code I added)
		// Then prints out unemployed warriors:
		// If there aren't any inactive warriors, prints out NONE
		// Else, iterates over the vector, inactiveWarriors, then prints out the warrior's name and his strength.
		else if (task == "Status") {
			cout << "Status: " << endl << "======" << endl;
			cout << "Nobles: " << endl;
			if (vecNobles.size() == 0) {
				cout << "NONE" << endl;
			}
			else {
				for (size_t i = 0; i < vecNobles.size(); i++) {
					vecNobles[i]->display();
				}
			}
			cout << "Unemployed Warriors: " << endl;
			if (inactiveWarriors.size() == 0) {
				cout << "NONE" << endl;
			}else{
				for (size_t i = 0; i < inactiveWarriors.size(); i++) {
					cout << inactiveWarriors[i]->getWarriorName() << ": " << inactiveWarriors[i]->getWarriorStrength() << endl;
				}
			}
		}

		// If the first word is "Clear"
		// iterates over the vector vecNobles, and deletes each noble in the vector (since they were created on the heap)
		// Then clears the vector to get rid of the pointers.
		// also iterates over the vector inactiveWarriors, and deletes each warrior in the vector (created on heap)
		// Then clears the vector to get rid of the pointers.
		else if (task == "Clear") {
			for (size_t x = 0; x < vecNobles.size(); x++) {
				delete vecNobles[x];
			}
			vecNobles.clear();
			for (size_t y = 0; y < inactiveWarriors.size(); y++) {
				delete inactiveWarriors[y];
			}
			inactiveWarriors.clear();
		}
	}

	// Closing the file after we're done with it.
	ifs.close();

	system("pause");
}