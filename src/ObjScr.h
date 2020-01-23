#pragma once
#include "ofMain.h"

class ObjScr {
public:
	void init(int _x, int _y, int _dx, int _wolfX, int _grW);
	void update();
	void display();
	void clicked(int _distance, int _dir);
	void befDisp();
	void afDisp();
	int x, y, dx, distance, dir;
	int wolfX, hPos, grW;

private:
	
};