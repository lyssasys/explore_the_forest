#pragma once
#include "ofMain.h"
#include "ObjScr.h"

class  Tree : public ObjScr {
public:
	void init(int _rootx, int _rooty, int _dx, int _h, int _lvNum, int _wolfX, int _grW);
	void update(int _windX);
	void display();
	void branch(int _h, int _node, int _deg, int _lv, float _degPmtR, float _degPmtL);
	void clicked(int _distance, int _dir);
	int radian(int _deg);

	int rootx, rooty;
	int h, lvNum;
	int node;
	int childNode;

	float degPmtR;
	float degPmtL;
	float dnyPmt;
	int deg;

	float windPmt;


private:

};