#ifndef _CHARACTER_CPP_
#define _CHARACTER_CPP_
#endif

#ifndef _CHARACTER_
#define _CHARACTER_
#include "character.hpp"
#endif

Character::Character(std::string name, std::vector<std::string> symbol = {"Ⓜ", "⬜"}) {
    this->name = name;
    this->symbol = symbol;
}

int Character::addLife(int value = 1) {
    this->life += value;
    return this->life;
}

int Character::addCoin(int value = 1) {
    this->coin += value;
    while (this->coin >= 100) {
        (this->addLife)(1);
        this->coin -= 100;
    }
    return this->coin;
}

void Character::finishGame(int point = 0){}