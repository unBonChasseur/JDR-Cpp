#pragma once
#include "CWeapon.h"

class CRanged : public CWeapon
{
protected:

	CRanged();

public:
	CRanged(std::string type, std::string nom, int degats, float critique, int vie, float esquive, int vitesse, int attaque, int defense, int agilite, int intelligence);

	float CalculerDegats();

	virtual void print();
};


