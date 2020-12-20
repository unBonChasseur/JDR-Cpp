#include "CWarrior.h"

CWarrior::CWarrior():CCharacter()
{
	m_CDHurlement = 0;
	m_parade = 0;
	m_nbToursHurlement = 0;
	m_classe = "Guerrier";
}

CWarrior::CWarrior(std::string nom, int vie, CWeapon* weapon, float esquive, int vitesse, int attaque, int defense, int agilite, int intelligence, float parade)
	:CCharacter(nom, vie, weapon, esquive, vitesse, attaque, defense, agilite, intelligence),
	m_CDHurlement(0),
	m_parade(parade),
	m_nbToursHurlement(0)
{
	m_classe = "Guerrier";
}

CWarrior::~CWarrior()
{
}

float CWarrior::GetParade()
{
	return m_parade;
}

int CWarrior::GetNbToursHurlement()
{
	return m_nbToursHurlement;
}

int CWarrior::GetCDHurlement()
{
	return m_CDHurlement;
}

void CWarrior::DebuterTour()
{
	if (m_empoisonne == 1) {
		float p_degats = (float)m_vieBase / 12;
		m_vie -= p_degats;
		std::cout << "\nVotre personnage vient de perdre " << p_degats << " points de vie du fait de son empoisonnement.";
	}
	if (m_nbToursHurlement >= 1) {
		m_nbToursHurlement--;
		if (m_nbToursHurlement == 0) {
			std::cout << "\nLe hurlement de votre personnage n'est plus actif, vos autres personnages pourront donc être ciblés à nouveau.";
		}
		else {
			std::cout << "\nLe hurlement de votre personnage est encore actif pour " << m_nbToursHurlement << " tour(s).";
		}
	}
	if (m_CDHurlement >= 1) {
		m_CDHurlement--;
		if (m_CDHurlement == 0) {
			std::cout << "\nVous pouvez de nouveau utiliser le hurlement de votre personnage si vous le souhaitez.";
		}
		else {
			std::cout << "\nLe hurlement de votre personnage sera de nouveau utilisable dans " << m_CDHurlement << " tour(s).";
		}
	}
	
}

void CWarrior::AttaquerAvecArme(CCharacter* cible)
{
	if (!cible->Esquiver()) {																				
		float coeff = 0.85 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (1.0 - 0.85)));
		int p_degats = 7 * (((float)m_attaque + (float)m_weapon->CalculerDegats()) / (float)cible->GetDefense()) * coeff;
		cible->SetVie(-p_degats);		
		std::cout << "\nL'adversaire prend " << p_degats << " points de dégat.";
	}
	else {
		std::cout << "\n" << cible->GetNom() << " a esquive.";												
	}
}

int CWarrior::Esquiver()
{
	float randEsquive = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	if (m_weapon->GetType() == "Epee")
		return randEsquive <= m_esquive + m_parade;

	return randEsquive <= m_esquive;
}

void CWarrior::Hurler()
{
	m_CDHurlement = 4;
	int randNum = rand() % (2 - 1 + 1) + 1;
	m_nbToursHurlement = randNum;
	std::cout << "\nVotre guerrier " << m_nom << " viens de hurler et va donc catalyser toutes les attaques adverses pour " << randNum << " tours.";
}

void CWarrior::ReparerArme(CCharacter* allie)
{
	CMelee* arme = dynamic_cast<CMelee*>(allie->GetWeapon());
	arme->Reparer();
}

void CWarrior::Print()
{
	std::cout << "\n\tClasse guerrier";
	std::cout << "\n\t\tNom : " << m_nom;
	std::cout << "\n\t\tVie : " << m_vie << "/" << m_vieBase;
	std::cout << "\n\t\tEsquive : " << m_esquive;
	std::cout << "\n\t\tVitesse : " << m_vitesseBase;
	std::cout << "\n\t\tAttaque : " << m_attaque;
	std::cout << "\n\t\tDefense : " << m_defense;
	std::cout << "\n\t\tAgilite : " << m_agilite;
	std::cout << "\n\t\tIntelligence : " << m_intelligence;
	std::cout << "\n\t\tParade : " << m_parade;
	if (m_weapon == nullptr) 
		std::cout << "\n\t\tArme equipee : Aucune";
	
	else {
		std::cout << "\n\t\tArme equipee : \n";
		m_weapon->print();
	}
}
