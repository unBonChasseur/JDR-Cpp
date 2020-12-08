#include "CWarrior.h"

CWarrior::CWarrior():CCharacter()
{
	m_CDHurlement = 0;
	m_parade = 0;
	m_hurlement = 0;
}

CWarrior::CWarrior(std::string nom, int vie, float esquive, int vitesseBase, int attaque, int defense, int agilite, int intelligence, float parade)
	:CCharacter(nom, vie, esquive, vitesseBase, attaque, defense, agilite, intelligence),
	m_CDHurlement(0),
	m_parade(parade),
	m_hurlement(0)
{
	/*
	if (m_weapon.GetType() == "Epee")
		m_esquive += m_parade;*/
}

CWarrior::~CWarrior()
{
}

void CWarrior::AttaquerAvecArme(CCharacter CCharacter)
{
	/*
	if (!CCharacter.Esquiver()) {																				//Si l'esquive adverse échoue ( inférieure au nombre random tiré au dessus
		if(m_weapon)

		float coeff = 0.95 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (1.05 - 0.95)));	//calcul du coeff
		int p_degats = 15 * (GetAttaque() / CCharacter.GetDefense()) * coeff;									//calcul des dégats
		p_degats = p_degats * -1;																				//on transforme les dégats en valeur négative
		CCharacter.SetVie(p_degats);																			//on inflige les dégats à l'adversaire
	}
	else {
		std::cout << CCharacter.GetNom() << " a esquivé votre coup !";											//on informe l'utilisateur que l'adversaire a esquivé
	}




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
				<< randDurabilite << " de durabilité lors de ce coup.\nIl reste " << m_durabilite << " de durabilité à votre arme.(/" << m_durabiliteInitiale << ")";
		}
	}

	float randomNumber = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX));
	if (randomNumber <= m_critique) {
		std::cout << "Le coup est fluide et sans bavure, si l'adversaire est touché ce sera un vrai carnage !";
		DegatsFinaux += DegatsFinaux;
	}

	return DegatsFinaux;*/
}

void CWarrior::Hurler()
{
	m_CDHurlement = 4;
	int randNum = rand() % (2 - 1 + 1) + 1;
	m_hurlement = randNum;
}

void CWarrior::ReparerArme()
{

}

void CWarrior::print()
{
	std::cout << "\n\nclasse CWarrior";
	std::cout << "\nnom : " << m_nom;
	std::cout << "\nVie : " << m_vie;
	std::cout << "\nEsquive : " << m_esquive;
	std::cout << "\nVitesse : " << m_vitesseBase;
	std::cout << "\nattaque : " << m_attaque;
	std::cout << "\ndefense : " << m_defense;
	std::cout << "\nagilite : " << m_agilite;
	std::cout << "\nintelligence : " << m_intelligence;
}
