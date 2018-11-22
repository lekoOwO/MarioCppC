#ifndef _CHARACTER_CPP_
#define _CHARACTER_CPP_
#endif

#ifndef _CHARACTER_
#define _CHARACTER_
#include "character.hpp"
#endif

const int COIN_TO_SCORE = 100;

namespace Character {
    Character::Character(std::string name, charSymbol symbol = {"Ⓜ", "⬜"}) {
        this->name = name;
        this->symbol = symbol;
    }

    int Character::addLife(int value = 1) {
        this->life += value;
        return this->life;
    }

    int Character::addCoin(int value = 1) {
        this->coin += value;
        this->score += COIN_TO_SCORE * 100;
        while (this->coin >= 100) {
            (this->addLife)(1);
            this->coin -= 100;
        }
        return this->coin;
    }

    void Character::finishGame(int point = 0){}
}

