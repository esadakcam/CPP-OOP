//Mehmed Esad AKÇAM
//150190725
#include "Person.h"
using namespace std;

Person::Person(string name, string surname){
    this->name = name;
    this->surname = surname;
}

Person::Person(){
    name = "";
    surname = "";
}

string Person::getName()const{return name;}
string Person::getSurname()const{return surname;}

Passenger::Passenger() : Person("",""){
    cash = 0;
    ticket = false;
}


Passenger::Passenger(string name, string surname):Person(name,surname){
    cash = 0;
    ticket = false; 
}

Passenger::Passenger(string name, string surname,int cash) : Person(name,surname){
    if(cash < 0){
        cerr<< "Passenger cash can't be negative. It is set to 0."<<endl;
        this->cash = 0;
    }else{
        this->cash = cash;
    }
    this->ticket = false;
}

bool Passenger::buyTicket(int price){
    if(price > cash){
        return false;
    }
    else{
        cash-=price;
        ticket = true;
        return true;
    }
}

bool Passenger::getTicket() const {
    return ticket;
}
Astronaut::Astronaut(string name, string surname, int numMissions = 0) : Person(name,surname){
    
    this->numMissions = numMissions;
    if(numMissions < 0){
        cerr << "Number of missions that astronaut completed can't be negative. It is set to 0." ;
        cerr << endl;
        this->numMissions = 0;

    }
}

Astronaut::Astronaut(string name, string surname) : Person(name,surname){
    
    this->numMissions = 0;
}
Astronaut::Astronaut() : Person("",""){
    this->numMissions = 0;
}

void Astronaut::completeMission(){numMissions++;};

PassengerNode::PassengerNode(const Passenger& Passenger){
    data = Passenger;
    next = NULL;

}

CrewNode::CrewNode(const Astronaut& astro){
    data = astro;
    next = NULL;
}