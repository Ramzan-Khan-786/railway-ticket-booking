#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <cstdlib>
using namespace std;

inline void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

inline void pauseScreen() {
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

#endif
