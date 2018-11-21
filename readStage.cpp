#ifndef _READSTAGE_CPP_
#define _READSTAGE_CPP_
#endif

#ifndef _READSTAGE_
#define _READSTAGE_
#include "readStage.hpp"
#endif

std::string readStage(const char* filepath){
    std::ifstream myfile(filepath);    
    std::vector<std::string> myLines;
    std::copy(std::istream_iterator<std::string>(myfile),
              std::istream_iterator<std::string>(),
              std::front_inserter(myLines));
    std::string result = "";
    for (auto s : myLines)
        result += s;
    return s;
}