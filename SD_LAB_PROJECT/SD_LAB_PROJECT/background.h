#ifndef BACKGROUND_h
#define BACKGROUND_h

#include "declarations.h"
#include "character.h"
#include "creeps.h"

using namespace std;


/*
Slope related stuff are in functions: 

1. environmentTriggers2(); ( was previously called checkSegments() )
2. heroMovement(); 

*/



int blockID_L;
int blockID_R;

bool fixBackground = false;
int backgroundCounter = 0;
int rainIndex = 0;
int temp_4 = false;


bool HeroGoingDown = false;
bool HeroGoingUp = false;
bool leftSlope = false;
bool RightSlope = false;

const int backgroundConstrain_1= -1000; // used as a reference variable. its used to stop the background moving when player tries to reach the bridgesegment again by pressing LEFT
										// after fixBackground is used after crossing bridgeSegment, the value of screen.x becomes -1000. Thus this reference -1000 is used

const int backgroundConstrain_2 = 0; // level 2: initially the player cannot go any further to the left.


typedef struct background{

	int x, y, id;
	int width, height;
	int speed;
	background()
	{
	}

	background(int _x, int _y, int _speed, int _width, int _height)
	{
		x = _x;
		y = _y;
		speed = _speed;
		width = _width;
		height = _height;
	}

	void resetValues(int _x, int _y, int _speed, int _width, int _height)
	{
		x = _x;
		y = _y;
		speed = _speed;
		width = _width;
		height = _height;

	}



}background;

background tile(0,0,25, 10928, 453), screen(0,0,25,10928,768), screen2(10928,0, 30, 2732, 768), rain;
int temp = 0;



void loadImagesBackground()
{
	//*********************loading backgrounds*******************************
	screen.id = iLoadImage("images\\background\\back.png");
	screen2.id = iLoadImage("images\\background\\back2.png");
	tile.id = iLoadImage("images\\background\\front.png");

    //************************************************************************
	blockID_L = iLoadImage("images\\background\\block-L.png"); // mystic arts blockage
	blockID_R = iLoadImage("images\\background\\block-R.png");


}

void loadImagesBackground2()
{

	//cout << "inside loadImages 2" << endl;

	screen.id = iLoadImage("images\\background\\L2Screen.png");
	tile.id = iLoadImage("images\\background\\L2Tile.png");
	screen2.id = 0;



}


void showBackground()
{
	
	if (level_1)
	{
		//cout << "level 1" << endl;
		iShowImage(screen.x, screen.y, screen.width, screen.height, screen.id);
		iShowImage(screen2.x, screen2.y, screen2.width, screen2.height, screen2.id);

		iShowImage(tile.x, tile.y, tile.width, tile.height, tile.id);

		if (backgroundEnd) 	//show a red blockage at 0,194 and 1366,194 coordinate. player cant move left 
		{
			iShowImage(0, tileHeight, 81, 354, blockID_L);
			iShowImage(1300, tileHeight, 81, 354, blockID_R);

		}
	}
	else
	{

		//cout << "level 2" << endl;

		iShowImage(screen.x, screen.y, screen.width, screen.height, screen.id);
		iShowImage(tile.x, tile.y, tile.width, tile.height, tile.id);

		if (backgroundEnd) 	//show a red blockage at 0,194 and 1366,194 coordinate. player cant move left 
		{
			iShowImage(0, tileHeight, 81, 354, blockID_L);
			iShowImage(1300, tileHeight, 81, 354, blockID_R);

		}

	}


	
}


void moveScreen(int dir)
{



	
		if (dir == LEFT)
		{
			screen.x -= screen.speed;
			screen2.x -= screen2.speed;

		}
		else
		{

			screen.x += screen.speed;
			screen2.x += screen2.speed;



		}
	


}

void moveTile(int dir)
{

	
	 
	if (dir == LEFT) // moving background left, means player is moving right
	{
		
		tile.x -= tile.speed;


	}

	else
	{
		//moving background right, means player is moving left
		
		tile.x += tile.speed;	
	
	}
}

