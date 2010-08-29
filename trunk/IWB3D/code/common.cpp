#include "common.h"
float max(float a, float b){
	if(a>b)
		return a;
	return b;
}

float min(float a, float b){
	if(a<b)
		return a;
	return b;
}

float sinal(float x){
	if(x>0)
		return 1;
	if(x<0)
		return -1;
	return 0;
}

float modulo(float x){
	if(x<0)
		return -x;
	return x;
}
