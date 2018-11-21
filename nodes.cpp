#ifndef _NODES_CPP_
#define _NODES_CPP_
#endif

#ifndef _NODES_
#define _NODES_
#include "nodes.hpp"
#endif

Node::Node(std::string type, std::string show) {
        this->type = type;
        this->symbol = show;
      };

Node::Node(const char* type, std::string show, bool isItem) {
    this->type = "item";
    this->symbol = show;
    switch (hash_(type)) {
        case hash_compile_time("Coin") :
            this->triggerable = true;
            this->func = [](Node *x, Character *c) {
                c->addCoin(1);
                x->npvar("touchable");
                x->npvar("visible");
                x->npvar("triggerable");
            };
            break;
        };
};

Node::Node(std::string type,
           std::string show,
           std::function<void(Node*, Character*)> func,
           bool triggerable = true,
           std::string symbolForRefresh = "") {
             if (type == "KongMingBrick") {
               this->visible = false;
               this->touchable = false;
             }

             this->type = type;
             this->symbol = show;
             this->func = func;
             if (triggerable) {
               this->triggerable = true;
               this->symbolForRefresh = symbolForRefresh == "" ? show : symbolForRefresh;
             } else {
               this->diviable = true;
             }
        
      };

namespace NewNode {
    ::Node* Node(std::string type, std::string show) {
        return new ::Node(type, show);
    }

    ::Node* Brick(int coin) {
        return new ::Node(
            "Brick", 
            "🅱", 
            [coin](::Node* x, Character* c) { 
                c->addCoin(coin);
                x->npvar("touchable");
                x->npvar("visible");
                x->npvar("triggerable");
            }, 
            true, 
            "　"
            );
        }

    ::Node* newChanceBlock(std::function<void(Character*)> func) {
        return new ::Node(
            "ChanceBlock",
            "⍰",
            [func](::Node *x, Character *c) {
                func(c);
                x->npvar("triggerable");
            },
            true,
            "⬛");
    }

    ::Node* newKongMingBrick(int coin = -1, std::function<void(Character*)> func = nullptr) {
        return new ::Node(
            "KongMingBrick", 
            "▨", 
            [coin, func](::Node* x, Character* c) { 
                if (coin == -1) {
                    c->addCoin(coin);
                } else {
                    func(c);
                }
                c->addCoin(coin);
                x->ypvar("visible");
                x->npvar("triggerable");
            }, 
            true, 
            "▨"
            );
    }

    ::Node *NullNode = new ::Node("NullNode", "　");
    ::Node *Ground = new ::Node("Ground", "▧");
    ::Node *Flag = new ::Node(
        "Flag", 
        "▎", 
        [](::Node *x, Character *c) {
            c->finishGame(0);
        },
        true
        );

    ::Node *FlagHead = new ::Node(
        "FlagHead", 
        "▲", 
        [](::Node *x, Character *c) {
            c->finishGame(1);
        },
        true
        );
    ::Node *Tube = new ::Node("Tube", "▥");
    ::Node *Tubehead = new ::Node("Tubehead", "═");
    ::Node *Coin = new ::Node("Coin", "＄", true);
}

