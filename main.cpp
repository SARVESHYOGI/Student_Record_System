#include <iostream>
#include "auth.h"
#include "student.h"

using namespace std;

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