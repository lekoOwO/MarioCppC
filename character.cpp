#ifndef _CHARACTER_CPP_
#define _CHARACTER_CPP_

namespace Character {
    Character::Character(std::string name, charSymbol symbol) {
        this->name = name;
        this->symbol = symbol;
        this->height = symbol.size();
        this->width = symbol[0].size();
    }

    void Character::reset(){
        this->life = INIT_LIFE;
        this->coin = 0;
        this->score = 0;
        this->finishedGame = false;
    }

    int Character::addLife(int value) {
        this->life += value;
        return this->life;
    }

    int Character::addCoin(int value) {
        this->coin += value;
        this->score += COIN_TO_SCORE * 100;
        while (this->coin >= 100) {
            (this->addLife)(1);
            this->coin -= 100;
        }
        return this->coin;
    }

    void Character::finishGame(int point){
        this->finishedGame = true;
    }

    void Character::die(){
        this->life--;
    }

    void Character::nextStage(){
        this->finishedGame = false;
    }
}
#endif
