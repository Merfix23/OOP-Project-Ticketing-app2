#include <iostream>
#include <string>
#include <string.h>
#include <cstring>

using namespace std;

class Location {
private:
    char* name;
    int maxSeats = 0;
    int rows = 0;
  
public:
    //Default constructor

    Location() :  maxSeats(0), rows(0){}
    //Constructor with parameters

    Location(char* name, int maxSeats, int rows) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->maxSeats = maxSeats;
        this->rows = rows;
    }

};


class Ticket {
private:
    char* eventName;
    double price;
    int ticketNumber;

    

public:
    // Default constructor
    Ticket(char* eventName, int price, int ticketNumber){
        this->eventName = new char[strlen(eventName) + 1];
        strcpy(this->eventName, eventName);
        this->price = price;
        this->ticketNumber = ticketNumber;
    }

   
  
};


int main()
{
    
}