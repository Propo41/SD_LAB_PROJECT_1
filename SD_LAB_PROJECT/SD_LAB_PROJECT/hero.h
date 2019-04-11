#ifndef hero_H
#define hero_H

#include "character.h"
#include "declarations.h"
#include "music.h"



// hero direction left means hero is looking left

/*loads the images of hero 1*/
void loadImagesHero()
{
	//*********************heroMovement**************************************************
	hero.id[0] = iLoadImage("images\\character\\hero\\movement\\hero_standing.png");//hero standing
	hero.id[1] = iLoadImage("images\\character\\hero\\movement\\hero_movement_01.png");
	hero.id[2] = iLoadImage("images\\character\\hero\\movement\\hero_movement_02.png");
	hero.id[3] = iLoadImage("images\\character\\hero\\movement\\hero_movement_03.png");
	hero.id[4] = iLoadImage("images\\character\\hero\\movement\\hero_movement_04.png");
	hero.id[5] = iLoadImage("images\\character\\hero\\movement\\hero_movement_05.png");
	hero.id[6] = iLoadImage("images\\character\\hero\\movement\\hero_movement_06.png");

	hero.id[7] = iLoadImage("images\\character\\hero\\movement\\hero_standing_flipped.png");//hero standing flipped
	hero.id[8] = iLoadImage("images\\character\\hero\\movement\\hero_movement_flipped_02.png");
	hero.id[9] = iLoadImage("images\\character\\hero\\movement\\hero_movement_flipped_03.png");
	hero.id[10] = iLoadImage("images\\character\\hero\\movement\\hero_movement_flipped_04.png");
	hero.id[11] = iLoadImage("images\\character\\hero\\movement\\hero_movement_flipped_05.png");
	hero.id[12] = iLoadImage("images\\character\\hero\\movement\\hero_movement_flipped_06.png");
	hero.id[13] = iLoadImage("images\\character\\hero\\movement\\hero_movement_flipped_07.png");
	//*************************************************************************************




	/*******************************************HERO JUMP*********************************************/
	// hero1.14 is empty
	// first five for jump up
	hero.id[15] = iLoadImage("images\\character\\hero\\jump\\herojump1.png"); // LOOKING RIGHT
	hero.id[16] = iLoadImage("images\\character\\hero\\jump\\herojump2.png");
	hero.id[17] = iLoadImage("images\\character\\hero\\jump\\herojump3.png");
	hero.id[18] = iLoadImage("images\\character\\hero\\jump\\herojump4.png");
	hero.id[19] = iLoadImage("images\\character\\hero\\jump\\herojump5.png");
	// next 5 for jump down
	hero.id[20] = iLoadImage("images\\character\\hero\\jump\\herojump6.png");
	hero.id[21] = iLoadImage("images\\character\\hero\\jump\\herojump7.png");
	hero.id[22] = iLoadImage("images\\character\\hero\\jump\\herojump8.png");
	hero.id[23] = iLoadImage("images\\character\\hero\\jump\\herojump9.png");


	hero.id[24] = iLoadImage("images\\character\\hero\\jump\\herojump10.png"); // this is not used as the standing and this image is same



	// reverse
	hero.id[25] = iLoadImage("images\\character\\hero\\jump\\ReverseHeroJump1.png");// LOOKING LEFT
	hero.id[26] = iLoadImage("images\\character\\hero\\jump\\ReverseHeroJump2.png");
	hero.id[27] = iLoadImage("images\\character\\hero\\jump\\ReverseHeroJump3.png");
	hero.id[28] = iLoadImage("images\\character\\hero\\jump\\ReverseHeroJump4.png");
	hero.id[29] = iLoadImage("images\\character\\hero\\jump\\ReverseHeroJump5.png");


	hero.id[30] = iLoadImage("images\\character\\hero\\jump\\ReverseHeroJump6.png");
	hero.id[31] = iLoadImage("images\\character\\hero\\jump\\ReverseHeroJump7.png");
	hero.id[32] = iLoadImage("images\\character\\hero\\jump\\ReverseHeroJump8.png");
	hero.id[33] = iLoadImage("images\\character\\hero\\jump\\ReverseHeroJump9.png");
	hero.id[34] = iLoadImage("images\\character\\hero\\jump\\ReverseHeroJump10.png");

	/******************************************************************************************/


	//***************************heroAttack***************************************************

	hero.attackID[0] = iLoadImage("images\\character\\hero\\attack\\atack_02.png"); // HERO LOOKING RIGHT
	hero.attackID[1] = iLoadImage("images\\character\\hero\\attack\\attack_03.png");
	hero.attackID[2] = iLoadImage("images\\character\\hero\\attack\\attack_04.png");
	hero.attackID[3] = iLoadImage("images\\character\\hero\\attack\\attack_05.png");
	hero.attackID[4] = iLoadImage("images\\character\\hero\\attack\\attack_06.png");
	hero.attackID[5] = iLoadImage("images\\character\\hero\\attack\\attack_07.png");
	hero.attackID[6] = iLoadImage("images\\character\\hero\\attack\\attack_08.png");
	hero.attackID[7] = iLoadImage("images\\character\\hero\\attack\\attack_09.png");
	hero.attackID[8] = iLoadImage("images\\character\\hero\\attack\\attack_10.png");
	hero.attackID[9] = iLoadImage("images\\character\\hero\\attack\\attack_11.png");
	hero.attackID[10] = iLoadImage("images\\character\\hero\\attack\\attack_12.png");
	hero.attackID[11] = iLoadImage("images\\character\\hero\\attack\\attack_13.png");
	hero.attackID[12] = iLoadImage("images\\character\\hero\\attack\\attack_14.png");
	hero.attackID[13] = iLoadImage("images\\character\\hero\\attack\\attack_15.png");

	hero.attackID[14] = iLoadImage("images\\character\\hero\\attack\\1.png"); //HERO LOOKING LEFT
	hero.attackID[15] = iLoadImage("images\\character\\hero\\attack\\2.png");
	hero.attackID[16] = iLoadImage("images\\character\\hero\\attack\\3.png");
	hero.attackID[17] = iLoadImage("images\\character\\hero\\attack\\4.png");
	hero.attackID[18] = iLoadImage("images\\character\\hero\\attack\\5.png");
	hero.attackID[19] = iLoadImage("images\\character\\hero\\attack\\6.png");
	hero.attackID[20] = iLoadImage("images\\character\\hero\\attack\\7.png");
	hero.attackID[21] = iLoadImage("images\\character\\hero\\attack\\8.png");
	hero.attackID[22] = iLoadImage("images\\character\\hero\\attack\\9.png");
	hero.attackID[23] = iLoadImage("images\\character\\hero\\attack\\10.png");
	hero.attackID[24] = iLoadImage("images\\character\\hero\\attack\\11.png");
	hero.attackID[25] = iLoadImage("images\\character\\hero\\attack\\12.png");
	hero.attackID[26] = iLoadImage("images\\character\\hero\\attack\\13.png");
	//hero.attackID[27] = iLoadImage("images\\character\\hero\\attack\\14.png");
	//*******************************************************************************************


	//******************************HERO HEAVY ATTACK*****************************************

	hero.attack2ID[1] = iLoadImage("images\\character\\hero\\attack2\\left_01.png"); // hero looking right
	hero.attack2ID[2] = iLoadImage("images\\character\\hero\\attack2\\left_02.png");
	hero.attack2ID[3] = iLoadImage("images\\character\\hero\\attack2\\left_04.png");
	hero.attack2ID[4] = iLoadImage("images\\character\\hero\\attack2\\left_05.png");
	hero.attack2ID[5] = iLoadImage("images\\character\\hero\\attack2\\left_06.png");
	hero.attack2ID[6] = iLoadImage("images\\character\\hero\\attack2\\left_07.png");
	hero.attack2ID[7] = iLoadImage("images\\character\\hero\\attack2\\left_09.png");
	hero.attack2ID[8] = iLoadImage("images\\character\\hero\\attack2\\left_10.png");
	hero.attack2ID[9] = iLoadImage("images\\character\\hero\\attack2\\left_11.png");
	hero.attack2ID[10] = iLoadImage("images\\character\\hero\\attack2\\left_13.png");
	hero.attack2ID[11] = iLoadImage("images\\character\\hero\\attack2\\left_14.png");
	hero.attack2ID[12] = iLoadImage("images\\character\\hero\\attack2\\left_15.png");
	hero.attack2ID[13] = iLoadImage("images\\character\\hero\\attack2\\left_16.png");
	hero.attack2ID[14] = iLoadImage("images\\character\\hero\\attack2\\left_17.png");
	hero.attack2ID[15] = iLoadImage("images\\character\\hero\\attack2\\left_18.png");
	hero.attack2ID[16] = iLoadImage("images\\character\\hero\\attack2\\left_19.png");
	hero.attack2ID[17] = iLoadImage("images\\character\\hero\\attack2\\left_20.png");

	hero.attack2ID[18] = iLoadImage("images\\character\\hero\\attack2\\right_14.png"); // hero looking left
	hero.attack2ID[19] = iLoadImage("images\\character\\hero\\attack2\\right_13.png");
	hero.attack2ID[20] = iLoadImage("images\\character\\hero\\attack2\\right_12.png");
	hero.attack2ID[21] = iLoadImage("images\\character\\hero\\attack2\\right_11.png");
	hero.attack2ID[22] = iLoadImage("images\\character\\hero\\attack2\\right_10.png");
	hero.attack2ID[23] = iLoadImage("images\\character\\hero\\attack2\\right_09.png");
	hero.attack2ID[24] = iLoadImage("images\\character\\hero\\attack2\\right_08.png");
	hero.attack2ID[25] = iLoadImage("images\\character\\hero\\attack2\\right_07.png");
	hero.attack2ID[26] = iLoadImage("images\\character\\hero\\attack2\\right_06.png");
	hero.attack2ID[27] = iLoadImage("images\\character\\hero\\attack2\\right_05.png");
	hero.attack2ID[28] = iLoadImage("images\\character\\hero\\attack2\\right_04.png");
	hero.attack2ID[29] = iLoadImage("images\\character\\hero\\attack2\\right_03.png");
	hero.attack2ID[30] = iLoadImage("images\\character\\hero\\attack2\\right_02.png");
	hero.attack2ID[31] = iLoadImage("images\\character\\hero\\attack2\\right_01.png");
	hero.attack2ID[32] = iLoadImage("images\\character\\hero\\attack2\\3.png");
	hero.attack2ID[33] = iLoadImage("images\\character\\hero\\attack2\\2.png");
	hero.attack2ID[34] = iLoadImage("images\\character\\hero\\attack2\\1.png");





	//******************************************************************************************


} // level 1


