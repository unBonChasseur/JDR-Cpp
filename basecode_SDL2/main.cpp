#include <vector>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <cstring>
#include "Jeu.h"

int main(int argc, char** argv)
{
	
	Jeu jeu;
	jeu.DemarrerJeu();
	
	return 0;
}

//float randomNumber = LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HI-LO)));
/*
void MaFonction(CWeapon * p_monArmeAReparer)
{
  CMelee * monArmeAReparer = dynamic_cast<CMelee *>(p_monArmeAReparer);
  if(monArmeAReparer != nullptr)
  {
	//monArmeAReparer est p_monArmeAReparer caster en CMelee * et est non null
	monArmeAReparer->Repair();
  }
}
*/