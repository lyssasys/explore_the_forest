#include "Wolf.h"

void Wolf::init(int _x, int _y, int _speed) {
	
	//walking sound
	walk.load("sound/bush.mp3");
	walk.setLoop(true);
	walk.setVolume(0.1);

	wolfW = ofGetWidth() * 0.2;
	wolfH = wolfW / 16.0 * 9.0;

	x = _x;
	y = _y - wolfH;

	wolfCX = x + (wolfW / 2);
	gX = wolfCX;
	gY = y;
	distance = 0;
	speed = _speed;
	imgNum = 0;

	

	for (int i = 0; i < 65; i++) {
		std::string fileNum;
		fileNum = std::to_string(i);
		if (i < 10) {
			fileNum = "0" + fileNum;
		}

		filePath = "wolf/wolf_000" + fileNum;
		filePath = filePath + ".png";
		wolfImage[i].load(filePath);
		//cout << filePath << "\n";

	}
	
}

void Wolf::update() {
	//wolfCX = x + (wolfW / 2);


	if (distance >0) {// move wolf to clicked point
		
		distance = distance - speed;

		imgNum++;
		if (imgNum >= 65) {
			imgNum = 0;
		}
	}
	if (distance <= 0 ) {
		walk.stop();
	}

	


}

	

void Wolf::display() {
	
	ofSetColor(0, 0, 0);
	wolfImage[imgNum].draw(x, y, wolfW, wolfH);
	

	//DEBUG point (x, y)
	//ofSetColor(255, 0, 0);
	//ofDrawCircle(x, y, 3);
	//ofSetColor(0, 0, 0);

}

void Wolf::clicked(int _gX, int _gY) {
	gX = _gX;
	gY = _gY;
	distance = abs(gX - x);
	direction();

	walk.play();
}

int Wolf::rtnWolfX() {
	//return wolfCX;
	return x;
}


void Wolf::direction() {
	if (gX > wolfCX && wolfW > 0 || gX < wolfCX && wolfW < 0) {
		x = wolfW + x;
		wolfW = wolfW * -1;	
		
	}

}