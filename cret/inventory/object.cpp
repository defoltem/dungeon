#include "wNs.h"
#include <iostream>
void object::info(){
    printw("weight: %d\n", weight);
    printw("self price: %d\n", self_price);
}
int object::getw(){
    return weight;
}
int object::getsp(){
    return self_price;
}
int object::getd(){
    return 1;
}
int object::geth(){
    return 1;
}
std::string object::get_label(){
    return "obj";
}
std::string object::get_name(){
    return "objn";
}
object::object(int weight, int self_price) : weight(weight), self_price(self_price) {}
//enum w {sword = 0, axe, morgenstern};
std::shared_ptr<object> object::createobj(w wid){
    std::shared_ptr<object> p;
    switch (wid)
    {
    case sword:{
        p = std::make_shared<weapon>(weapon(2, 5, 2, "sword"));
        break;
    }
    case axe:{
        p = std::make_shared<weapon>(weapon(3, 7, 4, "axe"));
        break;
    }
    case morgenstern:{
        p = std::make_shared<weapon>(weapon(5, 10, 5, "morgenstern"));
        break;
    }
    default:
        break;
    }
    return p;
}
//enum f {bread = 0, meat, nuts};
std::shared_ptr<object> object::createobj(f fid){
    std::shared_ptr<object> p;
    switch (fid)
    {
    case bread:{
        p = std::make_shared<food>(food(2, 2, 3, "bread"));
        break;
    }
    case meat:{
        p = std::make_shared<food>(food(3, 5, 4, "meat"));
        break;
    }
    case nuts:{
        p = std::make_shared<food>(food(1, 1, 1, "nuts"));
        break;
    }
    default:
        break;
    }
    return p;
}