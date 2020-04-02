#include <iostream>
#include <string>
#include "creatures.h"
enemy::enemy(int lvl, int hp, int mp, int str, int dex) : creature(lvl, hp, mp, str, dex){
    this->lvl = lvl;
    this->hp = hp;
    this->mp = mp;
    this->str = str;
    this->dex = dex;
    if (lvl <= 5) name = "goblin";
    else if (lvl <= 10) name = "golem";
    else name = "slave of eternity";
}
enemy::~enemy(){
    std::cout << "enemy fell\n";
}
void enemy::status() {
    std::cout << "named: " << name << std::endl;
    std::cout << "level: " << lvl << std::endl;
    std::cout << "health point: " << hp << std::endl;
    std::cout << "mana point: " << mp << std::endl;
    std::cout << "strength: " << str << std::endl;
    std::cout << "dexterity: " << dex << std::endl;                
}
int enemy::attack() {
    return str*0.5;
}
int enemy::block(int dmg) {
    return dmg-(dex*0.5);
}
void enemy::get_dmg(int dmg) {
     hp -= dmg;
}
int enemy::gethp(){
    return hp;
}
void enemy::getinv(){
    for(size_t i = 0; i < inventory.size(); i++){
        if(inventory.at(i) == nullptr) return;
        inventory.at(i)->info();
    }
}
void enemy::addinv(w wid){
    for(size_t i = 0; i < inventory.size(); i++){
        if(inventory.at(i) == nullptr) {
            inventory.at(i) = object::createobj(wid);
            return;
        }
    }    
}
void enemy::addinv(f fid){
    for(size_t i = 0; i < inventory.size(); i++){
        if(inventory.at(i) == nullptr) { 
            inventory.at(i) = object::createobj(fid);
            return;
        }
    }    
}


