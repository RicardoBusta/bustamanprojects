/*
 * Mob.cpp
 *
 *  Created on: 06/01/2011
 *      Author: ricardo
 */

#include "Mob.h"
#include "Combat.h"

#include "Map.h"

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
		glColor3f(1,1,1);
		glVertex3f(0,0,scale+1);
		glVertex3f(scale,0,scale+1);
		glVertex3f(scale,scale,scale+1);
		glVertex3f(0,scale,scale+1);
}

bool Mob::setPosition(int x, int y, Map *m){
	if(x>=0 and x<m->width and y>=0 and y<m->height and m->tile[x+m->width*y].mob==NULL){
		m->tile[x+m->width*y].mob = this;
		position.x = x;
		position.y = y;
		return true;
	}
	return false;
}

bool Mob::move(int x, int y, Map *m){
	int nx = position.x+x, ny = position.y+y;
	if(nx>=0 and nx<m->width and ny>=0 and ny<m->height and !m->tile[nx+m->width*ny].wall and m->tile[nx+m->width*ny].mob==NULL){
		m->tile[position.x+m->width*position.y].mob=NULL;
		m->tile[nx+m->width*ny].mob=this;
		position.x = nx;
		position.y = ny;
		return true;
	}
	return false;
}
