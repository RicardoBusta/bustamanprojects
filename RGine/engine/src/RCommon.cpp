/*
 * RCommon.cpp
 *
 *  Created on: Jul 16, 2011
 *      Author: ricardo
 */

#include "RCommon.h"

#include <RString.h>

void matrixMult(float *A, float *B, int o) {
	float res[o * o];
	/*
	 a b c     j k l   s t u
	 d e f  x  m n o = v w x
	 g h i     p q r   y z @
	 */
	for	(int i=0;i<o;i++) {
		for(int j=0;j<o;j++) {
			res[i+j*o] = 0;
			for(int k=0;k<o;k++) {
				res[i+j*o] += A[i+k*o]*B[k+j*o];
			}
		}
	}
	for(int i=0;i<o*o;i++) {
		A[i] = res[i];
	}
}

void matrixPrint(float *A, int o) {
	for (int i = 0; i < o; i++) {
		for (int j = 0; j < o; j++) {
			cout << A[i + j * o]; //TODO return string instead of printing on console
		}
		cout << endl;
	}
	cout << endl;
}
