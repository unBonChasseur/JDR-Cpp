#include "CWeapon.h"

CWeapon::CWeapon()
{
	m_type = "";
	m_nom = "";
	m_degats = 0;
	m_critique = 0;
	m_bonus = 1;
}

CWeapon::CWeapon(std::string type, std::string nom, int degats, float critique, float bonus)
{
	m_type = type;
	m_nom = nom;
	m_degats = degats;
	m_critique = critique;
	m_bonus = bonus;
}

CWeapon::~CWeapon()
{
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
	return m_bonus;
}