/*loads the images of hero 2*/
void loadImagesHero2() // level 2
{
	// *********************************HERO 2 movement****************************

	// movement
	hero.id[0] = iLoadImage("images\\character\\hero2\\movement\\hero2standing_01.png"); // standing 
	hero.id[1] = iLoadImage("images\\character\\hero2\\movement\\hero2movement_01.png"); // looking right
	hero.id[2] = iLoadImage("images\\character\\hero2\\movement\\hero2movement_02.png");
	hero.id[3] = iLoadImage("images\\character\\hero2\\movement\\hero2movement_03.png");
	hero.id[4] = iLoadImage("images\\character\\hero2\\movement\\hero2movement_04.png");
	hero.id[5] = iLoadImage("images\\character\\hero2\\movement\\hero2movement_05.png");
	hero.id[6] = iLoadImage("images\\character\\hero2\\movement\\hero2movement_06.png");
	hero.id[7] = iLoadImage("images\\character\\hero2\\movement\\hero2movement_07.png");
	hero.id[8] = iLoadImage("images\\character\\hero2\\movement\\hero2movement_08.png");
	hero.id[9] = iLoadImage("images\\character\\hero2\\movement\\hero2movement_09.png");
	hero.id[10] = iLoadImage("images\\character\\hero2\\movement\\hero2movement_10.png");
	hero.id[11] = iLoadImage("images\\character\\hero2\\movement\\hero2movement_11.png");
	hero.id[12] = iLoadImage("images\\character\\hero2\\movement\\hero2movement_12.png");
	hero.id[13] = iLoadImage("images\\character\\hero2\\movement\\hero2movement_13.png");
	hero.id[14] = iLoadImage("images\\character\\hero2\\movement\\hero2movement_14.png");
	hero.id[15] = iLoadImage("images\\character\\hero2\\movement\\hero2movement_15.png");
	hero.id[16] = iLoadImage("images\\character\\hero2\\movement\\hero2movement_15.png");


	hero.id[17] = iLoadImage("images\\character\\hero2\\movement\\hero2standing_02.png"); // standing 

	hero.id[32] = iLoadImage("images\\character\\hero2\\movement\\movement_flipped_hero2_01.png"); // looking left : it's reversed to match with the correct animation
	hero.id[31] = iLoadImage("images\\character\\hero2\\movement\\movement_flipped_hero2_02.png");
	hero.id[30] = iLoadImage("images\\character\\hero2\\movement\\movement_flipped_hero2_03.png");
	hero.id[29] = iLoadImage("images\\character\\hero2\\movement\\movement_flipped_hero2_04.png");
	hero.id[28] = iLoadImage("images\\character\\hero2\\movement\\movement_flipped_hero2_05.png");
	hero.id[27] = iLoadImage("images\\character\\hero2\\movement\\movement_flipped_hero2_06.png");
	hero.id[26] = iLoadImage("images\\character\\hero2\\movement\\movement_flipped_hero2_07.png");
	hero.id[25] = iLoadImage("images\\character\\hero2\\movement\\movement_flipped_hero2_08.png");
	hero.id[24] = iLoadImage("images\\character\\hero2\\movement\\movement_flipped_hero2_09.png");
	hero.id[23] = iLoadImage("images\\character\\hero2\\movement\\movement_flipped_hero2_10.png");
	hero.id[22] = iLoadImage("images\\character\\hero2\\movement\\movement_flipped_hero2_11.png");
	hero.id[21] = iLoadImage("images\\character\\hero2\\movement\\movement_flipped_hero2_12.png");
	hero.id[20] = iLoadImage("images\\character\\hero2\\movement\\movement_flipped_hero2_13.png");
	hero.id[19] = iLoadImage("images\\character\\hero2\\movement\\movement_flipped_hero2_14.png");
	hero.id[18] = iLoadImage("images\\character\\hero2\\movement\\movement_flipped_hero2_15.png");



	// **************************************hero2 jump************************************


	hero.id[33] = iLoadImage("images\\character\\hero2\\jump\\h2Jump_01.png"); // LOOKING RIGHT
	hero.id[34] = iLoadImage("images\\character\\hero2\\jump\\h2Jump_02.png");
	hero.id[35] = iLoadImage("images\\character\\hero2\\jump\\h2Jump_03.png");
	hero.id[36] = iLoadImage("images\\character\\hero2\\jump\\h2Jump_04.png");
	hero.id[37] = iLoadImage("images\\character\\hero2\\jump\\h2Jump_05.png");
	hero.id[38] = iLoadImage("images\\character\\hero2\\jump\\h2Jump_06.png");
	hero.id[39] = iLoadImage("images\\character\\hero2\\jump\\h2Jump_07.png");


	hero.id[40] = iLoadImage("images\\character\\hero2\\jump\\h2Jump_08.png"); // starts going down
	hero.id[41] = iLoadImage("images\\character\\hero2\\jump\\h2Jump_09.png");
	hero.id[42] = iLoadImage("images\\character\\hero2\\jump\\h2Jump_10.png");
	hero.id[43] = iLoadImage("images\\character\\hero2\\jump\\h2Jump_11.png");
	hero.id[44] = iLoadImage("images\\character\\hero2\\jump\\h2Jump_12.png");
	hero.id[45] = iLoadImage("images\\character\\hero2\\jump\\h2Jump_13.png");
	hero.id[46] = iLoadImage("images\\character\\hero2\\jump\\h2Jump_14.png");
	hero.id[47] = iLoadImage("images\\character\\hero2\\jump\\h2Jump_15.png");
	hero.id[48] = iLoadImage("images\\character\\hero2\\jump\\h2Jump_16.png");
	hero.id[49] = iLoadImage("images\\character\\hero2\\jump\\h2Jump_17.png");
	hero.id[50] = iLoadImage("images\\character\\hero2\\jump\\h2Jump_18.png");
	hero.id[51] = iLoadImage("images\\character\\hero2\\jump\\h2Jump_19.png");



	hero.id[52] = iLoadImage("images\\character\\hero2\\jump\\f_18.png");  // LOOKING LEFT
	hero.id[53] = iLoadImage("images\\character\\hero2\\jump\\f_17.png");
	hero.id[54] = iLoadImage("images\\character\\hero2\\jump\\f_16.png");
	hero.id[55] = iLoadImage("images\\character\\hero2\\jump\\f_15.png");
	hero.id[56] = iLoadImage("images\\character\\hero2\\jump\\f_14.png");
	hero.id[57] = iLoadImage("images\\character\\hero2\\jump\\f_13.png");


	hero.id[58] = iLoadImage("images\\character\\hero2\\jump\\f_12.png");   // starts going down
	hero.id[59] = iLoadImage("images\\character\\hero2\\jump\\f_11.png");
	hero.id[60] = iLoadImage("images\\character\\hero2\\jump\\f_10.png");
	hero.id[61] = iLoadImage("images\\character\\hero2\\jump\\f_09.png");
	hero.id[62] = iLoadImage("images\\character\\hero2\\jump\\f_08.png");
	hero.id[63] = iLoadImage("images\\character\\hero2\\jump\\f_07.png");
	hero.id[64] = iLoadImage("images\\character\\hero2\\jump\\f_06.png");
	hero.id[65] = iLoadImage("images\\character\\hero2\\jump\\f_05.png");
	hero.id[66] = iLoadImage("images\\character\\hero2\\jump\\f_04.png");
	hero.id[67] = iLoadImage("images\\character\\hero2\\jump\\f_03.png");
	hero.id[68] = iLoadImage("images\\character\\hero2\\jump\\f_02.png");
	hero.id[69] = iLoadImage("images\\character\\hero2\\jump\\f_01.png");



	// CHANGE

	//**************************************************************************************
	//*********************************POWER**********************************************


	hero.powerID[0] = iLoadImage("images\\character\\hero2\\power\\h2powerR_08.png"); // hero looking right
	hero.powerID[1] = iLoadImage("images\\character\\hero2\\power\\h2powerR_07.png");
	hero.powerID[2] = iLoadImage("images\\character\\hero2\\power\\h2powerR_06.png");
	hero.powerID[3] = iLoadImage("images\\character\\hero2\\power\\h2powerR_05.png");
	hero.powerID[4] = iLoadImage("images\\character\\hero2\\power\\h2powerR_04.png");
	hero.powerID[5] = iLoadImage("images\\character\\hero2\\power\\h2powerR_03.png"); // hero sits and fissure should be on
	hero.powerID[6] = iLoadImage("images\\character\\hero2\\power\\h2powerR_02.png");
	hero.powerID[7] = iLoadImage("images\\character\\hero2\\power\\h2powerR_01.png");

	hero.powerID[16] = iLoadImage("images\\character\\hero2\\power\\h2fissureR_02.png"); // fissure: hero looking right
	hero.powerID[17] = iLoadImage("images\\character\\hero2\\power\\h2fissureR_03.png");
	hero.powerID[18] = iLoadImage("images\\character\\hero2\\power\\h2fissureR_04.png");
	hero.powerID[19] = iLoadImage("images\\character\\hero2\\power\\h2fissureR_05.png");
	hero.powerID[20] = iLoadImage("images\\character\\hero2\\power\\h2fissureR_06.png");



	hero.powerID[8] = iLoadImage("images\\character\\hero2\\power\\h2powerL_01.png"); // hero looking left
	hero.powerID[9] = iLoadImage("images\\character\\hero2\\power\\h2powerL_02.png");
	hero.powerID[10] = iLoadImage("images\\character\\hero2\\power\\h2powerL_03.png");
	hero.powerID[11] = iLoadImage("images\\character\\hero2\\power\\h2powerL_04.png");
	hero.powerID[12] = iLoadImage("images\\character\\hero2\\power\\h2powerL_05.png"); // hero sits and fissure on
	hero.powerID[13] = iLoadImage("images\\character\\hero2\\power\\h2powerL_06.png");
	hero.powerID[14] = iLoadImage("images\\character\\hero2\\power\\h2powerL_07.png");
	hero.powerID[15] = iLoadImage("images\\character\\hero2\\power\\h2powerL_08.png");

	hero.powerID[21] = iLoadImage("images\\character\\hero2\\power\\h2fissureL_02.png");  // fissure: hero looking left
	hero.powerID[22] = iLoadImage("images\\character\\hero2\\power\\h2fissureL_03.png");
	hero.powerID[23] = iLoadImage("images\\character\\hero2\\power\\h2fissureL_04.png");
	hero.powerID[24] = iLoadImage("images\\character\\hero2\\power\\h2fissureL_05.png");
	hero.powerID[25] = iLoadImage("images\\character\\hero2\\power\\h2fissureL_06.png");


	//**************************************************************************************

	///*********************PROJECTILE

	//**************************************************************************************

	hero.attackID[11] = iLoadImage("images\\character\\hero2\\attack\\RIGHT_01.png");
	hero.attackID[12] = iLoadImage("images\\character\\hero2\\attack\\RIGHT_02.png");
	hero.attackID[13] = iLoadImage("images\\character\\hero2\\attack\\RIGHT_03.png");
	hero.attackID[14] = iLoadImage("images\\character\\hero2\\attack\\RIGHT_04.png");
	hero.attackID[15] = iLoadImage("images\\character\\hero2\\attack\\RIGHT_05.png");
	hero.attackID[16] = iLoadImage("images\\character\\hero2\\attack\\RIGHT_06.png");
	hero.attackID[17] = iLoadImage("images\\character\\hero2\\attack\\RIGHT_07.png");
	hero.attackID[18] = iLoadImage("images\\character\\hero2\\attack\\RIGHT_08.png");
	hero.attackID[19] = iLoadImage("images\\character\\hero2\\attack\\RIGHT_09.png");
	hero.attackID[20] = iLoadImage("images\\character\\hero2\\attack\\RIGHT_10.png");
	hero.attackID[21] = iLoadImage("images\\character\\hero2\\attack\\RIGHT_11.png");


	//**************************************************************************************
	// flipped
	//11 - 21
	hero.attackID[0] = iLoadImage("images\\character\\hero2\\attack\\LEFT_01.png");
	hero.attackID[1] = iLoadImage("images\\character\\hero2\\attack\\LEFT_02.png");
	hero.attackID[2] = iLoadImage("images\\character\\hero2\\attack\\LEFT_03.png");
	hero.attackID[3] = iLoadImage("images\\character\\hero2\\attack\\LEFT_04.png");
	hero.attackID[4] = iLoadImage("images\\character\\hero2\\attack\\LEFT_05.png");
	hero.attackID[5] = iLoadImage("images\\character\\hero2\\attack\\LEFT_06.png");
	hero.attackID[6] = iLoadImage("images\\character\\hero2\\attack\\LEFT_07.png");
	hero.attackID[7] = iLoadImage("images\\character\\hero2\\attack\\LEFT_08.png");
	hero.attackID[8] = iLoadImage("images\\character\\hero2\\attack\\LEFT_09.png");
	hero.attackID[9] = iLoadImage("images\\character\\hero2\\attack\\LEFT_10.png");
	hero.attackID[10] = iLoadImage("images\\character\\hero2\\attack\\LEFT_11.png");

	hero.attackID[22] = iLoadImage("images\\character\\hero2\\attack\\Projectile Right.png"); //RIGHT PROJECTILE
	hero.attackID[23] = iLoadImage("images\\character\\hero2\\attack\\Projectile Left.png"); //LEFT PROJECTILE
	//hero.attackID[23] = iLoadImage("images\\character\\hero2\\attack\\LEFT_11.png"); //RIGHT PROJECTILE


}

