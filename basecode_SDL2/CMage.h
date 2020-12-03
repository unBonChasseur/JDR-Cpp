#pragma once
#include "CCharacter.h"

class CMage : public CCharacter
{
private :
	void IsWeaponStaff();

protected :
	int m_ManaMax;
	int m_Mana;
	int m_CDSoin;
	int m_CD;

public :
	void RegenererMana();
	void Soigner();
	void Enchanter();

};

