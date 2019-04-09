#include "iGraphics.h"
#include <iostream>
#include "background.h"
#include "declarations.h"
#include "character.h"
#include "bridge.h"
#include "creeps.h"
#include "hero.h"
#include "boss.h"
#include "UIEffects.h"
#include "music.h"

// patch 6

// pressing 'm' takes to next level

//CREEPS: RIGHT MEANS, CREEPS COMING FROM RIGHT SIDE. THEREFORE, LOOKING LEFT
// HERO: RIGHT MEANS, HERO LOOKING RIGHT
// BOSS: RIGHT MEANS, COMING FROM RIGHT SIDE




// backgroundEnd indicates when the boss is triggered. If the boss comes, then backgroundEND is made true
// and the player cannot escape the region


//cntrl + K + C : COMMENTS A BLOCKS
//cntrl + K + U : UNCOMMENTS A BLOCKS

using namespace std;

void autoMotion();
void enemyAutoMotion();
void loadImages();

/*
The function is called to reset all technical stuff, ie: scoreArray or name array and etc
the ingame variables are not resetted here. They are resetted in the timer function called: initLevels();

*/
void resetGame()
{
	memset(UserNameInput, 0, sizeof(UserNameInput)); // resets the array
	memset(scoreArray, 0, sizeof(scoreArray));

	score = 0;
	UserNameInputIndex = 0;

	loading_dx = 0;
		
	MenuController = SELECTIONSCREEN;
	PreviousMenu = SELECTIONSCREEN;

	

	gameStart = false;
	gameOver = false;
	gameWon_1 = false;

		
	sound = true;
	menuMusic = true;

	






	 

	 


}


void iMouseMove(int mx, int my)
{
	
}


void iPassiveMouseMove(int mx, int my)
{

	PassiveMouseX = mx;
	PassiveMouseY = my;

	//cout << mx << " " << my << endl;

	//int rgb[4];

	// iGetPixelColor(mx, my, rgb); 
	//cout << "MOUSE: ";
	//cout << "color: ";
	//cout << rgb[0] << " " << rgb[1] << " " << rgb[2] << endl;
}

void iMouse(int button, int state, int mx, int my)
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		menuLogic(mx,my); // contains the implementation on w
	}



	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{

	}
}

