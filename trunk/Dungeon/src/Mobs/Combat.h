/*
 * Combat.h
 *
 *  Created on: 06/01/2011
 *      Author: ricardo
 */

#ifndef COMBAT_H_
#define COMBAT_H_

#include "Mob.h"

class Combat {
public:
	void getDamage(Mob atk, Mob def, CombatLog *log);

	Combat();
	virtual ~Combat();
};

#endif /* COMBAT_H_ */
