//Mehmed Esad AKÇAM
//150190725

#include "Agency.h"

Agency::Agency(){
    name = "";
    ticketPrice = 0;
    completedMissions = NULL;
    nextMissions = NULL;
}

Agency::Agency(string name,int cash, int ticketPrice){
    this->name = name;
    this->cash = cash;
    
    if(ticketPrice < 0){
        cout<<"Ticket price can't be negative. It is set to 0."<<endl;
        this->ticketPrice = 0;
    }else{
        this->ticketPrice = ticketPrice;
    }
    completedMissions = NULL;
    nextMissions = NULL;
}

ostream& operator<<(ostream &print, const Agency &info){
    print << "Agency name: " << info.name << ", Total cash: " << info.cash << ", Ticket Price: "<< info.ticketPrice<<endl<<"Next Missions:"<<endl;
    
    if(info.nextMissions == NULL){
        print<<"No missions available."<<endl;

    }else{
        MissionNode *misson = info.nextMissions;

        while(misson){
            print << "Mission number: " << misson->getData().getMissionNumber() << " Mission name: " << misson->getData().getName() << " Cost: "
            << misson->getData().getCost()<<endl;
            
            misson = misson->getNext();
        }
    }

    print<<"Completed Missions:"<<endl;

    if(info.completedMissions == NULL){

        print<<"No missions completed before."<<endl;

    }else{

        MissionNode *misson = info.completedMissions;
        while(misson){
            print<<"Mission number: "<< misson->getData().getMissionNumber() <<" Mission name: " << misson->getData().getName() << " Cost: "
            << misson->getData().getCost()<<endl;
            misson = misson->getNext();
        }
    }
    return print;
}

void Agency::executeNextMission(){
    if(nextMissions == NULL){
        cout<<"No available mission to execute!"<<endl;
        return;
    }
    bool done = nextMissions->getData().executeMission();
    cash+= nextMissions->getData().calculateProfit(ticketPrice);
    if(!done){
        cout<<"Agency reschedules the mission."<<endl;
        Mission failed; 
        failed = nextMissions->getData();
        this->addMission(failed);
        MissionNode *head = nextMissions->getNext();
        delete nextMissions;
        nextMissions = head;
    }else{
        MissionNode *completed = nextMissions;
        nextMissions = nextMissions->getNext();
        if(completedMissions == NULL){
            completedMissions = completed;
            completed->setNext(NULL); 
        }else{
            completed->setNext(completedMissions);
            completedMissions = completed;
        }
    }
}

void Agency::addMission(const Mission& inMiss){
    MissionNode *newMission = new MissionNode(inMiss);
    if(nextMissions == NULL){
        nextMissions = newMission;
    }else{
        MissionNode *temp = nextMissions;
        while(temp->getNext()!= NULL){
            temp = temp->getNext();
        }
        temp->setNext(newMission);

    }
}


int Agency::getTicketPrice() const{
    return ticketPrice;
}

void Agency::setTicketPrice(int in){
    ticketPrice = in;
}

Agency::~Agency() {

    if(completedMissions == NULL && nextMissions == NULL){
        return;
    }

    if(nextMissions != NULL){
        MissionNode *mission = nextMissions;

        while(mission){
            MissionNode *next = mission->getNext();
            delete mission;
            mission = next;
        }
    }

    if(completedMissions != NULL){
        MissionNode *compMission = completedMissions;

        while(compMission){
            MissionNode *next = compMission->getNext();
            delete compMission;
            compMission = next;

        }
    }
}