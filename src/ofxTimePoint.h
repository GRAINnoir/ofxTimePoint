#pragma once

#include "ofMain.h"

#define LENGTH 10

using namespace std::chrono;

enum timeRes {
    SECOND,
    MILLI,
    MICRO,
    NANO
};

class ofxTimePoint {
    
    public:
        ofxTimePoint();
    
        time_point<chrono::high_resolution_clock> startPoint(timeRes res = NANO);
    
        double getTimePoint();
        const double getTimeAverage();
        const float getTimeMin(float x, int n = LENGTH);
    
        void timePlot(float t, int x, int y, int w, int h);
    
        static bool snapshot;

        ~ofxTimePoint();
    
    private:
    
        high_resolution_clock::time_point pt1, pt2;
        double elapsed;
        double avrg[LENGTH], iter;
        double pointMin, pointMax;
        double plotX, plotY;
        int index;

};