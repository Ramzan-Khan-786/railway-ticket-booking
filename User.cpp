#include "User.h"
#include <bits/stdc++.h>
#include "utils.h"
using namespace std;
void User::registerUser() {
    clearScreen();
    cout << "\n\t\t\t=============================================";
    cout << "\n\t\t\t\t      User Registration";
    cout << "\n\t\t\t=============================================";
    cout << "\n\n\t\t\tEnter Username: ";
    cin >> username;
    cout << "\t\t\tEnter Password: ";
    cin >> password;

    ofstream outFile("users.dat", ios::binary | ios::app);
    if (!outFile) {
        cerr << "Error opening users file for writing!" << endl;
        return;
    }
    outFile.write(reinterpret_cast<char*>(this), sizeof(User));
    outFile.close();

    cout << "\n\t\t\tRegistration successful!" << endl;
}

bool User::loginUser() {
    char inputUsername[50];
    char inputPassword[50];
    bool userFound = false;

    clearScreen();
    cout << "\n\t\t\t=============================================";
    cout << "\n\t\t\t\t        User Login";
    cout << "\n\t\t\t=============================================";
    cout << "\n\n\t\t\tEnter Username: ";
    cin >> inputUsername;
    cout << "\t\t\tEnter Password: ";
    cin >> inputPassword;

    ifstream inFile("users.dat", ios::binary);
    if (!inFile) {
        cerr << "No user data found. Please register first." << endl;
        return false;
    }

    while (inFile.read(reinterpret_cast<char*>(this), sizeof(User))) {
        if (strcmp(this->username, inputUsername) == 0 && strcmp(this->password, inputPassword) == 0) {
            userFound = true;
            break;
        }
    }
    inFile.close();

    if (userFound) {
        cout << "\n\t\t\tLogin successful! Welcome " << this->username << "!" << endl;
        return true;
    } else {
        cout << "\n\t\t\tInvalid username or password." << endl;
        return false;
    }
}

string User::getUsername() {
    return string(username);
}