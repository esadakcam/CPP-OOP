/*Author: Mehmed Esad AKÇAM
150190725
*/

#include "Dwarves.h"
#include <iostream>
// since there are not any different attributes in Dwarves faction, body part of constructor is empty
Dwarves::Dwarves(string name , int numberOfUnits, int attackPoint, int healthPoint, int regen):Faction(
        name, numberOfUnits, attackPoint, healthPoint, regen){}; 
                                                                

void Dwarves::PerformAttack(){
    if(!firstEnemy->IsAlive() && secondEnemy->IsAlive()){ //only second enemy alive
        secondEnemy->ReceiveAttack(numOfUnits, attackPoint, "Dwarves");
    }else if(firstEnemy->IsAlive() && !secondEnemy->IsAlive()){ //only first enemy alive
        firstEnemy->ReceiveAttack(numOfUnits,attackPoint,"Dwarves"); 
    }else if(firstEnemy->IsAlive() && secondEnemy->IsAlive()) { //both enemies are alive
        //integer division done in order not to crop additinal units
        firstEnemy->ReceiveAttack(numOfUnits -(numOfUnits*5/10), attackPoint, "Dwarves"); 
        secondEnemy->ReceiveAttack(numOfUnits - (numOfUnits*5/10), attackPoint, "Dwarves");
    }
};

void Dwarves::ReceiveAttack(int unit, double attackedPoint, string attacking){
    int damage = unit*attackedPoint;//integer division done in order not to crop additinal units
    numOfUnits-= damage/healthPoint;
};

int Dwarves::PurchaseWeapons(int amount){
    attackPoint += amount; //increase attack point with purchased amount
    return amount * 10;  //pay 10 each weapon
}


int Dwarves::PurchaseArmors(int amount){
	healthPoint += amount * 2; //increase health point with double of purchased amount
	return amount * 3;   //pay 3 each armor
}

void Dwarves::Print() const{
    cout<<"\"Taste the power of our axes!\""<<endl; //war cry
    Faction::Print(); //Faction print method
}

