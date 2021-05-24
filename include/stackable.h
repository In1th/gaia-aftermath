/* ===========================================
 * stackable.h file
 * ===========================================
 * author: Mateusz Kruk
 * e-mail: krukm634@gmail.com
 * last modified: 25.05.2021
 * ===========================================
 * version: 0.1.0-a.1 [backpack]
 * ===========================================
 */

#ifndef STACK_H
#define STACK_H

#include "item.h"
#include "format.h"

namespace Item{
 
 class Stackable : public Instance {
    protected:
        const std::string type = "Stackable";
        unsigned int quantity;
        unsigned int QUANTITY_CAP;

        void set_attribute(char, std::string);

    public:

        Stackable& operator=(const Stackable &);
        Stackable& operator+=(Stackable &);
        Stackable& operator-=(Stackable &);

        Stackable();
        Stackable(const Stackable &);

        Stackable(std::string);
        Stackable(std::string,float);
        Stackable(std::string,float,u_int);
        Stackable(std::string,float,u_int,u_int);

        ~Stackable();

        void get_attribute(std::deque <std::string> &);

        void get_attribute(char, std::string &);

        void inspect();
    };

class Consumable : public Stackable {
    protected:
        const std::string type = "Consumable";
        Item::Effect item_effect;
        void set_attribute(char, std::string);

    public:

        Consumable& operator=(const Consumable &);
        Consumable& operator+=(Consumable &);
        Consumable& operator-=(Consumable &);

        Consumable();
        Consumable(const Consumable &);

        Consumable(std::string);
        Consumable(std::string,float);
        Consumable(std::string,float,u_int);
        Consumable(std::string,float,u_int,u_int);
        Consumable(std::string,float,u_int, u_int, u_int, u_int, u_int);

        ~Consumable();

        void get_attribute(std::deque <std::string> &);

        void get_attribute(char, std::string &);

        void inspect();
    };

 }

 #endif