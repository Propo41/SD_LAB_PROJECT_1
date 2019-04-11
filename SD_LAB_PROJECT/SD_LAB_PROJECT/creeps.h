#ifndef creeps_h
#define creeps_h

#include "declarations.h"
#include "character.h"
#include "boss.h"
#include "UIEffects.h"
//#include "hero.h"



/*
Timer functions used here are : 
	1. checkCreepsAlive();
	2. creepAttackLogic();
	3. creepDamage();
	4. creepHurtLogic(); : effects animation
	5. creepsMovement();
	6. creepTriggers();
Functions that are explicitly are :
	1. creepDamage(); : called from heroAttack()
	2. loadImagesCreep(); : called from main()
*/



//RIGHT MEANS CREEP COMING FROM RIGHT HAND SIDE, IE LOOKKING LEFT




/*loads the images for level 1 creeps*/
void loadImagesCreep()
{
	//********************************creepMovement*********************************************
	//INDEX 0-9: RIGHT
	//INDEX 10-19: LEFT

	creeps[0].id[0] = iLoadImage("images\\character\\enemy\\creeps\\movement\\R1.png");
	creeps[0].id[1] = iLoadImage("images\\character\\enemy\\creeps\\movement\\R2.png");
	creeps[0].id[2] = iLoadImage("images\\character\\enemy\\creeps\\movement\\R3.png");
	creeps[0].id[3] = iLoadImage("images\\character\\enemy\\creeps\\movement\\R4.png");
	creeps[0].id[4] = iLoadImage("images\\character\\enemy\\creeps\\movement\\R5.png");
	creeps[0].id[5] = iLoadImage("images\\character\\enemy\\creeps\\movement\\R6.png");
	creeps[0].id[6] = iLoadImage("images\\character\\enemy\\creeps\\movement\\R7.png");
	creeps[0].id[7] = iLoadImage("images\\character\\enemy\\creeps\\movement\\R8.png");
	creeps[0].id[8] = iLoadImage("images\\character\\enemy\\creeps\\movement\\R9.png");
	creeps[0].id[9] = iLoadImage("images\\character\\enemy\\creeps\\movement\\R10.png");

	creeps[0].id[10] = iLoadImage("images\\character\\enemy\\creeps\\movement\\S1.png"); //flipped direction
	creeps[0].id[11] = iLoadImage("images\\character\\enemy\\creeps\\movement\\S2.png");
	creeps[0].id[12] = iLoadImage("images\\character\\enemy\\creeps\\movement\\S3.png");
	creeps[0].id[13] = iLoadImage("images\\character\\enemy\\creeps\\movement\\S4.png");
	creeps[0].id[14] = iLoadImage("images\\character\\enemy\\creeps\\movement\\S5.png");
	creeps[0].id[15] = iLoadImage("images\\character\\enemy\\creeps\\movement\\S6.png");
	creeps[0].id[16] = iLoadImage("images\\character\\enemy\\creeps\\movement\\S7.png");
	creeps[0].id[17] = iLoadImage("images\\character\\enemy\\creeps\\movement\\S8.png");
	creeps[0].id[18] = iLoadImage("images\\character\\enemy\\creeps\\movement\\S9.png");
	creeps[0].id[19] = iLoadImage("images\\character\\enemy\\creeps\\movement\\S10.png");

	for (int i = 1; i < 20; i++)  //copying all id values to creeps[1-10]
	{
		for (int j = 0; j < 20; j++)
		{
			creeps[i].id[j] = creeps[0].id[j];

		}
	}

	//******************************************************************************************




	//********************************creepAttack*********************************************

	creeps[0].attackID[0] = iLoadImage("images\\character\\enemy\\creeps\\attack\\1.png"); //CREEPS LOOKING LEFT
	creeps[0].attackID[1] = iLoadImage("images\\character\\enemy\\creeps\\attack\\2.png");
	creeps[0].attackID[2] = iLoadImage("images\\character\\enemy\\creeps\\attack\\3.png");
	creeps[0].attackID[3] = iLoadImage("images\\character\\enemy\\creeps\\attack\\4.png");
	creeps[0].attackID[4] = iLoadImage("images\\character\\enemy\\creeps\\attack\\5.png");
	creeps[0].attackID[5] = iLoadImage("images\\character\\enemy\\creeps\\attack\\6.png");
	creeps[0].attackID[6] = iLoadImage("images\\character\\enemy\\creeps\\attack\\7.png");
	creeps[0].attackID[7] = iLoadImage("images\\character\\enemy\\creeps\\attack\\8.png");
	creeps[0].attackID[8] = iLoadImage("images\\character\\enemy\\creeps\\attack\\9.png");
	creeps[0].attackID[9] = iLoadImage("images\\character\\enemy\\creeps\\attack\\10.png");
	creeps[0].attackID[10] = iLoadImage("images\\character\\enemy\\creeps\\attack\\11.png");
	creeps[0].attackID[11] = iLoadImage("images\\character\\enemy\\creeps\\attack\\12.png");
	creeps[0].attackID[12] = iLoadImage("images\\character\\enemy\\creeps\\attack\\13.png");

	creeps[0].attackID[13] = iLoadImage("images\\character\\enemy\\creeps\\attack\\fattack_03.png"); //CREEPS LOOKING RIGHT
	creeps[0].attackID[14] = iLoadImage("images\\character\\enemy\\creeps\\attack\\fattack_05.png");
	creeps[0].attackID[15] = iLoadImage("images\\character\\enemy\\creeps\\attack\\fattack_07.png");
	creeps[0].attackID[16] = iLoadImage("images\\character\\enemy\\creeps\\attack\\fattack_09.png");
	creeps[0].attackID[17] = iLoadImage("images\\character\\enemy\\creeps\\attack\\fattack_11.png");
	creeps[0].attackID[18] = iLoadImage("images\\character\\enemy\\creeps\\attack\\fattack_13.png");
	creeps[0].attackID[19] = iLoadImage("images\\character\\enemy\\creeps\\attack\\fattack_15.png");
	creeps[0].attackID[20] = iLoadImage("images\\character\\enemy\\creeps\\attack\\fattack_18.png");
	creeps[0].attackID[21] = iLoadImage("images\\character\\enemy\\creeps\\attack\\fattack_20.png");
	creeps[0].attackID[22] = iLoadImage("images\\character\\enemy\\creeps\\attack\\fattack_22.png");
	creeps[0].attackID[23] = iLoadImage("images\\character\\enemy\\creeps\\attack\\fattack_24.png");
	creeps[0].attackID[24] = iLoadImage("images\\character\\enemy\\creeps\\attack\\fattack_26.png");
	creeps[0].attackID[25] = iLoadImage("images\\character\\enemy\\creeps\\attack\\fattack_28.png");



	for (int i = 1; i < 20; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			creeps[i].attackID[j] = creeps[0].attackID[j];

		}

	}

	//******************************************************************************************





	//********************************creepDying*********************************************

	creeps[0].deathID[0] = iLoadImage("images\\character\\enemy\\creeps\\dying\\1.png"); // CREEPS LOOKING RIGHT
	creeps[0].deathID[1] = iLoadImage("images\\character\\enemy\\creeps\\dying\\2.png");
	creeps[0].deathID[2] = iLoadImage("images\\character\\enemy\\creeps\\dying\\3.png");
	creeps[0].deathID[3] = iLoadImage("images\\character\\enemy\\creeps\\dying\\4.png");
	creeps[0].deathID[4] = iLoadImage("images\\character\\enemy\\creeps\\dying\\5.png");
	creeps[0].deathID[5] = iLoadImage("images\\character\\enemy\\creeps\\dying\\6.png");
	creeps[0].deathID[6] = iLoadImage("images\\character\\enemy\\creeps\\dying\\7.png");
	creeps[0].deathID[7] = iLoadImage("images\\character\\enemy\\creeps\\dying\\8.png");
	creeps[0].deathID[8] = iLoadImage("images\\character\\enemy\\creeps\\dying\\9.png");
	creeps[0].deathID[9] = iLoadImage("images\\character\\enemy\\creeps\\dying\\10.png");
	creeps[0].deathID[10] = iLoadImage("images\\character\\enemy\\creeps\\dying\\11.png");
	creeps[0].deathID[11] = iLoadImage("images\\character\\enemy\\creeps\\dying\\12.png");
	creeps[0].deathID[12] = iLoadImage("images\\character\\enemy\\creeps\\dying\\13.png");
	creeps[0].deathID[13] = iLoadImage("images\\character\\enemy\\creeps\\dying\\14.png");


	creeps[0].deathID[14] = iLoadImage("images\\character\\enemy\\creeps\\dying\\R_01.png"); //CREEPS LOOKING LEFT
	creeps[0].deathID[15] = iLoadImage("images\\character\\enemy\\creeps\\dying\\R_02.png");
	creeps[0].deathID[16] = iLoadImage("images\\character\\enemy\\creeps\\dying\\R_03.png");
	creeps[0].deathID[17] = iLoadImage("images\\character\\enemy\\creeps\\dying\\R_04.png");
	creeps[0].deathID[18] = iLoadImage("images\\character\\enemy\\creeps\\dying\\R_05.png");
	creeps[0].deathID[19] = iLoadImage("images\\character\\enemy\\creeps\\dying\\R_06.png");
	creeps[0].deathID[20] = iLoadImage("images\\character\\enemy\\creeps\\dying\\R_07.png");
	creeps[0].deathID[21] = iLoadImage("images\\character\\enemy\\creeps\\dying\\R_08.png");
	creeps[0].deathID[22] = iLoadImage("images\\character\\enemy\\creeps\\dying\\R_09.png");
	creeps[0].deathID[23] = iLoadImage("images\\character\\enemy\\creeps\\dying\\R_10.png");
	creeps[0].deathID[24] = iLoadImage("images\\character\\enemy\\creeps\\dying\\R_11.png");
	creeps[0].deathID[25] = iLoadImage("images\\character\\enemy\\creeps\\dying\\R_12.png");
	creeps[0].deathID[26] = iLoadImage("images\\character\\enemy\\creeps\\dying\\R_13.png");
	creeps[0].deathID[27] = iLoadImage("images\\character\\enemy\\creeps\\dying\\R_14.png");

	for (int i = 1; i < 20; i++)
	{
		for (int j = 0; j < 28; j++)
		{
			creeps[i].deathID[j] = creeps[0].deathID[j];

		}

	}

	//******************************************************************************************
} //level 1

