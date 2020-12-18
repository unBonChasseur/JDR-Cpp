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
	float m_enchantement;

	//statistiques liées aux personnage porteur
	int m_vie;
	float m_esquive;
	int m_vitesse;
	int m_attaque;
	int m_defense;
	int m_agilite;
	int m_intelligence;

	CWeapon();
	int CoupCritique();

public :
	CWeapon(std::string type, std::string nom, int degats, float critique, int vie, float esquive, int vitesse, int attaque, int defense, int agilite, int intelligence);

	std::string GetType();
	std::string GetNom();
	int GetDegats();
	float GetCritique();
	float GetEnchantement();

	int GetVie();
	float GetEsquive();
	int GetVitesse();
	int GetAttaque();
	int GetDefense();
	int GetAgilite();
	int GetIntelligence();

	virtual float GetSpecial();
	virtual float CalculerDegats();
	virtual void Reparer();

	virtual void print();

};
