#ifndef boss_h
#define boss_h

#include "declarations.h"
#include "character.h"
#include "UIEffects.h"


/*loads the images of level 1 boss*/
void loadImagesBoss()
{

	//****************************************boss movement********************************************
	L1Boss.id[0] = iLoadImage("images\\character\\enemy\\boss\\movement\\standing.png"); //hero standing: looking left
	L1Boss.id[1] = iLoadImage("images\\character\\enemy\\boss\\movement\\1.png");
	L1Boss.id[2] = iLoadImage("images\\character\\enemy\\boss\\movement\\2.png");
	L1Boss.id[3] = iLoadImage("images\\character\\enemy\\boss\\movement\\3.png");
	L1Boss.id[4] = iLoadImage("images\\character\\enemy\\boss\\movement\\4.png");
	L1Boss.id[5] = iLoadImage("images\\character\\enemy\\boss\\movement\\5.png");
	L1Boss.id[6] = iLoadImage("images\\character\\enemy\\boss\\movement\\6.png");
	L1Boss.id[7] = iLoadImage("images\\character\\enemy\\boss\\movement\\7.png");
	L1Boss.id[8] = iLoadImage("images\\character\\enemy\\boss\\movement\\8.png");

	L1Boss.id[9] = iLoadImage("images\\character\\enemy\\boss\\movement\\fstanding.png");  // hero standing: looking right
	L1Boss.id[10] = iLoadImage("images\\character\\enemy\\boss\\movement\\f1.png");
	L1Boss.id[11] = iLoadImage("images\\character\\enemy\\boss\\movement\\f2.png");
	L1Boss.id[12] = iLoadImage("images\\character\\enemy\\boss\\movement\\f3.png");
	L1Boss.id[13] = iLoadImage("images\\character\\enemy\\boss\\movement\\f4.png");
	L1Boss.id[14] = iLoadImage("images\\character\\enemy\\boss\\movement\\f5.png");
	L1Boss.id[15] = iLoadImage("images\\character\\enemy\\boss\\movement\\f6.png");
	L1Boss.id[16] = iLoadImage("images\\character\\enemy\\boss\\movement\\f7.png");
	L1Boss.id[17] = iLoadImage("images\\character\\enemy\\boss\\movement\\f8.png");
	//*************************************************************************************************


	//****************************************BOSS ATTACK************************************************
	L1Boss.attackID[0] = iLoadImage("images\\character\\enemy\\boss\\attack\\L_01.png"); //enemy looking LEFT
	L1Boss.attackID[1] = iLoadImage("images\\character\\enemy\\boss\\attack\\L_02.png");
	L1Boss.attackID[2] = iLoadImage("images\\character\\enemy\\boss\\attack\\L_03.png");
	L1Boss.attackID[3] = iLoadImage("images\\character\\enemy\\boss\\attack\\L_04.png");
	L1Boss.attackID[4] = iLoadImage("images\\character\\enemy\\boss\\attack\\L_05.png");
	L1Boss.attackID[5] = iLoadImage("images\\character\\enemy\\boss\\attack\\L_06.png");
	L1Boss.attackID[6] = iLoadImage("images\\character\\enemy\\boss\\attack\\L_07.png");
	L1Boss.attackID[7] = iLoadImage("images\\character\\enemy\\boss\\attack\\L_08.png");
	L1Boss.attackID[8] = iLoadImage("images\\character\\enemy\\boss\\attack\\L_09.png");
	L1Boss.attackID[9] = iLoadImage("images\\character\\enemy\\boss\\attack\\L_10.png");
	L1Boss.attackID[10] = iLoadImage("images\\character\\enemy\\boss\\attack\\L_11.png");
	L1Boss.attackID[11] = iLoadImage("images\\character\\enemy\\boss\\attack\\L_12.png");
	L1Boss.attackID[12] = iLoadImage("images\\character\\enemy\\boss\\attack\\L_13.png");
	L1Boss.attackID[13] = iLoadImage("images\\character\\enemy\\boss\\attack\\L_14.png"); //fissure starts from here
	L1Boss.attackID[14] = iLoadImage("images\\character\\enemy\\boss\\attack\\L_15.png");
	L1Boss.attackID[15] = iLoadImage("images\\character\\enemy\\boss\\attack\\L_16.png");

	L1Boss.attackID[16] = iLoadImage("images\\character\\enemy\\boss\\attack\\R_16.png"); //enemy looking RIGHT
	L1Boss.attackID[17] = iLoadImage("images\\character\\enemy\\boss\\attack\\R_15.png");
	L1Boss.attackID[18] = iLoadImage("images\\character\\enemy\\boss\\attack\\R_14.png");
	L1Boss.attackID[19] = iLoadImage("images\\character\\enemy\\boss\\attack\\R_13.png");
	L1Boss.attackID[20] = iLoadImage("images\\character\\enemy\\boss\\attack\\R_12.png");
	L1Boss.attackID[21] = iLoadImage("images\\character\\enemy\\boss\\attack\\R_11.png");
	L1Boss.attackID[22] = iLoadImage("images\\character\\enemy\\boss\\attack\\R_10.png");
	L1Boss.attackID[23] = iLoadImage("images\\character\\enemy\\boss\\attack\\R_09.png");
	L1Boss.attackID[24] = iLoadImage("images\\character\\enemy\\boss\\attack\\R_08.png");
	L1Boss.attackID[25] = iLoadImage("images\\character\\enemy\\boss\\attack\\R_07.png");
	L1Boss.attackID[26] = iLoadImage("images\\character\\enemy\\boss\\attack\\R_06.png");
	L1Boss.attackID[27] = iLoadImage("images\\character\\enemy\\boss\\attack\\R_05.png");
	L1Boss.attackID[28] = iLoadImage("images\\character\\enemy\\boss\\attack\\R_04.png");
	L1Boss.attackID[29] = iLoadImage("images\\character\\enemy\\boss\\attack\\R_03.png"); //fissure starts from here
	L1Boss.attackID[30] = iLoadImage("images\\character\\enemy\\boss\\attack\\R_02.png");
	L1Boss.attackID[31] = iLoadImage("images\\character\\enemy\\boss\\attack\\R_01.png");
	//*****************************************************************************************




	//**********************************************FISSURE******************************************
	L1Boss.powerID[0] = iLoadImage("images\\character\\enemy\\boss\\power\\back_01.png"); //enemy looking left
	L1Boss.powerID[1] = iLoadImage("images\\character\\enemy\\boss\\power\\back_02.png");
	L1Boss.powerID[2] = iLoadImage("images\\character\\enemy\\boss\\power\\back_03.png");
	L1Boss.powerID[3] = iLoadImage("images\\character\\enemy\\boss\\power\\back_04.png");

	L1Boss.powerID[4] = iLoadImage("images\\character\\enemy\\boss\\power\\fFissure_01.png");  //enemy looking right
	L1Boss.powerID[5] = iLoadImage("images\\character\\enemy\\boss\\power\\fFissure_02.png");
	L1Boss.powerID[6] = iLoadImage("images\\character\\enemy\\boss\\power\\fFissure_03.png");
	L1Boss.powerID[7] = iLoadImage("images\\character\\enemy\\boss\\power\\fFissure_04.png");
	//*************************************************************************************************


	//*************************************BOSS DEATH*************************************************
	L1Boss.deathID[0] = iLoadImage("images\\character\\enemy\\boss\\dying\\dying_23.png");  // boss dying : looking right
	L1Boss.deathID[1] = iLoadImage("images\\character\\enemy\\boss\\dying\\dying_22.png");
	L1Boss.deathID[2] = iLoadImage("images\\character\\enemy\\boss\\dying\\dying_21.png");
	L1Boss.deathID[3] = iLoadImage("images\\character\\enemy\\boss\\dying\\dying_20.png");
	L1Boss.deathID[4] = iLoadImage("images\\character\\enemy\\boss\\dying\\dying_19.png");
	L1Boss.deathID[5] = iLoadImage("images\\character\\enemy\\boss\\dying\\dying_18.png");
	L1Boss.deathID[6] = iLoadImage("images\\character\\enemy\\boss\\dying\\dying_17.png");


	L1Boss.deathID[7] = iLoadImage("images\\character\\enemy\\boss\\dying\\dyingL_17.png"); // boss dying : looking left
	L1Boss.deathID[8] = iLoadImage("images\\character\\enemy\\boss\\dying\\dyingL_18.png");
	L1Boss.deathID[9] = iLoadImage("images\\character\\enemy\\boss\\dying\\dyingL_19.png");
	L1Boss.deathID[10] = iLoadImage("images\\character\\enemy\\boss\\dying\\dyingL_20.png");
	L1Boss.deathID[11] = iLoadImage("images\\character\\enemy\\boss\\dying\\dyingL_21.png");
	L1Boss.deathID[12] = iLoadImage("images\\character\\enemy\\boss\\dying\\dyingL_22.png");
	L1Boss.deathID[13] = iLoadImage("images\\character\\enemy\\boss\\dying\\dyingL_23.png");
	//************************************************************************************************


} // level 1

