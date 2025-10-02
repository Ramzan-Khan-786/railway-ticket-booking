#include "Train.h"
#include <bits/stdc++.h>
#include "utils.h"
using namespace std;

void Train::addTrain() {
    clearScreen();
    cout << "\n==== Add New Train ====\n";
    cout << "Enter Train Number: ";
    cin >> trainNumber;
    cout << "Enter Train Name: ";
    cin.ignore();
    cin.getline(trainName, 50);
    cout << "Enter Source: ";
    cin.getline(source, 50);
    cout << "Enter Destination: ";
    cin.getline(destination, 50);
    cout << "Enter Total Seats: ";
    cin >> totalSeats;
    availableSeats = totalSeats;

    ofstream outFile("trains.dat", ios::binary | ios::app);
    outFile.write(reinterpret_cast<char*>(this), sizeof(Train));
    outFile.close();

    cout << "\nTrain added successfully!\n";
}

void Train::displayTrainDetails() {
    cout << left << setw(15) << trainNumber
         << setw(20) << trainName
         << setw(15) << source
         << setw(15) << destination
         << setw(10) << availableSeats << endl;
}

void Train::viewAllTrains() {
    ifstream inFile("trains.dat", ios::binary);
    if (!inFile) {
        cout << "\nNo trains available.\n";
        return;
    }
    cout << "\n==== All Trains ====\n";
    cout << left << setw(15) << "Train No"
         << setw(20) << "Train Name"
         << setw(15) << "Source"
         << setw(15) << "Destination"
         << setw(10) << "Seats Avl" << endl;

    while(inFile.read(reinterpret_cast<char*>(this), sizeof(Train))) {
        displayTrainDetails();
    }
    inFile.close();
}

void Train::searchTrain(const char* src, const char* dest) {
    ifstream inFile("trains.dat", ios::binary);
    bool found = false;
    if (!inFile) {
        cout << "\nNo trains available.\n";
        return;
    }
    cout << "\n==== Search Results ====\n";
    while(inFile.read(reinterpret_cast<char*>(this), sizeof(Train))) {
        if (strcasecmp(source, src) == 0 && strcasecmp(destination, dest) == 0) {
            displayTrainDetails();
            found = true;
        }
    }
    if (!found) cout << "\nNo trains found.\n";
    inFile.close();
}

void Train::bookSeats(int numSeats) {
    if (availableSeats >= numSeats) availableSeats -= numSeats;
}

void Train::cancelSeats(int numSeats) {
    availableSeats += numSeats;
}

const char* Train::getTrainNumber() const {
    return trainNumber;
}
