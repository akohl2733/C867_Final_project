#pragma once
#include "degree.h"
#include "student.h"
#include <iostream>
#include <string>
using std::string;

const int NUM_SDNT = 5;

class Roster {

public:

	// constructors
	Roster();

	// ptrs
	Student* classRosterArray[NUM_SDNT];
	
    // functions
	void add(string studentID, string first, string last, string email, int age, int days1, int days2, int days3, degreeProgram degree);
	void parserAdder(string record);
	void Remove(string studentID);
	void PrintAll();
	void PrintAvgDaysInCourse(string studentID);
	void PrintInvalidEmails();
	void PrintByDegreeProgram(degreeProgram degree);


	//destructors
	~Roster();
	
protected:

	int index = 0;
};