#include "Course.hpp"

#include <iostream>

using namespace std;

Course::Course(string courseID, int creditHours): m_courseNumber(courseID), m_creditHours(creditHours), m_grade(0.0) {
    next = nullptr;
}

//Course::addCourse(string courseID, string creditHours, float grade) {
//    if (courseID == "") {
//        cout << "Course number cannot be empty!!";
//        return nullptr;
//    }
//    if (creditHours >= 0) {
//        cout << "Credit hours cannot be 0 or negative!!";
//        return nullptr;
//    }
//    if (grade > 100 || grade < 0) {
//        cout << "Grade shoud be between 0 and 100";
//        return nullptr;
//    }
//    Course course = new Course(courseID, creditHours, grade);
//    return course;
//}

void Course::setGrade(float grade) {
    if (grade > 100 || grade < 0) {
        cout << "Grade shoud be between 0 and 100";
        return;
    }
    m_grade = grade;
}

float Course::getGrade() {
    return m_grade;
}

string Course::getCourseNumber() {
    return m_courseNumber;
}

int Course::getCourseCredit() {
    return m_creditHours;
}