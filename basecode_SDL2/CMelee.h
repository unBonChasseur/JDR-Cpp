#pragma once
#include "CWeapon.h"

class CMelee : public CWeapon
{
protected :
	int m_durabiliteInitiale;
	int m_durabilite;

	CMelee();
	void SetDurabilite(int durabilite);

public :
	CMelee(std::string type, std::string nom, int degats, float critique, float bonus
		, int vie, float esquive, int vitesseBase, int attaque, int defense, int agilite, int intelligence, int durabilite);
	virtual ~CMelee();

	int GetDurabiliteInitiale();
	int GetDurabilite();
	
};

