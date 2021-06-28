/*Author: Mehmed Esad AKÇAM
150190725
*/


#include "Faction.h"
using namespace std;
#include <iostream>
Faction::Faction(string name , int numberOfUnits, int attackPoint, int healthPoint, int regen){//constructor with parameters
    this->name = name;
    this->numOfUnits = numberOfUnits;
    this->attackPoint = attackPoint;
    this->healthPoint = healthPoint;
    this->unitRegen = regen;
    totalHealth = numOfUnits * healthPoint;
    isAlive = true;
    firstEnemy = NULL;
    secondEnemy = NULL;
}

Faction::Faction(){//default constructor
    this->name = "";
    this->numOfUnits = 0;
    this->attackPoint = 0;
    this->healthPoint = 0;
    this->unitRegen = 0;
    totalHealth = 0;
    isAlive = true;
    firstEnemy = NULL;
    secondEnemy = NULL;
}
void Faction::AssignEnemies(Faction* first,Faction* second){ //assigns a factions enemies directly to given pointers
    firstEnemy = first;
    secondEnemy = second;
}

void Faction::Print() const{ //base print method. other factions will print this and their war cry
    cout<<"Faction Name:         "<<name<<endl;
    cout<<"Status:               ";

    if(isAlive){
        cout<<"Alive"<<endl;
    }else{
        cout<<"Defeated"<<endl;
    }
    cout<<"Number of Units:      "<<numOfUnits<<endl;
    cout<<"Attack Point:         "<<attackPoint<<endl;
    cout<<"Health Point:         "<<healthPoint<<endl;
    cout<<"Unit Regen Number:    "<<unitRegen<<endl;
    cout<<"Total Faction Health: "<<totalHealth<<endl;
}

void Faction::EndTurn(){//Updates faction according to unit regen. if there are no unit a faction isAlive to false

    if (numOfUnits < 0){
        numOfUnits = 0;
    }
    if(numOfUnits == 0){
        isAlive = false;
        totalHealth = 0;
    }else{
        numOfUnits += unitRegen;
        totalHealth = numOfUnits * healthPoint;
    }
}   