void iKeyboard(unsigned char key)
{

	if (key == 'm')  // FOR DEBUGGING PURPOSES
	{
		gameWon_1 = false;
		gameStart = true;
		gameOver = false;

		level_1 = false;
		level_2 = true;

		MenuController = PLAY;
		PreviousMenu = PLAY;

		initLevel_2 = true; // initLevels() is called and resetgame() is called implicitly.

		initializeHero(HERO_2);

		hero.y = 180;

	}


	if (MenuController == ENTERNAME)
	{

		if ((key >= 'a' && key <= 'z') || (key >= 'A' && key <= 'Z'))
		{

			UserNameInput[UserNameInputIndex++] = key;
			nameShort = false;

		}
		if (key == '\b')
		{
			UserNameInputIndex--;

			if (UserNameInputIndex < 0) // used to prevent array out of index error
			{
				UserNameInputIndex = 0;
			}

			UserNameInput[UserNameInputIndex] = '\0'; //erases the previous character

		}

		if (key == '\r')
		{

			if (UserNameInputIndex < 4)
			{
				cout << "hello" << endl;

				memset(UserNameInput, 0, sizeof(UserNameInput)); // resets the array
				UserNameInputIndex = 0; // resetting index to start from the beginning
				nameShort = true;
			}
			else
			{

				MenuController = NARRATIVE_1;
				narrativeCounter = 1;
				UserNameInputIndex = 0; // resetting
			}




		}
	}











	if (MenuController == FALLEN_KINGDOM && key == ' ')
	{
		MenuController = SELECTIONSCREEN;
		PreviousMenu = SELECTIONSCREEN;

	}

	if (cutscene)
	{
		if (key == ' ')
		{
			cutsceneIndex++;
			cutscene = false;
			iResumeTimer(timer_ENEMYMOTION);

		}
	}
	if (bossCutscene)
	{
		static int limit;

		if (key == ' ')
		{
			cutsceneIndex++;

			if (level_1)
			{
				limit = 6;
			}
			else
			{
				limit = 12;
			}


			if (cutsceneIndex > limit)
			{
				//cout << "index : " << cutsceneIndex << endl;

				bossCutscene = false;

				iResumeTimer(timer_ENEMYMOTION);

			}

		}
	}



	if (level_2) // hero can jump only in level 2
	{


		if (key == ' ')
		{
			if (!hero.jump && !hero.power && !hero.channelPower)
			{
				if (!SlopeSegment  && HeroJumpingAbility) // hero cannot jump when in a slope
				{
					hero.jump = true;
					hero.jumpUp = true;
				}
			}
		}

		if ( (key == 'D' || key == 'd' ) && !hero.channelPower && mana.count > 0)      // hero power
		{
			hero.power = true;
			mana.variable1 -= 40;
			mana.variable2 -= 40;

			mana.count--; // count is 5. If mana count becomes <0 then hero cannot use any more power

		

		}



	}


	if (bridgeSegment && !fallAnimate)
	{


		if (key == ' ' && gameStart )
		{
			bridge_height += 10;
			if (bridge_height > bridgeGap[bridgeIndex] + 180)
			{
				resetBridge();
				return;
			}

			build_bridge = true;
			heroStanding = true;		

		}


		if (build_bridge)
		{
			if (key == 'p' || key == 'P')
			{
				build_bridge = false;
				bridge_fall = true;
			}

		}
	}



	// if hero is not already attacking and when the cutscene is showing, the hero cannot attack

	else if (!hero.attack && !hero.attack2 && !cutscene && !hero.power)
 	 {

		if (key == 'a' || key == 'A' )
		{
			hero.attack = true; // light attack
		}


		else if ( (key == 's' || key == 'S'))
		{
			hero.attack2 = true; // heavy attack
		}
	

	 }
	if (key == ' ' && MenuController == NARRATIVE_1)
	{
		narrativeCounter++;

		if (narrativeCounter == 5)
		{

			MenuController = HEROSELECTION;
			narrativeCounter = 1;


		}
	}


	
	


	
	
}
//PLAY, FALLEN_KINGDOM, SELECTIONSCREEN, HIGHSCORE, OPTIONS, CREDITS, PAUSEMENU

void iSpecialKeyboard(unsigned char key)
{

	if (!hero.attack && !bridgeSegment && !hero.attack2 && !cutscene && !bossCutscene && !fallAnimate && !hero.channelPower && !hero.power)
	{

		//cout << "screen.x:  " << screen.x << endl;

		if (key == GLUT_KEY_RIGHT)
		{
			environmentTriggers();

			heroMovement(RIGHT);

			if (level_2)
			{
				environmentTriggers2(CREEPS);

			}





		}

		if (key == GLUT_KEY_LEFT)
		{

		//	cout << "screen.x:  " << screen.x << endl;

			//cout << "screen.x : " << screen.x << "  " << "coinstrain: " << backgroundConstrain_1 << endl;
		
			if (level_1)
			{
				if (screen.x != backgroundConstrain_1)
				{
					heroMovement(LEFT);
					environmentTriggers();
				}
			}
			
			else // FOR LEVEL 2
			{

				if (screen.x < backgroundConstrain_2) // level 2: initially the player cannot go any further to the left.
				{
					heroMovement(LEFT);
					environmentTriggers();
					environmentTriggers2(CREEPS);

				}
			
			}
		

			

		}
	                 
	}


	if (key == GLUT_KEY_HOME && MenuController == PLAY)  // goes to escape menu when playing game
	{
		MenuController = PAUSEMENU; //escape menu while playing game
		PreviousMenu = PAUSEMENU;

		iPauseTimer(timer_ENEMYMOTION);
		iPauseTimer(timer_AUTOMOTION);
		iPauseTimer(timer_HEROMOTION);

		gameStart = false;


	}
	if (key == GLUT_KEY_END && MenuController != PAUSEMENU && MenuController != GAMEOVER) // when inside pausemenu, then pressing END wont go back to prev page
	{
		//MenuController = SELECTIONSCREEN;
		MenuController = PreviousMenu;

	}



}



