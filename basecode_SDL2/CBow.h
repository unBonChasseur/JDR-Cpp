#pragma once
#include "CRanged.h"

class CBow : public CRanged
{
protected:

	int m_nbFlechesBase;
	int m_nbFleches;

	CBow();

public:
	CBow(std::string type, std::string nom, int degats, float critique, float bonus
		, int vie, float esquive, int vitesseBase, int attaque, int defense, int agilite, int intelligence, int nbFleches);

	int GetNbFleches();
	int GetNbFlechesBase();

	void SetNbFleches(int nbFleches);

	float GetSpecial();

	void print();
};

