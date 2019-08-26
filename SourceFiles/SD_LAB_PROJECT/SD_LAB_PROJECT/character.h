#ifndef CHARACTER_h
#define CHARACTER_h

#include "declarations.h"


using namespace std;


// the following statements are used for hero standing mechanics
bool heroStanding = true;
int heroStandCounter = 0;

bool movePlayer = false;
// used when the player falls over a gap. 
bool fallAnimate = false;



typedef struct Character{

	int x, y, height, width;
	int id[100], attackID[100], attack2ID[100],deathID[100], powerID[100];
	int speed;
	int direction;
	int index, attackIndex, dyingIndex, powerIndex, attack2Index, fissureIndex;


	//BULLSHIT CODE. DONT INITIALIZE THESE HERE. WHAT ARE CONSTRUCTORS FOR???? @mustofa
	bool jump = false;
	bool jumpUp = false;
	int jump_dy = 0; // increases when hero moving up, and viceversa
	int jumpIndex = 0;


	int life, HP;
	bool show, showHP;


	bool attack; //light attack
	bool attack2; //heavy attack
	bool death;
	bool power;
	bool channelPower;
	bool chase;


	bool projectile = false;
	int projectileX, projectileY, projectileTarget;


	// level 2 boss power
	int powerX, powerY;
	bool BossMovingRight = false;
	bool BossMovingLeft = true;
	int BossTarget;


	int varHP;

	Character(int _x, int _y, int _speed)
	{
		x = _x;
		y = _y;
		speed = _speed;
		show = true;
		direction = RIGHT;
		index = 1;
		attack = false;
		attackIndex = 1; //starting the index from 0 causes bugs. a black screen renders
		life = 3;
		HP = 10;
		showHP = false;
		death = false;

		attack2 = false;
		attack2Index = 0;
	}

	Character()
	{

		speed = 10;
		show = false;
		direction = RIGHT;
		index = 0;
		attack = true;
		attackIndex = 0;
		life = 1;
		HP = 3;
		showHP = false;
		height = 60; //only for creeps. edit this later by adding another function call or constructor
		width = 100;//only for creeps. edit this later by adding another function call or constructor
		varHP = 60; //width of HP bar of creeps. it changes
		death = false;
		powerIndex = 0;
		attack2Index = 0;
	}

	Character(int _x, int _y, int _speed, bool _show, int _direction, int _index, int _attackIndex, bool _attack)
	{
		x = _x;
		y = _y;
		speed = _speed;
		show = _show;
		direction = _direction;
		index = _index;
		attackIndex = _attackIndex;
		attack = _attack;
	}
	void setVisibility(bool _show, bool _attack, bool _death, bool _power, bool _channelPower)
	{
		 show = _show;
		 attack= _attack;
		 death = _death;
		 power = _power;
		 channelPower = _channelPower;
		
	}

	void initializeLocation(int _x, int _y) //ADD MORE LATER
	{
		x = _x;
		y = _y;
		
	}
	void initializeMechanics(int _speed, int _HP, int _life, int _varHP)
	{
		speed = _speed;
		HP = _HP;
		life = _life;
		varHP = _varHP;
	}
	void initializeDimensions(int _width, int _height)
	{
		width = _width;
		height = _height;
	}
	void setDirection(int _direction)
	{
		direction = _direction;
	}



}Character;

Character hero(0, tileHeight - 16, 20), L1Boss, L2Boss, princess;
Character creeps[30];



int creepAttackIndex = 0; //if the instance variable "attackIndex" is used, then bugs occur, ie instead of iterating the index thu 1-12, it only iterates 1-10. Using this no problem seems to occur

void initPrincess()
{
	princess.index = 1;
	princess.x = 1100;
	princess.y = 200;

	princessCutscene = true;
	cutsceneIndex = 13;
	princessSegment = true;

	//called here again to initialize the hero.x coordinates
	initializeCutscenes2();
	cutsceneIndex = 13;

}

void loadImagesPrincess()
{
	// loading images of princess: indexed 1-11
	princess.id[1] = iLoadImage("images\\character\\princess\\Layer 2.png");
	princess.id[2] = iLoadImage("images\\character\\princess\\Layer 3.png");
	princess.id[3] = iLoadImage("images\\character\\princess\\Layer 4.png");
	princess.id[4] = iLoadImage("images\\character\\princess\\Layer 5.png");
	princess.id[5] = iLoadImage("images\\character\\princess\\Layer 6.png");
	princess.id[6] = iLoadImage("images\\character\\princess\\Layer 7.png");
	princess.id[7] = iLoadImage("images\\character\\princess\\Layer 8.png");
	princess.id[8] = iLoadImage("images\\character\\princess\\Layer 9.png");
	princess.id[9] = iLoadImage("images\\character\\princess\\Layer 10.png");
	princess.id[10] = iLoadImage("images\\character\\princess\\Layer 11.png");
	princess.id[11] = iLoadImage("images\\character\\princess\\Layer 12.png");
}

#endif