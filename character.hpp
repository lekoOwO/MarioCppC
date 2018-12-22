#ifndef _CHARACTER_
#define _CHARACTER_

#ifndef _STRING_
#define _STRING_
#include <string>
#endif

#ifndef _VECTOR_
#define _VECTOR_
#include <vector>
#endif


namespace Character {
    const int COIN_TO_SCORE = 100;
    const int INIT_LIFE = 3;
    using charSymbol = std::vector<std::string>;

    class Character {
        public:
          Character(std::string name, charSymbol symbol = {"Ⓜ"});
          inline charSymbol getSymbol() { return this->symbol; }
          inline int getLife() { return this->life; };
          inline int getCoin() { return this->coin; };
          inline int getScore() { return this->score; };
          void finishGame(int point = 0);
          void nextStage();
          void die();
          void reset();
          int addLife(int value = 1);
          int addCoin(int value = 1);
          inline void startGame() { this->finishedGame = false; };
          inline bool gameStatus() { return this->finishedGame; };
          inline int getHeight() { return this->height;}

        protected:
          std::string name;
          charSymbol symbol;
          int life = INIT_LIFE;
          int coin = 0;
          int score = 0;
          bool finishedGame = false;
          int height;
          int width;
    };
}

#include "character.cpp"
#endif