/*loads the images of level 2 boss*/
void loadImagesBoss2() // level 2
{

	//	L2Boss.id[0] = iLoadImage("images\\character\\enemy\\boss2\\level2_bossmovement_01.png"); // moving RIGHT images
	L2Boss.id[1] = iLoadImage("images\\character\\enemy\\boss2\\level2_bossmovement_02.png");
	L2Boss.id[2] = iLoadImage("images\\character\\enemy\\boss2\\level2_bossmovement_03.png");
	L2Boss.id[3] = iLoadImage("images\\character\\enemy\\boss2\\level2_bossmovement_04.png");
	L2Boss.id[4] = iLoadImage("images\\character\\enemy\\boss2\\level2_bossmovement_05.png");
	L2Boss.id[5] = iLoadImage("images\\character\\enemy\\boss2\\level2_bossmovement_06.png");

	L2Boss.id[6] = iLoadImage("images\\character\\enemy\\boss2\\level2_bossmovement-L_06.png"); // moving LEFT images
	L2Boss.id[7] = iLoadImage("images\\character\\enemy\\boss2\\level2_bossmovement-L_05.png");
	L2Boss.id[8] = iLoadImage("images\\character\\enemy\\boss2\\level2_bossmovement-L_04.png");
	L2Boss.id[9] = iLoadImage("images\\character\\enemy\\boss2\\level2_bossmovement-L_03.png");
	L2Boss.id[10] = iLoadImage("images\\character\\enemy\\boss2\\level2_bossmovement-L_02.png");
	L2Boss.id[11] = iLoadImage("images\\character\\enemy\\boss2\\level2_bossmovement-L_01.png");


	// 1 - 12 then hold at 9 for attacking while looking right
	// at the 11 image the hand returns and 12 is standing image
	L2Boss.attackID[0] = iLoadImage("images\\character\\enemy\\boss2\\attack_1.png");  // looking right
	L2Boss.attackID[1] = iLoadImage("images\\character\\enemy\\boss2\\attack_2.png");
	L2Boss.attackID[2] = iLoadImage("images\\character\\enemy\\boss2\\attack_3.png");
	L2Boss.attackID[3] = iLoadImage("images\\character\\enemy\\boss2\\attack_4.png");
	L2Boss.attackID[4] = iLoadImage("images\\character\\enemy\\boss2\\attack_5.png");
	L2Boss.attackID[5] = iLoadImage("images\\character\\enemy\\boss2\\attack_6.png");
	L2Boss.attackID[6] = iLoadImage("images\\character\\enemy\\boss2\\attack_7.png");
	L2Boss.attackID[7] = iLoadImage("images\\character\\enemy\\boss2\\attack_8.png"); // hold at this
	L2Boss.attackID[8] = iLoadImage("images\\character\\enemy\\boss2\\attack_9.png");
	L2Boss.attackID[9] = iLoadImage("images\\character\\enemy\\boss2\\attack_10.png");
	L2Boss.attackID[10] = iLoadImage("images\\character\\enemy\\boss2\\attack_11.png");
	L2Boss.attackID[11] = iLoadImage("images\\character\\enemy\\boss2\\attack_12.png");

	// ~~~~~~~~~~~~~~~~~~~~ REVERSE LOOKING LEFT IMAGE OF BOSS ATTACKING
	L2Boss.attackID[12] = iLoadImage("images\\character\\enemy\\boss2\\attack-L_1.png");  // 1 - 12 then hold at 9 for attacking while looking left
	L2Boss.attackID[13] = iLoadImage("images\\character\\enemy\\boss2\\attack-L_2.png");  // at the 11 image the hand returns and 12 is standing image
	L2Boss.attackID[14] = iLoadImage("images\\character\\enemy\\boss2\\attack-L_3.png");
	L2Boss.attackID[15] = iLoadImage("images\\character\\enemy\\boss2\\attack-L_4.png");
	L2Boss.attackID[16] = iLoadImage("images\\character\\enemy\\boss2\\attack-L_5.png");
	L2Boss.attackID[17] = iLoadImage("images\\character\\enemy\\boss2\\attack-L_6.png");
	L2Boss.attackID[18] = iLoadImage("images\\character\\enemy\\boss2\\attack-L_7.png");
	L2Boss.attackID[19] = iLoadImage("images\\character\\enemy\\boss2\\attack-L_8.png"); // hold at this
	L2Boss.attackID[20] = iLoadImage("images\\character\\enemy\\boss2\\attack-L_9.png");
	L2Boss.attackID[21] = iLoadImage("images\\character\\enemy\\boss2\\attack-L_10.png");
	L2Boss.attackID[22] = iLoadImage("images\\character\\enemy\\boss2\\attack-L_11.png");
	L2Boss.attackID[23] = iLoadImage("images\\character\\enemy\\boss2\\attack-L_12.png");


	///////  projectile image here
	L2Boss.powerID[0] = iLoadImage("images\\character\\enemy\\boss2\\hand.png");  // projectile looking left
	L2Boss.powerID[1] = iLoadImage("images\\character\\enemy\\boss2\\hand-right.png");  // projectile looking right
	//////


	//***********************dying***************************************
	L2Boss.deathID[0] = iLoadImage("images\\character\\enemy\\boss2\\boss-dying_02.png"); // looking right
	L2Boss.deathID[1] = iLoadImage("images\\character\\enemy\\boss2\\boss-dying_03.png");
	L2Boss.deathID[2] = iLoadImage("images\\character\\enemy\\boss2\\boss-dying_04.png");
	L2Boss.deathID[3] = iLoadImage("images\\character\\enemy\\boss2\\boss-dying_05.png");
	L2Boss.deathID[4] = iLoadImage("images\\character\\enemy\\boss2\\boss-dying_06.png");
	L2Boss.deathID[5] = iLoadImage("images\\character\\enemy\\boss2\\boss-dying_07.png");
	L2Boss.deathID[6] = iLoadImage("images\\character\\enemy\\boss2\\boss-dying_08.png");
	L2Boss.deathID[7] = iLoadImage("images\\character\\enemy\\boss2\\boss-dying_09.png");

	L2Boss.deathID[8] = iLoadImage("images\\character\\enemy\\boss2\\boss-dying-L_02.png"); // looking left
	L2Boss.deathID[9] = iLoadImage("images\\character\\enemy\\boss2\\boss-dying-L_03.png");
	L2Boss.deathID[10] = iLoadImage("images\\character\\enemy\\boss2\\boss-dying-L_04.png");
	L2Boss.deathID[11] = iLoadImage("images\\character\\enemy\\boss2\\boss-dying-L_05.png");
	L2Boss.deathID[12] = iLoadImage("images\\character\\enemy\\boss2\\boss-dying-L_06.png");
	L2Boss.deathID[13] = iLoadImage("images\\character\\enemy\\boss2\\boss-dying-L_07.png");
	L2Boss.deathID[14] = iLoadImage("images\\character\\enemy\\boss2\\boss-dying-L_08.png");
	L2Boss.deathID[15] = iLoadImage("images\\character\\enemy\\boss2\\boss-dying-L_09.png");


}

