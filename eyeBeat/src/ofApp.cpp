#include "ofApp.h"
float rotationOuter;
float rotationInner;
float rotationCenter;
float scale;
vector<float> eyeLocations;
int eyeCount;
//--------------------------------------------------------------
void ofApp::setup(){
	
	rotationOuter = 0;
	rotationInner = 0;
	rotationCenter = 0;
	gui.setup();
	gui.add(eyes.setup("Eyes", 1, 1, 17));
	eyeCount = 1;
	//scale = .1;
}

//--------------------------------------------------------------
void ofApp::update(){
	rotationOuter = rotationOuter + .2;
	rotationInner = rotationInner - .5;
	rotationCenter = rotationCenter - .5;
	scale = 1/ float(eyes);
	scale = ofClamp(scale, .1, 1);
	eyeCount = eyes;
	eyeLocations.clear();
	drawEyes(0, ofGetWidth()/2, ofGetHeight()/2);
}

//--------------------------------------------------------------
void ofApp::draw(){
	//number of eyes slider
	gui.draw();
	//make one eye ;)
	printf("%d \n", eyeLocations.size());
	for (int i = 0; i < eyeLocations.size(); i+=2)
	{
		ofPushMatrix();
		ofTranslate(eyeLocations[i], eyeLocations[i+1]);
		ofSetColor(ofColor().black);
		ofCircle(0, 0, 207 * scale);
		ofSetColor(ofColor().darkBlue);
		ofCircle(0, 0, 200 * scale);
		ofRotateZ(rotationOuter);
		ofSetColor(ofColor().antiqueWhite);
		ofCircle(0, 0, 130 * scale);
		ofRotateZ(rotationInner);
		ofSetColor(ofColor(65, 169, 228));
		ofCircle(20 * scale, 0, 100 * scale);
		ofRotateZ(rotationCenter);
		ofSetColor(ofColor().black);
		ofCircle(15 * scale, 0, 65 * scale);
		ofPopMatrix();
	}
	
	
	

}

void ofApp::drawEyes(int count, float x, float y) {
	count += 1;
	eyeLocations.push_back(x);
	eyeLocations.push_back(y);
	if (count < eyeCount) {
		
		drawEyes(count, x - (414 * scale), y - (414 * scale));
		drawEyes(count, x - (414 * scale), y + (414 * scale));
		drawEyes(count, x + (414 * scale), y - (414 * scale));
		drawEyes(count, x + (414 * scale), y + (414 * scale));
	}
	
	return;
	
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
