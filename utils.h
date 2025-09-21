#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <cstdlib>

inline void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

#endif // UTILS_H