#include "CBow.h"

CBow::CBow():CRanged()
{
	m_nbFleches = 0;
	m_nbFlechesBase = 0;
}

CBow::CBow(std::string type, std::string nom, int degats, float critique, int vie, float esquive, int vitesse, int attaque, int defense, int agilite, int intelligence, int nbFleches)
	:CRanged(type, nom, degats, critique, vie, esquive, vitesse, attaque, defense, agilite, intelligence),
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

float CBow::CalculerDegats()
{
	float p_degats;

	p_degats = (float)m_degats;
	if (CoupCritique()) {
		std::cout << "\nVous utiliser votre arme a son meilleur potentiel, elle va faire deux fois plus mal.";
		p_degats *= 2;
	}
	Utiliser();
	return p_degats;
}

void CBow::RecupererFleches()
{
	int nbFleches = rand() % (3 - 1 + 1) + 1;
	m_nbFleches = nbFleches;
	std::cout << "\nVous avez recupere " << nbFleches << " sur le champ de bataille et les remettez dans votre carquois.";
}

void CBow::Utiliser()
{
	std::cout << "\nVotre arme a perdu 1 fleche.";
	if (m_nbFleches != 0) {
		m_nbFleches--;
	}
}

void CBow::Reinitialiser()
{
	m_nbFleches = m_nbFlechesBase;
}

void CBow::print()
{
	std::cout << "\n\tClasse : " << m_type;
	std::cout << "\n\t\tNom : " << m_nom;
	std::cout << "\n\t\tDegats : " << m_degats;
	std::cout << "\n\t\tCritique : " << m_critique;
	std::cout << "\n\t\tNombre de Fleches : " << m_nbFleches << "/" << m_nbFlechesBase;

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