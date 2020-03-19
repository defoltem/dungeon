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
/*int enemy::getlvl(){
    return lvl;
}int creature::getmp(){
    return mp;
}
int creature::getstrg(){
    return str;
}
int creature::getdex(){
    return dex;
}*/


