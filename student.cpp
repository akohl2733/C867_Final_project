#include "student.h"
#include <iostream>
using std::string;
using namespace std;

// COnstructor with blank record
Student::Student() : studentID(""), first(""), last(""), email(""), age(-1), numDays{0, 0, 0} {}

// Create student object with mutator
Student::Student(string studentID, string first, string last, string email,
                 int age, int numDays[], degreeProgram degree)
{
    setStudentId(studentID);
    setFirstName(first);
    setLastName(last);
    setEmail(email);
    setAge(age);
    setNumDays(numDays);
    setDegree(degree);
}

// mutators
void Student::setStudentId(string studentID) { this->studentID = studentID; }
void Student::setFirstName(string first) { this->first = first; }
void Student::setLastName(string last) { this->last = last; }
void Student::setEmail(string email) { this->email = email; }
void Student::setAge(int age) { this->age = age; }
void Student::setNumDays(int numDays[]) {
    for (int i = 0; i < AMT_DAYS; ++i) {
        this->numDays[i] = numDays[i];
    }
}
void Student::setDegree(degreeProgram degree) { this->degree = degree; }

// getters
string Student::getStudentId() const { return studentID; }
string Student::getFirstName() const { return first; }
string Student::getLastName() const { return last; }
string Student::getEmailAddress() const { return email; }
int Student::getAge() const { return age; }
const int* Student::getNumDays() const { return numDays; } 
degreeProgram Student::getDegree() const { return degree; }

// Print student record
void Student::Print() const {
    cout << getStudentId();
    cout << "   First name is: " << getFirstName();
    cout << "   Last name is: " << getLastName();
    cout << "   Email address is: " << getEmailAddress(); 
    cout << "   Age is: " << getAge();
    
    cout << "   Days in courses: ";
    for (int i = 0; i < AMT_DAYS; ++i) {
        cout << "   " << numDays[i] << " "; 
    }

    //enum
    string dstr = "";
    switch (getDegree()) {
        case degreeProgram::NETWORK: dstr = "NETWORK"; break;
        case degreeProgram::SECURITY: dstr = "SECURITY"; break;
        case degreeProgram::SOFTWARE: dstr = "SOFTWARE"; break;
    }
    cout << "Degree: " << dstr << endl;
}

