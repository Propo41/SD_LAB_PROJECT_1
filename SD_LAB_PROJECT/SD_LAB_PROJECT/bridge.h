#ifndef bridge_H
#define bridge_H

using namespace std;

#include "declarations.h"
#include "character.h"


bool build_bridge = false;
bool bridge_fall = false;
bool bridgeDone = false;
bool rotateBridge = false;

int bridgeGap[] = { 113, 206, 332 };
int bridgeEdgeCoordinate[] = { 177, 470, 854 };
int blockCenterCoordinate[] = { 0, 292, 676, 1190 }; // for the hero to be at the center of the blocks, so that the player can reposition himself at the center 
//int destroyBridgeRender[10];

int bridge_x, bridge_y = tileHeight;
int bridge_width = 10, bridge_height=0;

int theta = 0;
int step = 0;
int bridgeIndex = 0;

void resetBridge()
{

	/*animation effect for bridge vanishing: add later @mustofa
	for (int i = 0; i < 5; i++) 
	{
		iShowImage(bridge_x, bridge_y, bridge_width, bridge_height, destroyBridgeRender[i]);
		iDelayMS(20);
	}*/

	
	step = 0;
	bridge_fall = false;
	bridge_y = tileHeight;
	bridge_height = 0;
//	bridgeIndex++;
	theta = 0;

	build_bridge = false;
	bridge_fall = false;
	bridgeDone = false;
    rotateBridge = false;
	fallAnimate = false;
}

//animation effect when creating the bridge: add later: @ahnaf

void buildBridge()
{
	bridge_x = hero.x + 120;

	iSetColor(0, 0, 0);
	iFilledRectangle(bridge_x, bridge_y, bridge_width, bridge_height);
}

void dropBridge()
{
	rotateBridge = true;
	if (theta <= -90)
	{
		
		rotateBridge = false;
		if (!bridgeDone)
			movePlayer = true;

		bridgeDone = true;
		
	}
	iRotate(bridge_x, bridge_y, theta);
	iSetColor(0, 0, 0);

	iFilledRectangle(bridge_x, bridge_y, bridge_width, bridge_height);
	iUnRotate();

}


void movePlayerOverBridge()
{
	heroStanding = false;


	hero.x += 40;
	//moveScreen(LEFT); // !!!!!!! bugg here. if not used, then works fine !!!!!!!
	hero.index++;
	if (hero.index >= 6)
		hero.index = 1;

	
	step += 40; // higher the value, the hero walks upto a small length

	if (step > bridge_height)
	{

		movePlayer = false;
		heroStanding = true;

		int h = bridge_height - (bridgeEdgeCoordinate[bridgeIndex] - bridge_x);

		if (h < bridgeGap[bridgeIndex])
		{
			fallAnimate = true;
			score -= 10;
			if (score < 0)
				score = 0;

		}
		else // when player successfully passed the bridge
		{
			resetBridge(); 

			score += 20;


			bridgeIndex++;
			hero.x = blockCenterCoordinate[bridgeIndex];

	
			if (bridgeIndex > 2) //if no more bridges left, fix the background and switch off bridge building power
			{
				bridgeSegment = false;
				fixBackground = true;

				objective[objectiveIndex].show = false; // hiding the 1st objective.
				
			}

		
		}


	}
}

void bridge()
{
	// rotates the bridge and show it
	if (bridge_fall)
	{
		dropBridge();
	}

	// bridge_x increases and shows it
	if (build_bridge)
	{
		buildBridge();

	}
}

#endif