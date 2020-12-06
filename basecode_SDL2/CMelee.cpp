#include "CMelee.h"

CMelee::CMelee():CWeapon()
{
	m_durabilite = 0;
	m_durabiliteInitiale = 0;
}

void CMelee::SetDurabilite(int durabilite)
{
	m_durabilite = durabilite;
}

CMelee::CMelee(std::string type, std::string nom, int degats, float critique, float bonus, int vie, float esquive, int vitesseBase, int attaque, int defense, int agilite, int intelligence, int durabilite)
	:CWeapon(type, nom, degats, critique, bonus, vie, esquive, vitesseBase, attaque, defense, agilite, intelligence),
	m_durabilite(durabilite),
	m_durabiliteInitiale(durabilite)
{
}

CMelee::~CMelee()
{
}

int CMelee::GetDurabiliteInitiale()
{
	return m_durabiliteInitiale;
}


int CMelee::GetDurabilite()
{
	return m_durabilite;
}