/*renders the images of boss. the function takes in parameters, ie MOVE, ATTACK...*/
void renderBoss(int mode)
{
	if (mode == MOVE)
	{

		iShowImage(L1Boss.x, L1Boss.y - 5, L1Boss.width, L1Boss.height, L1Boss.id[L1Boss.index]);

	}
	if (mode == ATTACK)
	{
		iShowImage(L1Boss.x, L1Boss.y - 20, 500, 400, L1Boss.attackID[L1Boss.attackIndex]);

	}
	if (mode == POWER)
	{
		if (L1Boss.direction == RIGHT)
			iShowImage(L1Boss.x - 100, L1Boss.y, 200, 100, L1Boss.powerID[L1Boss.powerIndex]);
		else
			iShowImage(L1Boss.x + 300, L1Boss.y, 200, 100, L1Boss.powerID[L1Boss.powerIndex]);

	}

	if (mode == DYING)
	{
		if (level_1)
			iShowImage(L1Boss.x, L1Boss.y, 500, 400, L1Boss.deathID[L1Boss.dyingIndex]);
		else
		{
			iShowImage(L2Boss.x, L2Boss.y, 200, 200, L2Boss.deathID[L2Boss.dyingIndex]);
			iDelayMS(40);
		}

	}
}

/*
changes the direction of boss wrt to the player.
ie.: if player is in right side of boss, then player turns towards player
the function is implicitly called from bossMovement()
*/
void bossFollowPlayer(int dir)
{
	if (dir == RIGHT) //if hero is on right side of boss, then boss will turn towards player
	{


		if (hero.x > L1Boss.x + 100)
		{
			L1Boss.direction = LEFT; // boos will turn right

		}


	}
	else
	{
		

		if (hero.x + 100 <= L1Boss.x + 200)
		{
			L1Boss.direction = RIGHT; // boos will turn left

		}


	}

}


