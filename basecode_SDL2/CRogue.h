#pragma once
#include "CCharacter.h"

class CRogue : public CCharacter
{
protected :
	float m_poison;

	int m_nbToursFurtif;

	int m_CDFurtif;

	CRogue();

public :
	CRogue(std::string nom, int vie, CWeapon* weapon, float esquive, int vitesseBase, int attaque, int defense, int agilite, int intelligence, float poison);
	virtual ~CRogue();

	std::string GetClasse();
	float GetCaracPartic();

	void AttaquerAvecArme();

	void Furtivite();

	void Print();
};

