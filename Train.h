#ifndef TRAIN_H
#define TRAIN_H

#include <string>

class Train {
private:
    char trainNumber[20];
    char trainName[50];
    char source[50];
    char destination[50];
    int totalSeats;
    int availableSeats;

public:
    void addTrain();
    void displayTrainDetails();
    void searchTrain(const char* src, const char* dest);
    void bookSeats(int numSeats);
    void cancelSeats(int numSeats);
    const char* getTrainNumber() const;
};

#endif // TRAIN_H