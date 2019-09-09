#pragma once
#include <string>
#include <iostream>
#include "student.h"
#include "softwareStudent.h"
#include "securityStudent.h"
#include "networkStudent.h"

class Roster {
private:
	int lastIndex;
	int capacity;
	Student** classRosterArray;
public:
	Roster();
	Roster(int capacity);
	Student* getStudentAt(int index);
	void parseAndAdd(string row);
	void add(string sID, string sfName, string slName, string semail, int age, int cd1, int cd2, int cd3, Degree sp);
	bool remove(string StudentID);
	void printAll();
	void printDaysInCourse(string StudentID);
	void printInvalidEmails();
	void printByDegreeProgram(Degree degreeProgram);
	~Roster();
};