#include "CArcher.h"

CArcher::CArcher():CCharacter()
{
	m_classe = "Archer";
	m_nbGuerison = 3;
	m_visee = 1;
}

CArcher::CArcher(std::string nom, int vie, CWeapon* weapon, float esquive, int vitesse, int attaque, int defense, int agilite, int intelligence)
	:CCharacter(nom, vie, weapon, esquive, vitesse, attaque, defense, agilite, intelligence)
{
	m_classe = "Archer";
	m_nbGuerison = 3;
	m_visee = 1;
}

CArcher::~CArcher()
{
}

int CArcher::AttaquerAvecArme(CCharacter* cible)
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
				float p_degats = (((float)m_agilite * m_visee + (float)m_weapon->CalculerDegats()) / (float)cible->GetDefense()) * coeff * 9;
				m_visee = 1;
				cible->SetVie(-p_degats);
				std::cout << "\nL'adversaire prend " << p_degats << " points de degats.";
			}
			else {
				std::cout << "\n" << cible->GetNom() << " a esquive.";
			}
		}
	}
	return 1;
}

int CArcher::GetNbGuerison()
{
	return m_nbGuerison;
}

void CArcher::GuerirPoison(CCharacter* allie)
{
	allie->SetPoison(0);
	m_nbGuerison--;
	std::cout << "\nVous venez de guérir votre allié " << allie->GetNom() << ".\nCe personnage pourra encore utiliser sa capacite de guerison " << m_nbGuerison << " fois.";
}

void CArcher::Viser()
{
	m_visee += 0.33;
	std::cout << "\nVotre prochaine fleche infligera 33% de dégats en plus soit au total " << m_visee;
}

void CArcher::Print()
{
	std::cout << "\n\tClasse archer";
	std::cout << "\n\t\tNom : " << m_nom;
	std::cout << "\n\t\tVie : " << m_vie << "/" << m_vieBase;
	std::cout << "\n\t\tEsquive : " << m_esquive;
	std::cout << "\n\t\tVitesse : " << m_vitesse << "/" << m_vitesseBase;
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
