#include <iostream>
#include <cstring>

using namespace std;

class Row {
public:
    int size = 0;
    string* seats;
    int rowNumber = 0;

    // Default constructor
    Row() : size(0), seats(nullptr), rowNumber(0) {}

    // Constructor with one parameter
    Row(int size, int rowNumber) : size(size), rowNumber(rowNumber) {
        seats = new string[size];
        for (int i = 0; i < size; i++) {
            seats[i] = "Available";
            cout << "Seat:" << seats[i] << endl;
        }
    }

    // Function to set the seat availability
    void setSeat(int index, const string& status) {
        if (index >= 0 && index < size) {
            seats[index] = status;
        }
        else {
            throw exception("Invalid seat index");
        }
    }

    // Function to get available seat count
    int getAvailableSeatCount() const {
        int count = 0;
        for (int i = 0; i < size; ++i) {
            if (seats[i] == "Available") {
                count++;
            }
        }
        return count;
    }

    // Function to display the seat status
    void displaySeats() const {
        for (int i = 0; i < size; ++i) {
            cout << "Seat " << i + 1 << ": " << seats[i] << endl;
        }
    }

    // Destructor
    ~Row() {
        delete[] seats;
    }

    // Setters
    void setRowNumber(int rownr) {
        this->rowNumber = rownr;
    }

    void setSize(int size) {
        if (size <= 0) {
            throw exception("Incorrect size value");
        }
        this->size = size;
    }

    // Getters
    int getSize() const {
        return this->size;
    }

    int getRowNumber() const {
        return this->rowNumber;
    }
};

class Location {
public:
    char* name;
    int maxSeats = 0;
    Row* rows;
    int rowCount;

    // Default constructor
    Location() : maxSeats(0) {}

    // Constructor with parameters
    Location(const char* name, int maxSeats, int rowCount, int seatsPerRow) : maxSeats(maxSeats), rowCount(rowCount) {
        this->name = new char[strlen(name) + 1];
        strcpy_s(this->name, strlen(name) + 1, name);
        this->rows = new Row[rowCount];
        for (int i = 0; i < rowCount; i++) {
            rows[i] = Row(seatsPerRow, i + 1);  // Pass the row number
        }
    }

    // Function to get the total count of available seats
    int getAvailableSeatCount() const {
        int totalCount = 0;
        for (int i = 0; i < rowCount; ++i) {
            totalCount += rows[i].getAvailableSeatCount();
        }
        return totalCount;
    }

    // Function to check seat availability
    bool isSeatAvailable(int row, int seat) const {
        if (row >= 1 && row <= rowCount && seat >= 1 && seat <= rows[row - 1].getSize()) {
            const string& seatStatus = rows[row - 1].seats[seat - 1];
            return seatStatus == "Available";
        }
        else {
            cout << "Invalid row or seat number." << endl;
            return false;
        }
    }

    // Function to buy a ticket for a specific seat
    void buyTicket(int row, int seat) {
        if (row >= 1 && row <= rowCount && seat >= 1 && seat <= rows[row - 1].getSize()) {
            string& seatStatus = rows[row - 1].seats[seat - 1];
            if (seatStatus == "Available") {
                seatStatus = "Occupied";
                cout << "Ticket bought for Row " << row << ", Seat " << seat << "." << endl;
            }
            else {
                cout << "Seat is already occupied." << endl;
            }
        }
        else {
            cout << "Invalid row or seat number." << endl;
        }
    }

    // Destructor 
    ~Location() {
        delete[] name;
    }
};

class Ticket {
private:
    char* eventName;
    double price;
    int ticketNumber;
    static int nextTicketID;  // Static variable to track the next ticket ID

public:
    // Default constructor
    Ticket(const char* eventName, double price) : price(price) {
        // Allocate memory for eventName
        this->eventName = new char[strlen(eventName) + 1];

        // Copy eventName using strcpy_s
        strcpy_s(this->eventName, strlen(eventName) + 1, eventName);

        // Assign the next available ticket ID and increment it
        this->ticketNumber = nextTicketID++;
    }

    // Destructor
    ~Ticket() {
        // Deallocate memory for eventName
        delete[] eventName;
    }

    // Function to get the ticket ID
    int getTicketID() const {
        return ticketNumber;
    }

    // Function to display ticket information
    void displayTicket() const {
        cout << "Ticket ID: " << getTicketID() << endl;
        cout << "Event: " << eventName << endl;
        cout << "Price: $" << price << endl;
    }
};

// Initialize the static variable
int Ticket::nextTicketID = 1;

int main() {
    // Example usage
    Location myLocation("My Cinema", 100, 5, 10);

    // Display initial seating chart
    for (int i = 0; i < myLocation.rowCount; ++i) {
        cout << "Row " << myLocation.rows[i].getRowNumber() << ":" << endl;
        myLocation.rows[i].displaySeats();
        cout << endl;  // Add an extra line for better readability
    }

    // Buy a ticket for Row 3, Seat 4
    myLocation.buyTicket(3, 4);

    // Display updated seating chart
    cout << "Updated Seating Chart:" << endl;
    for (int i = 0; i < myLocation.rowCount; ++i) {
        cout << "Row " << myLocation.rows[i].getRowNumber() << ":" << endl;
        myLocation.rows[i].displaySeats();
        cout << endl;  // Add an extra line for better readability
    }

    // Display total count of available seats
    cout << "Total Available Seats: " << myLocation.getAvailableSeatCount() << endl;

    // Check if seat in Row 3, Seat 4 is available
    if (myLocation.isSeatAvailable(3, 4)) {
        cout << "Seat is available." << endl;
    }
    else {
        cout << "Seat is not available." << endl;
    }

    // Example usage of Ticket class
    Ticket myTicket("Movie Night", 15.99);

    // Display ticket information
    myTicket.displayTicket();

    return 0;
}