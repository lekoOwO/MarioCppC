#ifndef _GRAPHICS_CPP_
#define _GRAPHICS_CPP_
#endif

#ifndef _GRAPHICS_
#define _GRAPHICS_
#include "graphics.hpp"
#endif

const int SPRINK_SECOND = 1;

void clear() {
    COORD topLeft  = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
        console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    FillConsoleOutputAttribute(
        console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    SetConsoleCursorPosition(console, topLeft);
};

std::vector<std::vector<std::string>> stageToGraphic(stage stage) {
    std::vector<std::vector<std::string>> result;
    for (auto line: stage) {
        std::vector<std::string> res;
        for (auto nodeptr: line) {
            res.push_back(nodeptr->getSymbol());
        }
        result.push_back(res);
    }
    // std::transform(stage.begin(), stage.end(), result.begin(), [](auto line) {
    //     std::vector<std::string> res;
    //     std::transform(line.begin(), line.end(), res.begin(), [](node nodeptr) {
    //         return nodeptr->getSymbol();
    //     });
    //     return res;
    // });
    return result;
};

void graphic(stage stage, Character::charSymbol symbol, coord charCoord){
    auto graphicStageV = stageToGraphic(stage);
    int y = charCoord.first;
    int x = charCoord.second;

    for (auto [e, i] = std::make_tuple(symbol.rbegin(), y); e != symbol.rend(); ++e, ++i) {
        graphicStageV[i][x] = *e;
    };

    clear();
    for (auto e: graphicStageV) {
        for (auto i : e) {
            std::cout << i;
        }
        std::cout << std::endl;
    };
};

void startMenu(){
    std::function<void(bool&)> sprink = [](bool &sprinkMode) {

    };
    std::future<char> getchAsync = std::async(std::launch::async, []() {
        char a;
        std::cin.get(a);
        return a;
    });

    bool sprinkMode = 1;

    std::future_status status;
    do {
        status = getchAsync.wait_for(std::chrono::seconds(1));
        if (status == std::future_status::timeout) {
            sprink(sprinkMode);
            sprinkMode = !sprinkMode;
        }
        else if (status == std::future_status::ready) {
            // go to next stage
        }
    } while (status != std::future_status::ready);
    return;
}