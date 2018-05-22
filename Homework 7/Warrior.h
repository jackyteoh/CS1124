#ifndef WARRIOR_H
#define WARRIOR_H

#include <string>
#include <iostream>

namespace WarriorCraft {
	class Noble; 

	// Warrior class
	class Warrior {
	public:
		// Warrior constructor, taking in a string name, and a float strength.
		Warrior(std::string givenName, float givenStrength) : warriorName(givenName), warriorStrength(givenStrength),
		boss(nullptr) {}
		// Getter function for the Warrior's name
		std::string getWarriorName() const;
		// Getter function for the Warrior's strength
		float getWarriorStrength() const;
		// Setter function for the Warrior's strength, multiplies his strength by the value passed in, x (Ratio)
		void setWarriorStrength(float x);
		// Display function
		void display() const;
		// Runaway function
		void runaway();
		// Change boss to nullptr
		void byeBoss();
		// Change boss to boss
		void hiBoss(Noble& n);
	private:
		std::string warriorName;
		float warriorStrength;
		Noble* boss;
	};
}

#endif