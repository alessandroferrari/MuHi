//--------------------SETTINGS' CLASS-----------------------//
#include "json/json.h"
#include "settings.hpp"
#include <string>
#include <iostream>
#include <stdexcept>
#include <fstream>

using std::string;
using std::ifstream;
using std::ostream;
using std::invalid_argument;
using std::stringstream;
using std::endl;

Json::Value parse_cfg(const string& path)
{
    ifstream ifs(path);
    Json::Value root;
    Json::Reader reader;
    bool parsing_result = reader.parse(ifs,root,false); 
    if(parsing_result)
    {
        return root;
    }
    else
    { 
        stringstream ss;
        ss << "The json file "<<path<<" given as input for configuration cannot be parsed correctly.";
        throw invalid_argument(ss.str());
    }
}

Settings::Settings(const string& path)
{
    this->root = parse_cfg(path);

    // Debugging
    this->kPlotVectorField = root.get("kPlotVectorField",false).asBool();

    // Size constants
    this->kEyePercentTop = root.get("kEyePercentTop",25).asInt();
    this->kEyePercentSide = root.get("kEyePercentSide",13).asInt();
    this->kEyePercentHeight = root.get("kEyePercentHeight",30).asInt();     
    this->kEyePercentWidth = root.get("kEyePercentWidth",35).asInt();

    // Preprocessing
    this->kSmoothFaceImage = root.get("kSmoothFaceImage",false).asBool();
    this->kSmoothFaceFactor = root.get("kSmoothFaceFactor",0.005).asFloat();

    // Algorithm Parameters
    this->kFastEyeWidth = root.get("kFastEyeWidth",50).asInt();
    this->kWeightBlurSize = root.get("kWeightBlurSize",5).asInt();
    this->kEnableWeight = root.get("kEnableWeight",true).asBool();
    this->kWeightDivisor = root.get("kWeightDivisor",1.0).asFloat();
    this->kGradientThreshold = root.get("kGradientThreshold",50.0).asFloat();

    // Postprocessing
    this->kEnablePostProcess = root.get("kEnablePostProcess",true).asBool();
    this->kPostProcessThreshold = root.get("kPostProcessThreshold",0.97).asFloat();

    // Eye Corner
    this->kEnableEyeCorner = root.get("kEnableEyeCorner",false).asBool();

}

//output stream can be stdout, files, pigs, unicorns, whatever
void Settings::repr_settings(ostream& out){
    out << this->root << endl;
}

