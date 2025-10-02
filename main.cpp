#include <bits/stdc++.h>
#include "User.h"
#include "Train.h"
#include "Ticket.h"
#include "utils.h"
using namespace std;

pair<string,string> loadAdminCredentials() {
    ifstream file("config.txt");
    string line, user, pass;
    while (getline(file, line)) {
        if (line.find("adminUsername=") == 0) {
            user = line.substr(14);
        }
        if (line.find("adminPassword=") == 0) {
            pass = line.substr(14);
        }
    }
    return {user, pass};
}

void adminMenu() {
    int choice;
    do {
        clearScreen();
        cout << "\n========== Admin Menu ==========\n";
        cout << "1. Add New Train\n";
        cout << "2. View All Bookings\n";
        cout << "3. View All Trains\n";
        cout << "0. Logout\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Train newTrain;
                newTrain.addTrain();
                break;
            }
            case 2: {
                ifstream ticketFile("tickets.dat", ios::binary);
                if (!ticketFile) {
                    cout << "\nNo bookings found.\n";
                } else {
                    Ticket tempTicket;
                    while(ticketFile.read(reinterpret_cast<char*>(&tempTicket), sizeof(Ticket))) {
                        tempTicket.displayTicket();
                    }
                }
                break;
            }
            case 3: {
                Train t;
                t.viewAllTrains();
                break;
            }
            case 0:
                return;
            default:
                cout << "\nInvalid choice.\n";
        }
        pauseScreen();
    } while (choice != 0);
}

void userMenu(const string& username) {
    int choice;
    do {
        clearScreen();
        cout << "\n========== User Menu ==========\n";
        cout << "1. Search Trains & Book Ticket\n";
        cout << "2. View My Bookings\n";
        cout << "3. Cancel Ticket\n";
        cout << "4. View All Trains\n";
        cout << "0. Logout\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                char src[50], dest[50];
                cout << "Enter Source: ";
                cin >> src;
                cout << "Enter Destination: ";
                cin >> dest;
                Train t;
                t.searchTrain(src, dest);

                char bookChoice;
                cout << "\nBook a ticket? (y/n): ";
                cin >> bookChoice;
                if (bookChoice == 'y' || bookChoice == 'Y') {
                    char trnNo[20];
                    cout << "Enter Train Number: ";
                    cin >> trnNo;
                    Ticket newTicket;
                    newTicket.createTicket(username, trnNo);
                }
                break;
            }
            case 2: {
                ifstream ticketFile("tickets.dat", ios::binary);
                bool found = false;
                Ticket tempTicket;
                while(ticketFile.read(reinterpret_cast<char*>(&tempTicket), sizeof(Ticket))) {
                    if (strcmp(tempTicket.getBookingUser(), username.c_str()) == 0) {
                        tempTicket.displayTicket();
                        found = true;
                    }
                }
                if (!found) cout << "\nNo bookings found.\n";
                break;
            }
            case 3: {
                Ticket t;
                t.cancelTicket();
                break;
            }
            case 4: {
                Train t;
                t.viewAllTrains();
                break;
            }
            case 0:
                return;
            default:
                cout << "\nInvalid choice.\n";
        }
        pauseScreen();
    } while (choice != 0);
}

int main() {
    int choice;
    User currentUser;
    auto [adminUser, adminPass] = loadAdminCredentials();

    do {
        clearScreen();
        cout << "\n==== Railway Ticket Reservation System ====\n";
        cout << "1. Login\n";
        cout << "2. Register\n";
        cout << "3. Admin Login\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
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
                string user, pass;
                cout << "Enter Admin Username: ";
                cin >> user;
                cout << "Enter Admin Password: ";
                cin >> pass;
                if (user == adminUser && pass == adminPass) {
                    adminMenu();
                } else {
                    cout << "\nInvalid admin credentials.\n";
                }
                break;
            }
            case 0:
                cout << "\nThank you for using the system!\n";
                return 0;
            default:
                cout << "\nInvalid choice.\n";
        }
        pauseScreen();
    } while (choice != 0);

    return 0;
}
