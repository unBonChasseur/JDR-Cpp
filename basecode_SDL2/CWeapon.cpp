#include "CWeapon.h"

CWeapon::CWeapon()
{
	m_type = "";
	m_nom = "";
	m_degats = 0;
	m_critique = 0;

	m_vie = 0;
	m_esquive = 0;
	m_vitesse = 0;
	m_attaque = 0;
	m_defense = 0;
	m_agilite = 0;
	m_intelligence = 0;
}

int CWeapon::CoupCritique()
{
	float randCritique = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	return randCritique <= m_critique;
}

CWeapon::CWeapon(std::string type, std::string nom, int degats, float critique, int vie, float esquive, int vitesse, int attaque, int defense, int agilite, int intelligence)
{
	m_type = type;
	m_nom = nom;
	m_degats = degats;
	m_critique = critique;

	m_vie = vie;
	m_esquive = esquive;
	m_vitesse = vitesse;
	m_attaque = attaque;
	m_defense = defense;
	m_agilite = agilite;
	m_intelligence = intelligence;
}

std::string CWeapon::GetType()
{
	return m_type;
}

std::string CWeapon::GetNom()
{
	return m_nom;
}

int CWeapon::GetDegats()
{
	return m_degats;
}

float CWeapon::GetCritique()
{
	return m_critique;
}

int CWeapon::GetVie()
{
	return m_vie;
}

float CWeapon::GetEsquive()
{
	return m_esquive;
}

int CWeapon::GetVitesse()
{
	return m_vitesse;
}

int CWeapon::GetAttaque()
{
	return m_attaque;
}

int CWeapon::GetDefense()
{
	return m_defense;
}

int CWeapon::GetAgilite()
{
	return m_agilite;
}

int CWeapon::GetIntelligence()
{
	return m_intelligence;
}

void CWeapon::Utiliser()
{
}

float CWeapon::CalculerDegats()
{
	float p_degats;

	p_degats = (float)m_degats;
	if (CoupCritique()) {
		std::cout << "\nVous utiliser votre arme a son meilleur potentiel, elle va faire deux fois plus mal.";
		p_degats *= 2;
	}
	return p_degats;
}

void CWeapon::Reinitialiser()
{
}

void CWeapon::print()
{
}
