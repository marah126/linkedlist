#include "StudentsList.hpp"

#include <iostream>

using namespace std;


StudentsList::StudentsList(): studentsList(nullptr){}


void StudentsList::addStudent(string studentID) {
    if (studentID.empty()) {
        cout << "Student ID cannot be empty!" << endl;
        return;
    }
    if (checkStudentID(studentID)) {
        cout << "This ID is already exists!" << endl;
        return;
    }
    Student* s = new Student(studentID);
    if (!studentsList) {
        studentsList = s;
    }
    else {
        int thisID = stoi(studentID);
        Student* current = studentsList;
        Student* previous = nullptr;
        while (current) {
            int currentID = stoi(current->getStudentID());
            if (thisID <= currentID) {
                s->next = current;
                if (!previous) {
                    studentsList = s;
                }
                else {
                    previous->next = s;
                }
                cout << "A new student is added" << endl;
                return;
            }
            else {
                previous = current;
                current = current->next;
            }
        }
        previous->next = s;
        cout << "A new student is added" << endl;
    }
}

Student* StudentsList::checkStudentID(string studentID) {
    /*if (studentID.empty()) {
        cout << "Student ID cannot be empty!" << endl;
        return true;
    }*/
    Student* current = studentsList;
    while (current) {
        if (current->getStudentID() == studentID) {
            /*cout << "This ID is already exists!" << endl;*/
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void StudentsList::setStudentName(string id, string name) {
    if (id.empty()) {
        cout << "Student ID cannot be empty!" << endl;
        return;
    }
    Student* current = checkStudentID(id);
    if (!current) {
        cout << "This ID doesn't exist" << endl;
        return;
    }
    current->setStudentName(name);
    return;
    /*Student* current = studentsList;
    while (current) {
        if (current->getStudentID() == id) {
            current->setStudentName(name);
            return;
        }
        current = current->next;
    }*/
}

void StudentsList::setStudentMajor(string id, string major) {
    if (id.empty()) {
        cout << "Student ID cannot be empty!" << endl;
        return;
    }
    Student* current = checkStudentID(id);
    if (!current) {
        cout << "This ID doesn't exist" << endl;
        return;
    }
    current->setStudentMajor(major);
    return;
}

void StudentsList::setStudentBirthdate(string id, string bd) {
    if (id.empty()) {
        cout << "Student ID cannot be empty!" << endl;
        return;
    }
    Student* current = checkStudentID(id);
    if (!current) {
        cout << "This ID doesn't exist" << endl;
        return;
    }
    current->setStudentBirthdate(bd);
    return;
}

string StudentsList::getStudentName(string id) {
    if (id.empty()) {
        cout << "Student ID cannot be empty!" << endl;
        return "";
    }
    Student* current = checkStudentID(id);
    if (!current) {
        cout << "This ID doesn't exist" << endl;
        return "";
    }
    return current->getStudentName();
}

string StudentsList::getStudentMajor(string id) {
    if (id.empty()) {
        cout << "Student ID cannot be empty!" << endl;
        return "";
    }
    Student* current = checkStudentID(id);
    if (!current) {
        cout << "This ID doesn't exist" << endl;
        return "";
    }
    return current->getStudentMajor();
}

string StudentsList::getStudentBirthdate(string id) {
    if (id.empty()) {
        cout << "Student ID cannot be empty!" << endl;
        return "";
    }
    Student* current = checkStudentID(id);
    if (!current) {
        cout << "This ID doesn't exist" << endl;
        return "";
    }
    return current->getStudentBirthdate();
}

void StudentsList::deleteStudent(string studentID) {
    if (studentID.empty()) {
        cout << "Student ID cannot be empty!" << endl;
        return;
    }
    if (studentsList == nullptr) {
        cout << "No students exist";
        return;
    }
    Student* current = checkStudentID(studentID);
    if (!current) {
        cout << "This ID doesn't exist" << endl;
        return;
    }
     
    if (studentsList == current) {
        studentsList = current->next;
        return;
    }

    Student* previous = studentsList;

    while (previous->next != current) {
        previous = previous->next;
    }
    
    previous->next = current->next;
    current = nullptr;
    
    /*Student* current = studentsList;
    Student* next = studentsList->next;
    Student* previous = nullptr;
    while (current != nullptr) {
        if (current->getStudentID() == studentID) {
            if (previous == nullptr) {
                studentsList = current->next;
            }
            else {
                previous->next = current->next;
                studentsIDs.erase(studentID);
            }
        }
        previous = current;
        current = next;
        if (current->next != nullptr) {
            next = current->next;
        }
    }
    return studentsList;*/
}
void StudentsList::print() {
    if (!studentsList) {
        return;
    }
    Student* current = studentsList;
    while (current) {
        cout << current->getStudentID() << " -> ";
        current = current->next;
    }
    cout << endl;
}

void StudentsList::setCourseGrade(string studentID, string courseNumber, float grade) {
    if (studentID.empty()) {
        cout << "Student ID cannot be empty!";
        return;
    }

    if (courseNumber.empty()) {
        cout << "Course number is empty or the grade is less than 0";
        return;
    }

    if (grade > 100 || grade < 0) {
        cout << "Grade shoud be between 0 and 100";
        return;
    }

    Student* current = checkStudentID(studentID);

    if (!current) {
        cout << "This ID doesn't exist" << endl;
        return ;
    }
    current->setGrade(courseNumber, grade);
}

float StudentsList::getCourseGrade(string studentID, string courseNumber) {
    if (studentID.empty()) {
        cout << "Student ID cannot be empty!";
        return -1;
    }
    Student* current = checkStudentID(studentID);

    if (!current) {
        cout << "This ID doesn't exist" << endl;
        return -1;
    }
    return current->getGrade(courseNumber);
    
}

float StudentsList::getAverage(string studentID) {
    if (studentID.empty()) {
        cout << "Student ID cannot be empty!";
        return -1;
    }
    Student* current = checkStudentID(studentID);

    if (!current) {
        cout << "This ID doesn't exist" << endl;
        return -1;
    }
    return current-> getAverage();     
}

void StudentsList::printStudentInfo(string studentID) {
    if (studentID.empty()) {
        cout << "Student ID cannot be empty!";
        return;
    }
    Student* current = checkStudentID(studentID);
    if (!current) {
        cout << "This ID doesn't exist" << endl;
        return;
    }
    cout << "ID: " << current->getStudentID() << endl;
    cout << "Name: " << current->getStudentName() << endl;
    cout << "Major: " << current->getStudentMajor() << endl;
    cout << "BirthDate: " << current->getStudentBirthdate() << endl;
    cout << "Courses: " << endl;
 
    if (current->courses == nullptr) {
        cout << "Average: " << current->getAverage() << endl;
        cout << "No courses for this student" << endl;
    }
    else {
        cout << "CNO \t\t Credit Hours \t\t Grade" << endl;
        Course* c = current->courses;
        while (c) {
            cout << c->getCourseNumber() << " \t\t " << c->getCourseCredit() << " \t\t " << c->getGrade() << endl;
            c = c->next;
        }
    }
}

void StudentsList::addCourse(string studentID, string courseNumber, int hours) {
    if (studentID.empty()) {
        cout << "Student ID cannot be empty!";
        return;
    }
    if (courseNumber.empty()) {
        cout << "Course ID cannot be empty!" << endl;
        return;
    }
    if (hours <= 0) {
        cout << "Credit hours cannot be 0 or negative!!" << endl;
        return;
    }
    Student* current = checkStudentID(studentID);
    if (!current) {
        cout << "This ID doesn't exist" << endl;
        return;
    }
    current->addCourse(courseNumber, hours);
}