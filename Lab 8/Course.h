#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>
#include <iostream>
#include "Student.h"

namespace BrooklynPoly {

	class Course {
	public:
		Course(const std::string& newName);
		std::string getCourseName() const;
		void displayCourse() const;
		void enrolled(const std::string& newName);
		void cancel();
	private:
		std::string courseName;
		std::vector<Student*> vecStudents;
	};
}

#endif
