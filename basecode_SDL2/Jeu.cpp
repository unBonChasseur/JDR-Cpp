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
			ParamJoueur(1);
			break;

		case 3:
			ParamJoueur(2);
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

void Jeu::ParamJoueur(int i)
{
	PrintJoueur(i);

	int choice = 0;
	int quit = 0;

	while (!quit) {
		if (m_vector.at(i-1).size() != 3) {
			std::cout << "\n\n\tQue souhaitez vous faire ?";
			std::cout << "\n\t  1. Ajouter un personnage";
			std::cout << "\n\t  2. Retourner au menu precedent.";

			std::cout << "\n\n\tQuelle option choisissez vous ?\n";
			std::cin >> choice;
			switch (choice) {
			case 1:
				AjouterPersonnage(i);
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

void Jeu::PrintJoueur(int i)
{
	std::cout << "\n\tPersonnages du joueur " << i << " :";
	std::vector<CCharacter*>::iterator it;

	for (it = m_vector.at(i-1).begin(); it != m_vector.at(i - 1).end(); it++) {
		(*it)->print();
		std::cout << "\n";
	}
}

void Jeu::AjouterPersonnage(int i)
{
	m_parsing.PrintCharacter();
	int choice = 0;
	int quit = 0;

	while (!quit) {

		std::cout << "\n\n\tQuelle personnage choisissez vous ?\n";
		std::cin >> choice;

		if (choice <= m_parsing.GetCharacterSize()) {
			
			std::string classe = m_parsing.ChooseCharacter(choice-1)->GetClasse();
			if (classe == "Voleur") {
				CCharacter* a = m_parsing.ChooseCharacter(choice - 1);
				CRogue* b = new CRogue(a->GetNom(),a->GetVie(), a->GetWeapon(), a->GetEsquive(), a->GetVitesseBase(), a->GetAttaque(), a->GetDefense(), a->GetAgilite(), a->GetIntelligence(), a->GetCaracPartic());
				m_vector.at(i - 1).push_back(b);
				m_parsing.EnleverCharacter(a);
			}
			if (classe == "Guerrier") {
				CCharacter* a = m_parsing.ChooseCharacter(choice - 1);
				CWarrior* b = new CWarrior(a->GetNom(), a->GetVie(), a->GetWeapon(), a->GetEsquive(), a->GetVitesseBase(), a->GetAttaque(), a->GetDefense(), a->GetAgilite(), a->GetIntelligence(), a->GetCaracPartic());
				m_vector.at(i - 1).push_back(b);
				m_parsing.EnleverCharacter(a);
			}
			if (classe == "Mage") {
				CCharacter* a = m_parsing.ChooseCharacter(choice - 1);
				CMage* b = new CMage(a->GetNom(), a->GetVie(), a->GetWeapon(), a->GetEsquive(), a->GetVitesseBase(), a->GetAttaque(), a->GetDefense(), a->GetAgilite(), a->GetIntelligence());
				m_vector.at(i - 1).push_back(b);
				m_parsing.EnleverCharacter(a);
			}
			if (classe == "Archer") {
				CCharacter* a = m_parsing.ChooseCharacter(choice - 1);
				CArcher* b = new CArcher(a->GetNom(), a->GetVie(), a->GetWeapon(), a->GetEsquive(), a->GetVitesseBase(), a->GetAttaque(), a->GetDefense(), a->GetAgilite(), a->GetIntelligence());
				m_vector.at(i - 1).push_back(b);
				m_parsing.EnleverCharacter(a);
			}
		}
		else {
			std::cout << "\n\n\t Choix incorrect.";
		}
		quit = 1;
	}
	ParamJoueur(i);
}

void Jeu::ViderVariables()
{

}


