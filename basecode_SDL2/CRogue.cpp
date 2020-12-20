#include "CRogue.h"

CRogue::CRogue():CCharacter()
{
	m_nbToursFurtif = 0;
	m_CDFurtif = 0;
	m_poison = 0;
	m_classe = "Voleur";
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
	m_classe = "Voleur";
}

CRogue::~CRogue()
{
}

int CRogue::AttaquerAvecArme(CCharacter* cible)
{
	if (m_weapon->GetType() == "Arc") {
		CBow* ptrWeapon = dynamic_cast<CBow*>(m_weapon);
		if (ptrWeapon->GetNbFleches() == 0) {
			std::cout << "\nVous n'avez plus de fleches et allez donc en recuperer sur le champ de bataille.";
			ptrWeapon->RecupererFleches();
		}
		else {
			if (!cible->Esquiver()) {
				float coeff = 0.85 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (1.0 - 0.85)));
				float p_degats = (((float)m_agilite + (float)m_weapon->CalculerDegats()) / (float)cible->GetDefense()) * coeff * 7;
				cible->SetVie(-p_degats);
				std::cout << "\nL'adversaire prend " << p_degats << " points de degats.";
			}
			else {
				std::cout << "\n" << cible->GetNom() << " a esquive.";
			}
		}
	}
	else {
		if (!cible->Esquiver()) {
			float coeff = 0.85 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (1.0 - 0.85)));
			float p_degats = (((float)m_agilite + (float)m_weapon->CalculerDegats()) / (float)cible->GetDefense()) * coeff * 7;
			cible->SetVie(-p_degats);
			std::cout << "\nL'adversaire prend " << p_degats << " points de degats.";
			if (Empoisonner() && cible->GetClasse() != "Archer") {
				cible->SetPoison(1);
				std::cout << "\nVotre coup a empoisonne l'adversaire !   (Il perdra 1/12e de ses points de vie par tour)";
			}
		}
	}
	return 1;
}

float CRogue::GetPoison()
{
	return m_poison;
}

int CRogue::GetNbToursFurtif()
{
	return m_nbToursFurtif;
}

int CRogue::GetCDFurtif()
{
	return m_CDFurtif;
}

void CRogue::Furtivite()
{
	m_CDFurtif = 4;
	int randNum = rand() % (2 - 1 + 1) + 1;
	m_nbToursFurtif = randNum;
	std::cout << "\nVotre voleur " << m_nom << " viens de se camoufler et va donc se derober a toutes les attaques adverses pour " << randNum << " tours.";
}

void CRogue::Print()
{
	std::cout << "\n\tClasse voleur";
	std::cout << "\n\t\tNom : " << m_nom;
	std::cout << "\n\t\tVie : " << m_vie << "/" << m_vieBase;
	std::cout << "\n\t\tEsquive : " << m_esquive;
	std::cout << "\n\t\tVitesse : " << m_vitesse << "/" << m_vitesseBase;
	std::cout << "\n\t\tAttaque : " << m_attaque;
	std::cout << "\n\t\tDefense : " << m_defense;
	std::cout << "\n\t\tAgilite : " << m_agilite;
	std::cout << "\n\t\tIntelligence : " << m_intelligence;
	std::cout << "\n\t\tProbabilite empoisonnement : " << m_poison << "/1";
	std::cout << "\n\n\t\tNombre de tours furtif restant : " << m_nbToursFurtif << " (" << m_CDFurtif << " tour(s) avant reutilisation).";
	std::cout << "\n\t\tEst empoisonne ? " << m_empoisonne << " (1 = oui; 0 = non)";
	
	if (m_weapon == nullptr)
		std::cout << "\n\n\t\tArme equipee : Aucune";

	else {
		std::cout << "\n\n\tArme equipee : ";
		m_weapon->print();
	}
}

void CRogue::DebuterTour()
{
	if (m_empoisonne == 1) {
		float p_degats = (float)m_vieBase / 12;
		m_vie -= p_degats;
		std::cout << "\nVotre personnage vient de perdre " << p_degats << " points de vie du fait de son empoisonnement.";
	}
	if (m_nbToursFurtif >= 1) {
		m_nbToursFurtif--;
		if (m_nbToursFurtif == 0) {
			std::cout << "\nLe camouflage de votre personnage n'est plus actif, vos autres personnages pourront donc être ciblés à nouveau.";
		}
		else {
			std::cout << "\nLe camoulage de votre personnage est encore actif pour " << m_nbToursFurtif << " tour(s).";
		}
	}
	if (m_CDFurtif >= 1) {
		m_CDFurtif--;
		if (m_CDFurtif == 0) {
			std::cout << "\nVous pouvez de nouveau utiliser le camouflage de votre personnage si vous le souhaitez.";
		}
		else {
			std::cout << "\nLe camouflage de votre personnage sera de nouveau utilisable dans " << m_CDFurtif << " tour(s).";
		}
	}
}

void CRogue::Reinitialiser()
{
	m_weapon->Reinitialiser();
	m_vie = m_vieBase;
	m_vitesse = m_vitesseBase;
	m_nbToursFurtif = 0;
	m_CDFurtif = 0;
}
