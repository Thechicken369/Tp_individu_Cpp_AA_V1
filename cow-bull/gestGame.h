#pragma once
#include <string>

using namespace std;

struct Bull_cow 
{
	int ctBull;
	int ctCow;

};

enum status
{
	Invalide_Statut,
	ok,
	not_isogram,
	wrong_length,
	not_lower_case
};

enum hiddenWords
{
	patate,
	poulet,
	riz,
	macaron,
	morue
};



class gestGame
{

private:
	int MyCurentTry;
	string myHiddenWord;
	bool gameIsWon;
	Bull_cow compteurs;
	status GameStatut;


public:

	//MUTATEUR
	int getCurentTry() const;
	bool getIsWon() const;
	int GetMaxTries() const;
	
	//Fonctions de gestions
	void comptBullAndCow(string monMot);
	status gestErreur(string monMot);

	//Reset les competeur
	void resetCompteur();

	//Fonction d'affichage
	void affichageErreur(int ID);
	bool affichageMenu();
	void affichResult();
	void afficheDefaite();
	void afficheWin();

	//Fonction de saisie
	string enterWord();
	bool replay();

	//Fonction d'initialisation 
	void initGame();
	
	//Constructeur et Destructeur
	gestGame();
	~gestGame();
	
};

