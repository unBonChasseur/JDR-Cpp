#pragma once
#include "CMelee.h"

class CDagger : public CMelee
{
protected:

	CDagger();

public:

	CDagger(std::string type, std::string nom, int degats, float critique, int vie, float esquive, int vitesse, int attaque, int defense, int agilite, int intelligence, int durabilite);

	void print();
};

