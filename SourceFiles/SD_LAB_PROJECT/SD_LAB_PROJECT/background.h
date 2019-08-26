#ifndef BACKGROUND_h
#define BACKGROUND_h

#include "declarations.h"
#include "character.h"
#include "creeps.h"

using namespace std;


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


/*
Loads the images of level 1 background
*/
void loadImagesBackground()
{
	//*********************loading backgrounds*******************************
	screen.id = iLoadImage("images\\background\\back.png");
	screen2.id = iLoadImage("images\\background\\back2.png");
	tile.id = iLoadImage("images\\background\\front.png");

   


}

/*
Loads the images of level 2 background
*/
void loadImagesBackground2()
{

	screen.id = iLoadImage("images\\background\\L2Screen.png");
	tile.id = iLoadImage("images\\background\\L2Tile.png");
	screen2.id = 0;

	
}

/*
Shows the background of level 1 or level 2
- typical call would be from iDraw()
*/
void showBackground()
{
	
	if (level_1)
	{
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

		iShowImage(screen.x, screen.y, screen.width, screen.height, screen.id);
		iShowImage(tile.x, tile.y, tile.width, tile.height, tile.id);

		if (backgroundEnd) 	//show a red blockage at 0,194 and 1366,194 coordinate. player cant move left 
		{
			iShowImage(0, tileHeight, 81, 354, blockID_L);
			iShowImage(1300, tileHeight, 81, 354, blockID_R);

		}

	}


	
}

/*
moves the screen to the specified direction at the rate of screen.speed
- typical call would be from iSpecialKeyboard();
  It's also called from fix_Background() to automatically restore the background after crossing the bridgeSegment
*/
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


/*
moves the tile to the specified direction at the rate of tile.speed
- typical call would be from iSpecialKeyboard();
It's also called from fix_Background() to automatically restore the background after crossing the bridgeSegment
*/
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


/*
calling it will automatically fix the background after crossing bridgeSegment.
the variable backgroundCounter is used to vary the change
- typical call would be from a timer Function to fix the background. 
*/
void fix_Background(int dir) //dir indicates direction in which player is moving, right means moving right
{
	if (dir == RIGHT)
	{
		moveTile(LEFT);
		moveScreen(LEFT);

		// if not used, then it feels like creeps are moving wrt to the background
		counterMotion(HERO, RIGHT, AUTO); 
		counterMotion(CREEPS, RIGHT, AUTO);
		
	}


	if (dir == LEFT)
	{
		moveTile(RIGHT);
		moveScreen(RIGHT);
	
		// if not used, then it feels like creeps are moving wrt to the background
		counterMotion(HERO, LEFT, AUTO);
		counterMotion(CREEPS, LEFT, AUTO);


	}

	// indicates how much the background is suppose to be moved. Increasing it means the background will shift more
	backgroundCounter++;

	if (backgroundCounter >= 30)
	{
		fixBackground = false;
		backgroundCounter = 0;

	}
}


/*
to counter the speed of background motion. Or else looks as if creeps/enemies are moving wrt the background
the function is called implicitly from fix_background();
- typical call would be from iSpecialKeyboard() when the player moves
*/
void counterMotion(int character, int dir, int mode) 	  
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


