#pragma once
#include "CCharacter.h"

class CRogue : public CCharacter
{
protected :
	float m_poison;

	int m_nbToursFurtif;

	int m_CDFurtif;

	CRogue();
	int Empoisonner();

public :
	CRogue(std::string nom, int vie, CWeapon* weapon, float esquive, int vitesse, int attaque, int defense, int agilite, int intelligence, float poison);
	virtual ~CRogue();

	void AttaquerAvecArme(CCharacter* ccharacter);
	float GetCaracPartic();

	void Furtivite();
	void Print();
};

