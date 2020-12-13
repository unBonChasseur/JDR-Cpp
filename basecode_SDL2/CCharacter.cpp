#include "CCharacter.h"

CCharacter::CCharacter()
{
	m_classe = "";
	m_nom = "";
	m_vie = 0;
	m_weapon = nullptr;
	m_esquive = 0;
	m_vitesseBase = 0;
	m_vitesse = 0;
	m_attaque = 0;
	m_defense = 0;
	m_agilite = 0;
	m_intelligence = 0;
	m_empoisonne = 0;
	m_bonusDegats = 0;
}

CCharacter::CCharacter(std::string nom, int vie, CWeapon* weapon, float esquive, int vitesseBase, int attaque, int defense, int agilite, int intelligence)
{
	m_classe = "";
	m_weapon = weapon;
	m_nom = nom;
	m_nom = nom;
	m_vie = vie;
	m_vieInitiale = vie;
	m_esquive = esquive;
	m_vitesseBase = vitesseBase;
	m_vitesse = vitesseBase;
	m_attaque = attaque;
	m_defense = defense;
	m_agilite = agilite;
	m_intelligence = intelligence;
	m_empoisonne = 0;
	m_bonusDegats = 0;

	if (weapon != nullptr) {
		
		m_vie += weapon->GetVie();
		m_vieInitiale += weapon->GetVie();
		m_esquive += weapon->GetEsquive();
		m_vitesseBase += weapon->GetVitesseBase();
		m_vitesse += weapon->GetVitesseBase();
		m_attaque += weapon->GetAttaque();
		m_defense += weapon->GetDefense();
		m_agilite += weapon->GetAgilite();
		m_intelligence += weapon->GetIntelligence();

	}
}

CCharacter::~CCharacter()
{
}

void CCharacter::AttaquerSansArme(CCharacter CCharacter)
{
	if (!CCharacter.Esquiver()) {																				//Si l'esquive adverse échoue ( inférieure au nombre random tiré au dessus
		float coeff = 0.95 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (1.05 - 0.95)));	//calcul du coeff
		int p_degats = 15*(GetAttaque()/CCharacter.GetDefense())*coeff;											//calcul des dégats
		p_degats = p_degats*-1;																					//on transforme les dégats en valeur négative
		CCharacter.SetVie(p_degats);																			//on inflige les dégats à l'adversaire
	}
	else {
		std::cout << CCharacter.GetNom() <<" a esquivé";														//on informe l'utilisateur que l'adversaire a esquivé
	}
}

void CCharacter::AttaquerAvecArme(CCharacter CCharacter)
{
}

int CCharacter::Esquiver()
{
	float randEsquive = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	return randEsquive <= m_esquive;
}

std::string CCharacter::GetClasse()
{
	return m_classe;
}

std::string CCharacter::GetNom()
{
	return m_nom;
}

int CCharacter::GetVieInitiale()
{
	return m_vieInitiale;
}

int CCharacter::GetVie()
{
	return m_vie;
}

CWeapon* CCharacter::GetWeapon()
{
	return m_weapon;
}

float CCharacter::GetEsquive()
{
	return m_esquive;
}

int CCharacter::GetVitesseBase()
{
	return m_vitesseBase;
}

int CCharacter::GetVitesse()
{
	return m_vitesse;
}

int CCharacter::GetAttaque()
{
	return m_attaque;
}

int CCharacter::GetDefense()
{
	return m_defense;
}

int CCharacter::GetAgilite()
{
	return m_agilite;
}

int CCharacter::GetIntelligence()
{
	return m_intelligence;
}

int CCharacter::IsEmpoisonne()
{
	return m_empoisonne;
}

int CCharacter::HasBonusDegats()
{
	return m_bonusDegats;
}

float CCharacter::GetCaracPartic()
{
	return 0.0f;
}

void CCharacter::SetVie(int vie)
{
	m_vie += vie;
	if (m_vie < 0) {
		m_vie = 0;
	}
}

void CCharacter::SetWeapon(CWeapon* weapon)
{
	if (m_weapon != nullptr) {
		m_vie -= m_weapon->GetVie();
		m_vieInitiale -= m_weapon->GetVie();
		m_esquive -= m_weapon->GetEsquive();
		m_vitesseBase -= m_weapon->GetVitesseBase();
		m_vitesse -= m_weapon->GetVitesseBase();
		m_attaque -= m_weapon->GetAttaque();
		m_defense -= m_weapon->GetDefense();
		m_agilite -= m_weapon->GetAgilite();
		m_intelligence -= m_weapon->GetIntelligence();
	}
	delete m_weapon;
	m_weapon = weapon;
	if (m_weapon != nullptr) {
		m_vie += weapon->GetVie();
		m_vieInitiale += weapon->GetVie();
		m_esquive += weapon->GetEsquive();
		m_vitesseBase += weapon->GetVitesseBase();
		m_vitesse += weapon->GetVitesseBase();
		m_attaque += weapon->GetAttaque();
		m_defense += weapon->GetDefense();
		m_agilite += weapon->GetAgilite();
		m_intelligence += weapon->GetIntelligence();
	}
}

void CCharacter::PresentationChoix()
{
	int boucled = 0;
	while (!boucled) {
		std::cout << "\nQuelle action souhaitez vous faire ?";
		std::cout << "\n\t1. Attaquer un adversaire. (Sans utiliser votre arme)";
		std::cout << "\n\t2. Attaquer un adversaire. (En utilisant votre arme)";
		std::cout << "\n\t3. Utiliser une capacité spéciale.";
		
		int choice;
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			
			break;
		case 2:	

			break;
		case 3:

			break;
		default:

			break;
		}
	}
}

void CCharacter::print()
{
}
