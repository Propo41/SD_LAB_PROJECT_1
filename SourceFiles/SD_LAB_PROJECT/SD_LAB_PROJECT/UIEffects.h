#ifndef UIEFFECTS_H
#define UIEFFECTS_H

#include "declarations.h"


typedef struct UserInterface  // put HUD members to Character.h. for better handling 
{
	int x, y, r , g , b;
	bool show;
	int id;
	char arrayChar[50];

	double polygon_x[10];
	double polygon_y[10];

	int variable1;
	int variable2;
	int count;


	int width, height;

	UserInterface()
	{
		show = true;
		x = 0;
		y = 0;
		width = 1366;
		height = 768;

	}

	UserInterface(int _x, int _y, int _r, int _g, int _b, int _count)
	{
		x = _x;
		y = _y;
		r = _r;
		g = _g;
		b = _b;
		count = _count;
		show = true;


	}

	void createHPbar(int _x, int _y, int variable1_X, int variable2_X, int A_x, int A_y, int B_x, int B_y, int C_x, int C_y, int D_x, int D_y) //reduce code by using only one function that takes different parameters
	{
		x = _x;
		y = _y;
		variable1 = variable1_X;
		variable2 = variable2_X;

		polygon_x[0] = A_x; //A
		polygon_x[1] = B_x; //B
		polygon_x[2] = C_x;// variable1; C
		polygon_x[3] = D_x;// variable2; D


		polygon_y[0] = A_y; //A
		polygon_y[1] = B_y; //B
		polygon_y[2] = C_y; //C
		polygon_y[3] = D_y; //D


	}

	void createLife(int A_x, int A_y, int B_x, int B_y, int C_x, int C_y, int D_x, int D_y) //reduce code by using only one function that takes different parameters
	{

		variable1 = C_x;
		variable2 = D_x;

		polygon_x[0] = A_x; //A
		polygon_x[1] = B_x; //B
		polygon_x[2] = variable1;// variable1; C
		polygon_x[3] = variable2;// variable2; D


		polygon_y[0] = A_y; //A
		polygon_y[1] = B_y; //B
		polygon_y[2] = C_y; //C
		polygon_y[3] = D_y; //D

	}

	void setDimensions(int _x, int _y, int _width, int _height)
	{
		x = _x;
		y = _y;
		width = _width;
		height = _height;
	}


}UserInterface;

UserInterface H1_HPbar, life, L1_BossHPbar, mana;

UserInterface cutscenes[100], objective[100], wave[100];

UserInterface stage_mark(1196, 715, 0,0,0, 1);

UserInterface menu[100];

UserInterface narrative[100];

UserInterface controls[2]; // hud controls

//UserInterface direction[2]; // used for indicating where the creeps are

typedef struct Effects
{
	int x, y;
	bool show;
	int index;
	int id[50];

	Effects()
	{
		index = 0;
		x = 0;
		y = 0;
		show = false;
	}
	Effects(int _x, int _y, bool _show, int _index)
	{
		x = _x;
		y = _y;
		show = _show;
		index = _index;
	}
	void resetValues()
	{
		index = 0;
		x = 0;
		y = 0;
		show = false;
	}

}Effects;

Effects heroHurt[100], creepHurt[100], L1_BossHurt;



