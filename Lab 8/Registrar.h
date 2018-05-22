#ifndef REGISTRAR_H
#define REGISTRAR_H
#include <string>
#include <vector>
#include <iostream>
#include "Course.h"
#include "Student.h"

namespace BrooklynPoly {

	class Registrar {
	public:
		Registrar() {}
		void printReport() const;
		void addCourse(const std::string& newName);
		void addStudent(const std::string& newName);
		void enrollStudentInCourse(const std::string& student, const std::string& course);
		void cancelCourse(const std::string& newName);
		void purge();
	private:
		std::vector<Student> registrarStudents;
		std::vector<Course> registrarCourses;
	};

}
#endif