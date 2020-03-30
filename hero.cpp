#include "creatures.h"
#include <string>
#include <iostream>
hero::hero(int lvl, int hp, int mp, int str, int dex, std::string name):creature(lvl, hp, mp, str, dex), name(name){
    this->lvl = lvl;
    this->hp = hp;
    this->mp = mp;
    this->str = str;
    this->dex = dex;
}
void hero::status() {
    std::cout << "named: " << name << std::endl;
    std::cout << "level: " << lvl << std::endl;
    std::cout << "health point: " << hp << std::endl;
    std::cout << "mana point: " << mp << std::endl;
    std::cout << "strength: " << str << std::endl;
    std::cout << "dexterity: " << dex << std::endl;                
}
int hero::attack() {
    return str*0.5;
}
int hero::block(int dmg) {
    return dmg-(dex*0.5);
}
void hero::get_dmg(int dmg) {
    hp -= dmg;
}
int hero::getlvl(){
    return lvl;
}
int hero::gethp(){
    return hp;
}
int hero::getmp(){
    return mp;
}
int hero::getstrg(){
    return str;
}
int hero::getdex(){
    return dex;
}
void hero::getinv(){
    for(size_t i = 0; i < inventory.size(); i++){
        if(inventory.at(i) == nullptr) return;
        inventory.at(i)->info();
    }
}
void hero::addinv(w wid){
    for(size_t i = 0; i < inventory.size(); i++){
        if(inventory.at(i) == nullptr) {
            inventory.at(i) = object::createobj(wid);
            return;
        }
    }    
}
void hero::addinv(f fid){
    for(size_t i = 0; i < inventory.size(); i++){
        if(inventory.at(i) == nullptr){
            inventory.at(i) = object::createobj(fid);
            return;
        }    
    }
}
