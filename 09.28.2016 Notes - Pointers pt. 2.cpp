#include <iostream>
#include <string>

using namespace std;

void func1() {
	int* y = new int(100);
	// delete y; Memory increases, then crashes. creating creating creating doesn't delete
	delete y; // 0.7 MB RAM used, very small amount. creating deleting creating deleting
}

void func2(int* arr) {
	arr[5] = 100;
}

void func3(int*& arr) { // (int* arr) doesn't work, but passing by reference works
	delete[] arr;
	arr = new int[100];
	arr[6] = 100;
}

class Person {
	string name;
public:
	Person* spouse;
	Person(string newName = " ") : name(newName) {}
	void setName(string newName) {
		name = newName;
	}
	string getName() const {
		return name;
	}
};

int main() {
	// Right click, run to cursor
	// Open debug toolbar
	int x = 5; // created on the stack
	int* y = &x; // Don't have to delete this y because it's created on stack not heap

	y = new int(100);
	delete y;

	// for (int i = 0; i < 10000000; i++) {
	// 	func1();
	// }

	y = nullptr;
	//	cout << *y << endl; // Can't DEREF NULL !!! 
	delete y; // Safe to do, does nothing

	y = new int(100);
	delete y;
	// delete y; // DOUBLE DELETE. Crashes. Can't do 
	y = nullptr;
	delete y;
	delete y; // Can delete nullptr as many times as you want. y still remains nullptr

	int* z = new int(100);
	y = new int(200);
	int* w = z;
	z = y;
	y = w;
	delete y;
	delete z;
	// delete w;  Double Delete !!!

	/* 
	z -> 100;
	y -> 200;
	w = z, w -> 100
	z = y, z -> 200
	y = w, y -> 100
	delete y, good
	delete z, good
	delete w, y and w had the same value, y already got deleted. Double delete !!
	*/

	int sarr[5];
	int size = 100;
	// int sarr[size]; <-- Can't do ! Can't use a non-constant to define the size of a stack array.
	z = new int[size]; // If created on the heap, then using a non-constant to define size is okay.
	z[0] = 100;
	z[1] = INT_MAX; // Highest integer you can store in an int (
	z[2] = INT_MIN; // Lowest integer you can store in an int (
	cout << *z << endl; // Pointer to base is pointer to first element, prints out 100.

	func2(z);
	cout << z[5] << endl; // WILL print out 100
	// Func2 got passed in a POINTER to an array, will still change the values in the array
	delete[] z; // Delete array by delete[], otherwise it just deletes the first element of array z

	func3(z); // deletes current array z, makes arr point to NEW array.
	cout << z[6] << endl; // Sets arr[6] = 100, then arr gets deleted. Z is not pointing to anything, arr[] is just there
	// Memory leak, and when you delete z again after, double delete.
	cout << *z << endl; // ?? Dereferencing something that has been deleted

	/*
	NEW func3(int*& arr)
	deletes arr and z, makes both arr and z point to NEW array
	sets new array[6] to 100, both z and arr still pointing to this new array.
	then arr gets destroyed, z still pointing to new array. Works !
	*/

	cout << *(z + 6) << endl; // same as z[6];
	int* other = z + 6;
	cout << other[0] << endl; // Same as z[6]
	cout << other[1] << endl; // same as z[7]
	cout << *other << endl; // same as z[6]
	int* confusing = other + 2; // same as other[2] or z[8]
	cout << *confusing++ << endl; // prints out 20, is this *(confusing)++ or *(confusing++), incrementing the pointer or the integer?
	cout << *confusing << endl; // prints out 13, Star aint shit, dereference has lowest precedence. Increments pointer, then dereferences *(confusing++)

	
	int* thing1, thing2; // NOT TWO POINTERS. THING1 IS A POINTER, THING2 IS AN INTEGER.

	Person* personPointer;
	personPointer = new Person("John");
	// cout << (*personPointer).getName() << endl;
	cout << personPointer->getName() << endl; // Arrow operator, same as pointer accessing function
	Person p("Jane");
	p.spouse = personPointer; // the spouse of Jane is the Person pointer, personPointer
	personPointer->spouse = &p; // personPointer's spouse is the address of Jane
	cout << personPointer->spouse->getName() << endl; // personPointer dereferencing spouse of personPointer, then accessing getName function
	cout << p.spouse->getName() << endl; // member of p object, spouse, pointing to getName function ?? 

	// left of the arrow MUST be a pointer.
	delete personPointer;
}

/*
Step Into - Goes into the function that you're calling
Step Over - Will run that function and return to the cursor at the next line of code.
Step Out - Brings you back to main (?) 

Step Over helps you find where the crash occurs, and what the values are that cause the crash

# of news = # of deletes

Element Base = Base of Array + (index * size of one element)
                Pointer!        Given     Based on Data Type
Base of array is base of first element of array

No difference between an array pointer and a regular pointer
When we pass an array into a function, the array is being pointed to by the pointer
*/

/*
Pointers& const -> const pointer, const value
int x = 17;
int y = 6;
int* const p = &x;
*p = 42;  <- This works. Changing value of the int, not the address of the pointer.
p = &y;   <- This will not work. Changing address of a constant pointer.

const int* p = &x;
*p= 42;   <- Will not work. pointer pointing to a CONSTANT int. Can't change the value.
p = &y;   <- Will work. Can change the address of the pointer, not the value.
*/