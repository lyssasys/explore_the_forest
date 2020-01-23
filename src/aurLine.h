#pragma once
#include "ofMain.h"

class AurLine {
public:
	void init(int _aurLen, float _alpha, float _dAlp);
	static float chngAlp(float _alp, float _dAlp);
	static float chngDAlp(float _alp, float _dAlp);
	void update();
	void display(float x, float y);

	int aurLen;
	float dAlp;
	float alpha;
	float alpPmt;

private:
};
