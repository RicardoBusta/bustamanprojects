/*
 * RCommon.h
 *
 *  Created on: Jul 16, 2011
 *      Author: ricardo
 */

#ifndef RCOMMON_H_
#define RCOMMON_H_

/*
 * Multiply a matrix A*B where A and B are square and of order 'o'
 */
void matrixMult(float *A, float *B, int o);

/*
 * Print Matrix with std cout
 */
void matrixPrint(float *A, int o);

#endif /* RCOMMON_H_ */
