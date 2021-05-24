/* ===========================================
 * stackable.cpp file
 * ===========================================
 * author: Mateusz Kruk
 * e-mail: krukm634@gmail.com
 * last modified: 25.05.2021
 * ===========================================
 * version: 0.1.0-a.1 [backpack]
 * ===========================================
 */

#include "../include/stackable.h"

#include <iostream>

//set_attribute

void Item::Stackable::set_attribute(char c, std::string val) {
    switch (c)
    {
    case 0:
        print << "Test Set" << eol;
        break;

    case 1: //name
        name = val;
        break;
    
    case 2: //value
        try {
            value = std::stof(val);
        }
        catch (std::exception &e) {
            error(e.what())
        }
        break;

    case 3: //quantity
        to_int(quantity,val)
        break;

    case 4: //quantity cap
        to_int(QUANTITY_CAP,val)
        break;


    default:
        error("Got invalid character " << c)
        break;
    }

}

void Item::Consumable::set_attribute(char c, std::string val) {

    switch (c)
    {
    case 0:
        print << "Test Set" << eol;
        break;

    case 1: //name
        name = val;
        break;
    
    case 2: //value
        try {
            value = std::stof(val);
        }
        catch (std::exception &e) {
            error(e.what())
        }
        break;

    case 3: //quantity
        to_int(quantity,val)
        break;

    case 4: //quantity cap
        to_int(QUANTITY_CAP,val)
        break;

    case 5: //effect
        to_int(item_effect.effect,val)
        break;

    case 6: //effect level
        to_int(item_effect.effect_level,val)
        break;

    case 7: //duration
        to_int(item_effect.duration,val)
        break;

    default:
        error("Got invalid character " << c)
        break;
    }

}

//Overloaded operators

Item::Stackable& Item::Stackable::operator=(const Item::Stackable &s){
    this -> name = s.name;
    this -> value = s.value;
    this -> quantity = s.quantity;
    this -> QUANTITY_CAP = s.QUANTITY_CAP;

    return *this;
}

Item::Stackable& Item::Stackable::operator+=(Item::Stackable &st) {

    print << "Overloaded operator +=" << eol;

    if (this -> name != st.name || this -> QUANTITY_CAP != st.QUANTITY_CAP) {
        print << "Error! Items cannot be stacked!" << eol;
        return *this; 
    }

    this -> quantity += st.quantity;
    
    auto avg = [](float a, float b) {return (a+b)/2.0f;};

    this -> value = avg(this -> value,st.value);

    return *this;
}

Item::Stackable& Item::Stackable::operator-=(Item::Stackable &st) {

    print << "Overloaded operator -=" << eol;

    if (this -> quantity < st.quantity || this -> name != st.name || this -> QUANTITY_CAP != st.QUANTITY_CAP) {
        print << "Error! Items cannot be stacked!" << eol;
        return *this;
    }

    this -> quantity -= st.quantity;
    
    auto avg = [](float a, float b) {return (a+b)/2.0f;};

    this -> value = avg(this -> value,st.value);

    return *this;
}

Item::Consumable& Item::Consumable::operator=(const Item::Consumable &s){
    this -> name = s.name;
    this -> value = s.value;
    this -> quantity = s.quantity;
    this -> QUANTITY_CAP = s.QUANTITY_CAP;
    this -> item_effect = s.item_effect;

    return *this;
}

Item::Consumable& Item::Consumable::operator+=(Item::Consumable &c) {
    print << "Overloaded operator +=" << eol;

    if (this -> name != c.name || this -> QUANTITY_CAP != c.QUANTITY_CAP || this -> item_effect != c.item_effect) {
        print << "Error! Items cannot be stacked!" << eol;
        return *this; 
    }

    this -> quantity += c.quantity;
    
    auto avg = [](float a, float b) {return (a+b)/2.0f;};

    this -> value = avg(this -> value, c.value);

    return *this;
}

Item::Consumable& Item::Consumable::operator-=(Item::Consumable &c) {

    print << "Overloaded operator -=" << eol;

    if (this -> quantity < c.quantity || this -> name != c.name || this -> QUANTITY_CAP != c.QUANTITY_CAP || this -> item_effect != c.item_effect) {
        print << "Error! Items cannot be stacked!" << eol;
        return *this;
    }

    this -> quantity -=  c.quantity;
    
    auto avg = [](float a, float b) {return (a+b)/2.0f;};

    this -> value = avg(this -> value,c.value);

    return *this;

}

//Stackable constructors

Item::Stackable::Stackable() {
    name = "";
    value = 0;
    quantity = 0;
    QUANTITY_CAP = 0;
}

Item::Stackable::Stackable(const Stackable &s) {
    *this = s;
}

