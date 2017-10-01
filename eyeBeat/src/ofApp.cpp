#include "ofApp.h"
float rotationOuter;
float rotationInner;
float rotationCenter;
//--------------------------------------------------------------
void ofApp::setup(){
	rotationOuter = 0;
	rotationInner = 0;
	rotationCenter = 0;
	gui.setup();
	gui.add(eyes.setup("Eyes", 1, 1, 500));
}

//--------------------------------------------------------------
void ofApp::update(){
	rotationOuter = rotationOuter + .05;
	rotationInner = rotationInner - .3;
	rotationCenter = rotationCenter - .3;
}

//--------------------------------------------------------------
void ofApp::draw(){
	gui.draw();
	//make one eye ;)
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	ofSetColor(ofColor().darkBlue);
	ofCircle(0, 0, 200);
	ofRotateZ(rotationOuter);
	ofSetColor(ofColor().antiqueWhite);
	ofCircle(0, 0, 130);
	ofRotateZ(rotationInner);
	ofSetColor(ofColor(65,169,228));
	ofCircle(20, 0, 100);
	ofRotateZ(rotationCenter);
	ofSetColor(ofColor().black);
	ofCircle(15, 0, 65);
	
	

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
