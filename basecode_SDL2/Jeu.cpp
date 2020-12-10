#include "Jeu.h"

Jeu::Jeu()
{
	m_vector.resize(4);
	m_vector.at(0).resize(0);
	m_vector.at(1).resize(0);
	m_vector.at(2).resize(0);
	m_vector.at(3).resize(0);
}

Jeu::~Jeu()
{
}

void Jeu::DemarrerJeu()
{
	int choice = 0;
	int quit = 0;

	while (!quit) {
		std::cout << "\n\nBienvenue dans le meilleur jeu du monde";
		std::cout << "\nQue souhaitez vous faire ?";
		std::cout << "\n  1. Jouer une partie";
		std::cout << "\n  2. Parametres du joueur 1";
		std::cout << "\n  3. Parametres du joueur 2";
		std::cout << "\n  4. Quitter";

		std::cout << "\n\nQuelle option choisissez vous ?\n";
		std::cin >> choice;
		switch (choice) {
		case 1:
			if (VerifierParamPartie())
				lancerPartie();
			break;

		case 2:
			ParamJoueur(m_vector.at(0), 1);
			break;

		case 3:
			ParamJoueur(m_vector.at(1), 2);
			break;

		case 4:
			quit = 1;
			ViderVariables();
			break;

		default:
			break;
		}

	}
}

int Jeu::VerifierParamPartie()
{
	size_t j1 = m_vector.at(0).size();
	size_t j2 = m_vector.at(1).size();

	if (j1 == 3) {//on vérifie que la taille des deux listes sont bonnes
		std::cout << "j1 a le bon nombre de personnage.";
		if (j2 == 3) {
			std::cout << "j2 a le bon nombre de personnage.";
		}
	}
	else 
		std::cout << "Les deux joueurs n'ont pas le bon nombre de personnage.";
	
	return 0;
}

void Jeu::lancerPartie()
{

}

void Jeu::ParamJoueur(std::vector<CCharacter*> p_vector, int i)
{
	PrintJoueur(p_vector, i);

	int choice = 0;
	int quit = 0;

	while (!quit) {
		if (p_vector.size() != 3) {
			std::cout << "\n\n\tQue souhaitez vous faire ?";
			std::cout << "\n\t  1. Ajouter un personnage";
			std::cout << "\n\t  2. Retourner au menu precedent.";

			std::cout << "\n\n\tQuelle option choisissez vous ?\n";
			std::cin >> choice;
			switch (choice) {
			case 1:
				AjouterPersonnage(p_vector, i);
				p_vector.resize(3);
				break;

			case 2:
				quit = 1;
				break;

			default:
				break;
			}
		}
		else {
			std::cout << "\n\n\tQue souhaitez vous faire ?";
			std::cout << "\n\t  1. Remplacer un personnage.";
			std::cout << "\n\t  2. Remplacer l'arme d'un personnage.";
			std::cout << "\n\t  3. Retourner au menu precedent.";

			std::cout << "\n\n\tQuelle option choisissez vous ?\n";
			std::cin >> choice;
			switch (choice) {
			case 1:
				break;

			case 2:

				break;

			case 3:
				quit = 1;
				break;

			default:
				break;
			}
		}
		
	}
	DemarrerJeu();
}


void Jeu::PrintJoueur(std::vector<CCharacter*> p_vector, int i)
{
	std::cout << "\n\tPersonnages du joueur " << i << " :";
	std::vector<CCharacter*>::iterator it;

	for (it = p_vector.begin(); it != p_vector.end(); it++) {
		(*it)->print();
	}
}

void Jeu::AjouterPersonnage(std::vector<CCharacter*> p_vector, int i)
{
	m_parsing.PrintCharacter();
	int choice1 = 0;
	int choice2 = 0;
	int quit = 0;

	while (!quit) {

		std::cout << "\n\n\tQuelle personnage choisissez vous ?\n";
		std::cin >> choice1;

		if (choice1 <= m_parsing.GetCharacterSize()) {
			m_parsing.PrintWeapon();
			std::cout << "\n\n\tQuelle arme choisissez vous ?\n";
			std::cin >> choice2;

			if (choice2 <= m_parsing.GetWeaponSize()) {

			}
			else 
				quit = 1;
		}
		else 
			quit = 1;
	}
	ParamJoueur(p_vector, i);
}

void Jeu::ViderVariables()
{

}


