#pragma once
#include "CCharacter.h"

class CArcher : public CCharacter
{
protected :

	CArcher();

public :
	CArcher(std::string nom, int vie, CWeapon* weapon, float esquive, int vitesse, int attaque, int defense, int agilite, int intelligence);
	virtual ~CArcher();

	void AttaquerAvecArme(CCharacter* ccharacter);

	void GuerirPoison();
	void Viser();

	void Print();
};

