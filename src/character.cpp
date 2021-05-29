/* ===========================================
 * character.cpp file
 * ===========================================
 * author: Mateusz Kruk
 * e-mail: krukm634@gmail.com
 * last modified: 29.05.2021
 * ===========================================
 * version: 0.1.1-a.1 [conversation]
 * ===========================================
 */

#include "../include/character.h"

#include <iostream>

Character::Character(std::string n, int hp, int str, int dex, int con, int i, int will, int cha) {

    auto is_unsigned = [](auto val) { if(val <= 0) return 1; return val;};

    this -> name = n;
    this -> HP = is_unsigned(hp);
    this -> STR = is_unsigned(str);
    this -> DEX = is_unsigned(dex);
    this -> CON = is_unsigned(con);
    this -> INT = is_unsigned(i);
    this -> WILL = is_unsigned(will);
    this -> CHA = is_unsigned(cha);

}