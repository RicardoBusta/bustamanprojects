/*
 * REntity.h
 *
 *  Created on: Jul 15, 2011
 *      Author: ricardo
 */

#ifndef RENTITY_H_
#define RENTITY_H_

//TODO this class will be every single object handled in this game

#include <RFrame.h>

class REntity {
public:
	REntity();
	virtual ~REntity();

	void handle();
private:
	RFrame frame;
};

#endif /* RENTITY_H_ */
