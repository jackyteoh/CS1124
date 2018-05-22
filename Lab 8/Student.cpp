#include <iostream>
#include "Student.h"

using namespace std;

namespace BrooklynPoly {
	Student::Student(const std::string& newName) {
		studentName = newName;
	}

	std::string Student::getStudentName() const {
		return studentName;
	}

	void Student::enroll(const std::string& newName) {
		for (size_t i = 0; i < vecCourses.size(); i++) {
			if (vecCourses[i]->getCourseName() != newName) {
				Course* co = new Course(newName);
				vecCourses.push_back(co);
			}
			else {
				cout << "This student is already enrolled in this course." << endl;
			}
		}
	}

	void Student::cancelled(const std::string& newName) {
		for (size_t i = 0; i < vecCourses.size(); i++) {
			if (vecCourses[i]->getCourseName() == newName) {
				delete vecCourses[i];
			}
			else {
				cout << "This student is not enrolled in this course!" << endl;
			}
		}
	}
	
	void Student::purged() {
		for (size_t i = 0; i < vecCourses.size(); i++) {
			delete vecCourses[i];
		}
		vecCourses.clear();
	}
}