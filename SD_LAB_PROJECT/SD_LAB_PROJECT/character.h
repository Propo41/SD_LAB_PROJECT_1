#ifndef CHARACTER_h
#define CHARACTER_h

#include "declarations.h"


using namespace std;


bool heroStanding = true;
int heroStandCounter = 0;
int actualHeroX;

bool movePlayer = false;
bool fallAnimate = false;


typedef struct Character{

	int x, y, height, width;
	int id[100], attackID[100], attack2ID[100],deathID[100], powerID[100];
	int speed;
	int direction;
	int index, attackIndex, dyingIndex, powerIndex, attack2Index, fissureIndex;

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

Character hero(0, tileHeight - 16, 20), L1Boss, L2Boss;
Character hero2;
Character creeps[30];



int creepAttackIndex = 0; //if the instance variable "attackIndex" is used, then bugs occur, ie instead of iterating the index thu 1-12, it only iterates 1-10. Using this no problem seems to occur



#endif