#pragma once
#include "CRanged.h"

class CStaff : public CRanged
{
protected:

	int m_cout;

	CStaff();

public:
	CStaff(std::string type, std::string nom, int degats, float critique, int vie, float esquive, int vitesse, int attaque, int defense, int agilite, int intelligence, int cout);

	int GetCout();
	int GetSpecial();

	void print();
};


