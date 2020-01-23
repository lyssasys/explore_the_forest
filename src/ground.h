#pragma once
#include "ofMain.h"
#include "ObjScr.h"
#include "Grass.h"
#include "Building.h"
#include "Tree.h"

#define GRASSNUM 1000
#define TREENUM 7
class Ground {
public:
	
	void init(int _level, int _gLine, int _speed, int _wolfX, int _grW);
	void update(int _wolfFHX);
	void display();
	void clicked(int wolfX, int gX);
	
	int grW;
	int windX;
	float windPmt;
	int level, gLine, speed, scrDx;
	float grassPmt;
	
	Grass grass[GRASSNUM];
	Tree tree[TREENUM];

private:
};