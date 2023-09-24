#include "student.h"
#include <iostream>
using namespace std;

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToComplete[], DegreeProgram degreeProgram) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (int i = 0; i < 3; i++) this->daysToComplete[i] = daysToComplete[i];
    this->degreeProgram = degreeProgram;
}

// Accessors (getters)
string Student::getStudentID() { return studentID; }
string Student::getFirstName() { return firstName; }
string Student::getLastName() { return lastName; }
string Student::getEmailAddress() { return emailAddress; }
int Student::getAge() { return age; }
int* Student::getDaysToComplete() { return daysToComplete; }
DegreeProgram Student::getDegreeProgram() { return degreeProgram; }

// Mutators (setters)
void Student::setStudentID(string studentID) { this->studentID = studentID; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmailAddress(string emailAddress) { this->emailAddress = emailAddress; }
void Student::setAge(int age) { this->age = age; }
void Student::setDaysToComplete(int daysToComplete[]) { for (int i = 0; i < 3; i++) this->daysToComplete[i] = daysToComplete[i]; }
void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }

void Student::print() {
    cout << getStudentID() << "\tFirst Name: " << getFirstName() << "\tLast Name: " << getLastName() << "\tAge: " << getAge()
         << "\tdaysInCourse: {" << getDaysToComplete()[0] << ", " << getDaysToComplete()[1] << ", " << getDaysToComplete()[2] << "} "
         << "Degree Program: ";
    switch (getDegreeProgram()) {
        case SECURITY:
            cout << "Security";
            break;
        case NETWORK:
            cout << "Network";
            break;
        case SOFTWARE:
            cout << "Software";
            break;
    }
    cout << endl;
}
