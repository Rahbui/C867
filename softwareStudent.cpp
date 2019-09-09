#include <iostream>
#include "softwareStudent.h"

SoftwareStudent::SoftwareStudent() :Student() {
	program = SOFTWARE;
}

SoftwareStudent::SoftwareStudent(string StudentID, string fname, string lname, string emailAddress, int age, int courseDays[], Degree program) : Student(StudentID, fname, lname, emailAddress, age, courseDays, program) {
	program = SOFTWARE;
}

Degree SoftwareStudent::getDegreeProgram()
{
	return SOFTWARE;
}

void SoftwareStudent::print() {
	this->Student::print();
	cout << "SOFTWARE" << endl;
}

SoftwareStudent::~SoftwareStudent() {
	Student::~Student();
}