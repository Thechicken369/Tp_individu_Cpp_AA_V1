#include "gestGame.h"
#include <string>


void main()
{
	//Init game
	gestGame myGame;
	bool replay = true;

	if (myGame.affichageMenu())
	{

		while (replay) {
			myGame.initGame();
			while (!myGame.getIsWon())
			{
				myGame.comptBullAndCow(myGame.enterWord());

			}
			if (myGame.getCurentTry() == myGame.GetMaxTries())
			{
				myGame.afficheDefaite();
			}
			else
			{
				myGame.afficheWin();
			}

			replay = myGame.replay();
		}


		system("pause");
	}
}
