#include <iostream>
#include <string>
#include "creatures.h"

creature::creature(int lvl, int hp, int mp, int str, int dex) : lvl(lvl), hp(hp), mp(mp), str(str), dex(dex) {}
void creature::status() {
    std::cout << "level: " << lvl << std::endl;
    std::cout << "health point: " << hp << std::endl;
    std::cout << "mana point: " << mp << std::endl;
    std::cout<< "damage: " << dmg << std::endl;
    std::cout << "strength: " << str << std::endl;
    std::cout << "dexterity: " << dex << std::endl;                
}
int creature::attack() {
    return dmg*str*0.5;
}
int creature::block(int dmg) {
    return dmg-(dex*0.5);
}
void creature::get_dmg(int dmg) {
     hp -= dmg;
}
int creature::getlvlp(){
    return lvl_point;
}
void creature::setlvlp(){
    lvl_point++;
    if (lvl_point == 3) lvl++;
    if (lvl_point == 5) lvl++;
    if (lvl_point == 10) lvl++;        
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
void creature::getinv(){
    for(size_t i = 0; i < inventory.size(); i++){
        if(inventory.at(i) == nullptr) return;
        inventory.at(i)->info();
    }
}
void creature::setdmg(){
    size_t per;
    std::cout << "choose a weapon: ";
    std::cin>>per;
    if(per <= inventory.size() && per >= 0 && inventory.at(per) != nullptr) {
        //main_weapon = per; main_weapon must be string!!
        dmg = inventory.at(per)->getd();
    }
    else {
        std::cout << "there's no item like that";
        return;
    }
}
void creature::setheal(){
    size_t per;
    std::cout << "choose an object: ";
    std::cin>>per;
    if(per <= inventory.size() && per >= 0 && inventory.at(per) != nullptr){
        hp += inventory.at(per)->geth();
    }
}
void creature::addinv(w wid){
    for(size_t i = 0; i < inventory.size(); i++){
        if(inventory.at(i) == nullptr){
            inventory.at(i) = object::createobj(wid);
            return;
        }
    }    
}
void creature::addinv(f fid){
    for(size_t i = 0; i < inventory.size(); i++){
        if(inventory.at(i) == nullptr){
            inventory.at(i) = object::createobj(fid);
            return;
        }
    }    
}

    