Item::Stackable::Stackable(std::string n) 
    {set_attribute(1,n);}

Item::Stackable::Stackable(std::string n, float v) :Stackable(n)
    {set_attribute(2,std::to_string(v));}

Item::Stackable::Stackable(std::string n, float v, u_int q) :Stackable(n,v)
    {set_attribute(3,std::to_string(q));}

Item::Stackable::Stackable(std::string n,float v, u_int q, u_int qp) :Stackable(n,v,q) 
    {set_attribute(4,std::to_string(qp));}

//Consumable contructors

Item::Consumable::Consumable() {
    name = "";
    value = 0;
    quantity = 0;
    QUANTITY_CAP = 0;
    item_effect.effect = 0;
    item_effect.effect_level = 0;
    item_effect.duration = 0;
}

Item::Consumable::Consumable(const Consumable &c){
    *this = c;
}

Item::Consumable::Consumable(std::string n)
    {set_attribute(1,n);}

Item::Consumable::Consumable(std::string n,float v) :Consumable(n)
    {set_attribute(2,std::to_string(v));}

Item::Consumable::Consumable(std::string n,float v,u_int q) :Consumable(n,v)
    {set_attribute(3,std::to_string(q));}

Item::Consumable::Consumable(std::string n,float v,u_int q, u_int qp) :Consumable(n,v,q)
    {set_attribute(4,std::to_string(qp));}

Item::Consumable::Consumable(std::string n,float v, u_int q, u_int qp,u_int e,u_int lvl,u_int d) : Consumable(n,v,q,qp) {
        set_attribute(5,std::to_string(e));
        set_attribute(6,std::to_string(lvl));   
        set_attribute(7,std::to_string(d));
        
}

//Destructors

Item::Stackable::~Stackable() {
    print<<"Destroying: "<< type <<" "<<name<<eol;
}

Item::Consumable::~Consumable() {
    print<<"Destroying: "<< type <<" "<<name<<eol;
}


//get_attribute

void Item::Stackable::get_attribute(std::deque <std::string> &atrs) {
    atrs.push_back(type);
    atrs.push_back(name);
    atrs.push_back(std::to_string(value));
    atrs.push_back(std::to_string(quantity));
    atrs.push_back(std::to_string(QUANTITY_CAP));
}

void Item::Stackable::get_attribute(char c, std::string &atr) {
    switch (c)
    {
    case 0:
        atr = type;
        break;
    case 1:
        atr = name;
        break;
    
    case 2:
        atr = std::to_string(value);
        break;

    case 3:
        atr = std::to_string(quantity);
        break;

    case 4:
        atr = std::to_string(QUANTITY_CAP);
        break;
    
    default:
        error("Invalid character key");
        break;
    }
}

void Item::Consumable::get_attribute(std::deque <std::string> &atrs) {
    atrs.push_back(type);
    atrs.push_back(name);
    atrs.push_back(std::to_string(value));
    atrs.push_back(std::to_string(quantity));
    atrs.push_back(std::to_string(QUANTITY_CAP));
    atrs.push_back(std::to_string(item_effect.effect));
    atrs.push_back(std::to_string(item_effect.effect_level));
    atrs.push_back(std::to_string(item_effect.duration));
}

void Item::Consumable::get_attribute(char c, std::string &atr) {
    switch (c)
    {
    case 0:
        atr = type;
        break;
    case 1:
        atr = name;
        break;
    
    case 2:
        atr = std::to_string(value);
        break;

    case 3:
        atr = std::to_string(quantity);
        break;

    case 4:
        atr = std::to_string(QUANTITY_CAP);
        break;

    case 5:
        atr = std::to_string(item_effect.effect);
        break;

    case 6:
        atr = std::to_string(item_effect.effect_level);
        break;

    case 7:
        atr = std::to_string(item_effect.duration);
        break;
    
    default:
        error("Invalid character key");
        break;
    }
}

//inspect

void Item::Stackable::inspect() {
    line(28);
    if (QUANTITY_CAP == 1)
        print << "Name: " << name << eol;
    else
        print << "Name: " << name << " x" << quantity << eol;
    print << "Item type: Stackable" << eol;
    line(28);
    print << "Value:" << value << eol;
    line(28);
}

void Item::Consumable::inspect() {
    line(28);
    if (QUANTITY_CAP == 1)
        print << "Name: " << name << eol;
    else
        print << "Name: " << name << " x" << quantity << eol;
    print << "Item type: Consumable" << eol;
    line(28);
    print << "Value:" << value << eol;
    line(28);
    print << "Effect: " << item_effect.effect 
          << " " << item_effect.effect_level << "lvl" << eol;
    line(28);
}