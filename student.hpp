#pragma once

#include <string>

using namespace std;

class Student {
private:
    const string m_ID;
    string m_name; 
    string m_major;
    string m_birthdate;
    Course* courses;

    

public:

    Student* next;

    explicit Student(string ID);
    // void addStudent(string studentID);
    // void deleteStudent(string studentID);
    void setStudentName(string studentName);
    void setStudentMajor(string studentMajor);
    void setStudentBirthdate(string studentBirthdate);
    string getStudentName();
    string getStudentMajor();
    string getStudentBirthdate();
    const string getStudentID();
    void addCourse(string courseID, int creditHours);
    void setGrade(string courseID);
    float getGrade(string courseID);
    float getAverage();
    void printInfo();

};