/*loads images for level 2 creeps*/
void loadImagesCreep2() // level 2
{
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~   creeps  2 movement ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	creeps[0].id[0] = iLoadImage("images\\character\\enemy\\creeps2\\movement\\leve2-enemy-movement_01.png");
	creeps[0].id[1] = iLoadImage("images\\character\\enemy\\creeps2\\movement\\leve2-enemy-movement_02.png");
	creeps[0].id[2] = iLoadImage("images\\character\\enemy\\creeps2\\movement\\leve2-enemy-movement_03.png");
	creeps[0].id[3] = iLoadImage("images\\character\\enemy\\creeps2\\movement\\leve2-enemy-movement_04.png");
	creeps[0].id[4] = iLoadImage("images\\character\\enemy\\creeps2\\movement\\leve2-enemy-movement_05.png");
	creeps[0].id[5] = iLoadImage("images\\character\\enemy\\creeps2\\movement\\leve2-enemy-movement_06.png");
	creeps[0].id[6] = iLoadImage("images\\character\\enemy\\creeps2\\movement\\leve2-enemy-movement_07.png");
	creeps[0].id[7] = iLoadImage("images\\character\\enemy\\creeps2\\movement\\leve2-enemy-movement_08.png");
	creeps[0].id[8] = iLoadImage("images\\character\\enemy\\creeps2\\movement\\leve2-enemy-movement_09.png");
	creeps[0].id[9] = iLoadImage("images\\character\\enemy\\creeps2\\movement\\leve2-enemy-movement_10.png");

	creeps[0].id[10] = iLoadImage("images\\character\\enemy\\creeps2\\movement\\leve2-enemy-movement-L_01.png"); //flipped direction
	creeps[0].id[11] = iLoadImage("images\\character\\enemy\\creeps2\\movement\\leve2-enemy-movement-L_02.png");
	creeps[0].id[12] = iLoadImage("images\\character\\enemy\\creeps2\\movement\\leve2-enemy-movement-L_03.png");
	creeps[0].id[13] = iLoadImage("images\\character\\enemy\\creeps2\\movement\\leve2-enemy-movement-L_04.png");
	creeps[0].id[14] = iLoadImage("images\\character\\enemy\\creeps2\\movement\\leve2-enemy-movement-L_05.png");
	creeps[0].id[15] = iLoadImage("images\\character\\enemy\\creeps2\\movement\\leve2-enemy-movement-L_06.png");
	creeps[0].id[16] = iLoadImage("images\\character\\enemy\\creeps2\\movement\\leve2-enemy-movement-L_07.png");
	creeps[0].id[17] = iLoadImage("images\\character\\enemy\\creeps2\\movement\\leve2-enemy-movement-L_08.png");
	creeps[0].id[18] = iLoadImage("images\\character\\enemy\\creeps2\\movement\\leve2-enemy-movement-L_09.png");
	creeps[0].id[19] = iLoadImage("images\\character\\enemy\\creeps2\\movement\\leve2-enemy-movement-L_10.png");

	for (int i = 1; i < 20; i++)  //copying all id values to creeps[1-10]
	{
		for (int j = 0; j < 20; j++)
		{
			creeps[i].id[j] = creeps[0].id[j];

		}
	}

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~   creeps  2 attacking  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	creeps[0].attackID[13] = iLoadImage("images\\character\\enemy\\creeps2\\attack\\level-2-enemy-attack_01.png"); //CREEPS LOOKING LEFT and attack
	creeps[0].attackID[14] = iLoadImage("images\\character\\enemy\\creeps2\\attack\\level-2-enemy-attack_02.png");
	creeps[0].attackID[15] = iLoadImage("images\\character\\enemy\\creeps2\\attack\\level-2-enemy-attack_03.png");
	creeps[0].attackID[16] = iLoadImage("images\\character\\enemy\\creeps2\\attack\\level-2-enemy-attack_04.png");
	creeps[0].attackID[17] = iLoadImage("images\\character\\enemy\\creeps2\\attack\\level-2-enemy-attack_05.png");
	creeps[0].attackID[18] = iLoadImage("images\\character\\enemy\\creeps2\\attack\\level-2-enemy-attack_06.png");
	creeps[0].attackID[19] = iLoadImage("images\\character\\enemy\\creeps2\\attack\\level-2-enemy-attack_07.png");
	creeps[0].attackID[20] = iLoadImage("images\\character\\enemy\\creeps2\\attack\\level-2-enemy-attack_08.png");
	creeps[0].attackID[21] = iLoadImage("images\\character\\enemy\\creeps2\\attack\\level-2-enemy-attack_09.png");
	creeps[0].attackID[22] = iLoadImage("images\\character\\enemy\\creeps2\\attack\\level-2-enemy-attack_10.png");
	creeps[0].attackID[23] = iLoadImage("images\\character\\enemy\\creeps2\\attack\\level-2-enemy-attack_11.png");
	creeps[0].attackID[24] = iLoadImage("images\\character\\enemy\\creeps2\\attack\\level-2-enemy-attack_12.png");
	creeps[0].attackID[25] = iLoadImage("images\\character\\enemy\\creeps2\\attack\\level-2-enemy-attack_13.png");  // number 14 sprite left


	creeps[0].attackID[0] = iLoadImage("images\\character\\enemy\\creeps2\\attack\\level-2-enemy-attack-L_01.png"); //CREEPS LOOKING RIGHT
	creeps[0].attackID[1] = iLoadImage("images\\character\\enemy\\creeps2\\attack\\level-2-enemy-attack-L_02.png");
	creeps[0].attackID[2] = iLoadImage("images\\character\\enemy\\creeps2\\attack\\level-2-enemy-attack-L_03.png");
	creeps[0].attackID[3] = iLoadImage("images\\character\\enemy\\creeps2\\attack\\level-2-enemy-attack-L_04.png");
	creeps[0].attackID[4] = iLoadImage("images\\character\\enemy\\creeps2\\attack\\level-2-enemy-attack-L_05.png");
	creeps[0].attackID[5] = iLoadImage("images\\character\\enemy\\creeps2\\attack\\level-2-enemy-attack-L_06.png");
	creeps[0].attackID[6] = iLoadImage("images\\character\\enemy\\creeps2\\attack\\level-2-enemy-attack-L_07.png");
	creeps[0].attackID[7] = iLoadImage("images\\character\\enemy\\creeps2\\attack\\level-2-enemy-attack-L_08.png");
	creeps[0].attackID[8] = iLoadImage("images\\character\\enemy\\creeps2\\attack\\level-2-enemy-attack-L_09.png");
	creeps[0].attackID[9] = iLoadImage("images\\character\\enemy\\creeps2\\attack\\level-2-enemy-attack-L_10.png");
	creeps[0].attackID[10] = iLoadImage("images\\character\\enemy\\creeps2\\attack\\level-2-enemy-attack-L_11.png");
	creeps[0].attackID[11] = iLoadImage("images\\character\\enemy\\creeps2\\attack\\level-2-enemy-attack-L_12.png");
	creeps[0].attackID[12] = iLoadImage("images\\character\\enemy\\creeps2\\attack\\level-2-enemy-attack-L_13.png"); // number 14 sprite left 


	for (int i = 1; i < 20; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			creeps[i].attackID[j] = creeps[0].attackID[j];

		}

	}

	//******************************************************************************************


	//********************************creepDying*********************************************

	creeps[0].deathID[0] = iLoadImage("images\\character\\enemy\\creeps2\\dying\\enemy-dying_01.png"); // CREEPS LOOKING RIGHT
	creeps[0].deathID[1] = iLoadImage("images\\character\\enemy\\creeps2\\dying\\enemy-dying_02.png");
	creeps[0].deathID[2] = iLoadImage("images\\character\\enemy\\creeps2\\dying\\enemy-dying_03.png");
	creeps[0].deathID[3] = iLoadImage("images\\character\\enemy\\creeps2\\dying\\enemy-dying_04.png");
	creeps[0].deathID[4] = iLoadImage("images\\character\\enemy\\creeps2\\dying\\enemy-dying_05.png");
	creeps[0].deathID[5] = iLoadImage("images\\character\\enemy\\creeps2\\dying\\enemy-dying_06.png");
	creeps[0].deathID[6] = iLoadImage("images\\character\\enemy\\creeps2\\dying\\enemy-dying_07.png");
	creeps[0].deathID[7] = iLoadImage("images\\character\\enemy\\creeps2\\dying\\enemy-dying_08.png");
	creeps[0].deathID[8] = iLoadImage("images\\character\\enemy\\creeps2\\dying\\enemy-dying_09.png");  // less 5 sprites needed compared to creeps 1
	creeps[0].deathID[9] = iLoadImage("images\\character\\enemy\\creeps2\\dying\\enemy-dying_09.png");
	creeps[0].deathID[10] = iLoadImage("images\\character\\enemy\\creeps2\\dying\\enemy-dying_09.png");
	creeps[0].deathID[11] = iLoadImage("images\\character\\enemy\\creeps2\\dying\\enemy-dying_09.png");
	creeps[0].deathID[12] = iLoadImage("images\\character\\enemy\\creeps2\\dying\\enemy-dying_09.png");
	creeps[0].deathID[13] = iLoadImage("images\\character\\enemy\\creeps2\\dying\\enemy-dying_09.png"); // less 5 sprites needed compared to creeps 1


	creeps[0].deathID[14] = iLoadImage("images\\character\\enemy\\creeps2\\dying\\enemy-dying-L_01.png"); //CREEPS LOOKING LEFT
	creeps[0].deathID[15] = iLoadImage("images\\character\\enemy\\creeps2\\dying\\enemy-dying-L_02.png");
	creeps[0].deathID[16] = iLoadImage("images\\character\\enemy\\creeps2\\dying\\enemy-dying-L_03.png");
	creeps[0].deathID[17] = iLoadImage("images\\character\\enemy\\creeps2\\dying\\enemy-dying-L_04.png");
	creeps[0].deathID[18] = iLoadImage("images\\character\\enemy\\creeps2\\dying\\enemy-dying-L_05.png");
	creeps[0].deathID[19] = iLoadImage("images\\character\\enemy\\creeps2\\dying\\enemy-dying-L_06.png");
	creeps[0].deathID[20] = iLoadImage("images\\character\\enemy\\creeps2\\dying\\enemy-dying-L_07.png");
	creeps[0].deathID[21] = iLoadImage("images\\character\\enemy\\creeps2\\dying\\enemy-dying-L_08.png");
	creeps[0].deathID[22] = iLoadImage("images\\character\\enemy\\creeps2\\dying\\enemy-dying-L_09.png"); // less 5 sprites needed compared to creeps 1
	creeps[0].deathID[23] = iLoadImage("images\\character\\enemy\\creeps2\\dying\\enemy-dying-L_09.png");
	creeps[0].deathID[24] = iLoadImage("images\\character\\enemy\\creeps2\\dying\\enemy-dying-L_09.png");
	creeps[0].deathID[25] = iLoadImage("images\\character\\enemy\\creeps2\\dying\\enemy-dying-L_09.png");
	creeps[0].deathID[26] = iLoadImage("images\\character\\enemy\\creeps2\\dying\\enemy-dying-L_09.png");
	creeps[0].deathID[26] = iLoadImage("images\\character\\enemy\\creeps2\\dying\\enemy-dying-L_09.png");// less 5 sprites needed compared to creeps 1


	for (int i = 1; i < 20; i++)
	{
		for (int j = 0; j < 28; j++)
		{
			creeps[i].deathID[j] = creeps[0].deathID[j];

		}

	}

}

