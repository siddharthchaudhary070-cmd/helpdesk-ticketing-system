#include <iostream>
#include <vector>
#include <limits>
#include <fstream>
using namespace std;

struct Ticket {
    int id;
    string customerName;
    string issue;
    string category;
    string status;
};

vector<Ticket> tickets;  // list to store tickets
int nextTicketId = 1;    // unique id generator

void addTicket() {
    Ticket t;

    t.id = nextTicketId++;
    
    cout << "Enter customer name: ";
    cin.ignore();
    getline(cin, t.customerName);

    cout << "Enter issue description: ";
    getline(cin, t.issue);

    cout << "Enter category (Hardware / Software / Network / Other): ";
    getline(cin, t.category);

    t.status = "Open";

    tickets.push_back(t);

    cout << "\nTicket created successfully!" << endl;
    cout << "Ticket ID: " << t.id << endl;
}

void viewTickets() {
    if (tickets.empty()) {
        cout << "\nNo tickets found.\n";
        return;
    }

    cout << "\n----- All Tickets -----\n";

    for (const Ticket& t : tickets) {
        cout << "Ticket ID: " << t.id << endl;
        cout << "Customer Name: " << t.customerName << endl;
        cout << "Issue: " << t.issue << endl;
        cout << "Category: " << t.category << endl;
        cout << "Status: " << t.status << endl;
        cout << "---------------------------" << endl;
    }
}

void updateTicket() {
    if (tickets.empty()) {
        cout << "\nNo tickets available to update.\n";
        return;
    }

    int id;
    cout << "\nEnter the Ticket ID to update: ";
    cin >> id;
    cin.ignore();

    // Find the ticket
    bool found = false;
    for (Ticket &t : tickets) {
        if (t.id == id) {
            found = true;

            cout << "\nUpdating Ticket ID: " << t.id << endl;

            cout << "Enter new customer name (leave empty to keep unchanged): ";
            string newName;
            getline(cin, newName);
            if (!newName.empty()) t.customerName = newName;

            cout << "Enter new issue description (leave empty to keep unchanged): ";
            string newIssue;
            getline(cin, newIssue);
            if (!newIssue.empty()) t.issue = newIssue;

            cout << "Enter new category (leave empty to keep unchanged): ";
            string newCategory;
            getline(cin, newCategory);
            if (!newCategory.empty()) t.category = newCategory;

            cout << "Enter new status (Open / Closed) (leave empty to keep unchanged): ";
            string newStatus;
            getline(cin, newStatus);
            if (!newStatus.empty()) t.status = newStatus;

            cout << "\nTicket updated successfully!\n";

            break;
        }
    }

    if (!found) {
        cout << "\nNo ticket found with ID " << id << ".\n";
    }
}

void closeTicket() {
    if (tickets.empty()) {
        cout << "\nNo tickets available to close.\n";
        return;
    }

    int id;
    cout << "\nEnter the Ticket ID to close: ";
    cin >> id;
    cin.ignore();

    bool found = false;

    for (Ticket &t : tickets) {
        if (t.id == id) {
            found = true;

            if (t.status == "Closed") {
                cout << "\nThis ticket is already closed.\n";
                return;
            }

            t.status = "Closed";
            cout << "\nTicket ID " << id << " has been closed successfully.\n";
            break;
        }
    }

    if (!found) {
        cout << "\nNo ticket found with ID " << id << ".\n";
    }
}

void pauseAndClear() {
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();  // waits for user to press Enter

    // Clear screen (Windows-specific)
    system("cls");
}

int getSafeIntegerInput() {
    int value;

    while (true) {
        if (cin >> value) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        } else {
            cout << "Invalid input. Please enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

void saveTicketsToFile() {
    ofstream file("tickets.txt");

    for (const Ticket& t : tickets) {
        file << t.id << endl;
        file << t.customerName << endl;
        file << t.issue << endl;
        file << t.category << endl;
        file << t.status << endl;
        file << "---" << endl; // separator
    }

    file.close();
}

void loadTicketsFromFile() {
    ifstream file("tickets.txt");
    if (!file) return; // No file exists yet

    tickets.clear();
    nextTicketId = 1;

    while (true) {
        Ticket t;
        string separator;

        // Read ID
        if (!(file >> t.id)) break;
        file.ignore();

        // Read other fields
        getline(file, t.customerName);
        getline(file, t.issue);
        getline(file, t.category);
        getline(file, t.status);

        // Read separator line (---)
        getline(file, separator);

        tickets.push_back(t);

        if (t.id >= nextTicketId)
            nextTicketId = t.id + 1;
    }

    file.close();
}


int main() {

    loadTicketsFromFile();

    while (true) {
        cout << "Welcome to the IT Helpdesk Ticketing System!" << endl;

        cout << "----------------------------------------" << endl;
        cout << "1. Add New Ticket" << endl;
        cout << "2. View Tickets" << endl;
        cout << "3. Update Ticket" << endl;
        cout << "4. Close Ticket" << endl;
        cout << "5. Exit" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Enter your choice: ";

        int choice;
        choice = getSafeIntegerInput();

        if (choice == 1) {
        addTicket();
        pauseAndClear();
        }
        else if (choice == 2) {
        viewTickets();
        pauseAndClear();
        }
        else if (choice == 3) {
        updateTicket();
        pauseAndClear();
        }
        else if (choice == 4) {
        closeTicket();
        pauseAndClear();
        }
        else if (choice == 5) {
            saveTicketsToFile();
            cout << "Exiting the system..." << endl;
            break;  // <-- This exits the loop
        }
        else {
            cout << "Invalid choice. Please choose a number between 1 and 5." << endl;
        }

        cout << endl; // print empty line for spacing 
    }

    return 0;
}