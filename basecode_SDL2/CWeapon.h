#pragma once
#include <string>
#include <iostream>

class CWeapon
{
protected :
	std::string m_type;
	std::string m_nom;
	int m_degats;
	float m_critique;
	float m_bonus;

	CWeapon();

public :
	CWeapon(std::string type, std::string nom, int degats, float critique, float bonus);
	virtual ~CWeapon();

	std::string GetType();
	std::string GetNom();
	int GetDegats();
	float GetCritique();
	float GetBonus();
};
