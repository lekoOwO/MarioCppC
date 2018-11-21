#ifndef _NODES_
#define _NODES_
#endif

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

#ifndef _SWITCH_STRING_
#define _SWITCH_STRING_
#include "switch_string.hpp"
#endif

#ifndef _NODES_CPP_
#define _NODES_CPP_
#include "nodes.cpp"
#endif

namespace Node {
    class Node {
        public:
          Node(std::string type, std::string show);

          Node(const char* type, std::string show, bool isItem);

          Node(std::string type,
              std::string show,
              std::function<void(Node *, Character *)> func,
              bool triggerable,
              std::string symbolForRefresh);

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

          inline void npvar(const char* varName){
            switch (hash_(varName)){
              case hash_compile_time("touchable"):
                this->touchable = false;
                break;
              case hash_compile_time("visible"):
                this->visible = false;
                break;
              case hash_compile_time("triggerable"):
                this->triggerable = false;
                break;
              case hash_compile_time("diviable"):
                this->diviable = false;
                break;
            }
          }

          inline void ypvar(const char* varName){
            switch (hash_(varName)){
              case hash_compile_time("visible"):
                this->visible = false;
                break;
            }
          }

          inline void trigger(Character* c) {
            (this->func)(this, c);
            (this->refreshSymbol)();
          };

        protected:
          std::string symbol;
          std::string type;
          std::string symbolForRefresh = "　";
          bool touchable = true;
          bool visible = true;
          bool triggerable = false;
          bool diviable = false;
          inline void refreshSymbol() {
            this->symbol = this->symbolForRefresh;
          };
          std::function<void(Node*, Character*)> func;
    };
}

namespace NewNode {
    class Node::Node* Node(std::string type, std::string show);
    class Node::Node* Brick(int coin);
    class Node::Node* newChanceBlock(std::function<void(Character *)> func);
    class Node::Node* newKongMingBrick(int coin, std::function<void(Character *)> func);
}
