#ifndef SETTINGS_HPP_GUARD
#define SETTINGS_HPP_GUARD

#include "json/json.h"
#include <string>
#include <iostream>

Json::Value parse_cfg(const std::string& path);

class Settings {

    private:

        Json::Value root;

    public:

        //Attributes

        /*attributes can be set both from configuration 
        files and command line, there would be need of setters
        and getters for all of them, thus there is not point
        to leave it private right now*/

        // Debugging
        bool kPlotVectorField = false;

        // Size constants
        int kEyePercentTop = 25;
        int kEyePercentSide = 13;
        int kEyePercentHeight = 30;
        int kEyePercentWidth = 35;

        // Preprocessing
        bool kSmoothFaceImage = false;
        float kSmoothFaceFactor = 0.005;

        // Algorithm Parameters
        int kFastEyeWidth = 50;
        int kWeightBlurSize = 5;
        bool kEnableWeight = true;
        float kWeightDivisor = 1.0;
        double kGradientThreshold = 50.0;

        // Postprocessing
        bool kEnablePostProcess = true;
        float kPostProcessThreshold = 0.97;

        // Eye Corner
        bool kEnableEyeCorner = false;

        // methods

        //constructor: takes as input the configuration filepath
        Settings(const std::string& path);
        void repr_settings(std::ostream& out);
};
#endif
