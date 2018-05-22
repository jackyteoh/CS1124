#include "Course.h"
#include "Student.h"
#include "Registrar.h"

using namespace BrooklynPoly;
using namespace std;

void Registrar::printReport() const {
	if (registrarCourses.size() == 0 && registrarStudents.size() == 0) {
		cout << "There are no students or courses yet in the Registrar." << endl;
	}
	else {
		for (size_t i = 0; i < registrarCourses.size(); i++) {
			cout << registrarCourses[i].getCourseName() << ": " << endl;
			registrarCourses[i].displayCourse();
		}
	}
}

void Registrar::addCourse(const string& newName) {
	registrarCourses.push_back(Course(newName));
}

void Registrar::addStudent(const string& newName) {
	registrarStudents.push_back(Student(newName));
}

void Registrar::enrollStudentInCourse(const std::string& student, const std::string& course) {
	for (size_t i = 0; i < registrarStudents.size(); i++) {
		if (registrarStudents[i].getStudentName() == student) {
			registrarStudents[i].enroll(course);
			for (size_t j = 0; j < registrarCourses.size(); j++) {
				if (registrarCourses[j].getCourseName() == course) {
					registrarCourses[j].enrolled(student);
				}
				else {
					cout << "This course does not exist in the Registrar." << endl;
				}
			}
		}
		else {
			cout << "This student does not exist in the Registrar." << endl;
		}
	}
}

void Registrar::cancelCourse(const std::string& newName) {
	for (size_t i = 0; i < registrarCourses.size(); i++) {
		if (registrarCourses[i].getCourseName() == newName) {
			registrarCourses[i] = registrarCourses[registrarCourses.size() - 1];
			registrarCourses[i].cancel();
			registrarCourses.pop_back();
		}
		else {
			cout << "This course does not exist in the Registrar." << endl;
		}
	}
}

void Registrar::purge() {
	for (size_t i = 0; i < registrarStudents.size(); i++) {
		registrarStudents[i].purged();
	}
	for (size_t j = 0; j < registrarCourses.size(); j++) {
		registrarCourses[j].cancel();
	}
}