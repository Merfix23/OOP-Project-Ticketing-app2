#include <iostream>
#include <string>
#include <string.h>
#include <cstring>

using namespace std;

class Row {
    int size = 0;
    string* seats;

    //Constructor with one parameter
    Row(int size) : size(size) {
        seats = new string[size];
        for (int i = 0; i < size; i++) {
            seats[i] = i + 1;
            cout << endl << "seat:" << seats[1];
        }
    }

    //function to set the seat availability
    void setSeat(int index, const string& status) {
        if (index >= 0 && index < size) {
            seats[index] = status;
        }
        else {
            throw exception("Invalid seat index");
        }
    }

    //function to display the seat status
    void displaySeats() {
        for (int i = 0; i < size; ++i) {
            cout << "Seat " << i + 1 << ": " << seats[i] << endl;
        }
    }

    //Destructor
    ~Row() {
        delete[] seats;
    }
};

class Location {
private:
    char* name;
    int maxSeats = 0;
    Row* rows;
    int rowCount;

public:
    //Default constructor

    Location() : maxSeats(0) {}
    //Constructor with parameters

    Location(char* name, int maxSeats, int rowCount, int seatsPerRow) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->maxSeats += seatsPerRow;
        this->rows = new Row[rowCount];
        for (int i = 0; i < seatsPerRow; i++) {
            rows[i] = Row(seatsPerRow);
        }
    }

    //destructor 
    ~Location() {
        delete[] rows;
    }


};


class Ticket {
private:
    char* eventName;
    double price;
    int ticketNumber;



public:
    // Default constructor
    Ticket(char* eventName, int price, int ticketNumber) {
        this->eventName = new char[strlen(eventName) + 1];
        strcpy(this->eventName, eventName);
        this->price = price;
        this->ticketNumber = ticketNumber;
    }



};


int main()
{

}