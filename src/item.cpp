
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