#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Complex {
	double real;
	double img;
};

class PlainOldClass {
public:
	PlainOldClass() : x(-72) {}
	int getX() const { return x; }
	void setX(int val) { x = val; }
private:
	int x;
};

class Colour {
public:
	Colour(const string& name, unsigned r, unsigned g, unsigned b)
		: name(name), r(r), g(g), b(b) {}
	void display() const {
		cout << name << " (RBG: " << r << "," << g << "," << b << ")";
	}
private:
	string   name;    // what we call this colour
	unsigned r, g, b; // red/green/blue values for displaying
};

class SpeakerSystem {
public:
	void vibrateSpeakerCones(unsigned signal) const {
		cout << "Playing: " << signal << "Hz sound..." << endl;
		cout << "Buzz, buzzy, buzzer, bzap!!!\n";
	}
};

class Amplifier {
public:
	void attachSpeakers(/* const */ SpeakerSystem& spkrs)
	{
		if (attachedSpeakers)
			cout << "already have speakers attached!\n"; // If you attach another speaker system, overrides old speaker system. Only one speaker system at a time
		else
			attachedSpeakers = &spkrs;
	}
	void detachSpeakers()
	{
		attachedSpeakers = NULL;
	}
	// should there be an "error" message if not attached?
	void playMusic() const {
		if (attachedSpeakers)
			attachedSpeakers->vibrateSpeakerCones(440);
		else
			cout << "No speakers attached\n";
	}
private:
	/* const */ SpeakerSystem* attachedSpeakers = NULL;
};

class Person {
public:
	Person(const string& name) : name(name) {}
	void movesInWith(Person& newRoomate) {
		roomie = &newRoomate;        // now I have a new roomie            
		newRoomate.roomie = this;    // and now they do too       
	}
	string getName() const { return name; }
	// Don't need to use getName() below, just there for you to use in debugging.
	string getRoomiesName() const { return roomie->getName(); }
private:
	Person* roomie;
	string name;
};