/*loads the UI for level 1 images
hud,objective,menu,narrative
*/
void loadImagesUI()
{

	//********************************HUD**********************************
	if (hero_1)
		H1_HPbar.id = iLoadImage("images\\UI\\hpbar.png");
	else
		H1_HPbar.id = iLoadImage("images\\UI\\h2hpbar_level1.png");

	L1_BossHPbar.id = iLoadImage("images\\UI\\L1bosshpbar.png");

	controls[0].id = iLoadImage("images\\UI\\HUD_CONTROLS.png");



	//*********************************************************************

	//*********************************objective*****************************
	objective[0].id = iLoadImage("images\\UI\\objective\\obj_1.png"); // build bridge
	objective[1].id = iLoadImage("images\\UI\\objective\\obj_2.png"); // kill all enemies
	objective[2].id = iLoadImage("images\\UI\\objective\\obj_3.png"); // kill cerberus

	objective[3].id = iLoadImage("images\\UI\\objective\\level2_1.png"); // special power
	objective[4].id = iLoadImage("images\\UI\\objective\\level2_2.png"); // jump




	wave[0].id = iLoadImage("images\\UI\\objective\\WAVE_1.png"); //wave 1
	wave[1].id = iLoadImage("images\\UI\\objective\\WAVE_2.png");
	wave[2].id = iLoadImage("images\\UI\\objective\\WAVE_3.png");

	//***********************************************************************

	//********************************MENU**********************************

	menu[0].id = iLoadImage("images\\UI\\menu\\menu_1.png");   //fallen kingdom
	menu[1].id = iLoadImage("images\\UI\\menu\\menu1_font.png");	//choosing menu font
	menu[2].id = iLoadImage("images\\UI\\menu\\Choosing Menu1.png");	// Choosing menu
	menu[3].id = iLoadImage("images\\UI\\menu\\Choosing MenuStart.png");	//menu start
	menu[4].id = iLoadImage("images\\UI\\menu\\Choosing MenuOptions.png");	//menu options
	menu[5].id = iLoadImage("images\\UI\\menu\\Choosing MenuCredits.png");	// menu credits
	menu[6].id = iLoadImage("images\\UI\\menu\\Choosing MenuHighScore.png");	// menu highscore
	menu[7].id = iLoadImage("images\\UI\\menu\\Choosing MenuExit.png");	// main menu exit
	menu[8].id = iLoadImage("images\\UI\\menu\\HighScore.png"); // High Score

	menu[9].id = iLoadImage("images\\UI\\menu\\Options1.png"); // Options

	menu[10].id = iLoadImage("images\\UI\\menu\\Credits.png"); // Credits
	menu[11].id = iLoadImage("images\\UI\\menu\\Pause.png"); // Credits
	menu[12].id = iLoadImage("images\\UI\\menu\\PauseResume.png"); // Pause - Resume
	menu[13].id = iLoadImage("images\\UI\\menu\\PauseOptions.png"); // Pause - Options
	menu[14].id = iLoadImage("images\\UI\\menu\\PauseExit.png"); // Pause - Exit
	menu[15].id = iLoadImage("images\\UI\\menu\\gameover.png");
	menu[16].id = iLoadImage("images\\UI\\menu\\gameover1.png");
	menu[17].id = iLoadImage("images\\UI\\menu\\gameover2.png");
	menu[18].id = iLoadImage("images\\UI\\menu\\gameover3.png");

	menu[19].id = iLoadImage("images\\UI\\menu\\Options2.png"); // Options : TURNING SOUND OFF



	menu[20].id = iLoadImage("images\\UI\\menu\\VICTORY.png"); // default
	menu[21].id = iLoadImage("images\\UI\\menu\\VICTORY_PROCEED.png"); // when mouse is over proceed
	menu[22].id = iLoadImage("images\\UI\\menu\\VICTORY_MAIN.png");// when mouse is over mainmenu
	
	//menu[23].id = iLoadImage("images\\UI\\menu\\star 3.png");

	menu[24].id = iLoadImage("images\\UI\\menu\\entername.png"); // ENTER name image here

	menu[25].id = iLoadImage("images\\UI\\HERO_SELCTION.png");  // hero selection default screen
	menu[26].id = iLoadImage("images\\UI\\HERO_SELCTION_1.png"); // hero 1
	menu[27].id = iLoadImage("images\\UI\\HERO_SELCTION_2.png"); // hero 2



	menu[28].id = iLoadImage("images\\UI\\loading_1.png"); // loading image 1


	//loading image 2 : to be continued
	menu[29].id = iLoadImage("images\\UI\\menu\\1.png");
	menu[30].id = iLoadImage("images\\UI\\menu\\2.png");
	menu[31].id = iLoadImage("images\\UI\\menu\\3.png");
	menu[32].id = iLoadImage("images\\UI\\menu\\4.png");

	// victory 2
	menu[33].id = iLoadImage("images\\UI\\menu\\victory_2.png"); // less bright
	menu[34].id = iLoadImage("images\\UI\\menu\\victory_2a.png"); // bright
	


	menu[35].id = iLoadImage("images\\UI\\menu\\back.png"); // default
	menu[36].id = iLoadImage("images\\UI\\menu\\back_a.png"); // when mouse hovers over



	//*******************************NARRATIVE****************************************
	cutscenes[0].id = iLoadImage("images\\UI\\narrative\\a.png");
	cutscenes[1].id = iLoadImage("images\\UI\\narrative\\a_1.png");
	cutscenes[2].id = iLoadImage("images\\UI\\narrative\\b_1.png");
	cutscenes[3].id = iLoadImage("images\\UI\\narrative\\b_2.png");
	cutscenes[4].id = iLoadImage("images\\UI\\narrative\\b_3.png");
	cutscenes[5].id = iLoadImage("images\\UI\\narrative\\b_4.png");
	cutscenes[6].id = iLoadImage("images\\UI\\narrative\\b_5.png");

	// level 2 boss cutscene
	cutscenes[7].id = iLoadImage("images\\UI\\narrative\\1.png");
	cutscenes[8].id = iLoadImage("images\\UI\\narrative\\2.png");
	cutscenes[9].id = iLoadImage("images\\UI\\narrative\\3.png");
	cutscenes[10].id = iLoadImage("images\\UI\\narrative\\4.png");
	cutscenes[11].id = iLoadImage("images\\UI\\narrative\\5.png");
	cutscenes[12].id = iLoadImage("images\\UI\\narrative\\6.png");

	// level 2 princess cutscene: 13-19
	cutscenes[13].id = iLoadImage("images\\UI\\narrative\\endgame\\1.png");
	cutscenes[14].id = iLoadImage("images\\UI\\narrative\\endgame\\2.png");
	cutscenes[15].id = iLoadImage("images\\UI\\narrative\\endgame\\3.png");
	cutscenes[16].id = iLoadImage("images\\UI\\narrative\\endgame\\4.png");
	cutscenes[17].id = iLoadImage("images\\UI\\narrative\\endgame\\5.png");
	cutscenes[18].id = iLoadImage("images\\UI\\narrative\\endgame\\6.png");
	cutscenes[19].id = iLoadImage("images\\UI\\narrative\\endgame\\7.png");
	

	narrative[0].id = iLoadImage("images\\story\\Artboard 1.png"); // story at game start
	narrative[1].id = iLoadImage("images\\story\\Artboard 2.png");
	narrative[2].id = iLoadImage("images\\story\\Artboard 3.png");
	narrative[3].id = iLoadImage("images\\story\\Artboard 4.png");


	//********************************************************************************


	//direction[0].id = iLoadImage("images\\UI\\objective\\moveL.png"); // go left direction
	//direction[1].id = iLoadImage("images\\UI\\objective\\moveR.png"); // go right direction









} // LEVEL 1

