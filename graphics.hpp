#ifndef _GRAPHICS_
#define _GRAPHICS_
#endif

#ifndef _WINDOWS_H_
#define _WINDOWS_H_
#include <windows.h>
#endif

#ifndef _STRING_
#define _STRING_
#include <string>
#endif

#ifndef _READSTAGE_
#define _READSTAGE_
#include "readStage.hpp"
#endif

#ifndef _CHARACTER_
#define _CHARACTER_
#include "character.hpp"
#endif

#ifndef _UTILITY_
#define _UTILITY_
#include <utility>
#endif

#ifndef _ALGORITHM_
#define _ALGORITHM_
#include <algorithm>
#endif

#ifndef _IOSTREAM_
#define _IOSTREAM_
#include <iostream>
#endif

#ifndef _FUTURE_
#define _FUTURE_
#include <future>
#endif

#ifndef _FUNCTIONAL_
#define _FUNCTIONAL_
#include <functional>
#endif

using coord = std::pair<int, int>;

void clear();
std::vector<std::vector<std::string>> stageToGraphic(stage stage);
void graphic(stage stage, Character::charSymbol symbol, coord charCoord);
void startMenu();

#ifndef _GRAPHICS_CPP_
#define _GRAPHICS_CPP_
#include "graphics.cpp"
#endif