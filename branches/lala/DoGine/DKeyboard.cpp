#include "DKeyboard.h"

DKeyboard::DKeyboard() {
    isDown = false;
    hit = false;
    release = false;
}

DKeyboard::~DKeyboard() {
}

void DKeyboard::reset(){
	hit = false;
	release = false;
}
