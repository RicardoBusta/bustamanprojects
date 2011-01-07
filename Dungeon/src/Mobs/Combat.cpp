/*
 * Combat.cpp
 *
 *  Created on: 06/01/2011
 *      Author: ricardo
 */

#include "Combat.h"

#include "stdlib.h"

Combat::Combat() {
	// TODO Auto-generated constructor stub

}

Combat::~Combat() {
	// TODO Auto-generated destructor stub
}

void Combat::getDamage(Mob atk, Mob def, CombatLog *log){
	//**Base Damage**
	log->baseDamage = atk.status.ATK.base*(1+atk.status.ATK.bonus) - def.status.DEF.base*(1+def.status.DEF.bonus);

	//**Bonus Damage**
	//Critical
	if(atk.special.CRC >= (rand()%100)+1)
		log->bonusDamage += (log->baseDamage*atk.special.CRT);

	//**Total Damage**
	log->totalDamage = log->baseDamage + log->bonusDamage;
}
