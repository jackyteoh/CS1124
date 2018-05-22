#ifndef NOBLE_H
#define NOBLE_H

#include <iostream>
#include <string>
#include <vector>

namespace WarriorCraft {
	class Warrior;

	// Noble class
	class Noble {
	public:
		// Noble constructor, taking in a string for the noble's name.
		Noble(std::string newName) : nobleName(newName) {}
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
		std::string getNobleName() const;
		// Overloading the cout operator as a friend so cpp can access privates
		friend std::ostream& operator<<(std::ostream& os, const Noble& rhs);
		// Ranaway function for the Noble
		void ranaway(Warrior& r);
	private:
		std::string nobleName;
		// Each noble has an army, which is a vector of Warrior pointers.
		std::vector<Warrior*> army;
		float armyStrength;
	};
}

#endif