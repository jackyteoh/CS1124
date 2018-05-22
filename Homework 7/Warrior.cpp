#include "Warrior.h"
#include "Noble.h"

using namespace std;

namespace WarriorCraft {
	// Display function to display the warrior's name and his strength.
	void Warrior::display() const {
		std::cout << getWarriorName() << ": " << getWarriorStrength() << endl;
	}

	// Getter function for the Warrior's name
	string Warrior::getWarriorName() const {
		return warriorName;
	}

	// Getter function for the Warrior's strength
	float Warrior::getWarriorStrength() const {
		return warriorStrength;
	}

	// Setter function for the Warrior's strength, multiplies his strength by the value passed in, x (Ratio)
	void Warrior::setWarriorStrength(float x) {
		warriorStrength = warriorStrength * x;
	}
	
	// Runaway function
	void Warrior::runaway() {
		boss->ranaway(*this);
	}

	// Changes boss to nullptr
	void Warrior::byeBoss() {
		boss = nullptr;
	}

	// Changes boss to boss
	void Warrior::hiBoss(Noble& n) {
		boss = &n;
	}
}