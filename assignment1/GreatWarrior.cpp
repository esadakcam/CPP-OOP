//////////////////////////////////
/* Mehmed Esad Akçam            */
/* 150190725                    */
//////////////////////////////////
#include "GreatWarrior.h"

Land::Land(){
    name = "";
    holding = "";
    next = NULL;
}

Land::Land(string name, string holding){
    this->name = name;
    this->holding = holding;
    next = NULL;
}

Land::Land(const Land& inland){
    this->holding = inland.holding;
    this->name = inland.name;
    Land *temp = new Land(inland.next->getName(),inland.next->getHolding());
    this->next = temp;
}

Character::Character(){
    name = "";
    manpower = 0;
    gold = 0;
    numOfLands = 0;
    lands = NULL;
}

Character::Character(const Character& in){
    name = in.name;
    manpower = in.manpower;
    gold = in.gold;
    numOfLands = in.numOfLands;
    lands = NULL;
    Land *traverse = in.lands;
    Land *traverse2 = lands;
    while(traverse){
        Land *toadd = new Land(traverse->getName(),traverse->getHolding());
        
        if(lands == NULL){
            lands = toadd;
            traverse2=lands;
            traverse = traverse->next;
        }else{
            traverse2->next = toadd;
            traverse = traverse->next;
            traverse2 = traverse2->next;
        } 
    }
}

Character::Character(string name, string land, int manpower, int gold , int numOfLands){
    this->name = name;
    this->manpower = manpower;
    this->gold = gold;
    this->numOfLands = numOfLands;
    Land *temp = new Land(land,"village");
    lands = temp;
}

Character::Character(string name,  int manpower, int gold, int numOfLands){
    this->name = name;
    this->manpower = manpower;
    this->gold = gold;
    this->numOfLands = 0;
    lands = NULL;
    
}

Character::Character(string name){
    this->name = name;
    this->lands = NULL;
    this->numOfLands = 0;
}

Character::~Character(){
    if(numOfLands == 0){
        return;
    }
    if(lands->next == NULL){
        lands = NULL;
        delete lands;
        return;
    }
    Land *traverse = lands;
    Land *temp;
    while(traverse){
        temp = traverse->next;
        delete traverse;
        traverse = temp;
    }
}
Land* Character::getHead(){
    return lands;
}
int Character::getGold() const{
    return gold;
}
int Character::getManpower() const{
    return manpower;
}

int Character::getNumOfLands() const{
    return numOfLands;
}

void Character::setGold(int gold){
    this->gold = gold;
}

void Character::setHead(Land * toset){
    lands = toset;
}
void Character::setManpower(int manpower){
    this->manpower = manpower;
}
void Character::printLands() const{
    if(lands == NULL){
        return;
    }
    Land *traverse = lands;
    while(traverse){
        cout<<traverse->getName()<<" "<<traverse->getHolding()<<" owned by "<<name<<endl;
        traverse = traverse->next;
    }
}

void Character::rebellion(){

    if(lands->next == NULL){
        lands = NULL;
        numOfLands = 0;
        return;
    }
        Land *temp= lands;
        lands = lands -> next;
        delete temp;
        numOfLands--;
}

void Character::getTaxes(){
    if(lands == NULL){
        return;
    }
    Land *traverse = lands;
    while(traverse){
        if(traverse->getHolding() == "village")
            gold+=5;
        else if(traverse->getHolding() == "castle")
            gold+=7;
        else if(traverse->getHolding() == "city")
            gold += 10;
        traverse = traverse->next;
    }
}

bool Character::doesItHaveLand(string wanted) const{
    Land *traverse = lands;
    while(traverse){
        if(traverse->getName() == wanted){
            return true;
        }
        traverse = traverse->next;
    }
    return false;
}

Land *Character::getLand(string wanted){
    Land *traverse = lands;
    Land *ret = new Land();
    while(traverse){
        if(traverse->getName() == wanted){
            ret = traverse;
            break;
        }
        traverse = traverse->next;
    }
    return ret;
}

bool Character::addLand(string land, string holding){
    Land *newNode = new Land(land,holding);
    numOfLands++;
    if(lands == NULL){
        lands = newNode;
        return true;
    }else{
        Land *traverse = lands;
        while(traverse){
            if(traverse->next == NULL){
                traverse->next = newNode;
                return true;
            }
            traverse = traverse->next;
            
        }
    }
    return false;
}

bool Character::removeLand(string land){
    if(lands == NULL){
        return false;
    }else{
        numOfLands -= 1;
        Land *traverse = lands;
        
        if(lands->getName() == land){
            lands=lands->next;
            delete traverse;
            return true;
        }else{
            Land *previous = lands;
            while(traverse){
                if(traverse->getName() == land){
                    previous->next = traverse->next;
                    delete traverse;
                    return true;
                }
                previous = traverse;
                traverse = traverse->next;
            }
        }
    }
    return false;
}

string Character::getName() const{
    return name;
}

CharacterList::CharacterList(){
    characters = NULL;
    size = 0;
}

CharacterList::~CharacterList(){
    delete [] characters;
}

bool CharacterList::addCharacter(Character &toadd){
    Character *temp = new Character[size+1];
    bool flag = false;
    for(int i = 0; i < size; i++){       
        Character *old = new Character(characters[i]);
        temp[i] = *old;  
    }
    temp[size] = toadd;
    size++;
    delete [] characters;
    characters = temp;
    return true;
}


bool CharacterList::delCharacter(Character& remove){
    Character *temp = new Character[size-1];
    bool flag = false;
    for(int i = 0; i < size; i++){
        if(characters[i].getName() == remove.getName()){
            flag = true;
            continue;
        }
        
        Character *old = new Character(characters[i]);
        if(flag){
            temp[i-1] = *old;

        }else{
            temp[i] = *old;
        }
    }
    size--;
    delete [] characters;
    characters = temp;
    return true;
}

Character& CharacterList::getPlayer(string wanted){
    int counter = 0;
    for(int i = 0; i < size; i++){
        if(characters[i].getName() == wanted){
            break; 
        }
        counter++;
    }
    return characters[counter];
}

int CharacterList::getSize() const{
    return size;
}

Character& CharacterList::getLandOwner(string wanted){
    int counter = 0;
    for(int i = 0; i < size; i++){
        if(characters[i].doesItHaveLand(wanted)){
            break;
        }  
        counter++;
    }
    return characters[counter];
    
}

bool CharacterList::validSelection(Character& in,string select){
    Land *traverse;
    for(int i = 0; i < size; i++){
        traverse = characters[i].getHead();
        while(traverse){
            if(traverse->getName() == select){
                if(characters[i].getName() == in.getName()){
                    cout<<"You can't attack your own " << traverse->getHolding() <<"."<<endl;
                    return false;
                }else{
                    return true;
                }
            }
            traverse = traverse->next;
        }
    }
    cout<<"Please enter correct land to attack."<<endl;
    return false;
}