/* timer function for 4 processes:
	1. fixes the background to adjust
	2. rotate bridge
	3. move the player on bridge
	4. fall from bridge animation
*/

void autoMotion()  
{
	



	if (MenuController == LOADING_1)
	{
		loading_dx += 10;
		if (loading_dx >= 837)
		{
			MenuController = PLAY;
			PreviousMenu = PLAY;

			initLevel_1 = true;

			gameStart = true;
			gameOver = false;               // game starts when this is reached
			gameWon_1 = false;


			playSound(STOP);
			playSound(INGAME);
		}
	}

	



	if (fixBackground && backgroundEnd == false) //moves the background to adjust 
		fix_Background(hero.direction);

	if (rotateBridge)
		theta -= 5;


	if (level_2)
	{
		if (!heroStanding && !fallAnimate && !hero.attack && !hero.attack2)
			environmentTriggers2(SLOPE);

		environmentTriggers2(FALL);

		if (hero.jump)
		{

			heroJump();

		}
	}





	
}
bool creepsHP = false;

void heroAutoMotion()
{

	if (fallAnimate && level_2)
	{

		//cout << "inside motion" << endl;

		hero.y -= 10;
		if (hero.y <= -200)
		{

			resetHero();

		}

	}

	if (bridgeSegment)
	{
		if (movePlayer)
			movePlayerOverBridge();

		if (fallAnimate)
		{
			hero.y -= 10;
			if (hero.y <= -200)
			{

				resetHero();

			}

		}
	}

	// CHANGE
	else // HERO RELATED EVERYTHING
	{

		checkHeroDamage();

		if (hero.attack)
		{
			heroAttack(LIGHT_ATTACK);
			creepsHP = true;

		}
		else if (hero.attack2)
		{
			heroAttack(HEAVY_ATTACK);
			creepsHP = true;

		}

		 if (hero.power)    // hero POWER
		{
			heroAttack(POWER);
			creepsHP = true;

		}
		 if (hero.channelPower)
		{
			heroAttack(FISSURE);
			creepsHP = true;

		}

		 if (creepsHP)
		 {
			 for (int i = 0; i < creepsCount; i++)
			 {
				 if (!creeps[i].death)
					 creeps[i].showHP = true;

			 }

		 }


		else
		{
			creepsHP = false;

			for (int i = 0; i < creepsCount; i++)
			{
				creeps[i].showHP = false;
			}
		}
	}

}

void enemyAutoMotion()
{
	if (creepsSegment)
	{
		creepsMovement();

		creepDamage(DYING, NULL);
		creepAttackLogic();

		creepHurtLogic();
	
		
	}

	if (bossSegment)
	{
		if (moveBoss)
		{

				bossMovement();
				//boss walks till reached a specific coordinate after which cutscenes are shown
				if ( (L1Boss.x <= 1100 || L2Boss.x <= 1100) && !temp_4) // temp_4 used because this block will only be executed once.
				{
					bossCutscene = true;
					initializeCutscenes();

					moveBoss = false;
					temp_4 = true;
					iPauseTimer(timer_ENEMYMOTION);


				}
		

		}


		if (L1Boss.show && !L1Boss.attack && !moveBoss)
		{
			bossMovement();

		}
		if (L1Boss.power  && L1Boss.channelPower)
		{
		
			bossAttackLogic(POWER);

		}
		if (L1Boss.attack)
		{
			
			bossAttackLogic(ATTACK);

		}
		if (L1Boss.death)
		{
			//cout << "boss death is true" << endl;
			bossDamage(DYING, NULL);
		}

		//when boss damage is on, then change index of the sprite to render

		if (L1_BossHurt.show)
		{
			L1BossHurtLogic();
		}


	}


}