/*
the function is called after the hero is selected, ie it's called from menuLogic()
it initializes and loads the images of the selected hero
*/
void initializeHero(int mode)
{
	if (mode == HERO_1)
	{
		hero_1 = true;
		hero_2 = false;

		loadImagesHero();
		hero.initializeDimensions(150, 150);

		H1_HPbar.createHPbar(54, 650, 349, 329, 161, 689, 181, 708, 349, 708, 329, 689);
		life.createLife(269, 674, 281, 685, 326, 685, 318, 674); // initializes the 3 lives of the hero (red)


	}
	else if (mode == HERO_2)
	{
		hero_2 = true;
		hero_1 = false;

		loadImagesHero2();
		hero.initializeDimensions(200, 200);
		hero.initializeMechanics(10, 3, 100, NULL); // null is to be filled with a value later on

		H1_HPbar.createHPbar(54, 650, 340, 317, 145, 686, 146, 709, 340, 709, 317, 686);
		life.createLife(259, 673, 270, 687, 317, 687, 307, 673);
	}

}

/*renders the hero related everything; called from iDraw*/
void renderHero()
{


	if (!hero.attack && !hero.attack2 && !hero.power)
	{


		if (hero.jump)
		{
			showHeroJump();

		}
		else
		{

			showHero();
		}

	}


	if (hero.attack)
	{
		renderHeroAttack(LIGHT_ATTACK);
	}
	if (hero.attack2)
	{
		renderHeroAttack(HEAVY_ATTACK);

	}
	if (hero.power)
	{
		renderHeroAttack(POWER);
	}

	if (hero.channelPower)
	{
		renderHeroAttack(FISSURE);
	}



}

