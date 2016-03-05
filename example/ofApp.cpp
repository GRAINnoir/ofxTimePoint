#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    ofSetVerticalSync(true);
    glLineWidth(1.0);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    cout<<"ico: "<<ico<<endl;
    cout<<"sphere: "<<sphere<<endl;

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(255);
    ofNoFill();
    ofDrawLine(ofGetWidth()/2, 40, ofGetWidth()/2, ofGetHeight()-40);

    pt.startPoint(NANO);

    // monitored process
    ofPushMatrix();
    ofTranslate(100, 180);
    ofRotate(ofGetElapsedTimef()*20, 0, 1,0);
    ofSetSphereResolution(2);
    ofDrawSphere(0, 0, 40);
    ofPopMatrix();

    ico = pt.getTimePoint();
    
    ofPushMatrix();
    ofTranslate(300, 180);
    ofRotate(ofGetElapsedTimef()*20, 1, 1, 1);
    ofSetSphereResolution(8);
    ofDrawSphere(0, 0, abs(sin(ofGetElapsedTimef())*20)+20);
    ofPopMatrix();
    
    sphere = pt.getTimePoint();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    // average snapshot
    if(key=='a') ofxTimePoint::snapshot = true;
}