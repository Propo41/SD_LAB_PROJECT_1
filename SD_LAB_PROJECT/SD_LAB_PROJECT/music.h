#ifndef music_h
#define music_h

#include "declarations.H"


void playSound(int mode)
{
	if (sound)
	{


		if (mode == MENU)
		{
			//cout << "eee" << endl;

			PlaySound("music\\menuMusic.wav", NULL, SND_LOOP | SND_ASYNC);

		}
		if (mode == STOP)
		{
			PlaySound(NULL, 0, 0);

		}
		if (mode == INGAME)
		{
			PlaySound("music\\ingame.wav", NULL, SND_LOOP | SND_ASYNC);

		}
		if (mode == GAMEOVER)
		{
		 //	cout << "helo" << endl;
			PlaySound("music\\gameover.wav", NULL, SND_LOOP | SND_ASYNC);

		}
	}

}
#endif