/*
initializes the variables of boss.
calling this function will spawn the boss.
the function is called from environmentTriggers() after the boss trigger is turned on
*/
void bossSpawn()
{
	

	if (level_1)
	{
		
		L1Boss.initializeDimensions(250, 250);
		L1Boss.initializeLocation(canvasWidth + 10, tileHeight - 2);
		L1Boss.setDirection(RIGHT);
		L1Boss.initializeMechanics(6, 100, 1, NULL); // change hp to 100
		L1Boss.setVisibility(true, false, false, false, false);
		L1_BossHPbar.createHPbar(850, 650, 876, 855, 876, 688, 855, 711, 1196, 711, 1211, 690); // total length is 356
		L1Boss.dyingIndex = 0;
	}
	else
	{

		L2Boss.initializeDimensions(300, 300);
		L2Boss.initializeLocation(1000, 185);
		L2Boss.setDirection(RIGHT); // right means coming from right side
		L2Boss.initializeMechanics(10, 80, 1, NULL); // change hp to 100
		L2Boss.setVisibility(true, false, false, false, false);
		//L2Boss.chase = true;

		// im using the level 1 boss HP bar, but with a different image. Im doing this so that no extra code is to written

		L1_BossHPbar.createHPbar(850, 650, 876, 855, 876, 688, 855, 711, 1196, 711, 1211, 690); // total length is 356
		L1Boss.initializeMechanics(6, 100, 1, NULL); // change hp to 100


		L2Boss.dyingIndex = 8;
		L2Boss.attackIndex = 12;
		L2Boss.powerIndex = 25;
		L2Boss.index = 7;


		L2Boss.projectileX = L2Boss.x;
		L2Boss.projectileY = 180+60;


		L1_BossHurt.index = 0;

		


	}



}



/*
contains the movement of boss and its index is incremented
also, the function bossFollowPlayer() is implicitly called.
if at any time the hero comes within the specified range of the boss's attack, then the bossAttack is turned true
*/
void bossMovement()
{
	if (level_1)
	{

		if (L1Boss.direction == RIGHT) //comes from right direction
		{

			//	L1Boss.attackIndex = 0;
			//	L1Boss.powerIndex = 0;


			L1Boss.x -= L1Boss.speed;
			L1Boss.index++;

			if (L1Boss.index >= 8)
			{
				L1Boss.index = 0;
			}


			if (hero.x >= L1Boss.x - 200 && hero.x <= L1Boss.x + 200) // if hero comes near boss, then boss will attack
			{
				if (temp_2) //calls only once. it is used for channeling attacks for boss. ie the boss does not attack consecutively. it attacks after a few seconds
				{
					L1Boss.attack = true;
					temp_2 = false;
				}



			}

			bossFollowPlayer(RIGHT);

		}
		else						  //come from left direction
		{
			//L1Boss.attackIndex = 16;
			//L1Boss.powerIndex = 4;

			L1Boss.x += L1Boss.speed;
			L1Boss.index++;

			if (L1Boss.index >= 17)
			{
				L1Boss.index = 9;
			}

			if (hero.x <= L1Boss.x + 400 && hero.x >= L1Boss.x) //calls only once. it is used for channeling attacks for boss. ie the boss does not attack consecutively. it attacks after a few seconds
			{
				if (temp_2)
				{
					L1Boss.attack = true;
					temp_2 = false;

				}

			}

			bossFollowPlayer(LEFT);
		}

	}

	//********************level 2 boss***************************************
	else
	{


		// the below code initializes the coordinate of the boss projectile.
		if (!L2Boss.channelPower && !L2Boss.power)
		{
			if (L2Boss.direction == RIGHT)
			{
				L2Boss.projectileX = L2Boss.x + 50;

			}
			else
			{
				L2Boss.projectileX = L2Boss.x + 250;

			}
		}


		// checks the condition when hero is within attack range of boss. if so, then l2boss.attack is true else boss will chase hero
		if (!L2Boss.attack)
		{
			if (L2Boss.direction == RIGHT) // boss coming from RHS
			{

				if ((hero.x >= L2Boss.x + 50 - 250) && (hero.x <= L2Boss.x + 50))   //if hero is within attack range
				{

					L2Boss.attack = true;
					L2Boss.chase = false;


				}
				else // chase hero if not in attack range
				{
					L2Boss.chase = true;

				}
			}

			else // boss coming from LHS
			{

				if ((hero.x <= L2Boss.x + 200 + 150) && (hero.x >= L2Boss.x + 200))
				{
					L2Boss.attack = true;
					L2Boss.chase = false;
				}
				else
				{
					L2Boss.chase = true;

				}


			}

		}



		if (L2Boss.chase)
		{
			if (L2Boss.direction == RIGHT) // if boss comes from RHS
			{

				L2Boss.x -= 5;
				L2Boss.index++;
				if (L2Boss.index == 6)
				{
					L2Boss.index++;
				}
				if (L2Boss.index >= 11)
				{
					L2Boss.index = 7;
				}

				// boss following player to the left
				if (hero.x > L2Boss.x + 300)
				{
					L2Boss.direction = LEFT; // boos will turn right
					//L2Boss.projectileX = L2Boss.x + 100; 

				}




			}

			else
			{

				L2Boss.x += 5;
				L2Boss.index++;

				if (L2Boss.index == 0)
				{
					L2Boss.index++;
				}

				if (L2Boss.index >= 5)
				{
					L2Boss.index = 1;
				}

				// boss following player to the right
				if (hero.x + 100 <= L2Boss.x + 300)
				{
					L2Boss.direction = RIGHT; // boos will turn left
					//L2Boss.projectileX = L2Boss.x + 300;

				}


			}


		}












	}





}