/*loads the UI for level 2 images*/
void loadImagesUI2() // LEVEL 2
{
	if (hero_1)
		H1_HPbar.id = iLoadImage("images\\UI\\h1hpbar_level2.png");
	else
		H1_HPbar.id = iLoadImage("images\\UI\\h2hpbar.png");

	L1_BossHPbar.id = iLoadImage("images\\UI\\L2bosshpbar.png");

}

/*
sets the x,y and dimensions of the objective images of level 1
*/
void initializeObjective()
{

	//*******************LEVEL 1****************************
	//BUILD BRIDGE
	objective[0].x = 0;
	objective[0].y = 470;
	objective[0].width = 276;
	objective[0].height = 71;

	//KILL ALL ENEMIES
	objective[1].x = 0;
	objective[1].y = 470;
	objective[1].width = 280;
	objective[1].height = 71;


	//KILL CERBERUS
	objective[2].x = 0;
	objective[2].y = 470;
	objective[2].width = 219;
	objective[2].height = 60;


	//WAVE 1
	wave[0].x = 1366-175;
	wave[0].y = 670;
	wave[0].width = 175;
	wave[0].height = 71;

	//WAVE 2
	wave[1].x = 1366-175;
	wave[1].y = 670;
	wave[1].width = 175;
	wave[1].height = 71;

	//WAVE 3
	wave[2].x = 1366 - 175;
	wave[2].y = 670;
	wave[2].width = 175;
	wave[2].height = 71;

	//*******************************************************

} // level 1

/*
sets the x,y and dimensions of the objective images of level 2
*/
void initializeObjective2() // level 2
{
	//PRESS D FOR SPECIAL ATTACK
	objective[3].x = 0;
	objective[3].y = 470;
	objective[3].width = 467;
	objective[3].height = 84;

	//SPACE TO JUMP
	objective[4].x = 0;
	objective[4].y = 470;
	objective[4].width = 278;
	objective[4].height = 67;


	
}

/*
sets the x,y and dimensions of the cutscene images of level 1
*/
void initializeCutscenes()
{


	cutscenes[0].x = hero.x + 200; //a
	cutscenes[0].y = hero.y + 150;
	cutscenes[0].width = 263;
	cutscenes[0].height = 99;

	cutscenes[1].x = hero.x + 200; //a_1
	cutscenes[1].y = hero.y + 150;
	cutscenes[1].width = 263;
	cutscenes[1].height = 99;


	cutscenes[2].x = L1Boss.x-300; //b_1
	cutscenes[2].y = L1Boss.y + 250;
	cutscenes[2].width = 288;
	cutscenes[2].height = 75;


	cutscenes[3].x = hero.x + 150; //b_2
	cutscenes[3].y = hero.y + 100;
	cutscenes[3].width = 288;
	cutscenes[3].height = 75;


	cutscenes[4].x = L1Boss.x-300; //b_3
	cutscenes[4].y = L1Boss.y + 250;
	cutscenes[4].width = 315;
	cutscenes[4].height = 96;


	cutscenes[5].x = hero.x + 150; //b_4
	cutscenes[5].y = hero.y + 100;
	cutscenes[5].width = 288;
	cutscenes[5].height = 75;


	cutscenes[6].x = L1Boss.x-300; //b_5
	cutscenes[6].y = L1Boss.y + 250;
	cutscenes[6].width = 377;
	cutscenes[6].height = 149;



} // level 1


/*
sets the x,y and dimensions of the cutscene images of level 2
*/
void initializeCutscenes2() // level 2 
{
	



	cutscenes[7].x = hero.x + 200; //1
	cutscenes[7].y = hero.y + 150;
	cutscenes[7].width = 300;
	cutscenes[7].height = 92;


	cutscenes[8].x = hero.x + 200; //2
	cutscenes[8].y = hero.y + 150;
	cutscenes[8].width = 391;
	cutscenes[8].height = 134;


	cutscenes[9].x = hero.x + 200; //3
	cutscenes[9].y = hero.y + 150;
	cutscenes[9].width = 406;
	cutscenes[9].height = 146;


	cutscenes[10].x = hero.x + 200; //4
	cutscenes[10].y = hero.y + 150;
	cutscenes[10].width = 406;
	cutscenes[10].height = 146;


	cutscenes[11].x = hero.x + 200; //5
	cutscenes[11].y = hero.y + 150;
	cutscenes[11].width = 391;
	cutscenes[11].height = 134;


	cutscenes[12].x = hero.x + 200; //6
	cutscenes[12].y = hero.y + 150;
	cutscenes[12].width = 317;
	cutscenes[12].height = 122;



	// princess cutscenes
	//13-19
	cutscenes[13].x = hero.x + 200; // H
	cutscenes[13].y = hero.y + 150;
	cutscenes[13].width = 316;
	cutscenes[13].height = 89;

	cutscenes[14].x = 700; // P
	cutscenes[14].y = princess.y + 100;
	cutscenes[14].width = 395;
	cutscenes[14].height = 163;

	cutscenes[15].x = hero.x + 200; // H
	cutscenes[15].y = hero.y + 150;
	cutscenes[15].width = 316;
	cutscenes[15].height = 89;

	cutscenes[16].x = 700; // P
	cutscenes[16].y = princess.y + 100;
	cutscenes[16].width = 395;
	cutscenes[16].height = 163;

	cutscenes[17].x = 700; //P 
	cutscenes[17].y = princess.y + 100;
	cutscenes[17].width = 395;
	cutscenes[17].height = 163;

	cutscenes[18].x = hero.x + 200; //H
	cutscenes[18].y = hero.y + 150;
	cutscenes[18].width = 316;
	cutscenes[18].height = 89;

	cutscenes[19].x = 700; //P
	cutscenes[19].y = princess.y + 100;
	cutscenes[19].width = 375;
	cutscenes[19].height = 129;


}

