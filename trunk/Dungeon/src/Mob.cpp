/*
 * Mob.cpp
 *
 *  Created on: 06/01/2011
 *      Author: ricardo
 */

#include "Mob.h"
#include "Combat.h"

//TODO remove this when implemented models
#include <SDL/SDL_opengl.h>

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

void Mob::draw(){
	float scale = 32;
	int i=3;
	int j=3;
	glBegin(GL_QUADS);
		glColor3f(1,1,1);
		glVertex3f(i*scale,j*scale,10);

		glVertex3f((i+1)*scale,j*scale,10);

		glVertex3f((i+1)*scale,(j+1)*scale,10);

		glVertex3f(i*scale,(j+1)*scale,10);
	glEnd();
}
