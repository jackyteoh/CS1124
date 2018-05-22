/*
Jacky Teoh - jt2908
CS1124 - Rec 05 - Association
10.07.2016
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Forward Declaration
class LabWorker;
class Section;
class Student;
class TimeSlot;

// Creating a student class
class Student {
public:
	// Student constructor, takes in name of student, creates a student with new name and initializes a vector with 13 
	// elements, all -1
	Student(const string& newName) : studentName(newName), studentGrades(13, -1) {}
	// Getter function for the name of the student
	string getStudentName() const {
		return studentName;
	}
	void display();
	void setStudentGrade(int inputGrade, int inputWeek);
private:
	string studentName;
	vector <int> studentGrades;
};

// Iterates over the student grades vector and prints out the grades.
void Student::display() {
	cout << endl << "Student: " << getStudentName() << "; Grades: ";
	for (int i = 0; i < studentGrades.size(); i++) {
		cout << " " << studentGrades[i] << " ";
	}
}

// Sets the new grade of the week for the student in the vector of student grades.
void Student::setStudentGrade(int inputGrade, int inputWeek) {
	studentGrades[inputWeek] = inputGrade;
}

// Time class
class TimeSlot {
public:
	// TimeSlot constructor with the day and the time as parameters
	TimeSlot(const string inputDay, int inputTime) : sectionDay(inputDay), sectionHour(inputTime) {}
	// Getter function for the day
	string getDay() const {
		return sectionDay;
	}
	// Getter function for the hour
	int getHour() const {
		return sectionHour;
	}
	void timeDisplay();
private:
	string sectionDay;
	int sectionHour;
};

// Display function for the time, since time is given in the 24 hour format, if time is less than 12, just prints out
// said time with AM
// If time is equal to 12, prints out 12 with PM
// If time is greater than 12, subtracts 12 from the given time and adds PM 
void TimeSlot::timeDisplay() {
	cout << sectionDay << " , at ";
	if (sectionHour < 12) {
		cout << sectionHour << " AM" << endl;
	}
	else if (sectionHour == 12) {
		cout << sectionHour << " PM" << endl;
	}
	else if (sectionHour > 12) {
		cout << sectionHour - 12 << " PM" << endl;
	}
}

// Section Class
class Section {
public:
	// Section constructor, taking in the name of the section, day of section, and time of section,
	// Initializes the day and time to sectionTime constructor
	Section(string newSection, const string newDay, int newTime)
		: sectionName(newSection), sectionTime(newDay, newTime) {}
	// Getter function for the name of the section
	string getSectionName() const {
		return sectionName;
	}
	void addStudent(const string& studentName);
	void sectionAddGrade(string inputName, int inputGrade, int inputWeek);
	void display();
	void reset();
private:
	string sectionName;
	TimeSlot sectionTime;
	vector<Student*> students;
};

// Adds a student by creating a new instance of student when given the student name, and pushes it back
// into the vector of students.
void Section::addStudent(const string& studentName) {
	Student* s = new Student(studentName);
	students.push_back(s);
}

// Checks to see if the name of the student in the vector of students matches the name given,
// If the name is equivalent to the name given, calls the setStudentGrade function of the student class,
// Passing in the parameters of the inputGrade and the inputWeek
void Section::sectionAddGrade(string inputName, int inputGrade, int inputWeek) {
	for (Student* x : students) {
		if (x->getStudentName() == inputName) {
			x->setStudentGrade(inputGrade, inputWeek);
		}
	}
}

// Prints out the section name, and when it meets.
// Then it iterates over the students vector and calls the display function for each student.
void Section::display() {
	cout << endl << "This is section " << getSectionName() << ", which meets on ";
	sectionTime.timeDisplay();
	for (int i = 0; i < students.size(); i++) {
		students[i]->display();
	}
}

// Resets/clears the vector.
void Section::reset() {
	students.clear();
}

// Lab Worker class
class LabWorker {
public:
	// Lab Worker constructor
	LabWorker(string newName) : workerName(newName) {}
	// Getter for worker name
	string getWorkerName() const {
		return workerName;
	}
	void addSection(Section& sec);
	void displayGrades(); // calls LabSection's display which calls Student's display
	void addGrade(string studentName, int weekGrade, int weekNumber);
private:
	string workerName;
	Section* workerSection;
};

// Assigning the given section to that specific lab worker.
void LabWorker::addSection(Section& sec) {
	workerSection = &sec;
}

// Calls the display function from the section class, which calls the display function from the student class
void LabWorker::displayGrades() {
	workerSection->display();
}

// Adds the grade by calling the sectionAddGrade function from the section class.
void LabWorker::addGrade(string studentName, int weekGrade, int weekNumber) {
	workerSection->sectionAddGrade(studentName, weekGrade, weekNumber);
}

int main() {
	// lab workers
	LabWorker moe("Moe");
	LabWorker jane("Jane");

	// sections and setup and testing
	Section secA2("A2", "Tuesday", 16);
	//secA2.loadStudentsFromFile( "A2.txt" );
	secA2.addStudent("John");
	secA2.addStudent("George");
	secA2.addStudent("Paul");
	secA2.addStudent("Ringo");

	cout << "\ntest A2\n";    // here the modeler-programmer checks that load worked
	secA2.display();          // YOU'll DO THIS LATER AS: cout << secA2 << endl;
	moe.addSection(secA2);
	moe.displayGrades();       // here the modeler-programmer checks that adding the Section worked

	Section secB3("B3", "Thursday", 11);
	//secB3.loadStudentsFromFile( "B3.txt" );
	secB3.addStudent("Thorin");
	secB3.addStudent("Dwalin");
	secB3.addStudent("Balin");
	secB3.addStudent("Kili");
	secB3.addStudent("Fili");
	secB3.addStudent("Dori");
	secB3.addStudent("Nori");
	secB3.addStudent("Ori");
	secB3.addStudent("Oin");
	secB3.addStudent("Gloin");
	secB3.addStudent("Bifur");
	secB3.addStudent("Bofur");
	secB3.addStudent("Bombur");

	cout << "\ntest B3\n";    // here the modeler-programmer checks that load worked
	secB3.display();          // YOU'll DO THIS LATER AS: cout << secB3 << endl;
	jane.addSection(secB3);
	jane.displayGrades();      // here the modeler-programmer checks that adding Instructor worked


							   // setup is complete, now a real world scenario can be written in the code
							   // [NOTE: the modeler-programmer is only modeling joe's actions for the rest of the program]

							   // week one activities  
	cout << "\nModeling week: 1\n";
	moe.addGrade("John", 7, 1);
	moe.addGrade("Paul", 9, 1);
	moe.addGrade("George", 7, 1);
	moe.addGrade("Ringo", 7, 1);
	cout << "End of week one\n";
	moe.displayGrades();

	// week two activities
	cout << "\nModeling week: 2\n";
	moe.addGrade("John", 5, 2);
	moe.addGrade("Paul", 10, 2);
	moe.addGrade("Ringo", 0, 2);
	cout << "End of week two\n";
	moe.displayGrades();

	//test that reset works  // NOTE: can we check that the heap data was dealt with?
	cout << "\ntesting reset()\n";
	secA2.reset();
	secA2.display();
	moe.displayGrades();

	system("pause");
}