/* ===========================================
 * nonstackable.cpp file
 * ===========================================
 * author: Mateusz Kruk
 * e-mail: krukm634@gmail.com
 * last modified: 25.05.2021
 * ===========================================
 * version: 0.1.0-a.1 [backpack]
 * ===========================================
 */

#include "../include/nonstackable.h"

#include <iostream>

//set_attribute functions

void Item::Non_Stackable::set_attribute(char c, std::string val) {
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

    default:
        error("Got invalid character " << c)
        break;
    }
}

void Item::Armour::set_attribute(char c, std::string val) {
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

    case 3: //type
        to_int(armour_type, val)
        break;

    case 4: //protection
        to_int(protection, val)
        break;

    default:
        error("Got invalid character " << c)
        break;
    }
}

void Item::Defensive_Item::set_attribute(char c, std::string val) {
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

    case 3: //effect
        to_int(item_effect.effect, val)
        break;

    case 4: //effect_level
        to_int(item_effect.effect_level, val)
        break;

    case 5: //duration
        to_int(item_effect.duration, val)
        break;

    case 6: //protection
        to_int(protection, val)
        break;

    case 7: //isWearable
        to_bool(isWearable, val)
        break;

    case 8: //isTwoHanded
        to_bool(isTwoHanded, val)
        break;

    default:
        error("Got invalid character " << c)
        break;
    }
}

void Item::Melee_Weapon::set_attribute(char c, std::string val) {
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

    case 3: //weapon_type
        to_int(weapon_type, val)
        break;

    case 4: //damage
        to_int(damage, val)
        break;

    case 5: //isTwoHanded
        to_bool(isTwoHanded, val)
        break;

    default:
        error("Got invalid character " << c)
        break;
    }
}

void Item::Ranged_Weapon::set_attribute(char c, std::string val) {
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

    case 3: //weapon_type
        to_int(weapon_type, val)
        break;

    case 4: //damage
        to_int(damage, val)
        break;

    case 5: //range
        to_int(range, val)
        break;

    case 6: //isTwoHanded
        to_bool(isTwoHanded, val)
        break;

    default:
        error("Got invalid character " << c)
        break;
    }
}

//Overloaded operators

Item::Non_Stackable& Item::Non_Stackable::operator=(const Item::Non_Stackable &ns) {
    this -> name = ns.name;
    this -> value = ns.value;

    return *this;
}

bool Item::Non_Stackable::operator==(Item::Non_Stackable &ns) {
    if (this -> name != ns.name || 
        this->value != ns.value )
        return false;

    return true;
}

bool Item::Non_Stackable::operator!=(Item::Non_Stackable &ns) {
    return !(*this == ns);
}

Item::Armour& Item::Armour::operator=(const Item::Armour &a) {
    this -> name = a.name;
    this -> value = a.value;
    this -> armour_type = a.armour_type;
    this -> protection = a.protection;

    return *this;
}

bool Item::Armour::operator==(Item::Armour &a) {
    if (this -> name != a.name               ||
        this -> value != a.value             ||
        this -> armour_type != a.armour_type ||
        this -> protection != a.protection   )
        return false;

    return true;
}

bool Item::Armour::operator!=(Item::Armour &a) {
    return !(*this == a);
}

Item::Defensive_Item& Item::Defensive_Item::operator=(const Item::Defensive_Item &di) {
    this -> name = di.name;
    this -> value = di.value;
    this -> protection = di.protection;
    this -> item_effect = di.item_effect; 
    this -> isWearable = di.isWearable;
    this -> isTwoHanded = di.isTwoHanded;

    return *this;
}

bool Item::Defensive_Item::operator==(Item::Defensive_Item &di) {
    if (this -> name != di.name               ||
        this -> value != di.value             ||
        this -> protection != di.protection   ||
        this -> item_effect != di.item_effect ||
        this -> isWearable != di.isWearable   ||
        this -> isTwoHanded != di.isTwoHanded )
        return false;

    return true;
}

bool Item::Defensive_Item::operator!=(Item::Defensive_Item &di) {
    return !(*this == di);
}