/*
TIMER function:
when space is pressed, then hero.jump is made true. the next execution sequence will start from autoMotion().
the autiomotion then calls the following function to show the animation for hero jump
*/
void heroJump()
{
	if (hero.direction == RIGHT)
	{
		if (hero.jumpUp)
		{
			hero.jump_dy += 5;



			if (hero_1) // hero 1
			{
				heroJumpIndex++;
				if (heroJumpIndex > 19)
					heroJumpIndex = 19;

				if (hero.jump_dy > JUMPLIMIT)
				{
					hero.jumpUp = false;
					heroJumpIndex = 20;
				}
			}
			else // hero 2
			{
				heroJumpIndex++;
				if (heroJumpIndex > 39)
					heroJumpIndex = 39;

				if (hero.jump_dy > JUMPLIMIT)
				{
					hero.jumpUp = false;
					heroJumpIndex = 40;
				}

			}




		}
		else			// hero moving down
		{
			hero.jump_dy -= 5;
			if ((hero.y + hero.jump_dy) <= 210)
			{


				if (hero_1)
				{
					heroJumpIndex++;
					if (heroJumpIndex > 23)
						heroJumpIndex = 23;


				}
				else
				{
					heroJumpIndex++;
					if (heroJumpIndex > 51)
						heroJumpIndex = 51;


				}


			}


			if (hero.jump_dy < 0)
			{
				hero.jump = false;
				hero.jump_dy = 0;
			}


		}
	}


	else if (hero.direction == LEFT)
	{

		if (hero.jumpUp)
		{
			hero.jump_dy += 5;

			if (hero_1)
			{
				heroJumpIndex++;
				if (heroJumpIndex > 29)
					heroJumpIndex = 29;

				if (hero.jump_dy > JUMPLIMIT)
				{
					hero.jumpUp = false;
					heroJumpIndex = 30;
				}
			}
			else // hero 2
			{
				heroJumpIndex++;
				if (heroJumpIndex > 57)
					heroJumpIndex = 57;

				if (hero.jump_dy > JUMPLIMIT) // when maximum limit reached 
				{
					hero.jumpUp = false;
					heroJumpIndex = 58;
				}



			}
		}
		else
		{
			hero.jump_dy -= 5;
			if ((hero.y + hero.jump_dy) <= 210)
			{


				if (hero_1)
				{
					heroJumpIndex++;
					if (heroJumpIndex > 33)
						heroJumpIndex = 33;
				}
				else
				{

					heroJumpIndex++;
					if (heroJumpIndex > 69)
						heroJumpIndex = 69;

				}


			}
			if (hero.jump_dy < 0)
			{
				hero.jump = false;
				hero.jump_dy = 0;
			}


		}
	}

}


