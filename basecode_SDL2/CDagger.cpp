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
	std::cout << "\n\nclasse CDagger";
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
	std::cout << "\nDurabiilite : " << m_durabilite;
}
