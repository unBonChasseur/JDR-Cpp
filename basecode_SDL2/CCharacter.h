#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "CWeapon.h"

class CCharacter
{
protected :
	std::string m_nom;
	int m_vie;
	std::vector<CWeapon*> m_weapon;
	float m_esquive;
	int m_vitesseBase;
	int m_vitesse;
	int m_attaque;
	int m_defense;
	int m_agilite;
	int m_intelligence;
	int m_empoisonne;
	int m_bonusDegats;

	CCharacter();
	void SetVie(int vie);

public :
	CCharacter(std::string nom, int vie, std::vector<CWeapon*> weapon, int esquive, int vitesseBase, int attaque, int defense, int agilite, int intelligence);
	virtual ~CCharacter();

	void AttaquerSansArme(CCharacter CCharacter);
	virtual void AttaquerAvecArme();
	virtual void UtiliserCapacite();
	virtual void EsquiverAttaque();

	std::string GetNom();
	int GetVie();
	CWeapon* GetWeapon();
	int GetEsquive();
	int GetVitesseBase();
	int GetVitesse();
	int GetAttaque();
	int GetDefense();
	int GetAgilite();
	int GetIntelligence();
	int IsEmpoisonne();
	int HasBonusDegats();

};

