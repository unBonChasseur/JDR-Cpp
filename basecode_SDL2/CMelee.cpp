#include "CMelee.h"

CMelee::CMelee():CWeapon()
{
	m_durabilite = 0;
	m_durabiliteInitiale = 0;
}

CMelee::CMelee(std::string type, std::string nom, int degats, float critique, float bonus, int durabilite)
	:CWeapon(type, nom, degats, critique, bonus), 
	m_durabilite(durabilite),
	m_durabiliteInitiale(durabilite)
{
}

CMelee::~CMelee()
{
}
