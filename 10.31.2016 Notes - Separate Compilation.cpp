#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

}

/*
#include <iostream>
#include "header.h"

If the function exists in the header file, you can use the function if you include the header file

Header file: declares the functions and class?
CPP files: gives the body of the function

Person.h
class Person{
	void display() const;
};


Person.cpp
#include "Person.h"            // Include the header file

void Person::display() const{
	cout << name << endl;
}

class class1{
	add();
};

class class2{
	add();
};

int main(){
	class1::add(); <-- How you call from a specific class
}

namespaces:
namespace myNameSpace{
	add();
}

int main(){
	myNameSpace::add();
}

using namespace myNameSpace;

int main(){
	add(); ??
}

if you include two namespaces that have the same functions,
you have to qualify the function

using namespace myNameSpace;
using namespace std;

int main(){
	std::add();
	myNameSpace::add();
}

main.cpp
DynArray.cpp
DynArray.h

No function definitions go in header file, just signatures
in BOTH DynArray.cpp and main.cpp, #include "DynArray.h"
Bad convention to use namespace std in header files

include guards (in header) (Pre compiler definition)
Acts as a flag, if this flag has not been defined, show it's been seen, then define the class.

#ifndef DYNARRAY_H
#define DYNARRAY_H

#endif

Prevents including a class twice within a cpp file

y.h
x.h has #include "y.h"
x.cpp has #include "y.h" and #include "x.h"
Therefore includes class Y twice.

Compilation of a cpp produces an .obj file, unreadable that still compiles
Source code -> obj one way street
Linker links all the .obj files
and becomes a Program.exe file
*/