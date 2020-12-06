#include "CSword.h"

CSword::CSword():CMelee()
{
}

CSword::CSword(std::string type, std::string nom, int degats, float critique, float bonus, int vie, float esquive, int vitesseBase, int attaque, int defense, int agilite, int intelligence, int durabilite)
	:CMelee(type, nom, degats, critique, bonus, vie, esquive, vitesseBase, attaque, defense, agilite, intelligence, durabilite)
{
}

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

