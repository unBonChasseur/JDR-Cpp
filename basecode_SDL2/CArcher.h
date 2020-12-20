#pragma once
#include "CCharacter.h"
#include "CBow.h"

class CArcher : public CCharacter
{
protected :
	float m_visee;
	int m_nbGuerison;
	CArcher();

public :
	CArcher(std::string nom, int vie, CWeapon* weapon, float esquive, int vitesse, int attaque, int defense, int agilite, int intelligence);
	virtual ~CArcher();

	int AttaquerAvecArme(CCharacter* ccharacter);

	void GuerirPoison(CCharacter* allie);
	void Viser();
	int GetNbGuerison();

	void Print();
};

