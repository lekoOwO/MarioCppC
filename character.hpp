#ifndef _CHARACTER_
#define _CHARACTER_
#endif

#ifndef _STRING_
#define _STRING_
#include <string>
#endif

#ifndef _VECTOR_
#define _VECTOR_
#include <vector>
#endif

namespace Character {
    using charSymbol = std::vector<std::string>;
    class Character {
        public:
          Character(std::string name, charSymbol symbol);
          inline charSymbol getSymbol() { return this->symbol; }
          inline int getLife() { return this->life; };
          inline int getCoin() { return this->coin; };
          void finishGame(int point);
          int addLife(int value);
          int addCoin(int value);
          inline void startGame() { this->finishedGame = false; };
          inline bool gameStatus() { return this->finishedGame; };
          inline int getHeight() { return this->height;}

        protected:
          std::string name;
          charSymbol symbol;
          int life = 5;
          int coin = 0;
          int score = 0;
          bool finishedGame = false;
          int height;
          int width;
    };
}

#ifndef _CHARACTER_CPP_
#define _CHARACTER_CPP_
#include "character.cpp"
#endif
