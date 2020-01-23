#include "aurLine.h"

void AurLine::init(int _aurLen, float _alpha, float  _dAlp) {
	aurLen = _aurLen;
	alpha = _alpha;
	dAlp = _dAlp;

	alpPmt = 0.00;
	
	
};


float AurLine::chngAlp(float _alp, float _dAlp) {
	
	//cout << _dAlp << "\n";
	_alp = _alp + _dAlp;
	
	return _alp;
}

float AurLine::chngDAlp(float _alp, float _dAlp) {
	if (_alp >= 100.00 || _alp < -1.00) {
		_dAlp = -1.00 * _dAlp;
	}
	return _dAlp;
	
}

void AurLine::update() {
	dAlp = chngDAlp(alpha, dAlp);
	alpha = chngAlp(alpha, dAlp);

	alpPmt = alpPmt + 0.01;
	
};

void AurLine::display(float x, float y) {
	
	//ofSetColor(0, 255, 0, 100.00 * ofNoise(alpha));
	ofSetColor(106, 187, 172, alpha * ofNoise(alpPmt));
	
	ofDrawLine(x, y, x,  y + aurLen);
	
	
};