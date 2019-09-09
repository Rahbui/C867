#include <iostream>
#include "securityStudent.h"

SecurityStudent::SecurityStudent() :Student() {
	program = SECURITY;
}

SecurityStudent::SecurityStudent(string StudentID, string fname, string lname, string emailAddress, int age, int courseDays[], Degree program) : Student(StudentID, fname, lname, emailAddress, age, courseDays, program) {
	program = SECURITY;
}

Degree SecurityStudent::getDegreeProgram()
{
	return SECURITY;
}

void SecurityStudent::print() {
	this->Student::print();
	cout << "SECURITY" << endl;
}

SecurityStudent::~SecurityStudent() {
	Student::~Student();
}