Item::Melee_Weapon& Item::Melee_Weapon::operator=(const Item::Melee_Weapon &mw) {
    this -> name = mw.name;
    this -> value = mw.value;
    this -> weapon_type = mw.weapon_type;
    this -> damage = mw.damage;
    this -> isTwoHanded = mw.isTwoHanded;

    return *this;
}

bool Item::Melee_Weapon::operator==(Item::Melee_Weapon &mw) {
    if (this -> name != mw.name               ||
        this -> value != mw.value             ||
        this -> weapon_type != mw.weapon_type ||
        this -> damage != mw.damage           ||
        this -> isTwoHanded != mw.isTwoHanded )
        return false;

    return true;
}

bool Item::Melee_Weapon::operator!=(Item::Melee_Weapon &mw) {
    return !(*this == mw);
}

Item::Ranged_Weapon& Item::Ranged_Weapon::operator=(const Item::Ranged_Weapon &rw){
    this -> name = rw.name;
    this -> value = rw.value;
    this -> weapon_type = rw.weapon_type;
    this -> damage = rw.damage;
    this -> isTwoHanded = rw.isTwoHanded;

    return *this;
}

bool Item::Ranged_Weapon::operator==(Item::Ranged_Weapon &rw) {
    if (this -> name != rw.name               ||
        this -> value != rw.value             ||
        this -> weapon_type != rw.weapon_type ||
        this -> damage != rw.damage           ||
        this -> isTwoHanded != rw.isTwoHanded ||
        this -> range != rw.range             )
        return false;

    return true;
}

bool Item::Ranged_Weapon::operator!=(Item::Ranged_Weapon &rw) {
    return !(*this == rw);
}

//Constructors

Item::Non_Stackable::Non_Stackable() {
    name = "";
    value = 0;
}

Item::Non_Stackable::Non_Stackable(const Non_Stackable &n) {
    *this = n;
}

Item::Non_Stackable::Non_Stackable(std::string s) 
    {set_attribute(1,s);}

Item::Non_Stackable::Non_Stackable(std::string s,float v) :Non_Stackable(s)
    {set_attribute(2,std::to_string(v));}


Item::Armour::Armour() {
    name = "";
    value = 0;
    armour_type = 0;
    protection = 0;
}

Item::Armour::Armour(const Armour &a) {
    *this = a;
}
        
Item::Armour::Armour(std::string n)
    {set_attribute(1,n);}

Item::Armour::Armour(std::string n,float v) :Armour(n)
    {set_attribute(2,std::to_string(v));}

Item::Armour::Armour(std::string n,float v,u_int at) :Armour(n,v)
    {set_attribute(3,std::to_string(at));}

Item::Armour::Armour(std::string n,float v,u_int at, u_int p) :Armour(n,v,at)
    {set_attribute(4,std::to_string(p));}


Item::Defensive_Item::Defensive_Item() {
    name = "";
    value = 0;
    protection = 0;
    item_effect.effect = 0;
    item_effect.effect_level = 0;
    item_effect.duration = 0;
    isWearable = false;
    isTwoHanded = true;
}

Item::Defensive_Item::Defensive_Item(const Defensive_Item &di) {
    *this = di;
}

Item::Defensive_Item::Defensive_Item(std::string n)
    {set_attribute(1,n);}

Item::Defensive_Item::Defensive_Item(std::string n,float v) :Defensive_Item(n)
    {set_attribute(2,std::to_string(v));}

Item::Defensive_Item::Defensive_Item(std::string n,float v,u_int p) :Defensive_Item(n,v)
    {set_attribute(6,std::to_string(p));}

Item::Defensive_Item::Defensive_Item(std::string n,float v,u_int p, bool iw, bool it) :Defensive_Item(n,v,p) {
    this -> isTwoHanded = it;
    this -> isWearable = iw;
}

Item::Defensive_Item::Defensive_Item(std::string n,float v,u_int p, u_int e,u_int lvl,u_int d) :Defensive_Item(n,v,p) {
    set_attribute(3,std::to_string(e));
    set_attribute(4,std::to_string(lvl));   
    set_attribute(5,std::to_string(d));   
}

Item::Defensive_Item::Defensive_Item(std::string n,float v,u_int p, u_int e,u_int lvl,u_int d, bool iw, bool it) :Defensive_Item(n,v,p,e,lvl,d) {
    this -> isTwoHanded = it;
    this -> isWearable = iw;   
}


