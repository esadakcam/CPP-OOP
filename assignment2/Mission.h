//Mehmed Esad AKÇAM
//150190725
#pragma once

using namespace std;
#include <string>
#include "Person.h"
#include <cstdlib>

class Mission{
    string name;
    int missionNumber;
    int cost;
    int faultProbability;
    bool completed;
    static int numMissions;
    PassengerNode *passList;
    CrewNode *crewList;
    int numPassenger;
    int numCrew;
public:
    //constructors
    Mission(string,int,int);
    Mission();

    ~Mission();//destructor

    //getters
    PassengerNode *getPasslist();
    CrewNode *getCrewList();
    int getMissionNumber() const;
    int getCost() const;
    string getName() const;
    int getFaultProbability() const {return faultProbability;}
    bool getCompleted() const {return completed;}
    int getNumPassanger() const {return numPassenger;}
    int getNumCrew() const { return numCrew;}

    //operator overload
    void operator+=( Passenger*);
    void operator+=( Astronaut*);
    void operator=(const Mission&);

    bool executeMission();
    int calculateProfit(int);
    
    void setName(string);//setter
    void setCost(int inCost){cost = inCost;}
    void setFaultProbability(int inPro) {faultProbability = inPro;}
};

class MissionNode{ //mission linked list node
    Mission data;
    MissionNode *next;
public:
    MissionNode(const Mission& in) {data = in; next = NULL;}; 
    MissionNode *getNext(){return next;};
    void setNext(MissionNode* in){ next = in;};
    Mission& getData(){return data;};
};
