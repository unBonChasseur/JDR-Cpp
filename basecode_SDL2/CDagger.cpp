#include "CDagger.h"

CDagger::CDagger():CMelee()
{
}

CDagger::CDagger(std::string type, std::string nom, int degats, float critique, float bonus, int vie, float esquive, int vitesseBase, int attaque, int defense, int agilite, int intelligence, int durabilite)
	:CMelee(type, nom, degats, critique, bonus, vie, esquive, vitesseBase, attaque, defense, agilite, intelligence, durabilite)
{
}

void CDagger::print()
{
	std::cout << "\n\n\tClasse Dague";
	std::cout << "\n\t\tType : " << m_type;
	std::cout << "\n\t\tNom : " << m_nom;
	std::cout << "\n\t\tDegats : " << m_degats;
	std::cout << "\n\t\tCritique : " << m_critique;
	std::cout << "\n\t\tDurabilite : " << m_durabilite;

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
