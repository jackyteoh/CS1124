#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class DynArray {
public:
	DynArray() : data(new int[5]), sizeOfData(5), numOfElements(0) {}
	~DynArray() {                                   // Destructor
		delete[] data;
	}
	DynArray& operator=(const DynArray& rhs) {       // Assignment Operator

	}
	DynArray(const DynArray& rhs) : data(nullptr) { // Copy Constructor
		*this = rhs;                                // Always calls the assignment operator
	}            
	int operator[](int index) const{
		return data[index];
	}
	int& operator[](int index) {
		return data[index];
	}
	int size() const {
		return numOfElements;
	}
	int capacity() const {
		return sizeOfData;
	}

	void push_back(int element);
	int pop_back();
	void clear();
	void resize(int newSize);
private:
	int sizeOfData;    // Capacity
	int numOfElements; // How many push_backs
	int* data;
	string name;
	// type?
};

DynArray& DynArray::operator=(const DynArray& rhs) {
	if (this == &rhs) {  // Test for self assignment. If they try to assign something to themselves, and you already deleted it
		return *this;    // What are you going to assign to the new data
	}
	else {
		delete[] data;
		data = new int[rhs.numOfElements];			// Creates new space initialized with copied's numOfEle
		numOfElements = rhs.numOfElements;          // Updating num of ele to copied's numofEle
		for (int i = 0; i < numOfElements; i++) {   // Sets created new array to copied's arrays element
			data[i] = rhs.data[i];
		}
		sizeOfData = numOfElements;					// Then makes the size equal to the # of elements
		return *this;								// Returns the newly created array
	}
}

void DynArray::resize(int newSize) {
	int* temp = new int[newSize];
	if (newSize < numOfElements) {            // Checks to see if the new size is smaller than old size
		numOfElements = newSize;              // Changes to smaller size, to deletes old data
	}
	for (int i = 0; i < numOfElements; i++) {
		temp[i] = data[i];                    // Sets new data to old data
	}
	delete[] data;                            // Deletes old data
	data = temp;                              // puts new "resized" array back into data
	sizeOfData = newSize;                     // Changes size of data to the newsize
}                                             // End of function call, temp deleted. Data is now the new resized array

void DynArray::push_back(int element) {
	if (numOfElements == sizeOfData) {
		resize(sizeOfData * 2);
	}
	else {
		data[numOfElements++] = element;
	}
}

void DynArray::clear() {
	delete[] data;
	data = new int[5];
	sizeOfData = 5;
	numOfElements = 0;
}

int DynArray::pop_back() {
	int retVal;
	if (numOfElements > 0) {
		retVal = data[--numOfElements]; // Changes actual numOfElements, sets it to retval (2nd to last element?)
	}
	return retVal;
}

int main() {

}

/*
Assignment operator automatically overloaded?
But it makes a shallow copy.
obj1 = obj2;
if obj1 = 4;
obj2 = 100;
copies obj2's value, 100, and places it in obj1; SHALLOW COPY.
SHALLOW COPY COPIES THE POINTER, NOT WHAT THE POINTERS ARE POINTING TO.
Creates a double delete situation.
obj1 = obj2
makes obj1 point to 100
when destructor is called, obj2 deleted, obj1 ??? double delete
Copy constructor and assignment operator
int x(5) = copy constructor

BIG 3
Destructor
Assignment Operator
Copy Constructor

int x = 5;
int y(x);

DynArray z;
DynArray w(z); <- copy constructor
z = w;		   <- assignment operator
Calls only one constructor to make an object
Calling the copy constructor wont call the default constructor
Copy constructor creates the w object, and calls the assignment operator to make w = z;
data = nullptr
call assignment operator?
*/