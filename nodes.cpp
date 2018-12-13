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
            if (type == "NullNode") this->touchable = false;
        };

    Node::Node(std::string type,
               std::string show, 
               bool isItem,
               std::function<void (std::shared_ptr<Node>, std::shared_ptr<Character::Character>)> func) {
        this->type = type;
        this->symbol = show;
        this->func = func;
        this->item = true;
        this->triggerable = true;
    };

    Node::Node(std::string type,
            std::string show,
            std::function<void (std::shared_ptr<Node>, std::shared_ptr<Character::Character>)> func,
            bool triggerable,
            std::string symbolForRefresh) {
                if (type == "KongMingBrick") {
                    this->visible = false;
                    this->touchable = false;
                }

                this->type = type;
                this->symbol = show;
                this->func = func;
                if (triggerable) {
                    this->triggerable = true;
                    this->symbolForRefresh = symbolForRefresh.empty() ? show : symbolForRefresh;
                } else {
                    this->diviable = true;
                }
            
        };
}



namespace NewNode {
    std::shared_ptr<Node::Node> Node(std::string type, std::string show) {
        return std::make_shared<Node::Node>(type, show);
    }

    std::shared_ptr<Node::Node> Brick(int coin) {
        return std::make_shared<Node::Node>(
            "Brick", 
            "🅱", 
            [coin](std::shared_ptr<Node::Node> x, std::shared_ptr<Character::Character> c) { 
                c->addCoin(coin);
                x->npvar("touchable");
                x->npvar("visible");
                x->npvar("triggerable");
            }, 
            true,
            "　"
            );
        }

    std::shared_ptr<Node::Node> newChanceBlock(std::function<void(std::shared_ptr<Character::Character>)> func) {
        return std::make_shared<Node::Node>(
            "ChanceBlock",
            "⍰",
            [func](std::shared_ptr<Node::Node> x, std::shared_ptr<Character::Character> c) {
                func(c);
                x->npvar("triggerable");
            },
            true,
            "⬛");
    }

    std::shared_ptr<Node::Node> newKongMingBrick(int coin, std::function<void(std::shared_ptr<Character::Character>)> func) {
        return std::make_shared<Node::Node>(
            "KongMingBrick", 
            "▨", 
            [coin, func](std::shared_ptr<Node::Node> x, std::shared_ptr<Character::Character> c) {
                if (coin != -1) {
                    c->addCoin(coin);
                } else {
                    func(c);
                }
                x->ypvar("visible");
                x->npvar("triggerable");
            }, 
            true,
            "▨"
            );
    }

    std::shared_ptr<Node::Node> Coin() {
        return std::make_shared<Node::Node>(
            "Coin", 
            "＄", 
            true,
            [](std::shared_ptr<Node::Node> x, std::shared_ptr<Character::Character> c) {
                c->addCoin(1);
                x->npvar("touchable");
                x->npvar("visible");
                x->npvar("triggerable");
            }
            );
    }
}

