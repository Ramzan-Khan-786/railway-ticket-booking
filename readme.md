# Railway Ticket Reservation System 🚂

A console-based application written in C++ that simulates a simple railway ticket booking system. This project demonstrates core Object-Oriented Programming (OOP) principles, file handling for data persistence, and a modular code structure.

---

## ## Features ✨

The system is divided into two main modules with distinct functionalities:

### ### User Features
* **User Registration & Login:** Securely create a new user account and log in.
* **Search Trains:** Search for available trains between a specified source and destination.
* **Book Tickets:** Book a ticket on an available train, which generates a unique PNR number.
* **View My Bookings:** View a list of all tickets booked by the logged-in user.
* **Cancel Ticket:** Cancel a previously booked ticket using its PNR number.

### ### Admin Features
* **Admin Login:** Access a separate admin panel with a unique password.
* **Add New Trains:** Add new train routes to the system, including train number, name, source, destination, and total seats.
* **View All Bookings:** Monitor and view a complete list of all tickets booked across all users.

---

## ## Getting Started ⚙️

Follow these instructions to get a copy of the project up and running on your local machine.

### ### Prerequisites

You need a C++ compiler installed on your system. The most common one is **g++**, which is part of the MinGW toolchain on Windows.
* A C++ Compiler (like g++)
* A command-line terminal (like Command Prompt or PowerShell)
* Git (for cloning the repository)

### ### Installation & Setup

1.  **Clone the Repository**
    Open your terminal and clone the repository to your local machine. (Replace the URL with your actual repository URL if you have one).
    ```sh
    git clone [https://github.com/your-username/railway-system.git](https://github.com/your-username/railway-system.git)
    ```

2.  **Navigate to the Project Directory**
    ```sh
    cd railway-system
    ```

3.  **Compile the Source Code**
    Use the `g++` compiler to compile all the `.cpp` files into a single executable file.
    ```sh
    g++ main.cpp User.cpp Train.cpp Ticket.cpp -o railway_system.exe
    ```

4.  **Run the Application**
    Once compiled successfully, run the executable file to start the program.
    ```sh
    railway_system.exe
    ```

---

## ## Usage Guide & Example Walkthrough 🚀

Here’s a step-by-step example of how to use the application from start to finish.

### ### Step 1: Admin - Add a Train

First, the admin needs to add a train so users have something to book.

1.  Run the application: `railway_system.exe`
2.  From the main menu, select option `3. Admin Login`.
3.  Enter the credentials:
    * Username: `admin`
    * Password: `admin123`
4.  In the Admin Menu, select `1. Add New Train`.
5.  Enter the train details:
    * Train Number: `12345`
    * Train Name: `Capital Express`
    * Source: `Delhi`
    * Destination: `Mumbai`
    * Total Seats: `100`
6.  The train is now added. You can select `0. Logout` to return to the main menu.

### ### Step 2: User - Register and Book a Ticket

Now, a new user will register, search for the train, and book a ticket.

1.  From the main menu, select option `2. Register`.
2.  Enter new user credentials:
    * Username: `aisha`
    * Password: `mypassword`
3.  After successful registration, select `1. Login` from the main menu and log in as `aisha`.
4.  You are now in the User Menu. Select `1. Search Trains & Book Ticket`.
5.  Enter the route you want to search for:
    * Source: `Delhi`
    * Destination: `Mumbai`
6.  The system will display the "Capital Express" with 100 available seats. When prompted to book, enter `y`.
7.  Enter the train number `12345`.
8.  Enter your passenger details.
9.  ✅ **Success!** The system will confirm your booking and provide a **unique PNR number**. Make sure to note it down.

### ### Step 3: User - View and Cancel a Ticket

Finally, the user checks her booking and then cancels it.

1.  In the User Menu, select `2. View My Bookings`. You will see the ticket you just booked.
2.  To cancel, select `3. Cancel Ticket`.
3.  Enter the PNR number you noted down earlier.
4.  ✅ **Success!** The system will confirm the cancellation.
5.  If you check `2. View My Bookings` again, it will be empty. If you search for the `Delhi` to `Mumbai` train, the available seats will be back to `100`.

You have now successfully tested the core functionalities of the Railway Reservation System!