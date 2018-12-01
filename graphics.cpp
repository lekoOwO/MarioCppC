#ifndef _GRAPHICS_CPP_
#define _GRAPHICS_CPP_
#endif

#ifndef _GRAPHICS_
#define _GRAPHICS_
#include "graphics.hpp"
#endif

const int SPRINK_SECOND = 1;

void clear() {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD                      count;
  DWORD                      cellCount;
  COORD                      homeCoords = { 0, 0 };

  if (hOut == INVALID_HANDLE_VALUE) return;

  /* Get the number of cells in the current buffer */
  if (!GetConsoleScreenBufferInfo( hOut, &csbi )) return;
  cellCount = csbi.dwSize.X *csbi.dwSize.Y;

  /* Fill the entire buffer with spaces */
  if (!FillConsoleOutputCharacter(
    hOut,
    (TCHAR) ' ',
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Fill the entire buffer with the current colors and attributes */
  if (!FillConsoleOutputAttribute(
    hOut,
    csbi.wAttributes,
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Move the cursor home */
  SetConsoleCursorPosition( hOut, homeCoords );
}

std::vector<std::vector<std::string>> stageToGraphic(stage stage) {
    std::vector<std::vector<std::string>> result(stage.size());
    for (int i = 0; i < stage.size(); i++){
        auto line = stage[i];
        result[i].resize(line.size());
        for (int j = 0; j < line.size(); j++){
            result[i][j] = line[j]->getSymbol();
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
        for (auto& e: graphicStageV[i]) {
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