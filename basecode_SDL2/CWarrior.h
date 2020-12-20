#pragma once
#include "CCharacter.h"
#include "CMelee.h"

class CWarrior : public CCharacter
{
protected :	
	float m_parade;

	int m_nbToursHurlement;
	int m_CDHurlement;

	CWarrior();

public :
	CWarrior(std::string nom, int vie, CWeapon* weapon, float esquive, int vitesse, int attaque, int defense, int agilite, int intelligence, float parade);
	virtual ~CWarrior();

	int AttaquerAvecArme(CCharacter* ccharacter);
	int Esquiver();

	float GetParade();
	int GetNbToursHurlement();
	int GetCDHurlement();

	void Hurler();
	void ReparerArme(CCharacter* allie);

	void Print();
	void DebuterTour();
};