/*
rendering creeps for moving and when dying
takes 2 parameters- mode and index.
mode: MOVE : to render moving creeps
	  DYING : to render dying creeps
	  ATTACK : to render attacking creeps
index : the index of the creep to show
*/
void renderCreeps(int mode, int index)
{
	if (mode == MOVE)
	{
		iShowImage(creeps[index].x, creeps[index].y, creeps[index].width, creeps[index].height, creeps[index].id[creeps[index].index]);

	}
	else if (mode == DYING)
	{
		if (level_1)
			iShowImage(creeps[index].x, creeps[index].y, 100, 110, creeps[index].deathID[creeps[index].dyingIndex]);
		else
			iShowImage(creeps[index].x, creeps[index].y, 150, 150, creeps[index].deathID[creeps[index].dyingIndex]);

	}
	else if (mode == ATTACK)
	{
		if (level_1)
			iShowImage(creeps[index].x, creeps[index].y, creeps[index].width, creeps[index].height+5, creeps[index].attackID[creeps[index].attackIndex]);
		else
			iShowImage(creeps[index].x, creeps[index].y, creeps[index].width, creeps[index].height, creeps[index].attackID[creeps[index].attackIndex]);

	}
}


/*iDraw function*/
void showCreeps()
{
	for (int i = 0; i < creepsCount; i++)
	{

		if (creeps[i].show)
		{

			if (creeps[i].showHP)
			{
				renderHUD(CREEPS, i);

			}

			if (creeps[i].attack)
			{
				renderCreeps(ATTACK, i);
			}
			else
			{
				renderCreeps(MOVE, i);

			}

		}


		if (creeps[i].death)
		{
			renderCreeps(DYING, i);

		}

		if (creepHurt[i].show)
		{
			renderEffects(CREEPS, i);
		}


	}
}



