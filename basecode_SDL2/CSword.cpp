#include "CSword.h"

CSword::CSword():CMelee()
{
}

void CSword::Utiliser()
{
	int durabilitePerdue = rand() % (5 - 2 + 1) + 2;
	m_durabilite -= durabilitePerdue;
	std::cout << "\nVotre arme a perdu " << durabilitePerdue << " points de durabilite.";
	if (m_durabilite <= 0) {
		m_durabilite = 0;
		std::cout << "\nVotre arme viens de se briser avec ce coup, faites la reparer ou vous infligerez 10 fois moins de degats lors votre prochain coup.";
	}
	else {
		std::cout << "\nIl reste " << m_durabilite << " points de durabilite a votre arme. (/" << m_durabiliteBase << ").";
	}
}

CSword::CSword(std::string type, std::string nom, int degats, float critique, int vie, float esquive, int vitesse, int attaque, int defense, int agilite, int intelligence, int durabilite)
	:CMelee(type, nom, degats, critique, vie, esquive, vitesse, attaque, defense, agilite, intelligence, durabilite)
{
}

void CSword::print()
{
	std::cout << "\n\tClasse : " << m_type;
	std::cout << "\n\t\tNom : " << m_nom;
	std::cout << "\n\t\tDegats : " << m_degats;
	std::cout << "\n\t\tCritique : " << m_critique;
	std::cout << "\n\t\tEnchantement : " << m_enchantement << " (=multiplicateur de degats)";
	std::cout << "\n\t\tDurabilite : " << m_durabilite << "/" << m_durabiliteBase;

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