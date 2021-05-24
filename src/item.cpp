/* ===========================================
 * item.cpp file
 * ===========================================
 * author: Mateusz Kruk
 * e-mail: krukm634@gmail.com
 * last modified: 25.05.2021
 * ===========================================
 * version: 0.1.0-a.1 [backpack]
 * ===========================================
 */

#include "../include/item.h"

bool Item::Effect::operator==(Item::Effect e) {

    if (this -> effect != e.effect             ||
        this -> effect_level != e.effect_level ||
        this -> duration != e.duration         )
        return false;

    return true;
}

bool Item::Effect::operator!=(Item::Effect e) {
    return !(*this == e);
}