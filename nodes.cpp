#ifndef _NODES_
#define _NODES_
#include "nodes.hpp"
#endif

Node::Node(std::string show) {
    this->symbol = show;
};

Brick::Brick(int coin) : TriggerableNode("🅱")
{
    this->coin = coin;
};

void Brick::trigger(Character c) {
    c.addCoin(this->coin);
    this->touchable = false;
    this->visible = false;
    this->triggerable = false;
};

ChanceBlock::ChanceBlock(std::function<void(Character)> f) :  TriggerableNode("⍰") {
    this->func = f;
};

void ChanceBlock::trigger(Character c) {
    (this->func)(c);
    this->refreshSymbol(std::string("⬛"));
    this->triggerable = false;
};

KongMingBrick::KongMingBrick(int coin) : TriggerableNode("▨"){
    this->coin = coin;
};

KongMingBrick::KongMingBrick(std::function<void(Character)> f) :  TriggerableNode("▨") {
    this->func = f;
};

void KongMingBrick::trigger(Character c) {
    if (this->coin > -1) {
        c.addCoin(this->coin);
    } else {
        (this->func)(c);
    }

    this->visible = true;
    this->triggerable = false;
};

NullNode::NullNode() : Node("　"){};
Ground::Ground() : Node("▧"){};
Flag::Flag() : Node("▎"){};
Flaghead::Flaghead() : Node("▲"){};
Tube::Tube() : Node("▥"){};
Tubehead::Tubehead() : Node("═"){};