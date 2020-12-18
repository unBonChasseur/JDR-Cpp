#include "CArcher.h"

CArcher::CArcher():CCharacter()
{
	m_classe = "Archer";
}

CArcher::CArcher(std::string nom, int vie, CWeapon* weapon, float esquive, int vitesse, int attaque, int defense, int agilite, int intelligence)
	:CCharacter(nom, vie, weapon, esquive, vitesse, attaque, defense, agilite, intelligence)
{
	m_classe = "Archer";
}

CArcher::~CArcher()
{
}

void CArcher::AttaquerAvecArme(CCharacter* ccharacter)
{
	if (!ccharacter->Esquiver()) {																				//Si l'esquive adverse échoue ( inférieure au nombre random tiré au dessus
		float coeff = 0.85 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (1.0 - 0.85)));	//calcul du coeff
		int p_degats = 9 * ((m_agilite + m_weapon->CalculerDegats()) / ccharacter->GetDefense()) * coeff;			//calcul des dégats																				//on transforme les dégats en valeur négative
		ccharacter->SetVie(-p_degats);																			//on inflige les dégats à l'adversaire
		std::cout << "\nL'adversaire prend " << p_degats << " points de dégat.";
	}
	else {
		std::cout << "\n" << ccharacter->GetNom() << " a esquive.";												//on informe l'utilisateur que l'adversaire a esquivé
	}
}

void CArcher::GuerirPoison()
{
}

void CArcher::Viser()
{
}

void CArcher::Print()
{
	std::cout << "\n\tClasse archer";
	std::cout << "\n\t\tNom : " << m_nom;
	std::cout << "\n\t\tVie : " << m_vie;
	std::cout << "\n\t\tEsquive : " << m_esquive;
	std::cout << "\n\t\tVitesse : " << m_vitesseBase;
	std::cout << "\n\t\tAttaque : " << m_attaque;
	std::cout << "\n\t\tDefense : " << m_defense;
	std::cout << "\n\t\tAgilite : " << m_agilite;
	std::cout << "\n\t\tIntelligence : " << m_intelligence;

	if (m_weapon == nullptr)
		std::cout << "\n\t\tArme equipee : Aucune";

	else {
		std::cout << "\n\t\tArme equipee : \n";
		m_weapon->print();
	}
}
