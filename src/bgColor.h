#pragma once
#include "ofMain.h"

class BgColor
{
public:
	void init(int _y, float _md, float _sR, float _sG, float _sB, float _eR, float _eG, float _eB);
	void update();
	void display();

	int bgY, md_y;
	float sR, sG, sB, R, G, B, dR, dG, dB;


private:

};

