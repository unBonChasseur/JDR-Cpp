#pragma once
#include <cstring>
#include <iostream>

class CWeapon
{
protected :
	//statistiques liées à l'arme
	std::string m_type;
	std::string m_nom;
	int m_degats;
	float m_critique;
	float m_bonusDegatsArme;

	//statistiques liées aux personnage porteur
	int m_vie;
	float m_esquive;
	int m_vitesseBase;
	int m_attaque;
	int m_defense;
	int m_agilite;
	int m_intelligence;

	CWeapon();

public :
	CWeapon(std::string type, std::string nom, int degats, float critique, float bonus
	,int vie,float esquive, int vitesseBase, int attaque, int defense, int agilite, int intelligence);
	virtual ~CWeapon();

	virtual float Utiliser();

	std::string GetType();
	std::string GetNom();
	int GetDegats();
	float GetCritique();
	float GetBonus();

	int GetVie();
	int GetEsquive();
	int GetVitesseBase();
	int GetAttaque();
	int GetDefense();
	int GetAgilite();
	int GetIntelligence();
};
