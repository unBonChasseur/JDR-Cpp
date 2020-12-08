#include "CBow.h"

CBow::CBow():CRanged()
{
	m_nbFleches = 0;
	m_nbFlechesBase = 0;
}

CBow::CBow(std::string type, std::string nom, int degats, float critique, float bonus, int vie, float esquive, int vitesseBase, int attaque, int defense, int agilite, int intelligence, int nbFleches)
	:CRanged(type, nom, degats, critique, bonus, vie, esquive, vitesseBase, attaque, defense, agilite, intelligence),
	m_nbFleches(nbFleches),
	m_nbFlechesBase(nbFleches)
{
}

int CBow::GetNbFleches()
{
	return m_nbFleches;
}

int CBow::GetNbFlechesBase()
{
	return m_nbFlechesBase;
}

void CBow::SetNbFleches(int nbFleches)
{
	m_nbFleches += nbFleches;
}

void CBow::print()
{
	std::cout << "\n\nclasse CBow";
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
	std::cout << "\nnbFleches :" << m_nbFleches;
}