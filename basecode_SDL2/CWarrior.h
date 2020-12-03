#pragma once
#include "CCharacter.h"

class CWarrior : public CCharacter
{
private :
	void IsWeaponSword();

protected :
	int m_CDHurlement;

public :
	void ParerAttaque();
	void Hurler();
	void ReparerArme();
};

