#include "Tree.h"

int Tree::radian(int _deg) {
	int rad = _deg * PI / 180;
	return rad;

	
}


void Tree::init(int _rootx, int _rooty, int _dx, int _h, int _lvNum, int _wolfX, int _grW) {
	ObjScr::init(_rootx, _rooty, _dx, _wolfX, _grW);
	h = _h;
	lvNum = _lvNum;
	rootx = _rootx;
	rooty = _rooty;
	node = 10;
	childNode = node / 2;
	deg = 60;

	windPmt = ofRandom(0.00, 1.00);

}

void Tree::update(int _windX) {
	ObjScr::update();
	
	//wind
	int n = 0;
	if (_windX < x + 50 && _windX > x - 50) {
		n = 20;
	}
	for (int i = 0; i < n; i++) {
		windPmt = windPmt + 0.01;
	}
	
}

void Tree::display() {
	
	ObjScr::befDisp();//save default, translate center to A
	
	//initialize pmt
	degPmtR = 0.07;
	degPmtL = 0.03;
	dnyPmt = 0.00;

	

	//draw trunk
	int maxW = h * 0.1;
	float trPmtR = 0.00;
	float trPmtL = 0.03;
	for (int j = 0; j < h; j++) {

		float trW = 1.00 - (j * 1.00 / h * 1.00);

		ofDrawRectangle(0, j, trW * maxW * ofNoise(trPmtR), 1);
		ofDrawRectangle(0, j, -trW * maxW * ofNoise(trPmtL), 1);

		trPmtR = trPmtR + 0.001;
		trPmtL = trPmtL + 0.001;
	}

	ofPushMatrix(); // save A
	ofTranslate(0, h); // B


	int dny = -h / node / 2;
	for (int i = 0; i < node; i++) {

		//right side
		branch(h, childNode, deg * ofNoise(degPmtR) + 3.00 * ofNoise(windPmt), lvNum, degPmtR, degPmtL);
		branch(h, childNode, 10 * ofNoise(degPmtR), lvNum, degPmtR, degPmtL);
		
		ofTranslate(0, dny * ofNoise(degPmtR));
		

		//left side
		branch(h, childNode, -deg * ofNoise(degPmtL) - 3.00 * ofNoise(windPmt), lvNum, degPmtR, degPmtL);
		branch(h, childNode, -10 * ofNoise(degPmtL), lvNum, degPmtR, degPmtL);

		ofTranslate(0, dny * ofNoise(degPmtL));
	
		//update pmt
		degPmtR = degPmtR + 0.7;
		degPmtL = degPmtL + 0.7;

		

	}
	
	ofPopMatrix(); //back to A

	ObjScr::afDisp(); // back to default
}


void Tree::branch(int _h, int _node, int _deg, int _lv, float _degPmtR, float _degPmtL) {
	
	_h = _h * 0.3;
	int _dny = _h / _node;
	int _maxW = _h * 0.05;


	if (_lv > 0) {


		ofPushMatrix();
		ofRotateZDeg(_deg);

		//draw branch
		float _trPmtR = 0.003;
		float _trPmtL = 0.007;
		for (int j = 0; j < _h; j++) {

			float _trW = 1.00 - (j * 1.00 / _h * 1.00);


			ofDrawRectangle(0, -j, _trW * _maxW * ofNoise(_trPmtR), 1);
			ofDrawRectangle(0, -j, -_trW * _maxW * ofNoise(_trPmtL), 1);

			_trPmtR = _trPmtR + 0.001;
			_trPmtL = _trPmtL + 0.001;

		}
		ofDrawLine(0, 0, 0, -_h);


		_lv--;
		ofTranslate(0, -_h);

		//update pmt
		_degPmtR = _degPmtR + 0.4;
		_degPmtL = _degPmtL + 0.7;


		for (int i = 0; i < _node; i++) {
			//ofTranslate(0, -dny);

			//right side
			ofPushMatrix();
			//ofTranslate(0, _dny * i * ofNoise(_degPmtR));
			ofTranslate(0, _dny * i);
			branch(_h, _node, _deg * ofNoise(_degPmtR), _lv, _degPmtR, _degPmtL);
			//ofPopMatrix();

			//left side
			branch(_h, _node, -_deg * ofNoise(_degPmtL), _lv, _degPmtR, _degPmtL);
			ofPopMatrix();
		}
		ofPopMatrix();

	}
}

void Tree::clicked(int _distance, int _dir) {
	ObjScr::clicked(_distance, _dir);
}