/*
percieves the environment using iGetPixelColor() and using coordinates to check triggers for creeps/boss/cutscenes
- typical call would be from iSpecialKeyboard() when hero moves or from a timer function to continuosly keep on checking for triggers
*/
void environmentTriggers()
{

	if (level_2)
		return;
	
	switch (stage)
	{
		case 0:  //checking for creeps triggers (mummy)
			
			if (screen.x < -1130)
			{

				

				// //used for debug purposes, ie the boss spawns immediately in the first trigger. This helps to transition to level 2 quickly
				//
				/*moveBoss = true;
				backgroundEnd = true;    //boss triggers
				bossSegment = true;
				bossSpawn();
				stage++;
				*/

				iPauseTimer(timer_ENEMYMOTION); // timer paused so that creeps dont move while player reads cutscene. It gets resumed when player presses space
				cutscene = true;
				cutsceneIndex = 0;
				initializeCutscenes(); // needs to be called here to get the coordinate of hero accordingly


				creepsSegment = true; //creep triggers
				spawnCreeps();


				objectiveIndex = 1; // changing objective to show "kill all enemies!"
				objective[objectiveIndex].show = true;

				waveIndex++; // to iterate through the indexes of the wave object ID of type UserInterface
				stage++; // to indicate which stage is currently running, ie, stage=0 means the first creepstage
			}
		
	
			break;


		case 1: //checking for creeps triggers (canon)

			creepTriggers(255, 126, 0, 150, 230);



			break;

		case 2: //checking for creeps triggers (green box)


			creepTriggers(0, 255, 0, 150, 230);

			break;



		case 3:  //  when hero enters cave: cutscene

			iGetPixelColor(hero.x + 150, 314, checkTriggers);

			if ( (checkTriggers[0] == 75 && checkTriggers[1] == 59 && checkTriggers[2] == 64 ) && waveClear)
			{

				cutscene = true;

				// timer is paused so that any creeps spawned will stop at their location
				iPauseTimer(timer_ENEMYMOTION);
				initializeCutscenes();
				stage++;

			}

			// continously checks if creeps are dead, if they are, then the next stage will occur
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

				//spawns a number of creeps again to make it tougher
				//spawnCreeps();
			
				stage++;

			}

			break;


		case 5:  // trigger for but cutscenes


			// the block will be executed when the boss moves a certain distance.
			if (bossCutscene)
			{
				iPauseTimer(timer_ENEMYMOTION);
			}

			break;

	}


}


/*
percieves the environment and uses the coordinate system for creeps/boss/cutscene
- typical call would be from iSpecialKeyboard() when hero moves or from a timer function to continuosly keep on checking for triggers
uses creepsTriggerCounter to navigate through the different stages
*/

void environmentTriggers2(int mode)
{
	
//	cout << "screen.x:  " << screen.x << endl;


	if (screen.x <= -1000 && screen.x >= -1500 && !temp_8) 
	{
		objectiveIndex = 4; 
		objective[objectiveIndex].show = true;
		temp_8 = true;

	}


	/*****************************SLOPE***************************************************/

	if (mode == SLOPE)
	{

		if (screen.x <= -1380 && screen.x >= -5100)
		{
			SlopeSegment = true;
			objective[objectiveIndex].show = false; // turning the "press space to jump" objective false. ie it wont be shown

		}
		else
			SlopeSegment = false;



		if (SlopeSegment)
		{


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
			
			// for debug purposes, the boss spawns early
			
			/*backgroundEnd = true;
			creepsSegment = false;
			bossSegment = true;
			bossSpawn();
			*/
			

			objectiveIndex = 3; // changing objective to show "PRESS D FOR SPECIAL POWER"
			objective[objectiveIndex].show = true;
			waveIndex++;
			
			creepsSegment = true;
			spawnCreeps();
			CreepsTriggerCounter++;

		}


		else if (CreepsTriggerCounter == 2) // second creep segment :: inside slopeSegment, so creeps.y must be low
		{ 
		
			if (screen.x == -3440 && waveClear)
			{

			//	// for debug purposes
			//backgroundEnd = true;
			//creepsSegment = false;
			//bossSegment = true;
			//bossSpawn();




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


		else if (CreepsTriggerCounter == 3)  // third creep segment
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

		else if (CreepsTriggerCounter == 4) // BOSS TRIGGER
		{

			if (screen.x == -9540 && waveClear)
			{
				// boss spawns

				backgroundEnd = true;   
				creepsSegment = false;
				bossSegment = true;
				bossSpawn();
		
				bossCutscene = true;
			
				initializeCutscenes2();
				cutsceneIndex = 7; // for boss
				iPauseTimer(timer_ENEMYMOTION);

				CreepsTriggerCounter++;

				tile.x += 200;

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