#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include "roster.h"
#include "degree.h"
#include "student.h"
using namespace std;


Roster::Roster() {
    for (int i = 0; i < NUM_SDNT; ++i) {
        classRosterArray[i] = nullptr; // Initialize array to null
    }
}

// Sets instance variables and updates roster
void Roster::add(string studentID, string first, string last, string email,
				 int age, int days1, int days2, int days3, degreeProgram degree) {
	int numDays[] = {days1, days2, days3};

	classRosterArray[index++] = new Student(studentID, first, last, email, age, numDays, degree);
}

// Parse each record from the studentData table 
void Roster::parserAdder(string record) {
    vector<string> pieces;
    stringstream ss(record);
    string temp;

    while (getline(ss, temp, ',')) {
        pieces.push_back(temp);
    }

    string studentID = pieces[0];
    string firstName = pieces[1];
    string lastName = pieces[2];
    string email = pieces[3];
    int age = stoi(pieces[4]); 
    int days[3] = {stoi(pieces[5]), stoi(pieces[6]), stoi(pieces[7])};  

    degreeProgram degree;
    if (pieces[8] == "SECURITY") {
        degree = degreeProgram::SECURITY;
    } else if (pieces[8] == "NETWORK") {
        degree = degreeProgram::NETWORK;
    } else if (pieces[8] == "SOFTWARE") {
        degree = degreeProgram::SOFTWARE;
    } else {
        cout << "Error: Invalid degree program for student " << studentID << endl;
        return;
    }

    add(studentID, firstName, lastName, email, age, days[0], days[1], days[2], degree);
}

// Allows you to remove based on studentID input
void Roster::Remove(string studentID) {
    int x = 0;
    for (int i = 0; i < NUM_SDNT; ++i) {
        if (classRosterArray[i] == nullptr) {
            continue;
        }
        else if (studentID == classRosterArray[i]->getStudentId()) {
            classRosterArray[i] = nullptr;
            x = 1;
            cout << studentID << " has been found." << endl;
            break;
        }
    }
    if (x == 0) {
            cout << "Student " << studentID << " is not Found." << endl;
    }
    return;
}

// Print cassRosterArray
void Roster::PrintAll() {
	for (int i = 0; i < NUM_SDNT; ++i) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->Print();
		}
	}
}

// Takes studentID input and outputs average days in the course
void Roster::PrintAvgDaysInCourse(string studentID) {
    bool y = 0;
    for (int i = 0; i < NUM_SDNT; ++i) {
        if (classRosterArray[i] == nullptr) {
            continue;
        }
        else if (classRosterArray[i]->getStudentId() == studentID) {
            const int* days = classRosterArray[i]->getNumDays();
            
            if (days != nullptr) {
                cout << studentID << "Average days in the course for is: "
                     << (days[0] + days[1] + days[2]) / 3 << endl;
            } 
            else {
                cout << "Missing data for " << studentID << endl;
            }
            
            y = 1;
            break;
        }
    }
    if (y == 0) {
        cout << "Student ID not found" << endl;
    }
}


// Print out emails that do not have '@'/'.' or contain a space
void Roster::PrintInvalidEmails() {
    for (int i = 0; i < NUM_SDNT; i++) {
        if (classRosterArray[i] == nullptr) {
            continue;
        }

        string currEmail = classRosterArray[i]->getEmailAddress();
        bool test = false;

        if (currEmail.find(" ") != string::npos) {
            cout << currEmail << " --  No white space allowed." << endl;
            test = true;
        }

        if (currEmail.find("@") == string::npos) {
            cout << currEmail << " --  Missing '@' symbol." << endl;
            test = true;
        }

        if (currEmail.find(".") == string::npos) {
            cout << currEmail << " --  Missing '.' character." << endl;
            test = true;
        }
    }
}

// return records by degree
void Roster::PrintByDegreeProgram(degreeProgram degree) {
    int z = 0;
	cout << endl << "Results are grouped by degree:" << endl;
	for (int i = 0; i < NUM_SDNT; ++i) {
		if (classRosterArray[i] != nullptr) {
			if (degree == classRosterArray[i]->Student::getDegree()) {
				classRosterArray[i]->Student::Print();
                z = 1;
			}
		}
	}
    if (z == 0) {
        cout << "No Students in this degree program";
    }
	cout << endl;
}

// destr
Roster::~Roster() {
    for (int i = 0; i < NUM_SDNT; ++i) {
        delete classRosterArray[i];  
        classRosterArray[i] = nullptr;
    }
}