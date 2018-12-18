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
            result[i][j] = line[j]->isVisiable() ? line[j]->getSymbol() : "　";
        }
    }
    return result;
};

void graphic(stage stage, std::shared_ptr<Character::Character> mario, coord charCoord){
    auto graphicStageV = stageToGraphic(stage);
    auto symbol = mario->getSymbol();
    int y = charCoord.first;
    int x = charCoord.second;

    for (auto [e, i] = std::make_tuple(symbol.rbegin(), y); e != symbol.rend(); ++e, ++i) {
        graphicStageV[i][x] = *e;
    };

    // clear();
    COORD     cursorPos;
    cursorPos.X   =   0;   
    cursorPos.Y   =   0; 
    SetConsoleCursorPosition(hOut, cursorPos);

    std::cout << std::setw(8) << "SCORE" << std::setw(8) << "COIN" << std::setw(8) << "LIFE" << '\n';
    std::cout << std::setw(8) << mario->getScore() << std::setw(8) << mario->getCoin() << std::setw(8) << mario->getLife();
    std::cout << "\n\n\n";

    for (int i = size(graphicStageV) - 1; i >= 0; i--){
        for (auto& e: graphicStageV[i]) {
            std::cout << e;
        }
        std::cout << '\n';
    }
    std::cout.flush();
};

BOOL SetConsoleSize(HANDLE hOut, int W, int H)
{
    HWND hwnd = GetConsoleWindow();
    if( hwnd != NULL ) MoveWindow(hwnd ,0, 0 ,W ,H ,TRUE);

    SMALL_RECT SR = {0, 0, static_cast<SHORT>(W-1), static_cast<SHORT>(H-1)};
    WINBOOL ret = SetConsoleWindowInfo(hOut,TRUE, &SR);
    if(!ret) return ret;

    COORD Sz = {static_cast<SHORT>(W), static_cast<SHORT>(H) };
        
    return SetConsoleScreenBufferSize(hOut,Sz);
}