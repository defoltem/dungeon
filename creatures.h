#include <iostream>
#include <string>
class creature{
private:
    int lvl;
    int hp;
    int mp;
    int str;
    int dex;
protected:
    creature(int lvl, int hp, int mp, int str, int dex) : lvl(lvl), hp(hp), mp(mp), str(str), dex(dex) {}
     void status() {
        std::cout << "level: " << lvl << std::endl;
        std::cout << "health point: " << hp << std::endl;
        std::cout << "mana point: " << mp << std::endl;
    }
    int attack(){ // this go first
        return str*0.5;
    }
    int block(int dmg){ // that thing's going to block input damage
        return dmg-(dex*0.5);
    }
    void get_dmg(int dmg){ // and, finally, this method hit creature
        hp -= dmg;
    }
};
class hero : public creature {
private:
    std::string name;
public:
    int lvl;
    int hp;
    int mp;
    int str;
    int dex;
    hero(int lvl, int hp, int mp, int str, int dex, std::string name):creature(lvl, hp, mp, str, dex), name(name){
        this->lvl = lvl;
        this->hp = hp;
        this->mp = mp;
        this->str = str;
        this->dex = dex;
    }
    void status() {
        std::cout << "named: " << name << std::endl;
        std::cout << "level: " << lvl << std::endl;
        std::cout << "health point: " << hp << std::endl;
        std::cout << "mana point: " << mp << std::endl;
        std::cout << "strength: " << str << std::endl;
        std::cout << "dexterity: " << dex << std::endl;                
    }
    int attack() {
        return str*0.5;
    }
    int block(int dmg) {
        return dmg-(dex*0.5);
    }
    int get_dmg(int dmg) {
        return hp -= dmg;
    }
    void the_fuck(){
        std::cout << "fuck" << '\n';
    }
};
class enemy : public creature {
private:
    std::string name;
    int lvl;
    int mp;
    int str;
    int dex;
public:
    int hp;
    enemy(int lvl, int hp, int mp, int str, int dex) : creature(lvl, hp, mp, str, dex){
        this->lvl = lvl;
        this->hp = hp;
        this->mp = mp;
        this->str = str;
        this->dex = dex;
        if (lvl <= 5) name = "goblin";
        else if (lvl <= 10) name = "golem";
        else name = "slave of eternity";
    }
    void status() {
        std::cout << "named: " << name << std::endl;
        std::cout << "level: " << lvl << std::endl;
        std::cout << "health point: " << hp << std::endl;
        std::cout << "mana point: " << mp << std::endl;
        std::cout << "strength: " << str << std::endl;
        std::cout << "dexterity: " << dex << std::endl;                
    }
    int attack() {
        return str*0.5;
    }
    int block(int dmg) {
        return dmg-(dex*0.5);
    }
    void get_dmg(int dmg) {
        hp -= dmg;
    }
};
