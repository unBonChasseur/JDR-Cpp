#include "CStaff.h"

CStaff::CStaff():CRanged()
{
	m_cout = 0;
}

CStaff::CStaff(std::string type, std::string nom, int degats, float critique, int vie, float esquive, int vitesse, int attaque, int defense, int agilite, int intelligence, int cout)
	: CRanged(type, nom, degats, critique, vie, esquive, vitesse, attaque, defense, agilite, intelligence),
	m_cout(cout)
{
}

int CStaff::GetCout()
{
	return m_cout;
}

void CStaff::print()
{
	std::cout << "\n\tClasse : " << m_type;
	std::cout << "\n\t\tNom : " << m_nom;
	std::cout << "\n\t\tDegats : " << m_degats;
	std::cout << "\n\t\tCritique : " << m_critique;
	std::cout << "\n\t\tEnchantement : " << m_enchantement << " (=multiplicateur de degats)";
	std::cout << "\n\t\tCout : " << m_cout;

	std::cout << "\n\n\tBuffs/Debuffs statistiques du porteur :";
	if (m_vie != 0)
		std::cout << "\n\t\tVie : " << m_vie;

	if (m_esquive != 0)
		std::cout << "\n\t\tEsquive : " << m_esquive;

	if (m_vitesse != 0)
		std::cout << "\n\t\tVitesse : " << m_vitesse;

	if (m_attaque != 0)
		std::cout << "\n\t\tAttaque : " << m_attaque;

	if (m_defense != 0)
		std::cout << "\n\t\tDefense : " << m_defense;

	if (m_agilite != 0)
		std::cout << "\n\t\tAgilite : " << m_agilite;

	if (m_intelligence != 0)
		std::cout << "\n\t\tIntelligence : " << m_intelligence;
}
