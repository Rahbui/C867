#include <iostream>
#include "networkStudent.h"

NetworkStudent::NetworkStudent() :Student() {
	program = NETWORKING;
}

NetworkStudent::NetworkStudent(string StudentID, string fname, string lname, string emailAddress, int age, int courseDays[], Degree program) : Student(StudentID, fname, lname, emailAddress, age, courseDays, program) {
	program = NETWORKING;
}

Degree NetworkStudent::getDegreeProgram()
{
	return NETWORKING;
}

void NetworkStudent::print() {
	this->Student::print();
	cout << "NETWORKING" << endl;
}

NetworkStudent::~NetworkStudent() {
	Student::~Student();
}