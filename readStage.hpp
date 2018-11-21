#ifndef _READSTAGE_
#define _READSTAGE_
#endif

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

#ifndef _NODES_
#define _NODES_
#include "nodes.hpp"
#endif

#ifndef _SWITCH_STRING_
#define _SWITCH_STRING_
#include "switch_string.hpp"
#endif

std::string readStage(const char* filepath);
std::vector<std::vector<std::shared_ptr<class Node::Node>>> readStage(const char *stage);

#ifndef _READSTAGE_CPP_
#define _READSTAGE_CPP_
#include "readStage.cpp"
#endif