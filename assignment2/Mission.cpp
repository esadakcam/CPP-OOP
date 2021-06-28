//Mehmed Esad AKÇAM
//150190725

#include "Mission.h"

Mission::Mission(){
    name = "";
    numPassenger = 0;
    cost = 0;
    numCrew = 0;
    faultProbability = 0;
    completed = false;
    passList = NULL;
    crewList = NULL;
    missionNumber = numMissions;
}

Mission::Mission(string missionName, int cost, int faultProbability){
    if(!((missionName[0]>= 65 && missionName[0]<= 90) && (missionName[1]>= 65 && missionName[1]<= 90) && 
    (missionName[3]>= 48 && missionName[3]<= 57) && (missionName[4]>= 48 && missionName[4]<= 57) &&
    missionName[2] == '-')){
        cerr<<"Given name does not satisfy the mission naming convention. Please set a new name!"<<endl;

        name = "AA-00";
    }else{
        name = missionName;
    }
    this->cost = cost;
    this->faultProbability = faultProbability;
    completed = false;
    numMissions++;
    missionNumber = numMissions;
    passList = NULL;
    crewList = NULL;
    numPassenger = 0;
    numCrew = 0;
}





int Mission::calculateProfit(int price){
    int profit = 0;
    if(completed){
        profit += price*numPassenger;
    }
    return profit - cost;
}

int Mission::getMissionNumber() const{
    return missionNumber;
}

string Mission::getName() const{
    return name;
}

int Mission::getCost() const{
    return cost;
}

PassengerNode* Mission::getPasslist(){
    return passList;
}

CrewNode* Mission::getCrewList(){
    return crewList;
}

void Mission::setName(string missionName){
    if(!((missionName[0]>= 65 && missionName[0]<= 90) && (missionName[1]>= 65 && missionName[1]<= 90) && 
    (missionName[3]>= 48 && missionName[3]<= 57) && (missionName[4]>= 48 && missionName[4]<= 57) &&
    missionName[2] == '-')){
        cerr<<"Given name does not satisfy the mission naming convention. Please set a new name!"<<endl;

        name = "AA-00";
    }else{
        name = missionName;
    }
}

bool Mission::executeMission(){
    int probability = rand() % 100;
    if(faultProbability == 100 || faultProbability > probability){
        completed = false;
        cout<<"MISSION " << name <<" FAILED!"<<endl;
        return false;
    }
    cout<<"MISSION " << name <<" SUCCESSFUL!"<<endl;
    completed = true;
    CrewNode *traverse = crewList;
    while(traverse){
        traverse->getData().completeMission();
        cout << "Astronaut " << traverse->getData().getName() << " " << traverse->getData().getSurname()<< " successfully completed "<<
        traverse->getData().getNumMissions() <<" missions."<<endl;
        traverse = traverse->getNext();
    }
    return true;
}
void Mission::operator+=( Passenger *inPass){
    
    if(!inPass->getTicket()){
        cout<<"Passenger "<<inPass->getName() << " " << inPass->getSurname()<<" does not have a valid ticket!"<<endl;
        return;
    }
    PassengerNode *toadd = new PassengerNode(*inPass);
    if(passList == NULL){
        passList = toadd;
    }else{
        PassengerNode *traverse = passList;
        while(traverse){
            if(traverse->getNext() == NULL){
                traverse->setNext(toadd);
                break;
            }
            traverse = traverse->getNext();
        }
    }
    numPassenger++;
}

void Mission::operator+=( Astronaut* inAst){
    CrewNode *toadd = new CrewNode(*inAst);
    if(crewList == NULL){
        crewList = toadd;
    }else{
        CrewNode *traverse = crewList;
        while(traverse){
            if(traverse->getNext() == NULL){
                traverse->setNext(toadd);
                break;
            }
            traverse = traverse->getNext();
        }
    }
    numCrew++;
}

void Mission::operator=(const Mission& in){
    this->name = in.name;
    this->cost = in.cost;
    this->missionNumber = in.missionNumber;
    this->numMissions = in.numMissions;
    this->completed = in.completed;
    this->numCrew = 0;
    this->faultProbability = in.faultProbability;
    this->numPassenger = 0; 
    this->passList = NULL;
    this->crewList = NULL;
    PassengerNode *oldPass = in.passList;
    CrewNode *oldCrew = in.crewList;
    while(oldCrew){
            (*this)+= &(oldCrew->getData());
            oldCrew = oldCrew->getNext();
    }
    while(oldPass){
            (*this)+= &(oldPass->getData());
            oldPass = oldPass->getNext();
    }  
}

Mission::~Mission() {
    if(crewList == NULL && passList == NULL ){
        return;
    }
    if(crewList != NULL){
        CrewNode *crew = crewList;
        while(crew){
            CrewNode *temp = crew->getNext();
            delete crew;
            crew = temp;
        }
    }
    if(passList != NULL){
        PassengerNode *pass = passList;
        while(pass){
            PassengerNode *temp = pass->getNext();
            delete pass;
            pass = temp;
        }
    }

}