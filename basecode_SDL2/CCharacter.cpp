#include "CCharacter.h"

CCharacter::CCharacter()
{
	m_nom = "";
	m_vie = 0;
	//m_weapon = new std::vector<CWeapon();
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

void CCharacter::SetVie(int vie)
{
	m_vie += vie; 
	if (m_vie < 0) {
		m_vie = 0;
	}
}

CCharacter::CCharacter(std::string nom, int vie, std::vector<CWeapon*> weapon, int esquive, int vitesseBase, int attaque, int defense, int agilite, int intelligence)
{
	m_nom = nom;
	m_vie = vie;
	m_weapon = weapon;
	m_esquive = esquive;
	m_vitesseBase = vitesseBase;
	m_vitesse = vitesseBase;
	m_attaque = attaque;
	m_defense = defense;
	m_agilite = agilite;
	m_intelligence = intelligence;
	m_empoisonne = 0;
	m_bonusDegats = 0;
}

CCharacter::~CCharacter()
{
}

void CCharacter::AttaquerSansArme(CCharacter CCharacter)
{
	float randEsquive = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);							//on prends un float compris entre 0 et 1
	if (randEsquive > CCharacter.GetEsquive()) {																//Si l'esquive adverse échoue ( inférieure au nombre random tiré au dessus
		float coeff = 0.95 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (1.05 - 0.95)));	//calcul du coeff
		int p_degats = 15*(GetAttaque()/CCharacter.GetDefense())*coeff;											//calcul des dégats
		p_degats = p_degats*-1;																					//on transforme les dégats en valeur négative
		CCharacter.SetVie(p_degats);																			//on inflige les dégats à l'adversaire
	}
	else {
		std::cout << randEsquive << "<" << CCharacter.GetEsquive();
		std::cout << CCharacter.GetNom() <<" a esquivé";														//on informe l'utilisateur que l'adversaire a esquivé
	}
}

std::string CCharacter::GetNom()
{
	return m_nom;
}

int CCharacter::GetVie()
{
	return m_vie;
}

CWeapon* CCharacter::GetWeapon()
{
	return nullptr;
}

int CCharacter::GetEsquive()
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