/*
timer function: the function changes the index of attackID/ powerID of boss for the animation
called from enemyAutoMotion() when boss.attack/power is true
*/
void bossAttackLogic(int mode)
{
	if (temp_3) //resetting the values of power indexes. if not used here, a bug occurs.
	{
		if (L1Boss.direction == RIGHT || L2Boss.direction == RIGHT)
		{
			L1Boss.dyingIndex = 0;
			L1Boss.powerIndex = 0;

			L2Boss.dyingIndex = 8;
			L2Boss.attackIndex = 12;
			L2Boss.powerIndex = 0;

		}
		else
		{
			L1Boss.powerIndex = 4;
			L1Boss.dyingIndex = 7;

			L2Boss.dyingIndex = 0;
			L2Boss.attackIndex = 0;
			L2Boss.powerIndex = 1;
		}

		temp_3 = false;
	}


	if (mode == ATTACK)
	{


		if (level_1)
		{

			if (L1Boss.direction == RIGHT)
			{

				if (!L1Boss.power)
				{
					L1Boss.attackIndex++;
					//cout << "attack index : right :: " << L1Boss.attackIndex << endl;
				}

				if (L1Boss.attackIndex == 13)
				{
					wait++;
					L1Boss.power = true;
					L1Boss.channelPower = true;

					if (wait >= 60)
					{
						L1Boss.power = false;
						L1Boss.channelPower = false;
						L1Boss.powerIndex = 0;
						temp_3 = true;


					}
				}

				if (L1Boss.attackIndex >= 15)
				{
					L1Boss.attack = false;
					wait = 0;
					L1Boss.attackIndex = 0;
					L1Boss.powerIndex = 0;

					temp_2 = true;

				}

			}
			else
			{


				if (!L1Boss.power)
				{
					L1Boss.attackIndex++;
					//	cout << "attack index : left :: " << L1Boss.attackIndex << endl;

				}

				if (L1Boss.attackIndex == 29)
				{
					wait++;
					L1Boss.power = true;
					L1Boss.channelPower = true;

					if (wait >= 100)
					{
						L1Boss.powerIndex = 4;

						L1Boss.power = false;
						L1Boss.channelPower = false;
						temp_3 = true;


					}

				}

				if (L1Boss.attackIndex >= 31)
				{
					L1Boss.attack = false;
					wait = 0;
					L1Boss.attackIndex = 16;
					temp_2 = true;
					L1Boss.powerIndex = 4;


				}



			}

		}


		//****************************level 2 boss*****************************************

		else
		{
			if (L2Boss.direction == RIGHT)
			{
				if (!L2Boss.power)
				{
					L2Boss.attackIndex++;
				}

				if (L2Boss.attackIndex == 19) // when boss starts to shoot the projectile
				{
					L2Boss.channelPower = true;
					L2Boss.power = true;

				}


				// this block will not execute when l2boss.power is true. ie: while the projectile's motion is not completed (both forward and reverse)
				if (L2Boss.attackIndex >= 23)
				{


					// wait for awhile, before attacking again
					L2Boss.attackIndex = 23;
					wait++;
					if (wait > 10)
					{
						wait = 0;
						L2Boss.attackIndex = 12;
						L2Boss.powerIndex = 0;
						L2Boss.attack = false;
					}
				}


			}

			else
			{

				if (!L2Boss.power)
				{
					L2Boss.attackIndex++;
				}

				if (L2Boss.attackIndex == 7) // when boss starts to shoot the projectile
				{
					L2Boss.channelPower = true;
					L2Boss.power = true;

					if (temp_3)
					{
						L2Boss.projectileX = L2Boss.x + 250;
						temp_3 = false;
					}

				}


				// this block will not execute when l2boss.power is true. ie: while the projectile's motion is not completed (both forward and reverse)
				if (L2Boss.attackIndex >= 11)
				{
					L2Boss.attackIndex = 11;
					wait++;
					if (wait > 10)
					{
						wait = 0;
						L2Boss.attackIndex = 0;
						L2Boss.powerIndex = 1;
						L2Boss.attack = false;
					}
				}

			}


		}



	}


	if (mode == POWER)
	{

		if (level_1)
		{

			if (L1Boss.direction == RIGHT)
			{


				L1Boss.powerIndex++;
				if (L1Boss.powerIndex >= 3)
				{
					L1Boss.powerIndex = 3;
				}


			}
			else
			{


				L1Boss.powerIndex++;

				if (L1Boss.powerIndex >= 7)
				{

					L1Boss.powerIndex = 7;

				}

			}

		}

		/********************level 2 boss********************************/
		else
		{










			if (L2Boss.channelPower)
			{
				//cout << "projctileX: " << L2Boss.projectileX << "  hero.x: " << hero.x << " boss.x: " << L2Boss.x << endl;
				if (L2Boss.direction == RIGHT)
				{
					L2Boss.projectileX -= 10;

					if (L2Boss.projectileX <= L2Boss.x - 200)
					{

						L2Boss.channelPower = false;
					}

				}
				else
				{
					L2Boss.projectileX += 10;

					if (L2Boss.projectileX >= L2Boss.x + 200 + 200)
					{

						L2Boss.channelPower = false;
					}
				}

			}


			// when projectile is coming back
			if (!L2Boss.channelPower)
			{

				if (L2Boss.direction == RIGHT)
				{
					L2Boss.projectileX += 10;

					if (L2Boss.projectileX >= L2Boss.x + 50)
					{
						L2Boss.power = false;
					}
				}
				else
				{
					L2Boss.projectileX -= 10;
					if (L2Boss.projectileX <= L2Boss.x + 100)
					{
						L2Boss.power = false;
					}
				}


			}


		}
	}
}

