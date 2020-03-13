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
    int attack(){
        return str*0.5;
    }
    int miss(int dmg){
        return dmg-(dex*0.5);
    }
    void get_dmg(int dmg){
        hp -= dmg;
    }
};
class hero : public creature {
private:
    std::string name;
    int lvl;
    int hp;
    int mp;
    int str;
    int dex;
public:
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

    }
    int attack() {
        return str*0.5;
    }
    int miss(int dmg) {
        return dmg-(dex*0.5);
    }
    void get_dmg(int dmg) {
        hp -= dmg;
    }
    void the_fuck(){
        std::cout << "fuck" << '\n';
    }
};