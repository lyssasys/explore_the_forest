#include "ground.h"


void Ground::init(int _level, int _gLine, int _speed, int _wolfX, int _grW) {
	level = _level;
	gLine = _gLine;
	speed = _speed;
	grassPmt = 0.00;
	
	grW = _grW;
	windX = ofRandom(0, ofGetWidth());
	windPmt = 0.00;

	//scrDx
	if(level ==0 || level ==2){
		scrDx = -1 * speed;
	
	}else{
		scrDx = speed;
	}

	for (int j = 0; j < GRASSNUM; j++) {
		int grassX = _grW;
		grass[j].init(ofRandom(0, grassX), gLine, scrDx, ofRandom(0.00, ofGetHeight()*0.05), _wolfX, _grW);
		grassPmt = grassPmt + 0.01;
	}

	float treeHPmt = 0.00;
	for (int l = 0; l < TREENUM; l++) {
		tree[l].init(ofRandom(0, _grW), gLine, scrDx, ofGetHeight() * 0.4 * ofNoise(treeHPmt), 2, _wolfX, _grW);
		treeHPmt = treeHPmt + 0.1;
	}
	
}


void Ground::update(int _wolfFHX) {

	//wind
	windPmt = windPmt + 0.01;
	windX = ofGetWidth() * ofNoise(windPmt);
	
	for (int j = 0; j < GRASSNUM; j++)grass[j].update(_wolfFHX, windX);
	for (int l = 0; l < TREENUM; l++)tree[l].update(windX);
}

void Ground::display() {

	ofDrawLine(0, gLine, ofGetWidth(), gLine);
	ofDrawRectangle(0, gLine, ofGetWidth(), ofGetHeight());

	for (int j = 0; j < GRASSNUM; j++)grass[j].display();

	for (int l = 0; l < TREENUM; l++)tree[l].display();
}

void Ground::clicked(int wolfX, int gX) {

	int direction;
	if (wolfX < gX) {
		direction = 1;
	}
	else {
		direction = -1;
	}
	
	for (int j = 0; j < GRASSNUM; j++)grass[j].clicked(abs(wolfX - gX), direction);
	for (int l = 0; l < TREENUM; l++)tree[l].clicked(abs(wolfX - gX), direction);
}