/*
loads the animation effects. Common for both level 1 and 2
*/
void loadImagesEffects()
{
	//************************************effects*****************************************

	heroHurt[0].id[0] = iLoadImage("images\\effects\\blood.png");
	for (int i = 0; i < 30; i++)
		heroHurt[i].id[0] = iLoadImage("images\\effects\\blood.png");


	//creep hurt effect 
	for (int i = 0; i < 30; i++)
	{
		
			creepHurt[i].id[0] = iLoadImage("images\\effects\\effect_01.png");
			creepHurt[i].id[1] = iLoadImage("images\\effects\\effect_02.png");
			creepHurt[i].id[2] = iLoadImage("images\\effects\\effect_03.png");
			creepHurt[i].id[3] = iLoadImage("images\\effects\\effect_04.png");
			creepHurt[i].id[4] = iLoadImage("images\\effects\\effect_05.png");
			creepHurt[i].id[5] = iLoadImage("images\\effects\\effect_06.png");
			creepHurt[i].id[6] = iLoadImage("images\\effects\\effect_07.png");
			creepHurt[i].id[7] = iLoadImage("images\\effects\\effect_08.png");
	}
	

	L1_BossHurt.id[0] = iLoadImage("images\\effects\\bossdamage_01.png");
	L1_BossHurt.id[1] = iLoadImage("images\\effects\\bossdamage_02.png");
	L1_BossHurt.id[2] = iLoadImage("images\\effects\\bossdamage_03.png");
	L1_BossHurt.id[3] = iLoadImage("images\\effects\\bossdamage_04.png");
	L1_BossHurt.id[4] = iLoadImage("images\\effects\\bossdamage_05.png");



	//******************************************************************************************
}

/*
:: called from iDraw, showBoss(), showCreeps()
it renders the animation effects for hero getting hurt, creeps/boss getting hurt
*/
void renderEffects(int mode, int i)
{

	if (mode == HERO_HURT_EFFECT)
	{
		for (int i = 0; i < creepsCount; i++) //shows effects for getting hurt
		{
			if (heroHurt[i].show && creeps[i].show)
			{
				iShowImage(0, 0, canvasWidth, canvasHeight, heroHurt[i].id[0]);
				//heroHurt[i].show = false;
			}
			

		}

	}
	if (mode == CREEPS)
	{
		if (creeps[i].direction==RIGHT)
			iShowImage(creeps[i].x+10, creeps[i].y, 50, 50, creepHurt[i].id[creepHurt[i].index]);
		else
			iShowImage(creeps[i].x+50, creeps[i].y, 50, 50, creepHurt[i].id[creepHurt[i].index]);

	}
	if (mode == BOSS)
	{
		if (level_1)
			iShowImage(L1Boss.x + 100, L1Boss.y, 100, 100, L1_BossHurt.id[L1_BossHurt.index]);
		else
			iShowImage(L2Boss.x + 100, L2Boss.y, 100, 100, L1_BossHurt.id[L1_BossHurt.index]);

		
		//	iShowImage(L1Boss.x + 50, L1Boss.y, 100, 100, L1_BossHurt.id[L1_BossHurt.index]);
	}

}

