/*
Jacky Teoh - jt2908
Homework 3 - Association
hw 03.cpp
*/

#include <iostream>
#include <string>
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
void Warrior::display() const{
	cout << getWarriorName() << ": " << getWarriorStrength() << endl;
}

// Noble class
class Noble {
public:
	// Noble constructor, taking in a string for the noble's name.
	Noble(string newName) : nobleName(newName) {}
	// Hire function, taking in a warrior by reference, because we're pushing it back into a vector of Warrior pointers.
	void hire(Warrior& h);
	// Fire function, taking in a warrior by reference, because we're removing it from a vector of Warrior pointers.
	void fire(Warrior& f);
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

// Fire function, takes in a Warrior by reference,
// Iterates over the vector of Warriors, and checks if the warrior's name in the vector is the same as the one that is passed in.
// Then creates a variable called temp of the warrior at that position,
// Then iterates again over the vector, but only until the second to last item in that vector
// Sets army[i] to army[j] to swap them, and then sets army[j] to temp.
// Keeps doing this until temp is at the end of the vector. Then pop back will remove the warrior that is to be fired.
// Prints out who got fired, and by which noble.
// Then decreases the army strength of the noble by the warrior's strength that was fired.
void Noble::fire(Warrior& f) {
	for (size_t i = 0; i < army.size(); i++) {
		if (army[i]->getWarriorName() == f.getWarriorName()) {
			Warrior* temp = army[i];
			for (size_t j = i; j < army.size() - 1; j++) {
				army[i] = army[j];
				army[j] = temp;
			}
		}
	}
	army.pop_back();
	cout << f.getWarriorName() << ", you're fired !! -- " << getNobleName() << endl << endl;
	armyStrength -= f.getWarriorStrength();
}

// Display function, then prints out the name of the noble, as well as the size of his army vector.
// Then iterates over his army vector, and calls the display function for each warrior in his army
// Which prints out the warrior's name and his strength.
void Noble::display() const{
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

int main() {
	Noble art("King Arthur");
	Noble lance("Lancelot du Lac");
	Noble jim("Jim");
	Noble linus("Linus Torvalds");
	Noble billie("Bill Gates");

	Warrior cheetah("Tarzan", 10);
	Warrior wizard("Merlin", 15);
	Warrior theGovernator("Conan", 12);
	Warrior nimoy("Spock", 15);
	Warrior lawless("Xena", 20);
	Warrior mrGreen("Hulk", 8);
	Warrior dylan("Hercules", 3);

	jim.hire(nimoy);
	lance.hire(theGovernator);
	art.hire(wizard);
	lance.hire(dylan);
	linus.hire(lawless);
	billie.hire(mrGreen);
	art.hire(cheetah);

	jim.display();
	lance.display();
	art.display();
	linus.display();
	billie.display();

	art.fire(cheetah);
	art.display();

	art.battle(lance);
	jim.battle(lance);
	linus.battle(billie);
	billie.battle(lance);

	jim.display();
	lance.display();
	art.display();
	linus.display();
	billie.display();

	system("pause");
}