/*
 calling this function would spawn a random number of enemies coming from both left and right directions.
 to change their mechanism, edit the parameters passed in structure functions.
 to change their spawn number or direction, change creepsCount and creepsSpawnDirection;
 
*/

void spawnCreeps()
{

	randomTime = time(NULL); //uses the time function as a seed for srand. It generates elapsed time since the birth of the computer
	srand(randomTime);

    creepsCount = rand() % creepsLimit + 1; //total number of creeps spawning
	//creepsCount = 0;

	cout << "creeps count: " << creepsCount << endl;

	for (int i = 0, creepSpacing = 0; i < creepsCount; i++, creepSpacing += 100)
	{
		int creepsSpawnDirection = rand() % 2;

		if (creepsSpawnDirection) // rand() will produce values: 1 or 0. if it's 1 then enemy comes from right edge of canvas, else from 0
		{
			creepsSpawnDirection = canvasWidth;
		}
		else
		{
			creepsSpawnDirection = 0;

		}
	

		if (creepsSpawnDirection == 0)
		{
			creepsSpawnDirection -=  creepSpacing;

		}
		else
		{
			creepsSpawnDirection += creepSpacing;

		}

		creeps[i].setVisibility(true, false, false, false, false);



		if (level_1) // level 1 creeps
		{

			creeps[i].initializeLocation(creepsSpawnDirection, tileHeight);
			creeps[i].initializeDimensions(100, 50);
			creeps[i].initializeMechanics(3, 6, 1, 60);

		}
		else // level 2 creeps
		{

			if (CreepsTriggerCounter == 1) // during the first wave, the creeps will spawn only from the left side
			{
				creepsSpawnDirection = 0;
				creeps[i].initializeLocation(creepsSpawnDirection, 187);

			}

			else if (SlopeSegment)
			{
				creeps[i].initializeLocation(creepsSpawnDirection, 80);

			}
			else
			{
				creeps[i].initializeLocation(creepsSpawnDirection, 187);

			}
			creeps[i].initializeDimensions(150, 150);
			creeps[i].initializeMechanics(2, 6, 1, 60); // change varHP

		}
	
	

		creeps[i].index = 0;
		creeps[i].attackIndex = 0;

		if (creepsSpawnDirection == canvasWidth)
		{
			creeps[i].setDirection(RIGHT); //RIGHT MEANS CREEP COMING FROM RIGHT HAND SIDE, IE LOOKKING LEFT
			creeps[i].dyingIndex = 14;

		}
		else
		{
				creeps[i].setDirection(LEFT);
				creeps[i].dyingIndex = 0;
		}

			

	}


}


