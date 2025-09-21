#include "Ticket.h"
#include "Train.h"
#include "utils.h"
#include<bits/stdc++.h>
using namespace std;
void Ticket::createTicket(const string& user, const string& trnNo) {
    srand(time(0));
    pnrNumber = time(0) + rand() % 1000;
    
    strcpy(trainNumber, trnNo.c_str());
    strcpy(bookingUser, user.c_str());
    
    cout << "\t\t\tEnter Passenger Name: ";
    cin.ignore();
    cin.getline(passengerName, 50);
    cout << "\t\t\tEnter Passenger Age: ";
    cin >> passengerAge;
    cout << "\t\t\tEnter Passenger Gender (M/F): ";
    cin >> passengerGender;

    Train train;
    bool trainFound = false;
    fstream file("trains.dat", ios::in | ios::out | ios::binary);

    while(file.read(reinterpret_cast<char*>(&train), sizeof(Train))) {
        if (strcmp(train.getTrainNumber(), trnNo.c_str()) == 0) {
            train.bookSeats(1);
            file.seekp(static_cast<long>(file.tellg()) - sizeof(Train));
            file.write(reinterpret_cast<char*>(&train), sizeof(Train));
            trainFound = true;
            break;
        }
    }
    file.close();

    if(trainFound) {
        ofstream outFile("tickets.dat", ios::binary | ios::app);
        outFile.write(reinterpret_cast<char*>(this), sizeof(Ticket));
        outFile.close();

        clearScreen();
        cout << "\n\t\t\t=============================================";
        cout << "\n\t\t\t\t      Ticket Booked!";
        cout << "\n\t\t\t=============================================\n";
        displayTicket();

    } else {
        cout << "\n\t\t\tError in booking. Train not updated." << endl;
    }
}

void Ticket::displayTicket() {
    cout << "\n\t\t\tPNR Number: " << pnrNumber;
    cout << "\n\t\t\tTrain Number: " << trainNumber;
    cout << "\n\t\t\tPassenger Name: " << passengerName;
    cout << "\n\t\t\tAge: " << passengerAge;
    cout << "\n\t\t\tGender: " << passengerGender << endl;
    cout << "\t\t\t---------------------------------------------\n";
}

void Ticket::cancelTicket() {
    long long pnr;
    bool ticketFound = false;
    cout << "\n\t\t\tEnter PNR Number to cancel: ";
    cin >> pnr;

    ifstream inFile("tickets.dat", ios::binary);
    ofstream tempFile("temp.dat", ios::binary);

    while(inFile.read(reinterpret_cast<char*>(this), sizeof(Ticket))) {
        if (this->pnrNumber == pnr) {
            ticketFound = true;
            Train train;
            fstream trainFile("trains.dat", ios::in | ios::out | ios::binary);
            while(trainFile.read(reinterpret_cast<char*>(&train), sizeof(Train))) {
                if(strcmp(train.getTrainNumber(), this->trainNumber) == 0) {
                    train.cancelSeats(1);
                    trainFile.seekp(static_cast<long>(trainFile.tellg()) - sizeof(Train));
                    trainFile.write(reinterpret_cast<char*>(&train), sizeof(Train));
                    break;
                }
            }
            trainFile.close();
        } else {
            tempFile.write(reinterpret_cast<char*>(this), sizeof(Ticket));
        }
    }

    inFile.close();
    tempFile.close();

    remove("tickets.dat");
    rename("temp.dat", "tickets.dat");

    if(ticketFound) {
        cout << "\n\t\t\tTicket with PNR " << pnr << " cancelled successfully." << endl;
    } else {
        cout << "\n\t\t\tTicket with PNR " << pnr << " not found." << endl;
    }
}

long long Ticket::getPNR() const {
    return pnrNumber;
}

const char* Ticket::getTrainNumber() const {
    return trainNumber;
}

const char* Ticket::getBookingUser() const {
    return bookingUser;
}