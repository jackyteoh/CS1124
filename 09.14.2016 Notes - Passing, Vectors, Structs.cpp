#include <iostream>
#include <string>
#include <vector>

using namespace std;

// variable outside the main means its in the global scope
// means it can be used by any function
// DO NOT EVER MAKE A VARIABLE IN THE GLOBAL SCOPE THAT'S NOT CONST

const double taxRate = 0.0875; // const PROHIBITS any changes to the variable

int main() {
	double total = 1400;
	cout << "You owe Uncle Sam " << total*taxRate << " dollars." << endl;
	// taxRate *= 100; not do-able because taxRate is const

	int x = 100;
	if (x > 10) {
		int y = 20;
		cout << "x = " << x << "\ty=" << y << endl;
	}
	// cout << y << endl;        Can't print out y, doesn't exist past the scope in the if ^

	int i = 0;
	for (int i = 0; i < 100; i++) {
		cout << i << endl;
	}
	// cout << i << endl;        Can't print out i, i exists in the scope of the for loop only ^
	cout << i << endl;        // This prints out 0, ONLY IF the int i = 0 exists before the loop.

	int i = 0;
	for (i = 0; i < 100; i++) {
		cout << i << endl;
	}
	cout << i << endl;       //  This prints out 100, changes value of variable i when i = 0 in for loop

	vector<int> v; // Vector of integers, stores homogeneous data types, ONLY INTS
	// v.push_back(5);  push back adds onto end of the vector

	for (int i = 0; i < 100; i++) {
		v.push_back(i * 2);
	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}

	for (int val : v) { // Ranged For loop
		// Loop will continue for whatever is in vector 'v', sets val to next value in the vector
		// Until end of v
		cout << val << endl;
	}

	v.clear(); // empties out the vector. 

	struct Date {
		int day;
		int month;
		int year;
	};

	struct Person { // Stores different data types
		string name;
		int height; // inches
		double weight;
		Date bday;
		vector<string> childrenNames;
	};

	Person p;
	p.name = "Daniel";
	p.height = 72;
	p.bday.month = 7; // Can access the bday object of the Date struct in the Person struct
	p.bday.day = 9;
	p.childrenNames.push_back("Aidan");
	p.childrenNames.push_back("Sofia");

	vector<Person> vp;
	vp.push_back(p);
	for (Person p : vp) {
		cout << p.name;
		if (p.childrenNames.size() > 0) {
			cout << '\t';
			for (string childName : p.childrenNames) {
				cout << childName << '\t';
			}
		}
	}

	for (int i = 0; i < vp.size(); i++) {
		cout << vp[i].name;
		if (p.childrenNames.size() > 0) {
			cout << ": ";
			for (int j = 0; j < p.childrenNames.size(); j++) {
				cout << vp[i].childrenNames[j] << ", ";
			}
		}
		cout << endl;
	}
}

/*
PTC Tutoring
Monday - Thursday 11-8
Friday            12-5

Passing by reference: (Denoted by & after data type)
Does not make a copy
Reference = Another name for the same variable
When passed by reference, changes ACTUAL value/variable

Passing by value:
Passing the value to the function
Makes a copy of the actual value/variable
Does not change actual value/variable
*/

/*
09.16.2016 Lab Notes
Structures
Parameter passing mechanisms
Vectors

struct Date{
	int month;
	int day;
	int year;
};

struct Human{
	string name;
	int height;
	int age;
};

Human xyz;
xyz.name = "";
xyz.height = 6;
xyz.age = 20;

int add(int p1, int p2){
	p1 = p1 + 10;
	cout << p1 << '\t' << p2 << endl;
	return p1 + p2;
}

int main(){
	int ip1, ip2, result;
	cin >> ip1 >> ip2 >> endl;
	result = add(ip1, ip2);
}

Function:
return type nameOfFunction (parameters){
	return ____;
}

Vector<type> v; Container for homogeneous data types
Vector<Human> class;
class [];
class.push_back(xyz);
*/