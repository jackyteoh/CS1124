#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {

}

/*
Class Something{
public:
	something() : x(5) {} // initialization list, sets x to 5 when object is created.
	something(int val) : x(val) {} // takes in passed in number, sets it to x when object is created
	something(int val = 5) : x(val) {} // takes in val which is 5, sets it to x when object is created
private:
	int x;
};

Main memory:
Von Neuman (?) Architecture: Both the data and the code for that data are in the same main memory ?
Every byte has a unique address
Can record the address of a SINGLE byte
Size of the address space is important:
If size is 32 bits, the biggest you can access is 2^32 = 4 billion bytes (4 GB RAM)
The address space has to be large enough 
64 bits = 2^64 = 18 exabytes is the biggest memory. 1 exabyte = 1 billion GB
64 bits = 18 Billion GB of RAM. 

int x = 5;
integers take 4 bits of memory.
800 801 802 803 804 805 806 807 808 809 80A 80B 
if we set base address of x to 802, 
x will have an address of 802 - 805 because it's an int and takes 4 bits.
A pointer is a way to store a memory address.
int* z;  
Pointer does not store the something/value of the integer of the thing it's pointing to.
It stores the memory address where we can find the data type it's pointing to.
Integer pointer cannot point to a double.
Integer pointer can only point to an integer
Same for every data type. Data type of pointer can only point to it's own data type.
If base address of z is 807,
z will have an address of 807-80A. 4 bits.
If we don't give it a value, the value stored in that pointer is garbage.
int* z; // dangling pointer
z = nullptr;
nullptr IS a pointer, but a special pointer. 
Special place in memory that we make things point to indicate that we're not using them.
If we have a pointer that points to somewhere thats not valid, or a garbage value, that is a DANGLING POINTER
int* z;
z = nullptr;
z = &x;       & = Address-of operator. Gives address of x, and sets it to z. 
Stores 802 (address of x) into 807 (address of z)

cout << *z << endl;  Dereference operator, gives the value of the pointer
Dereference goes to pointer, goes to where the pointer is pointing to. 
*z goes to where z points to, which is the address of x. Thus prints out value of x which is 5. 

Class Person{
public:
	string getName() const{
		return name;
	}
	Person(Person* newMom = nullptr, Person* newDad = nullptr, string newName = "") 
	: mom(newMom), dad(newDad), name(newName) {}
	string getMomName() const{
		return (*mom), name;     Access mom object, gets name from mom object ???
		return (*mom).name;
		return mom->name;
	}
	string getDadName() const{
		return (*dad).name;
		return dad->name;
	}
private:
	int age;
	int height;
	Person parents; (?)
	Person* mom;
	Person* dad;
	string name;
};

Creating variables on the STACK
Activation Records only exist during a function call
Once the function call ends, all the variables are destroyed.
The heap is where we can put things that need to exist for a long time, or change.
Vector is made(?) on the heap. Dynamic.
Variables on the heap cannot have names, instead we have pointers.
new = storage of data type on the heap. int pointer, create new int. double pointer, create new double, etc.
int* x = new int;
*x = 100;
cout << *x; prints out 100.
delete x; DELETE DOES NOT DO ANYTHING TO THE POINTER.
Instead, deletes what the pointer is pointing to (in this case, the int 100)
x = new int;

Three possible errors with pointers:

1) Dereferencing null (DEREF NULL), program crashes. Illegal to access 0x00000. 
int* x = nullptr;
cout << *x;

2) Double Delete, also crashes program.
delete x;
delete x; <-- Can't delete the same memory space again if it's already been deleted.
int* x = new int;
int* y = x; <-- points to what x is pointing to, the new int.
delete x; <-- deletes the new int that x is pointing to
delete y; <-- Only creating one new item on the heap, x = new int, so you only need to delete once.
              Therefore you can't delete y because it has already been deleted.

3) Garbage on the heap/Memory leak:
Memory leak = memory left on the heap that you can no longer access.
int* x = new int; // garbage on the heap
x = new int;
delete x; <-- the first new int is still there that we can't access. Therefore memory leak.
Memory leaks don't happen instantaneously, happens over time, then crashes.

int* p = new int(5);
int* a = new int[3]; // creating an array with size of 3
delete p;
delete[] a;
delete p; <-- double delete, program crashes
p = nullptr;
delete p; <-- you can delete nullptr safely
a[0] = 4; undefined, program space
*p = 5; undefined behavior, don't dereference nullptr

class Base{
public:
	Base(){ 
	cout << "A";
	}
};

class Derived: public/protected/private Base{ // You can specify what you inherit from base

};

Base -> Public -> Protected -> Private
When Derived again:
Derived: Public Base -> Public and Protected
Derived: Protected Base -> Public can't be used by outside, protected can be used by Derived children
Derived: Private Base -> Nothing gets inherited from Base class

Children: Public Derived -> Public and Protected
Children: Protected Derived -> Public and Protected inherited, just public can't be used by outside.
Children: Private Derived -> Nothing is inherited from the Base class

class Base{
public:
	Base(){
		cout << "A";
	}
};

class Derived: Base{ // You can specify what you inherit from base

};

int main(){
Derived d;
Base b;
Base* bp;
Derived* dp;

bp = &d; = Error, Base is an inaccessible base of Derived ? Base pointer to address of d

bp = &(*dp); = Error, Base is an inaccessible base of Derived. Base pointer to address of Derived pointer dereferenced
bp = dp;     = Error, Base is an inaccessible base of Derived. bp = Base*, dp = Derived*, not same type, does not work.
bp = (Base*)dp; = prints out AA

}

C - style casting
Static Casting, Dynamic Casting, Reinterpret Casting
static_cast
dynamic_cast
reinterpret_cast
*/