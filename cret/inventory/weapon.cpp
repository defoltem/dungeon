#include "wNs.h"
#include <iostream>
#include <string>
weapon::weapon(int weight, int self_price, int damage, std::string obj_name):object(weight, self_price), damage(damage), obj_name(obj_name){
    this->weight = weight;
    this->self_price = self_price;
}  
int weapon::getd(){
    return damage;
}
int weapon::getsp(){
    return self_price;
}
int weapon::getw(){
    return weight;
}
void weapon::info(){
    printw("object: %s\n", obj_name.c_str());
    printw("weight: %d\n", weight);
    printw("self price: %d\n", self_price);
    printw("damage: %d\n", damage);
}