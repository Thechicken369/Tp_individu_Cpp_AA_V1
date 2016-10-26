#include "gestGame.h"
#include <map>
#include <ctype.h>
#include <iostream>

//Constructeur par default 
gestGame::gestGame()
{
	this->gameIsWon = false;
	this->MyCurentTry = 0;
	this->myHiddenWord = "pate";
	this->compteurs.ctBull = 0;
	this->compteurs.ctCow = 0;
}

//Destrcteur
gestGame::~gestGame()
{
}

//Retourne MyCurrentTry
int gestGame::getCurentTry() const
{
	return this->MyCurentTry;
}

//Retourne la valeur de gameIsWon
bool gestGame::getIsWon() const
{
	return this->gameIsWon;
}

void gestGame::comptBullAndCow(string monMot)
{

	if (this->gestErreur(monMot) != 1)
	{
		this->affichageErreur(this->gestErreur(monMot));
	}
	else if (monMot == this->myHiddenWord || this->MyCurentTry == this->GetMaxTries())
	{
		this->gameIsWon = true;
		
	}else
	{
		for (int i = 0; i < this->myHiddenWord.length(); i++)
		{
			if (monMot[i] == this->myHiddenWord[i])
			{
				this->compteurs.ctBull++;
			}
			for (int j = 0; j < this->myHiddenWord.length(); j++)
			{
				if (monMot[j] == this->myHiddenWord[i] && i != j)
				{
					this->compteurs.ctCow++;
				}
			}

		}
		this->MyCurentTry++;
		this->affichResult();
		this->resetCompteur();
	}
}

void gestGame::resetCompteur()
{
	this->compteurs.ctBull = 0;
	this->compteurs.ctCow = 0;
}

void gestGame::affichageErreur(int ID)
{
	switch (ID)
	{
	case 2:
		cout << "Le mot n'est pas un isograme réasayer" << endl;
		break;
	case 3:
		cout << "le mot n'est pas de la bonne longueur" << endl;
		break;
	case 4:
		cout << "Il y a au moin un caractére en maj" << endl;
		break;
	default:
		cout << "Erreur Inconu reaisayer" << endl;
		break;
	}
}

status gestGame::gestErreur(string monMot)
{
	status Stat;
	for (int i = 0; i <= monMot.length(); i++)
	{
		for (int j = 0; j <= monMot.length(); j++)
		{
			if (monMot[i] == monMot[j] && i!=j)
			{
				return not_isogram;
			}
			else if (isupper(monMot[i]))
			{
				return not_lower_case;
			}
		}
	}
	if (monMot.length() != this->myHiddenWord.length())
	{
		return wrong_length;
	}
	else {
		return ok;
	}

}

int gestGame::GetMaxTries() const
{
	std::map<int, int> WordLengthToMaxTries{ { 3,4 },{ 4,7 },{ 5,10 },{ 6,16 },{ 7,20 } };
	return WordLengthToMaxTries[myHiddenWord.length()];
}


bool gestGame::affichageMenu()
{
	string test;
	cout << "Voullez vous jouez avec un mot cachez ? (y/n)" << endl;
	cin >> test;
	if (test == "y" || test == "Y")
	{
		return true;
	}
	else {
		return false;
	}
}

string gestGame::enterWord()
{
	string esais;
	cout << "Entrer votre mot vous avez " << this->GetMaxTries() - this->MyCurentTry << " esais restant " << endl;
	cin >> esais;
	return esais;
}

void gestGame::affichResult()
{
	cout << "cow= " << this->compteurs.ctCow << " bull =" << this->compteurs.ctBull << endl;
}

void gestGame::afficheDefaite()
{
	cout << "Oh noooon !!! Vous avez pzrdu" << endl;
}
void gestGame::afficheWin()
{
	cout << "BRAVO !!!! Vous avez trouver le mot :" << this->myHiddenWord <<  endl;
}

bool gestGame::replay()
{
	string replay;
	cout << "Voulez vous rejouer ? y/n" << endl;
	cin >> replay;
	if (replay == "y" || replay == "Y")
	{
		return true;
		
	}
	else
	{
		return false;
	}


}

void gestGame::initGame()
{
	this->gameIsWon = false;
	this->MyCurentTry = 0;
	this->myHiddenWord = "pate";
	this->compteurs.ctBull = 0;
	this->compteurs.ctCow = 0;

}

