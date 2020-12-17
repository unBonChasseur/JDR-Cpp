#pragma once
#include "CCharacter.h"

class CMage : public CCharacter
{
protected :
	int m_manaMax;
	int m_mana;

	int m_CDsoin;
	int m_CDenchantement;

	CMage();

public :
	CMage(std::string nom, int vie, CWeapon* weapon, float esquive, int vitesse, int attaque, int defense, int agilite, int intelligence);
	virtual ~CMage();

	std::string GetClasse();
	void AttaquerAvecArme(CCharacter* cible);
	float GetCaracPartic();

	void RegenererMana();
	void Soigner(CCharacter* cible);
	void Enchanter(CCharacter* cible);
	void Print();
};

