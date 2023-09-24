#include "roster.h"
#include <iostream>
using namespace std;

using namespace std;

const string studentData[] = {
    classRoster.addStudent("A1", "John", "Smith", "john1989@gm ail.com", 20, 30, 35, 40, SECURITY);
    classRoster.addStudent("A2", "Suzan", "Erickson", "Erickson_1990@gmailcom", 19, 50, 30, 40, NETWORK);
    classRoster.addStudent("A3", "Jack", "Napoli", "The_lawyer99yahoo.com", 19, 20, 40, 33, SOFTWARE);
    classRoster.addStudent("A4", "Erin", "Black", "Erin.black@comcast.net", 22, 50, 58, 40, SECURITY);
    classRoster.addStudent("A5", "Justice", "Gudorf", "jgudor1@wgu.edu", 34, 19, 10, 14, SOFTWARE);
}

int main() {
    // Print out course information
    std::cout << "Scripting and Programming Applications C867" << std::endl;
    std::cout << "Programming Language: C++" << std::endl;
    std::cout << "WGU Student ID: 011016837" << std::endl;
    std::cout << "Name: Justice Gudorf" << std::endl;

    Roster classRoster;

    for (const string& data : studentData) {
        size_t rhs = 0;
        size_t lhs = 0;
        rhs = data.find(",", lhs);

        string studentID = data.substr(lhs, rhs - lhs);
        lhs = rhs + 1;

        rhs = data.find(",", lhs);
        string firstName = data.substr(lhs, rhs - lhs);
        lhs = rhs + 1;

        rhs = data.find(",", lhs);
        string lastName = data.substr(lhs, rhs - lhs);
        lhs = rhs + 1;

        rhs = data.find(",", lhs);
        string emailAddress = data.substr(lhs, rhs - lhs);
        lhs = rhs + 1;

        rhs = data.find(",", lhs);
        int age = stoi(data.substr(lhs, rhs - lhs));
        lhs = rhs + 1;

        rhs = data.find(",", lhs);
        int daysInCourse1 = stoi(data.substr(lhs, rhs - lhs));
        lhs = rhs + 1;

        rhs = data.find(",", lhs);
        int daysInCourse2 = stoi(data.substr(lhs, rhs - lhs));
        lhs = rhs + 1;

        rhs = data.find(",", lhs);
        int daysInCourse3 = stoi(data.substr(lhs, rhs - lhs));
        lhs = rhs + 1;

        DegreeProgram degreeProgram;
        string degreeProgramStr = data.substr(lhs, data.length() - lhs);
        if (degreeProgramStr == "SECURITY") degreeProgram = SECURITY;
        else if (degreeProgramStr == "NETWORK") degreeProgram = NETWORK;
        else if (degreeProgramStr == "SOFTWARE") degreeProgram = SOFTWARE;

        classRoster.add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
    }

    classRoster.printAll();
    classRoster.printInvalidEmails();

    // Print average days in course for each student
    for (int i = 0; i < 5; i++) {
        if (classRoster.getClassRosterArray()[i] != nullptr) {
            classRoster.printAverageDaysInCourse(classRoster.getClassRosterArray()[i]->getStudentID());
        }
    }

    classRoster.printByDegreeProgram(SOFTWARE);

    classRoster.remove("A3");
    classRoster.printAll();
    classRoster.remove("A3");

    return 0;
}