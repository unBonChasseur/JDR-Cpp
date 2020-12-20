#include "CMelee.h"

CMelee::CMelee():CWeapon()
{
	m_durabilite = 0;
	m_durabiliteInitiale = 0;
	m_enchantee = 1;
}

void CMelee::Utiliser()
{
}

CMelee::CMelee(std::string type, std::string nom, int degats, float critique, int vie, float esquive, int vitesse, int attaque, int defense, int agilite, int intelligence, int durabilite)
	:CWeapon(type, nom, degats, critique, vie, esquive, vitesse, attaque, defense, agilite, intelligence),
	m_durabilite(durabilite),
	m_durabiliteInitiale(durabilite)
{
	m_enchantee = 1;
}

int CMelee::GetDurabiliteInitiale()
{
	return m_durabiliteInitiale;
}

int CMelee::GetDurabilite()
{
	return m_durabilite;
}

float CMelee::CalculerDegats()
{
	float p_degats;
	if (m_durabilite == 0) {
		std::cout << "\nVotre arme est brisee, elle infligera donc 10 fois moins de degats.\nPensez a vite la reparer.";
		p_degats = (float)m_degats / 10;
	}
	else {
		p_degats = (float)m_degats;
		if (CoupCritique()) {
			std::cout << "\nVous utiliser votre arme a son meilleur potentiel, elle va faire deux fois plus mal.";
			p_degats *= 2;
		}
		Utiliser();
	}
	if (m_enchantee != 1) {
		p_degats *= m_enchantee;
		std::cout << "\nL'arme inflige " << m_enchantee << " fois plus de degats du fait de son enchantement.";
		m_enchantee = 1;
	}

	return p_degats;
}

void CMelee::Reparer()
{
	if (m_durabilite==0) {
		m_durabilite = 1;
		std::cout << "\nVotre arme etait cassee avant que vous ne la repariez. ";
	}
	else {
		int randDurabilite = rand() % (15 - 3 + 1) + 3;
		m_durabilite += randDurabilite;
		if (m_durabilite > m_durabiliteInitiale) {
			m_durabilite = m_durabiliteInitiale;
			std::cout << "\nVotre arme a ete completement reparee et dispose donc de " << m_durabilite << " points de durabilite.";
		}
		else {
			std::cout << "\nVotre arme a ete reparee de " << randDurabilite << " et a donc " << m_durabilite << "points de durabilite. (/"<< m_durabiliteInitiale << ").";
		}
	}
}

void CMelee::print()
{
}
