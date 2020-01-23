#include "Moon.h";

void Moon::init(float _deg, float _r, float _size, float _speed) {
	Star::init(_deg, _r, _size, _speed, 255);
}

void Moon::update() {
	Star::update();
	if (deg < 0) {
		deg = 120;
	}

	//cout << deg;
}

void Moon::display() {
	Star::display();
}