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
    std::cout << "object: " << obj_name << '\n';
    std::cout << "weight: " << weight << '\n';
    std::cout << "self price: " << self_price << '\n';
    std::cout << "heal: " << heal << '\n';
}