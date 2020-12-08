#include "CArcher.h"

CArcher::CArcher()
{
}

CArcher::CArcher(std::string nom, int vie, float esquive, int vitesseBase, int attaque, int defense, int agilite, int intelligence)
	:CCharacter(nom, vie, esquive, vitesseBase, attaque, defense, agilite, intelligence)
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
	std::cout << "\n\nclasse CArcher";
	std::cout << "\nnom : " << m_nom;
	std::cout << "\nVie : " << m_vie;
	std::cout << "\nEsquive : " << m_esquive;
	std::cout << "\nVitesse : " << m_vitesseBase;
	std::cout << "\nattaque : " << m_attaque;
	std::cout << "\ndefense : " << m_defense;
	std::cout << "\nagilite : " << m_agilite;
	std::cout << "\nintelligence : " << m_intelligence;
}
