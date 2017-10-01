#include "ofApp.h"
float rotationX;

//--------------------------------------------------------------
void ofApp::setup(){
	rotationX = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
	rotationX = rotationX + .05;
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	ofRotateZ(rotationX);
	ofCircle(-300, 0, 130);
	

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