int main() {
	// Task 2
	int x;
	x = 10;
	cout << "x = " << x << endl;

	// Task 8
	int* p;
	p = &x;
	cout << "p = " << p << endl;

	// Task 9
	// p = 0x00b3f774;

	// Task 10
	cout << "p points to where " << *p << " is stored." << endl;
	cout << "*p contains " << *p << endl;

	// Task 11
	*p = -2763; // Changing the value that p points to. which is the value of x
	cout << "p points to where " << *p << " is stored." << endl;
	cout << "*p now contains " << *p << endl;
	cout << "x now contains " << x << endl;

	// Task 12
	int y(13);
	cout << "y contains " << y << endl; // y is now 13
	p = &y;                             // p points to the address of 13
	cout << "p now points to where " << *p << " is stored\n";
	cout << "*p now contains " << *p << endl; // 13
	*p = 980;
	cout << "p points to where " << *p << " is stored\n"; // Changes value of y to 980
	cout << "*p now contains " << *p << endl;             // 980
	cout << "y now contains " << y << endl;               // 980

	// Task 13
	int* q;
	q = p;
	cout << "q points to where " << *q << " is stored\n"; // Dereferences q, which dereferences p
	cout << "*q contains " << *q << endl;                 // q contains 980 (From task 12)

	// Task 14
	double d(33.44);
	double* pD(&d);
	*pD = *p; // Changes value of p to dereference value of pD which is 33.44
	*pD = 73.2343;
	*p = *pD; // double can be cast to an int
	*q = *p;  // int can be cast to a double ?
	// pD = p;  <-- Can't change address of different pointer types ?
	// p = pD;  <-- Int pointer cannot be cast to double pointer
	// Int* cannot be cast to a double*, but an int can be cast to a double
	// Double* cannot be cast to an int*, but double can be cast to an int

	// Task 15
	int joe(24);
	const int sal(19);
	int*  pI;
	//  pI = &joe;  <-- Works.
	// *pI = 234;   <-- Works. joe isn't a const int.
	//  pI = &sal;  <-- Doesn't work, can't point a regular integer pointer to a constant integer pointer
	// *pI = 7623;  <-- Works because pI is still pointing to address of joe, which is a regular integer.

	const int* pcI;
	//  pcI = &joe;  // Works. const int pointers can be cast to a regular int
	// *pcI = 234;   // Doesn't work. can't change the value of a constant integer pointer
	//  pcI = &sal;  // Works. Can point a const int pointer to a const int.
	// *pcI = 7623;  // Doesn't work. Can't change the value of a constant integer

	// int* const cpI;       // Currently pointing to nothing (?) (Says needs initialization)
	// int* const cpI(&joe); // Doesn't work. You can't change the address of a constant pointer
	// int* const cpI(&sal); // Doesn't work. You can't change the address of a constant pointer, even to a constant int
	//  cpI = &joe;          // Doesn't work. Constant pointer can't change address.
	// *cpI = 234;           // Works. Constant pointers can change the value of the integer it's pointing to.
	//  cpI = &sal;          // Doesn't work(?). Can't change address of a constant pointer, even to a constant int(?)
	// *cpI = 7623;          // Works. Constant pointers can change the value of the integer it's pointing to.

	// const int* const cpcI;           // Constant pointer to a constant integer, cpcI.
	//const int* const cpcI(&joe);      // Doesn't work. Can't change the address of a constant pointer. Initialized pointer to address of joe is ok.
	//const int* const cpcI(&sal);      // Doesn't work. Can't change the address of a constant pointer. Initialized pointer to address of sal is ok.
	//  cpcI = &joe;                    // Doesn't work. Can't change the address of a constant pointer  Can't change from address of sal to address of joe.
	// *cpcI = 234;                     // Doesn't work. Can't change the value of a constant integer pointer. 
	//  cpcI = &sal;                    // Doesn't work. Can't change the address of a constant pointer. Can't change from address of joe to address of sal.
	// *cpcI = 7623;                    // Doesn't work. Can't change the value of a constant integer pointer.

	// Task 16
	Complex c = { 11.23, 45.67 };
	Complex* pC(&c);
	// cout << "real: " << *pC.real << endl << "imaginary: " << *pC.img << endl;     // Tries to access real and img values first, takes precedence before dereference operator.
	// cout << "real: " << (*pC).real << endl << "imaginary: " << (*pC).img << endl; // Not the right way to do it.
	cout << "real: " << pC->real << endl << "imaginary: " << pC->img << endl;        // Correct way.

	// Task 17
	/*
	class PlainOldClass {
	public:
	PlainOldClass() : x(-72) {}
	int getX() const { return x; }
	void setX(int val) { x = val; }
	private:
	int x;
	};
	*/
	PlainOldClass poc;            // Creates a PlainOldClass object, initialized x to -72.
	PlainOldClass* ppoc(&poc);    // Creates a PlainOldClass pointer, which points to poc object.
	cout << ppoc->getX() << endl; // Dereferences poc object, accesses getX() value, which is -72.
	ppoc->setX(2837);             // Dereferences poc object, accesses setX(), which changes value of x to 2837.
	cout << ppoc->getX() << endl; // Dereferences poc object, accesses getX() value, which is now 2837.

	// Task 18
	/*
	class PlainOldClass {
	public:
		 PlainOldClass() : x(-72) {}
		 int getX() const { return x; }
		 void setX( int x )  { x = x; } // HMMMM???
	private:
         int x;
	};

	int getX( const PlainOldClass* const this = &poc ) const { return x; }              // Same as above.
	void setX( PlainOldClass* const this = &poc, int x )  { x = x; } // Still HMMMM???  // Same as above.

	void setX( int x )  { this->x = x; } // No confusion! Before adding the dereferencing of parameter this, you were assigning the parameter x to itself.
	*/

	// Task 19
	int* pDyn = new int(3); // pDyn points to an int initialized to 3 on the heap      
	*pDyn = 17;             // Now pDyn's value is changed to 17. MEMORY LEAK. Didn't delete the int 3 on the heap

	// Task 20
	cout << pDyn << endl;   // prints out address of pDyn
	delete pDyn;            // Deletes the heap space that pDyn points to. (3?)
	cout << pDyn << endl;   // Still prints out the address of pDyn

	// cout << "The 17 might STILL be stored at address " << pDyn << " even though we deleted pDyn\n";
    // cout << "But can we dereference pDyn?  We can try.  This might crash... " << *pDyn << ".  Still here?\n";

	// Task 21
	pDyn = nullptr;
	double* pDouble(nullptr);

	// Task 22
	// cout << "Can we dereference NULL?  " << *pDyn << endl;       // CANNOT DEREFERENCE NULL/NULLPTR.
	// cout << "Can we dereference NULL?  " << *pDouble << endl;    // CANNOT DEREFERENCE NULL/NULLPTR.

	// Task 23
	// this can be a nullptr
	/*
	Think about that "this" pointer - can it ever be NULL (contain the value NULL)?
	DUH!!! It's the address of the object that a method is invoked on.
	How can it ever be not pointing to something?
	*/

	// Task 24
	double* pTest = new double(12);
	delete pTest;
	pTest = NULL;
	delete pTest; // safe
	// YOU CAN DELETE NULL/NULLPTRS.

	// Task 25
	short* pShrt = new short(5);
	delete pShrt;
	// delete pShrt;      // Double Delete, crashes program. CANNOT DO.

	// Task 26
	/*
	long jumper(12238743);
	delete jumper;
	long* ptrTolong(&jumper);
	delete ptrTolong;
	Complex cmplx;
	delete cmplx;
	*/
	// You only need to delete space you created on the heap. One "delete" for every one "new". No need to free up space created on the stack.

	// Task 27
	vector<Complex*> complV; // can hold pointers to Complex objects
	Complex* tmpPCmplx;      // space for a Complex pointer
	for (size_t ndx = 0; ndx < 3; ++ndx) {
		tmpPCmplx = new Complex; // create a new Complex object on the heap
		tmpPCmplx->real = ndx;   // set real and img to be the
		tmpPCmplx->img = ndx;   // value of the current ndx
		complV.push_back(tmpPCmplx); // store the ADDRESS of the object in a vector or pointer to Complex
	}
	// display the objects using the pointers stored in the vector
	for (size_t ndx = 0; ndx < 3; ++ndx) {
		cout << complV[ndx]->real << endl;
		cout << complV[ndx]->img << endl;
	}
	// release the heap space pointed at by the pointers in the vector      
	for (size_t ndx = 0; ndx < 3; ++ndx) {
		delete complV[ndx];
	}
	// clear the vector      
	complV.clear(); // Clear does not delete new objects created on the heap. Delete, then clear.

	// Task 28
	/*
	class Colour {
	public:
	Colour( const string& name, unsigned r, unsigned g, unsigned b )
	: name(name), r(r), g(g), b(b) {}
	void display() const {
	cout << name << " (RBG: " << r << "," << g<< "," << b << ")";
	}
	private:
	string   name;    // what we call this colour
	unsigned r, g, b; // red/green/blue values for displaying
	};
	
	vector< Colour* > colours;
	string inputName;
	unsigned inputR, inputG, inputB;

	// fill vector with Colours from the file
	// this could be from an actual file but here we are using the keyboard instead of a file
	// (so we don't have to create an actual file)
	// do you remember the keystroke combination to indicate "end of file" at the keyboard? (ctrl+z)
	// somehow the while's test has to fail - from keyboard input
	while ( cin >> inputName >> inputR >> inputG >> inputB ) {
		colours.push_back( new Colour(inputName, inputR, inputG, inputB) );
	}

	// display all the Colours in the vector:
	for ( size_t ndx = 0; ndx < colours.size(); ++ndx ) {
		colours[ndx]->display();
		cout << endl;
	}
	*/
	
	// Task 29
	/*
	class SpeakerSystem {
public:
	void vibrateSpeakerCones(unsigned signal) const {
		cout << "Playing: " << signal << "Hz sound..." << endl;
		cout << "Buzz, buzzy, buzzer, bzap!!!\n";
	}
};

class Amplifier {
public:
	void attachSpeakers(/* const  SpeakerSystem& spkrs)
	{
		if (attachedSpeakers)
			cout << "already have speakers attached!\n"; // If you attach another speaker system, overrides old speaker system. Only one speaker system at a time
		else
			attachedSpeakers = &spkrs;
	}
	void detachSpeakers()
	{
		attachedSpeakers = NULL;
	}
	// should there be an "error" message if not attached?
	void playMusic() const {
		if (attachedSpeakers)
			attachedSpeakers->vibrateSpeakerCones(440);
		else
			cout << "No speakers attached\n";
	}
	private:
	/* const  SpeakerSystem* attachedSpeakers = NULL;
	};
	*/

	SpeakerSystem newSpeaker;
	Amplifier newAmplifier;
	SpeakerSystem* sP = &newSpeaker;
	Amplifier* aP = &newAmplifier;
	sP->vibrateSpeakerCones(440);
	aP->attachSpeakers(*sP);
	aP->playMusic();

	// Task 30
	/*
	class Person {
	public:
		Person(const string& name) : name(name) {}
		void movesInWith(Person& newRoomate) {
			roomie = &newRoomate;        // now I have a new roomie            
			newRoomate.roomie = this;    // and now they do too       
		}
		string getName() const { return name; }
		// Don't need to use getName() below, just there for you to use in debugging.
		string getRoomiesName() const { return roomie->getName(); }
	private:
		Person* roomie;
		string name;
	};
	*/
	// write code to model two people in this world       
	Person joeBob("Joe Bob"), billyJane("Billy Jane");
	// now model these two becoming roommates       
	joeBob.movesInWith(billyJane); // Sets Joe Bob's roommate to Billy Jane, and also sets Billy Jane's roommate to Joe Bob
	// did this work out?       
	cout << joeBob.getName() << " lives with " << joeBob.getRoomiesName() << endl;
	cout << billyJane.getName() << " lives with " << billyJane.getRoomiesName() << endl;

	system("pause");
}