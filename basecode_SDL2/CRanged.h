#pragma once
#include "CWeapon.h"

class CRanged : public CWeapon
{
protected:

	CRanged();

public:
	CRanged(std::string nom, std::string degats, std::string critique, std::string bonus, int durabilite);
	virtual ~CRanged();

};


