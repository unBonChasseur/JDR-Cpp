#include "CMage.h"

CMage::CMage():CCharacter()
{
	m_mana = 0;
	m_manaMax = 0;
	m_CDsoin = 0;
	m_CDenchantement = 0;
}

CMage::CMage(std::string nom, int vie,  float esquive, int vitesseBase, int attaque, int defense, int agilite, int intelligence) :
	CCharacter(nom, vie, esquive, vitesseBase, attaque, defense, agilite, intelligence),
	m_mana(intelligence * 10),
	m_manaMax(intelligence*10),
	m_CDenchantement(0),
	m_CDsoin(0)
{

}

CMage::~CMage()
{
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
	std::cout << "\n\nclasse CMage";
	std::cout << "\nnom : " << m_nom;
	std::cout << "\nVie : " << m_vie;
	std::cout << "\nEsquive : " << m_esquive;
	std::cout << "\nVitesse : " << m_vitesseBase;
	std::cout << "\nattaque : " << m_attaque;
	std::cout << "\ndefense : " << m_defense;
	std::cout << "\nagilite : " << m_agilite;
	std::cout << "\nintelligence : " << m_intelligence;
}
