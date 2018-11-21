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

#ifndef _CHARACTER_CPP_
#define _CHARACTER_CPP_
#include "character.cpp"
#endif

class Character {
    public:
      Character(std::string name, std::vector<std::string> symbol);
      inline std::vector<std::string> getSymbol() { return this->symbol; }
      inline int getLife() { return this->life; };
      inline int getCoin() { return this->coin; };
      void finishGame(int point);
      int addLife(int value);
      int addCoin(int value);

    protected:
      std::string name;
      std::vector<std::string> symbol;
      int life = 5;
      int coin = 0;
};