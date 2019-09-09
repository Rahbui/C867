#pragma once
#include <string>
#include "student.h"

class SecurityStudent : public Student {

public:
	SecurityStudent();
	SecurityStudent(
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

	~SecurityStudent();


};