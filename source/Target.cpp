#include <opencv2/opencv.hpp>

class Target{

    public:
        cv::Point target;
        cv::Rect leftEyeRegion;
        cv::Rect rightEyeRegion;
        cv::Point leftPupil;
        cv::Point rightPupil;

    Target(cv::Point t, cv::Rect lER, cv::Rect rER, cv::Point lP, cv::Point rP){
        target = t;
        leftEyeRegion = lER;
        rightEyeRegion = rER;
        leftPupil = lP;
        rightPupil = rP;
    }
    
};

