/*Author: Mehmed Esad AKÇAM
150190725
*/


#include "Merchant.h"
#include <iostream>
Merchant::Merchant(){ //default constrcutor
    startingArmorPoint = 0;
    startingWeaponPoint = 0;
    weaponPointLeft = 0;
    armorPointLeft = 0;
    firstFaction = NULL;
    secondFaction = NULL;
    thirdFaction = NULL;
    revenue = 0;
}

Merchant::Merchant(int wp, int ap){ //constructor with parameters
    startingArmorPoint = ap;
    startingWeaponPoint = wp;
    weaponPointLeft = wp;
    armorPointLeft = ap;
    firstFaction = NULL;
    secondFaction = NULL;
    thirdFaction = NULL;
    revenue = 0;
}

void Merchant::AssignFactions(Faction* first, Faction* second, Faction* third){ //assigns the factions
    firstFaction = first;
    secondFaction = second;
    thirdFaction = third;
}

bool Merchant::SellWeapons(const string& faction, int amount){
    if(amount > weaponPointLeft){ //sells given amount weapon
        cout << "You try to sell more weapons than you have in possession."<<endl; //trying to sell more than possess
        return false;
    }
    
    Faction *fptr;
    //choosing the correct faction pointer
    if(firstFaction->getFaction() == faction){
        fptr = firstFaction;
    }else if(secondFaction->getFaction() == faction){
        fptr = secondFaction;
    }else{
        fptr = thirdFaction;
    }

    if(!fptr->IsAlive()){ //if the faction is not alive
        cout<< "The faction you want to sell weapons is dead!" <<endl;
        return false;
    }

    revenue += fptr->PurchaseWeapons(amount);
    weaponPointLeft-=amount;
    cout<<"Weapons sold!"<<endl;
    return true;
}


bool Merchant::SellArmors(const string& faction, int amount){ //same procedure with the sellWeapons function
    if(amount > armorPointLeft){
        cout << "You try to sell more armors than you have in possession."<<endl;
        return false;
    }
    
    Faction *fptr;
    if(firstFaction->getFaction() == faction){
        fptr = firstFaction;
    }else if(secondFaction->getFaction() == faction){
        fptr = secondFaction;
    }else{
        fptr = thirdFaction;
    }

    if(!fptr->IsAlive()){
        cout<< "The faction you want to sell armors is dead!" <<endl;
        return false;
    }

    revenue += fptr->PurchaseArmors(amount);
    armorPointLeft-=amount;
    cout<<"Armors sold!"<<endl;
    return true;
}

void Merchant::EndTurn(){ //resets weaponPoint and armorPoint
    weaponPointLeft = startingWeaponPoint;
	armorPointLeft = startingArmorPoint;
}
//getters
int Merchant::GetRevenue() const{return revenue;};
int Merchant::GetWeaponPoints() const{return weaponPointLeft;};
int Merchant::GetArmorPoints() const{return armorPointLeft;};