Item::Melee_Weapon::Melee_Weapon() {
    name = "";
    value = 0;
    weapon_type = 0;
    damage = 0;
    isTwoHanded = 0;
}

Item::Melee_Weapon::Melee_Weapon(const Melee_Weapon &mw) {
    *this = mw;
}

Item::Melee_Weapon::Melee_Weapon(std::string n)
    {set_attribute(1,n);}

Item::Melee_Weapon::Melee_Weapon(std::string n,float v) :Melee_Weapon(n)
    {set_attribute(2,std::to_string(v));}

Item::Melee_Weapon::Melee_Weapon(std::string n,float v,u_int wt, u_int d) :Melee_Weapon(n,v) {
    set_attribute(3,std::to_string(wt));
    set_attribute(4,std::to_string(d));    
}

Item::Melee_Weapon::Melee_Weapon(std::string n,float v,u_int wt, u_int d, bool it) :Melee_Weapon(n,v,wt,d)
    {this -> isTwoHanded = it;}


Item::Ranged_Weapon::Ranged_Weapon() {
    name = "";
    value = 0;
    weapon_type = 0;
    damage = 0;
    isTwoHanded = 0;
    range = 0;
}

Item::Ranged_Weapon::Ranged_Weapon(const Ranged_Weapon &rw) {
    *this = rw;
}

Item::Ranged_Weapon::Ranged_Weapon(std::string n)
    {set_attribute(1,n);}

Item::Ranged_Weapon::Ranged_Weapon(std::string n,float v) :Ranged_Weapon(n)
    {set_attribute(2,std::to_string(v));}

Item::Ranged_Weapon::Ranged_Weapon(std::string n,float v,u_int wt, u_int d) :Ranged_Weapon(n,v){
    set_attribute(3,std::to_string(wt));
    set_attribute(4,std::to_string(d)); 
}

Item::Ranged_Weapon::Ranged_Weapon(std::string n,float v,u_int wt, u_int d, bool it) :Ranged_Weapon(n,v,wt,d) 
    {set_attribute(6,std::to_string(it));}

Item::Ranged_Weapon::Ranged_Weapon(std::string n,float v,u_int wt, u_int d, u_int r) :Ranged_Weapon(n,v,wt,d)
    {set_attribute(5,std::to_string(r));}

Item::Ranged_Weapon::Ranged_Weapon(std::string n,float v,u_int wt, u_int d, u_int r, bool it) :Ranged_Weapon(n,v,wt,d,r)
    {this -> isTwoHanded = it;}

//Destructors

Item::Non_Stackable::~Non_Stackable() {
    print<<"Destroying: "<< type <<" "<<name<<eol;
}

Item::Armour::~Armour() {
    print<<"Destroying: "<< type <<" "<<name<<eol;
}

Item::Defensive_Item::~Defensive_Item() {
    print<<"Destroying: "<< type <<" "<<name<<eol;
}

Item::Melee_Weapon::~Melee_Weapon() {
    print<<"Destroying: "<< type <<" "<<name<<eol;
}

Item::Ranged_Weapon::~Ranged_Weapon() {
    print<<"Destroying: "<< type <<" "<<name<<eol;
}

//get_attribute

void Item::Non_Stackable::get_attribute(std::deque <std::string> &atrs) {
    atrs.push_back(type);
    atrs.push_back(name);
    atrs.push_back(std::to_string(value));
}

void Item::Non_Stackable::get_attribute(char c, std::string &atr) {
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
    
    default:
        error("Invalid character key");
        break;
    }
}

void Item::Armour::get_attribute(std::deque <std::string> &atrs) {
    atrs.push_back(type);
    atrs.push_back(name);
    atrs.push_back(std::to_string(value));
    atrs.push_back(std::to_string(armour_type));
    atrs.push_back(std::to_string(protection));
}

void Item::Armour::get_attribute(char c, std::string &atr) {
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
        atr = std::to_string(armour_type);
        break;

    case 4:
        atr = std::to_string(protection);
        break;
    
    default:
        error("Invalid character key");
        break;
    }
}

