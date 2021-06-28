/*Author: Mehmed Esad AKÇAM
150190725
*/


#pragma once
#include "Faction.h"

class Dwarves : public Faction{ //Public derivation
    public:
    Dwarves():Faction(){}; //Default constructor
    Dwarves(string name , int numberOfUnits, int attackPoint, int healthPoint, int regen);//Constroctur with parameters
    
    //Expected functions
    void PerformAttack();
    void ReceiveAttack(int unit, double attackPoint, string attacking);
    int PurchaseArmors(int);
    int PurchaseWeapons(int);
    void Print() const;

    //Returns faction type
    string getFaction(){return "Dwarves";};
};