/*
mechanism behind creeps getting hurt or dying. takes parameters: mode
possible values for mode are : DAMAGE, DYING.

The function iterates through the number of creeps in total and checks if creep is within hero, if so, then their life will reduce

for the DYING part, it basically changes the index number FURTHERMORE, when the creeps get hurt, then the damage effect boolean value is turned on
*/


/*
the functions is called when hero presses attack keys. it checks if the creeps are in range of hero's attack. If they are, then they get damaged
depending on the type of attack. ie: for light attack their hp is reduced less, and for heavy attack, they are reduced significantly
*/
void creepDamage(int mode, int attackType)
{

	
	if (mode == DAMAGE)
	{
		for (int i = 0; i < creepsCount; i++)
		{

			//add hero directions, ie when left or right

			if (attackType == POWER)						// range limit when attack type is power
			{
				if (hero_1)
				{
					// no sprite animation was available. Sadly, we couldnt implement this
				}
				else
				{
					//cout << "power for hero 2" << endl;
					if (hero.direction == RIGHT)
					{
						rangeLeft = 130; // right side from where fissure should start
						rangeRight = 130 + heroFissureLength; // total range of fissure
					}
					else
					{
						//cout << "hero direction left" << endl;

						rangeLeft = 55 - heroFissureLength; // right side from where fissure should start
						rangeRight = 55; // total range of fissure

					}
					
				}
			}

			else									// range limit when attack type is Light Attack and Heavy Attack
			{

				if (hero_1)
				{
					rangeLeft = -50;
					rangeRight = 115;
				}
				else // hero 2
				{
					if (hero.direction == RIGHT)
					{
						rangeRight = -hero.x + hero.projectileX; 
						rangeLeft = 0;
					}
					else
					{
						rangeRight = 0;
						rangeLeft = -hero.x + hero.projectileX;


					}
					
				}
				
			}


			//cout << "PROJECTILE_X: " << hero.projectileX  << "  if less than: " << (hero.x + rangeRight) << " " << "greater than: " << (hero.x + rangeLeft) << "   creepx.x: " << creeps[i].x << endl;

			//************************************************************************************************************************************

		if ((creeps[i].x <= (hero.x + rangeRight)) && (creeps[i].x >= (hero.x + rangeLeft))) //IF CREEP COMES NEAR HERO THEN DAMAGE
		{
			
				//***************************type of attacks*********************************

			// if at any time, a creep gets attacked a a projectile, the projectile's power is over. ie it cant hit anymore creeps on it's path
			
			if (hero.projectile)
			{
				hero.projectile = false;
			}
			
				if (attackType == LIGHT_ATTACK)
				{

					creeps[i].HP -= 1; // dies in 6 hits
					creeps[i].varHP -= 10; // varHP is set to 60 in constructor
					creepHurt[i].show = true;

				}
				else if (attackType == HEAVY_ATTACK)
				{
					creeps[i].HP -= 2; // dies in 3 hits
					creeps[i].varHP -= 20; // varHP is set to 60 in constructor
					creepHurt[i].show = true;
				}

				else if (attackType == POWER)
				{
					
					creeps[i].HP -= 1; // dies in 3 hits
					creeps[i].varHP -= 20; // varHP is set to 60 in constructor
					creepHurt[i].show = true;
				}

				//********************************************************************************

			}


			//**********************Mechanics for when creeps die******************************************

			if (creeps[i].HP <= 0 && creeps[i].HP >= -2)
			{
				heroGain(SCORE);
			

				randomTime = time(NULL); //uses the time function as a seed for srand. It generates elapsed time since the birth of the computer
				srand(randomTime);

				if (rand() % 3 == 1) // if it's 1, then gains hp, probability is 1/3
				{
					
					heroGain(HPBAR);
					heroGain(MANA);

				}
			
				creeps[i].death = true;
				creeps[i].show = false;
				creeps[i].showHP = false;
				//	creepHurt[i].show = false;
				//creeps[i].x = 0;

			}

			//**********************************************************************************************

			


		}
	}

	else if (mode == DYING)
	{

		for (int i = 0; i < creepsCount; i++)
		{

			if (creeps[i].death)
			{
				if (creeps[i].direction == RIGHT)
				{
					creeps[i].dyingIndex++;
					creeps[i].y -= 2;

					if (creeps[i].dyingIndex >= 27)
					{

						creeps[i].death = false;
						creeps[i].x = -1000;


					}

				}
				else
				{
					creeps[i].dyingIndex++;
					creeps[i].y -= 2;

					if (creeps[i].dyingIndex >= 13)
					{

						creeps[i].death = false;
						creeps[i].x = -1000;



					}

				}
			}




		}
	

	}
	
}


