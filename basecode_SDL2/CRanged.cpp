#include "CRanged.h"

CRanged::CRanged():CWeapon()
{
}

CRanged::CRanged(std::string type, std::string nom, int degats, float critique, float bonus, int vie, float esquive, int vitesseBase, int attaque, int defense, int agilite, int intelligence):
	CWeapon(type, nom, degats, critique, bonus, vie, esquive, vitesseBase, attaque, defense, agilite, intelligence)
{
}

CRanged::~CRanged()
{
}

float CRanged::Utiliser()
{
	return 0.0f;
}
