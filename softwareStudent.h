#pragma once
#include <string>
#include "student.h"

class SoftwareStudent : public Student {

public:
	SoftwareStudent();
	SoftwareStudent(
		string StudentID,
		string fname,
		string lname,
		string emailAddress,
		int age,
		int courseDays[],
		Degree program
	);

	Degree getDegreeProgram();
	void print();

	~SoftwareStudent();


};