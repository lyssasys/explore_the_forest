#include "ObjScr.h"

void ObjScr::init(int _x, int _y, int _dx, int _wolfX, int _grW) {
	x = _x;
	y = _y;
	dx = _dx;
	dir = 1;
	distance = 0;
	wolfX = _wolfX;
	hPos = _wolfX;
	grW = _grW;


}

void ObjScr::update() {
	if (distance > 0) { // scroll object untill gap between wolf and clicked point get 0
		distance = distance - abs(dx);
		x = x + dx * dir;
		wolfX = wolfX - dx * dir;

	}
	
	if (wolfX > grW - ofGetHeight() + hPos) {  //move object to right side out of screen
		if (x < 0) {
			x = x + grW;
		}

		wolfX = hPos;

	}else if (wolfX < hPos) {  //move object to left side out of screen

		if (x > ofGetWidth()) {
			x = x - grW;
		}
		
		wolfX = grW - ofGetHeight() + hPos;
	}

	
}


void ObjScr::befDisp() {
	ofPushMatrix();
	ofTranslate(x, y);
	ofScale(1, -1);
}

void ObjScr::display() {
	

}

void ObjScr::afDisp() {
	ofPopMatrix();
}

void ObjScr::clicked(int _distance, int _dir) {

	distance = _distance;
	dir = _dir;

}