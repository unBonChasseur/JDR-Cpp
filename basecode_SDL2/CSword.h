#pragma once
#include "CMelee.h"

class CSword : public CMelee
{
protected :

	CSword();

public :
	CSword(std::string type, std::string nom, int degats, float critique, float bonus
		, int vie, float esquive, int vitesseBase, int attaque, int defense, int agilite, int intelligence, int durabilite);

	void print();
};

