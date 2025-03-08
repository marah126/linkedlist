#include <student.hpp>
#include <iostream>
#include <regex>

Student::Student(string ID): m_major(ID) {
    courses = nullptr;
    next = nullptr;
}

// void Student::addStudent(string studentID) {
    
// }

// void Student::deleteStudent(string studentID) {

// }

void Student::setStudentName(string studentName) {
    if (studentName == "") {
        cout << "Student name cannot be empty!!";
        return;
    }
    m_name = studentName;
}

void Student:: setStudentMajor(string studentMajor) {
    if (setStudentMajor == "") {
        cout << "Student major cannot be empty!!";
        return;
    }
    m_major = setStudentMajor;
}

void Student::setStudentBirthdate(string studentBirthdate) {
    if (setStudentBirthdate == "") {
        cout << "Student birthdate cannot be empty!!";
        return;
    }
    else{
        regex birthdateRegex(R"(\d{1,2}/\d{1,2}/\d{4})");
        if (regex_match(studentBirthdate, birthdateRegex)) {
            m_birthdate = studentBirthdate;
        }
        else{
            cout << "Student birthdate should be formatted like this DD/MM/YYYY";
            return;
        }
    }
}

const string Student::getStudentID() {
    return m_ID;
}

string Student::getStudentName() {
    if (m_name.empty()) {
        cout << "Student name is not initialized";
        return "";
    }
    return m_name;
}

string Student::getStudentMajor() {
    if (m_major.empty()) {
        cout << "Student name is not initialized";
        return "";
    }
    return m_major;
}

string Student::getStudentBirthdate() {
    if (m_ID.m_birthdate()) {
        cout << "Student name is not initialized";
        return "";
    }
    return m_birthdate;
}

void Student::addCourse(string courseID, int creditHours) {
    if (courseID == ""){
        cout << "Course ID cannot be empty!";
        return;
    }
    if (creditHours >= 0) {
        cout << "Credit hours cannot be 0 or negative!!";
        return;
    }
    Course* c = new Course(courseID, creditHours);
    if(courses == nullptr) {
        courses = c;
    }
    else {
        c->next = courses;
        courses = c;
    }
}

void Student::setGrade(string courseID) {
    Course* c = courses;
        while (c != nullptr) {
            if (c->getCourseNumber() == courseID) {
                c->setGrade(grade);
            }
        }
}

float Student::getGrade(string courseID) {
    if (courses == nullptr){
        return
    }
    Course* c = courses;
        while (c != nullptr) {
            if (c->getCourseNumber() == courseNumber) {
                return c->getGrade(grade);
            }
        }
}

float Student::getAverage() {
    if (courses == nullptr) {
        cout << "No courses!!";
        return -1;
    }
    Course c = courses;
    float sum = 0;
    int count = 0;
    while (c != nullptr) {
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
    if (Courses == nullptr) {
        cout << "No courses for this student";
    }
    else {
        cout << "CNO \t\t Credit Hours \t\t Grade" << endl;
        Course c = courses;
        while (c != nullptr) {
            cout << c->getCourseNumber() << " \t\t " << c->getCourseCredit() << " \t\t " << c->getCourseGrade();
        }
    }
}