void Item::Defensive_Item::get_attribute(std::deque <std::string> &atrs) {
    atrs.push_back(type);
    atrs.push_back(name);
    atrs.push_back(std::to_string(value));
    atrs.push_back(std::to_string(protection));
    atrs.push_back(std::to_string(item_effect.effect));
    atrs.push_back(std::to_string(item_effect.effect_level));
    atrs.push_back(std::to_string(item_effect.duration));
    atrs.push_back(std::to_string(isWearable));
    atrs.push_back(std::to_string(isTwoHanded));
}

void Item::Defensive_Item::get_attribute(char c, std::string &atr) {
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
        atr = std::to_string(protection);
        break;

    case 4:
        atr = std::to_string(item_effect.effect);
        break;

    case 5:
        atr = std::to_string(item_effect.effect_level);
        break;

    case 6:
        atr = std::to_string(item_effect.duration);
        break;

    case 7:
        atr = std::to_string(isWearable);
        break;

    case 8:
        atr = std::to_string(isTwoHanded);
        break;
    
    default:
        error("Invalid character key");
        break;
    }
}

void Item::Melee_Weapon::get_attribute(std::deque <std::string> &atrs) {
    atrs.push_back(type);
    atrs.push_back(name);
    atrs.push_back(std::to_string(value));
    atrs.push_back(std::to_string(weapon_type));
    atrs.push_back(std::to_string(damage));   
    atrs.push_back(std::to_string(isTwoHanded));
}

void Item::Melee_Weapon::get_attribute(char c, std::string &atr) {
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
        atr = std::to_string(weapon_type);
        break;

    case 4:
        atr = std::to_string(damage);
        break;

    case 5:
        atr = std::to_string(isTwoHanded);
        break;
    
    default:
        error("Invalid character key");
        break;
    }
}

void Item::Ranged_Weapon::get_attribute(std::deque <std::string> &atrs) {
    atrs.push_back(type);
    atrs.push_back(name);
    atrs.push_back(std::to_string(value));
    atrs.push_back(std::to_string(weapon_type));
    atrs.push_back(std::to_string(damage));   
    atrs.push_back(std::to_string(isTwoHanded));
    atrs.push_back(std::to_string(range));
}

void Item::Ranged_Weapon::get_attribute(char c, std::string &atr) {
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
        atr = std::to_string(weapon_type);
        break;

    case 4:
        atr = std::to_string(damage);
        break;

    case 5:
        atr = std::to_string(isTwoHanded);
        break;

    case 6:
        atr = std::to_string(range);
        break;
    
    default:
        error("Invalid character key");
        break;
    }
}

//inspect

void Item::Non_Stackable::inspect() {
    line(28);
    print << "Name: " << name << eol;
    print << "Item type: Non Stackable" << eol;
    line(28);
    print << "Value: " << value << eol;
    line(28);
}

void Item::Armour::inspect() {
    line(28);
    print << "Name: " << name << eol;
    print << "Item type: Armor" << eol;
    line(28);
    print << "Value: " << value << eol;
    print << "Type: " << armour_type << eol;
    print << "Protection: " << protection << eol;
    line(28);
}

void Item::Defensive_Item::inspect() {
    line(28);
    print << "Name: " << name << eol;
    print << "Item type: Defensive Item" << eol;
    line(28);
    print << "Value: " << value << eol;
    print << "Protection: " << protection << eol;
    line(28);
    print << "Effect: " << item_effect.effect 
          << " " << item_effect.effect_level << "lvl" << eol;
    line(28);
}

void Item::Melee_Weapon::inspect() {
    line(28);
    print << "Name: " << name << eol;
    print << "Item type: Melee Weapon" << eol;
    line(28);
    print << "Value: " << value << eol;
    print << "Type: " << weapon_type << eol;
    print << "Damage: " << damage << eol;
    print << "Is two handed? " << isTwoHanded << eol;
    line(28);
}

void Item::Ranged_Weapon::inspect() {
    line(28);
    print << "Name: " << name << eol;
    print << "Item type: Ranged Weapon" << eol;
    line(28);
    print << "Value: " << value << eol;
    print << "Type: " << weapon_type << eol;
    print << "Damage: " << damage << "(" << range << "m)" << eol;
    print << "Is two handed? " << isTwoHanded << eol;
    line(28);
}