/*
renders the images for when hero is standing straight or when it's running
furthermore, the attackIndex/powerIndex are being initialized/set in accordance to the hero.direction
*/
void showHero()
{
	if (!heroStanding)
	{
		iShowImage(hero.x, hero.y, hero.width, hero.height, hero.id[hero.index]);

		heroStandCounter++;
		if (heroStandCounter >= 20)
		{
			heroStanding = true;


		}

		iDelayMS(70);
	}
	else
	{
		if (hero.direction == RIGHT)
		{
			iShowImage(hero.x, hero.y, hero.width, hero.height, hero.id[0]);
			hero.attackIndex = 1;
			hero.index = 1;
			hero.attack = false;
		}
		else
		{
			if (hero_1)
			{
				iShowImage(hero.x, hero.y, hero.width, hero.height, hero.id[7]);

				hero.index = 7;
				hero.attackIndex = 14;
				hero.attack = false;

			}
			else
			{
				iShowImage(hero.x, hero.y, hero.width, hero.height, hero.id[17]);

				hero.index = 18;
				hero.attackIndex = 14;
				hero.attack = false;
			}



		}

	}


}

/*
renders the jump animation.
implicitly called from renderHero().
*/
void showHeroJump()
{
	if (hero_1)
		iShowImage(hero.x, hero.y + hero.jump_dy, hero.width + 30, hero.height + 30, hero.id[heroJumpIndex]);
	else
		iShowImage(hero.x, hero.y + hero.jump_dy, 200, 400, hero.id[heroJumpIndex]);


}

