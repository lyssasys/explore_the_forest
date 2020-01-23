#pragma once
#include "ofMain.h"

class Star
{
public:
	void init(float _deg, float _r, float _size, float _speed, float _alpha);
	void update();
	void display();
	float deg, r, rad, x, y, size, speed, alpha;

private:
	
};

