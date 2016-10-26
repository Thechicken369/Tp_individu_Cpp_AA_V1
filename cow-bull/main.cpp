#include "gestGame.h"
#include <string>


void main()
{
	//Init game
	gestGame myGame;
	bool replay = true;

	if (myGame.affichageMenu())
	{
		//Boucle principale 
		while (replay) {
			myGame.initGame();
			//boucle de jeu de saisie du mot 
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
	}
}
