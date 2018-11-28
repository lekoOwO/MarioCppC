#ifndef _READSTAGE_CPP_
#define _READSTAGE_CPP_
#endif

#ifndef _READSTAGE_
#define _READSTAGE_
#include "readStage.hpp"
#endif

// std::string readFile(const char* filepath){
//     std::ifstream myfile(filepath);
//     std::vector<std::string> myLines;
//     std::copy(std::istream_iterator<std::string>(myfile),
//               std::istream_iterator<std::string>(),
//               std::front_inserter(myLines));
//     std::string resultString = "";
//     for (auto s : myLines)
//         resultString += s;
//     return resultString;
// };

stage readMap(const char* filepath) {
    std::ifstream i(filepath);
    json jsonStage;
    i >> jsonStage;
    std::reverse(jsonStage.begin(), jsonStage.end());

    stage result(jsonStage.size());
    for (auto arr: jsonStage) {
        stageline resultArray(arr[0].size());
        for (auto elem : arr) {
            switch (hash_(std::string(elem["type"]).c_str())) {
                case "NullNode"_hash:
                    resultArray.push_back(NewNode::NullNode);
                    break;
                
                case "Ground"_hash:
                case "GroundXX"_hash:
                    resultArray.push_back(NewNode::Ground);
                    break;

                case "KongMingBrick"_hash:
                    if (elem.find("coin") != elem.end()) {
                        resultArray.push_back(NewNode::newKongMingBrick(elem["coin"]));
                    } else {
                        resultArray.push_back(NewNode::NullNode);
                    }
                    break;

                case "Tube"_hash:
                case "TubeNode"_hash:
                    resultArray.push_back(NewNode::Tube);
                    break;

                case "TubeHead"_hash:
                    resultArray.push_back(NewNode::Tubehead);
                    break;

                case "Flag"_hash:
                    resultArray.push_back(NewNode::Flag);
                    break;

                case "FlagHead"_hash:
                    resultArray.push_back(NewNode::FlagHead);
                    break;

                case "Coin"_hash:
                case "CoinNode"_hash:
                    resultArray.push_back(NewNode::Coin);
                    break;
            } 
        }
        result.push_back(resultArray);
    }
    return result;
}