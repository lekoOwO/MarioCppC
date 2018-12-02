#ifndef _READSTAGE_CPP_
#define _READSTAGE_CPP_
#endif

#ifndef _READSTAGE_
#define _READSTAGE_
#include "readStage.hpp"
#endif

stage readMap(const char* filepath) {
    std::ifstream i(filepath);
    json jsonStage;
    i >> jsonStage;
    std::reverse(jsonStage.begin(), jsonStage.end());

    stage result(jsonStage.size(), stageline(jsonStage[0].size()));
    for (int i = 0; i < jsonStage.size(); i++) {
        auto arr = jsonStage[i];
        for (int j = 0; j < size(arr); j++) {
            auto elem = arr[j];
            switch (hash_(std::string(elem["type"]).c_str()))
                {
                case "NullNode"_hash:
                    result[i][j] = NewNode::NullNode;
                    break;
                
                case "Ground"_hash:
                case "GroundXX"_hash:
                    result[i][j] = (NewNode::Ground);
                    break;

                case "KongMingBrick"_hash:
                    if (elem.find("coin") != elem.end()) {
                        result[i][j] = (NewNode::newKongMingBrick(elem["coin"]));
                    } else {
                        result[i][j] = (NewNode::NullNode);
                    }
                    break;

                case "Tube"_hash:
                case "TubeNode"_hash:
                    result[i][j] = (NewNode::Tube);
                    break;

                case "Tubehead"_hash:
                case "TubeHead"_hash:
                    result[i][j] = (NewNode::Tubehead);
                    break;

                case "Flag"_hash:
                    result[i][j] = (NewNode::Flag);
                    break;

                case "FlagHead"_hash:
                    result[i][j] = (NewNode::FlagHead);
                    break;

                case "Coin"_hash:
                case "CoinNode"_hash:
                    result[i][j] = (NewNode::Coin());
                    break;
            } 
        }
    }
    return result;
}