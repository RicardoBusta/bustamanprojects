/*
 * Mob.cpp
 *
 *  Created on: 06/01/2011
 *      Author: ricardo
 */

#include "Mob.h"
#include "Combat.h"

Mob::Mob() {
	// TODO Auto-generated constructor stub

}

Mob::~Mob() {
	// TODO Auto-generated destructor stub
}

void Mob::engageCombat(Mob e){
	CombatLog This;
	CombatLog Enemy;

	Combat c;
	c.getDamage(*this,e,&This);
	c.getDamage(e,*this,&Enemy);

	//Haste Effect
	if((skill.HASTE or buff.HASTE) and !(e.skill.HASTE or e.buff.HASTE))
	e.status.HP -= This.baseDamage + This.bonusDamage;
}
