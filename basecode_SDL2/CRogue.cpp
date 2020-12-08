#include "CRogue.h"

CRogue::CRogue():CCharacter()
{
	m_nbToursFurtif = 0;
	m_CDFurtif = 0;
	m_poison = 0;
}

CRogue::CRogue(std::string nom, int vie, float esquive, int vitesseBase, int attaque, int defense, int agilite, int intelligence, float poison)
	:CCharacter(nom, vie, esquive, vitesseBase, attaque, defense, agilite, intelligence),
	m_nbToursFurtif(0),
	m_CDFurtif(0),
	m_poison(poison)
{

}

CRogue::~CRogue()
{
}

void CRogue::AttaquerAvecArme()
{
}

void CRogue::Furtivite()
{

}

void CRogue::print()
{
	std::cout << "\n\nclasse CRogue";
	std::cout << "\nnom : " << m_nom;
	std::cout << "\nVie : " << m_vie;
	std::cout << "\nEsquive : " << m_esquive;
	std::cout << "\nVitesse : " << m_vitesseBase;
	std::cout << "\nattaque : " << m_attaque;
	std::cout << "\ndefense : " << m_defense;
	std::cout << "\nagilite : " << m_agilite;
	std::cout << "\nintelligence : " << m_intelligence;
}
