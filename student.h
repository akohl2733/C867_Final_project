#pragma once
#include "degree.h"
#include <iostream>
#include <string>
using namespace std;

class Student {


public:

    // constructors
    Student(string studentID, string first, string last, string email,
        int age, int numDays[], degreeProgram degree);
    Student();

    // mutators
    void setStudentId(string studentID);
    void setFirstName(string first);
    void setLastName(string last);
    void setEmail(string email);
    void setAge(int age);
    void setNumDays(int numDays[]);
    void setDegree(degreeProgram degree);

    // getters
    string getStudentId() const;
    string getFirstName() const;
    string getLastName() const;
    string getEmailAddress() const;
    int getAge() const;
    const int* getNumDays() const;
    degreeProgram getDegree() const;

    void Print() const;

    const static int AMT_DAYS = 3;

    protected:
    string studentID;
    string first;
    string last;
    string email;
    int age;
    int numDays[3];
    degreeProgram degree;

};