/*
Timer function. It iterates through all the creeps alive and changes their index number to show their movement
if at any time the creep comes near hero, then they will start to attack, by turning, creeps[i].attack = true;
the function implicitly calls another function: creepsFollowPlayer() to turn left or right depending on the hero position 
*/

void creepsMovement() 
{
	for (int i = 0; i < creepsCount; i++)
	{
		if (creeps[i].show) 
		{
			if (creeps[i].direction == RIGHT) //creep comes from right side, moving toward left
			{
				if (!creeps[i].attack) // if creeps are in attack motion, then they wont move
				{
					creeps[i].x -= creeps[i].speed;

					creeps[i].index++;
					if (creeps[i].index >= 19)
						creeps[i].index = 10;
				}

				// if creep comes near hero, attack

				if (creeps[i].x <= (hero.x + 80) + 25) 
				{

					creeps[i].attack = true;

				}
				else
				{
					creeps[i].attack = false;

					heroHurt[i].show = false; // if it;s not used, then the blood overlay  for hero will keep on showing even when the creep is not attacking

				}

				creepsFollowPlayer(RIGHT);

			}
			else							//creep comes from left side
			{
				if (!creeps[i].attack)
				{
					creeps[i].x += creeps[i].speed;

					creeps[i].index++;
					if (creeps[i].index >= 9)
						creeps[i].index = 0;
				}

				if (creeps[i].x >= hero.x - 50)
				{
					creeps[i].attack = true;


				}
				else
				{
					creeps[i].attack = false;
					heroHurt[i].show = false;

				

				}

				creepsFollowPlayer(LEFT);
			}
		}
	}
}

