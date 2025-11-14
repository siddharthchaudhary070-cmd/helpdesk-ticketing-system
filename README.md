IT Helpdesk Ticketing System (C++)
A simple desktop-based console application that simulates an IT Helpdesk Ticketing System using C++.
This project allows users to create, view, update, and close support tickets, while also saving all data using persistent file storage.

This beginner-friendly project is perfect for anyone learning programming fundamentals or wanting to understand how real-world ticketing/workflow systems work.

Features ---->

#Create New Ticket
->Enter customer name, issue, and category
->Automatically generates unique Ticket ID
->Ticket stored with Open status

#View All Tickets
->Displays ID, customer name, issue, category, and status
->Clean and readable output format

#Update Ticket
->Modify name, issue, category, or status
->Leave a field empty to keep old value

#Close Ticket
->Marks any ticket as Closed
->Prevents closing an already closed ticket

#Persistent Storage
->Saves all tickets to tickets.txt
->Automatically loads them on program start

#Input Validation
->Prevents crashes from invalid inputs (letters, symbols, etc.)
->Ensures clean and predictable user experience

#Clean Console Interface
->Menu-driven
->Screen clears after each action for clarity

##Technologies Used
-->C++ (Standard Library)
-->Structs for modeling tickets
-->Vectors for dynamic storage
-->File I/O (fstream) for persistence
-->Functions for modularity
-->Input validation using numeric_limits

##Project Structure
helpdesk-ticketing-system/
│
├── main.cpp        # Full application source code
├── tickets.txt     # Auto-generated file storing saved tickets
└── README.md       # Project documentation

##What You Learn From This Project

1.How to build a real console application
2.Using structs, vectors, loops, and conditionals
3.How to write modular C++ code with functions
4.Implementing file handling for saving/loading data
5.Handling invalid user input safely
6.Designing menu-based systems

##How to Run
1.Compile
g++ main.cpp -o main

2.Run
./main

##Future Improvements

Delete Ticket
Search Ticket by ID or Name
Filter tickets by Category or Status
Export tickets to CSV
Add a login system (Admin/User)
Convert to GUI using Qt or FLTK
Database integration (SQLite / MySQL)

Author

Siddharth Chaudhary
A beginner-friendly project designed to strengthen foundational C++ skills and simulate real-world ticketing workflows.