#include <iostream>
#include <string>
#include "creatures.h"

creature::creature(int lvl, int hp, int mp, int str, int dex) : lvl(lvl), hp(hp), mp(mp), str(str), dex(dex) {}
void creature::status() {
    std::cout << "level: " << lvl << std::endl;
    std::cout << "health point: " << hp << std::endl;
    std::cout << "mana point: " << mp << std::endl;
    std::cout << "strength: " << str << std::endl;
    std::cout << "dexterity: " << dex << std::endl;                
}
int creature::attack() {
    return str*0.5;
}
int creature::block(int dmg) {
    return dmg-(dex*0.5);
}
void creature::get_dmg(int dmg) {
     hp -= dmg;
}
int creature::getlvl(){
    return lvl;
}
int creature::gethp(){
    return hp;
}
int creature::getmp(){
    return mp;
}
int creature::getstrg(){
    return str;
}
int creature::getdex(){
    return dex;
}
    