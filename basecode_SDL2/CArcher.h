#pragma once
#include "CCharacter.h"

class CArcher : public CCharacter
{
private :
	void IsWeaponBow();

protected :
	int m_nbFleche;

public :
	void GuerirPoison();
	void VIser();

};

