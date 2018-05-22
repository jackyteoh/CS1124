/*
Jacky Teoh - jt2908
CS 1124 - Rec 07 : More Inheritance
10.21.2016
rec 07.cpp
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Instrument Class
class Instrument {
public:
	// Making the makeSound function pure virtual, so no instance/object of Instrument can be made, but it can be overridden.
	virtual void makeSound() = 0;
	// Making the normalPlay function pure virtual, so no instance/object of Instrument can be made, but it can be overridden.
	virtual void normalPlay() = 0;
};

// Brass class, which inherits from public of Instrument
class Brass : public Instrument {
public:
	// Brass constructor, taking in an unsigned mouthPiece, assigns it to mouthpieceSize
	Brass(unsigned mouthPiece) : mouthpieceSize(mouthPiece) {}
	// The general makeSound function for a brass. Used for the MILL's test play.
	void makeSound() {
		cout << "Trumpet/Trombone : To make a sound... blow on a mouthpiece of size 9." << endl;
	}
	// normalPlay still needs to be specified in later derived classes, so no need to write it again.
	// Inherently?/Implicitly? implied that normalPlay is still pure virtual even though it's not specified.
private:
	unsigned mouthpieceSize;
};

// Trumpet class, which inherits from the public of Brass
class Trumpet : public Brass {
public:
	// Trumpet constructor, takes in an unsigned newPiece, calls the Brass constructor and passes in newPiece
	Trumpet(unsigned newPiece) : Brass(newPiece) {};
	// Overridden normalPlay function for the Trumpet.
	void normalPlay() {
		cout << "Toot" << endl;
	}
};

// Trombone class, which inherits from the public of Brass.
class Trombone : public Brass {
public:
	// Trombone constructor, which takes in an unsigned newPiece, calls the Brass constructor and passes in newPiece
	Trombone(unsigned newPiece) : Brass(newPiece) {};
	// Overridden normalPlay function for the Trombone.
	void normalPlay() {
		cout << "Blat" << endl;
	}
};

// String class, which inherits from the public of Instrument
class String : public Instrument {
public:
	// String constructor, taking in an unsigned newPitch and assigning newPitch to pitch.
	String(unsigned newPitch) : pitch(newPitch) {}
	// The general makeSound function for a string. Used for the MILL's test play.
	void makeSound() {
		cout << "Violin / Cello : To make a sound... bow a string with a pitch 567." << endl;
	}
	// normalPlay still needs to be specified in later derived classes, so no need to write it again.
	// Inherently?/Implicitly? implied that normalPlay is still pure virtual even though it's not specified.
private:
	unsigned pitch;
};

// Violin class, which inherits from the public of String
class Violin : public String {
public:
	// Violin constructor, which takes in an unsigned newPitch and calls the String constructor and passes in newPitch
	Violin(unsigned newPitch) : String(newPitch) {}
	// Overridden normalPlay function for the Violin.
	void normalPlay() {
		cout << "Screech" << endl;
	}
};

// Cello class, which inherits from the public of String
class Cello : public String {
public:
	// Cello constructor, which takes in an unsigned newPitch, and calls the String constructor and passes in newPitch.
	Cello(unsigned newPitch) : String(newPitch) {}
	// Overridden normalPlay function for the Cello
	void normalPlay() {
		cout << "Squawk" << endl;
	}
};

// Percussion class, which inherits from the public of Instrument.
class Percussion : public Instrument {
public:
	// Percussion constructor, has no parameters nor does anything.
	Percussion() {}
	// General makeSound function for Percussion class. Used for MILL testPlay()
	void makeSound() {
		cout << "Drum / Cymbal : To make a sound... hit me!" << endl;
	}
	// normalPlay still needs to be specified in later derived classes, so no need to write it again.
	// Inherently?/Implicitly? implied that normalPlay is still pure virtual even though it's not specified.
};

// Drum class, which inherits from the public of Percussion
class Drum : public Percussion {
public:
	// Drum constructor, takes no parameters nor does anything.
	Drum() {}
	// Overridden normalPlay function for the Drums.
	void normalPlay() {
		cout << "Boom" << endl;
	}
};

// Cymbal class, which inherits from the public of Percussion
class Cymbal : public Percussion {
public:
	// Cymbal constructor, takes in no parameters nor does anything.
	Cymbal() {}
	// Overridden normalPlay function for the Cymbals.
	void normalPlay() {
		cout << "Crash" << endl;
	}
};

// Musical Instrument Lending Library class
class MILL {
public:
	// MILL constructor, takes in no parameters nor does anything.
	MILL() {}
	// loanOut function, which returns an Instrument*
	Instrument* loanOut() {
		// First checks to see if there ARE any instruments, if not, returns nullptr.
		if (vectorOfInstruments.size() == 0) {
			return nullptr;
		}
		// If there are instruments, first creates a instrument* x, then sets it equal to the first object in that vector
		// Then sets the first object of the vector to the last object of the vector.
		// Removes the last object in the vector (it's been loaned out)
		// Then returns the instrument*
		else {
			for (size_t i = 0; i < vectorOfInstruments.size(); i++) {
				Instrument* x;
				x = vectorOfInstruments[0];
				vectorOfInstruments[0] = vectorOfInstruments[vectorOfInstruments.size() - 1];
				vectorOfInstruments.pop_back();
				return x;
			}
		}
	}
	// receiveInstr function, takes in an instrument by reference. Pushes the ADDRESS of it back into the vector of Instrument*
	void receiveInstr(Instrument& i) {
		vectorOfInstruments.push_back(&i);
	}
	// dailyTestPlay function, iterates over the vector, calls the makeSound function for each instrument.
	void dailyTestPlay() {
		for (size_t i = 0; i < vectorOfInstruments.size(); i++) {
			vectorOfInstruments[i]->makeSound();
		}
	}
private:
	// Vector of Instrument* inside the MILL
	vector<Instrument*> vectorOfInstruments;
};

// Musician class
class Musician {
public:
	// Musician constructor, takes in no parameters but initializes instr to NULL
	Musician() : instr(NULL) {}
	// acceptInstr function, takes in an instrument by reference, and sets instr* = address of instrument passed in.
	void acceptInstr(Instrument& i) {
		instr = &i;
	}
	// giveBackInstr function, sets their Instrument* instr data member back to NULL, they've returned their instrument.
	Instrument* giveBackInstr() {
		Instrument* tmp(instr);
		instr = NULL;
		return tmp;
	}
	// testPlay function, if they have an instrument, (instr != nullptr), calls makeSound for that instrument.
	// else prints out that they have no instrument.
	void testPlay() const {
		if (instr)
			instr->makeSound();
		else
			cerr << "have no instr\n";
	}
	// normalPlay function, for PART 2. 
	// If they have an instrument, (instr != nullptr), calls the normalPlay function for that instrument.
	// If they don't, prints out that they have no instrument.
	void normalPlay() const {
		if (instr) {
			instr->normalPlay();
		}
		else {
			cout << "have no instr\n";
		}
	}
private:
	// Each musician has a instrument pointer.
	Instrument* instr;
};

// Orchestra class
class Orch {
public:
	// addPlayer function, takes in a musician by reference
	// If the orchestra has less than 25 musicians, pushes back the ADDRESS of the musician into the vector of Musician*
	// If the orchestra is already at its max size (25), it'll cout it's full and won't allow the musician to join.
	void addPlayer(Musician& m) {
		if (vectorOfMusicians.size() < 25) {
			vectorOfMusicians.push_back(&m);
		}
		else {
			cout << "It's full" << endl;
		}
	}
	// play function for the Orchestra, takes in no parameters.
	// Iterates over the vector, and for each musician, calls the normalPlay function, which then calls the normalPlay
	// for each instrument.
	void play() {
		for (size_t i = 0; i < vectorOfMusicians.size(); i++) {
			vectorOfMusicians[i]->normalPlay();
		}
	}
private:
	// Vector of Musician*
	vector<Musician*> vectorOfMusicians;
};

int main() {
	/*
	------------------------------------------- PART 1 ------------------------------------------------------------
	cout << "Define some instruments ----------------------------------------\n";
	Drum drum;
	Cello cello(673);
	Cymbal cymbal;
	Trombone tbone(4);
	Trumpet trpt(12) ;
	Violin violin(567) ;

	// // use the debugger to look at the mill
	cout << "Define the MILL ------------------------------------------------\n";
	MILL mill;

	cout << "Put the instruments into the MILL ------------------------------\n";
	mill.receiveInstr( trpt );
	mill.receiveInstr( violin );
	mill.receiveInstr( tbone );
	mill.receiveInstr( drum );
	mill.receiveInstr( cello );
	mill.receiveInstr( cymbal );

	cout << "Daily test -----------------------------------------------------\n";
	cout << endl;
	cout << "dailyTestPlay()" << endl;
	mill.dailyTestPlay();
	cout << endl;

	cout << "Define some Musicians-------------------------------------------\n";
	Musician j;
	Musician jj;
	Musician q;

	cout << "TESTING: q.acceptInstr( *mill.loanOut() );-----------------------\n";
	q.testPlay();	
	cout << endl;
	q.acceptInstr( *mill.loanOut() );
	cout << endl;
	q.testPlay();
	cout << endl;
	cout << "dailyTestPlay()" << endl;
	mill.dailyTestPlay();

	cout << endl << endl;

	q.testPlay();	
	cout << endl;
	mill.receiveInstr( *q.giveBackInstr() );
	j.acceptInstr( *mill.loanOut() );
	q.acceptInstr( *mill.loanOut() );
	cout << endl;
	q.testPlay();
	cout << endl;
	j.testPlay();
	cout << endl;
	cout << "dailyTestPlay()" << endl;
	mill.dailyTestPlay();

	cout << "TESTING: mill.receiveInstr( *q.giveBackInstr() ); -------------\n";

	// // fifth
	mill.receiveInstr( *q.giveBackInstr() );
	cout << "TESTING: mill.receiveInstr( *j.giveBackInstr() ); -------------\n";
	mill.receiveInstr( *j.giveBackInstr() );


	cout << endl;
	cout << "dailyTestPlay()" << endl;
	mill.dailyTestPlay();
	cout << endl;

	cout << endl;
	------------------------------------------- PART 1 ------------------------------------------------------------
	*/

	/*------------------------------------------- PART 2 ------------------------------------------------------------*/
	// The initialization phase

	Drum drum;
	Cello cello(673);
	Cymbal cymbal;
	Trombone tbone(4);
	Trumpet trpt(12);
	Violin violin(567);

	MILL mill;
	mill.receiveInstr(trpt);
	mill.receiveInstr(violin);
	mill.receiveInstr(tbone);
	mill.receiveInstr(drum);
	mill.receiveInstr(cello);
	mill.receiveInstr(cymbal);

	Musician bob;
	Musician sue;
	Musician mary;
	Musician ralph;
	Musician jody;
	Musician morgan;

	Orch orch;

	// THE SCENARIO

	//Bob joins the orchestra without an instrument.
	orch.addPlayer(bob);

	//The orchestra performs
	cout << "orch performs\n";
	orch.play();

	//Sue gets an instrument from the MIL2 and joins the orchestra.
	sue.acceptInstr(*mill.loanOut());
	orch.addPlayer(sue);

	//Ralph gets an instrument from the MIL2.
	ralph.acceptInstr(*mill.loanOut());

	//Mary gets an instrument from the MIL2 and joins the orchestra.
	mary.acceptInstr(*mill.loanOut());
	orch.addPlayer(mary);

	//Ralph returns his instrument to the MIL2.
	mill.receiveInstr(*ralph.giveBackInstr());

	//Jody gets an instrument from the MIL2 and joins the orchestra.
	jody.acceptInstr(*mill.loanOut());
	orch.addPlayer(jody);

	// morgan gets an instrument from the MIL2
	morgan.acceptInstr(*mill.loanOut());

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	//Ralph joins the orchestra.
	orch.addPlayer(ralph);

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	// bob gets an instrument from the MIL2
	bob.acceptInstr(*mill.loanOut());

	// ralph gets an instrument from the MIL2
	ralph.acceptInstr(*mill.loanOut());

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	//Morgan joins the orchestra.
	orch.addPlayer(morgan);

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	/*------------------------------------------- PART 2 ------------------------------------------------------------*/

	system("pause");
}