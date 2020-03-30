#include "wNs.h"
#include <iostream>
void object::info(){
    std::cout << "weight: " << weight << '\n';
    std::cout << "self price: " << self_price << '\n';
}
int object::getw(){
    return weight;
}
int object::getsp(){
    return self_price;
}
object::object(int weight, int self_price) : weight(weight), self_price(self_price) {}
//enum w {sword = 0, axe, morgenstern};
std::shared_ptr<object> object::createobj(w wid){
    std::shared_ptr<object> p;
    switch (wid)
    {
    case sword:{
        std::shared_ptr<weapon> pw(new weapon(2, 5, 2, "sword"));
        p = pw;
        break;
    }
    case axe:{
        std::shared_ptr<weapon> pw(new weapon(3, 7, 4, "axe"));
        p = pw;
        break;
    }
    case morgenstern:{
        std::shared_ptr<weapon> pw(new weapon(5, 10, 5, "morgenstern"));
        p = pw;
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
        std::shared_ptr<food> pw(new food(2, 2, 3, "bread"));
        p = pw;
        break;
    }
    case meat:{
        std::shared_ptr<food> pw(new food(3, 5, 4, "meat"));
        p = pw;
        break;
    }
    case nuts:{
        std::shared_ptr<food> pw(new food(1, 1, 1, "nuts"));
    }
    default:
        break;
    }
    return p;
}