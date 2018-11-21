#ifndef _READSTAGE_CPP_
#define _READSTAGE_CPP_
#endif

#ifndef _READSTAGE_
#define _READSTAGE_
#include "readStage.hpp"
#endif

std::string readFile(const char* filepath){
    std::ifstream myfile(filepath);
    std::std::vector<std::string> myLines;
    std::copy(std::istream_iterator<std::string>(myfile),
              std::istream_iterator<std::string>(),
              std::front_inserter(myLines));
    std::string resultString = "";
    for (auto s : myLines)
        resultString += s;
    return resultString;
};

std::vector<std::vector<std::shared_ptr<class Node::Node>>> readStage(const char* stage) {
    auto jsonStage = json::parse(stage);
    std::vector<std::vector<std::shared_ptr<class Node::Node>>> result(std::size(jsonStage));
    for (auto arr: jsonStage) {
        std::vector<std::shared_ptr<class Node::Node>> resultArray(std::size(arr[0]));
        for (auto elem : arr) {
            switch (hash_(elem["type"])) {
                case hash_compile_time("NullNode"):
                    resultArray.push_back(NewNode::NullNode);
                    break;
                
                case hash_compile_time("Ground")
                case hash_compile_time("GroundXX"):
                    resultArray.push_back(NewNode::Ground);
                    break;

                case hash_compile_time("KongMingBrick"):
                    if (elem.find("coin") != elem.end()) {
                        resultArray.push_back(NewNode::newKongMingBrick(elem["coin"]));
                    }
                    break;

                case hash_compile_time("Tube")
                case hash_compile_time("TubeNode"):
                    resultArray.push_back(NewNode::Tube);
                    break;

                case hash_compile_time("TubeHead"):
                    resultArray.push_back(NewNode::TubeHead);
                    break;

                case hash_compile_time("Flag"):
                    resultArray.push_back(NewNode::Flag);
                    break;

                case hash_compile_time("FlagHead"):
                    resultArray.push_back(NewNode::FlagHead);
                    break;

                case hash_compile_time("Coin"):
                case hash_compile_time("CoinNode"):
                    resultArray.push_back(NewNode::Coin);
                    break;
            } 
        }
        result.push_back(resultArray);
    }
    return result;
}