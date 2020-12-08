#include "CRanged.h"

CRanged::CRanged():CWeapon()
{
}

CRanged::CRanged(std::string type, std::string nom, int degats, float critique, float bonus, int vie, float esquive, int vitesseBase, int attaque, int defense, int agilite, int intelligence):
	CWeapon(type, nom, degats, critique, bonus, vie, esquive, vitesseBase, attaque, defense, agilite, intelligence)
{
}

void CRanged::print()
{
	std::cout << "\n\nclasse CWeapon";
	std::cout << "\ntype : " << m_type;
	std::cout << "\nnom : " << m_nom;
	std::cout << "\nDegats : " << m_degats;
	std::cout << "\nCritique : " << m_critique;
	std::cout << "\nBonus : " << m_bonusDegatsArme;
	std::cout << "\nVie : " << m_vie;
	std::cout << "\nEsquive : " << m_esquive;
	std::cout << "\nVitesse : " << m_vitesseBase;
	std::cout << "\nattaque : " << m_attaque;
	std::cout << "\ndefense : " << m_defense;
	std::cout << "\nagilite : " << m_agilite;
	std::cout << "\nintelligence : " << m_intelligence;
}
