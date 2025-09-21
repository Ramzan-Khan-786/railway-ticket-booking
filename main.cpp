#include <bits/stdc++.h>
#include "User.h"
#include "Train.h"
#include "Ticket.h"
#include "utils.h"
using namespace std;
void adminMenu() {
    int choice;
    do {
        clearScreen();
        cout << "\n\t\t\t=============================================";
        cout << "\n\t\t\t\t        Admin Menu";
        cout << "\n\t\t\t=============================================";
        cout << "\n\t\t\t1. Add New Train";
        cout << "\n\t\t\t2. View All Bookings";
        cout << "\n\t\t\t0. Logout";
        cout << "\n\n\t\t\tEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Train newTrain;
                newTrain.addTrain();
                break;
            }
            case 2: {
                clearScreen();
                cout << "\n\t\t\tViewing All Booked Tickets:\n";
                 cout << "\t\t\t---------------------------------------------\n";
                ifstream ticketFile("tickets.dat", ios::binary);
                if (!ticketFile) {
                    cout << "\n\t\t\tNo bookings found." << endl;
                } else {
                    Ticket tempTicket;
                    while(ticketFile.read(reinterpret_cast<char*>(&tempTicket), sizeof(Ticket))) {
                        tempTicket.displayTicket();
                    }
                }
                ticketFile.close();
                break;
            }
            case 0:
                return;
            default:
                cout << "\n\t\t\tInvalid choice. Please try again." << endl;
        }
        cout << "\n\t\t\tPress Enter to continue...";
        cin.ignore();
        cin.get();
    } while (choice != 0);
}

void userMenu(const string& username) {
    int choice;
    do {
        clearScreen();
        cout << "\n\t\t\t=============================================";
        cout << "\n\t\t\t\t        User Menu";
        cout << "\n\t\t\t=============================================";
        cout << "\n\t\t\t1. Search Trains & Book Ticket";
        cout << "\n\t\t\t2. View My Bookings";
        cout << "\n\t\t\t3. Cancel Ticket";
        cout << "\n\t\t\t0. Logout";
        cout << "\n\n\t\t\tEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                char src[50], dest[50];
                cout << "\n\t\t\tEnter Source: ";
                cin >> src;
                cout << "\t\t\tEnter Destination: ";
                cin >> dest;
                Train t;
                t.searchTrain(src, dest);
                
                char bookChoice;
                cout << "\n\t\t\tDo you want to book a ticket? (y/n): ";
                cin >> bookChoice;
                if (bookChoice == 'y' || bookChoice == 'Y') {
                    char trnNo[20];
                    cout << "\n\t\t\tEnter the Train Number to book: ";
                    cin >> trnNo;
                    Ticket newTicket;
                    newTicket.createTicket(username, trnNo);
                }
                break;
            }
            case 2: {
                 clearScreen();
                 cout << "\n\t\t\tYour Booked Tickets:\n";
                 cout << "\t\t\t---------------------------------------------\n";
                 ifstream ticketFile("tickets.dat", ios::binary);
                 bool found = false;
                 Ticket tempTicket;
                 while(ticketFile.read(reinterpret_cast<char*>(&tempTicket), sizeof(Ticket))) {
                     if (strcmp(tempTicket.getBookingUser(), username.c_str()) == 0) {
                         tempTicket.displayTicket();
                         found = true;
                     }
                 }
                 if (!found) {
                     cout << "\n\t\t\tYou have no bookings." << endl;
                 }
                 ticketFile.close();
                 break;
            }
            case 3: {
                Ticket t;
                t.cancelTicket();
                break;
            }
            case 0:
                return;
            default:
                cout << "\n\t\t\tInvalid choice. Please try again." << endl;
        }
        cout << "\n\t\t\tPress Enter to continue...";
        cin.ignore();
        cin.get();
    } while (choice != 0);
}


int main() {
    int choice;
    User currentUser;

    do {
        clearScreen();
        cout << "\n\t\t\t=============================================";
        cout << "\n\t\t\t      Railway Ticket Reservation System";
        cout << "\n\t\t\t=============================================";
        cout << "\n\t\t\t1. Login";
        cout << "\n\t\t\t2. Register";
        cout << "\n\t\t\t3. Admin Login";
        cout << "\n\t\t\t0. Exit";
        cout << "\n\n\t\t\tEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (currentUser.loginUser()) {
                    userMenu(currentUser.getUsername());
                }
                break;
            case 2:
                currentUser.registerUser();
                break;
            case 3: {
                 string adminUser, adminPass;
                 cout << "\n\t\t\tEnter Admin Username: ";
                 cin >> adminUser;
                 cout << "\t\t\tEnter Admin Password: ";
                 cin >> adminPass;
                 if (adminUser == "admin" && adminPass == "admin123") {
                     adminMenu();
                 } else {
                     cout << "\n\t\t\tInvalid admin credentials." << endl;
                 }
                 break;
            }
            case 0:
                cout << "\n\t\t\tThank you for using the system!" << endl;
                return 0;
            default:
                cout << "\n\t\t\tInvalid choice. Please try again." << endl;
        }
         cout << "\n\t\t\tPress Enter to continue...";
         cin.ignore();
         cin.get();
    } while (choice != 0);

    return 0;
}