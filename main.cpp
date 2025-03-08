#include<student.hpp>
#include<course.hpp>
#include<unordered_set>
#include<iostream>

using namespace std;

unordered_set<string> studentsIDs;
unordered_set<string> coursesIDS;

Student* studentsList;

void addStudent(string studentID){
    if (studentID == "") {
        cout << "Student ID cannot be empty!!";
        return;
    }
    if (studentsIDs.find(studentID == studentsIDs.end())) {
        cout << "This ID exist before!!";
        return;
    }
    Student s = new Student(studentID);
    if (studentsList == nullptr) {
        studentsList = s;
    }
    int thisID = stoi(studentID);
    Student* current = studentsList;
    Student* previous = nullptr;
    else {
        while (current != nullptr){
            int currentID = stoi(current->getStudentID());
            if (thisID <= currentID){
                s->next = current;
                previous-<next = s;
            }
            else {
                previous = current;
                current = current->next;
            }
        }
    }
    cout << "A new student is added";
}

Student deleteStudent(string studentID) {
    if (studentID == "") {
        return;
    }
    if (studentsIDs.find(studentID != studentsIDs.end())) {
        cout << "This ID doesn't exist to be deleted!";
        return;
    }
    if (studentsList == nullptr) {
        cout << "No students exist";
        return;
    }
    Student* current = studentsList;
    Student* next = studentsList->next;
    Student* previous = nullptr;
    while (current != nullptr) {
        if (current->getStudentID() == studentID) {
            if (previous == nullptr){
                studentsList = current->next; 
            }
            else {
                previous->next = current->next;
                studentsList.erase(studentID);
            }   
        }
        previous = current;
        current = next;
        if (current->next != nullptr) {
            next = current->next;
        }
    }   
}

void setStudentName(string id, string name) {
    if (studentsIDs.find(id) == studentsIDs.end()) {
        cout << "This ID doesn't exist";
        return;
    }
    current = studentsList;
    while (current != nullptr){
        if(current.getStudentID == id) {
            current.setStudentName(name);
        }
        else {
            current = current->next;
        }
    }
}

void setStudentMajor(string id, string major) {
    if (studentsIDs.find(id) == studentsIDs.end()) {
        cout << "This ID doesn't exist";
        return;
    }
    current = studentsList;
    while (current != nullptr){
        if(current.getStudentID == id) {
            current.setStudentMajor(major);
        }
        else {
            current = current->next;
        }
    }
}

void setStudentBirthdate(string id, string bd) {
    if (studentsIDs.find(id) == studentsIDs.end()) {
        cout << "This ID doesn't exist";
        return;
    }
    current = studentsList;
    while (current != nullptr){
        if(current.getStudentID == id) {
            current.setStudentBirthdate(bd);
        }
        else {
            current = current->next;
        }
    }
}

string getStudentName(string id) {
    if (studentsIDs.find(id) == studentsIDs.end()) {
        cout << "This ID doesn't exist";
        return;
    }
    current = studentsList;
    while (current != nullptr){
        if(current.getStudentID == id) {
            return current.getStudentName();
        }
        else {
            current = current->next;
        }
    }
}

string getStudentMajor(string id) {
    if (studentsIDs.find(id) == studentsIDs.end()) {
        cout << "This ID doesn't exist";
        return;
    }
    current = studentsList;
    while (current != nullptr){
        if(current.getStudentID == id) {
            return current.getStudentMajor();
        }
        else {
            current = current->next;
        }
    }
}

string getStudentBirthdate(string id) {
    string getStudentName(string id) {
        if (studentsIDs.find(id) == studentsIDs.end()) {
            cout << "This ID doesn't exist";
            return;
        }
        current = studentsList;
        while (current != nullptr){
            if(current.getStudentID == id) {
                return current.getStudentBirthdate();
            }
            else {
                current = current->next;
            }
        }
    }
}

void setCourseGrade(string studentID, string courseNumber, float grade) {
    if (studentID == "") {
        cout << "Student ID cannot be empty!";
        return;
    }
    if (studentsIDs.find(studentID) == studentsIDs.end()) {
        cout << "This student ID doesn't exist";
        return;
    }
    if (courseNumber == ""){
        cout << "Course number cannot be empty";
        return;
    }
    if (coursesIDS.find(courseNumber) == coursesIDS.end()) {
        cout << "This course ID doesn't exist";
        return;
    }
    (grade > 100 || grade < 0 ) {
        cout << "Grade shoud be between 0 and 100";
        return nullptr;
    }
    if (courses == nullptr) {
        return;
    }
    
    Student* s = studentsList;
    while (s != nullptr) {
        if (s->getStudentID() == studentID) {
            s->setGrade(courseNumber);
            // Course* c = s->courses;
            // while (c != nullptr) {
            //     if (c->getCourseNumber() == courseNumber) {
            //         c->setGrade(grade);
            //     }
            // }
        }
    }
}

float getCourseGrade(string studentID, string courseNumber) {
    if (studentID == "") {
        cout << "Student ID cannot be empty!";
        return -1;
    }
    if (studentsIDs.find(studentID) == studentsIDs.end()) {
        cout << "This student ID doesn't exist";
        return -1;
    }
    if (courseNumber == ""){
        cout << "Course number cannot be empty";
        return -1;
    }
    if (coursesIDS.find(courseNumber) == coursesIDS.end()) {
        cout << "This course ID doesn't exist";
        return -1;
    }
    Student* s = studentsList;
    while (s != nullptr) {
        if (s->getStudentID() == studentID) {
            return s->getGrade();
            // Course* c = s->courses;
            // while (c != nullptr) {
            //     if (c->getCourseNumber() == courseNumber) {
            //         return c->getGrade(grade);
            //     }
            // }
        }
    }
    return -1;
}

float getAverage(string studentID) {
    if (studentID == "") {
        cout << "Student ID cannot be empty!";
        return -1;
    }
    if (studentsIDs.find(studentID) == studentsIDs.end()) {
        cout << "This student ID doesn't exist";
        return -1;
    }
    Student* s = studentsList;
    while (s != nullptr) {
        if (s->getStudentID() == studentID) {
            return s->getAverage();
        }
    }
    return -1;
}

void printStudentInfo(string studentID) {
    if (studentID == "") {
        cout << "Student ID cannot be empty!";
        return -1;
    }
    if (studentsIDs.find(studentID) == studentsIDs.end()) {
        cout << "This student ID doesn't exist";
        return -1;
    }
    Student* s = studentsList;
    while (s != nullptr) {
        if (s->getStudentID() == studentID) {
            s->printInfo();
        }
    }
}
int main(){
    
}