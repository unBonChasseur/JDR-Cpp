#pragma once
#include "CWeapon.h"

class CMelee : public CWeapon
{
protected :
	int m_durabiliteInitiale;
	int m_durabilite;

	CMelee();

public :
	CMelee(std::string type, std::string nom, int degats, float critique, float bonus
		, int vie, float esquive, int vitesseBase, int attaque, int defense, int agilite, int intelligence, int durabilite);

	int GetDurabiliteInitiale();
	int GetDurabilite();
	void SetDurabilite(int durabilite);
	virtual void print();
};

