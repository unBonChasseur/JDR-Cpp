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
	std::cout << "\n\tClasse Arc";
	std::cout << "\n\t\tType : " << m_type;
	std::cout << "\n\t\tNom : " << m_nom;
	std::cout << "\n\t\tDegats : " << m_degats;
	std::cout << "\n\t\tCritique : " << m_critique;
	std::cout << "\n\t\Nombre de fleches : " << m_nbFlechesBase;

	std::cout << "\n\tBuffs/Debuffs statistiques du porteur :";
	if (m_vie != 0)
		std::cout << "\n\t\tVie : " << m_vie;

	if (m_esquive != 0)
		std::cout << "\n\t\tEsquive : " << m_esquive;

	if (m_vitesseBase != 0)
		std::cout << "\n\t\tVitesse : " << m_vitesseBase;

	if (m_attaque != 0)
		std::cout << "\n\t\tAttaque : " << m_attaque;

	if (m_defense != 0)
		std::cout << "\n\t\tDefense : " << m_defense;

	if (m_agilite != 0)
		std::cout << "\n\t\tAgilite : " << m_agilite;

	if (m_intelligence != 0)
		std::cout << "\n\t\tIntelligence : " << m_intelligence;
}