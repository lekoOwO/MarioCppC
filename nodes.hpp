#ifndef _STRING_
#define _STRING_
#include <string>
#endif

#ifndef _CHARACTER_
#define _CHARACTER_
#include "character.hpp"
#endif

#ifndef _FUNCTIONAL_
#define _FUNCTIONAL_
#include <functional>
#endif

class Node {
    public:
      Node(std::string show);
      inline std::string getSymbol() {
          return symbol;
      };

      inline bool isTouchable() {
          return touchable;
      };
      inline bool isTriggerable() {
          return triggerable;
      };
      inline bool isDiviable(){
          return diviable;
      };

    protected:
      std::string symbol;
      bool touchable = true;
      bool visible = true;
      bool triggerable = false;
      bool diviable = false;
};

class NullNode : protected Node {
    public:
      NullNode();

    protected:
      bool touchable = false;
      bool visible = false;
      bool triggerable = false;
      bool diviable = false;
};

class TriggerableNode : protected Node {
    public:
      TriggerableNode(std::string show) : Node(show){};
      virtual void trigger(Character c);

    protected:
      bool triggerable = true;
      void refreshSymbol(std::string show);
};

class Brick : protected TriggerableNode {
    public:
      Brick(int coin = 0);
      void trigger(Character c);

    protected:
      int coin = 0;
};

class ChanceBlock : protected TriggerableNode {
    public:
      ChanceBlock(std::function<void(Character)> f);
      void trigger(Character c);

    protected: 
      std::function<void(Character)> func;
};

class KongMingBrick : protected TriggerableNode {
    public:
      KongMingBrick(int coin = 1);
      KongMingBrick(std::function<void(Character)> f);
      void trigger(Character c);

    protected:
      bool visible = false;
      int coin = -1;
      std::function<void(Character)> func;
};

class Ground : protected Node {
    public:
      Ground();
};

class Flag : protected Node {
    public:
      Flag();
};

class Flaghead : protected Node {
    public:
      Flaghead();
};

class Tube : protected Node {
    public:
      Tube();
};

class Tubehead : protected Node {
    public:
      Tubehead();

    protected:
      bool diviable = false;
};
