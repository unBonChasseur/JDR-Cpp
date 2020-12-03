#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "CWeapon.h"

class CCharacter
{
private :
	void IsAlive();

protected :
	std::string m_nom;
	int m_vie;
	std::vector<CWeapon*> m_weapon;
	int m_esquive;
	int m_vitesse;
	int m_attaque;
	int m_defense;
	int m_agilite;
	int m_intelligence;

public :
	CCharacter();
	virtual ~CCharacter();

	void AttaquerSansArme();
	void AttaquerAvecArme();
	void UtiliserCapacite();
	void EsquiverAttaque();

};

