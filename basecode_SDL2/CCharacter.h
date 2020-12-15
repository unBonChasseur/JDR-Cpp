#pragma once
#include <iostream>
#include <cstring>
#include <vector>

#include "CWeapon.h"

class CCharacter
{
protected :

	std::string m_nom;
	int m_vieBase;
	int m_vie;
	CWeapon* m_weapon;
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

public :
	CCharacter(std::string nom, int vie, CWeapon* weapon, float esquive, int vitesse, int attaque, int defense, int agilite, int intelligence);
	virtual ~CCharacter();

	void AttaquerSansArme(CCharacter* ccharacter);
	virtual void AttaquerAvecArme(CCharacter* ccharacter);
	int Esquiver();

	virtual std::string GetClasse();
	std::string GetNom();
	int GetVieInitiale();
	int GetVie();
	CWeapon* GetWeapon();
	float GetEsquive();
	int GetVitesseBase();
	int GetVitesse();
	int GetAttaque();
	int GetDefense();
	int GetAgilite();
	int GetIntelligence();
	int IsEmpoisonne();
	int HasBonusDegats();
	virtual float GetCaracPartic();

	void SetVie(int vie);
	void SetWeapon(CWeapon* weapon);

	virtual void Print();
};

