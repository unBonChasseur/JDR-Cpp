#pragma once
#include "CMelee.h"

class CDagger : public CMelee
{
protected:

	CDagger();

public:

	CDagger(std::string type, std::string nom, int degats, float critique, float bonus
		, int vie, float esquive, int vitesseBase, int attaque, int defense, int agilite, int intelligence, int durabilite);

	virtual ~CDagger();

	float Utiliser();
};