/*
the function is called when the hero moves, ie: from iSpecialKeyboard()
it moves the hero in the specified direction (dir). RIGHT means the hero moves towards right, which means the background should move towards left.
thus, the functions moveScreen() and moveTile() are called implicitly

furthermore, during the slope segment the heromovements are different. They are implemented in a block using a conditional statement
*/
void heroMovement(int dir)
{
	if (dir == RIGHT)
	{
		hero.direction = dir;

		if (backgroundEnd || bridgeSegment)
			hero.x += hero.speed;			      //move player // speed is 15 here



		//*************************** SLOPE MECHANICS***********************************
		if (level_2)
		{
			if (leftSlope)
			{
				hero.y -= 10;
				if (hero.y == 100) // correcting the value because it suits perfectly
					hero.y = 80;
				if (hero.y < 80)
					hero.y = 80;
			}


			if (RightSlope)
			{
				hero.y += 10;
				if (hero.y == 170)
					hero.y = 180;
			}
		}

		//******************************************************************************



		hero.index++;

		if (hero_1)
		{
			if (hero.index >= 6)
				hero.index = 1;
		}
		else
		{
			if (hero.index >= 15)
				hero.index = 1;
		}




		heroStanding = false;
		// CHANGE
		//resetting the index values. else for sprite starts from the beginning
		if (hero_1)
		{
			hero.attackIndex = 1;       //resetting the index values. else for sprite starts from the beginning
			hero.attack2Index = 1;
		}
		if (hero_2)
		{
			hero.attackIndex = 11;
			hero.fissureIndex = 16;
			hero.powerIndex = 0;
			hero.projectileTarget = RIGHT;
		}


		if (!backgroundEnd && !bridgeSegment) //counters background motion
		{
			moveScreen(LEFT);
			moveTile(LEFT);

			counterMotion(CREEPS, RIGHT, MANUAL);
		}




		if ((hero.x >= 1190) && backgroundEnd)  // if boss comes, dont let the player escape
		{
			hero.x = 1190;
		}





	}

	else
	{
		hero.direction = LEFT;
		if (backgroundEnd || bridgeSegment)
			hero.x -= hero.speed;			//move player


		// SLOPE MECHANICS
		if (level_2)
		{
			if (leftSlope)
				hero.y += 10;


			if (RightSlope){
				hero.y -= 10;
				if (hero.y == 90)
					hero.y = 80;
				if (hero.y < 80)
					hero.y = 80;
			}
		}






		hero.index++;

		if (hero_1)
		{
			if (hero.index >= 13)
				hero.index = 8;
		}
		else
		{
			if (hero.index >= 32)
				hero.index = 18;
		}


		heroStanding = false;

		// CHANGE

		if (hero_1)
		{
			hero.attackIndex = 14; //resetting the index values. else for sprite starts from the beginning
			hero.attack2Index = 18;
		}
		else
		{

			hero.attackIndex = 0;
			hero.fissureIndex = 21;
			hero.powerIndex = 8;
			hero.projectileTarget = LEFT;

			//hero.attackIndex = 11;
		}

		hero.attackIndex = 14; //resetting the index values. else for sprite starts from the beginning
		hero.attack2Index = 18;
		//hero.powerIndex = 8;
	//	hero.fissureIndex = 21;

		if (!backgroundEnd && !bridgeSegment) //counters background motion
		{
			moveScreen(RIGHT);
			moveTile(RIGHT);

			counterMotion(CREEPS, LEFT, MANUAL);

		}

		if ((hero.x <= 45) && backgroundEnd) // if boss comes, dont let the player escape
		{
			hero.x = 45;

		}



	}


}

