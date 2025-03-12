#include "StudentsList.hpp"
#include <unordered_set>
#include <iostream>

using namespace std;

int main() {
    StudentsList stdList;
    stdList.addStudent("123456789");
    stdList.addStudent("111111111");
    stdList.addStudent("333333333");
    stdList.print();
    //stdList.deleteStudent("333333333");
    //stdList.print();
    stdList.addCourse("123456789", "10", 3);
    stdList.printStudentInfo("111111111");
    stdList.printStudentInfo("123456789");

    /*stdList.addStudent("123456789");
    cout << stdList.getStudentName("123456789") << endl;
    cout << stdList.getStudentMajor("123456789") << endl;
    cout << stdList.getStudentBirthdate("123456789") << endl;
    stdList.setStudentName("", "Marah");
    stdList.setStudentName("1234589", "Marah");
    stdList.setStudentName("123456789", "");
    stdList.setStudentName("123456789","Marah");
    cout << "======================" << endl;
    stdList.setStudentMajor("", "Computer Engineer");
    stdList.setStudentMajor("12", "Computer Engineer");
    stdList.setStudentMajor("123456789", "");
    stdList.setStudentMajor("123456789", "Computer Engineer");
    cout << "======================" << endl;
    stdList.setStudentBirthdate("", "11");
    stdList.setStudentBirthdate("12", "11");
    stdList.setStudentBirthdate("123456789", "11");
    stdList.setStudentBirthdate("123456789", "12/06/2001");

    cout << stdList.getStudentName("123456789") << endl;
    cout << stdList.getStudentMajor("123456789") << endl;
    cout << stdList.getStudentBirthdate("123456789") << endl;*/



}