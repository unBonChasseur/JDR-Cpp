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
	CWarrior(std::string nom, int vie, CWeapon* weapon, float esquive, int vitesseBase, int attaque, int defense, int agilite, int intelligence, float parade);
	virtual ~CWarrior();

	float GetCaracPartic();

	void AttaquerAvecArme(CCharacter CCharacter);

	void Hurler();
	void ReparerArme();
	void print();
};

