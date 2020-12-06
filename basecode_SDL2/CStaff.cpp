#include "CStaff.h"

CStaff::CStaff():CRanged()
{
}

CStaff::CStaff(std::string type, std::string nom, int degats, float critique, float bonus, int vie, float esquive, int vitesseBase, int attaque, int defense, int agilite, int intelligence)
	:CRanged(type, nom, degats, critique, bonus, vie, esquive, vitesseBase, attaque, defense, agilite, intelligence)
{
}

CStaff::~CStaff()
{
}

float CStaff::Utiliser()
{
	float DegatsFinaux;
	
	float randomNumber = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX));
	if (randomNumber <= m_critique) {
		std::cout << "La sort dégage une aura fantastique et sera 2 fois plus efficace !";
		DegatsFinaux += DegatsFinaux;
	}
	
	return DegatsFinaux;
}
