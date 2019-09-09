#include <string>
#include <iostream>
#include <iomanip>
#include "student.h"


//Default Constructor
Student::Student() {
	this->StudentID = "";
	this->fname = "";
	this->lname = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < 3; i++) this->courseDays[i] = 0;
}


//Full Constructor
Student::Student(string ID, string fName, string lName, string email, int years, int days[], Degree degree){
	setStudentID(ID);
	setFirstName(fName);
	setLastName(lName);
	setEmail(email);
	setAge(years);
	setCourseDays(days);

}

//Destructor
Student::~Student() {};

//Mutators
void Student::setStudentID(string id) {
	StudentID = id;
}

void Student::setFirstName(string fName) {
	fname = fName;
}

void Student::setLastName(string lName) {
	lname = lName;
}

void Student::setEmail(string email) {
	emailAddress = email;
}

void Student::setAge(int years) {
	age = years;
}

void Student::setCourseDays(int days[]) {
	for (int i = 0; i < 3; i++) {
		courseDays[i] = days[i];
	}
}

void Student::setDegreeProgram(Degree degree) {
	program = degree;
}


//Accessors
string Student::getStudentID() {
	return StudentID;
}

string Student::getFirstName() {
	return fname;
}

string Student::getLastName() {
	return lname;
}

string Student::getEmail() {
	return emailAddress;
}

int Student::getAge() {
	return age;
}

const int * Student::getCourseDays()  const {
	return courseDays;
}


void Student::print() {
	cout << left << setw(5) << StudentID;
	cout << left << setw(15) << fname;
	cout << left << setw(15) << lname;
	cout << left << setw(30) << emailAddress;
	cout << left << setw(10) << age;
	cout << left << setw(5) << getCourseDays()[0];
	cout << left << setw(5) << getCourseDays()[1];
	cout << left << setw(5) << getCourseDays()[2];

}
