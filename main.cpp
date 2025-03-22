#include <iostream>
#include "roster.h"
#include "student.h"
#include "degree.h"
using namespace std;



int main() {
	cout << "Scripting and Programming - Applications - C867" << endl;
	cout << "Programming language - C++" << endl;
	cout << "WGU Student ID: 012448952" << endl;
	cout << "Andrew Kohl" << endl;
	
    Roster classRoster;

	const string studentData[] =
	{
			"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
			"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
			"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
			"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
			"A5,Andrew,Kohl,akohl26@wgu.edu,24,18,30,35,SOFTWARE"
	};
	
	for (int i = 0; i < NUM_SDNT; ++i) {
		classRoster.parserAdder(studentData[i]);
	}
	
    cout << endl << "Displaying all students" << endl;
	classRoster.PrintAll();
	cout << endl;
	
	cout << "All invalid emails" << endl;
	classRoster.PrintInvalidEmails();
	
	cout << endl << "Average days in courses, per student: " << endl;
	for (int i = 0; i < NUM_SDNT; ++i) {
		if (classRoster.classRosterArray[i] != nullptr) {
			classRoster.PrintAvgDaysInCourse(classRoster.classRosterArray[i]->getStudentId());
		}
	}
	
    cout << endl << "Students in Software Degree Program";
    classRoster.PrintByDegreeProgram(degreeProgram::SOFTWARE);
    cout << endl;
	
	classRoster.Remove("A3");
	cout << endl;

    cout << "Class roster after removing Student A3" << endl;
	classRoster.PrintAll();
	cout << endl;

	classRoster.Remove("A3");
	cout << endl;
	
	classRoster.~Roster();
	
	return 0;
}