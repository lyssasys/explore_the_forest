#pragma once
#define WOLFNUM 65;
#include "ofMain.h"

class Wolf {
public:
	void init(int _x, int _y, int _speed);
	void update();
	void display();
	void clicked(int _gX, int _gY);
	int rtnWolfX();
	void direction();
	int x, y, gX, gY, fileNum,imgNum, wolfW, wolfH,wolfCX, speed, dir, distance;
	string filePath;
	ofImage wolfImage[65];
	ofSoundPlayer walk;

private:

};