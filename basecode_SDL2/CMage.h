#pragma once
#include "CCharacter.h"
#include "CStaff.h"
#include "CMelee.h"

class CMage : public CCharacter
{
protected :
	int m_manaBase;
	int m_mana;

	int m_CDsoin;
	int m_CDenchantement;

	CMage();

public :
	CMage(std::string nom, int vie, CWeapon* weapon, float esquive, int vitesse, int attaque, int defense, int agilite, int intelligence);
	virtual ~CMage();

	int AttaquerAvecArme(CCharacter* cible);

	int GetManaBase();
	int GetMana();
	int GetCDSoin();
	int GetCDEnchantement();

	void RegenererMana();
	int Soigner(CCharacter* cible);
	int Enchanter(CCharacter* cible);

	void Print();
	void DebuterTour();
	void Reinitialiser();
};

