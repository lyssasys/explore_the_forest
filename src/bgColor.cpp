#include "bgColor.h"

void BgColor::init(int _y, float _md, float _sR, float _sG, float _sB, float _eR, float _eG, float _eB) {
	bgY = _y;
	md_y = bgY * _md;

	dR = (_eR - _sR) / md_y;
	dG = (_eG - _sG) / md_y;
	dB = (_eB - _sB) / md_y;

	R = _sR;
	G = _sG;
	B = _sB;


	sR = _sR;
	sG = _sG;
	sB = _sB;
	

}

void BgColor::update() {
	


}

void BgColor::display(){
	
	//for (int i = x; i < rLen; i++) {
	//	ofSetColor(R, G, B);
	//	ofDrawCircle(x, y, r);
	//	r++;
	//	R = R + dR;
	//	G = G + dG;
	//	B = B + dB;
	//}
	//if (r > rLen) {
	//	r = 0;
	//	R = sR;
	//	G = sG;
	//	B = sB;
	//}
	for (int i = bgY; i > md_y; i--) {

		ofSetColor(R, G, B);
		ofDrawLine(0, i, ofGetWidth(), i);
		R = R + dR;
		G = G + dG;
		B = B + dB;

	}
	
	for (int j = md_y; j > 0; j--) {
		ofDrawLine(0, j, ofGetWidth(), j);
	}
		
	R = sR;
	G = sG;
	B = sB;
	
}