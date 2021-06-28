/*Author: Mehmed Esad AKÇAM
150190725
*/


#pragma once
#include "Faction.h"

class Elves : public Faction{
    public:
    Elves():Faction(){}; //Default Constructor 
    Elves(string name , int numberOfUnits, int attackPoint, int healthPoint, int regen); //Constructor with parameters
    
    //expected functions
    void PerformAttack();
    void ReceiveAttack(int unit, double attackPoint, string attacking);
    int PurchaseArmors(int);
    int PurchaseWeapons(int);
    void Print() const;

    //Returns faction type
    string getFaction(){return "Elves";};
};