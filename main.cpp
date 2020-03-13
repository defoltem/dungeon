#include <iostream>
#include "creatures.h"

int main(){
    hero hr(1, 10, 10, 10, 10,"ku"); // creture(lvl, hp, mp, str, dex), name(name) 
    std::cout<< hr.attack() <<'\n';
    hr.status();
    return 0;
}