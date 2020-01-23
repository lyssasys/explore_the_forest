#include "Star.h"


void Star::init(float _deg, float _r, float _size, float _speed, float _alpha) {
	speed = _speed;
	size = _size;
	deg = _deg;
	r = _r;
	alpha = _alpha;
	//cout << r << "\n";
	
}

void Star::update() {
	deg= deg - speed;
	rad = deg * PI / 180.00;
	
	x = r * cos(rad);
	y = r * sin(rad);

	//cout << x << "\n";
	//cout << deg << "\n";
	//cout << r << "\n";

	
}

void Star::display() {
	
	ofPushMatrix();
	ofTranslate(ofGetWidth() / 2, ofGetHeight());
	ofScale(1, -1);

	ofSetColor(255, 255, 255, alpha);
	ofDrawCircle(x, y, size);

	ofPopMatrix();
	
}
