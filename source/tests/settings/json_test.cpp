#include "rapidjson/document.h"
#include "settings.hpp"
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

using rapidjson::Document;

int main(){
    
    Document doc;
    parse_cfg(doc, string("test.json"));   

    assert(doc.IsObject());
    assert(doc.HasMember("this"));
    assert(doc.HasMember("is"));
    assert(doc.HasMember("a"));
    assert(doc.HasMember("test"));

    cout << "this: " << doc["this"].GetInt() << endl;
    cout << "is: " << doc["is"].GetString() << endl;
    cout << "a: " << doc["a"].GetBool() << endl;
    cout << "test: " << doc["test"].GetDouble() << endl;

    return 0;
}
