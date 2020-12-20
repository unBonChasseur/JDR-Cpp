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
}

CCharacter::CCharacter(std::string nom, int vie, CWeapon* weapon, float esquive, int vitesse, int attaque, int defense, int agilite, int intelligence)
{
	m_classe = "character";
	m_nom = nom;
	m_vie = vie;
	m_vieBase = vie;
	m_weapon = weapon;
	m_esquive = esquive;
	m_vitesseBase = vitesse;
	m_vitesse = vitesse;
	m_attaque = attaque;
	m_defense = defense;
	m_agilite = agilite;
	m_intelligence = intelligence;
	m_empoisonne = 0;

	if (weapon != nullptr) {
		
		m_vie += weapon->GetVie();
		m_vieBase += weapon->GetVie();
		m_esquive += weapon->GetEsquive();
		m_vitesseBase += weapon->GetVitesse();
		m_vitesse += weapon->GetVitesse();
		m_attaque += weapon->GetAttaque();
		m_defense += weapon->GetDefense();
		m_agilite += weapon->GetAgilite();
		m_intelligence += weapon->GetIntelligence();

	}
}

CCharacter::~CCharacter()
{
}

void CCharacter::AttaquerSansArme(CCharacter* ccharacter)
{
	if (!ccharacter->Esquiver()) {																			
		float coeff = 0.95 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (1.05 - 0.95)));	
		float p_degats = 15*((float)m_attaque/(float)ccharacter->GetDefense())*coeff;										
		ccharacter->SetVie(-p_degats);
		std::cout << "\n\nLa cible a pris " << p_degats << " points de degats.\nIl lui reste " << ccharacter->GetVie() << "/" << ccharacter->GetVieBase() << " points de vie.";
	}
	else {
		std::cout << "\n\nVotre cible (" << ccharacter->GetNom() <<") a esquive.";
	}
}

void CCharacter::AttaquerAvecArme(CCharacter* CCharacter)
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

int CCharacter::GetVieBase()
{
	return m_vieBase;
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

void CCharacter::SetVie(int vie)
{
	m_vie += vie;
	if (m_vie >= m_vieBase) {
		m_vie = m_vieBase;
	}
	if (m_vie < 0) {
		m_vie = 0;
	}
}

void CCharacter::SetVitesse(int vitesse)
{
	m_vitesse = vitesse;
}

void CCharacter::SetWeapon(CWeapon* weapon)
{
	if (m_weapon != nullptr) {
		m_vie -= m_weapon->GetVie();
		m_vieBase -= m_weapon->GetVie();
		m_esquive -= m_weapon->GetEsquive();
		m_vitesseBase -= m_weapon->GetVitesse();
		m_vitesse -= m_weapon->GetVitesse();
		m_attaque -= m_weapon->GetAttaque();
		m_defense -= m_weapon->GetDefense();
		m_agilite -= m_weapon->GetAgilite();
		m_intelligence -= m_weapon->GetIntelligence();
	}
	delete m_weapon;
	m_weapon = weapon;
	if (m_weapon != nullptr) {
		m_vie += weapon->GetVie();
		m_vieBase += weapon->GetVie();
		m_esquive += weapon->GetEsquive();
		m_vitesseBase += weapon->GetVitesse();
		m_vitesse += weapon->GetVitesse();
		m_attaque += weapon->GetAttaque();
		m_defense += weapon->GetDefense();
		m_agilite += weapon->GetAgilite();
		m_intelligence += weapon->GetIntelligence();
	}
}

void CCharacter::SetPoison(int poison)
{
	m_empoisonne = poison;
}

void CCharacter::DebuterTour()
{
}

void CCharacter::Print()
{
}

void CCharacter::Reinitialiser()
{
}
