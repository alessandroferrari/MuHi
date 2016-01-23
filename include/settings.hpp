#ifndef SETTINGS_HPP_GUARD
#define SETTINGS_HPP_GUARD

#include "rapidjson/document.h"
#include <string>
#include <iostream>

using rapidjson::Document;

void parse_cfg(Document& doc, const std::string& path);
#endif