/*
changes the direction of the creeps depending on the hero position
takes parameters: LEFT, RIGHT.
LEFT: if the hero is on right side of the enemy
RIGHT: if the hero is on left side of the enemy

*/

void creepsFollowPlayer(int direction)
{

	if (direction == RIGHT) //if hero is on right side of spider, then spider will turn towards player
	{
		for (int i = 0; i<creepsCount; i++)
		{
			if (hero.x > creeps[i].x) 
			{
				creeps[i].direction = LEFT; // moving towards right

			}

		}

	}
	else
	{
		for (int i = 0; i< creepsCount; i++) // if hero is on left side of spider, then spider will turn towards player
		{
			if (hero.x < creeps[i].x)
			{
				creeps[i].direction = RIGHT; // moving towards left

			}

		}


	}

}

/*

Timer function. Iterates through all creeps alive, and if the creeps are in attacking position, then their index will change for rendering.
When the last index is reached, the heroDamage() function is called to decrease health of the player.
NOTE: the last index is used to make a more realistic animation.

*/
void creepAttackLogic()
{

	for (int i = 0; i < creepsCount; i++)
	{
		if (creeps[i].attack && creeps[i].show)
		{

			if (creeps[i].direction == RIGHT)
			{
				creeps[i].attackIndex++;
				//cout << "right i: " << i << "  " << creeps[i].attackIndex << endl;

				if (creeps[i].attackIndex >= 12)
				{

					heroHurt[i].show = true;
					heroDamage(byCreeps);
					creeps[i].attackIndex = 0;



				}
			}
			else
			{

				creeps[i].attackIndex++;
				if (creeps[i].attackIndex >= 25)
				{
					
					heroHurt[i].show = true;
					heroDamage(byCreeps);


					creeps[i].attackIndex = 13;

				}
			}
		}
	}


}


