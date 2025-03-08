#pragma once
#include <string>
using namespace std;

class Course {
private: 
    const string m_courseNumber;
    int m_creditHours;
    float m_grade;

    Course(string courseID, string creditHours);

public:
    Courses* next;
    // Course addCourse(string courseID, string creditHours);
    void setGrade(float grade);
    float getGrade();
    string getCourseNumber();
    int getCourseCredit();
};