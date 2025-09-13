#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student
{
public:
    int rollno;
    std::string name;
    float marks;

    void input();
    void display() const;
    char calculategread() const;
    std::string toCSV() const;
};

void addstudent();
void displaystudent();
void searchstudent();
void deletestudent();
void updateStudent();

#endif