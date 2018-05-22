#include "Noble.h"
#include "Warrior.h"

using namespace std;

namespace WarriorCraft {
	// Hire function, takes in a Warrior by reference, pushes it back into the vector of Warrior pointers, army,
	// Then adds the strength of the warrior to the total army strength.
	// hiBoss function takes in a noble and sets boss = to the noble passed in. 
	// After a warrior is hired, passes in *this into hiBoss to link the two.
	void Noble::hire(Warrior& h) {
		army.push_back(&h);
		armyStrength = armyStrength + h.getWarriorStrength();
		h.hiBoss(*this);
	}

	// Fire function, takes in a Warrior by reference,
	// Iterates over the vector of Warriors, and checks if the warrior's name in the vector is the same as the one that is passed in.
	// Then sets that warrior to the end of the army.
	// Calls byeBoss function on that warrior which removes the boss from that specific warrior.
	// Pops back the warrior.
	// Prints out who got fired, and by which noble.
	// Then decreases the army strength of the noble by the warrior's strength that was fired.
	void Noble::fire(Warrior& f) {
		for (size_t i = 0; i < army.size(); i++) {
			if (army[i]->getWarriorName() == f.getWarriorName()) {
				army[i] = army[army.size() - 1];
				army[i]->byeBoss();
			}
		}
		army.pop_back();
		cout << f.getWarriorName() << ", you're fired !! -- " << getNobleName() << endl << endl;
		armyStrength -= f.getWarriorStrength();
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

	// Getter function for the name of the noble.
	string Noble::getNobleName() const {
		return nobleName;
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

	// Overloaded output operator
	// Prints out name of the noble, with his army size.
	// Then iterates over the army, and prints out each warrior wtih his strength in the army
	// returns os
	ostream& operator<<(ostream& os, const Noble& rhs) {
		os << rhs.getNobleName() << " has an army of " << rhs.army.size() << endl;
		for (size_t i = 0; i < rhs.army.size(); i++) {
			os << rhs.army[i]->getWarriorName() << ": " << rhs.army[i]->getWarriorStrength() << endl;
		}
		cout << endl;
		return os;
	}

	// Ranaway function
	// Basically does the same as the fire function, except it prints out who left instead of saying
	// they got fired.
	void Noble::ranaway(Warrior& r) {
		for (size_t i = 0; i < army.size(); i++) {
			if (army[i]->getWarriorName() == r.getWarriorName()) {
				army[i] = army[army.size() - 1];
				army[i]->byeBoss();
			}
		}
		army.pop_back();
		cout << r.getWarriorName() << " flees in terror, abandoning his lord, " << getNobleName() << endl;
		armyStrength -= r.getWarriorStrength();
	}
}