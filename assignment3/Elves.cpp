/*Author: Mehmed Esad AKÇAM
150190725
*/


#include "Elves.h"
#include <iostream>

// since there are not any different attributes in Dwarves faction, body part of constructor is empty
Elves::Elves(string name , int numberOfUnits, int attackPoint, int healthPoint, int regen):Faction(
        name, numberOfUnits, attackPoint, healthPoint, regen){};

void Elves::PerformAttack(){
/* Attacks dwarves with 1.5 attackPoints
    If only one enemey left attack with all units
    If both enemies are alive 0.4 of units to dwarves 0.6 of units to elves 
    Integer division is processed not to crop additional units.
*/
    if(!firstEnemy->IsAlive() && secondEnemy->IsAlive()){ 
        if(secondEnemy->getFaction() == "Dwarves"){
            secondEnemy->ReceiveAttack(numOfUnits, attackPoint*1.5, "Elves");
        }else{
           secondEnemy->ReceiveAttack(numOfUnits, attackPoint, "Elves"); 
        }
        secondEnemy->ReceiveAttack(numOfUnits, attackPoint, "Elves");
    }else if(firstEnemy->IsAlive() && !secondEnemy->IsAlive()){
        if(firstEnemy->getFaction() == "Dwarves"){
            firstEnemy->ReceiveAttack(numOfUnits,attackPoint*1.5,"Elves");
        }else{
            firstEnemy->ReceiveAttack(numOfUnits,attackPoint,"Elves");
        }
        firstEnemy->ReceiveAttack(numOfUnits,attackPoint,"Elves");
    }else if(firstEnemy->IsAlive() && secondEnemy->IsAlive()) {
        if(firstEnemy->getFaction() == "Dwarves"){
            firstEnemy->ReceiveAttack(numOfUnits - (6*numOfUnits/10), attackPoint*1.5,"Elves");
            secondEnemy->ReceiveAttack(numOfUnits - (4*numOfUnits/10), attackPoint,"Elves");
        }else{
            firstEnemy->ReceiveAttack(numOfUnits - (4*numOfUnits/10), attackPoint,"Elves");
            secondEnemy->ReceiveAttack(numOfUnits - (6*numOfUnits/10), attackPoint*1.5,"Elves");
        }
    }
};

void Elves::ReceiveAttack(int unit, double attackedPoint, string attacking){
    //integer division done in order not to crop additinal units
    int damage;
    if(attacking == "Orcs"){
        damage = attackedPoint*125*unit/100; //If orcs attacking damage is increased to 125%
    }else{
        damage = attackedPoint*75*unit/100; //If dwarves attacking damage is decreased to 75%
    }
    numOfUnits-= damage/healthPoint;
}

int Elves::PurchaseWeapons(int amount){
    attackPoint += 2*amount; //increase attack point with double of purchased amount
    return amount * 15; //pay 15 each weapon
}


int Elves::PurchaseArmors(int amount){
	healthPoint += amount * 4;//increase health point with quadriplet of purchased amount
	return amount * 5;      //pay 5 each armor
}

void Elves::Print() const{
    cout<<"\"You cannot reach our elegance.\""<<endl; //war cry
    Faction::Print(); //Faction print func.
}

