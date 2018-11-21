#ifndef _NODES_CPP_
#define _NODES_CPP_
#endif

#ifndef _NODES_
#define _NODES_
#include "nodes.hpp"
#endif

namespace Node {
    Node::Node(const char* type, const char* show) {
            this->type = type;
            this->symbol = show;
        };

    Node::Node(const char* type, const char* show, bool isItem) {
        this->type = "item";
        this->symbol = show;
        switch (hash_(type)) {
            case hash_compile_time("Coin") :
                this->triggerable = true;
                this->func = [](Node* x, class Character::Character *c) {
                    c->addCoin(1);
                    x->npvar("touchable");
                    x->npvar("visible");
                    x->npvar("triggerable");
                };
                break;
            };
    };

    Node::Node(const char* type,
            const char* show,
            std::function<void(Node*, class Character::Character*)> func,
            bool triggerable = true,
            const char* symbolForRefresh = "") {
                if (strncmp(type, "KongMingBrick", 13) == 0) {
                this->visible = false;
                this->touchable = false;
                }

                this->type = type;
                this->symbol = show;
                this->func = func;
                if (triggerable) {
                this->triggerable = true;
                this->symbolForRefresh = strncmp(symbolForRefresh, "", 1) == 0 ? show : symbolForRefresh;
                } else {
                this->diviable = true;
                }
            
        };
}



namespace NewNode {
    std::unique_ptr<class Node::Node> Node(const char* type, const char* show) {
        return std::unique_ptr<class Node::Node>(new class Node::Node(type, show));
    }

    std::unique_ptr<class Node::Node> Brick(int coin) {
        return std::unique_ptr<class Node::Node>(new class Node::Node(
            "Brick", 
            "🅱", 
            [coin](auto x, auto c) { 
                c->addCoin(coin);
                x->npvar("touchable");
                x->npvar("visible");
                x->npvar("triggerable");
            }, 
            true,
            "　"
            ));
        }

    std::unique_ptr<class Node::Node> newChanceBlock(std::function<void(class Character::Character*)> func) {
        return std::unique_ptr<class Node::Node>(new class Node::Node(
            "ChanceBlock",
            "⍰",
            [func](auto x, auto c) {
                func(c);
                x->npvar("triggerable");
            },
            true,
            "⬛"));
    }

    std::unique_ptr<class Node::Node> newKongMingBrick(int coin = -1, std::function<void(class Character::Character*)> func = nullptr) {
        return std::unique_ptr<class Node::Node>(new class Node::Node(
            "KongMingBrick", 
            "▨", 
            [coin, func](auto x, auto c) {
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
            ));
    }

    auto NullNode = std::make_shared<class Node::Node>(new class Node::Node("NullNode", "　"));
    auto Ground = std::make_shared<class Node::Node>(new class Node::Node("Ground", "▧"));

    auto FlagHead = std::make_shared<class Node::Node>(new class Node::Node(
        "FlagHead", 
        "▲", 
        [](auto x, auto *c) {
            c->finishGame(1);
        },
        true,
        "▲"
        ));

    auto Flag = std::make_shared<class Node::Node>(new class Node::Node(
        "Flag", 
        "▎", 
        [](auto x, auto c) {
            c->finishGame(0);
        },
        true,
        "▎"
        ));
    
    auto Tube = std::make_shared<class Node::Node> (new class Node::Node("Tube", "▥"));
    auto Tubehead = std::make_shared<class Node::Node> (new class Node::Node("Tubehead", "═"));
    auto Coin = std::make_shared<class Node::Node> (new class Node::Node("Coin", "＄", true));
}

