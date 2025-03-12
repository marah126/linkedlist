#pragma once

#include "Student.hpp"
#include "Course.hpp"

using namespace std;

class StudentsList {
private:
	Student* studentsList;

public:
	StudentsList();
	void addStudent(string studentID);
	Student* checkStudentID(string studentID);
	void setStudentName(string id, string name);
	void setStudentMajor(string id, string major);
	void setStudentBirthdate(string id, string bd);
	string getStudentName(string id);
	string getStudentMajor(string id);
	string getStudentBirthdate(string id);
	void deleteStudent(string studentID);
	void print();
	void setCourseGrade(string studentID, string courseNumber, float grade);
	float getCourseGrade(string studentID, string courseNumber);
	float getAverage(string studentID);
	void printStudentInfo(string studentID);
	void addCourse(string studentID, string courseNumber, int hours);
	//Course* checkCourseID(string id);
};