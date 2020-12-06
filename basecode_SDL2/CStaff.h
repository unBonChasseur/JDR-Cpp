#pragma once
#include "CRanged.h"

class CStaff : public CRanged
{
protected:

	CStaff();

public:
	CStaff(std::string type, std::string nom, int degats, float critique, float bonus
		, int vie, float esquive, int vitesseBase, int attaque, int defense, int agilite, int intelligence);
	virtual ~CStaff();

	float Utiliser();
};


