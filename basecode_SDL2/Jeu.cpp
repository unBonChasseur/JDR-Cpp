#include "Jeu.h"

Jeu::Jeu()
{
	m_parsing.resize(2);
	m_parsing.at(0) = new Parsing();
	m_parsing.at(1) = new Parsing();

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
			ParamJoueur(0);
			break;

		case 3:
			ParamJoueur(1);
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
	int choice = 0;
	int quit = 0;

	while (!quit) {
		PrintJoueur(i);
		if (m_vector.at(i).size() != 3) {
			std::cout << "\n\n\tQue souhaitez vous faire ?";
			std::cout << "\n\t  1. Ajouter un personnage";
			std::cout << "\n\t  2. Retourner au menu precedent.";

			std::cout << "\n\n\tQuelle option choisissez vous ?\n\t";
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

			std::cout << "\n\n\tQuelle option choisissez vous ?\n\t";
			std::cin >> choice;
			switch (choice) {
			case 1:
				
				break;

			case 2:
				RemplacerArme(i);
				break;

			case 3:
				quit = 1;
				break;

			default:
				break;
			}
		}
	}
}

void Jeu::PrintJoueur(int i)
{
	std::cout << "\n\tPersonnages du joueur " << i+1 << " :";
	std::vector<CCharacter*>::iterator it;
	int x = 1;

	for (it = m_vector.at(i).begin(); it != m_vector.at(i).end(); it++) {
		std::cout << "\n\n\tPersonnage "<< x << " : ";
		(*it)->print();
		std::cout << "\n";
		x++;
	}
}

void Jeu::AjouterPersonnage(int i)
{
	m_parsing.at(i)->PrintCharacter();
	int choice = 0;
	int quit = 0;

	while (!quit) {

		std::cout << "\n\n\tQuel personnage choisissez vous ?\n\t";
		std::cin >> choice;

		if (choice <= m_parsing.at(i)->GetCharacterSize()) {

			choice--;
			CCharacter* character = m_parsing.at(i)->ChooseCharacter(choice);
			std::string classe = character->GetClasse();

			if (classe == "Voleur") {
				CRogue* temp = new CRogue(character->GetNom(),character->GetVie(), character->GetWeapon(), character->GetEsquive(), character->GetVitesseBase(), character->GetAttaque(), character->GetDefense(), character->GetAgilite(), character->GetIntelligence(), character->GetCaracPartic());
				m_vector.at(i).push_back(temp);
			}
			if (classe == "Guerrier") {
				CWarrior* temp = new CWarrior(character->GetNom(), character->GetVie(), character->GetWeapon(), character->GetEsquive(), character->GetVitesseBase(), character->GetAttaque(), character->GetDefense(), character->GetAgilite(), character->GetIntelligence(), character->GetCaracPartic());
				m_vector.at(i).push_back(temp);
			}
			if (classe == "Mage") {
				CMage* temp = new CMage(character->GetNom(), character->GetVie(), character->GetWeapon(), character->GetEsquive(), character->GetVitesseBase(), character->GetAttaque(), character->GetDefense(), character->GetAgilite(), character->GetIntelligence());
				m_vector.at(i).push_back(temp);
			}
			if (classe == "Archer") {
				CArcher* temp = new CArcher(character->GetNom(), character->GetVie(), character->GetWeapon(), character->GetEsquive(), character->GetVitesseBase(), character->GetAttaque(), character->GetDefense(), character->GetAgilite(), character->GetIntelligence());
				m_vector.at(i).push_back(temp);
			}
			m_parsing.at(i)->EnleverCharacter(character);
		}
		else 
			std::cout << "\n\n\t Choix incorrect.\n";
		
		quit = 1;
	}
}

void Jeu::RemplacerArme(int i)
{
	int choice = 0;
	int quit = 0;

	while (!quit) {
		PrintJoueur(i);

		std::cout << "\n\n\tQuel est le personnage dont vous souhaitez changer l'equipement ?\n\t";
		std::cin >> choice;

		if (choice <= m_vector.at(i).size()) {
			choice--;
			CCharacter* character = m_vector.at(i).at(choice);
			std::string classe = character->GetClasse();
			std::string type1, type2;

			if (classe == "Guerrier") {
				type1 = "Epee";
				type2 = "Dague";
			}
			if (classe == "Mage") {
				type1 = "Baton";
				type2 = "Epee";
			}
			if (classe == "Archer") {
				type1 = "Arc";
				type2 = "Dague";
			}
			if (classe == "Voleur") {
				type1 = "Dague";
				type2 = "Arc";
			}
			m_parsing.at(i)->PrintWeapon(type1, type2);

			std::cout << "\n\n\tQuelle arme souhaitez vous lui donner ?\n\t";
			std::cin >> choice;
			
			if (choice <= m_parsing.at(i)->GetWeaponSize(type1, type2)) {
				CWeapon* weapon = m_parsing.at(i)->ChooseWeapon(type1, type2, choice);
				std::string type = weapon->GetType();

				if (type == "Epee") {
					CSword* temp = new CSword(weapon->GetType(), weapon->GetNom(), weapon->GetDegats(), weapon->GetCritique(), weapon->GetBonus(), weapon->GetVie(), weapon->GetEsquive(), weapon->GetVitesseBase(), weapon->GetAttaque(), weapon->GetDefense(), weapon->GetAgilite(), weapon->GetIntelligence(), weapon->GetSpecial());
					
				}
				if (type == "Dague") {
					CDagger* temp = new CDagger(weapon->GetType(), weapon->GetNom(), weapon->GetDegats(), weapon->GetCritique(), weapon->GetBonus(), weapon->GetVie(), weapon->GetEsquive(), weapon->GetVitesseBase(), weapon->GetAttaque(), weapon->GetDefense(), weapon->GetAgilite(), weapon->GetIntelligence(), weapon->GetSpecial());
					
				}
				if (type == "arc") {
					CBow* temp = new CBow(weapon->GetType(), weapon->GetNom(), weapon->GetDegats(), weapon->GetCritique(), weapon->GetBonus(), weapon->GetVie(), weapon->GetEsquive(), weapon->GetVitesseBase(), weapon->GetAttaque(), weapon->GetDefense(), weapon->GetAgilite(), weapon->GetIntelligence(), weapon->GetSpecial());
					
				}
				if (type == "Baton") {
					CStaff* temp = new CStaff(weapon->GetType(), weapon->GetNom(), weapon->GetDegats(), weapon->GetCritique(), weapon->GetBonus(), weapon->GetVie(), weapon->GetEsquive(), weapon->GetVitesseBase(), weapon->GetAttaque(), weapon->GetDefense(), weapon->GetAgilite(), weapon->GetIntelligence(), weapon->GetSpecial());
					
				}
			}

			else 
				std::cout << "\n\n\t Choix d'arme incorrect.\n";
		}
		else
			std::cout << "\n\n\t Choix de personnage incorrect.\n";
		quit = 1;
	}
}

void Jeu::ViderVariables()
{

}
