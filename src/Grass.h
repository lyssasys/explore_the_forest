#pragma once
#include "ofMain.h"
#include "ObjScr.h"

class Grass: public ObjScr {
public:

	void init(int _x, int _y, int _dx, int _h, int _wolfX, int _grW);
	void update(int _wolfFHX, int _windX);
	void display();
	void clicked(int _distance, int _dir);
	int w, h, tipX;
	int hPos;
	float movePmt;
	float windPmt;

private:
};