/*
LEVEL 1
if the boss comes within the range of hero's attack range, then the boss will get hurt depending on the attack type.
ie: for light attacks, the damage taken by boss will be more
After getting damage, when hp of boss becomes less than 0, then boss.death is turned true and the sliding portion takes place

the function also does the animation for when the boss is dying. ie: the boss rotates and slides across the floor.
and at one point after sliding for a while, the ***VICTORY*** window appears
*/
void bossDamage(int mode, int attackType)
{

	//BOSS HP IS SET TO 100
	// hp bar length is 356
	cout << "boss hp: " << L1Boss.HP << endl;
	cout << "boss 1 show: " << L1Boss.show << endl;

	if (mode == DAMAGE && attackType != POWER)
	{


		///******************HERO 1***********************************
		if (hero_1)
		{

			if (level_2)
			{
				L1Boss.x = L2Boss.x;
				//	temp10 = true;

			}

			if (level_1)
			{
				if (((hero.x >= L1Boss.x && hero.x <= L1Boss.x + 100) || (hero.x <= L1Boss.x + 300 && hero.x >= L1Boss.x + 200)) || (hero.x + 75 >= L1Boss.x && hero.x <= L1Boss.x + 100) || (hero.x + 75 <= L1Boss.x + 300 && hero.x >= L1Boss.x + 200)) // if boss comes near hero's range while hero.attack is true, then boss gets hurt
				{


					if (attackType == LIGHT_ATTACK)
					{
						L1Boss.HP -= 5; // dies in 20 HITS

						L1_BossHurt.show = true;					 // damage efffects turned true


						L1_BossHPbar.variable1 += 20;
						L1_BossHPbar.variable2 += 20;





					}



					else if (attackType == HEAVY_ATTACK)
					{
						L1Boss.HP -= 10; // dies in 10

						L1_BossHPbar.variable1 += 40;
						L1_BossHPbar.variable2 += 40;



						L1_BossHurt.show = true;					// damage efffects turned true

					}


					//condition used so that boss hp  doesnt exceed the bar
					if (L1_BossHPbar.variable2 >= 1214)
					{
						L1_BossHPbar.variable1 = 1119;
						L1_BossHPbar.variable2 = 1214;
					}




					if (L1Boss.HP <= 0 && L1Boss.show)
					{
						if (level_1)
						{
							// boss 
							L1Boss.death = true;
							L1Boss.show = false;
							L1Boss.power = false;
							L1Boss.showHP = false;
							L1Boss.attack = false;
							L1Boss.channelPower = false;

							score += 50;
						}
						else
						{
							// boss 
							L2Boss.death = true;
							L2Boss.show = false;
							L2Boss.power = false;
							L2Boss.showHP = false;
							L2Boss.attack = false;
							L2Boss.channelPower = false;

							score += 100;

							if (L2Boss.direction == RIGHT)
							{
								L2Boss.dyingIndex = 8;

							}
							else
							{
								L2Boss.dyingIndex = 0;

							}


						}

					}



				}




			}
			else
			{


				if (((hero.x >= L2Boss.x && hero.x <= L2Boss.x + 100) || (hero.x <= L2Boss.x + 300 && hero.x >= L2Boss.x + 200)) || (hero.x + 75 >= L2Boss.x && hero.x <= L2Boss.x + 100) || (hero.x + 75 <= L2Boss.x + 300 && hero.x >= L2Boss.x + 200)) // if boss comes near hero's range while hero.attack is true, then boss gets hurt
				{


					if (attackType == LIGHT_ATTACK)
					{
						L1Boss.HP -= 5; // dies in 20 HITS

						L1_BossHurt.show = true;					 // damage efffects turned true


						L1_BossHPbar.variable1 += 15;
						L1_BossHPbar.variable2 += 15;





					}



					else if (attackType == HEAVY_ATTACK)
					{
						L1Boss.HP -= 10; // dies in 10

						L1_BossHPbar.variable1 += 35;
						L1_BossHPbar.variable2 += 35;



						L1_BossHurt.show = true;					// damage efffects turned true

					}


					//condition used so that boss hp  doesnt exceed the bar
				/*	if (L1_BossHPbar.variable2 >= 1190)
					{
						L1_BossHPbar.variable1 = 11190;
						L1_BossHPbar.variable2 = 1215;
					}
					*/


					if (L1_BossHPbar.variable2 >= 1214)
					{
						L1_BossHPbar.variable1 = 1119;
						L1_BossHPbar.variable2 = 1214;
					}



					if (L1Boss.HP <= 0 && (L1Boss.show || L2Boss.show))
					{
						

						if (level_1)
						{
							// boss 
							L1Boss.death = true;
							L1Boss.show = false;
							L1Boss.power = false;
							L1Boss.showHP = false;
							L1Boss.attack = false;
							L1Boss.channelPower = false;

							score += 50;
						}
						else
						{
							// boss 
							L2Boss.death = true;
							L2Boss.show = false;
							L2Boss.power = false;
							L2Boss.showHP = false;
							L2Boss.attack = false;
							L2Boss.channelPower = false;

							score += 100;

							if (L2Boss.direction == RIGHT)
							{
								L2Boss.dyingIndex = 8;

							}
							else
							{
								L2Boss.dyingIndex = 0;

							}


						}

					}



				}






			}
			


		}


		//***************************HERO 2**************************************

		else 	// for hero 2 attack damages to level 1 and 2 bosses:: ** i should've used this in the above function. but due to shortage of time
		{

			// HERO DIRECTION: RIGHT
			/*

			imporove code hygiene by making it polymorhic
			if (hero.direction == RIGHT)
			{
				actualBossX = 50;
				rangeLeft = hero.projectileX;
				rangeRight = hero.projectileX + 100;

			}
			else
			{
				actualBossX = 250;
				rangeLeft = hero.projectileX;
				rangeRight = hero.projectileX + 100;
			}

			if (level_2)
			{
				L1Boss.x = L2Boss.x;

			}
			*/


			
			if (attackType == LIGHT_ATTACK)
			{

				if (hero.direction == RIGHT)
				{
					if (level_2)
					{
						L1Boss.x = L2Boss.x;

					}
				//	cout << "hero: right" << endl;

					if ((L1Boss.x <= hero.projectileX + 50 && L1Boss.x >= hero.projectileX) && (L2Boss.show || L1Boss.show) )
					{

					//	cout << "damage: right" << endl;
						L1Boss.HP -= 10; // dies in 10 HITS

						L1_BossHurt.show = true;					 // damage efffects turned true

						L1_BossHPbar.variable1 += 40;
						L1_BossHPbar.variable2 += 40;

						hero.projectile = false;

						if (L1Boss.HP <= 0)
						{

							if (level_1)
							{

								L1Boss.death = true;
								L1Boss.show = false;
								L1Boss.power = false;
								L1Boss.showHP = false;
								L1Boss.attack = false;
								L1Boss.channelPower = false;

								score += 100;
							}
							else
							{

								L2Boss.death = true;
								L2Boss.show = false;
								L2Boss.power = false;
								L2Boss.showHP = false;
								L2Boss.attack = false;
								L2Boss.channelPower = false;

								score += 100;

								if (L2Boss.direction == RIGHT)
								{
									L2Boss.dyingIndex = 8;

								}
								else
								{
									L2Boss.dyingIndex = 0;

								}

							}


						}


					}



				}

				// HERO DIRECTION: LEFT
				else
				{
					if (level_2)
					{
						L1Boss.x = L2Boss.x;

					}



					if ((L1Boss.x + 150 >= hero.projectileX && L1Boss.x + 150 <= hero.projectileX + 50) && (L2Boss.show || L1Boss.show) )
					{


						L1Boss.HP -= 10; // dies in 20 HITS

						L1_BossHurt.show = true;					 // damage efffects turned true

						L1_BossHPbar.variable1 += 40;
						L1_BossHPbar.variable2 += 40;

						hero.projectile = false;

						if (L1Boss.HP <= 0)
						{


							if (level_1)
							{

								L1Boss.death = true;
								L1Boss.show = false;
								L1Boss.power = false;
								L1Boss.showHP = false;
								L1Boss.attack = false;
								L1Boss.channelPower = false;

								score += 100;

							}
							else
							{
								L2Boss.death = true;
								L2Boss.show = false;
								L2Boss.power = false;
								L2Boss.showHP = false;
								L2Boss.attack = false;
								L2Boss.channelPower = false;

								score += 100;



								if (L2Boss.direction == RIGHT)
								{
									L2Boss.dyingIndex = 8;

								}
								else
								{
									L2Boss.dyingIndex = 0;

								}
							}

						


						}

					}


				}


			}
		}


	}




	else if (attackType == POWER)
	{


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



		if ((L2Boss.x <= (hero.x + rangeRight) && L2Boss.x >= (hero.x + rangeLeft)) && (L2Boss.show || L1Boss.show))
		{

			L1Boss.HP -= 1; 


			L1_BossHPbar.variable1 += 5;
			L1_BossHPbar.variable2 += 5;

			if (L1Boss.HP <= 0)
			{
				//cout << "damaging, score increasing" << endl;
				L2Boss.death = true;
				L2Boss.show = false;
				L2Boss.power = false;
				L2Boss.showHP = false;
				L2Boss.attack = false;
				L2Boss.channelPower = false;

				score += 100;


				if (L2Boss.direction == RIGHT)
				{
					L2Boss.dyingIndex = 8;

				}
				else
				{
					L2Boss.dyingIndex = 0;

				}


			}

			L1_BossHurt.show = true;

		}


	}






	else if (mode == DYING)  // DYING ANIMATION FOR LEVEL 1 BOSS
	{


		if (temp_6) // used for initializing the sprite animation. or else it rotates twice
		{
			L1Boss.dyingIndex = 0;


			if (L2Boss.direction == RIGHT)
			{
				L2Boss.dyingIndex = 8;

			}
			else
			{
				L2Boss.dyingIndex = 0;

			}

			temp_6 = false;
		}




		if (level_1)
		{

			L1Boss.dyingIndex++;

			L1Boss.x -= 20;

			L1Boss.y -= 1;


			if (L1Boss.dyingIndex >= 6)
			{
				temp_7++;

				L1Boss.dyingIndex = 6;

				if (temp_7 >= 40) //for how long the boss SLIDES on the floor before the game finishes
				{


					// victory!!!!!
					temp_7 = 0;

					L1Boss.dyingIndex = 0;
					L1Boss.death = false;


					MenuController = VICTORY_1;

					iPauseTimer(timer_AUTOMOTION);
					iPauseTimer(timer_ENEMYMOTION);
					iPauseTimer(timer_HEROMOTION);

					hero.x = 200; // bringing hero to left side

					gameWon_1 = true;
					gameStart = false;
					gameOver = false;


				}


			}

		}

		//******************level 2 boss****************************
		else
		{
			if (L2Boss.direction == RIGHT)
			{
				L2Boss.dyingIndex++;

				//L1Boss.x -= 20;


				//L2Boss.x -= 10;
				L2Boss.y = 150;


				if (L2Boss.dyingIndex >= 7)
				{
					L2Boss.dyingIndex = 7;
					temp_7++;

					if (temp_7 >= 30) //for how long the boss lies on the floor before the game finishes
					{


						temp_7 = 0;
						L2Boss.dyingIndex = 0;
						L2Boss.death = false;

						//iPauseTimer(timer_AUTOMOTION);
						//iPauseTimer(timer_ENEMYMOTION);
						//iPauseTimer(timer_HEROMOTION);

						initPrincess();


					}

				}

			}
			else
			{

				L2Boss.dyingIndex++;
				//	L2Boss.x += 10;
				L2Boss.y = 150;
				if (L2Boss.dyingIndex >= 15)
				{
					L2Boss.dyingIndex = 15;

					temp_7++;

					if (temp_7 >= 30) //for how long the boss lies on the floor before the game finishes
					{


						temp_7 = 0;
						L1Boss.dyingIndex = 8;
						L2Boss.death = false;

						//iPauseTimer(timer_AUTOMOTION);
						//iPauseTimer(timer_ENEMYMOTION);
						//iPauseTimer(timer_HEROMOTION);

						initPrincess();


					}
				}
			}

		}


	}




}