/*
call the function to check if all the creeps spawned are dead or not. if they are dead, then the next objectives are triggered and 
the stage Mark (ie wave 1,2...) is incremented.
Also, the total creep count is resetted.

*/

void checkCreepsAlive() 
{


	int c = 0;

	for (int i = 0; i < creepsCount; i++) //checks if all the creeps are dead
	{
		if (!creeps[i].show)
		{

			// if the creeps are dead, then c inceases. in other words, it stores how many creeps are dead
			c++;
		}
			
	}

	if (creepsCount!=0)
		creepsAlive = creepsCount - c;


	if (c == creepsCount && creepsCount>0)
	{
	
		waveClear = true;
		stage_mark.count++;
		objective[objectiveIndex].show = false;
		creepsCount = 0; // resetting creeps Count since all are dead

		if (level_2)
		{
			HeroJumpingAbility = true; // this is used for level 2 and the hero gains jump ability when all first segment creeps are dead
		}

	}
}

/*
uses the iGetPixelColor() to find specific pre-configured objects in the background. When such objects are identified using the iGetPixelColor()
certain events are triggered. eg: for the first 3 stages, creeps are spawned.
the function is called implicitly from environmentTriggers();
*/

void creepTriggers(int r, int g, int b, int dx, int dy)
{

	iGetPixelColor(hero.x + dx, dy, checkTriggers);

//	cout << checkTriggers[0] << " " << checkTriggers[1] << " " << checkTriggers[2] << endl;



	if ( (checkTriggers[0] == r && checkTriggers[1] == g && checkTriggers[2] == b)  && waveClear) 
	{

		creepsSegment = true; //creep triggers
		spawnCreeps();


		objectiveIndex = 1; // changing objective to show "kill all enemies!"
		objective[objectiveIndex].show = true;

		waveIndex++;

		waveClear = false;

		stage++;

	}


	if (creepsCount>0)
		checkCreepsAlive();



}

/*
TIMER FUNCTION: if the creeps are damaged, then their hurting animation effect is traversed.

*/
void creepHurtLogic()
{
	for (int i = 0; i < creepsCount; i++)
	{
		if (creepHurt[i].show)
		{
			creepHurt[i].index++;
			if (creepHurt[i].index >= 7)
			{
				creepHurt[i].show = false;
				creepHurt[i].index = 0;
			}
		}
	}

}



#endif