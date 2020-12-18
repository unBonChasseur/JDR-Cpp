#pragma once
#include <vector>
#include "CCharacter.h"
#include "Parsing.h"

class Jeu
{
protected :
	std::vector<Parsing*> m_parsing;
	std::vector<std::vector<CCharacter*>> m_vector;

public :
	Jeu();
	~Jeu();

	//Fonctions menu principal
	void DemarrerJeu();

	//Option 1 : Lancer une partie
	int VerifierParamPartie();

	//Option 2 & 3 : Modifier les paramètres d'équipe des joueurs
	void ParamJoueur(int i);
	
	//Sous options : modifier la liste des personnages et armes de chaque joueur
	void AjouterPersonnage(int i);
	void RemplacerPersonnage(int i);
	void RemplacerArme(int i);

	//Option 4 : Quitter le jeu
	void ViderVariables();
	
	//Fonctions déroulement partie 
	int LancerPartie();
	void AttaquerSansArme(CCharacter* ccharacter, int i);
	int Rejouer();

	//Fontions annexes 
	void PrintJoueur(int i);
	void EnleverCharacter(CCharacter* ccharacter, int i);
	int VerifierMorts();
};

