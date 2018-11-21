#ifndef _NODES_CPP_
#define _NODES_CPP_
#endif

#ifndef _NODES_
#define _NODES_
#include "nodes.hpp"
#endif

namespace Node {
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
}



namespace NewNode {
    class Node::Node* Node(std::string type, std::string show) {
        return new Node::Node(type, show);
    }

    class Node::Node* Brick(int coin) {
        return new Node::Node(
            "Brick", 
            "🅱", 
            [coin](class Node::Node* x, Character* c) { 
                c->addCoin(coin);
                x->npvar("touchable");
                x->npvar("visible");
                x->npvar("triggerable");
            }, 
            true, 
            "　"
            );
        }

    class Node::Node* newChanceBlock(std::function<void(Character*)> func) {
        return new Node::Node(
            "ChanceBlock",
            "⍰",
            [func](class Node::Node* x, Character *c) {
                func(c);
                x->npvar("triggerable");
            },
            true,
            "⬛");
    }

    class Node::Node* newKongMingBrick(int coin = -1, std::function<void(Character*)> func = nullptr) {
        return new Node::Node(
            "KongMingBrick", 
            "▨", 
            [coin, func](class Node::Node* x, Character* c) { 
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

    class Node::Node* NullNode = new Node::Node("NullNode", "　");
    class Node::Node* Ground = new Node::Node("Ground", "▧");
    class Node::Node* Flag = new Node::Node(
        "Flag", 
        "▎", 
        [](class Node::Node* x, Character *c) {
            c->finishGame(0);
        },
        true
        );

    class Node::Node* FlagHead = new Node::Node(
        "FlagHead", 
        "▲", 
        [](class Node::Node* x, Character *c) {
            c->finishGame(1);
        },
        true
        );
    class Node::Node* Tube = new Node::Node("Tube", "▥");
    class Node::Node* Tubehead = new Node::Node("Tubehead", "═");
    class Node::Node* Coin = new Node::Node("Coin", "＄", true);
}

