#pragma once
#include "CWeapon.h"

class CMelee : public CWeapon
{
protected :
	int m_durabiliteInitiale;
	int m_durabilite;

	CMelee();

public :
	CMelee(std::string type, std::string nom, int degats, float critique, float bonus, int durabilite);
	virtual ~CMelee();
};

