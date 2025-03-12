#include "Student.hpp"

#include <iostream>
#include <regex>

Student::Student(string ID) : m_ID(ID) {
    courses = nullptr;
    next = nullptr;
}

void Student::setStudentName(string studentName) {
    if (studentName == "") {
        cout << "Student name cannot be empty!!" << endl;
        return;
    }
    m_name = studentName;
    cout << "Student name is set to : " << studentName << endl;
}

void Student::setStudentMajor(string studentMajor) {
    if (studentMajor == "") {
        cout << "Student major cannot be empty!!" << endl;
        return;
    }
    m_major = studentMajor;
    cout << "Student Major is set to : " << studentMajor << endl;
}

void Student::setStudentBirthdate(string studentBirthdate) {
    if (studentBirthdate == "") {
        cout << "Student birthdate cannot be empty!!" << endl;
        return;
    }
    else {
        regex birthdateRegex(R"(\d{1,2}/\d{1,2}/\d{4})");
        if (regex_match(studentBirthdate, birthdateRegex)) {
            m_birthdate = studentBirthdate;
            cout << "Student birthdate is set to : " << studentBirthdate << endl;
        }
        else {
            cout << "Student birthdate should be formatted like this DD/MM/YYYY" << endl;
            return;
        }
    }
}

const string Student::getStudentID() {
    return m_ID;
}

string Student::getStudentName() {
    if (m_name.empty()) {
        cout << "Student name is not initialized" << endl;
        return "";
    }
    return m_name;
}

string Student::getStudentMajor() {
    if (m_major.empty()) {
        cout << "Student major is not initialized" << endl;
        return "";
    }
    return m_major;
}

string Student::getStudentBirthdate() {
    if (m_birthdate.empty()) {
        cout << "Student birthdate is not initialized" << endl;
        return "";
    }
    return m_birthdate;
}

void Student::addCourse(string courseID, int creditHours) {
    /*if (courseID == "") {
        cout << "Course ID cannot be empty!" << endl;
        return;
    }
    if (creditHours >= 0) {
        cout << "Credit hours cannot be 0 or negative!!" << endl;
        return;
    }*/
    Course* c = new Course (courseID, creditHours);
    if (courses == nullptr) {
        courses = c;
    }
    else {
        c->next = courses;
        courses = c;
    }
}

void Student::setGrade(string courseID, float courseGrade) {
    Course* c = checkCourseID(courseID);
    if (!c) {
        cout << "This course ID doesn't exist" << endl;
        return;
    }
    c->setGrade(courseGrade);       
}

float Student::getGrade(string courseID) {
    if (courses == nullptr) {
        cout << "No courses for this student" << endl;
        return -1;
    }
    Course* c = checkCourseID(courseID);
    if (!c) {
        cout << "This course ID doesn't exist" << endl;
        return -1;
    }
    return c->getGrade();
}

float Student::getAverage() {
    if (courses == nullptr) {
        cout << "No courses!!" << endl;
        return -1;
    }
    Course* c = courses;
    float sum = 0;
    int count = 0;
    while (c) {
        count++;
        sum += c->getGrade();
    }
    return sum / count;
}

void Student::printInfo() {
    cout << "ID: " << m_ID << endl;
    cout << "Name: " << m_name << endl;
    cout << "Major: " << m_major << endl;
    cout << "BirthDate: " << m_birthdate << endl;
    cout << "Courses: " << endl;
    cout << "Average: " << getAverage();
    if (courses == nullptr) {
        cout << "No courses for this student";
    }
    else {
        cout << "CNO \t\t Credit Hours \t\t Grade" << endl;
        Course* c = courses;
        while (c != nullptr) {
            cout << c->getCourseNumber() << " \t\t " << c->getCourseCredit() << " \t\t " << c->getGrade() << endl;
        }
    }
}

Course* Student::checkCourseID(string id) {
    Course* current = courses;
    while (current) {
        if (current->getCourseNumber() == id) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}


