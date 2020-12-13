#pragma once
#include <vector>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <cstring>

#include <sstream>
#include "CWeapon.h"
#include "CSword.h"
#include "CBow.h"
#include "CStaff.h"
#include "CDagger.h"

#include "CCharacter.h"
#include "CWarrior.h"
#include "CArcher.h"
#include "CMage.h"
#include "CRogue.h"

class Parsing
{
protected :

	std::vector<CWeapon*> m_weapon;
	std::vector<CCharacter*> m_character;
	void LectureArmes();
	void LecturePersonnages();

public :
	
	Parsing();
	~Parsing();

	void PrintCharacter();
	void PrintWeapon();
	void PrintWeapon(std::string type1, std::string type2);

	CCharacter* ChooseCharacter(int numero);
	CWeapon* ChooseWeapon(int numero);
	CWeapon* ChooseWeapon(std::string type1, std::string type2, int choix);

	int GetWeaponSize();
	int GetWeaponSize(std::string type1, std::string type2);
	int GetCharacterSize();

	void EnleverWeapon(CWeapon* ccharacter);
	void EnleverCharacter(CCharacter* ccharacter);

	void AjouterCharacter(CCharacter* ccharacter);
};