/*
timer function. animation for damage effect for level 1 boss
*/
void L1BossHurtLogic()
{
	L1_BossHurt.index++;
	if (L1_BossHurt.index >= 4)
	{
		L1_BossHurt.show = false;
		L1_BossHurt.index = 0;
	}
}


/*idraw function*/
void showBoss()
{
	if (level_1)
	{

		if (!L1Boss.attack && L1Boss.show)
		{

			renderBoss(MOVE);

		}
		if (L1Boss.attack)
		{
			renderBoss(ATTACK);
		}

		if (L1Boss.channelPower)
		{
			renderBoss(POWER);
		}
		if (L1Boss.death)
		{
			renderBoss(DYING);

		}
		if (L1_BossHurt.show)
		{
			renderEffects(BOSS, NULL);
		}
	}


	//*******************************level 2 boss***********************************************
	else
	{

		if (bossCutscene)
		{
			iShowImage(1100, 185, L2Boss.width - 50, L2Boss.height - 50, L2Boss.id[6]);
			return;
		}


		// shows boss chasing
		if (!L2Boss.attack && L2Boss.show && L2Boss.chase)
		{

			iShowImage(L2Boss.x, L2Boss.y+10, L2Boss.width - 50, L2Boss.height - 50 +5 , L2Boss.id[L2Boss.index]);


		}

		// attack animation
		if (L2Boss.attack)
		{
			iShowImage(L2Boss.x, L2Boss.y-2, L2Boss.width-20, L2Boss.height -20, L2Boss.attackID[L2Boss.attackIndex]);

		}

		//shows the projectile
		if (L2Boss.power)
		{
			iShowImage(L2Boss.projectileX, L2Boss.projectileY, 73, 60, L2Boss.powerID[L2Boss.powerIndex]);


		}

		if (L1_BossHurt.show)
		{
			renderEffects(BOSS, NULL);
		}

		if (L2Boss.death)
		{
			renderBoss(DYING);

		}








	}
}





#endif