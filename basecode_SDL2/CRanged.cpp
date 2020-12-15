#include "CRanged.h"

CRanged::CRanged():CWeapon()
{
}

CRanged::CRanged(std::string type, std::string nom, int degats, float critique, int vie, float esquive, int vitesse, int attaque, int defense, int agilite, int intelligence):
	CWeapon(type, nom, degats, critique, vie, esquive, vitesse, attaque, defense, agilite, intelligence)
{
}

float CRanged::GetSpecial()
{
	return 0.0f;
}

void CRanged::print()
{
}