/*
:: called from iDraw(), showCreeps()
it renders the HUD (ie HP bars) of creeps/heroes/bosses for both level 1 and 2
*/
void renderHUD(int mode, int i)
{
	if (mode == CREEPS) // creeps HUD
	{


		if (level_1) // for level 1
		{
			iSetColor(206, 2, 56);
			iFilledRectangle(creeps[i].x + 10, creeps[i].y + 80, creeps[i].varHP, 10);

			iSetColor(0, 0, 0);
			iRectangle(creeps[i].x + 10, creeps[i].y + 80, 60, 10);

		}
		else // for level 2
		{
			iSetColor(206, 2, 56);
			iFilledRectangle(creeps[i].x + 15, creeps[i].y + 110, creeps[i].varHP, 10);

			iSetColor(0, 0, 0);
			iRectangle(creeps[i].x + 15, creeps[i].y + 110, 60, 10);

		}



	
	}
	
	 if (mode == HERO) // HERO HP BAR (GREEN)
	 {
		

		if (hero_1)
		{
			if (level_1)
			{
				H1_HPbar.polygon_x[2] = H1_HPbar.variable1;// variable1; C
				H1_HPbar.polygon_x[3] = H1_HPbar.variable2;// variable2; D

				iSetColor(0, 255, 54); //green

				iFilledPolygon(H1_HPbar.polygon_x, H1_HPbar.polygon_y, 4);

				iShowImage(H1_HPbar.x, H1_HPbar.y, 304, 88, H1_HPbar.id);

			}
			else
			{
				H1_HPbar.polygon_x[2] = H1_HPbar.variable1;// variable1; C
				H1_HPbar.polygon_x[3] = H1_HPbar.variable2;// variable2; D

				iSetColor(0, 255, 54); //green: health bar
				iFilledPolygon(H1_HPbar.polygon_x, H1_HPbar.polygon_y, 4);


				mana.polygon_x[2] = mana.variable1;// variable1; C
				mana.polygon_x[3] = mana.variable2;// variable2; D

				iSetColor(73, 206, 255); //blue: mana
				iFilledPolygon(mana.polygon_x, mana.polygon_y, 4);

				iShowImage(H1_HPbar.x, H1_HPbar.y, 344, 108, H1_HPbar.id);


			}


		}
		else // hero 2
		{
			if (level_1)
			{

				H1_HPbar.polygon_x[2] = H1_HPbar.variable1;// variable1; C
				H1_HPbar.polygon_x[3] = H1_HPbar.variable2;// variable2; D

				iSetColor(0, 255, 54); //green

				iFilledPolygon(H1_HPbar.polygon_x, H1_HPbar.polygon_y, 4);

				iShowImage(H1_HPbar.x, H1_HPbar.y, 293, 87, H1_HPbar.id);

			}
			else
			{
				H1_HPbar.polygon_x[2] = H1_HPbar.variable1;// variable1; C
				H1_HPbar.polygon_x[3] = H1_HPbar.variable2;// variable2; D

				iSetColor(0, 255, 54); //green: health bar
				iFilledPolygon(H1_HPbar.polygon_x, H1_HPbar.polygon_y, 4);



				mana.polygon_x[2] = mana.variable1;// variable1; C
				mana.polygon_x[3] = mana.variable2;// variable2; D

				iSetColor(73, 206, 255); //blue: mana
				iFilledPolygon(mana.polygon_x, mana.polygon_y, 4);

				iShowImage(H1_HPbar.x, H1_HPbar.y, 330, 104, H1_HPbar.id);



			}



		}

	 }
	 if (mode == LIFE) // LIVES FOR HERO ( RED )
	 {


		life.polygon_x[2] = life.variable1;// variable1; C
		life.polygon_x[3] = life.variable2;// variable2; D

		iSetColor(226, 34, 34); //red
		iFilledPolygon(life.polygon_x, life.polygon_y, 4);

	 }


	

	 if (mode == CONTROLS)
	 {
		 iShowImage(controls[0].x, controls[0].y, controls[0].width, controls[0].height, controls[0].id);
	 }



	 if (mode == L1BOSSHPBAR && (L1Boss.show || L2Boss.show) )
	 {
		L1_BossHPbar.polygon_x[0] = L1_BossHPbar.variable1;// variable1; C
		L1_BossHPbar.polygon_x[1] = L1_BossHPbar.variable2;// variable2; D

		iSetColor(214, 21, 21); //red

		iFilledPolygon(L1_BossHPbar.polygon_x, L1_BossHPbar.polygon_y, 4);


		iShowImage(L1_BossHPbar.x, L1_BossHPbar.y, 458, 86, L1_BossHPbar.id);


	 }
	
}


