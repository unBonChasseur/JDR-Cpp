#include "CWeapon.h"

CWeapon::CWeapon()
{
	m_type = "";
	m_nom = "";
	m_degats = 0;
	m_critique = 0;
	m_enchantement = 1;

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
	m_enchantement = 1;

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

float CWeapon::GetEnchantement()
{
	return m_enchantement;
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

int CWeapon::GetSpecial()
{
	return 0;
}

float CWeapon::CalculerDegats()
{
	return 0.0f;
}

void CWeapon::Reparer()
{
}

void CWeapon::print()
{
}
