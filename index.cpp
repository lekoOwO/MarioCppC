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

#ifndef _WINDOWS_H_
#define _WINDOWS_H_
#include <windows.h>
#endif

#include "menu.hpp"

#include<iomanip>
using namespace std;

const int JUMP_HEIGHT = 3;

char ProcessStdin()
{
    INPUT_RECORD ir;
    DWORD numRead;
    if(!ReadConsoleInput(hIn, &ir, 1, &numRead)) {
        // hmm handle this error somehow...
        return '0';
    }

    if(ir.EventType != KEY_EVENT) {
        // don't care about other console events
        return '0';
    }

    if (!ir.Event.KeyEvent.bKeyDown) {
        return '0';
    };

    switch (ir.Event.KeyEvent.wVirtualKeyCode)
    {
        case VK_ESCAPE:
            return '0';
            break;
        case VK_DOWN:
            return '2';
            break;
        case VK_LEFT:
            return '1';
            break;
        case VK_RIGHT:
            return '3';
            break;
        case VK_UP:
            return '5';
            break;
        default:
            return '0';
    }
    // record.Event.KeyEvent.uChar.AsciiChar

}

char getch(int timeout = 50) {
    switch( WaitForSingleObject( hIn, timeout ) ) {
        case( WAIT_TIMEOUT ):
            break; // return from this function to allow thread to terminate
        case( WAIT_OBJECT_0 ):
            return ProcessStdin();
            break;
        case( WAIT_FAILED ):
            break;
        case( WAIT_ABANDONED ): 
            break;
        default:
            break;
        }
    return '0';
}

coord marioCoord = {3, 0};
void resetMarioCoord(){
    marioCoord = {3, 0};
}
int upCount = 0;
bool reGraphic = true;

void right(stage& stage1, std::shared_ptr<Character::Character> mario){
    auto side = Side::RIGHT;
    bool isBlocked = false;
    for (int i = 0; i < mario->getHeight(); i++) {
        int result = collide(stage1[marioCoord.first + i][marioCoord.second + 1], side, mario);
        if (!result) {
            isBlocked = true;
            break;
        }
    }
    if (!isBlocked) marioCoord.second++;
}

void left(stage& stage1, std::shared_ptr<Character::Character> mario){
    auto side = Side::LEFT;
    bool isBlocked = false;
    for (int i = 0; i < mario->getHeight(); i++) {
        int result = collide(stage1[marioCoord.first + i][marioCoord.second - 1], side, mario);
        if (!result) {
            isBlocked = true;
            break;
        }
    }
    if (!isBlocked) marioCoord.second--;
}

void airMove(stage& stage1, std::shared_ptr<Character::Character> mario, char inputChar = '0'){
    auto in = inputChar - '0' ? inputChar - '0' : getch(30) - '0';
    switch (in) {
        case 3:
            right(stage1, mario);
            break;
        case 1:
            left(stage1, mario);
            break;
        default:
            break;
    }
}

void up(stage& stage1, std::shared_ptr<Character::Character> mario){
    auto side = Side::UP;
    int result = collide(stage1[marioCoord.first + mario->getHeight()][marioCoord.second], side, mario);
    if (result){
        marioCoord.first++;
        airMove(stage1, mario);
        upCount = JUMP_HEIGHT - 1;
    }
}

void hideCursor(HANDLE hOut){
    CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(hOut, &CursorInfo);
    CursorInfo.bVisible = false;
    SetConsoleCursorInfo(hOut, &CursorInfo);
}

int game(stage stage1, std::shared_ptr<Character::Character> mario){
    do
        {
            if (reGraphic) graphic(stage1, mario, marioCoord);
            reGraphic = true;

            if (!marioCoord.first){ // 馬力歐死了
                mario->die();
                resetMarioCoord();
                if (mario->getLife() < 0){
                    clear();

                    cout<<"game over";
                    cin.get();
                    
                    return 0;
                }
                continue;
            }
            auto inputChar = getch(10);
            if (upCount > 0) { // 處理跳躍還在進行中的狀況
                auto side = Side::UP;
                int result = collide(stage1[marioCoord.first + mario->getHeight()][marioCoord.second], side, mario);
                if (result){
                    marioCoord.first++;
                    airMove(stage1, mario, inputChar);
                    upCount--;
            } else {
                upCount = 0;
            }
            continue;
        } else { // 如果下面的東西踏不上去的話就往下掉，期間可操作角色
            int result = collide(stage1[marioCoord.first - 1][marioCoord.second], Side::DOWN, mario);
            if (result) {
                airMove(stage1, mario, inputChar);
                int result = collide(stage1[marioCoord.first - 1][marioCoord.second], Side::DOWN, mario);
                if (result) {
                    marioCoord.first--;
                    continue;
                }
            }
        }

            switch (inputChar) {
                case '0':
                    reGraphic = false;
                    break;
                case '5': {
                    up(stage1, mario);
                    break;
                }
                case '3': {
                    right(stage1, mario);
                    break;
                }
                case '1': {
                    left(stage1, mario);
                    break;
                }
                    
            }
    } while (!mario->gameStatus());
    mario->nextStage();
    return 1;
}
    
int main(){
    setvbuf(stdout, nullptr, _IOFBF, 1000);
    SetConsoleOutputCP(CP_UTF8);

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    hIn = GetStdHandle(STD_INPUT_HANDLE);

    hideCursor(hOut);

    SetConsoleSize(hOut, 1400, 600);

    TITLE(hOut);
    IMAGE(hOut);
    cin.get(); // 阻塞程序運行

    int stageCount = 1;

    auto stage = readMap(stageCount);
    auto mario = std::make_shared<Character::Character>("Mario");
    

    clear();

    cout<<"stage "<<stageCount;
    cin.get();

    int result = game(stage, mario);
    while(result && mapExist(++stageCount)){
        stage = readMap(stageCount);

        clear();
        cout<<"stage "<<stageCount;
        cin.get();

        result = game(stage, mario);
    }
    return 0;
        
}