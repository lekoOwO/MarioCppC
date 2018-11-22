#ifndef _NODES_
#define _NODES_
#endif

#ifndef _STRING_
#define _STRING_
#include <string>
#endif

#ifndef _CSTRING_
#define _CSTRING_
#include <cstring>
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
          Node(const char* type, const char* show);

          Node(const char* type, const char* show, bool isItem);

          Node(const char* type,
               const char* show,
               std::function<void(Node* , class Character::Character*)> func,
               bool triggerable,
               const char* symbolForRefresh);

          inline const char* getSymbol() {
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

          inline void npvar(const char* varName){
            switch (hash_(varName)){
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
          }

          inline void ypvar(const char* varName){
            switch (hash_(varName)){
              case "visible"_hash:
                this->visible = false;
                break;
            }
          }

          inline void trigger(class Character::Character* c) {
            (this->func)(this, c);
            (this->refreshSymbol)();
          };

        protected:
          const char* symbol;
          const char* type;
          const char* symbolForRefresh = "　";
          bool touchable = true;
          bool visible = true;
          bool triggerable = false;
          bool diviable = false;
          inline void refreshSymbol() {
            this->symbol = this->symbolForRefresh;
          };
          std::function<void(Node*, class Character::Character*)> func;
    };
}

namespace NewNode {
  std::unique_ptr<class Node::Node> Node(const char*, const char* );
  std::unique_ptr<class Node::Node> Brick(int );
  std::unique_ptr<class Node::Node> newChanceBlock(std::function<void(class Character::Character *)>);
  std::unique_ptr<class Node::Node> newKongMingBrick(int coin, std::function<void(class Character::Character *)>);
}

#ifndef _NODES_CPP_
#define _NODES_CPP_
#include "nodes.cpp"
#endif
