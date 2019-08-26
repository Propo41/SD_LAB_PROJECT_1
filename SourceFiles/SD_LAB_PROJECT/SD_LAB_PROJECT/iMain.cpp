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
#include "fstream"

using namespace std;

/* TIMER FUNCTIONS used are: autoMotion, enemyAutoMotion, heroAutoMotion, initLevels:

1) autoMotion:
a. the loading window : ingame variables are initialized from here
b. auto moves the background after crossing bridgeSegment
c. rotate the bridge down; make it fall over
d. jump animation : used here due to time smoothness, or else would've used in heroAutoMotion
e. for level 2: when hero falls from gap trigger, checks for slope trigger
2. enemyAutoMotion:
a. moves creeps, checks creep getting damage
b. boss moving, boss attacking, boss getting hurt
3. heroAutoMotion:
a. fall animate animation, when hero falls
b. move the player over bridge after building it
c. hero attack animation, hero power, hero fissure
d. when hero attacks, the creeps' HUD appears

4. initLevels:
a. initializes all level 1 variables
b. initializes all level 2 variables

*/

// HERO: RIGHT MEANS, HERO LOOKING RIGHT
// BOSS: RIGHT MEANS, COMING FROM RIGHT SIDE
//CREEPS: RIGHT MEANS, CREEPS COMING FROM RIGHT SIDE



//********************SHORCUTS*******************************

//cntrl + K + C : COMMENTS A BLOCKS****
//cntrl + K + U : UNCOMMENTS A BLOCKS****
// To autoformat a document: Ctrl+K, Ctrl+D******
//Commands to collapse all sections of code: 
//CTRL + M + O will collapse all.
//CTRL + M + L will expand all. (in VS 2013 - Toggle All outlining)
//CTRL + M + P will expand all and disable outlining.
//CTRL + M + M will collapse / expand the current section.********

//*******************************************************************

/*
The function is called to reset variables, ie: scoreArray or name array and etc
Called when user loses game or when quit to main menu is pressed or when return to main menu from victory window is pressed
the ingame variables are not resetted here. They are resetted in the timer function called: initLevels();
*/

// call this when gameover or when game finishes
void saveScore()
{

	FILE *savingScore = fopen("score.txt", "a");

	fprintf(savingScore, "\n%s %d", UserNameInput, score);

	fclose(savingScore);


}


// when highscore menu is shown, call this function
void loadScore()
{

	char prevName[100];
	char ch;
	int prevScore;

	FILE *loadingScore = fopen("score.txt", "r");

	int i = 0;


	// reading from file and storing the entries in the arrays: nameSorted and scoreSorted.
	while (!feof(loadingScore))
	{
		fscanf(loadingScore, "%s %d", prevName, &prevScore);

		strcpy(nameSorted[i], prevName);
		scoreSorted[i] = prevScore;

		i++;

	}


	totalEntries = i;

	// sorting the arrays in descending order
	for (int i = 0; i < totalEntries; i++)
	{
		for (int j = i; j < totalEntries; j++)
		{
			if (scoreSorted[i] < scoreSorted[j])
			{
				// swapping scores
				swap(scoreSorted[i], scoreSorted[j]);

				//swapping names
				char temp[100];
				strcpy(temp, nameSorted[i]);
				strcpy(nameSorted[i], nameSorted[j]);
				strcpy(nameSorted[j], temp);


			}

		}
	}


	// finally, printing it out on the screen
	for (int i = 0; i < totalEntries; i++)
	{
		cout << nameSorted[i] << " " << scoreSorted[i] << endl;
	}

	fclose(loadingScore);
}



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

	princessCutscene = false;
	princess.x = -100;
	princess.y = -100;

}

/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{

}


void iPassiveMouseMove(int mx, int my)
{

	PassiveMouseX = mx;
	PassiveMouseY = my;

//	cout << mx << " " << my << endl;

	//int rgb[4];

	// iGetPixelColor(mx, my, rgb); 
	//cout << "MOUSE: ";
	//cout << "color: ";
	//cout << rgb[0] << " " << rgb[1] << " " << rgb[2] << endl;
}

