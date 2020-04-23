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
    int x = getmaxx(stdscr);
    move(0, x-20);
    printw("named: %s\n", name.c_str());
    move(1, x-20);    // too bad
    printw("level: %d\n", lvl);
    move(2, x-20);
    printw("health point: %d\n", hp);
    move(3, x-20);
    printw("mana point: %d\n", mp);
    move(4, x-20);
    printw("damage: %d\n", dmg);
//    printw("strength: %d\n", str);
//    printw("dexterity: %d\n", dex);
}
int enemy::attack() {
    return dmg*str*0.5;
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


