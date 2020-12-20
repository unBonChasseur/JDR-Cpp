#pragma once
#include "CCharacter.h"
#include "CBow.h"

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

	int AttaquerAvecArme(CCharacter* ccharacter);

	float GetPoison();
	int GetNbToursFurtif();
	int GetCDFurtif();
	
	void Furtivite();

	void Print();
	void DebuterTour();
};

