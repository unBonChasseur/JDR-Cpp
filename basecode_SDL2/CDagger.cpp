#include "CDagger.h"

CDagger::CDagger():CMelee()
{
}

CDagger::CDagger(std::string type, std::string nom, int degats, float critique, float bonus, int vie, float esquive, int vitesseBase, int attaque, int defense, int agilite, int intelligence, int durabilite)
	:CMelee(type, nom, degats, critique, bonus, vie, esquive, vitesseBase, attaque, defense, agilite, intelligence, durabilite)
{
}

CDagger::~CDagger()
{
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