void fix_Background(int dir) //dir indicates direction in which player is moving, right means moving right
{
	if (dir == RIGHT)
	{
		moveTile(LEFT);
		moveScreen(LEFT);

		counterMotion(HERO, RIGHT, AUTO);
		counterMotion(CREEPS, RIGHT, AUTO);
		
	}


	if (dir == LEFT)
	{
		moveTile(RIGHT);
		moveScreen(RIGHT);
	
		counterMotion(HERO, LEFT, AUTO);
		counterMotion(CREEPS, LEFT, AUTO);


	}

	backgroundCounter++;

	if (backgroundCounter >= 30)
	{
		fixBackground = false;
		backgroundCounter = 0;

	}
}

void counterMotion(int character, int dir, int mode) 	   //to counter the speed of background motion. Or else looks as if player is moving
{
	if (character == HERO)
	{
		
		if (mode == AUTO)
		{
			if (dir == LEFT)
			{
				if (heroStanding)
					hero.x += tile.speed;

			}
			if (dir == RIGHT)
			{
				if (heroStanding)
					hero.x -= tile.speed;
			}
		}
		
	}

	if (character == CREEPS)
	{
		if (dir == LEFT)
		{
			for (int j = 0; j < creepsCount; j++)  //counters the motion of creeps. 
			{

				creeps[j].x += (tile.speed);

			}
		}
		if (dir == RIGHT)
		{

			for (int j = 0; j < creepsCount; j++)  //counters the motion of creeps. 
			{
				creeps[j].x -=  (tile.speed);

			}

		}

	}

}

void environmentTriggers()
{
	if (level_2)
		return;
	
	switch (stage)
	{
		case 0:  //checking for creeps triggers (mummy)
			
			if (screen.x < -1130)
			{
				backgroundEnd = true;    //boss triggers
				bossSegment = true;
				bossSpawn();
				stage++;



				iPauseTimer(timer_ENEMYMOTION); // timer paused so that creeps dont move while player reads cutscene. It gets resumed when player presses space
				cutscene = true;
				initializeCutscenes(); // needs to be called here to get the coordinate of hero accordingly


				creepsSegment = true; //creep triggers
				spawnCreeps();


				objectiveIndex = 1; // changing objective to show "kill all enemies!"
				objective[objectiveIndex].show = true;

				waveIndex++;
				stage++;
			}
		
	
			break;


		case 1: //checking for creeps triggers (canon)

			creepTriggers(255, 126, 0, 150, 230);



			break;

		case 2: //checking for creeps triggers (green box)


			creepTriggers(0, 255, 0, 150, 230);

			break;



		case 3: 

		//	cout << "case :  3" << endl;

			iGetPixelColor(hero.x + 150, 314, checkTriggers);

			if ( (checkTriggers[0] == 75 && checkTriggers[1] == 59 && checkTriggers[2] == 64 ) && waveClear)
			{
			//	cout << "entered cave" << endl;

				cutscene = true;
				iPauseTimer(timer_ENEMYMOTION);
				initializeCutscenes();
				stage++;

			}

			if (creepsCount>0)
				checkCreepsAlive();


			break;




		case 4: // checking for bossTrigger (banner)



			iGetPixelColor(hero.x + 150, 313, checkTriggers);

			if ( (checkTriggers[0] == 255 && checkTriggers[1] == 255 && checkTriggers[2] == 255)  && waveClear)
			{
				moveBoss = true;
				backgroundEnd = true;    //boss triggers
				bossSegment = true;
				bossSpawn();
			
				stage++;

			}

			break;


		case 5: 


			if (bossCutscene)
			{
				iPauseTimer(timer_ENEMYMOTION);
			}

			break;

	}



	if (bridgeSegment)
	{
		if (hero.direction == RIGHT)
		{


			iGetPixelColor(hero.x + 100, tileHeight - 10, checkGap);
			if (checkGap[0] != 0 && checkGap[1] != 0 && checkGap[2] != 0)
			{
				fallAnimate = true;
			}
		}
		if (hero.direction == LEFT)
		{


			iGetPixelColor(hero.x + 50, tileHeight - 10, checkGap);

			if (checkGap[0] != 0 && checkGap[1] != 0 && checkGap[2] != 0)
			{
				fallAnimate = true;
			}

		}

	}





}

