/*Author: Mehmed Esad AKÇAM
150190725
*/


#include "Orcs.h"
#include <iostream>
Orcs::Orcs(string name , int numberOfUnits, int attackPoint, int healthPoint, int regen):Faction(
        name, numberOfUnits, attackPoint, healthPoint, regen){};

void Orcs::PerformAttack(){
/*
If one enemy left attack with all units
If both enemies are alive attack elves with 70% and attack dwarwes 30%



*/
    if(!firstEnemy->IsAlive() && secondEnemy->IsAlive()){ 
        secondEnemy->ReceiveAttack(numOfUnits, attackPoint, "Orcs");
    }else if(firstEnemy->IsAlive() && !secondEnemy->IsAlive()){
        firstEnemy->ReceiveAttack(numOfUnits,attackPoint,"Orcs");
    }else if(firstEnemy->IsAlive() && secondEnemy->IsAlive()) {
        if(firstEnemy->getFaction() == "Elves"){
             //In order to get rid of cropping units integer division an subtraction operations are used.
            firstEnemy->ReceiveAttack((numOfUnits - (3*numOfUnits/10)), attackPoint,"Orcs");
            secondEnemy->ReceiveAttack((numOfUnits - (7*numOfUnits/10)), attackPoint,"Orcs");
        }else{
            firstEnemy->ReceiveAttack((numOfUnits - (7*numOfUnits/10)), attackPoint,"Orcs");
            secondEnemy->ReceiveAttack(numOfUnits - (3*numOfUnits/10), attackPoint,"Orcs");
        }
    }
};

void Orcs::ReceiveAttack(int unit, double attackedPoint, string attacking){
    int damage;
    if(attacking == "Elves"){//If elves attacking, reduce incoming attackPoint to 75%
        damage = attackedPoint*0.75*unit;
    }else{
        damage = attackedPoint*0.8*unit;//If dwarves attacking, reduce incoming attackPoint to 80%
    }
    numOfUnits-=damage/healthPoint;
}

int Orcs::PurchaseWeapons(int amount){
    attackPoint += amount*2;//increase attackPoint double of purchased weapon amount
    return amount * 20; //pay 20 for each purchased weapon 
}

int Orcs::PurchaseArmors(int amount){
	healthPoint += amount * 3;//increase healthPoint triple of purchased armor amount
	return amount;   //pay 1 for each purchased weapon 
}

void Orcs::Print() const{
    cout<<"\"Stop running, you'll only die tired!\""<<endl;
    Faction::Print();
}