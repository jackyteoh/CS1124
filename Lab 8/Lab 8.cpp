/*
Jacky Teoh - jt2908
CS 1124 - Rec 8 : Separate Compilation
10.28.2016
rec 08.cpp
*/

#include "Registrar.h"
#include "Course.h"
#include "Student.h"
#include <iostream>
#include <string>
#include <vector>

using namespace BrooklynPoly;
using namespace std;

int main() {
	Registrar registrar;

	cout << "No courses or students added yet\n";
	registrar.printReport();

	cout << "AddCourse CS101.001\n";
	registrar.addCourse("CS101.001");
	registrar.printReport();

	cout << "AddStudent FritzTheCat\n";
	registrar.addStudent("FritzTheCat");
	registrar.printReport();

	cout << "AddCourse CS102.001\n";
	registrar.addCourse("CS102.001");
	registrar.printReport();

	cout << "EnrollStudentInCourse FritzTheCat CS102.001\n";
	registrar.enrollStudentInCourse("FritzTheCat", "CS102.001");
	cout << "EnrollStudentInCourse FritzTheCat CS101.001\n";
	registrar.enrollStudentInCourse("FritzTheCat", "CS101.001");
	registrar.printReport();

	cout << "EnrollStudentInCourse Bullwinkle CS101.001\n";
	cout << "Should fail, i.e. do nothing, since Bullwinkle is not a student.\n";
	registrar.enrollStudentInCourse("Bullwinkle", "CS101.001");
	registrar.printReport();

	cout << "CancelCourse CS102.001\n";
	registrar.cancelCourse("CS102.001");
	registrar.printReport();

								/*
								// [OPTIONAL - do later if time]
								cout << "ChangeStudentName FritzTheCat MightyMouse\n";
								registrar.changeStudentName("FritzTheCat", "MightyMouse");
								cout << registrar << endl;  // or registrar.printReport()

								cout << "DropStudentFromCourse MightyMouse CS101.001\n";
								registrar.dropStudentFromCourse("MightyMouse", "CS101.001");
								cout << registrar << endl;  // or registrar.printReport()

								cout << "RemoveStudent FritzTheCat\n";
								registrar.removeStudent("FritzTheCat");
								cout << registrar << endl;  // or registrar.printReport()
								*/

	cout << "Purge for start of next semester\n";
	registrar.purge();
	registrar.printReport();

	system("pause");
}