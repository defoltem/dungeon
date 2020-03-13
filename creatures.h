#include <iostream>
#include <string>
class creture{
private:
    int lvl;
    int hp;
    int mp;
    int str;
    int dex;
protected:
    creture(int lvl, int hp, int mp, int str, int dex) : lvl(lvl), hp(hp), mp(mp), str(str), dex(dex) {}
     void status() {
        std::cout << "level: " << this->lvl << std::endl;
        std::cout << "health point: " << this->hp << std::endl;
        std::cout << "mana point: " << this->mp << std::endl;
    }
    int attack(){
        return this->str*0.5;
    }
    int miss(int dmg){
        return dmg-(this->dex*0.5);
    }
    void get_dmg(int dmg){
        this->hp -= dmg;
    }
};
class hero : public creture {
private:
    std::string name;
    int lvl;
    int hp;
    int mp;
    int str;
    int dex;
public:
    hero(int lvl, int hp, int mp, int str, int dex, std::string name):creture(lvl, hp, mp, str, dex), name(name) {}
    void status() {
        std::cout << "level: " << this->lvl << std::endl;
        std::cout << "health point: " << this->hp << std::endl;
        std::cout << "mana point: " << this->mp << std::endl;

    }
    int attack() {
        return this->str*0.5;
    }
    int miss(int dmg) {
        return dmg-(this->dex*0.5);
    }
    void get_dmg(int dmg) {
        this->hp -= dmg;
    }
    void the_fuck(){
        std::cout << "fuck" << '\n';
    }
};