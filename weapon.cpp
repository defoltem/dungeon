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
    std::cout << "object: " << obj_name << '\n';
    std::cout << "weight: " << weight << '\n';
    std::cout << "self price: " << self_price << '\n'; 
    std::cout << "damage: " << damage << '\n';
}