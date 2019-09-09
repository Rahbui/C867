#include <cstdio>
#include <cstring>
#include <iostream>
#include "roster.h"
#include <vector>
#include <sstream>

using namespace std;

const string degreetype[] = { "Security", "Networking", "Software" };

Roster::Roster() {
	this->lastIndex = -1;
	this->capacity = 0;
	this->classRosterArray = nullptr;
}

Roster::Roster(int capacity) {
	this->lastIndex = -1;
	this->capacity = capacity;
	this->classRosterArray = new Student * [capacity];
}

Student* Roster::getStudentAt(int index) {
	return classRosterArray[index];
}

void Roster::parseAndAdd(string row) {
	if (lastIndex < capacity) {
		lastIndex++;

		//Parse Student Id
		int rhs = row.find(",");
		string sID = row.substr(0, rhs);

		//Parse First Name
		int lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string sfName = row.substr(lhs, rhs - lhs);

		//Parse Last Name
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string slName = row.substr(lhs, rhs - lhs);

		//Parse Email Address
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string semail = row.substr(lhs, rhs - lhs);

		//Parse Age and convert to int
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int age = stoi(row.substr(lhs, rhs - lhs));

		//Parse Days left in Course and convert to int
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int cd1 = stoi(row.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int cd2 = stoi(row.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int cd3 = stoi(row.substr(lhs, rhs - lhs));

		//Parse Degree Program
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string degreeprogram = row.substr(lhs, rhs - lhs);
		Degree sp;
		if (degreeprogram == "SECURITY") {
			sp = SECURITY;
		}
		else if (degreeprogram == "SOFTWARE") {
			sp = SOFTWARE;
		}
		else {
			sp = NETWORKING;
		}

		add(sID, sfName, slName, semail, age, cd1, cd2, cd3, sp);

	}

	else {
		cout << "ERROR! DATA TOO LARGE!" << endl;
	}
}

void Roster::add(string sID, string sfName, string slName, string semail, int age, int cd1, int cd2, int cd3, Degree sp) {
	int dayArray[3];
	dayArray[0] = cd1;
	dayArray[1] = cd2;
	dayArray[2] = cd3;
	if (sp == SECURITY) {
		classRosterArray[lastIndex] = new SecurityStudent(sID, sfName, slName, semail, age, dayArray, sp);
	}
	else if (sp == SOFTWARE) {
		classRosterArray[lastIndex] = new SoftwareStudent(sID, sfName, slName, semail, age, dayArray, sp);
	}
	else {
		classRosterArray[lastIndex] = new NetworkStudent(sID, sfName, slName, semail, age, dayArray, sp);
	}
}

void Roster::printAll() {
	for (int i = 0; i <= this->lastIndex; i++) {
		(this->classRosterArray)[i]->print();
	}

	cout << endl;
}

bool Roster::remove(string StudentID) {
	cout << "Removing Student by ID: " << StudentID << " ..." << endl;
	bool found = false;
	for (int i = 0; i <= lastIndex; i++) {
		if (this->classRosterArray[i]->getStudentID() == StudentID) {
			found = true;
			delete this->classRosterArray[i];
			this->classRosterArray[i] = this->classRosterArray[lastIndex];
			lastIndex--;
		}
	}

	if (found == false) {
		cout << "Student with this ID not found." << endl << endl;
	}
	else {
		this->printAll();
		cout << endl;
	}
	return found;
}

void Roster::printDaysInCourse(string StudentID) {
	bool found = false;
	for (int i = 0; i <= lastIndex; i++) {
		if (this->classRosterArray[i]->getStudentID() == StudentID) {
			found = true;
			const int* classes = classRosterArray[i]->getCourseDays();
			cout << classes[0] << ", " << classes[1] << ", " << classes[2] << ", " << endl;
			cout << "Average days in course: " << (classes[0] + classes[1] + classes[2]) / 3 << endl;
		}
	}

	if (found == false) {
		cout << "Student with this ID not found" << endl;
	}

	cout << endl;
}

void Roster::printInvalidEmails() {
	cout << "Checking Emails for validity..." << endl;
	int count = 0;
	for (int i = 0; i < lastIndex; i++) {
		string em = classRosterArray[i]->getEmail();
		if (em.find("@") != string::npos && em.find(".") != string::npos && em.find(" ") == string::npos) {
			count++;
		}
		else {
			cout << "Invalid: " << em << endl;
		}
		
	}
	if (count == lastIndex) {
		cout << "All emails are valid" << endl;
	}
	
}

void Roster::printByDegreeProgram(Degree degreeprogram) {
	cout << "Students in the " << degreetype[degreeprogram] << " program: " << endl;
	for (int i = 0; i <= lastIndex; i++) {
		if (this->classRosterArray[i]->getDegreeProgram() == degreeprogram) {
			classRosterArray[i]->print();
		}
	}
	cout << endl;
}

Roster::~Roster() {
	for (int i = 0; i <= lastIndex; i++) {
		delete this->classRosterArray[i];
	}
	delete classRosterArray;
}

int main() {

	//Personal Info
	cout << "____________________________________" << endl
		<< "Course: C867 Scripting and Programming Applications" << endl
		<< "Written in: C++ Programming Language" << endl
		<< "Student ID: " << endl
		<< "Name: Rahbui" << endl
		<< "____________________________________" << endl << endl;
	
	//Student Data
	const string studentData[] = {
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Rahbui,rahbui,rahbui@rahbui.com,26,20,20,20,SOFTWARE"
	};

	//Class Size
	int classSize = 5;
	
	//Create New Roster
	Roster* classRoster = new Roster(classSize);
	cout << "Parsing Roster..." << endl;

	//Parse the data into the roster
	for (int i = 0; i < classSize; i++) {
		classRoster->parseAndAdd(studentData[i]);
	}

	cout << "Done" << endl << endl;
	cout << "Displaying all students:" << endl;

	//Print all students
	classRoster->printAll();

	//Print all invalid emails
	classRoster->printInvalidEmails();

	cout << endl;

	//Print Days Left in course and average
	classRoster->printDaysInCourse("A1");

	//Print Student information by Degree Program
	classRoster->printByDegreeProgram(SOFTWARE);

	//First removal of student
	classRoster->remove("A3");

	//Second removal of same student ID. (should prompt error)
	classRoster->remove("A3");

	//Call to the destructor
	classRoster->~Roster();


}