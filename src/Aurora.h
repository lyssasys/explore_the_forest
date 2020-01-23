#pragma once
#include "ofMain.h"
#include "aurLine.h"

#define LINENUM 1000

class Aurora {
public:
	void init(float _sy, float _rotateDeg, float _sinPrd, float _sinH, int _aurLen);
	
	void update();
	void display();

	float x, y, sinPrd, sinH, sy, rotateDeg;
	float pmt, pmt1;
	AurLine aurLine[LINENUM];

private:
};