/*Author: Mehmed Esad AKÇAM
150190725
*/


#include "Faction.h"
class Merchant{
    Faction *firstFaction;
    Faction *secondFaction;
    Faction *thirdFaction;
    int startingWeaponPoint;
    int startingArmorPoint;
    int revenue;
    int weaponPointLeft;
    int armorPointLeft;

    public:
    //constructors
    Merchant();
    Merchant(int,int);
    //expected functions
    void AssignFactions(Faction *,Faction *,Faction *);
    bool SellWeapons(const string&, int);
    bool SellArmors(const string&, int);
	void EndTurn();
    int GetRevenue() const;
    int GetWeaponPoints() const;
    int GetArmorPoints() const;
};