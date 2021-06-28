//////////////////////////////////
/* Mehmed Esad Akçam            */
/* 150190725                    */
//////////////////////////////////

#include <iostream>
#include <fstream>
#include "GreatWarrior.h"
#include "GreatWarrior.cpp"

void listCharacters(CharacterList&);
void listLands(CharacterList&);
void readData(string, CharacterList&);
void printGameMenu();
bool endOfTurn(Character&, int);

int main() {
    cout << "Welcome to the Great Warriors. Create your character and attack other lands to be a great warrior.\n" << endl;

    CharacterList charList;             // list object to store the characters

    string fileName = "characters.txt"; // read characters.txt file
    readData(fileName, charList);

    /* creating player's character */
    string name, land, general;
    cout << "Enter your name: ";
    cin >> name;

    cout << "Enter name of your capital: ";
    cin >> land;

    cout << "Enter name of your general: ";
    cin >> general;

    Character const *playerG = new Character(general); //general
    Character *character = new Character(name,land,3,20,1); //player's caharacter
    bool playerAdded = charList.addCharacter(*character); //adding player's character to charlist
    delete character; //after adding to charlist deleting player character

    int choice = 0, round = 0;
    while (choice != 6) {
        printGameMenu();
        bool end = false;
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "You have rested in your palace." << endl;
            cout << "You've talked with your general " << playerG->getName() << "." << endl;

            round++;
            end = endOfTurn(charList.getPlayer(name),round);
            break;
        }
        case 2: {
            listLands(charList);
            
            cout << "Enter name of the land to attack." << endl;

            string land;
            cin >> land;
            if(charList.validSelection(charList.getPlayer(name),land)){ //check wheter valid or not
                Character& attacked =  charList.getLandOwner(land); //get attacked player
                if(charList.getPlayer(name).getManpower() >= attacked.getManpower()){ //if player has more manpower s/he wins
                    charList.getPlayer(name).setManpower(charList.getPlayer(name).getManpower() - attacked.getManpower()); //decrease manpower
                    attacked.setManpower(0); //set attacked player's manpower to 0 
                    Land* move = attacked.getLand(land);
                    string hold = move->getHolding();
                    bool removed = attacked.removeLand(land);
                    charList.getPlayer(name).addLand(land,hold); //add new land to player
                    cout << "You've won the battle and conquered " << land << "." << endl;
                    if(attacked.getNumOfLands() == 0){ //if attacked has no land remove from charlist
                        charList.delCharacter(attacked);
                    }

                }else{
                    cout << "You've lost the battle and " << charList.getPlayer(name).getManpower() << " manpower." << endl;
                    charList.getPlayer(name).setManpower(0); //set player's manpower to 0

                }
                round++;
                end = endOfTurn(charList.getPlayer(name),round);
            }
            break;
        }
        case 3:
            cout << "How much manpower do you need? (1 manpower=5 gold)" << endl;

            int order;
            cin >> order;
            if(charList.getPlayer(name).getGold() >= order * 5){ //if player has enough money h/she can buy manpower
                charList.getPlayer(name).setManpower(charList.getPlayer(name).getManpower() + order);
                cout << "Order successful. You have " << charList.getPlayer(name).getManpower()<< " manpower." << endl;
                charList.getPlayer(name).setGold(charList.getPlayer(name).getGold()-(order)*5);
            }else{
                cout << "You do not have enough money." << endl;
            }          
            break;
        case 4:
            listCharacters(charList);
            break;
        case 5:
            listLands(charList);

            break;
        case 6:
            return 0;

        default:
            cout << "You entered an invalid value. Try again." << endl;
        }

        if(end){
            break;

        }
        if(charList.getSize() == 1){//if there is only player left in, game game over.
            cout << charList.getPlayer(name).getName() << " is the only great warrior now." << endl;
            break;
        }
    }
    delete playerG;
}

void readData(string fileName, CharacterList& charList) {

    fstream dataFile(fileName.c_str());

    if (dataFile.is_open()) {

        string word;
        while (dataFile >> word) {

            string name, title;
            int money, manpower, numOfLands;
            name = word;
            dataFile >> manpower;
            dataFile >> money;
            dataFile >> numOfLands;
            Character *temp = new Character(name,manpower,money,numOfLands); //create a character with reading data
            string landName, holding;
            for (int i = 0; i < numOfLands; i++) { 
                dataFile >> landName;
                dataFile >> holding;

                temp->addLand(landName,holding);//add its lands
            }
            bool added = charList.addCharacter(*temp); //add created character to list
        }

        dataFile.close();
    }
    else cout << "Unable to open the file" << endl;
    return;
}

void printGameMenu() {
    cout << endl;
    cout << "1. Stay in your palace" << endl;
    cout << "2. Attack to a land" << endl;
    cout << "3. Buy manpower" << endl;
    cout << "4. List characters" << endl;
    cout << "5. List lands" << endl;
    cout << "6. Exit" << endl;
    cout << endl;
}

void listCharacters(CharacterList& charList) {
    cout << endl;
    for(int i = 0; i < charList.size; i++){
        cout<<charList.characters[i].getName()<<endl; //list all of the characters in the list
    }
}

void listLands(CharacterList& charList) {
    cout << endl;
    for(int i = 0; i < charList.size ;i++){
        charList.characters[i].printLands(); //list all the lands
    }
    cout << endl;
}

bool endOfTurn(Character& player, int round) { //return a bool value that indicates if the game is over or not.
    bool flag = false;
    player.getTaxes(); //collect taxes
    if(player.getNumOfLands() == 0){ //check game is over or not
        cout << "You are no longer a great warrior. You survived " << round << " turns." << endl;
        cout << endl;
        cout << "GAME OVER." << endl;
        flag = true ;
    }else{
        if(player.getManpower() == 0){
            if(player.getNumOfLands() == 0){
                cout << "You are no longer a great warrior. You survived " << round << " turns." << endl;
                cout << endl;
                cout << "GAME OVER." << endl;
                flag = true ;
                return true;
            }
            player.rebellion(); //check if rebellion occurs
            cout << "You lost one of your lands to rebellions since you don't have enough army." << endl;
            cout << "Turn " << round << ": " << " " << player.getName() << " has " << player.getNumOfLands()
            << " land(s), " <<player.getManpower() << " manpower and " << player.getGold() << " golds." << endl;
        }else{
            if(player.getGold() >= player.getManpower()){ //check if player has enough money to feed his/her soliders
                player.setGold(player.getGold()-player.getManpower());
            }else{
                cout <<player.getManpower() - player.getGold()<< " soldiers run away from your army because you don't have enough gold to feed them." << endl;
                player.setManpower(player.getGold());
                player.setGold(0);

            }

            cout << "Turn " << round << ": " << " " << player.getName() << " has " << player.getNumOfLands()
            << " land(s), " <<player.getManpower() << " manpower and " << player.getGold() << " golds." << endl; //prints game information
        }

        
    }
    return flag;

}