/*
Contains the implementation of menu mechanism according to mouse cursor

*/
void iMouse(int button, int state, int mx, int my)
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		menuLogic(mx, my); // contains the implementation on w
	}



	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//SettingNewHighScore();
	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	
	if ((int)key == 27 && MenuController == PLAY)
	{
		MenuController = PAUSEMENU; //escape menu while playing game
		PreviousMenu = PAUSEMENU;

		iPauseTimer(timer_ENEMYMOTION);
		iPauseTimer(timer_AUTOMOTION);
		iPauseTimer(timer_HEROMOTION);

		gameStart = false;


	}

	/*if (key == 'p')
	{
		//cout << "menucontroller set to : " << MenuController << endl;
	}
	*/

	/*if (key == 'm')  // FOR DEBUGGING PURPOSES
	{
		gameWon_1 = false;
		gameStart = true;
		gameOver = false;

		playSound(STOP);
		playSound(LEVEL_2);

		MenuController = PLAY;
		PreviousMenu = PLAY;

		initLevel_2 = true; // initLevels() is called and resetgame() is called implicitly.

		initializeObjective();
		initializeHero(HERO_1); 
		//initializeHero(HERO_1);

		hero.y = 180;

	}


	if (key == ']') // FOR DEBUGGING PURPOSES
	{
		MenuController = LOADING_2;
		gameStart = false;
		gameOver = false;
		gameWon_2 = false;
		gameWon_1 = false;
		gameWon_2 = false;

	}

	*/
	//**********************************MENU RELATED STUFF***********************************


	// the first screen that shows up. User needs to press space to continue
	if (MenuController == FALLEN_KINGDOM && key == ' ')
	{
		MenuController = SELECTIONSCREEN;
		PreviousMenu = SELECTIONSCREEN;

	}

	// when enter name window appears
	if (MenuController == ENTERNAME)
	{

		if ((key >= 'a' && key <= 'z') || (key >= 'A' && key <= 'Z'))
		{
			if (UserNameInputIndex >= 17)
			{
			}
			else{

				UserNameInput[UserNameInputIndex++] = key;
				nameShort = false;
			}


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
			// if user inputs name with size less than 4 then prompt user to enter name again
			if (UserNameInputIndex < 4)
			{

				memset(UserNameInput, 0, sizeof(UserNameInput)); // resets the array
				UserNameInputIndex = 0; // resetting index to start from the beginning
				nameShort = true;

			}
			else
			{
				// if entered name fulfills the conditions, then continue to narrative part of level 1
				MenuController = NARRATIVE_1;
				narrativeCounter = 1;
				UserNameInputIndex = 0; // resetting
			}


		}
	}

	// the first set of stories that appear, and are progressed by pressing space
	if (key == ' ' && MenuController == NARRATIVE_1)
	{
		narrativeCounter++;

		if (narrativeCounter == 5)
		{

			MenuController = HEROSELECTION;
			narrativeCounter = 1;


		}
	}


	//*****************BRIDGE SEGMENT**********************************************

	if (bridgeSegment && !fallAnimate)
	{

		if (key == ' ' && gameStart)
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

	//****************************IN GAME CUTSCENES*******************************************


	if (princessCutscene)
	{
		if (key == ' ')
		{
			cutsceneIndex++;
			if (cutsceneIndex >= 19)
			{
				MenuController = LOADING_2;
				gameStart = false;
				gameOver = false;
				gameWon_2 = false;
				gameWon_1 = false;
				gameWon_2 = false;
				playSound(STOP);
				playSound(GAMEOVER);

			}
		}
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

	//*****************************HERO RELATED STUFF****************************************************

	// level 2 stuff here. Used conditions since some features are only exclusively available in level 2
	if (level_2)
	{

		// hero can jump only in level 2
		if (key == ' ' && !cutscene && !bossCutscene && !princessCutscene)
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

		// hero can use powers only in level 2
		if ((key == 'D' || key == 'd') && !hero.channelPower && mana.count > 0 && !hero.jump && !bridgeSegment)      // hero power
		{
			cout << "hero power initiated" << endl;
			
				hero.power = true;
				mana.variable1 -= 40;
				mana.variable2 -= 40;

				// count is 5. If mana count becomes <0 then hero cannot use any more power
				mana.count--;

				if (mana.variable1 < 162 || mana.variable2 <177)
				{
					mana.variable1 = 162;
					mana.variable2 = 177;

				}
			
		
			


		}

	}


	// if hero is not already attacking and when the cutscene is showing, the hero cannot attack
	//cout << "inside: " << hero.attack << " " << hero.attack2 << " " << cutscene << " " << hero.power << endl;

	if (!hero.attack && !hero.attack2 && !cutscene && !hero.jump && !bridgeSegment)
	{

		if (key == 'a' || key == 'A')
		{

			if (hero_1)
			{
				hero.attack = true; // light attack
			}
			else
			{

				if (!hero.projectile)
				{
					hero.attack = true;
					hero.projectile = true;

					if (hero.direction == RIGHT)
					{
						hero.attackIndex = 11;
						hero.projectileX = hero.x + 60;
						hero.projectileTarget = RIGHT;

					}
					else if (hero.direction == LEFT)
					{
						hero.attackIndex = 0;
						hero.projectileX = hero.x;
						hero.projectileTarget = LEFT;

					}

					hero.projectileY = hero.y + 80;

				}

			}
		}


		else if ((key == 's' || key == 'S'))
		{

			if (hero_1)
			{
				hero.attack2 = true; // heavy attack

			}
			else
			{
				// there are no animation sprites for heavy attack of hero 2. Sadly, we couldnt implement it
				// but soon...
			}
		}


	}


	/******************************************************************************************/





}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{
	// the hero cannot move if it's attacking or it's falling down or the cutscenes are playing
	if (!hero.attack && !bridgeSegment && !hero.attack2 && !cutscene && !bossCutscene && !fallAnimate && !hero.channelPower && !hero.power)
	{

		if (key == GLUT_KEY_RIGHT)
		{
			if (hero_1)
				hero.powerIndex = 0;
			environmentTriggers();
			heroMovement(RIGHT);

		
			// for level 2, the creep triggers are different. Hence, a different function is used
			if (level_2)
			{
				environmentTriggers2(CREEPS);

			}


		}

		if (key == GLUT_KEY_LEFT)
		{
			if (hero_1)
				hero.powerIndex = 8;

			if (level_1)
			{
				// used a constrain in level 1. This is triggered when bridge segment is over. The player cannot return to the bridge segment after crossing the gaps succcessfully
				if (screen.x != backgroundConstrain_1)
				{
					heroMovement(LEFT);
					environmentTriggers();
				}
			}

			else
			{

				// for level 2, the creep triggers are different. Hence, a different function is used
				// also used a constrain, so that hero cannot move further to the left, or else black screen appears

				if (screen.x < backgroundConstrain_2) // level 2: initially the player cannot go any further to the left.
				{
					heroMovement(LEFT);
					//environmentTriggers();
					environmentTriggers2(CREEPS);

				}

			}




		}

	}

	// goes to escape menu when playing game
	/*if (key == GLUT_KEY_HOME && MenuController == PLAY)
	{
		MenuController = PAUSEMENU; //escape menu while playing game
		PreviousMenu = PAUSEMENU;

		iPauseTimer(timer_ENEMYMOTION);
		iPauseTimer(timer_AUTOMOTION);
		iPauseTimer(timer_HEROMOTION);

		gameStart = false;


	}
	*/

	if (key == GLUT_KEY_END && MenuController != PAUSEMENU && MenuController != GAMEOVER) // when inside pausemenu, then pressing END wont go back to prev page
	{

	//	MenuController = PreviousMenu;

	}



}

void autoMotion()
{

	// the first loading page, the ingame variables are initialized from here, ie ingame sound starts, and level 1 variables are set
	if (MenuController == LOADING_1)
	{

		cout << "loading 1:: automotion" << endl;

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
			playSound(LEVEL_1);

			cout << "loading 1:: complete" << endl;


		}
	}





	//moves the background to adjust 
	if (fixBackground && backgroundEnd == false)
		fix_Background(hero.direction);

	//rotates the bridge
	if (rotateBridge)
		theta -= 5;



	if (level_2)
	{

		// checks where the slope is located
		if (!heroStanding && !fallAnimate && !hero.attack && !hero.attack2)
			environmentTriggers2(SLOPE);

		// checks where gaps are situated
		environmentTriggers2(FALL);


		if (hero.jump)
		{

			heroJump();

		}
	}



}

