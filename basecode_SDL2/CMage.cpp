#include "CMage.h"

CMage::CMage():CCharacter()
{
	m_mana = 0;
	m_manaMax = 0;
	m_CDsoin = 0;
	m_CDenchantement = 0;
}

CMage::CMage(std::string nom, int vie, CWeapon* weapon, float esquive, int vitesseBase, int attaque, int defense, int agilite, int intelligence) :
	CCharacter(nom, vie, weapon, esquive, vitesseBase, attaque, defense, agilite, intelligence),
	m_mana(intelligence * 10),
	m_manaMax(intelligence * 10),
	m_CDenchantement(0),
	m_CDsoin(0)
{
	m_classe = "Mage";
}

CMage::~CMage()
{
}

float CMage::GetCaracPartic()
{
	return m_mana;
}

void CMage::RegenererMana()
{
	int randNum = rand() % (7 - 2 + 1) + 2;
	m_mana += randNum;
	if (m_mana > m_manaMax)
		m_mana = m_manaMax;
}

void CMage::Soigner(CCharacter CCharacter)
{
	m_mana -= 5;
	int randNum = rand() % (20 - 10 + 1) + 10;
	CCharacter.SetVie(CCharacter.GetVie() + randNum);
	if (CCharacter.GetVie() > CCharacter.GetVieInitiale())
		CCharacter.SetVie(CCharacter.GetVieInitiale());
	m_CDsoin = 4;
}

void CMage::Enchanter(CCharacter CCharacter)
{
	m_mana -= 7;

	m_CDenchantement = 3;
}

void CMage::print()
{
	std::cout << "\n\tClasse mage";
	std::cout << "\n\t\tNom : " << m_nom;
	std::cout << "\n\t\tVie : " << m_vie;
	std::cout << "\n\t\tEsquive : " << m_esquive;
	std::cout << "\n\t\tVitesse : " << m_vitesseBase;
	std::cout << "\n\t\tAttaque : " << m_attaque;
	std::cout << "\n\t\tDefense : " << m_defense;
	std::cout << "\n\t\tAgilite : " << m_agilite;
	std::cout << "\n\t\tIntelligence : " << m_intelligence;
	std::cout << "\n\t\tMana : " << m_mana;
	if (m_weapon == nullptr)
		std::cout << "\n\t\tArme equipee : Aucune";

	else {
		std::cout << "\n\t\tArme equipee : \n";
		m_weapon->print();
	}
}
