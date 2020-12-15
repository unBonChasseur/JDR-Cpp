#include "CMelee.h"

CMelee::CMelee():CWeapon()
{
	m_durabilite = 0;
	m_durabiliteInitiale = 0;
}

CMelee::CMelee(std::string type, std::string nom, int degats, float critique, int vie, float esquive, int vitesse, int attaque, int defense, int agilite, int intelligence, int durabilite)
	:CWeapon(type, nom, degats, critique, vie, esquive, vitesse, attaque, defense, agilite, intelligence),
	m_durabilite(durabilite),
	m_durabiliteInitiale(durabilite)
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

void CMelee::SetDurabilite(int durabilite)
{
	m_durabilite = durabilite;
}

float CMelee::GetSpecial()
{
	return m_durabiliteInitiale;
}

void CMelee::print()
{
}
