#ifndef _READSTAGE_
#define _READSTAGE_

#ifndef _FSTREAM_
#define _FSTREAM_
#include <fstream>
#endif

#ifndef _STRING_
#define _STRING_
#include <string>
#endif

#ifndef _VECTOR_
#define _VECTOR_
#include <vector>
#endif

#ifndef _ITERATOR_
#define _ITERATOR_
#include <iterator>
#endif

#ifndef _JSON_
#define _JSON_
#include "json.hpp"
using json = nlohmann::json;
#endif

#include "nodes.hpp"
#include "switch_string.hpp"

#ifndef _ALGORITHM_
#define _ALGORITHM_
#include <algorithm>
#endif 

#ifndef _IOSTREAM_
#define _IOSTREAM_
#include <iostream>
#endif

using node = std::shared_ptr<Node::Node>;
using stageline = std::vector<node>;
using stage = std::vector<stageline>;

stage readMap(int in);
std::string stageFileName(int in);
bool mapExist(int in);

#include "readStage.cpp"
#endif