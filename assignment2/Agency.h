//Mehmed Esad AKÇAM
//150190725

#pragma once
#include "Mission.h"

class Agency{
    //private attributes
    string name;
    int cash;
    int ticketPrice;
    MissionNode *completedMissions;
    MissionNode *nextMissions;
public:
    Agency(); //default constructor
    ~Agency(); //destructor
    Agency(string,int,int); //constructor with parameters
    void addMission(const Mission&); 
    void executeNextMission();
    int getTicketPrice() const; //Ticket price getter
    void setTicketPrice(int); //Ticket prcie setter
    string getName() const{return name;}
    int getCash() const{return cash;}
    void setName(string inName){name = inName;}
    void setCash(int inCash){cash = inCash;}
    friend ostream& operator<< (ostream&, const Agency&); //<< operator overload. it is a friend function of Agency. So it can reach all members of Agency class. 

};