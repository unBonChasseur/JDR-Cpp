#pragma once
#include "CCharacter.h"

class CWarrior : public CCharacter
{
protected :	
	float m_parade;

	int m_hurlement;
	int m_CDHurlement;

	CWarrior();

public :
	CWarrior(std::string nom, int vie, CWeapon* weapon, float esquive, int vitesse, int attaque, int defense, int agilite, int intelligence, float parade);
	virtual ~CWarrior();

	void AttaquerAvecArme(CCharacter* ccharacter);
	int Esquiver();
	float GetCaracPartic();

	void Hurler();
	void ReparerArme(CCharacter* allie);
	void Print();
};

