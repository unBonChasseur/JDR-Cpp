#pragma once
#include "CWeapon.h"

class CMelee : public CWeapon
{
protected :
	int m_durabiliteBase;
	int m_durabilite;
	int m_enchantee;

	CMelee();
	virtual void Utiliser();

public :
	CMelee(std::string type, std::string nom, int degats, float critique, int vie, float esquive, int vitesse, int attaque, int defense, int agilite, int intelligence, int durabilite);

	int GetDurabiliteInitiale();
	int GetDurabilite();

	float CalculerDegats();
	void Reparer();

	virtual void print();
};

