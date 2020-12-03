#pragma once
#include "CCharacter.h"

class CRogue : public CCharacter
{
private :
	int IsWeaponDagger();

protected :
	int m_nbToursFurtif;
	int m_CDFurtif;
	int m_nbFleche;

public :
};

