#pragma once
#include <string>
#include "student.h"

class NetworkStudent : public Student {

public:
	NetworkStudent();
	NetworkStudent(
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

	~NetworkStudent();


};