void heroAutoMotion()
{

	if (fallAnimate && level_2)
	{

		//cout << "inside motion" << endl;

		hero.y -= 10;
		if (hero.y <= -10)
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
			if (hero.y <= -10)
			{

				resetHero();

			}

		}
	}

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

		if (hero.power && hero_2)    // hero POWER
		{
			heroAttack(POWER);
			creepsHP = true;

		}
		if (hero.channelPower)
		{
			heroAttack(FISSURE);
			creepsHP = true;

		}

		// if and only if hero attack/power is on, then iterate over all creeps and show their HUD, if they are alive
		if (creepsHP)
		{
			for (int i = 0; i < creepsCount; i++)
			{
				if (!creeps[i].death)
					creeps[i].showHP = true;

			}

		}

		// if hero is not attacking, then dont show the Creeps' hud
		else
		{
			creepsHP = false;

			for (int i = 0; i < creepsCount; i++)
			{
				creeps[i].showHP = false;
			}
		}
	}

	if (hero.projectile)
	{
		heroAttack(LIGHT_ATTACK);
		ProjectileDistance += 20;

		if (hero.projectileTarget == RIGHT)
		{
			//cout << "PROJECTILE_X :" << hero.projectileX << endl;
			hero.projectileX += 20;
		}
		else
		{
			//cout << "PROJECTILE_X :" << hero.projectileX << endl;
			hero.projectileX -= 20;
		}

		if (ProjectileDistance >= 400)
		{
			hero.projectile = false;
			ProjectileDistance = 0;
			hero.projectileX = hero.x;
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

	// traverses the index of princess for animation
	if (princessSegment)
	{
		princess.index++;
		if (princess.index >= 11)
		{
			princess.index = 1;

		}
	}



	//for hero 2, should've used in the timer fucntion names: heroAutoMotion. But since this function has a better timer interval, this was used.
	if (hero.projectile)
	{
		creepDamage(DAMAGE, LIGHT_ATTACK); // creep got hurt if creep is within range of attack animation
		bossDamage(DAMAGE, LIGHT_ATTACK);
	}

	if (bossSegment)
	{
		if (moveBoss && level_1)
		{
			bossMovement();

			//boss walks till reached a specific coordinate after which cutscenes are shown
			if (L1Boss.x <= 1100 && !temp_4)
			{

				bossCutscene = true;
				//if (level_1)
				initializeCutscenes();
				//else
				//initializeCutscenes2();


				moveBoss = false;
				temp_4 = true;
				iPauseTimer(timer_ENEMYMOTION);


			}


		}




		// if level 2, then dont execute the below lines of code, since all functions of boss2 are different and in different timer functions
		//if (level_2)
		//return;


		if (level_1)
		{


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
				bossDamage(DYING, NULL);
			}


			if (L1_BossHurt.show)
			{
				L1BossHurtLogic();
			}


		}

		else if (level_2)
		{


			//l2boss.attack : when hero is within attack range of boss, then this is turned true, else false
			//l2boss.power: indicates the entire projectile motion, both forward and reverse. It's set to false when the entire projectile motion is over
			//l2boss.channelPpower: indicates only the forward projectile motion. when hits the limit, its set to false

			if (L2Boss.show)
			{
				bossMovement();

			}

			// boss attack animation only happening when power is false., ie the whole projectile motion is over
			if (L2Boss.attack && !L2Boss.power)
			{

				bossAttackLogic(ATTACK);

			}

			if (L2Boss.power && !L2Boss.chase)
			{

				bossAttackLogic(POWER);

			}

			if (L2Boss.death)
			{
				bossDamage(DYING, NULL);
			}

			if (L1_BossHurt.show)
			{
				L1BossHurtLogic();
			}





			//if (L1Boss.power  && L1Boss.channelPower)
			//{

			//	bossAttackLogic(POWER);

			//}
			//if (L1Boss.attack)
			//{

			//	bossAttackLogic(ATTACK);

			//}
			//if (L1Boss.death)
			//{
			//	bossDamage(DYING, NULL);
			//}


			//if (L1_BossHurt.show)
			//{
			//	L1BossHurtLogic();
			//}


		}




	}

}