/*
:: called from iDraw()
it renders everything related to menus.
Dependent on the variable: MenuController. The menuController's values are assigned
from menuLogic() when player clicks on specific locations
*/
void renderMenu(int PassiveMouseX, int PassiveMouseY)
{

	if (MenuController == FALLEN_KINGDOM)
	{
		iShowImage(0, 0, 1366, 768, menu[0].id); // fallen kingdom

		p++;

		if (p > 500)
		{
			iShowImage(480, 40, 461, 30, menu[1].id); // fallen kingdom font

			if (p > 3000)
			{
				p = 0;
			}
		}


	}
	 else if (MenuController == LOADING_2)
	 {
		 iShowImage(0, 0, 1366, 768, menu[victoryIndex].id);

	 }


	 else if (MenuController == SELECTIONSCREEN)
	 {
		 if (PassiveMouseX >= 120 && PassiveMouseX <= 330 && PassiveMouseY >= 350 && PassiveMouseY <= 400)
			 iShowImage(0, 0, 1368, 768, menu[3].id); //when mouse hovering over start

		 else if ((PassiveMouseX >= 120 && PassiveMouseX <= 330 && PassiveMouseY >= 280 && PassiveMouseY <= 320))
			 iShowImage(0, 0, 1368, 768, menu[4].id); //when mouse hovering over Options
		 else if ((PassiveMouseX >= 120 && PassiveMouseX <= 330 && PassiveMouseY >= 220 && PassiveMouseY <= 250))
			 iShowImage(0, 0, 1368, 768, menu[5].id); //when mouse hovering over credits
		 else if ((PassiveMouseX >= 120 && PassiveMouseX <= 330 && PassiveMouseY >= 150 && PassiveMouseY <= 190))
			 iShowImage(0, 0, 1368, 768, menu[6].id); //when mouse hovering over highscore
		 else if ((PassiveMouseX >= 120 && PassiveMouseX <= 330 && PassiveMouseY >= 80 && PassiveMouseY <= 120))
			 iShowImage(0, 0, 1368, 768, menu[7].id); //when mouse hovering over exit
		 else
			 iShowImage(0, 0, 1368, 768, menu[2].id); // normally shown when not hovering over any options 350
	 }


	else if (MenuController == ENTERNAME)
	{
		iShowImage(0, 0, 1366, 768, menu[24].id);
		iSetColor(255, 255, 255);
		iText(600, 400, UserNameInput, GLUT_BITMAP_TIMES_ROMAN_24);

		if (nameShort)
		{
			iSetColor(255, 255, 255);
			iText(530, 300, "A warrior has a bigger name!", GLUT_BITMAP_TIMES_ROMAN_24);

		}



		iSetColor(255, 255, 255);
		iText(1100, 20, "Press ENTER to continue", GLUT_BITMAP_HELVETICA_18);
		

	}
	if (MenuController == NARRATIVE_1)
	{

		//cout << " narrativeCounter : " << narrativeCounter << endl;
	
		if (narrativeCounter == 1)
		{
			iShowImage(0, 0, 1366, 768, narrative[0].id);
			iText(1100, 20, "Press SPACE to continue", GLUT_BITMAP_HELVETICA_18);
		}
		else if (narrativeCounter == 2)
		{
			iShowImage(0, 0, 1366, 768, narrative[1].id);
			iText(1100, 20, "Press SPACE to continue", GLUT_BITMAP_HELVETICA_18);
		}
		else if (narrativeCounter == 3)
		{
			iShowImage(0, 0, 1366, 768, narrative[2].id);
			iText(1100, 20, "Press SPACE to continue", GLUT_BITMAP_HELVETICA_18);
		}
		else if (narrativeCounter == 4)
		{
			iShowImage(0, 0, 1366, 768, narrative[3].id);
			iText(1100, 20, "Press SPACE to continue", GLUT_BITMAP_HELVETICA_18);
		}
		
		
	}


	else if (MenuController == HEROSELECTION)
	{


		if (PassiveMouseX >= 304 && PassiveMouseX <= 622 && PassiveMouseY >= 174 && PassiveMouseY <= 562) // hero 1
			iShowImage(0, 0, 1368, 768, menu[26].id); 
		else if (PassiveMouseX >= 720 && PassiveMouseX <= 1043 && PassiveMouseY >= 174 && PassiveMouseY <= 562) // hero 2
			iShowImage(0, 0, 1368, 768, menu[27].id);
		else																							// default
			iShowImage(0, 0, 1368, 768, menu[25].id); 

	}



	if (MenuController == LOADING_1)
	{
		iShowImage(0, 0, 1366, 768, menu[28].id);
		iSetColor(29, 109, 105);

		iFilledRectangle(266, 55, loading_dx, 15);

	}


	

	
	else if (MenuController == HIGHSCORE)
	{
		iShowImage(0, 0, 1366, 768, menu[8].id);    // highscore

		//iSetColor(255, 255, 255);
		//iText(1100, 50, "Press END to go back", GLUT_BITMAP_HELVETICA_18);

		HighScoreFiles();

		if (PassiveMouseX >= 1200 && PassiveMouseX <= 1200+95 && PassiveMouseY >= 40 && PassiveMouseY <= 40+60)
		{
			iShowImage(1200, 40, 92, 60, menu[36].id); // back button effect
		}
		else
		{
			iShowImage(1200, 40, 89, 53, menu[35].id); // back button default

		}

	

	}
	else if (MenuController == OPTIONS)
	{
		

		if (sound)
			iShowImage(0, 0, 1366, 768, menu[9].id);    // Options
		else
			iShowImage(0, 0, 1366, 768, menu[19].id); // sound off



		if (PassiveMouseX >= 1200 && PassiveMouseX <= 1200 + 95 && PassiveMouseY >= 40 && PassiveMouseY <= 40 + 60)
		{
			iShowImage(1200, 40, 92, 60, menu[36].id); // back button effect
		}
		else
		{
			iShowImage(1200, 40, 89, 53, menu[35].id); // back button default

		}

		//iSetColor(255, 255, 255);
		//iText(1100, 50, "Press END to go back", GLUT_BITMAP_HELVETICA_18);

		
	}

	else if (MenuController == CREDITS)
	{

		iShowImage(0, 0, 1366, 768, menu[10].id);   //credits roles

		//iSetColor(255, 255, 255);
		//iText(1100, 50, "Press END to go back", GLUT_BITMAP_HELVETICA_18);

		if (PassiveMouseX >= 1200 && PassiveMouseX <= 1200 + 95 && PassiveMouseY >= 40 && PassiveMouseY <= 40 + 60)
		{
			iShowImage(1200, 40, 92, 60, menu[36].id); // back button effect
		}
		else
		{
			iShowImage(1200, 40, 89, 53, menu[35].id); // back button default

		}


	}
	else if (MenuController == PAUSEMENU)
	{
		if (PassiveMouseX >= 600 && PassiveMouseX <= 710 && PassiveMouseY >= 260 && PassiveMouseY <= 300)
		{
			iShowImage(0, 0, 1368, 768, menu[12].id); // Pause resume
		}
		else if (PassiveMouseX >= 600 && PassiveMouseX <= 710 && PassiveMouseY >= 190 && PassiveMouseY <= 220)
		{
			iShowImage(0, 0, 1368, 768, menu[13].id); // Pause Options
		}
		else if (PassiveMouseX >= 630 && PassiveMouseX <= 690 && PassiveMouseY >= 120 && PassiveMouseY <= 150)
		{
			iShowImage(0, 0, 1368, 768, menu[14].id); // Pause Exit
		}
		else
			iShowImage(0, 0, 1368, 768, menu[11].id);  // Pressing home during game pops this , escape menu 
	}


	else if (MenuController == GAMEOVER) // gameover window
	{
		
		if (PassiveMouseX >= 545 && PassiveMouseX <= 608 && PassiveMouseY >= 170 && PassiveMouseY <= 235)
		{
			iShowImage(0, 0, 1366, 768, menu[16].id); // main menu highlighed
		}
		else if (PassiveMouseX >= 692 && PassiveMouseX <= 759 && PassiveMouseY >= 172 && PassiveMouseY <= 235)
		{
			iShowImage(0, 0, 1366, 768, menu[17].id); // play again  highlighed
		}
		else if (PassiveMouseX >= 833 && PassiveMouseX <= 897 && PassiveMouseY >= 172 && PassiveMouseY <= 235)
		{
			iShowImage(0, 0, 1366, 768, menu[18].id); // highscores  highlighed
		}
		else
		{
			iShowImage(0, 0, 1366, 768, menu[15].id); // default when mouse is not pointing anywhere
		}


		sprintf_s(scoreArray, "Score obtained: %d", score);
		iSetColor(255, 255, 255);
		iText(669 - 50, 373, scoreArray, GLUT_BITMAP_TIMES_ROMAN_24);
	}

	else if (MenuController == VICTORY_1)
	{

		if (PassiveMouseX >= 883 && PassiveMouseX <= 943 && PassiveMouseY >= 79 && PassiveMouseY <= 206) // proceed
			iShowImage(1366-673, 0, 663, 768, menu[21].id); // proceed

		else if (PassiveMouseX >= 1104 && PassiveMouseX <= 1163 && PassiveMouseY >= 79 && PassiveMouseY <= 206) // main menu
			iShowImage(1366 - 673, 0, 663, 768, menu[22].id); // main menu

		else
			iShowImage(1366 - 673, 0, 663, 768, menu[20].id); // default



		sprintf_s(scoreArray, "Score obtained: %d", score);
		iSetColor(255, 255, 255);
		iText(950, 467, scoreArray, GLUT_BITMAP_TIMES_ROMAN_24);

	}



	else if (MenuController == VICTORY_2)
	{

		if (PassiveMouseX >= 644 && PassiveMouseX <= 720 && PassiveMouseY >= 61 && PassiveMouseY <= 179)
			iShowImage(0, 0, 1366, 768, menu[34].id);
		else
			iShowImage(0, 0, 1366, 768, menu[33].id);

		sprintf_s(scoreArray, "Score obtained: %d", score);
		sprintf_s(nameArray, "Warrior: %s", UserNameInput);

		iSetColor(255, 255, 255);
		iText(593, 320, nameArray, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(593, 278, scoreArray, GLUT_BITMAP_TIMES_ROMAN_24);


	}



}


/*
:: called from iDraw()
it renders the OBJECTIVES, WAVES, SCORE
*/
void renderUI(int mode)
{

	if (mode == OBJECTIVE && objective[objectiveIndex].show)
	{
		//cout << "hello" << endl;
		iShowImage(objective[objectiveIndex].x, objective[objectiveIndex].y, objective[objectiveIndex].width, objective[objectiveIndex].height, objective[objectiveIndex].id);

	}
	if (mode == WAVE)
	{
		if (stage_mark.count < 4 && !bridgeSegment) 
		{

			if (stage_mark.count < 4 && waveIndex >= 0)
			{
			//	if (wave[waveIndex-1].show)
				iShowImage(wave[waveIndex].x, wave[waveIndex].y, wave[waveIndex].width, wave[waveIndex].height, wave[waveIndex].id);
				sprintf_s(creepsAliveArray, "Creeps alive: %d/%d", creepsAlive, creepsCount);

				if (creepsCount != 0)
				{
					iSetColor(255, 255, 255);
					iText(1100, 150, creepsAliveArray, GLUT_BITMAP_TIMES_ROMAN_24);
				}
			

			}



		}

	}

	if (mode == SCORE)
	{
		//showing SCORE
		sprintf_s(scoreArray, "Current Score: %d", score);
		iSetColor(255, 255, 255);
		iText(1100, 100, scoreArray, GLUT_BITMAP_TIMES_ROMAN_24);

	}


	//if (mode == DIRECTION_L)
	//{
	//	iShowImage(objective[0].x, objective[0].y, objective[0].width, objective[0].height, objective[0].id);

	//}
	//if (mode == DIRECTION_R)
	//{
	//	iShowImage(objective[1].x, objective[1].y, objective[1].width, objective[1].height, objective[1].id);

	//}
	
	


}

/*
:: called from iDraw()
it renders the level 1 cutscenes
*/
void renderNarrative(int mode, int i)
{
	if (mode == LEVEL_1)
	{
		iShowImage(cutscenes[cutsceneIndex].x, cutscenes[cutsceneIndex].y, cutscenes[cutsceneIndex].width, cutscenes[cutsceneIndex].height, cutscenes[cutsceneIndex].id);
	}
	if (mode == LEVEL_2)
	{

		iShowImage(cutscenes[cutsceneIndex].x, cutscenes[cutsceneIndex].y, cutscenes[cutsceneIndex].width, cutscenes[cutsceneIndex].height, cutscenes[cutsceneIndex].id);

	}
	

}


/*
:: called from iMouse()
when the mouse cursor is over certain elements, ie: START GAME, OPTIONS.. etc, then their respective values are assigned into
MenuController and appropriate functions are called respectively
*/
void menuLogic(int mx, int my)
{



	if ((MenuController == OPTIONS || MenuController == HIGHSCORE || MenuController == CREDITS) && ((mx >= 1200 && mx <= 1200+95) && (my >= 40 && my <= 40+60)) ) // when inside pausemenu, then pressing END wont go back to prev page
	{

		MenuController = PreviousMenu;

	}



	if (MenuController == SELECTIONSCREEN && ((mx >= 120 && mx <= 330) && (my >= 350 && my <= 400))) // start game
	{

		MenuController = ENTERNAME;
		PreviousMenu = SELECTIONSCREEN;


	}

	if (MenuController == HEROSELECTION)
	{
		if ((mx >= 304 && mx <= 622) && (my >= 174 && my <= 562)) // select hero 1
		{
		//	cout << "menucontroller set to : " << MenuController << endl;
			
			MenuController = LOADING_1;
			initializeHero(HERO_1);

			initLevel_1 = true;



		}
		else if ((mx >= 720 && mx <= 1043) && (my >= 174 && my <= 562)) //  select hero 2
		{
			
			MenuController = LOADING_1;
			initializeHero(HERO_2);

			initLevel_1 = true;




		}

		
	}

	else if (MenuController == SELECTIONSCREEN && ((mx >= 120 && mx <= 330) && (my >= 280 && my <= 320))) // options 
	{
		MenuController = OPTIONS;
		PreviousMenu = SELECTIONSCREEN;

	}




	//BUGG IN COORDINATE
	else if (MenuController == OPTIONS && PreviousMenu == SELECTIONSCREEN && ((mx >= 0 && mx <= 1034) && (my >= 0 && my <= 1000))) // options: sound off 
	{

		PreviousMenu = SELECTIONSCREEN;



		if (!sound)
		{
			sound = true;
			playSound(MENU);



		}
		else
		{
			sound = false;
			PlaySound(NULL, 0, 0);



		}

	}


	else if (MenuController == SELECTIONSCREEN && ((mx >= 120 && mx <= 330) && (my >= 220 && my <= 250))) // Credits
	{
		MenuController = CREDITS;
		PreviousMenu = SELECTIONSCREEN;

	}
	else if (MenuController == SELECTIONSCREEN && ((mx >= 120 && mx <= 330) && (my >= 150 && my <= 190)))// credits - roles
	{
		MenuController = HIGHSCORE; // highscore
		PreviousMenu = SELECTIONSCREEN;
		SettingNewHighScore();

	}
	else if (MenuController == SELECTIONSCREEN && ((mx >= 120 && mx <= 330) && (my >= 80 && my <= 120))) // exits from game.
	{
		exit(0);

	}
	else if (MenuController == PAUSEMENU && ((mx >= 600 && mx <= 710) && (my >= 260 && my <= 300)))
	{
		MenuController = PLAY;  //continue to game
		PreviousMenu = PLAY;

		gameStart = true;


		iResumeTimer(timer_AUTOMOTION);
		iResumeTimer(timer_ENEMYMOTION);
		iResumeTimer(timer_HEROMOTION);

	}
	else if (MenuController == PAUSEMENU && ((mx >= 600 && mx <= 710) && (my >= 190 && my <= 220)))
	{
		MenuController = OPTIONS; // showing Options from Pause Menu
		PreviousMenu = PAUSEMENU;

	}
	else if (MenuController == PAUSEMENU && ((mx >= 630 && mx <= 690) && (my >= 120 && my <= 150)))
	{
		MenuController = SELECTIONSCREEN; // Going into the main menu from escape menu
		PreviousMenu = SELECTIONSCREEN;

		playSound(MENU);
		resetGame();    // Re-Initializing game variables
	}

	else if (MenuController == OPTIONS && PreviousMenu == PAUSEMENU && ((mx >= 0 && mx <= 1034) && (my >= 0 && my <= 1000))) // options: sound off 
	{

		PreviousMenu = PAUSEMENU;

		if (!sound)
		{
			sound = true;
			playSound(MENU);

		}
		else
		{
			sound = false;
			PlaySound(NULL, 0, 0);

		}

	}

	else if (MenuController == GAMEOVER && (mx >= 545 && mx <= 608 && (my >= 170 && my <= 235))) // back to mainmenu
	{
		MenuController = SELECTIONSCREEN;
		PreviousMenu = SELECTIONSCREEN;
		playSound(MENU);
		resetGame();

	}

	//play again after losing
	else if (MenuController == GAMEOVER && (mx >= 682 && mx <= 759 && (my >= 172 && my <= 235))) 
	{
		
		MenuController = PLAY;			// game starts when this is reached
		PreviousMenu = PLAY;

		initLevel_1 = true;

		gameStart = true;
		gameOver = false;               
		gameWon_1 = false;

		if (hero_1)
		{
			initializeHero(HERO_1);
		}
		else
		{
			initializeHero(HERO_2);
		}


		playSound(STOP);
		playSound(LEVEL_1);
	

	}
	else if (MenuController == GAMEOVER && (mx >= 833 && mx <= 897 && (my >= 172 && my <= 235))) // check high scores window 
	{
		MenuController = HIGHSCORE;
		PreviousMenu = GAMEOVER;
	}

	else if (MenuController == VICTORY_1 && (mx >= 1104 && mx <= 1163 && (my >= 79 && my <= 206))) // returns to mainmenu from victory 1 window
	{
		MenuController = SELECTIONSCREEN;
		PreviousMenu = SELECTIONSCREEN;
		playSound(MENU);
	
		resetGame();
		


	}
	else if (MenuController == VICTORY_1 && (mx >= 883 && mx <= 943 && (my >= 79 && my <= 209))) // proceed to level 2
	{

		gameWon_1 = false;
		gameStart = true;
		gameOver = false;
	
		MenuController = PLAY;
		PreviousMenu = PLAY;

		playSound(STOP);
		playSound(LEVEL_2);

		initLevel_2 = true;


	}


	else if (MenuController == VICTORY_2 && (mx >= 644 && mx <= 720 && (my >= 61 && my <= 179))  ) // BACK TO MAINMENU
	{
		MenuController = SELECTIONSCREEN;
		PreviousMenu = SELECTIONSCREEN;
		playSound(MENU);

		resetGame();
	}



}



#endif