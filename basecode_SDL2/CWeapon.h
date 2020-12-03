#pragma once
#include <string>

class CWeapon
{
protected :
	std::string m_nom;
	std::string m_degats;
	std::string m_critique;
	std::string m_bonus;

	CWeapon();

public :
	CWeapon(std::string nom, std::string degats, std::string critique, std::string bonus);
	virtual ~CWeapon();

	std::string GetNom();
	std::string GetDegats();
	std::string GetCritique();
	std::string GetBonus();
};
