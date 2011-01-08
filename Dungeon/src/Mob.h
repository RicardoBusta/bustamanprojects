/*
 * Mob.h
 *
 *  Created on: 06/01/2011
 *      Author: ricardo
 */

#ifndef MOB_H_
#define MOB_H_

#include <string>
using namespace std;

class Map;

//Attribute Structure
struct Status{
	string tooltip;	//Describes the status
	int base;		//Basic Number
	int bonus;		//Percentage applied over base
	int growth;		//Ammount gained on level up
	Status(){
		tooltip = "NIL";
		base = bonus = growth = 0;
	}
};

struct CombatLog{
	int HP;
	int MHP;
	int MP;
	int MMP;
	int EXP;
	int bonusDamage;
	int baseDamage;
	int totalDamage;
};

//Game Mob - Might be a hero or monster
class Mob{
private:
	//Map Positioning
	struct POSITION{
		int x, y;
		POSITION(){
			x=y=0;
		}
	}position;
	//Basic Attributes
	struct STATUS{
		int LVL;		//Level		- The current level. Should range from 1 to 10
		int HP;
		int MP;
		int EXP;
		Status MHP;		//Max Health- 0 = dead
		Status MMP;		//Max Mana 	- Used to cast spells
		Status ATK;		//Attack	- Ammount of damage given
		Status DEF;		//Defense	- Reduces phisical damage recieved
		Status MAG;		//Magic		- Magic Damage
		Status RES;		//Resist	- Magic Resistance
		STATUS(){
			LVL=HP=MP=EXP=0;
		}
	}status;

	//Special Attributes
	struct SPECIAL{
		int CRT;		//Critical	- Percentage of damage added over final damage
		int CRC;		//Chance	- % chance to trigger critical
		int DOD;		//Dodge		- % chance to trigger dodge (Don't take phisical damage)
		SPECIAL(){
			CRC = DOD = CRT = 0;
		}
	}special;

	//Skill
	struct SKILL{
		bool HASTE;		//Haste - Have permanent first strike
		SKILL(){
			HASTE = false;
		}
	}skill;

	//Buffs
	struct BUFF{
		bool HASTE;		//Haste - Have first strike
		BUFF(){
			HASTE = false;
		}
	}buff;

	//Debuffs
	struct DEBUFF{
		bool DEAD;		//Dead			- Will show dead sprite and do nothing
		bool PSN;		//Poisoned		- Lose HP every action
		bool CUR;		//Cursed		- Will not regenerate HP
		bool CON;		//Confusion		- Random Movement
		bool MBR;		//ManaBurned 	- Will not regenerate MANA
		bool STN;		//Stone			- Count as a wall with living greyscale sprite
		bool SIL;		//Silenced		- Cannot use scrolls
		DEBUFF(){
			DEAD = PSN = CUR = CON = MBR = STN = SIL = false;
		}
	}debuff;

	//Inventory
	struct INVENTORY{
		int HPOT;			//Ammount of Health potions
		int MPOT;			//Ammount of Mana Potions
		int GOLD;			//Gold
		int FAITH;			//Ammount of faith
		INVENTORY(){
			HPOT = MPOT = GOLD = FAITH = 0;
		}
	}inventory;

	//Scrolls
	//Scroll *scr1;
	//Scroll *scr2;
	//Scroll *scr3;

	//Combat Methods
	void previewCombat(Mob m);
	void engageCombat(Mob m);

	//Class and Race
	void setClass(int c);
	void setRace(int r);

	//Other
	void lvlUp();

	//Extra
	friend class Combat;
public:
	Mob();
	virtual ~Mob();

	//Test
	virtual void draw();
	bool setPosition(int x, int y, Map *m);
	bool move(int x, int y, Map *m);
};

#endif /* HERO_H_ */