void loadImages()
{
	
	loadImagesEffects();
	loadImagesUI();

	//loadImagesBackground();
	//loadImagesHero();
	//loadImagesCreep();
	//loadImagesBoss();

	
}



void iDraw()
{
	iClear();


	if (!gameStart)
	{
		renderMenu(PassiveMouseX, PassiveMouseY); //shows menu stuff
	}

	if (gameWon_1) // after level 1 victory
	{
		showBackground();
		showHero();
		renderMenu(PassiveMouseX, PassiveMouseY);

	}

	else if (gameStart)
	{

		if (level_1)
		{

			

			showBackground();

			renderHUD(LIFE, NULL); // 0 MEANS NULL, NO ACTUAL INDEX
			renderHUD(HERO, NULL);
			renderHUD(STAGE_MARK, NULL);
			renderHUD(L1BOSSHPBAR, NULL);
	

			renderUI(OBJECTIVE);
			renderUI(WAVE);

			if (bridge_fall)
			{
				dropBridge();
			}
			if (build_bridge)
			{
				buildBridge();

			}


		

		}
		else if (level_2)
		{

			showBackground();

			renderHUD(LIFE, NULL); // 0 MEANS NULL, NO ACTUAL INDEX
			renderHUD(HERO, NULL);
			renderHUD(STAGE_MARK, NULL);
			renderHUD(L1BOSSHPBAR, NULL);

			renderUI(OBJECTIVE);
			renderUI(WAVE);

		//	showHeroJump();


		}





		//************** the below lines are common for level 1 and 2. *************************

		//showing SCORE
		sprintf_s(scoreArray, "Current Score: %d", score);
		iSetColor(255, 255, 255);
		iText(1100, 50, scoreArray, GLUT_BITMAP_TIMES_ROMAN_24);


		if (cutscene)
		{
			renderNarrative(L1_CUTSCENE, cutsceneIndex);
		}
		if (bossCutscene)
		{
			renderNarrative(L1_CUTSCENE, cutsceneIndex);

		}

		if (bossSegment)
		{

			if (!L1Boss.attack && L1Boss.show)
			{
				renderBoss(MOVE);

				//	cout << "boss moving" << endl;

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



		
		//REFERENCE LINES HERO
		iSetColor(RED);
		iLine(hero.x, tileHeight - 10, hero.x, tileHeight + 500);
		iSetColor(RED);
		iLine(hero.x + 200, tileHeight - 10, hero.x + 200, tileHeight + 500);


		iSetColor(GREEN); // LEFT SIDE OF HERO
		iLine(hero.x+55, tileHeight - 10, hero.x+55, tileHeight + 500);
		iSetColor(BLUE); // RIGHT SIDE OF HERO
		iLine(hero.x + 130, tileHeight - 10, hero.x + 130, tileHeight + 500);

		////REFERENCE LINES BOSS
		//if (bossSegment)
		//{

		//iSetColor(255, 255, 255);
		//iLine(L1Boss.x + 200, tileHeight - 10, L1Boss.x + 200, tileHeight + 500);

		//iSetColor(0, 255, 0);
		//iLine(L1Boss.x + 300, tileHeight - 10, L1Boss.x + 300, tileHeight + 500);
		//}
		//

		//iLine(hero.x + 100+20, 230,  hero.x + 500, 230);

		renderEffects(HERO_HURT_EFFECT, NULL);




		//****************************HERO****************************************

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


		//*********************************************************************


		if (creepsSegment)
		{

			for (int i = 0; i < creepsCount; i++)
			{


				// if atleast one creep is inside canvas range, then do not show direction.
				// P implies !Q. contrapositive will be, Q implies !P
				// ie show direction if no creeps is within range of canvas.




				if (creeps[i].show)
				{

					/*if (creeps[i].x >= 0 && creeps[i].x <= canvasWidth)
					{
						c++;
					}
					if (c <= 0)
					{

						if (creeps[i].x <= 0)
							renderUI(DIRECTION_L);
						else
							renderUI(DIRECTION_R);



					}
                   */

					if (creeps[i].showHP)
					{
						//cout << "inside creeps hud : 935 line" << endl;
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



			//c = 0;
		}


	}

	if (gameOver)
	{
		renderMenu(PassiveMouseX, PassiveMouseY);

	}


}

void initLevels()
{

	if (initLevel_1)
	{

		cout << "reset level 1" << endl;

		level_1 = true;
		level_2 = false;


		loadImagesBoss();
		loadImagesCreep();
		loadImagesBackground();
		initializeObjective();
		loadImagesUI();

		tile.resetValues(0, 0, 25, 10928, 453);
		screen.resetValues(0, 0, 25, 10928, 768);
		screen2.resetValues(10928, 0, 30, 2732, 768);

		iResumeTimer(timer_ENEMYMOTION);
		iResumeTimer(timer_AUTOMOTION);
		iResumeTimer(timer_HEROMOTION);

		//******************BRIDGE*****************************
		resetBridge();
		build_bridge = false;
		bridge_fall = false;
		bridgeDone = false;
		rotateBridge = false;
		theta = 0;
		step = 0;
		bridgeIndex = 0;
		bridgeSegment = true;
		//***********************************************
		//*******************HERO*************************
		
		hero.x = blockCenterCoordinate[0];
		hero.y = tileHeight - 16;
		hero.show = true;
		hero.direction = RIGHT;
		hero.index = 1;
		hero.attack = false;
		hero.attackIndex = 1; //starting the index from 0 causes bugs. a black screen renders
		hero.life = 3;
		hero.HP = 10;
		hero.showHP = false;
		hero.death = false;
		hero.attack2 = false;
		hero.attack2Index = 0;
		heroStanding = true;
		heroStandCounter = 0;

		for (int i = 0; i < creepsLimit; i++)
		{
			heroHurt[i].resetValues();
		}

		//*********************************************************
		//********************ENEMY*******************************
		creepsSegment = false;
		waveIndex = -1;
		waveClear = false;
		creepAttackIndex = 0;


		wait = 0; // USED FOR THE LEVEL 1 BOSS FISSURE WAITING
		fissureLength = 400;
		moveBoss = false;
		bossTrigger = 0;
		bossSegment = false;

		//***************************************************
		//********************OTHER VARIABLES*******************************
		movePlayer = false;
		fallAnimate = false;

		cutscene = false;
		bossCutscene = false;
		cutsceneIndex = 0;
		narrativeCounter = 0;

		gapPassed = false;
		backgroundEnd = false;
		fixBackground = false;
		backgroundCounter = 0;
		stage = 0;

		bloodEffect = false;


		temp = 0;
		temp_2 = true;
		temp_3 = true;
		temp_4 = false;
		temp_5 = false;
		temp_6 = true;
		temp_7 = 0;
		//***************************************************

		initLevel_1 = false;



	}



	if (initLevel_2)
	{
		cout << "reset level 2" << endl;


		level_1 = false;
		level_2 = true;

		loadImagesBoss2();
		loadImagesCreep2();
		loadImagesBackground2();
		initializeObjective2();
		initializeCutscenes2();
		loadImagesUI2();


		objective[objectiveIndex].show = false; // whatever the value of objective index is, turn it to false, so that its not shown during level 2 UNTIL the appropriate conditions are met

		screen.resetValues(0, 0, 20, 10920, 768);
		tile.resetValues(0, 0, 20, 10920, 195);

		iResumeTimer(timer_ENEMYMOTION);
		iResumeTimer(timer_AUTOMOTION);
		iResumeTimer(timer_HEROMOTION);


		//*****************************SLOPE**************************************
		 HeroGoingDown = false;
		 HeroGoingUp = false;
		 leftSlope = false;
		 RightSlope = false;

		 SlopeSegment = false;

		//************************************************************************



		//*****************************HER0***************************************
		hero.x = 550;
		hero.y = 180;
		hero.show = true;
		hero.direction = RIGHT;
		hero.index = 0;
		hero.attack = false;
		hero.attackIndex = 0; 
		hero.life = 3;
		hero.HP = 10;
		hero.showHP = false;
		hero.death = false;
		hero.attack2 = false;
		hero.attack2Index = 0;
		heroStanding = true;
		heroStandCounter = 0;

		heroJumpIndex = 14;
		CreepsTriggerCounter = 1;

		if (hero_1)
		{
			H1_HPbar.createHPbar(54, 650, 390, 370, 167, 697, 187, 720, 390, 720, 370, 697); 
			mana.createLife(159, 677, 167, 697, 370, 697, 354, 677); // shows mana
			mana.count = 5;
			life.createLife(290, 666, 301, 677, 349, 677, 339, 666); // shows the three lives ; red

		}
		else
		{

			H1_HPbar.createHPbar(54, 650, 378, 359, 155, 700, 175, 721, 378, 721, 359, 700);
			mana.createLife(146, 679, 155, 700, 359, 700, 340, 679);
			mana.count = 5;
			life.createLife(276, 667, 287, 679, 330, 679, 325, 667);


		}

	

		for (int i = 0; i < creepsLimit; i++)
		{
			heroHurt[i].resetValues();
		}


		//*************************************************************************
		//*****************************ENEMY***************************************
		creepsSegment = false;
		waveIndex = -1;
		waveClear = false;
		creepAttackIndex = 0;


	
		moveBoss = false;
		bossTrigger = 0;
		bossSegment = false;
		//*************************************************************************
		//*****************************OTHERS***************************************
		waveIndex = -1;
		stage = 0;
		stage_mark.count = 1;
		waveClear = false;

		fallAnimate = false;

		cutscene = false;
		bossCutscene = false;
		cutsceneIndex = 0;
		narrativeCounter = 0;

		gapPassed = false;
		backgroundEnd = false;
		fixBackground = false;
		backgroundCounter = 0;
		stage = 0;

		bloodEffect = false;

		temp = 0;
		temp_2 = true;
		temp_3 = true;
		temp_4 = false;
		temp_5 = false;
		temp_6 = true;
		temp_7 = 0;
		//********************************************************************



		initLevel_2 = false;

	

	

		

	}


}



int main()
{
	iInitialize(canvasWidth, canvasHeight, "The Fallen Kingdom");

	loadImages();

	/*H1_HPbar.createHPbar(54, 650, 349, 329, 161, 689, 181, 708, 349, 708, 329, 689);
	hero.initializeDimensions(150, 150);*/ // hero 1; move this fucntion call to heroselection page. ie whenuser selects a hero, then init them

//	controls[0].setDimensions(1366 - 199, 0, 199, 209);
	//direction[0].setDimensions(0, 500, 168, 66);
//	direction[1].setDimensions(1366-168, 500, 168, 66);

	//L1_BossHPbar.createHPbar(850, 650, 876, 855, 876, 688, 855, 711, 1196, 711, 1211, 690); // total length is 356

	/*life.createLife();*/

	//initializeObjective();
	//initializeCutscenes();


	iSetTimer(0, initLevels); // initializing levels

	timer_AUTOMOTION = iSetTimer(30, autoMotion); // FOR PERFECT JUMP ANMIMATION CHANGE TIMER TO 35 MS
	timer_ENEMYMOTION = iSetTimer(70, enemyAutoMotion);
	timer_HEROMOTION = iSetTimer(60, heroAutoMotion);

	playSound(MENU);
	
	iStart();
	return 0;
}