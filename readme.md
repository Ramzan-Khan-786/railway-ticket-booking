# Railway Ticket Reservation System 🚂

A **console-based application** written in **C++** that simulates a simple railway ticket booking system.  
This project demonstrates **Object-Oriented Programming (OOP) principles**, **file handling for data persistence**, and a **modular code structure**.

---

## ✨ Features

The system is divided into two primary modules with distinct functionalities:

### 👤 User Features
- **User Registration & Login:** Securely create a new user account and log in.
- **Search Trains:** Search for available trains between a specified source and destination.
- **Book Tickets:** Book a ticket on an available train, generating a unique **PNR number**.
- **View My Bookings:** View all tickets booked by the logged-in user.
- **Cancel Ticket:** Cancel a previously booked ticket using its PNR number.

### 👨‍💼 Admin Features
- **Admin Login:** Access a separate admin panel with secure credentials.
- **Add New Trains:** Add new train routes to the system (train number, name, source, destination, and total seats).
- **View All Bookings:** Monitor and view all tickets booked across all users.

---

## ⚙️ Getting Started

Follow these instructions to get the project running on your local machine.

### 📋 Prerequisites
You need a **C++ compiler** installed on your system. Common choices:
- **g++** (part of MinGW on Windows or pre-installed on Linux/macOS)
- A terminal (Command Prompt, PowerShell, or Linux shell)
- **Git** (optional, for cloning the repository)

### 🔧 Installation & Setup

1. **Clone the Repository**
   ```sh
   git clone https://github.com/your-username/railway-system.git
   ```

2. **Navigate to the Project Directory**
   ```sh
   cd railway-system
   ```

3. **Compile the Source Code**
   Use the `g++` compiler to compile the `.cpp` files into an executable:
   ```sh
   g++ main.cpp User.cpp Train.cpp Ticket.cpp -o railway_system.exe
   ```

4. **Run the Application**
   ```sh
   railway_system.exe
   ```

---

## 🚀 Usage Guide & Example Walkthrough

Here’s a complete example of using the application:

### 🔹 Step 1: Admin Adds a Train
1. Run the app: `railway_system.exe`
2. Select `3. Admin Login`
3. Enter credentials:
   - Username: `admin`
   - Password: `admin123`
4. Select `1. Add New Train`
5. Enter train details:
   - Train Number: `12345`
   - Train Name: `Capital Express`
   - Source: `Delhi`
   - Destination: `Mumbai`
   - Total Seats: `100`
6. Train successfully added ✅

---

### 🔹 Step 2: User Registers & Books a Ticket
1. From main menu, select `2. Register`
2. Enter credentials:
   - Username: `aisha`
   - Password: `mypassword`
3. Log in with option `1. Login`
4. From User Menu, select `1. Search Trains & Book Ticket`
5. Enter route:
   - Source: `Delhi`
   - Destination: `Mumbai`
6. System shows available trains. Confirm booking.
7. Enter train number `12345` and passenger details.
8. ✅ Booking confirmed with a unique **PNR number**

---

### 🔹 Step 3: User Views & Cancels a Ticket
1. From User Menu, select `2. View My Bookings`
2. See booked ticket(s).
3. Select `3. Cancel Ticket`
4. Enter your PNR number.
5. ✅ Ticket successfully cancelled.
6. Train seat availability restored.

---

## 📂 Project Structure
```
railway-system/
├── main.cpp        # Main program logic
├── User.cpp        # User management (registration, login, bookings)
├── Train.cpp       # Train management (add/search trains)
├── Ticket.cpp      # Ticket booking and cancellation
├── utils.h         # Utility functions
├── User.h          # User class declaration
├── Train.h         # Train class declaration
├── Ticket.h        # Ticket class declaration
├── README.md       # Documentation
```

---

## 🏆 Conclusion

This **Railway Ticket Reservation System** demonstrates:
- Practical use of **OOP concepts** in C++
- **File handling** for persistent storage
- A clean and modular code structure
- Realistic simulation of user and admin workflows

🚂 All core functionalities have been successfully implemented and tested!