bool temp_8 = false;

void environmentTriggers2(int mode)
{
	
//	cout << "screen.x:  " << screen.x << endl;


	if (screen.x <= -1000 && screen.x >= -1500 && !temp_8) // temp_8 is used for entering once inside this block. ie the objective "space to jump" will only be shown once the hero is within the given range
	{
		objectiveIndex = 4; 
		objective[objectiveIndex].show = true;
		temp_8 = true;

	}


	/*****************************SLOPE***************************************************/

	if (mode == SLOPE)
	{
		//cout << "slope mode " << endl;

		if (screen.x <= -1380 && screen.x >= -5100)
		{
			SlopeSegment = true;
			objective[objectiveIndex].show = false; // turning the "press space to jump" objective false. ie it wont be shown

		}
		else
			SlopeSegment = false;



		if (SlopeSegment)
		{
		//	cout << "slope segment " << endl;


			if (screen.x <= -1820 && screen.x >= -2020)
			{  //left slope
				leftSlope = true;

			}
			else
				leftSlope = false;


			if (screen.x <= -4820 && screen.x >= -4980)  // right slope
				RightSlope = true;
			else
				RightSlope = false;

		}
	}
	

	/***********************CREEPS TRIGGER***************************************************/

	if (mode == CREEPS)
	{

		if (CreepsTriggerCounter == 1 && screen.x == -500){  // first creep segment
			
			//// for debug purposes, the boss spawns early
			//moveBoss = true;
			//backgroundEnd = true;
			//bossSegment = true;

			//bossSpawn();
			//


	
			objectiveIndex = 3; // changing objective to show "PRESS D FOR SPECIAL POWER"
			objective[objectiveIndex].show = true;
			waveIndex++;
			

	
			creepsSegment = true;
			spawnCreeps();
			CreepsTriggerCounter++;

		}


		if (CreepsTriggerCounter == 2) // second creep segment :: inside slopeSegment, so creeps.y must be low
		{ 
		
			if (screen.x == -3440 && waveClear)
			{

				spawnCreeps();
				CreepsTriggerCounter++;
				waveIndex++;

				waveClear = false;


				objectiveIndex = 1; // changing objective to show "kill all enemies!"
				objective[objectiveIndex].show = true;


			
			}

			if (creepsCount>0)
				checkCreepsAlive();

			

		}


		if (CreepsTriggerCounter == 3)  // third creep segment
		{

			if (screen.x == -6000 && waveClear)
			{
				spawnCreeps();
				CreepsTriggerCounter++;
				waveIndex++;


				waveClear = false;

				objectiveIndex = 1; // changing objective to show "kill all enemies!"
				objective[objectiveIndex].show = true;
			}
			

			if (creepsCount > 0)
				checkCreepsAlive();

		}

		if (CreepsTriggerCounter == 4) // BOSS TRIGGER
		{

			if (screen.x == -9540 && waveClear)
			{
				// boss spawns
				moveBoss = true;
				backgroundEnd = true;   
				creepsSegment = false;
				bossSpawn();
				bossSegment = true;
				

				CreepsTriggerCounter++;



			}

			if (creepsCount > 0)
				checkCreepsAlive();
		}

	}



	if (mode == FALL)
	{
		// controlling fall animate from here


		if ((screen.x <= -1200 && screen.x >= -1300) && (hero.y + hero.jump_dy) == 180)
		{
			fallAnimate = true;


		}

	}

}





#endif