#include "student.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void Student ::input()
{
    cout << "Enter roll no: ";
    cin >> rollno;
    cin.ignore();
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter marks: ";
    cin >> marks;
}

void Student::display() const
{
    cout << "Roll No: " << rollno
         << ", Name: " << name
         << ", Marks: " << marks
         << ", Grade: " << calculategread() << endl;
}

char Student::calculategread() const
{
    if (marks >= 90)
        return 'A';
    else if (marks >= 75)
        return 'B';
    else if (marks >= 60)
        return 'C';
    else if (marks >= 40)
        return 'D';
    else
        return 'F';
}

string Student::toCSV() const
{
    return to_string(rollno) + "," + name + "," + to_string(marks) + "," + calculategread();
}

void addstudent()
{
    ofstream outfile("student.csv", ios::app);
    Student s;
    s.input();
    outfile << s.toCSV() << endl;
    cout << "Student added Successfully" << endl;
}

void displaystudent()
{
    ifstream infile("student.csv");
    string line;
    while (getline(infile, line))
    {
        cout << line << endl;
    }
}
void deletestudent()
{
    ifstream infile("student.csv");
    ofstream tempfile("temp.csv");
    int rollno;
    cout << "Enter the roll no to delete: ";
    cin >> rollno;

    string line;
    bool deleted = false;
    while (getline(infile, line))
    {
        stringstream ss(line);
        string roll;
        getline(ss, roll, ',');
        if (stoi(roll) != rollno)
        {
            tempfile << line << endl;
        }
        else
        {
            deleted = true;
        }
    }
    infile.close();
    tempfile.close();
    remove("student.csv");
    rename("temp.csv", "student.csv");
    if (deleted)
    {
        cout << "Student Deleted" << endl;
    }
    else
    {
        cout << "Student not found" << endl;
    }
}

void searchstudent()
{
    ifstream infile("student.csv");
    int rollno;
    cout << "Enter the roll no to search :";
    cin >> rollno;

    string line;
    bool found = false;
    while (getline(infile, line))
    {
        stringstream ss(line);
        string rollStr, name, marksStr, grade;
        getline(ss, rollStr, ',');
        getline(ss, name, ',');
        getline(ss, marksStr, ',');
        getline(ss, grade, ',');

        if (stoi(rollStr) == rollno)
        {
            cout << "Record Found: " << line << endl;
            found = true;
            break;
        }
    }
    infile.close();
    if (!found)
        cout << "Student not found.\n";
}

void updateStudent()
{
    ifstream infile("student.csv");
    ofstream tempfile("temp.csv");

    int roll;
    cout << "Enter the rollno " << endl;
    cin >> roll;

    string line;
    bool updated = false;
    while (getline(infile, line))
    {
        stringstream ss(line);
        string rollStr, name, marksStr;
        getline(ss, rollStr, ',');
        getline(ss, name, ',');
        getline(ss, marksStr, ',');
        if (stoi(rollStr) == roll)
        {
            Student s;
            s.rollno = roll;
            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, s.name);
            cout << "Enter new marks: ";
            cin >> s.marks;
            tempfile << s.toCSV() << endl;
            updated = true;
        }
        else
        {
            tempfile << line << endl;
        }
    }
    infile.close();
    tempfile.close();
    remove("student,csv");
    rename("temp.csv", "student.csv");
    if (updated)
    {
        cout << "Record Updated" << endl;
    }
    else
    {
        cout << "Student not Found" << endl;
    }
}