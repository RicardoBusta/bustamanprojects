#include "DMouse.h"

DMouse::DMouse(){
	left.hit = false;
	left.release = false;
	left.isDown = false;

	right.hit = false;
	right.release = false;
	right.isDown = false;

	middle.hit = false;
	middle.release = false;
	middle.isDown = false;

	speed.x = 0;
	speed.y = 0;

	position.x = 0;
	position.y = 0;
}

void DMouse::reset(){
	left.hit = false;
	left.release = false;

	right.hit = false;
	right.release = false;

	middle.hit = false;
	right.release = false;

	speed.x = 0;
	speed.y = 0;
}
