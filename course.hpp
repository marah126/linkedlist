#pragma once
#include <string>
using namespace std;

class Course {
private:
    const string m_courseNumber;
    int m_creditHours;
    float m_grade;


public:
    Course(string courseID, int creditHours);
    Course* next;
    // Course addCourse(string courseID, string creditHours);
    void setGrade(float grade);
    float getGrade();
    string getCourseNumber();
    int getCourseCredit();
};