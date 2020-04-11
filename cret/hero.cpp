#include "creatures.h"
#include <string>
#include <iostream>
#include <ncurses.h>
hero::hero(int lvl, int hp, int mp, int str, int dex, std::string name):creature(lvl, hp, mp, str, dex), name(name){
    this->lvl = lvl;
    this->hp = hp;
    this->mp = mp;
    this->str = str;
    this->dex = dex;
}
void hero::status() {
    /*std::cout << "named: " << name << std::endl;
    std::cout << "level: " << lvl << std::endl;
    std::cout << "health point: " << hp << std::endl;
    std::cout << "mana point: " << mp << std::endl;
    std::cout<< "damage: " << dmg << std::endl;
    std::cout << "strength: " << str << std::endl;
    std::cout << "dexterity: " << dex << std::endl;                
    */
 //   initscr();
    printw("named: %s\n", name.c_str());
    printw("level: %d\n", lvl);
    printw("health point: %d\n", hp);
    printw("mana point: %d\n", mp);
    printw("damage: %d\n", dmg);
    printw("strength: %d\n", str);
    printw("dexterity: %d\n", dex);
    getch();
   // endwin();
}
int hero::attack() {
    return dmg*str*0.5;
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
void hero::setdmg(){
    size_t per;
    std::cout << "choose a weapon: ";
    std::cin>>per;
    if(per <= inventory.size() && per >= 0 && inventory.at(per) != nullptr) {
        main_weapon = per;
        dmg = inventory.at(main_weapon)->getd();
    }
    else {
        std::cout << "there's no item like that";
        return;
    }
}
void hero::setheal(){
    size_t per;
    std::cout << "choose an object: ";
    std::cin>>per;
    if(per <= inventory.size() && per >= 0 && inventory.at(per) != nullptr){
        hp += inventory.at(per)->geth();
    }
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
