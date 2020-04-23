#include "wNs.h"
#include <iostream>
#include <string>
food::food(int weight, int self_price, int heal, std::string obj_name):object(weight, self_price), heal(heal), obj_name(obj_name){
    this->weight = weight;
    this->self_price = self_price;
}
int food::geth(){
    return heal;
}
int food::getsp(){
    return self_price;
}
int food::getw(){
    return weight;
}
void food::info(){
    printw("object: %s\n", obj_name.c_str());
    printw("weight: %d\n", weight);
    printw("self price: %d\n", self_price);
    printw("heal: %d\n", heal);
}
std::string food::get_label(){
    return "food";
}
std::string food::get_name(){
    return obj_name;
}