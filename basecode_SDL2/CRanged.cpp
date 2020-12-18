#include "CRanged.h"

CRanged::CRanged():CWeapon()
{
}

CRanged::CRanged(std::string type, std::string nom, int degats, float critique, int vie, float esquive, int vitesse, int attaque, int defense, int agilite, int intelligence):
	CWeapon(type, nom, degats, critique, vie, esquive, vitesse, attaque, defense, agilite, intelligence)
{
}

void CRanged::Reparer()
{
}

int CRanged::GetSpecial()
{
	return 0;
}

void CRanged::print()
{
}
