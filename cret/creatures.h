#include <iostream>
#include <string>
#include <array>
#include "inventory/wNs.h"
#include <ncurses.h>
class creature{
protected:
    int lvl;
    int lvl_point = 0;
    int hp;
    int mp;
    int str;
    int dex;
    int dmg = 1;
    int main_weapon;
    std::array<std::shared_ptr<object>, 10> inventory;
    creature(int lvl, int hp, int mp, int str, int dex);
    void status();
    int attack(); // this go first
    int block(int dmg); // that thing's going to block input damage
    void get_dmg(int dmg); // and, finally, this method hit creature
    int getlvl();
    int gethp();
    int getmp();
    int getstrg();
    int getdex();
    void getinv();
    int getlvlp();
    void setlvlp();
    void setheal();
    void setdmg();
    void addinv(w wid);
    void addinv(f fid);
};

class hero : public creature {
private:
    std::string name;
public:
    hero(int lvl, int hp, int mp, int str, int dex, std::string name);
    void status();
    int attack();
    int block(int dmg);
    void get_dmg(int dmg);
    int getlvl();
    int gethp();
    int getmp();
    int getstrg();
    int getdex();
    void getinv();
    void setheal();
    int getlvlp();
    void setlvlp();
    void setdmg();
    void addinv(w wid);
    void addinv(f fid);    
};
class enemy : public creature {
private:
    std::string name;
public:
    enemy(int lvl, int hp, int mp, int str, int dex);
    void status();
    int attack();
    int block(int dmg);
    void get_dmg(int dmg);
    int gethp();
    void getinv();
    void addinv(w wid);
    void addinv(f fid);
};
