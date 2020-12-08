#pragma once
#include <cstring>
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <vector>

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
	void LectureArmes(std::vector<CWeapon*> vector);
	void LecturePersonnages(std::vector<CCharacter*> vector);

public :
	
	Parsing();
	void PrintCharacter();
	void PrintWeapon();

};

