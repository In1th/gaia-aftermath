/* ===========================================
 * character.h file
 * ===========================================
 * author: Mateusz Kruk
 * e-mail: krukm634@gmail.com
 * last modified: 29.05.2021
 * ===========================================
 * version: 0.1.1-a.1 [conversation]
 * ===========================================
 */

#include "item.h"
#include "eq.h"

class Character {

    private:
        std::string name;

        //atributes
        int HP;
        u_int STR;
        u_int DEX;
        u_int CON;
        u_int INT;
        u_int WILL;
        u_int CHA;

        //data containers
        Limited_Stack<item_ptr, 5> armour;
        Limited_Stack<item_ptr, 2> hands;
        Stack<Item::Effect> eff_list;

        void set_attribute(char, std::string);

    public:

        explicit Character(std::string, int, int, int, int, int, int, int);

        void get_attribute(std::deque <std::string> &);

        void get_attribute(char, std::string &);

        void inspect();

};