#ifndef _CONTROL_SYSTEM_CPP_
#define _CONTROL_SYSTEM_CPP_
#endif

#ifndef _CONTROL_SYSTEM_
#define _CONTROL_SYSTEM_
#include "controlSystem.hpp"
#endif

int collide(node block, Side::side motiveSide, std::shared_ptr<Character::Character> x, bool dive = false) {
    /*
        @brief               Returns the result when a character runs into a block.
        @param block         The pointer of a block.
        @param motiveSide    The side of the character's vector.
        @param x             The pointer of the character.
        @param dive          Whether the character is diving into a tube.

        The process of collision is processed in this function.

        Returns 1 if the character runs over the block.
        Returns 0 if the character is blocked.
        Returns -1 if the chatacter dives into the block.
    */

    if (!block->isTriggerable()) {
        if (!block->isTouchable())
            return 1;
        else if (dive && motiveSide == Side::DOWN && block->isDiviable())
            return -1;
        else
            return 0;
    } else {
        if (block->isItem()) {
            block->trigger(x, block);
            return 1;
        }

        switch (motiveSide){
            case Side::DOWN:
            case Side::LEFT:
            case Side::RIGHT:
                return !block->isTouchable();
                break;
            case Side::UP:
                block->trigger(x, block);
                return 0;
                break;
        }
    }
};
