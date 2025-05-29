#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

// ----------------Auth System-------------------//

bool existUser(const string &username)
{
    ifstream infile("users.txt");
    string line, user, pass;
    while (getline(infile, line))
    {
        stringstream ss(line);
        getline(ss, user, ',');
        if (user == username)
        {
            return true;
        }
    }
    return false;
}

bool login()
{
    cout << "Enter the username :";
    string username, password;
    cin >> username;
    cout << "Enter the password :";
    cin >> password;
    ifstream infile("users.txt");
    string line, user, pass;
    while (getline(infile, line))
    {
        stringstream ss(line);
        getline(ss, user, ',');
        getline(ss, pass, ',');
        if (user == username && pass == password)
        {
            cout << "Login Successful" << endl;
            return true;
        }
    }
    cout << "Invalid Username or password, try again " << endl;

    return false;
}

bool signup()
{
    string username, password;
    cout << "Enter the username :";
    cin >> username;

    if (existUser(username))
    {
        cout << "Username exist , please log in" << endl;
        return false;
    }
    cout << "Eter the password ";
    cin >> password;
    ofstream outfile("users.txt", ios::app);
    outfile << username << "," << password << endl;
    outfile.close();
    cout << "SignUp successfully" << endl;
    return true;
}

// -----------------Student System---------------//

class Student
{
public:
    int rollno;
    string name;
    float marks;

    void input()
    {
        cout << "Enter roll no" << endl;
        cin >> rollno;
        cin.ignore();
        cout << "Enter name " << endl;
        getline(cin, name);
        cout << "Enter marks " << endl;
        cin >> marks;
    }

    void display() const
    {
        cout << "Roll No " << rollno << "Name " << name << "marks " << marks << "Grade " << calculategread() << endl;
    }

    char calculategread() const
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

    string toCSV() const
    {
        return to_string(rollno) + "," + name + "," + to_string(marks) + "," + calculategread();
    }
};

void addstudent()
{
    ofstream outfile("student.csv", ios::app);
    Student s;
    s.input();
    outfile << s.toCSV() << endl;
    outfile.close();
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

void deletestudent()
{
    ifstream infile("student.csv");
    ofstream tempfile("temp.csv");

    int rollno;
    cout << "Enter the roll no to delete" << endl;
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
        cout << "Student deleted " << endl;
    }
    else
    {
        cout << "student not found" << endl;
    }
}

void updateStudent()
{
    ifstream inFile("student.csv");
    ofstream tempFile("temp.csv");

    int roll;
    cout << "Enter Roll No to update: ";
    cin >> roll;

    string line;
    bool updated = false;
    while (getline(inFile, line))
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
            tempFile << s.toCSV() << endl;
            updated = true;
        }
        else
        {
            tempFile << line << endl;
        }
    }

    inFile.close();
    tempFile.close();

    remove("student.csv");
    rename("temp.csv", "student.csv");

    if (updated)
        cout << "Record updated.\n";
    else
        cout << "Student not found.\n";
}

// ------------------main function--------------//
int main()
{
    int authChoise;
    bool isAuthenticated = false;

    cout << "Welcome to the student record system" << endl;
    do
    {
        cout << "\n1. Login\n2. Signup\n3. Exit\nChoose an option: ";
        cin >> authChoise;
        switch (authChoise)
        {
        case 1:
            isAuthenticated = login();
            break;

        case 2:
            signup();
            break;

        case 3:
            cout << "Program Terminated" << endl;
            return 0;

        default:
            cout << "Invalid input" << endl;
            break;
        }
    } while (!isAuthenticated);

    int choice;
    do
    {
        cout << "\n--- Main Menu ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        switch (choice)
        {
        case 1:
            addstudent();
            break;
        case 2:
            displaystudent();
            break;
        case 3:
            searchstudent();
            break;
        case 4:
            updateStudent();
            break;
        case 5:
            deletestudent();
            break;
        case 6:
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid choice.\n";
            break;
        }
    } while (choice != 6);

    return 0;
}