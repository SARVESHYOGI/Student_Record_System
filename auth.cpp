#include "auth.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

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
    cout << "Enter the username : ";
    string username, password;
    cin >> username;
    cout << "Enter the password : ";
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
    cout << "Invalid Username or Password. Try again.\n";
    return false;
}

bool signup()
{
    string username, password;
    cout << "Enter the username : ";
    cin >> username;
    if (existUser(username))
    {
        cout << "Username already exists. Please log in.\n";
        return false;
    }
    cout << "Enter the password : ";
    cin >> password;
    ofstream outfile("users.txt", ios::app);
    outfile << username << "," << password << endl;
    cout << "Signup successful.\n";
    return true;
}
