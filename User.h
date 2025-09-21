#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    char username[50];
    char password[50];

public:
    void registerUser();
    bool loginUser();
    std::string getUsername();
};

#endif // USER_H