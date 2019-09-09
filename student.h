#pragma once

#include <cstdio>
#include <cstring>
#include "degree.h"

using namespace std;

class Student {

protected:
	string StudentID;
	string fname;
	string lname;
	string emailAddress;
	int age;
	int courseDays[3];
	Degree program;

public:
	Student();
	Student(string ID, string fName, string lName, string email, int years, int days[], Degree degree);
	
	void setStudentID(string ID);
	void setFirstName(string fName);
	void setLastName(string lName);
	void setEmail(string email);
	void setAge(int years);
	void setCourseDays(int days[]);
	void setDegreeProgram(Degree degree);

	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	const int *getCourseDays() const;
	virtual Degree getDegreeProgram() = 0;

	virtual void print() = 0;
	~Student();
};