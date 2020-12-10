#include "CArcher.h"

CArcher::CArcher()
{
}

CArcher::CArcher(std::string nom, int vie, CWeapon* weapon, float esquive, int vitesseBase, int attaque, int defense, int agilite, int intelligence)
	:CCharacter(nom, vie, weapon, esquive, vitesseBase, attaque, defense, agilite, intelligence)
{
}

CArcher::~CArcher()
{
}

void CArcher::GuerirPoison()
{
}

void CArcher::Viser()
{
}

void CArcher::print()
{
	std::cout << "\n\tClasse archer";
	std::cout << "\n\t\tNom : " << m_nom;
	std::cout << "\n\t\tVie : " << m_vie;
	std::cout << "\n\t\tEsquive : " << m_esquive;
	std::cout << "\n\t\tVitesse : " << m_vitesseBase;
	std::cout << "\n\t\tAttaque : " << m_attaque;
	std::cout << "\n\t\tDefense : " << m_defense;
	std::cout << "\n\t\tAgilite : " << m_agilite;
	std::cout << "\n\t\tIntelligence : " << m_intelligence;
}
