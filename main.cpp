#include <iostream>
#include "cret/creatures.h"
#include <string>
#include <ncurses.h>
#include <array>

void prints(std::string s){
    for(const char c:s) addch(c | A_STANDOUT);
    addch('\n');
}

void fight(){
    clear();
    printw("- you will die!\n- no u");
    getch();
}

void choose(const std::array<std::string, 4> arr, hero &h){
    unsigned choice = 0;
    curs_set(0);
    while (1)
    {
        clear();
        printw("use vim-keys(j - down, k - up)\n");
        for(size_t i = 0; i < arr.size(); i++){
            if (i == choice) prints(arr.at(i));
            else printw("%s\n", arr.at(i).c_str());
        }
        printw("%d\n", choice);
        switch(getch()){
            case 107:
                if(choice) choice--;
            break;
            case 106:
                if(choice != 3) choice++;
            break;
            case 10:
                if(!choice) fight(); // this kinda bad
                else if(choice == 1) h.status();
                else if (choice == 2) h.getinv();
                else if (choice == 3)  h.setdmg();
            break;
        }
    }
}

void line(){
    std::cout << "----------------\n";
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
    system("clear");
    keypad(stdscr, true); // allow arrows
    const std::array<std::string, 4> bar = {"fight", "status", "inventory", "choose weapon"};
    initscr();
    hero hr(1, arrn[0], arrn[1], arrn[2], arrn[3], cn); // creture(lvl, hp, mp, str, dex), name(name) 
    hr.addinv(morgenstern);
    choose(bar, hr);
    getch();
    endwin();
    return 0;
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
            //all_status(hr, e);
            break;
        }
        break;
    }
    return 0;
}