#ifndef _CHARACTER_
#define _CHARACTER_
#include "character.hpp"
#endif

#ifndef _CONTROL_SYSTEM_
#define _CONTROL_SYSTEM_
#include "controlSystem.hpp"
#endif

#ifndef _GRAPHICS_
#define _GRAPHICS_
#include "graphics.hpp"
#endif

#ifndef _NODES_
#define _NODES_
#include "nodes.hpp"
#endif

#ifndef _IOSTREAM_
#define _IOSTREAM_
#include <iostream>
#endif

#ifndef _CSTDIO_
#define _CSTDIO_
#include <cstdio>
#endif

#ifndef _WINDOWS_H_
#define _WINDOWS_H_
#include <windows.h>
#endif

const int JUMP_HEIGHT = 2;

std::future<char> getchAsync = std::async(std::launch::async, []() {
        char a;
        std::cin.get(a);
        return a;
    });

int main(){
    setvbuf(stdout, nullptr, _IOFBF, 1000);
    SetConsoleOutputCP(CP_UTF8); 
    auto stage1 = readMap("./stages/stage 1-1.json");
    auto mario = std::make_shared<Character::Character>("Mario");
    coord marioCoord = {3, 0};
    int upCount = 0;
    do {
        graphic(stage1, mario->getSymbol(), marioCoord);
        if (upCount > 0) { // 處理跳躍還在進行中的狀況
            auto side = Side::UP;
            int result = collide(stage1[marioCoord.first + mario->getHeight()][marioCoord.second], side, mario);
            if (result){
                marioCoord.first++;
                upCount--;
            } else {
                upCount = 0;
            }
            continue;
        } else { // 如果下面的東西踏不上去的話就往下掉，期間不可操作角色
            int result = collide(stage1[marioCoord.first - 1][marioCoord.second], Side::DOWN, mario);
            if (result) {
                marioCoord.first -= 1;
                continue;
            }
        }

        std::future_status status = getchAsync.wait_for(std::chrono::milliseconds(100));
        auto side = Side::DOWN;
        if (status == std::future_status::ready) {
            switch (getchAsync.get()) {
                case '5': {
                    side = Side::UP;
                    int result = collide(stage1[marioCoord.first + mario->getHeight()][marioCoord.second], side, mario);
                    if (result){
                        marioCoord.first++;
                        upCount = JUMP_HEIGHT - 1;
                    }
                    graphic(stage1, mario->getSymbol(), marioCoord);
                    break;
                }
                case '3': {
                    side = Side::RIGHT;
                    bool isBlocked = false;
                    for (int i = 0; i < mario->getHeight(); i++) {
                        int result = collide(stage1[marioCoord.first + i][marioCoord.second + 1], side, mario);
                        if (result) {
                            isBlocked = true;
                            break;
                        }
                    }
                    if (!isBlocked) marioCoord.second++;
                    graphic(stage1, mario->getSymbol(), marioCoord);
                    break;
                }
                case '1': {
                    side = Side::LEFT;
                    bool isBlocked = false;
                    for (int i = 0; i < mario->getHeight(); i++) {
                        int result = collide(stage1[marioCoord.first + i][marioCoord.second - 1], side, mario);
                        if (result) {
                            isBlocked = true;
                            break;
                        }
                    }
                    if (!isBlocked) marioCoord.second++;
                    graphic(stage1, mario->getSymbol(), marioCoord);
                    break;
                }
                    
            }
        } else if (status == std::future_status::timeout) {
            // std::cout << "timeouted!!" << std::endl;
            continue;
        }
    } while (!mario->gameStatus());
    return 0;
}