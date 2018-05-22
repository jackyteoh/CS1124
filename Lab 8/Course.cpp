#include "Course.h"

using namespace std;

namespace BrooklynPoly {
	Course::Course(const std::string& newName) {
		courseName = newName;
	}

	string Course::getCourseName() const {
		return courseName;
	}

	void Course::displayCourse() const {
		for (size_t i = 0; i < vecStudents.size(); i++) {
			cout << vecStudents[i]->getStudentName() << endl;
		}
	}

	void Course::enrolled(const std::string& newName) {
		for (size_t i = 0; i < vecStudents.size(); i++) {
			if (vecStudents[i]->getStudentName() != newName) {
				Student* so = new Student(newName);
				vecStudents.push_back(so);
			}
			else {
				cout << "This student is already enrolled in this course!" << endl;
			}
		}
	}

	void Course::cancel() {
		for (size_t i = 0; i < vecStudents.size(); i++) {
			delete vecStudents[i];
		}
		vecStudents.clear();
	}
}