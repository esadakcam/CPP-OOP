//////////////////////////////////
/* Mehmed Esad Akçam            */
/* 150190725                    */
//////////////////////////////////

#pragma once
#include <iostream>
using namespace std;

class Land{
    //private data
    string name;
    string holding; 
    public:

        Land(); // default constructor
        Land(string , string ); // constructor with parameter
        Land(const Land& inLand); // copy constructor
        //getters
        string getHolding() const {return holding;};
        string getName() const {return name;};
        //linked list next
        Land *next;
};

class Character{
    //private data
    string name;
    int manpower;
    int gold;
    int numOfLands;
    Land *lands;

    public:
        Character(); //default constructor
        Character(const Character&); //copy constructor
        //constructors
        Character(string name,string land, int manpower, int gold , int numOfLands);
        Character(string name, int manpower , int gold , int numOfLands);
        Character(string name);

        ~Character();//destructor
        
        bool addLand(string,string); //add land to character
        bool removeLand(string); //delete land form character
        bool doesItHaveLand(string) const; //returns true if character has specific land
        void getTaxes(); //collect taxes
        //getters
        string getName() const;
        int getManpower() const;
        Land *getLand(string);
        int getNumOfLands() const;
        int getGold() const;
        Land *getHead();
        //setters
        void setGold(int);
        void setHead(Land*);
        void setManpower(int);

        void printLands() const;//prints all lands of character
        void rebellion(); //deletes head of lands

};

class CharacterList{
    //private data
    Character *characters;
    int size; 
    //friend functions
    friend void listCharacters(CharacterList&);
    friend void listLands(CharacterList&);
    public:
        CharacterList(); //constroctur
        ~CharacterList(); //destructor
        Character &getPlayer(string); //returns reference to wanted player
        Character &getLandOwner(string); //returns reference to owner of specific land
        int getSize() const; //returns size of characters
        bool addCharacter(Character&); //adds character to array
        bool delCharacter(Character&); //deletes character to array
        bool validSelection(Character&,string); //checks if attacking selection valid or not
        
};


