#include "ofApp.h"
float rotationOuter;
float rotationInner;
float rotationCenter;
float scalePupil;
float scale;
float beatWait;
float lastBeat;
vector<float> eyeLocations;
vector<ofColor> pallete;
int eyeCount;
int color = 0;
//--------------------------------------------------------------
void ofApp::setup(){
	ofEnableAlphaBlending();
	//rotation values for parts of eyes.
	rotationOuter = 0;
	rotationInner = 0;
	rotationCenter = 0;
	
	//slider setup.
	gui.setup();
	gui.add(eyes.setup("Eyes", 2, 1, 17));
	eyeCount = 1;
	//background
	ofBackground(ofColor().black);
	//load and play song. 
	song.load("sleepingPowder.mp3");
	fftSmooth = new float[8192];
	for (int i = 0; i < 8192; i++)
	{
		fftSmooth[i] = 0;
	}
	bands = 64;

	song.play();
	
	lastBeat = ofGetElapsedTimeMicros();

	pallete.push_back(ofColor(255,255,0,128));
	pallete.push_back(ofColor(0,255,255,128));
	pallete.push_back(ofColor(0,255,1,128));
	pallete.push_back(ofColor(255,0,254,128));
	pallete.push_back(ofColor(254,0,0,128));
	pallete.push_back(ofColor(0,0,254,128));
	
}

//--------------------------------------------------------------
void ofApp::update(){
	beatWait = 576923.07692;
	ofSoundUpdate();
	if (ofGetElapsedTimeMicros() - lastBeat > beatWait)
	{
		if(ofGetElapsedTimef()> 20 && ofGetElapsedTimef()<25){ printf("%f, %f, %f\n", ofGetElapsedTimef, lastBeat, beatWait); }
		
		ofBackground(pallete[color]);
		if (color == 5)
		{
			color = 0;
		}
		else
		{
			color += 1;
		}
		lastBeat = ofGetElapsedTimeMicros();
	}
	float * value = ofSoundGetSpectrum(bands);
	for (int i = 0; i < bands; i++)
	{
		fftSmooth[i] *= .9f;
		if (fftSmooth[i] < value[i]) {
			fftSmooth[i] = value[i];
		}
	}
	scale = (float(1) / float(eyes));
	scalePupil = scale;
	for (int i = 0; i < bands; i++)
	{
		//if(fftSmooth[i]> .5){ printf("%f", fftSmooth[i]); }
		
		rotationOuter = rotationOuter + (.1*fftSmooth[i]);
		rotationInner = rotationInner - (.2*fftSmooth[i]);
		rotationCenter = rotationCenter - (.2*fftSmooth[i]);
		scalePupil = scalePupil - (fftSmooth[i] * .01);
	}


	
	scale = ofClamp(scale, .1, 1);
	scalePupil = ofClamp(scalePupil, .1, 1);
	eyeCount = eyes;
	eyeLocations.clear();
	drawEyes(0, ofGetWidth()/2, ofGetHeight()/2);
	vector<float> temp; 
	for (int i = 0; i < eyeLocations.size(); i += 2) {
		bool dup = false;
		float x = eyeLocations[i];
		float y = eyeLocations[i + 1];
		for (int j = 0; j < temp.size(); j += 2) {
			if (x == temp[j] && y == temp[j + 1]) {
				dup = true; 
			}

		}
		if (!dup) {
			temp.push_back(x); 
			temp.push_back(y);
		}
	}
	eyeLocations = temp;
}

//--------------------------------------------------------------
void ofApp::draw(){
	//number of eyes slider
	//int count = 1;
	//make one eye ;)
	//printf("%d \n", eyeLocations.size());
	ofPushMatrix();
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	ofSetColor(ofColor().black);
	ofCircle(0, 0, 220*(eyes*2)*scale );
	ofPopMatrix();
	

		for (int i = 0; i < eyeLocations.size(); i += 2)
		{
			//printf("%d", count);
			ofPushMatrix();
			ofTranslate(eyeLocations[i], eyeLocations[i + 1]);
			//printf("%f, %f \n", eyeLocations[i], eyeLocations[i + 1]);
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
			ofCircle(15 * scale, 0, 65 * scalePupil);
			ofPopMatrix();
			/*if (count % 2 == 1) {
				ofPushMatrix();
				ofTranslate(eyeLocations[i], eyeLocations[i + 1]);
				ofSetColor(ofColor().pink);
				ofDrawRectangle(0, 0, 207 * 2 * scale, 207 * 2 * scale);
				ofPopMatrix();
			}

			count += 1;*/
		}
	
	gui.draw();
	
	

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