// called once from main, since the images here are fixed, and do not change
void loadImages()
{
	//loadImagesMenu();

	//loadImagesEffects();
	//loadImagesUI();
	//loadImagesPrincess();



	// JUST FOR THE VIDEO IM PUTTING IT HERE TO REDUCE TIME FOR LOADING
	//loadImagesBoss();
	//loadImagesCreep();
	//loadImagesBackground();




}


void iDraw()
{
	iClear();
	
	// initially when game is not started yet. Shows all menu related stuff
	if (!gameStart)
	{
		renderMenu(PassiveMouseX, PassiveMouseY);
	}


	// after level 1 victory, the window that appears.
	if (gameWon_1)
	{
		showBackground();
		showHero();
		renderMenu(PassiveMouseX, PassiveMouseY);

	}
	if (gameWon_2)
	{

		//iShowImage(0, 0, 1366, 768, menu[33].id);

	}


	//if game is lost, then render a new window
	if (gameOver)
	{
		renderMenu(PassiveMouseX, PassiveMouseY);

	}



	// when game is started. NOTE: gameStart is made true in autoMotion() when the loading is completed
	if (gameStart)
	{

		showBackground();

		// 0 MEANS NULL, NO ACTUAL INDEX. Used to make the function polymorphic. Since, the function has to be called for the creeps as well. And for that, an index must be sent
		renderHUD(LIFE, NULL);  //  the red bars for hero
		renderHUD(HERO, NULL); // the green bar as well as mana (in level 2) and the image
		renderHUD(L1BOSSHPBAR, NULL); // boss hp bar: contains both red bar and the image


		renderUI(OBJECTIVE); // shows the objectives, ie : build bridge to cross gaps....
		renderUI(WAVE); // wave-1, wave-2 etc, also shows the number of creeps alive
		renderUI(SCORE); // shows the score

		//build and drops the bridge
		bridge();

		// cutscenes in the environment
		if (cutscene)
		{
			renderNarrative(LEVEL_1, cutsceneIndex);
		}
		//cutscene for boss, level 1 and 2 both
		if (bossCutscene)
		{
			renderNarrative(LEVEL_1, cutsceneIndex);

		}

		// CUTSCENES WHEN PRINCESS COMES
		if (princessCutscene)
		{

			renderNarrative(LEVEL_2, cutsceneIndex);

		}

		// showing boss
		if (bossSegment)
		{

			showBoss();

		}
		if (princessSegment)
		{
			iShowImage(princess.x, princess.y, 75, 140, princess.id[princess.index]);

		}

		if (hero_2)
		{

			if (hero.projectile)
				ProjectileAnimation();
		}

		/*
		///REFERENCE LINES HERO
		iSetColor(RED);
		iLine(hero.x, tileHeight - 10, hero.x, tileHeight + 500);
		iSetColor(RED);
		iLine(hero.x + 200, tileHeight - 10, hero.x + 200, tileHeight + 500);


		iSetColor(GREEN); // LEFT SIDE OF HERO
		iLine(hero.x + 55, tileHeight - 10, hero.x + 55, tileHeight + 500);
		iSetColor(BLUE); // RIGHT SIDE OF HERO
		iLine(hero.x + 130, tileHeight - 10, hero.x + 130, tileHeight + 500);

		////REFERENCE LINES BOSS
		if (bossSegment)
		{
			iSetColor(RED);
			iLine(L2Boss.x + 50 , tileHeight - 10, L2Boss.x + 50, tileHeight + 500);

			iSetColor(GREEN);
			iLine(L2Boss.x + 350, tileHeight - 10, L2Boss.x + 350, tileHeight + 500);
		}


		//iLine(hero.x + 100+20, 230,  hero.x + 500, 230);
		*/



		// when hero is damaged, an animation is shown 
		renderEffects(HERO_HURT_EFFECT, NULL);


		renderHero();

		if (creepsSegment)
		{
			showCreeps();
		}

	}


/*
///REFERENCE LINES HERO
iSetColor(RED);
iLine(hero.x, tileHeight - 10, hero.x, tileHeight + 500);
iSetColor(RED);
iLine(hero.x + 200, tileHeight - 10, hero.x + 200, tileHeight + 500);


iSetColor(GREEN); // LEFT SIDE OF HERO
iLine(hero.x + 55, tileHeight - 10, hero.x + 55, tileHeight + 500);
iSetColor(BLUE); // RIGHT SIDE OF HERO
iLine(hero.x + 130, tileHeight - 10, hero.x + 130, tileHeight + 500);

////REFERENCE LINES BOSS
if (bossSegment)
{
iSetColor(RED);
iLine(L2Boss.x + 50, tileHeight - 10, L2Boss.x + 50, tileHeight + 500);

iSetColor(GREEN);
iLine(L2Boss.x + 200, tileHeight - 10, L2Boss.x + 200, tileHeight + 500);
}


//iLine(hero.x + 100+20, 230,  hero.x + 500, 230);

//cout <<"L2 BOSS Y: " <<  L2Boss.y << endl;
	
	*/





}


