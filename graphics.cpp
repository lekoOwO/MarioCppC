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
    std::vector<std::vector<std::string>> result(stage.size());
    for (int i = 0; i < stage.size(); i++){
        auto line = stage[i];
        result[i].resize(line.size());
        for (int j = 0; j < line.size(); j++){
            auto nodeptr = line[j];
            result[i][j] = nodeptr->getSymbol();
        }
    }
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
    for (int i = size(graphicStageV) - 1; i >= 0; i--) {
        for (auto e: graphicStageV[i]) {
            std::cout << e;
        }
        std::cout << std::endl;
    }
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