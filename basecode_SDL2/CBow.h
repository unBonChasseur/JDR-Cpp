#pragma once
#include "CRanged.h"

class CBow : public CRanged
{
protected:

	int m_nbFlechesBase;
	int m_nbFleches;

	CBow();

public:
	CBow(std::string type, std::string nom, int degats, float critique, int vie, float esquive, int vitesse, int attaque, int defense, int agilite, int intelligence, int nbFleches);

	int GetNbFleches();
	int GetNbFlechesBase();

	float CalculerDegats();

	void RecupererFleches();
	void Utiliser();
	void Reinitialiser();

	void print();
};

