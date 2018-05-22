#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <vector>
#include "Course.h"

namespace BrooklynPoly {

	class Student {
	public:
		Student(const std::string& newName);
		std::string getStudentName() const;
		void enroll(const std::string& newName);
		void cancelled(const std::string& newName);
		void purged();
	private:
		std::string studentName;
		std::vector<Course*> vecCourses;
	};
}

#endif
