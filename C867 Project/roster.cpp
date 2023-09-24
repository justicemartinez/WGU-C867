#include "roster.h"
#include <iostream>
#include <iomanip>
#include <regex>
using namespace std;

Roster::Roster() {
    for (int i = 0; i < 5; i++) classRosterArray[i] = nullptr;
}

Roster::~Roster() {
    for (int i = 0; i < 5; i++) {
        delete classRosterArray[i];
    }
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    int daysToComplete[] = { daysInCourse1, daysInCourse2, daysInCourse3 };
    for (int i = 0; i < 5; i++) {
        if (classRosterArray[i] == nullptr) {
            classRosterArray[i] = new Student(studentID, firstName, lastName, emailAddress, age, daysToComplete, degreeProgram);
            break;
        }
    }
}

void Roster::remove(string studentID) {
    bool found = false;
    for (int i = 0; i < 5; i++) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;
            found = true;
            cout << "Student with ID: " << studentID << " has been removed from the roster." << endl;
            break;
        }
    }
    if (!found) {
        cout << "ERROR: Student with ID: " << studentID << " not found." << endl;
    }
}

void Roster::printAll() {
    for (int i = 0; i < 5; i++) {
        if (classRosterArray[i] != nullptr) classRosterArray[i]->print();
    }
}

void Roster::printAverageDaysInCourse(string studentID) {
    bool found = false;
    for (int i = 0; i < 5; i++) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
            int* daysToComplete = classRosterArray[i]->getDaysToComplete();
            cout << "Average days in course for student ID " << studentID << " is "
                 << fixed << setprecision(2) << ((daysToComplete[0] + daysToComplete[1] + daysToComplete[2]) / 3.0) << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "ERROR: Student with ID: " << studentID << " not found." << endl;
    }
}

void Roster::printInvalidEmails() {
    regex emailPattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    for (int i = 0; i < 5; i++) {
        if (classRosterArray[i] != nullptr && !regex_match(classRosterArray[i]->getEmailAddress(), emailPattern)) {
            cout << "Invalid email address found: " << classRosterArray[i]->getEmailAddress() << endl;
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i < 5; i++) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}
