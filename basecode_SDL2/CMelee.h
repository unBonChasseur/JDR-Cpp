#pragma once
#include "CWeapon.h"

class CMelee : public CWeapon
{
protected :
	int m_durabiliteInitiale;
	int m_durabilite;
	CMelee();

public :
	CMelee(std::string nom, std::string degats, std::string critique, std::string bonus, int durabilite);
	virtual ~CMelee();

};

