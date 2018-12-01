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

#ifndef _MEMORY_
#define _MEMORY_
#include <memory>
#endif

namespace Node {
    class Node {
        public:
          Node(std::string type, std::string show);

          Node(std::string type, std::string show, bool isItem);

          Node(std::string type,
               std::string show,
               std::function<void (std::shared_ptr<Node>, std::shared_ptr<Character::Character>)> func,
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
          inline bool isVisiable() {
              return visible;
          };

          inline void npvar(std::string varName){
            switch (hash_(varName.c_str())){
              case "touchable"_hash:
                this->touchable = false;
                break;
              case "visible"_hash:
                this->visible = false;
                break;
              case "triggerable"_hash:
                this->triggerable = false;
                break;
              case "diviable"_hash:
                this->diviable = false;
                break;
            }
          };

          inline void ypvar(std::string varName){
            switch (hash_(varName.c_str())){
              case "visible"_hash:
                this->visible = false;
                break;
            }
          };

          inline void trigger(std::shared_ptr<Character::Character> c) {
            (this->func)(std::shared_ptr<Node>(this), c);
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
          std::function<void(std::shared_ptr<Node>, std::shared_ptr<Character::Character>)> func;
    };
}

namespace NewNode {
  std::shared_ptr<Node::Node> Node(std::string, std::string);
  std::shared_ptr<Node::Node> Brick(int coin);
  std::shared_ptr<Node::Node> newChanceBlock(std::function<void(std::shared_ptr<Character::Character>)>);
  std::shared_ptr<Node::Node> newKongMingBrick(int coin, std::function<void(std::shared_ptr<Character::Character>)>);
}

#ifndef _NODES_CPP_
#define _NODES_CPP_
#include "nodes.cpp"
#endif
