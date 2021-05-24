/* ===========================================
 * nonstackable.h file
 * ===========================================
 * author: Mateusz Kruk
 * e-mail: krukm634@gmail.com
 * last modified: 25.05.2021
 * ===========================================
 * version: 0.1.0-a.1 [backpack]
 * ===========================================
 */

#ifndef NONSTACK_H
#define NONSTACK_H

#include "item.h"
#include "format.h"

namespace Item
{
    
    class Non_Stackable : public Instance {
    protected:
        const std::string type = "Non_Stackable";
        const u_int quantity = 1;

        void set_attribute(char, std::string);

    public:
        Non_Stackable& operator=(const Non_Stackable &);
        bool operator==(Non_Stackable &);
        bool operator!=(Non_Stackable &);

        Non_Stackable();
        Non_Stackable(const Non_Stackable &);

        Non_Stackable(std::string);
        Non_Stackable(std::string,float);

        ~Non_Stackable();

        void get_attribute(std::deque <std::string> &);

        void get_attribute(char, std::string &);

        void inspect();
    };

    class Armour : public Non_Stackable {
    protected:
        const std::string type = "Armour";
        u_int armour_type;
        u_int protection;

        void set_attribute(char, std::string);

    public:

        Armour& operator=(const Armour &);
        bool operator==(Armour &);
        bool operator!=(Armour &);

        Armour();
        Armour(const Armour &);

        Armour(std::string);
        Armour(std::string,float);
        Armour(std::string,float,u_int);
        Armour(std::string,float,u_int, u_int);

        ~Armour();

        void get_attribute(std::deque <std::string> &);

        void get_attribute(char, std::string &);

        void inspect();
    };

    class Defensive_Item : public Non_Stackable {
    protected:
        const std::string type = "Defensive_Item";
        Item::Effect item_effect;
        u_int protection;
        bool isWearable;
        bool isTwoHanded;

        void set_attribute(char, std::string);

    public:
        Defensive_Item& operator=(const Defensive_Item &);
        bool operator==(Defensive_Item &);
        bool operator!=(Defensive_Item &);

        Defensive_Item();
        Defensive_Item(const Defensive_Item &);

        Defensive_Item(std::string);
        Defensive_Item(std::string,float);
        Defensive_Item(std::string,float,u_int);
        Defensive_Item(std::string,float,u_int, bool, bool);
        Defensive_Item(std::string,float,u_int, u_int,u_int,u_int);
        Defensive_Item(std::string,float,u_int, u_int,u_int,u_int, bool);
        Defensive_Item(std::string,float,u_int, u_int,u_int,u_int, bool, bool);

        ~Defensive_Item();

        void get_attribute(std::deque <std::string> &);

        void get_attribute(char, std::string &);

        void inspect();
    };

    class Weapon : public Non_Stackable {
    protected:
        const std::string type = "Weapon";
        u_int weapon_type;
        u_int damage;
        bool isTwoHanded;

        virtual void set_attribute(char, std::string) = 0;

    public:
        virtual void get_attribute(std::deque <std::string> &) = 0;

        virtual void get_attribute(char, std::string &) = 0;

        virtual void inspect() = 0;
    };

    class Melee_Weapon : public Weapon {
    protected:
        const std::string type = "Melee_Weapon";
        void set_attribute(char, std::string);

    public:

        Melee_Weapon& operator=(const Melee_Weapon &);
        bool operator==(Melee_Weapon &);
        bool operator!=(Melee_Weapon &);

        Melee_Weapon();
        Melee_Weapon(const Melee_Weapon &);

        Melee_Weapon(std::string);
        Melee_Weapon(std::string,float);
        Melee_Weapon(std::string,float,u_int, u_int);
        Melee_Weapon(std::string,float,u_int, u_int, bool);

        ~Melee_Weapon();

        void get_attribute(std::deque <std::string> &);

        void get_attribute(char, std::string &);

        void inspect();
    };

    class Ranged_Weapon : public Weapon {
    protected:
        const std::string type = "Ranged_Weapon";
        u_int range;

        void set_attribute(char, std::string);

    public:

        Ranged_Weapon& operator=(const Ranged_Weapon &);
        bool operator==(Ranged_Weapon &);
        bool operator!=(Ranged_Weapon &);

        Ranged_Weapon();
        Ranged_Weapon(const Ranged_Weapon &);

        Ranged_Weapon(std::string);
        Ranged_Weapon(std::string,float);
        Ranged_Weapon(std::string,float,u_int, u_int);
        Ranged_Weapon(std::string,float,u_int, u_int, bool);
        Ranged_Weapon(std::string,float,u_int, u_int, u_int);
        Ranged_Weapon(std::string,float,u_int, u_int, u_int, bool);

        ~Ranged_Weapon();

        void get_attribute(std::deque <std::string> &);

        void get_attribute(char, std::string &);

        void inspect();
    };

}


#endif