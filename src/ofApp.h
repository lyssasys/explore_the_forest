


#include <stdio.h>
#include <string>
#include "ofMain.h"
#include "Star.h"
#include "Wolf.h"
#include"Moon.h"

#include "ground.h"
#include "bgColor.h"
#include "Aurora.h"

#pragma once
#define STARNUM 400
#define GROUNDLV 2


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		ofSoundPlayer wind;
	
	Star stars[STARNUM];
	//Star moon;
	Moon moon;
    Wolf wolf;

	Ground ground[GROUNDLV];
	BgColor bg;
	Aurora aurora;

};
