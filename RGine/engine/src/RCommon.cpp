/**
 * @file
 * @author Ricardo Bustamante de Queiroz <ricardobqueiroz@gmail.com>
 * @version
 *
 * @section LICENSE
 *
 * This file is part of RGine.
 *
 * RGine is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Foobar is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with RGine.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @section DESCRIPTION
 *
 * File: RCommon.cpp
 * Created on: Aug 5, 2011
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
