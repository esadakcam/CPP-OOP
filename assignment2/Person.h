//Mehmed Esad AKÇAM
//150190725

#pragma once
#include <iostream>
using namespace std;
#include <string>


class Person{
    string name;
    string surname;
public:
    //constructors
    Person(string,string);
    Person(); 

    //getters  
    string getName() const;
    string getSurname() const;
    
    //setters
    void setName(string inName){name = inName;}
    void setSurname(string inSurname){surname = inSurname;}

};

class Passenger : public Person{ //public derivation from Person class
    int cash;
    bool ticket;
public:
    //constructors
    Passenger(string,string,int);
    Passenger(string,string);
    Passenger();

    bool buyTicket(int);
    bool getTicket() const;

    //getters
    int getCash() const{return cash;}
    bool getticket() const{return ticket;}

    //setters
    void setCash(int inCash){cash = inCash;}
    void setTicket(bool inTicket){ticket = inTicket;}
};

class Astronaut : public Person{ //public derivation from Person class
    int numMissions;
public:
    //constructors
    Astronaut(string,string,int);
    Astronaut(string,string);
    Astronaut();

    void completeMission();

    int getNumMissions() const {return numMissions;}
    void setNumMissions(int inNum){numMissions = inNum;}
};

class PassengerNode{ //passanger linked list node
    Passenger data;
    PassengerNode *next;
public:
    PassengerNode(const Passenger&);
    PassengerNode *getNext(){return next;};
    void setNext(PassengerNode* in){ next = in;};
    Passenger& getData(){return data;};
    
};

class CrewNode{ //crew linked list node
    Astronaut data;
    CrewNode *next;
public:
    CrewNode(const Astronaut&);
    CrewNode *getNext(){return next;};
    void setNext(CrewNode* in){ next = in;};
    Astronaut& getData(){return data;};
};