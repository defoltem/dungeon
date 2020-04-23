#include "creatures.h"
#include <string>
#include <vector>
#include <iostream>

void printh(std::string s){
    for(const char c:s) addch(c | A_STANDOUT);
    addch('\n');
}
hero::hero(int lvl, int hp, int mp, int str, int dex, std::string name):creature(lvl, hp, mp, str, dex), name(name){
    this->lvl = lvl;
    this->hp = hp;
    this->mp = mp;
    this->str = str;
    this->dex = dex;
}
void hero::status() {
    //clear();
    printw("named: %s\n", name.c_str());
    printw("level: %d\n", lvl);
    printw("health point: %d\n", hp);
    printw("mana point: %d\n", mp);
    printw("damage: %d\n", dmg);
    printw("strength: %d\n", str);
    printw("dexterity: %d\n", dex);
    //getch();
}
int hero::getlvlp(){
    return lvl_point;
}
void hero::setlvlp(){
    lvl_point++;
    if (lvl_point == 3) lvl++;
    if (lvl_point == 5) lvl++;
    if (lvl_point == 10) lvl++;        
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
void hero::getinv(){
    clear();
    for(size_t i = 0; i < inventory.size(); i++){
        if(inventory.at(i) == nullptr) {
            getch();
            return;
        }
        inventory.at(i)->info();
        printw("------------\n");
    }
    //getch();
}
void hero::setdmg(){
    std::vector<int> vec;
    size_t per = 0;
    while(1){
        clear();
        printw("choose a weapon: \npress 'e' to exit\n");
        for(size_t i = 0; i < inventory.size(); i++){
            if(inventory.at(i) == nullptr) break;
            if(inventory.at(i)->get_label() == "weapon") {
                vec.push_back(i);
                per = vec.at(0);
                if (i == per) printh(inventory.at(i)->get_name());
                else {     
                    printw("%s\n", inventory.at(i)->get_name().c_str());
                }
            }
        }
        switch(getch()){
            case 107:
                if(per) per--;
            break;
            case 106:
                if(inventory.at(per+1) != nullptr) per++;
            break;
            case 101:
                return;
            case 10:
                main_weapon = vec.at(per);
                dmg = inventory.at(main_weapon)->getd();
                return;
        }
    }
}
void hero::setheal(){
    std::vector<int> vec;
    size_t per = 0;
    size_t ch = 0;
    while(1){
        clear();
        printw("choose a food: \npress 'e' to exit\n");
        for(size_t i = 0; i < inventory.size(); i++){
            if(inventory.at(i) == nullptr) break;
            if(inventory.at(i)->get_label() == "food") {
                vec.push_back(i);
                per = vec.at(0);
                if (i == per)  printh(inventory.at(i)->get_name());
                else {     
                    printw("%s\n", inventory.at(i)->get_name().c_str());
                }
            }
        }
        switch(getch()){
            case 107:
                if(ch) ch--;
            break;
            case 106:
                if(inventory.at(ch+1) != nullptr) ch++;
            break;
            case 101:
                return;
            case 10:
                hp += inventory.at(vec.at(ch))->geth();
                inventory.at(ch) = nullptr;
                return;
            //break;
        }
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
