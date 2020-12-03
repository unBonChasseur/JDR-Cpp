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
	int m_vitesseMax;
	int m_vitesse;
	int m_attaque;
	int m_defense;
	int m_agilite;
	int m_intelligence;
	int m_empoisonne;
	int BonusDegats;

public :
	CCharacter();
	virtual ~CCharacter();

	virtual void AttaquerSansArme();
	virtual void AttaquerAvecArme();
	virtual void UtiliserCapacite();
	virtual void EsquiverAttaque();

};

