#include "Aurora.h"

void Aurora::init(float _sy, float _rotateDeg, float _sinPrd, float _sinH, int aurLen) {

	pmt = ofRandom(0.00, 1.00);
	pmt1 = 0.00;


	sinPrd = _sinPrd;
	sinH = _sinH;

	x = 0;
	y = 0;

	sy = _sy;
	rotateDeg = _rotateDeg;

	float defAlp = ofRandom(0, 20.00);
	float defDAlp = 0.50;
	for (int i = 0; i < LINENUM; i++) {
		
		aurLine[i].init(aurLen, defAlp * ofNoise(pmt1), 0.50);
		defDAlp = AurLine::chngDAlp(defAlp, defDAlp);
		defAlp = AurLine::chngAlp(defAlp, defDAlp);
		
		pmt1 = pmt1 + 0.01;
	}

	
}


void Aurora::update() {

	

	for (int i = 0; i < LINENUM; i++)aurLine[i].update();
	
}

void Aurora::display() {
	
	ofPushMatrix();

	ofSetFrameRate(40);
	ofTranslate(0, sy);
	ofScale(1, -1);
	ofRotateZDeg(rotateDeg);

	//ofSetColor(255, 0, 0);
	//ofDrawCircle(0, 0, 10);

	x = 0;
	pmt = 0.00;

	for (int i = 0; i < LINENUM; i++) {
		aurLine[i].display(x, y);
		y = sinH * sin(x * sinPrd) * ofNoise(pmt);
		
		x = x + ofGetWidth() *1.1 / LINENUM;
		pmt = pmt + 0.01;
	}
	
	ofPopMatrix();
	

}

//void Aurora::drawCurve(float x, float y) {
	

//}