/*
:: called from heroAutoMotion.
it implements the animation for the hero attacks, ie: LIGHT ATTACK, HEAVY ATTACK, POWER, FISSURE
*/
void heroAttack(int mode)
{

	if (mode == LIGHT_ATTACK)
	{
		if (hero_1)
		{
			if (hero.direction == LEFT)
			{
				hero.attackIndex++;
				if (hero.attackIndex >= 26)
				{
					creepDamage(DAMAGE, LIGHT_ATTACK); // creep got hurt if creep is within range of attack animation
					bossDamage(DAMAGE, LIGHT_ATTACK);

					hero.attackIndex = 14;
					hero.attack = false;
				}


			}
			else // for hero 2
			{

				hero.attackIndex++;
				if (hero.attackIndex >= 13)
				{
					creepDamage(DAMAGE, LIGHT_ATTACK); // creep got hurt if creep is within range of attack animation
					bossDamage(DAMAGE, LIGHT_ATTACK);

					hero.attackIndex = 1;
					hero.attack = false;

				}

			}
		}


		// for hero 2
		else
		{

			// this is for hero 2 LIGHT attack
			//0 - 11  
			// 11 - 21


			if (hero.direction == LEFT)
			{
				hero.attackIndex++;

				// if hero image == 4 then power show
				if (hero.attackIndex == 4) // when hero sits and the projectile starts from here
				{
					hero.projectile = true;
				}

				if (hero.attackIndex >= 10)
				{
					//cout << "inside piss" << endl;

					hero.attackIndex = 0;
					hero.attack = false;
				}

			}
			else
			{

				hero.attackIndex++;

				if (hero.attackIndex == 14)
				{
					hero.projectile = true;
					//hero.attack = false;
				}


				if (hero.attackIndex >= 21)
				{
					//cout << "inside poop" << endl;

					hero.attackIndex = 11;
					hero.attack = false;

				}

			}


		}




	}

	else if (mode == HEAVY_ATTACK)
	{
		if (hero.direction == LEFT)   	// hero looking left
		{
			hero.attack2Index++;
			if (hero.attack2Index >= 34)
			{
				creepDamage(DAMAGE, HEAVY_ATTACK); // creep gets hurt if creep is within range of attack animation
				bossDamage(DAMAGE, HEAVY_ATTACK);

				hero.attack2Index = 18;
				hero.attack2 = false;
			}


		}
		else							// hero looking right
		{

			hero.attack2Index++;
			if (hero.attack2Index >= 17)
			{
				creepDamage(DAMAGE, HEAVY_ATTACK); // creep got hurt if creep is within range of attack animation
				bossDamage(DAMAGE, HEAVY_ATTACK);

				hero.attack2Index = 1;
				hero.attack2 = false;

			}

		}



	}



	if (mode == POWER)
	{
		if (hero.direction == RIGHT)
		{

			if (!hero.channelPower)
				hero.powerIndex++;

			if (hero.powerIndex == 5) // animation when hero sits down, this is where the fissure should come; and when enemies are near, they get damaged
			{


				creepDamage(DAMAGE, POWER); // creep got hurt if creep is within range of attack animation
				bossDamage(DAMAGE, POWER);

				hero.powerIndex = 5;
				hero.channelPower = true;
			}

			if (hero.powerIndex >= 7)
			{


				hero.power = false;
				hero.powerIndex = 0;


			}
		}
		else
		{

			if (!hero.channelPower)
				hero.powerIndex++;

			if (hero.powerIndex == 12) // animation when hero sits down, this is where the fissure should come
			{

				creepDamage(DAMAGE, POWER); // creep got hurt if creep is within range of attack animation
				bossDamage(DAMAGE, POWER);

				hero.powerIndex = 12;
				hero.channelPower = true;
			}

			if (hero.powerIndex >= 15)
			{

				hero.power = false;
				hero.powerIndex = 8;


			}

		}
	}



	static int c = 0;

	if (mode == FISSURE)
	{
		if (hero.direction == RIGHT)
		{
			hero.fissureIndex++;
			if (hero.fissureIndex >= 20)
			{
				hero.fissureIndex = 20;
				c++;
				if (c >= fissureDuration)
				{


					hero.fissureIndex = 16;
					hero.channelPower = false;

					c = 0;
				}




			}
		}
		else
		{
			hero.fissureIndex++;
			if (hero.fissureIndex >= 25)
			{

				c++;
				hero.fissureIndex = 25;
				if (c >= fissureDuration)
				{
					hero.fissureIndex = 21;
					hero.channelPower = false;
					c = 0;
				}
			}

		}
	}

}

/*
:: called from iDraw
it shows the images of hero attacks
*/
void renderHeroAttack(int mode)
{
	if (mode == LIGHT_ATTACK)
		iShowImage(hero.x, hero.y, 200, 200, hero.attackID[hero.attackIndex]);
	if (mode == HEAVY_ATTACK)
		iShowImage(hero.x, hero.y + 13, 200, 200, hero.attack2ID[hero.attack2Index]);
	if (mode == POWER)
	{
		if (hero_1)
			iShowImage(hero.x, hero.y + 13, 200, 200, hero.powerID[hero.powerIndex]);
		else
		{
			iShowImage(hero.x, hero.y + 13, 200, 200, hero.powerID[hero.powerIndex]);
			iDelayMS(70);
		}



	}

	if (mode == FISSURE) // only hero 2 can shoot fissures
	{
		if (hero.direction == RIGHT)
			iShowImage(hero.x + 130, hero.y + 10, 400, 100, hero.powerID[hero.fissureIndex]);
		else
			iShowImage(abs((hero.x + 55) - heroFissureLength), hero.y + 10, 400, 100, hero.powerID[hero.fissureIndex]);

		iDelayMS(30);

	}

}

