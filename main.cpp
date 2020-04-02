#include <iostream>
#include "creatures.h"
#include <string>
#include <ncurses.h>

void line(){
    std::cout << "----------------\n";
}
void all_status(hero h, std::shared_ptr<enemy> e){
    h.status();
    line();
    e->status();    
}

int main(){
    bool hero_turn = true;
    const int size_arr = 4;
    short int for_cicle = size_arr;
    int arrn[size_arr] = {5, 5, 5, 5};
    std::string arrs[size_arr] = {"hp", "mp", "str", "dex"}; // just for creating hero
    short int points = 3, step = 0;
    std::string n;
    std::cout << "write your name: ";
    getline(std::cin, n);
    const std::string cn = n; // create hero's name
    std::cout << cn << '\n';
    std::cout << "each your characteristic is equal to 5 and you have only 3 points\nif you don't want to add points then just write zero\n";
    while(points > 0){
        int per;
        std::cout << "you have " << points << " points\n";
        for(int i = 0; i < for_cicle; i++){
            std::cout << arrs[i] << ": " << arrn[i] << '\n';
            //points = 0;  
        }
        std::cout << "add to " << arrs[step] << "? ";
        std::cin>>per;
        if(per > points){
            std::cout << "your value's more then avaliable points\n";
            for_cicle++;
            continue;
        }
        points -= per;
        arrn[step] += per;
        step++;
        line();
    }
    hero hr(1, arrn[0], arrn[1], arrn[2], arrn[3], cn); // creture(lvl, hp, mp, str, dex), name(name) 
    hr.status();
    hr.addinv(sword);
    hr.getinv();
    while(1){
        std::shared_ptr<enemy> e(new enemy(hr.getlvl(), hr.gethp(), hr.getmp(), 0, hr.getdex()));
        while(e->gethp() > 0 || hr.gethp() > 0){
            if(hero_turn) {
                e->get_dmg(hr.attack());
                hero_turn = false;
                }
            else {
                hr.get_dmg(e->attack());
                hero_turn = true;
            }
            system("clear");
            all_status(hr, e);
        }
        break;
    }
    return 0;
}