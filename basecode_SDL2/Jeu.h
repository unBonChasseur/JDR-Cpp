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

	void DemarrerJeu();

	int VerifierParamPartie();
	void lancerPartie();
	
	void ParamJoueur(int i);
	void PrintJoueur(int i);

	void AjouterPersonnage(int i);
	void RemplacerArme(int i);

	void ViderVariables();
	
	
};

