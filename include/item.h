/* ===========================================
 * item.h file
 * ===========================================
 * author: Mateusz Kruk
 * e-mail: krukm634@gmail.com
 * last modified: 25.05.2021
 * ===========================================
 * version: 0.1.0-a.1 [backpack]
 * ===========================================
 */

#ifndef ITEMS_H
#define ITEMS_H

#ifndef LIBS
#define LIBS

#include <iostream>
#include <deque>
#include <string>

#endif


#define class_name(x) typeid(x).name()

//macro for error displaying (items.h:19)
#define error(message)       \
        print <<         \
        "An error occured: " \
        << message <<        \
        eol;           \
        throw;

//macro for setting an int from a string
#define to_int(variable, value)          \
        try {                            \
            variable = std::stoi(value); \
        }                                \
        catch (std::exception &e) {      \
            error(e.what())              \
        }                                 

//macro for setting a bool from a string
#define to_bool(variable,value)                                        \
    if (value == "1" || value == "true" || value == "True")            \
        variable = true;                                               \
    else if (value == "0" || value == "false" || value == "False")     \
        variable = false;                                              \
    else                                                               \
        error("bool conversion")


namespace Item {

    class Instance {

    protected:
        std::string type;
        std::string name;
        float value;

        virtual void set_attribute(char, std::string) = 0;

    public:

        virtual void get_attribute(std::deque <std::string> &) = 0;

        virtual void get_attribute(char, std::string &) = 0;

        virtual void inspect() = 0;

    };

    class Effect {
        public:
            u_int effect;
            u_int effect_level;
            u_int duration;

            bool operator!=(Effect);
            bool operator==(Effect);
    };

}

typedef Item::Instance *item_ptr;


#endif
