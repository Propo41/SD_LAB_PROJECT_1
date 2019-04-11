#ifndef bridge_H
#define bridge_H

using namespace std;

#include "declarations.h"
#include "character.h"


/*
bridge gets resetted when the bridge is build completely or when it increases to a maximum height
the function initializes all the variables of bridge
*/
void resetBridge()
{

	
	step = 0;
	bridge_fall = false;
	bridge_y = tileHeight;
	bridge_height = 0;
	theta = 0;

	build_bridge = false;
	bridge_fall = false;
	bridgeDone = false;
    rotateBridge = false;
	fallAnimate = false;
}

/*
typical call would be from the function bridge() which is in iDraw();

*/
void buildBridge()
{
	// bridge is built near the hero
	bridge_x = hero.x + 120;

	iSetColor(0, 0, 0);
	iFilledRectangle(bridge_x, bridge_y, bridge_width, bridge_height);
}

/*
rotates the bridge, ie make it fall over. 
When the bridge is built completely, the player is moved through. This is done by making movePlayer=true;
*/
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

/*
timer function: it moves the player over completed bridge. The block calculates the gap difference and checks if the hero will fall or not.
If it falls, then fallAnimate is made true and the animation appears of falling.
else, the bridge is resetted and the player continues, gaining score
*/
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


/*
iDraw functions
*/
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