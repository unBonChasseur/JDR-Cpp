#include "CBow.h"

CBow::CBow():CRanged()
{
	m_nbFleches = 0;
	m_nbFlechesBase = 0;
}

CBow::CBow(std::string type, std::string nom, int degats, float critique, float bonus, int vie, float esquive, int vitesseBase, int attaque, int defense, int agilite, int intelligence, int nbFleches)
	:CRanged(type, nom, degats, critique, bonus, vie, esquive, vitesseBase, attaque, defense, agilite, intelligence),
	m_nbFleches(nbFleches),
	m_nbFlechesBase(nbFleches)
{
}

CBow::~CBow()
{
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
