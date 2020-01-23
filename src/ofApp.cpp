#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//load wind sound
	wind.load("sound/wind.mp3");
	wind.setLoop(true);
	wind.play();

	ofSetCircleResolution(128);
	
	int motherGrY = ofGetHeight() * 0.95;
	int grW = ofGetHeight() * 2;

//objects

	//sky
	bg.init(motherGrY, 0.5, 133, 192, 149, 17, 42, 47);	
	for (int i = 0; i < STARNUM; i++)stars[i].init(ofRandom(0.00, 360.00), ofRandom(0.00, ofGetHeight()), ofRandom(0.00, 3.00), 0.01, ofRandom(0.00, 255.00));
	moon.init(100.000, ofGetHeight() * 0.80, ofGetWidth() * 0.03, 0.00001);
	aurora.init(300, 3, 0.002, 100, 300);

	//ground
	int wolfX = 200;
	wolf.init(wolfX , motherGrY, 5);
	ground[0].init(0, motherGrY, 5, wolfX, grW);
	

}

//--------------------------------------------------------------
void ofApp::update(){

//objects

	//sky
	bg.update();
	for (int i = 0; i < STARNUM; i++)stars[i].update();
	moon.update();
	aurora.update();

	//ground
	wolf.update();
	ground[0].update(wolf.rtnWolfX());
	

}

//--------------------------------------------------------------
void ofApp::draw(){

//objects

	//sky
	bg.display();
	for (int i = 0; i < STARNUM; i++)stars[i].display();
	moon.display();
	aurora.display();

	//ground
	ofSetColor(0, 0, 0);
	wolf.display();
	ground[0].display();
	
	
	
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
	int wolfX = wolf.rtnWolfX();
	wolf.clicked(x, y);
	ground[0].clicked(wolfX, x);
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
