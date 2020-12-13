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
float CSword::Utiliser()
{
	float DegatsFinaux;
	if (m_durabilite == 0) {							//on vérifie si l'arme est cassée avant d'ascener le coup
		DegatsFinaux = (float)m_degats / 10;			//Si oui, on divise les dégats par 10
	}
	else {												//sinon, les dégats sont normaux
		DegatsFinaux = m_degats;

		int randDurabilite = rand() % (5 - 2 + 1) + 2;	//on choisi un chiffre au hasard entre 2 et 5
		m_durabilite -= randDurabilite;					//on soustrait ce chiffre à la durabilité de l'arme
		if (m_durabilite <= 0) {
			m_durabilite = 0;
			std::cout << "\nVotre arme '" << m_nom <<	//informe le joueur que l'arme viens de se briser
				"' viens de se casser lors de ce coup!\nPensez à la faire réparer au plus vite !";
		}
		else {
			std::cout << "\nVotre arme viens de perdre " //informe l'utilisateur de la durabilité restante de l'arme
				<< randDurabilite << " de durabilité lors de ce coup.\nIl reste " << m_durabilite << " de durabilité à votre arme.(/"<<m_durabiliteInitiale<<")";
		}
	}

	float randomNumber = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX));
	if (randomNumber <= m_critique) {
		std::cout << "Le coup est fluide et sans bavure, si l'adversaire est touché ce sera un vrai carnage !";
		DegatsFinaux += DegatsFinaux;
	}

	return DegatsFinaux;
}

float CDagger::Utiliser()
{
	float DegatsFinaux;
	if (m_durabilite == 0) {							//on vérifie si l'arme est cassée avant d'ascener le coup
		DegatsFinaux = (float)m_degats / 10;			//Si oui, on divise les dégats par 10
	}
	else {												//sinon, les dégats sont normaux
		DegatsFinaux = m_degats;
		m_durabilite--;					//on soustrait ce chiffre à la durabilité de l'arme
		if (m_durabilite == 0) {
			m_durabilite = 0;
			std::cout << "\nVotre arme '" << m_nom <<	//informe le joueur que l'arme viens de se briser
				"' viens de se casser lors de ce coup!\nPensez à la faire réparer au plus vite !";
		}
		else {
			std::cout << "\nVotre arme viens de perdre " //informe l'utilisateur de la durabilité restante de l'arme
				"1 de durabilité lors de ce coup.\nIl reste " << m_durabilite << " de durabilité à votre arme.(/" << m_durabiliteInitiale << ")";
		}
	}

	float randomNumber = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX));
	if (randomNumber <= m_critique) {
		std::cout << "Ce coup est vicieux et bien placé, s'il fait mouche il devrait être redoutable !";
		DegatsFinaux += DegatsFinaux;
	}

	return DegatsFinaux;
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

float CBow::Utiliser()
{
	float DegatsFinaux;
	if (m_nbFleches == 0) {							//on vérifie si l'arme est cassée avant d'ascener le coup

		DegatsFinaux = 0.0f;						//Si oui, on divise les dégats par 10
	}
	else {												//sinon, les dégats sont normaux
		DegatsFinaux = m_degats;

		m_nbFleches--;					//on soustrait ce chiffre à la durabilité de l'arme
		if (m_nbFleches == 0) {
			std::cout << "\nVotre arme '" << m_nom <<	//informe le joueur que l'arme viens de se briser
				"' ne possède plus de flèches!\nPensez à récupérer des flèches au plus vite !";
		}
		else {
			std::cout << "\nVous décochez votre flèche. " //informe l'utilisateur de la durabilité restante de l'arme
				<<"\nIl reste " << m_nbFleches << " flèches dans votre carquois.(/" << m_nbFlechesBase << ")";
		}
	}

	float randomNumber = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX));
	if (randomNumber <= m_critique) {
		std::cout << "La flèche est particulièrement précise et devrait infliger un coup critique !";
		DegatsFinaux += DegatsFinaux;
	}

	return DegatsFinaux;
}


*/