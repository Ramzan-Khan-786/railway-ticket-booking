#ifndef TICKET_H
#define TICKET_H

#include <string>

class Ticket {
private:
    long long pnrNumber;
    char trainNumber[20];
    char passengerName[50];
    int passengerAge;
    char passengerGender;
    char bookingUser[50];

public:
    void createTicket(const std::string& user, const std::string& trnNo);
    void displayTicket();
    void cancelTicket();
    long long getPNR() const;
    const char* getTrainNumber() const;
    const char* getBookingUser() const;
};

#endif