/*Author: Mehmed Esad AKÇAM
150190725
*/


#pragma once
#include <string>
using namespace std;
class Faction{  
    string name;

    protected: //in order to access thise attributes from child classes
    Faction *firstEnemy;
    Faction *secondEnemy;
    int numOfUnits;
    int attackPoint;
    int healthPoint;
    int unitRegen;
    int totalHealth;
    bool isAlive;
    
    public:
    Faction(); //Default constructor
    Faction(string , int , int , int , int ); //Constructor with parameters
    bool IsAlive() const{return isAlive;}; //getter

    //virtual functions that will be implemented on a faction pointer thanks to polymorphism
    virtual void AssignEnemies(Faction* ,Faction*  );
    virtual void PerformAttack() = 0; //pure virtual function
    virtual void ReceiveAttack(int unit, double attackPoint, string attacking) = 0;
    virtual int PurchaseArmors(int) = 0;
    virtual int PurchaseWeapons(int) = 0;
    virtual void Print() const;
    virtual string getFaction() = 0; //this function returns type of faction: elves, dwarves or orcs
    
    void EndTurn();
};