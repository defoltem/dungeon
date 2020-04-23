#include <string>
#include <memory>
#include <ncurses.h>
enum w {sword = 0, axe, morgenstern};
enum f {bread = 0, meat, nuts};

class object{
protected:
    int weight;
    int self_price;
public:
    object(int weight, int self_price);
    static std::shared_ptr<object> createobj(w wid);
    static std::shared_ptr<object> createobj(f fid);
    virtual int getw();
    virtual int getsp();
    virtual int getd();
    virtual int geth();
    virtual void info();
    virtual std::string get_label();
    virtual std::string get_name();
};

class weapon : public object{
private:
    int damage;
    std::string obj_name;
public:
    weapon(int weight, int self_price, int damage, std::string obj_name);
    //static std::shared_ptr<weapon> createweap(w i);
    int getd()override;
    int getw()override;
    int getsp()override;
    void info()override;
    std::string get_label()override;
    std::string get_name()override;
};

class food : public object{
private:
    int heal;
    std::string obj_name;
public:
    food(int weight, int self_price, int heal, std::string obj_name);
    //static std::shared_ptr<food> createf(f id);
    int geth()override;
    int getw()override;
    int getsp()override;
    void info()override;
    std::string get_label()override;
    std::string get_name()override;
};