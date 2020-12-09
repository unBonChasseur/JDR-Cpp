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
	CCharacter* ChooseCharacter(int numero);
};

