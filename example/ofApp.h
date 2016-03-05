#pragma once

#include "ofMain.h"
#include "ofxTimePoint.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);

        ofxTimePoint pt;
        double ico, sphere;
    
};