/*
used to initialize ingame variables and load images.
Called from the start of the game, and when hero transitions from level 1 to level 2
*/
void initLevels()
{

	if (initLevel_1)
	{

		cout << "reset level 1" << endl;

		level_1 = true;
		level_2 = false;

		// the delay that occurs after loading window-1 is due to the below codes.
		
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
		hero.attack = false;

		hero.life = 3;
		hero.HP = 10;
		hero.showHP = false;
		hero.death = false;
		hero.attack2 = false;

		hero.index = 1;
		hero.attack2Index = 0;
		hero.attackIndex = 1; //starting the index from 0 causes bugs. a black screen renders

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
		creepsAlive = 0;

		wait = 0; // USED FOR THE LEVEL 1 BOSS FISSURE WAITING
		fissureLength = 400;
		moveBoss = false;
		bossSegment = false;

		//***************************************************
		//********************OTHER VARIABLES*******************************
		movePlayer = false;
		fallAnimate = false;

		cutscene = false;
		bossCutscene = false;
		cutsceneIndex = 0;
		objectiveIndex = 0;
		narrativeCounter = 0;

		gapPassed = false;
		backgroundEnd = false;
		fixBackground = false;
		backgroundCounter = 0;
		stage = 0;

		bloodEffect = false;


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
		loadLevel2Cutscenes();
		loadImagesPrincess();

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


		//*****************************HER0***************************************
		hero.x = 550;
		hero.y = 180;
		hero.show = true;
		hero.direction = RIGHT;
		hero.index = 0;
		hero.attack = false;
		hero.attackIndex = 0;
		hero.life = 3;
		hero.HP = 15;
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


		//*****************************ENEMY***************************************
		creepsSegment = false;
		waveIndex = -1;
		waveClear = false;
		creepAttackIndex = 0;
		creepsAlive = 0;


		moveBoss = false;
		bossSegment = false;

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
		objectiveIndex =3;

		gapPassed = false;
		backgroundEnd = false;
		fixBackground = false;
		backgroundCounter = 0;
		stage = 0;

		bloodEffect = false;

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


void loading()
{
	static int m = 0;

	if (MenuController == LOADING_2)
	{
		victoryIndex++;
		if (victoryIndex >= 32)
		{
			victoryIndex = 32;

			m++;
			if (m > 5)
			{
				MenuController = VICTORY_2;
				m = 0;
				princessCutscene = false;
			}


		}
	}

}

void heroAutoMotion_2()
{
	if (hero_1 && hero.power)
	{
		heroAttack(POWER);
		creepsHP = true;

	}

}



int main()
{
	iInitialize(canvasWidth, canvasHeight, "The Fallen Kingdom");

	loadImagesMenu();
	//loadImages();

	iSetTimer(0, initLevels); // initializing levels
	iSetTimer(700, loading);


	timer_AUTOMOTION = iSetTimer(30, autoMotion); // FOR PERFECT JUMP ANMIMATION CHANGE TIMER TO 35 MS
	timer_ENEMYMOTION = iSetTimer(70, enemyAutoMotion);
	timer_HEROMOTION = iSetTimer(60, heroAutoMotion);
	timer_HEROMOTION_2 = iSetTimer(100, heroAutoMotion_2);

	
	playSound(MENU);

	iStart();


	return 0;
}