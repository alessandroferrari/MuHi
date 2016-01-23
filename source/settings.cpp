//--------------------SETTINGS-----------------------//
#include "rapidjson/document.h"
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using std::string;
using std::ifstream;
using std::stringstream;
using rapidjson::Document;
using std::invalid_argument;

void parse_cfg(Document& doc, const string& path)
{
    ifstream ifs(path.c_str());
    stringstream buffer;
    buffer << ifs.rdbuf();
    if(doc.Parse<0>(buffer.str().c_str()).HasParseError())
        throw invalid_argument("Error while parsing settings in json format.");  
}
