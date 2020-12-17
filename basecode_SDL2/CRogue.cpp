#include "CRogue.h"

CRogue::CRogue():CCharacter()
{
	m_nbToursFurtif = 0;
	m_CDFurtif = 0;
	m_poison = 0;
}

int CRogue::Empoisonner()
{
	float randPoison = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	return randPoison < m_poison;
}

CRogue::CRogue(std::string nom, int vie, CWeapon* weapon, float esquive, int vitesse, int attaque, int defense, int agilite, int intelligence, float poison)
	:CCharacter(nom, vie, weapon, esquive, vitesse, attaque, defense, agilite, intelligence),
	m_nbToursFurtif(0),
	m_CDFurtif(0),
	m_poison(poison)
{
}

CRogue::~CRogue()
{
}

std::string CRogue::GetClasse()
{
	return "Voleur";
}

float CRogue::GetCaracPartic()
{
	return m_poison;
}

void CRogue::AttaquerAvecArme(CCharacter* ccharacter)
{
	if (!ccharacter->Esquiver()) {																				//Si l'esquive adverse échoue ( inférieure au nombre random tiré au dessus
		float coeff = 0.85 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (1.0 - 0.85)));	//calcul du coeff
		int p_degats = 7 * ((m_agilite + m_weapon->GetDegats()) / ccharacter->GetDefense()) * coeff;			//calcul des dégats																				//on transforme les dégats en valeur négative
		ccharacter->SetVie(-p_degats);																			//on inflige les dégats à l'adversaire
		std::cout << "\nL'adversaire prend " << p_degats << " points de dégat.";
		if (m_weapon->GetType() == "Dague" && Empoisonner()) {
			ccharacter->SetPoison(1);
			std::cout << "\nVotre coup a empoisonné l'adversaire !   (Il perdra 1/12e de ses pv par tour)";
		}
	}
	else {
		std::cout << "\n" << ccharacter->GetNom() << " a esquive.";												//on informe l'utilisateur que l'adversaire a esquivé
	}
}

void CRogue::Furtivite()
{

}

void CRogue::Print()
{
	std::cout << "\n\tClasse voleur";
	std::cout << "\n\t\tNom : " << m_nom;
	std::cout << "\n\t\tVie : " << m_vie;
	std::cout << "\n\t\tEsquive : " << m_esquive;
	std::cout << "\n\t\tVitesse : " << m_vitesseBase;
	std::cout << "\n\t\tAttaque : " << m_attaque;
	std::cout << "\n\t\tDefense : " << m_defense;
	std::cout << "\n\t\tAgilite : " << m_agilite;
	std::cout << "\n\t\tIntelligence : " << m_intelligence;
	std::cout << "\n\t\tProbabilite empoisonnement : " << m_poison << "/1";
	if (m_weapon == nullptr)
		std::cout << "\n\t\tArme equipee : Aucune";

	else {
		std::cout << "\n\t\tArme equipee : \n";
		m_weapon->print();
	}
}
