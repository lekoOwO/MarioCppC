#ifndef _STRING_
#define _STRING_
#include <string>
#endif

#ifndef _VECTOR_
#define _VECTOR_
#include <vector>
#endif

class Character {
    public:
      Character(std::string name, std::vector<std::string> symbol);
      inline std::vector<std::string> getSymbol() { return this->symbol; }
      inline int getLife() { return this->life; };
      inline int getCoin() { return this->coin; };
      int addLife(int value);
      int addCoin(int value);

    protected:
      std::string name;
      std::vector<std::string> symbol;
      int life = 5;
      int coin = 0;
};