#include "CWeapon.h"

CWeapon::CWeapon()
{
	m_type = "";
	m_nom = "";
	m_degats = 0;
	m_critique = 0;
	m_bonusDegatsArme = 1;

	m_vie = 0;
	m_esquive = 0;
	m_vitesseBase = 0;
	m_attaque = 0;
	m_defense = 0;
	m_agilite = 0;
	m_intelligence = 0;
}

CWeapon::CWeapon(std::string type, std::string nom, int degats, float critique, float bonus, int vie, float esquive, int vitesseBase, int attaque, int defense, int agilite, int intelligence)
{
	m_type = type;
	m_nom = nom;
	m_degats = degats;
	m_critique = critique;
	m_bonusDegatsArme = bonus;

	m_vie = vie;
	m_esquive = esquive;
	m_vitesseBase = vitesseBase;
	m_attaque = attaque;
	m_defense = defense;
	m_agilite = agilite;
	m_intelligence = intelligence;
}

CWeapon::~CWeapon()
{
}

float CWeapon::Utiliser()
{

	return 0.0f;
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

float CWeapon::GetBonus()
{
	return m_bonusDegatsArme;
}

int CWeapon::GetVie()
{
	return m_vie;
}

int CWeapon::GetEsquive()
{
	return m_esquive;
}

int CWeapon::GetVitesseBase()
{
	return m_vitesseBase;
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
