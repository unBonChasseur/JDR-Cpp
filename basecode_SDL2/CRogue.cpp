#include "CRogue.h"

CRogue::CRogue():CCharacter()
{
	m_nbToursFurtif = 0;
	m_CDFurtif = 0;
	m_poison = 0;
}

CRogue::CRogue(std::string nom, int vie, CWeapon* weapon, float esquive, int vitesse, int attaque, int defense, int agilite, int intelligence, float poison)
	:CCharacter(nom, vie, weapon, esquive, vitesse, attaque, defense, agilite, intelligence),
	m_nbToursFurtif(0),
	m_CDFurtif(0),
	m_poison(poison)
{
}

CRogue::~CRogue()
{
}

std::string CRogue::GetClasse()
{
	return "Voleur";
}

float CRogue::GetCaracPartic()
{
	return m_poison;
}

void CRogue::AttaquerAvecArme()
{
}

void CRogue::Furtivite()
{

}

void CRogue::Print()
{
	std::cout << "\n\tClasse voleur";
	std::cout << "\n\t\tNom : " << m_nom;
	std::cout << "\n\t\tVie : " << m_vie;
	std::cout << "\n\t\tEsquive : " << m_esquive;
	std::cout << "\n\t\tVitesse : " << m_vitesseBase;
	std::cout << "\n\t\tAttaque : " << m_attaque;
	std::cout << "\n\t\tDefense : " << m_defense;
	std::cout << "\n\t\tAgilite : " << m_agilite;
	std::cout << "\n\t\tIntelligence : " << m_intelligence;
	std::cout << "\n\t\tProbabilite empoisonnement : " << m_poison << "/1";
	if (m_weapon == nullptr)
		std::cout << "\n\t\tArme equipee : Aucune";

	else {
		std::cout << "\n\t\tArme equipee : \n";
		m_weapon->print();
	}
}
