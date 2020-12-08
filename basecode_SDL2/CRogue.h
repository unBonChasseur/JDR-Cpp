#pragma once
#include "CCharacter.h"

class CRogue : public CCharacter
{
protected :
	int m_nbToursFurtif;
	int m_CDFurtif;
	float m_poison;

	CRogue();

public :
	CRogue(std::string nom, int vie, float esquive, int vitesseBase, int attaque, int defense, int agilite, int intelligence, float poison);
	virtual ~CRogue();

	void AttaquerAvecArme();

	void Furtivite();

	void print();
};