/*
:: called from checkHeroDamage() and creepAttackLogic()
hero will get damage depending on by what it is hit.
ie: when hero is damaged by creeps, then hero hp will reduce less, but for boss, it's more

furthermore, when the hero hp bar (green) completely deplishes, then resetHero() is called, which resets the green hp bar and decreases one life bar (red)

*/
void heroDamage(int mode)
{

	if (mode == byBOSS)
	{
		hero.HP -= 1;
		H1_HPbar.variable1 -= 1;
		H1_HPbar.variable2 -= 1;


	}
	if (mode == byCreeps)
	{
		hero.HP -= 1;
		H1_HPbar.variable1 -= 10;
		H1_HPbar.variable2 -= 10;
	}


	if (H1_HPbar.variable1 <= H1_HPbar.polygon_x[1])
	{

		//render hero image as blinking for a a few seconds.
		resetHero();

	}
}

/*
:: called from heroAutoMotion
when the hero comes in the range of boss attack ( when fissure is down - channelPower is true ) , then the heroDamage() is called implicitly

*/
void checkHeroDamage()
{
	if (L1Boss.direction == LEFT)
	{
		if (hero.x >= L1Boss.x + 300 && hero.x <= L1Boss.x + 300 + fissureLength)
		{
			//cout << "BOSS LOOKING RIGHT" << endl;
			if (L1Boss.channelPower)
			{
				heroDamage(byBOSS);

			}

		}

	}
	else
	{
		//cout << "BOSS LOOKING LEFT" << endl;
		if (hero.x <= L1Boss.x + 200 && hero.x >= L1Boss.x + 200 - fissureLength)
		{

			if (L1Boss.channelPower)
			{

				heroDamage(byBOSS);

			}

		}

	}

}

/*
:: called from heroAutoMotion() and heroDamage()
the function resets the hero hp bar (green) and decreases 1 life bar ( red ) when the hpbar completely deplishes.
the function is also called when the hero falls down from gap.

if at any time if the hero life ( which is initially 3 ) becomes less than 1, then GAME OVER.
*/
void resetHero()
{


	if (hero.life <= 1) 		//gameover
	{
		gameOver = true;

		MenuController = GAMEOVER;
		hero.life = 3;

		gameStart = false;

		if (!temp_5)
		{
			playSound(STOP);
			playSound(GAMEOVER);
			temp_5 = true;
		}

		return;
	}


	hero.life--;
	life.variable1 -= 15; //removes one life bar 
	life.variable2 -= 15;


	if (hero_1)
	{
		H1_HPbar.variable1 = 349; // resets hp bar
		H1_HPbar.variable2 = 329;

		mana.variable1 = 359; // resetting mana bar
		mana.variable2 = 354;

	}
	else
	{
		H1_HPbar.variable1 = 340; // resets hp bar
		H1_HPbar.variable2 = 317;

		mana.variable1 = 359; // resetting mana bar
		mana.variable2 = 354;

	}
	


	if (hero.direction == RIGHT)
	{
		if (bridgeDone)
		{


			//hero.x = blockCenterCoordinate[bridgeIndex];  //resets from the nearest block

			hero.x = blockCenterCoordinate[0]; // resets from the beginning
			bridgeIndex = 0;
			resetBridge();

		}
		else
		{
			//hero.x -= 100; // add blinking effect by turning hero.show true/false consecutively using counter method

		}


	}
	if (hero.direction == LEFT)
	{


		//	hero.x += 100;



	}

	hero.y = tileHeight - 16;


	if (level_2)
	{
		if (hero.direction == RIGHT)
		{
			hero.y = 180;
			hero.x -= 40; // reset from 20 pixels away
			screen.x += 40;
		}
		else
		{
			hero.y = 180;
			hero.x += 40; // reset from 20 pixels away
			screen.x -= 40;

		}

	}

	fallAnimate = false;
}

/*
:: called from creepDamage()
if a creep dies, then randomly, the hero will gain HP or mana.
Furthermore, the hero gains Score if a creep dies.
*/
void heroGain(int mode)
{
	if (mode == HPBAR)
	{
		hero.HP += 2;


		if (hero_1)
		{

			H1_HPbar.variable1 += 20; // gains HP (RED)
			H1_HPbar.variable2 += 20;

			// the following codes are used not to exceed the HP bar, ie when hero gains more HP than it can hold in the bar

			if (H1_HPbar.variable1 >= 349)
			{
				H1_HPbar.variable1 = 349;
				H1_HPbar.variable2 = 329;
			}


		}
		else
		{
			H1_HPbar.variable1 += 20; // resets hp bar
			H1_HPbar.variable2 += 20;

			// the following codes are used not to exceed the HP bar, ie when hero gains more HP than it can hold in the bar

			if (H1_HPbar.variable1 >= 340)
			{
				H1_HPbar.variable1 = 340;
				H1_HPbar.variable2 = 317;
			}

		}

	}
	else if (mode == MANA)
	{
		mana.count += 1; // gains 1 mana 

		if (mana.count > 10)
			mana.count = 10;

		mana.variable1 += 10; // resets mana bar
		mana.variable2 += 10;


		// the following codes are used not to exceed the mana bar, ie when hero gains more mana than it can hold in the bar
		if (hero_1)
		{
			if (mana.variable2 >= 354)
			{
				mana.variable1 = 370;
				mana.variable2 = 354;
			}
		}
		else
		{
			if (mana.variable2 >= 340)
			{
				mana.variable1 = 359;
				mana.variable2 = 340;
			}

		}



	}
	else if (mode == SCORE)
	{
		score += 10;

	}


}


/*
animation effect of projectile
*/
void ProjectileAnimation()
{
	int index;

	if (hero.direction == RIGHT)
		index = 22;
	else
		index = 23;

	if (!SlopeSegment)
		iShowImage(hero.projectileX, 230, 100, 60, hero.attackID[index]);
	else
		iShowImage(hero.projectileX, 230-100, 100, 60, hero.attackID[index]);

}



#endif