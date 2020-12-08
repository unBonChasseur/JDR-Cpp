#pragma once
#include "CCharacter.h"

class CWarrior : public CCharacter
{
protected :
	int m_CDHurlement;
	float m_parade;
	int m_hurlement;

	CWarrior();

public :
	CWarrior(std::string nom, int vie, float esquive, int vitesseBase, int attaque, int defense, int agilite, int intelligence, float parade);
	virtual ~CWarrior();

	void AttaquerAvecArme(CCharacter CCharacter);

	void Hurler();
	void ReparerArme();
	void print();
};

