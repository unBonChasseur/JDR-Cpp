#include "CMage.h"

CMage::CMage():CCharacter()
{
	m_mana = 0;
	m_manaBase = 0;
	m_CDsoin = 0;
	m_CDenchantement = 0;
	m_classe = "Mage";
}

CMage::CMage(std::string nom, int vie, CWeapon* weapon, float esquive, int vitesse, int attaque, int defense, int agilite, int intelligence) :
	CCharacter(nom, vie, weapon, esquive, vitesse, attaque, defense, agilite, intelligence),
	m_mana(intelligence * 10),
	m_manaBase(intelligence * 10),
	m_CDenchantement(0),
	m_CDsoin(0)
{
	m_classe = "Mage";
}

CMage::~CMage()
{
}

void CMage::AttaquerAvecArme(CCharacter* cible)
{
	if (!cible->Esquiver()) {
		float coeff = 0.85 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (1.0 - 0.85)));
		int p_degats = 5 * (((float)m_intelligence + (float)m_weapon->CalculerDegats()) / (float)cible->GetDefense()) * coeff;																						//on transforme les dégats en valeur négative
		cible->SetVie(-p_degats);
		std::cout << "\nL'adversaire prend " << p_degats << " points de degats.";
	}
	else {
		std::cout << "\n" << cible->GetNom() << " a esquive.";
	}
}

int CMage::GetManaBase()
{
	return m_manaBase;
}

int CMage::GetMana()
{
	return m_mana;
}

int CMage::GetCDSoin()
{
	return m_CDsoin;
}

int CMage::GetCDEnchantement()
{
	return m_CDenchantement;
}

void CMage::RegenererMana()
{
	int randNum = rand() % (7 - 2 + 1) + 2;
	m_mana += randNum;
	if (m_mana > m_manaBase)
		m_mana = m_manaBase;
}

void CMage::Soigner(CCharacter* cible)
{
	m_mana -= 5;
	int randNum = rand() % (20 - 10 + 1) + 10;
	cible->SetVie(cible->GetVie() + randNum);
	std::cout << "\nVotre personnage " << cible->GetNom() << " a été soigné de "<< randNum << " points de vie.";
	m_CDsoin = 4;
}

void CMage::Enchanter(CCharacter* cible)
{
	m_mana -= 7;
	//cible->m_weapon;
	m_CDenchantement = 3;
}

void CMage::Print()
{
	std::cout << "\n\tClasse mage";
	std::cout << "\n\t\tNom : " << m_nom;
	std::cout << "\n\t\tVie : " << m_vie << "/" << m_vieBase;
	std::cout << "\n\t\tEsquive : " << m_esquive;
	std::cout << "\n\t\tVitesse : " << m_vitesseBase;
	std::cout << "\n\t\tAttaque : " << m_attaque;
	std::cout << "\n\t\tDefense : " << m_defense;
	std::cout << "\n\t\tAgilite : " << m_agilite;
	std::cout << "\n\t\tIntelligence : " << m_intelligence;
	std::cout << "\n\t\tMana : " << m_mana << "/" << m_manaBase;
	if (m_weapon == nullptr)
		std::cout << "\n\t\tArme equipee : Aucune";

	else {
		std::cout << "\n\t\tArme equipee : \n";
		m_weapon->print();
	}
}

void CMage::DebuterTour()
{
	if (m_empoisonne == 1) {
		float p_degats = (float)m_vieBase / 12;
		m_vie -= p_degats;
		std::cout << "\nVotre personnage vient de perdre " << p_degats << " points de vie du fait de son empoisonnement.";
	}
	if (m_CDenchantement >= 1) {
		m_CDenchantement--;
		if (m_CDenchantement == 0) {
			std::cout << "\nVous pouvez de nouveau utiliser l'enchantement d'une arme de melee si vous le souhaitez.";
		}
		else {
			std::cout << "\nL'enchantement d'une arme de melee sera de nouveau utilisable dans " << m_CDenchantement << " tour(s).";
		}
	}
	if (m_CDsoin >= 1) {
		m_CDsoin--;
		if (m_CDsoin == 0) {
			std::cout << "\nVous pouvez de nouveau utiliser le soin sur un de vos personnages si vous le souhaitez.";
		}
		else {
			std::cout << "\nLe soin d'un personnage sera de nouveau utilisable dans " << m_CDsoin << " tour(s).";
		}
	}

}