#pragma once
#include "ofMain.h"
#include "Star.h"

class Moon: public Star {
public:
	void init(float _deg, float _r, float _size, float _speed);
	void update();
	void display();
private:

};
