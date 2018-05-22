/*
Jacky Teoh - jt2908
CS 1124 - Homework 6 : Inheritance
11.02.2016
hw 06.cpp
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Lord;
class Noble;

// Protector class (Parent class)
class Protector {
public:
	// Protector constructor, taking in a string(newName) and a float(newStrength)
	// Initializes the protectorName, protectorStrength, and hired to false, since no one has a lord when created
	// Also initializes their hired lord pointer to nullptr since no one has a lord when created
	Protector(const string& newName, float newStrength) :
		protectorName(newName), protectorStrength(newStrength), hired(false), lord(nullptr) {}
	// Virtual getter for the name of the protector
	virtual string getProtectorName() const {
		return protectorName;
	}
	// Virtual getter for the strength of the protector
	virtual float getProtectorStrength() const {
		return protectorStrength;
	}
	// Virtual setter for the strength of the protector, multiplies his/her strength by x
	virtual void setProtectorStrength(float x) {
		protectorStrength *= x;
	}
	// Virtual display for the protector, prints out his name with his strength (extra)
	virtual void display() const {
		cout << getProtectorName() << ": " << getProtectorStrength() << endl;
	}
	// Pure virtual function to make sure no one can create an instance of Protector unless overridden
	virtual void attack() const = 0;
	// virtual gotHired function, sets hired = to true
	virtual void gotHired() {
		hired = true;
	}
	// virtual gotFired function, sets hired = to false
	virtual void gotFired() {
		hired = false;
	}
	// virtual hireStatus function, returns the hire status of the protector(true/false)
	virtual bool hireStatus() const {
		return hired;
	}
	// Declaring Lord setter function, passing in a lord pointer
	void setLord(Lord* l);
	// Declaring Lord getter function
	string getLordName() const;
private:
	string protectorName;
	float protectorStrength;
	bool hired;
	Lord* lord;
};

// Warrior class (Derived from Protector)
class Warrior : public Protector {
public:
	// Warrior constructor, taking in a string name, and a float strength, initializes by calling Protector constructor
	Warrior(const string& givenName, float givenStrength) : Protector(givenName, givenStrength) {}
	// Getter function for the Warrior's name, calls Protector's getter
	string getWarriorName() const {
		return Protector::getProtectorName();
	}
	// Getter function for the Warrior's strength, calls Protector's getter
	float getWarriorStrength() const {
		return Protector::getProtectorStrength();
	}
	// Setter function for the Warrior's strength, calls Protector's setter
	void setWarriorStrength(float x) {
		Protector::setProtectorStrength(x);
	}
	// Display function
	void display() const;
	// Pure virtual attack function, overridden in derived classes from Warriors.
	virtual void attack() const = 0;
};

// Display function to display the warrior's name and his strength, calls Protector's display
void Warrior::display() const {
	Protector::display();
}

// Noble class (Parent class)
class Noble {
public:
	// Noble constructor, taking in a string for the noble's name, initializes isDead bool to false, when created he's alive.
	Noble(const string& newName) : nobleName(newName), isDead(false) {}
	// Getter for the noble name
	virtual string getNobleName() const {
		return nobleName;
	}
	// Pure virtual battle function
	void battle(Noble& n);
	// virtual getter for the Noble, returns strength
	virtual float getNobleStrength() const = 0;
	// virtual setter for the Noble, sets strength to x
	virtual void setNobleStrength(float x) = 0;
	// BattleCalls is virtual, to be overridden in Lord class, PersonWithStrengthToFight doesn't need it
	virtual void battleCalls() {
		return;
	}
	// Returns the status of the noble in bool
	bool liveStatus() {
		return isDead;
	}
	// Setter for status of noble, changes to true (he's dead).
	void setDead() {
		isDead = true;
	}
private:
	string nobleName;
	bool isDead;
};

// Battle function, taking in another noble by reference,
// First displays which noble is battling who,
// Then calls the battleCalls function, which was a virtual in the Noble class.
// In Lord, it is overridden so it will call that but PersonWithStrengthToFight doesn't have battlecalls, so calls
// Parent's battleCalls function which just returns.
// Then checks if the strength of the first noble's army is the same as the second noble's army.
// If both of their strength's are already 0, prints out they're both already dead.
// Otherwise, it prints out that both of the nobles lose, and sets both of their army strengths to 0.
// If they both lose, sets both of them to dead.
void Noble::battle(Noble&n) {
	cout << endl << this->getNobleName() << " battles " << n.getNobleName() << endl;
	battleCalls();
	if (this->getNobleStrength() == n.getNobleStrength()) {
		if (this->getNobleStrength() == 0 && n.getNobleStrength() == 0) {
			cout << "Oh, they're both already dead!" << endl;
			this->setDead();
			n.setDead();
		}
		else {
			cout << "Both " << this->getNobleName() << " and " << n.getNobleName() << " lose! " << endl;
			this->setNobleStrength(0);
			n.setNobleStrength(0);
			this->setDead();
			n.setDead();
		}
	}
	// If the passed in noble's strength is less than the noble's strength who's trying to battle,
	// Prints out that the noble with the lesser strength loses,
	// Then calculates the strength ratio to alter the winner's warriors.
	// If the passed in noble's army already has a strength of 0, he's already dead, and it prints that.
	// If not, calls the setArmyStrength function for the winner and passes in 1 - strengthRatio
	// Also sets the loser's army strength to 0 because he lost.
	// Sets the loser to being dead, because he lost and died.
	if (this->getNobleStrength() > n.getNobleStrength()) {
		cout << n.getNobleName() << " loses!" << endl;
		if (n.getNobleStrength() == 0) {
			cout << "He's already dead, " << this->getNobleName() << endl;
		}
		float strengthRatio;
		if (n.getNobleStrength() > 0) {
			strengthRatio = (n.getNobleStrength() / this->getNobleStrength());
		}
		else if (n.getNobleStrength() <= 0) {
			return;
		}
		this->setNobleStrength(1 - strengthRatio);
		n.setNobleStrength(0);
		n.setDead();
	}
	// Tests if the second noble's strength is higher than the first noble's.
	// Prints out that the first noble's loses if the test is true.
	// If the first noble tries to battle, but he's dead, prints out that he's already dead.
	// Then calculates the strength ratio to alter the winner's warriors.
	// If the noble's army who is trying to fight already has a strength of 0, he's already dead, and it prints that.
	// If not, calls the setArmyStrength function for the winner and passes in 1 - strengthRatio
	// Also sets the loser's army strength to 0 because he lost.
	// Sets the loser to being dead, because he lost and died.
	if (n.getNobleStrength() > this->getNobleStrength()) {
		cout << this->getNobleName() << " loses!" << endl;
		if (this->getNobleStrength() == 0) {
			cout << "He's already dead, " << n.getNobleName() << endl;
		}
		float strengthRatio;
		if (this->getNobleStrength() > 0) {
			strengthRatio = (this->getNobleStrength() / n.getNobleStrength());
		}
		else if (this->getNobleStrength() <= 0) {
			return;
		}
		n.setNobleStrength(1 - strengthRatio);
		this->setNobleStrength(0);
		this->setDead();
	}
}

// Lord class (Derived from Noble)
class Lord : public Noble {
public:
	// Lord Constructor, taking in newName, passing it into Noble constructor.
	Lord(const string& newName) : Noble(newName) {}
	// Overridden battle function
	void battle(Noble& n);
	// Hire function, taking in a warrior by reference, because we're pushing it back into a vector of Warrior pointers.
	void hire(Protector& h);
	// Fire function, taking in a warrior by reference, because we're removing it from a vector of Warrior pointers.
	void fire(Protector& f);
	// Display function for nobles
	void display() const;
	// Getter function for the army strength of the noble.
	float getNobleStrength() const;
	// Setter function for the army strength of the noble.
	void setNobleStrength(float x);
	// Each Protector in the army has a specific battle call, this iterates over the army and 
	// If the protector's strength is > 0, which means they can still fight, calls the attack from each protector
	void battleCalls() {
		for (size_t p = 0; p < army.size(); p++) {
			if (army[p]->getProtectorStrength() > 0) {
				army[p]->attack();
			}
		}
	}
private:
	// Each lord has an army, which is a vector of Protector pointers.
	vector<Protector*> army;
};

// Overridden battle function, calls the Noble's battle function.
void Lord::battle(Noble& n) {
	Noble::battle(n);
}

// First checks if the hiring noble is alive, if he is dead, he cannot hire, thus returning.
// Checks to see if Protector is not hired, 
// Hire function, takes in a Protector by reference, pushes it back into the vector of Protector pointers, army,
// Then adds the strength of the Protector to the total army strength.
// Changes hire status of Protector to hired.
// Changes the Lord for the Protector to point to the calling/hiring Lord.
void Lord::hire(Protector& h) {
	if (this->liveStatus()) {
		return;
	}
	else if (h.hireStatus() == false) {
		army.push_back(&h);
		h.gotHired();
		h.setLord(this);
	}
	else {
		cout << "This Protector is already hired by another noble!" << endl;
	}
}

// Checks to see if the lord is dead before firing, if he's dead, can't fire. (Don't know if necessary?)
// Fire function, takes in a Protector by reference,
// Iterates over the vector of Protectors, and checks if the protectors's name in the vector is the same as the one that is passed in.
// If yes, sets that Protector to the end of the vector, and pops back, thus firing him
// Prints out who got fired, and by which noble.
// Then decreases the army strength of the noble by the warrior's strength that was fired.
// Then changes the hire status of the Protector to false (not hired).
// Sets lord pointer for that protector to nullptr (he no longer has a lord).
void Lord::fire(Protector& f) {
	if (this->liveStatus()) {
		return;
	}
	for (size_t i = 0; i < army.size(); i++) {
		if (army[i]->getProtectorName() == f.getProtectorName()) {
			army[i] = army[army.size() - 1];
		}
	}
	army.pop_back();
	cout << f.getProtectorName() << ", you're fired !! -- " << getNobleName() << endl << endl;
	f.gotFired();
	f.setLord(nullptr);
}

// Display function, then prints out the name of the lord, as well as the size of his army vector.
// Then iterates over his army vector, and calls the display function for each protector in his army
// Which prints out the protector's name and his strength.
void Lord::display() const {
	cout << getNobleName() << " has an army of " << army.size() << endl;
	for (Protector* p : army) {
		p->display();
	}
	cout << endl;
}

// Getter function for the army strength of the lord, 
// Adds all the strengths of the warriors within the army
// Then sets that strength to the variable armyStrength
// Then returns the value created, armyStrength
float Lord::getNobleStrength() const {
	float armyStrength = 0;
	for (size_t p = 0; p < army.size(); p++) {
		armyStrength += army[p]->getProtectorStrength();
	}
	return armyStrength;
}

// Setter function for the army strength of the lord, takes in the battle ratio, float, as a parameter.
// Iterates over the army of Protector*
// Then changes each protector's strength by calling setProtector strength on each protector
// Passes in the battle ratio to the setProtectorStrength
void Lord::setNobleStrength(float x) {
	for (int i = 0; i < army.size(); i++) {
		army[i]->setProtectorStrength(x);
	}
}

// Protector's setLord, passes in a lord* and sets their pointer = to the pointer passed in.
void Protector::setLord(Lord* l) {
	lord = l;
}

// Getter for the Lord's name, which calls the getNobleName from the Lord
string Protector::getLordName() const {
	return lord->getNobleName();
}

// PersonWithStrengthToFight class, which inherits from Noble
// Takes in string for name and strength, initializes by calling Noble's constructor, and selfStrength(newStrength)
class PersonWithStrengthToFight : public Noble {
public:
	PersonWithStrengthToFight(const string& newName, float newStrength) : Noble(newName), selfStrength(newStrength) {}
	// Getter for the strength
	float getNobleStrength() const {
		return selfStrength;
	}
	// Setter for the strength
	void setNobleStrength(float x) {
		selfStrength *= x;
	}
	// Overridden battle function, calls the Noble's battle function.
	void battle(Noble& n) {
		Noble::battle(n);
	}
private:
	float selfStrength;
};

// Archer class, inherits from public Warrior. 
// Constructor takes in string and strength, passes into Warrior constructor,
// Has it's own attack function.
class Archer : public Warrior {
public:
	Archer(const string& newName, float newStrength) : Warrior(newName, newStrength) {}
	void attack() const;
};

// Archers have a specific attack call, which says TWANG, their name, then a quote, then their lord's name.
void Archer::attack() const {
	cout << "TWANG! " << getProtectorName() << " says: Take that in the name of my lord, " << getLordName() << endl;
}

// Swordsman class, inherits from public Warrior. 
// Constructor takes in string and strength, passes into Warrior constructor,
// Has it's own attack function.
class Swordsman : public Warrior {
public:
	Swordsman(const string& newName, float newStrength) : Warrior(newName, newStrength) {}
	void attack() const;
};

// Swordsmen have a specific attack call, which says CLANG, their name, a quote, then their lord's name.
void Swordsman::attack() const {
	cout << "CLANG! " << getProtectorName() << " says: Take that in the name of my lord, " << getLordName() << endl;
}

// Wizard class, inherits from public Protector. 
// Constructor takes in string and strength, passes into Protector constructor,
// Has it's own attack function.
class Wizard : public Protector {
public:
	Wizard(const string& newName, float newStrength) : Protector(newName, newStrength) {}
	void attack() const;
};

// Wizards just say Poof.
void Wizard::attack() const {
	cout << "POOF!" << endl;
}

int main() {
	Lord sam("Sam");
	Archer samantha("Samantha", 200);
	sam.hire(samantha);
	Lord joe("Joe");
	PersonWithStrengthToFight randy("Randolf the Elder", 250);
	joe.battle(randy);
	joe.battle(sam);
	Lord janet("Janet");
	Swordsman hardy("TuckTuckTheHardy", 100);
	Swordsman stout("TuckTuckTheStout", 80);
	janet.hire(hardy);
	janet.hire(stout);
	PersonWithStrengthToFight barclay("Barclay the Bold", 300);
	janet.battle(barclay);
	janet.hire(samantha);
	Archer pethora("Pethora", 50);
	Archer thora("Thorapleth", 60);
	Wizard merlin("Merlin", 150);
	janet.hire(pethora);
	janet.hire(thora);
	sam.hire(merlin);
	janet.battle(barclay);
	sam.battle(barclay);
	joe.battle(barclay);

	system("pause");
}