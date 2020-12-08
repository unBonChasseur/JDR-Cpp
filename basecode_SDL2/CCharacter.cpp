#include "CCharacter.h"

CCharacter::CCharacter()
{
	m_nom = "";
	m_vie = 0;
	//m_weapon = CWeapon(0,0,0,0,0,0,0,0,0,0,0,0);
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

CCharacter::CCharacter(std::string nom, int vie, float esquive, int vitesseBase, int attaque, int defense, int agilite, int intelligence)
{
	//m_weapon = weapon;

	m_nom = nom;
	m_vie = vie;//+weapon.GetVie();
	m_vieInitiale = vie;// +weapon.GetVie();
	m_esquive = esquive;//+weapon.GetEsquive();
	m_vitesseBase = vitesseBase;//+weapon.GetVitesseBase();
	m_vitesse = vitesseBase;//+weapon.GetVitesseBase();
	m_attaque = attaque;//+weapon.GetAttaque();
	m_defense = defense;//+weapon.GetDefense();
	m_agilite = agilite;//+weapon.GetAgilite();
	m_intelligence = intelligence;//+weapon.GetIntelligence();
	m_empoisonne = 0;
	m_bonusDegats = 0;
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

/*CWeapon CCharacter::GetWeapon()
{
	//return m_weapon;
}*/

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

void CCharacter::SetVie(int vie)
{
	m_vie += vie;
	if (m_vie < 0) {
		m_vie = 0;
	}
}

void CCharacter::print()
{
	std::cout << "\n\nclasse CCharacter";
	std::cout << "\nnom : " << m_nom;
	std::cout << "\nVie : " << m_vie;
	std::cout << "\nEsquive : " << m_esquive;
	std::cout << "\nVitesse : " << m_vitesseBase;
	std::cout << "\nattaque : " << m_attaque;
	std::cout << "\ndefense : " << m_defense;
	std::cout << "\nagilite : " << m_agilite;
	std::cout << "\nintelligence : " << m_intelligence;
}
