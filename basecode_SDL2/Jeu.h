#pragma once
#include <vector>
#include "CCharacter.h"
#include "Parsing.h"

class Jeu
{
protected :
	Parsing m_parsing;
	std::vector<std::vector<CCharacter*>> m_vector;

public :
	Jeu();
	~Jeu();

	void DemarrerJeu();

	int VerifierParamPartie();
	void lancerPartie();
	
	void ParamJoueur(std::vector<CCharacter*> p_vector, int i);
	void PrintJoueur(std::vector<CCharacter*> p_vector, int i);

	void AjouterPersonnage(std::vector<CCharacter*> p_vector, int i);

	void ViderVariables();
	
	
};

