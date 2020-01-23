#include "Grass.h"

void Grass::init(int _x, int _y, int _dx, int _h, int _wolfX, int _grW) {
	ObjScr::init(_x, _y, _dx, _wolfX, _grW);
	h = _h;
	w = h * ofRandom(0.0, 0.3);
	tipX = ofRandom(-1 * h, 2 * h);

	hPos = _wolfX;
	movePmt = ofRandom(0.00, 1.00);
	windPmt = ofRandom(0.00, 1.00);
}

void Grass::update(int _wolfFHX, int _windX) {
	ObjScr::update();
	
	//wolf move
	int n = 0;
	if (x > _wolfFHX - 20 && x < _wolfFHX + 20 && distance > abs(dx)) {
		n = 5;
	}
	for (int i = 0; i < n; i++) {
		movePmt = movePmt + 0.4;
	}

	//wind
	int m = 0;
	if (_windX < x + 50 && _windX > x - 50) {
		m = 20;
	}
	for (int j = 0; j < m; j++) {
		windPmt = windPmt + 0.01;
	}

}

void Grass::display() {
	ObjScr::befDisp();

	


	ofDrawTriangle(0, 0, w, 0, tipX * ofNoise(movePmt) * ofNoise(windPmt), h);
	
	ObjScr::afDisp();
}

void Grass::clicked(int _distance, int _dir) {
	ObjScr::clicked(_distance, _dir);
}