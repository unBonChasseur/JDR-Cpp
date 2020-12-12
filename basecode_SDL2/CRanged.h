#pragma once
#include "CWeapon.h"

class CRanged : public CWeapon
{
protected:

	CRanged();

public:
	CRanged(std::string type, std::string nom, int degats, float critique, float bonus
		, int vie, float esquive, int vitesseBase, int attaque, int defense, int agilite, int intelligence);

	virtual float GetSpecial();

	virtual void print();
};


