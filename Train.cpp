#include "Train.h"
#include<bits/stdc++.h>
#include "utils.h"
using namespace std;
void Train::addTrain() {
    clearScreen();
    cout << "\n\t\t\t=============================================";
    cout << "\n\t\t\t\t        Add New Train";
    cout << "\n\t\t\t=============================================";
    cout << "\n\n\t\t\tEnter Train Number: ";
    cin >> trainNumber;
    cout << "\t\t\tEnter Train Name: ";
    cin.ignore();
    cin.getline(trainName, 50);
    cout << "\t\t\tEnter Source: ";
    cin.getline(source, 50);
    cout << "\t\t\tEnter Destination: ";
    cin.getline(destination, 50);
    cout << "\t\t\tEnter Total Seats: ";
    cin >> totalSeats;
    availableSeats = totalSeats;

    ofstream outFile("trains.dat", ios::binary | ios::app);
    outFile.write(reinterpret_cast<char*>(this), sizeof(Train));
    outFile.close();

    cout << "\n\t\t\tTrain added successfully!" << endl;
}

void Train::displayTrainDetails() {
    cout << left << setw(20) << trainNumber
              << setw(20) << trainName
              << setw(20) << source
              << setw(20) << destination
              << setw(10) << availableSeats << endl;
}

void Train::searchTrain(const char* src, const char* dest) {
    ifstream inFile("trains.dat", ios::binary);
    bool found = false;

    clearScreen();
    cout << "\n\t\t\t=====================================================================================================";
    cout << "\n\t\t\t\t\t\t      Available Trains";
    cout << "\n\t\t\t=====================================================================================================";
    cout << "\n\t\t\t" << left << setw(20) << "Train No."
              << setw(20) << "Train Name"
              << setw(20) << "Source"
              << setw(20) << "Destination"
              << setw(10) << "Seats Avl." << endl;
    cout << "\t\t\t-----------------------------------------------------------------------------------------------------\n";

    while(inFile.read(reinterpret_cast<char*>(this), sizeof(Train))) {
        if (strcasecmp(source, src) == 0 && strcasecmp(destination, dest) == 0) {
            cout << "\t\t\t";
            displayTrainDetails();
            found = true;
        }
    }

    if (!found) {
        cout << "\n\n\t\t\tNo trains found for the specified route." << endl;
    }
    inFile.close();
}


void Train::bookSeats(int numSeats) {
    if (numSeats > 0 && availableSeats >= numSeats) {
        availableSeats -= numSeats;
    }
}

void Train::cancelSeats(int numSeats) {
    availableSeats += numSeats;
}

const char* Train::getTrainNumber() const {
    return trainNumber;
}