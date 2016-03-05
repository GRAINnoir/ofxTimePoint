#include "ofxTimePoint.h"

bool ofxTimePoint::snapshot = true;

ofxTimePoint::ofxTimePoint(){};

time_point<chrono::high_resolution_clock> ofxTimePoint::startPoint(timeRes res){
    pt1 = high_resolution_clock::now();
    
    switch (res) {
        case SECOND:
            index = 1;
            break;
        case MILLI:
            index = 1e3;
            break;
        case MICRO:
            index = 1e6;
            break;
        case NANO:
            index = 1e9;
            break;
        default:
            index = 1e9;
            break;
    }

    return pt1;
}

double ofxTimePoint::getTimePoint(){
    pt2 = high_resolution_clock::now();
    elapsed = duration_cast<duration<double>>(pt2 - pt1).count();
    return elapsed*index;
}

const double ofxTimePoint::getTimeAverage(){
    static double val;
    iter = 0;
    if (snapshot) {
        for (int i=1; i<LENGTH;i++){
            val = getTimePoint();
            avrg[i]=val;
            iter+=avrg[i];
        }
        snapshot = false;
        val = iter/(LENGTH-1);
    }
    return val;
}

const float ofxTimePoint::getTimeMin(float x, int n){
    
    if(snapshot){
        pointMin = avrg[0];
        for (int i=1; i<n;i++){
            avrg[i]=x;
            if (avrg[i] < pointMin) {
                pointMin = avrg[i];
            }
        }
        snapshot = false;
    }
    return pointMin;
}

void ofxTimePoint::timePlot(float t, int x, int y, int w, int h){
    
    ofSetRectMode(OF_RECTMODE_CORNER);

    ofRectangle plot(x, y, w, ofMap(getTimeAverage(), 0, getTimeAverage(), 0, h));
    ofDrawRectangle(plot);
    ofDrawLine(plot.getBottomLeft(), plot.getTopLeft());
    ofDrawLine(plot.getBottomLeft(), plot.getBottomRight());
    
    plotX =  plot.getRight()-abs(sin(ofGetElapsedTimef()))*w;
    plotY = ofMap(t, 0, getTimeAverage(), plot.getBottom(), plot.getTop());
    ofPushStyle();
    ofFill();
    ofSetColor(255, 0, 0);
    ofDrawCircle(plotX, plotY, 2);
    ofPopStyle();
    
}

ofxTimePoint::~ofxTimePoint(){};
