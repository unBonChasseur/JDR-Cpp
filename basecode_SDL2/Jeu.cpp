#include "Jeu.h"

Jeu::Jeu()
{
	m_parsing.resize(2);
	m_parsing.at(0) = new Parsing();
	m_parsing.at(1) = new Parsing();

	m_vector.resize(2);
	m_vector.at(0).resize(0);
	m_vector.at(1).resize(0);
}
Jeu::~Jeu()
{
}

//Fonctions menu principal
void Jeu::DemarrerJeu()
{
	int choix = 0;
	int quit = 0;

	while (!quit) {
		std::cout << "\n\n\n\n\n\n\n\n\n\n----------------------------------------------------------------------------------------------------------------------";
		std::cout << "\n-----------------------------------------------------Menu Principal---------------------------------------------------";
		std::cout << "\n----------------------------------------------------------------------------------------------------------------------\n";
		std::cout << "\n\nQue souhaitez vous faire ?";
		std::cout << "\n  1. Jouer une partie";
		std::cout << "\n  2. Parametres du joueur 1";
		std::cout << "\n  3. Parametres du joueur 2";
		std::cout << "\n  4. Quitter";

		std::cout << "\n\nQuelle option choisissez vous ?\n";
		std::cin >> choix;

		switch (choix) {
		case 1:
			if (VerifierParamPartie()) {
				int quitGame = LancerPartie();
				if (quitGame == 0) {

				}
				if (quitGame == 1) {

				}
				if (quitGame == 2)
					quit = 1;
			}
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

//Option 1 : Lancer une partie
int Jeu::VerifierParamPartie()
{
	size_t vectorSize = m_vector.size();
	size_t fullTeamSize = 3;
	if (m_vector.at(0).size() == fullTeamSize && m_vector.at(1).size() == fullTeamSize) {
		for (int i = 0; i < vectorSize; i++) {
			for (int j = 0; j < fullTeamSize; j++) {
				if (m_vector.at(i).at(j)->GetWeapon() == nullptr) {
					std::cout << "\n\nLe " << j + 1 << "e personnage du joueur " << i + 1 << " ne possede pas d'arme.\nVeuillez equiper chaque personnage d'une arme.";
					return 0;
				}
			}
		}

		return 1;
	}
	else 
		std::cout << "\n\nAu moins l'un des deux joueurs n'a pas une equipe complete.\nVeuillez les completer pour pouvoir jouer.";

	return 0;
}

//Option 2 & 3 : Modifier les paramètres d'équipe des joueurs
void Jeu::ParamJoueur(int equipe)
{
	int choix = 0;
	int quit = 0;

	while (!quit) {
		std::cout << "\n\n\n\n\n\n\n\n\n\n----------------------------------------------------------------------------------------------------------------------";
		std::cout << "\n-------------------------------------------------Parametres du joueur "<< equipe+1 <<"-----------------------------------------------";
		std::cout << "\n----------------------------------------------------------------------------------------------------------------------\n";
		PrintJoueur(equipe);
		if (m_vector.at(equipe).size() != 3) {
			std::cout << "\n\n\tQue souhaitez vous faire ?";
			std::cout << "\n\t  1. Ajouter un personnage";
			std::cout << "\n\t  2. Retourner au menu precedent.";

			std::cout << "\n\n\tQuelle option choisissez vous ?\n\t";
			std::cin >> choix;
			switch (choix) {
			case 1:
				AjouterPersonnage(equipe);
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
			std::cin >> choix;
			switch (choix) {
			case 1:
				RemplacerPersonnage(equipe);
				break;

			case 2:
				RemplacerArme(equipe);
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

//Sous options : modifier la liste des personnages et armes de chaque joueur
void Jeu::AjouterPersonnage(int equipe)
{
	int choix = 0;
	int quit = 0;

	while (!quit) {
		std::cout << "\n\n\n\n\n\n\n\n\n\n----------------------------------------------------------------------------------------------------------------------";
		std::cout << "\n-------------------------------------------------Ajout d'un personnage------------------------------------------------";
		std::cout << "\n----------------------------------------------------------------------------------------------------------------------\n";
		m_parsing.at(equipe)->PrintCharacter();
		std::cout << "\n\n\tQuel personnage souhaitez vous ajouter a votre equipe ?\n\t";
		std::cin >> choix;

		if (choix > 0 && choix <= m_parsing.at(equipe)->GetCharacterSize()) {

			choix--;
			CCharacter* character = m_parsing.at(equipe)->ChooseCharacter(choix);
			std::string classe = character->GetClasse();

			if (classe == "Voleur") {
				CRogue* character2 = dynamic_cast<CRogue*>(character);
				CRogue* temp = new CRogue(character->GetNom(),character->GetVie(), character->GetWeapon(), character->GetEsquive(), character->GetVitesseBase(), character->GetAttaque(), character->GetDefense(), character->GetAgilite(), character->GetIntelligence(), character2->GetPoison());
				m_vector.at(equipe).push_back(temp);
			}
			if (classe == "Guerrier") {
				CWarrior* character2 = dynamic_cast<CWarrior*>(character);
				CWarrior* temp = new CWarrior(character->GetNom(), character->GetVie(), character->GetWeapon(), character->GetEsquive(), character->GetVitesseBase(), character->GetAttaque(), character->GetDefense(), character->GetAgilite(), character->GetIntelligence(), character2->GetParade());
				m_vector.at(equipe).push_back(temp);
			}
			if (classe == "Mage") {
				CMage* temp = new CMage(character->GetNom(), character->GetVie(), character->GetWeapon(), character->GetEsquive(), character->GetVitesseBase(), character->GetAttaque(), character->GetDefense(), character->GetAgilite(), character->GetIntelligence());
				m_vector.at(equipe).push_back(temp);
			}
			if (classe == "Archer") {
				CArcher* temp = new CArcher(character->GetNom(), character->GetVie(), character->GetWeapon(), character->GetEsquive(), character->GetVitesseBase(), character->GetAttaque(), character->GetDefense(), character->GetAgilite(), character->GetIntelligence());
				m_vector.at(equipe).push_back(temp);
			}
			m_parsing.at(equipe)->EnleverCharacter(character);
		}
		else 
			std::cout << "\n\n\t Choix incorrect.\n";

		quit = 1;
	}
}
void Jeu::RemplacerPersonnage(int i)
{
	int choix = 0;
	int quit = 0;

	while (!quit) {
		PrintJoueur(i);
		std::cout << "\n\n\tQuel est le personnage que vous souhaitez echanger ?\n\t";
		std::cin >> choix;

		if (choix > 0 && choix <= m_vector.at(i).size()) {

			int choix2;
			m_parsing.at(i)->PrintCharacter();
			std::cout << "\n\n\tPar quel personnage souhaitez vous le remplacer ?\n\t";
			std::cin >> choix2;

			if (choix2 > 0 && choix2 <= m_parsing.at(i)->GetCharacterSize()) {
				//On récupère le personnage, lui enlève l'équipement et le remet dans la liste du parsing puis on le delete du vector du joueur 

				/*
				CCharacter* character = m_vector.at(i).at(choix);
				std::string classe = character->GetClasse();
				character->SetWeapon(nullptr);

				if (classe == "Voleur") {
					CRogue* temp = new CRogue(character->GetNom(), character->GetVie(), character->GetWeapon(), character->GetEsquive(), character->GetVitesseBase(), character->GetAttaque(), character->GetDefense(), character->GetAgilite(), character->GetIntelligence(), character->GetCaracPartic());
					m_parsing.at(i)->AjouterCharacter(temp);
				}
				if (classe == "Guerrier") {
					CWarrior* temp = new CWarrior(character->GetNom(), character->GetVie(), character->GetWeapon(), character->GetEsquive(), character->GetVitesseBase(), character->GetAttaque(), character->GetDefense(), character->GetAgilite(), character->GetIntelligence(), character->GetCaracPartic());
					m_parsing.at(i)->AjouterCharacter(temp);
				}
				if (classe == "Mage") {
					CMage* temp = new CMage(character->GetNom(), character->GetVie(), character->GetWeapon(), character->GetEsquive(), character->GetVitesseBase(), character->GetAttaque(), character->GetDefense(), character->GetAgilite(), character->GetIntelligence());
					m_parsing.at(i)->AjouterCharacter(temp);
				}
				if (classe == "Archer") {
					CArcher* temp = new CArcher(character->GetNom(), character->GetVie(), character->GetWeapon(), character->GetEsquive(), character->GetVitesseBase(), character->GetAttaque(), character->GetDefense(), character->GetAgilite(), character->GetIntelligence());
					m_parsing.at(i)->AjouterCharacter(temp);
				}
				EnleverCharacter(character, i);

				
				//On récupère le personnage de la liste de la liste de parsing
				CCharacter* character2 = m_parsing.at(i)->ChooseCharacter(choix2);
				std::string classe2 = character->GetClasse();

				if (classe2 == "Voleur") {
					CRogue* temp = new CRogue(character2->GetNom(), character2->GetVie(), character2->GetWeapon(), character2->GetEsquive(), character2->GetVitesseBase(), character2->GetAttaque(), character2->GetDefense(), character2->GetAgilite(), character2->GetIntelligence(), character2->GetCaracPartic());
					m_vector.at(i).push_back(temp);
				}
				if (classe2 == "Guerrier") {
					CWarrior* temp = new CWarrior(character2->GetNom(), character2->GetVie(), character2->GetWeapon(), character2->GetEsquive(), character2->GetVitesseBase(), character2->GetAttaque(), character2->GetDefense(), character2->GetAgilite(), character2->GetIntelligence(), character2->GetCaracPartic());
					m_vector.at(i).push_back(temp);
				}
				if (classe2 == "Mage") {
					CMage* temp = new CMage(character2->GetNom(), character2->GetVie(), character2->GetWeapon(), character2->GetEsquive(), character2->GetVitesseBase(), character2->GetAttaque(), character2->GetDefense(), character2->GetAgilite(), character2->GetIntelligence());
					m_vector.at(i).push_back(temp);
				}
				if (classe2 == "Archer") {
					CArcher* temp = new CArcher(character2->GetNom(), character2->GetVie(), character2->GetWeapon(), character2->GetEsquive(), character2->GetVitesseBase(), character2->GetAttaque(), character2->GetDefense(), character2->GetAgilite(), character2->GetIntelligence());
					m_vector.at(i).push_back(temp);
				}
				m_parsing.at(i)->EnleverCharacter(character2);
				*/
			}
			else 
				std::cout << "\n\n\t Choix de personnage incorrect.\n";
			
		}
		else 
			std::cout << "\n\n\t Choix de personnage incorrect.\n";
		quit = 1;
	}
}
void Jeu::RemplacerArme(int i)
{
	int choix = 0;
	int quit = 0;

	while (!quit) {
		std::cout << "\n\n\n\n\n\n\n\n\n\n----------------------------------------------------------------------------------------------------------------------";
		std::cout << "\n---------------------------------------------------Remplacer une arme-------------------------------------------------";
		std::cout << "\n----------------------------------------------------------------------------------------------------------------------\n";
		PrintJoueur(i);
		std::cout << "\n\n\tQuel est le personnage dont vous souhaitez changer l'equipement ?\n\t";
		std::cin >> choix;

		if (choix > 0 && choix <= m_vector.at(i).size()) {
			choix--;
			CCharacter* character = m_vector.at(i).at(choix);
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
			std::cin >> choix;
			
			if (choix > 0 && choix <= m_parsing.at(i)->GetWeaponSize(type1, type2)) {
				CWeapon* weapon = m_parsing.at(i)->ChooseWeapon(type1, type2, choix);
				std::string type = weapon->GetType();

				if (type == "Epee") {
					CSword* weapon2 = dynamic_cast<CSword*>(weapon);
					CSword* temp = new CSword(weapon->GetType(), weapon->GetNom(), weapon->GetDegats(), weapon->GetCritique(), weapon->GetVie(), weapon->GetEsquive(), weapon->GetVitesse(), weapon->GetAttaque(), weapon->GetDefense(), weapon->GetAgilite(), weapon->GetIntelligence(), weapon2->GetDurabiliteInitiale());
					character->SetWeapon(temp);
				}
				if (type == "Dague") {
					CDagger* weapon2 = dynamic_cast<CDagger*>(weapon);
					CDagger* temp = new CDagger(weapon->GetType(), weapon->GetNom(), weapon->GetDegats(), weapon->GetCritique(), weapon->GetVie(), weapon->GetEsquive(), weapon->GetVitesse(), weapon->GetAttaque(), weapon->GetDefense(), weapon->GetAgilite(), weapon->GetIntelligence(), weapon2->GetDurabiliteInitiale());
					character->SetWeapon(temp);
				}
				if (type == "Arc") {
					CBow* weapon2 = dynamic_cast<CBow*>(weapon);
					CBow* temp = new CBow(weapon->GetType(), weapon->GetNom(), weapon->GetDegats(), weapon->GetCritique(), weapon->GetVie(), weapon->GetEsquive(), weapon->GetVitesse(), weapon->GetAttaque(), weapon->GetDefense(), weapon->GetAgilite(), weapon->GetIntelligence(), weapon2->GetNbFlechesBase());
					character->SetWeapon(temp);
				}
				if (type == "Baton") {
					CStaff* weapon2 = dynamic_cast<CStaff*>(weapon);
					CStaff* temp = new CStaff(weapon->GetType(), weapon->GetNom(), weapon->GetDegats(), weapon->GetCritique(), weapon->GetVie(), weapon->GetEsquive(), weapon->GetVitesse(), weapon->GetAttaque(), weapon->GetDefense(), weapon->GetAgilite(), weapon->GetIntelligence(), weapon2->GetCout());
					character->SetWeapon(temp);
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

//Option 4 : Quitter le jeu
void Jeu::ViderVariables()
{

}

//Fonctions déroulement partie 
int Jeu::LancerPartie()
{
	int quit = 0;
	int choix = 0;

	int gagnant = 0;
	int TourSuivant = 1;

	int joueur = 0;

	int vitesse = 0;
	int vitesseIdentique = 0;
	int vitesseReference = 0;

	CCharacter* personnageChoisi = nullptr;

	std::cout << "\n\n\n\n\n\n\n\n\n\n----------------------------------------------------------------------------------------------------------------------";
	std::cout << "\n---------------------------------------------------Debut de la partie-------------------------------------------------";
	std::cout << "\n----------------------------------------------------------------------------------------------------------------------\n";
	while (!quit) {

		//Au début de chaque tour, on vérifie si tous les personnages d'une liste sont morts

		/*gagnant = VerifierMorts();
		if (gagnant != 0) {
			std::cout << "\nLe joueur " << gagnant << " a gagne.";
			quit = 1;
		}*/
		
		std::cout << "\n\n\n\n\n\n\n\n\n\n----------------------------------------------------------------------------------------------------------------------";
		std::cout << "\n------------------------------------------------Debut du tour : joueur " << joueur+1 << "----------------------------------------------";
		std::cout << "\n----------------------------------------------------------------------------------------------------------------------\n";
		/*else {*/
			//Si une action a été menée a bien par le personnage précédent, on choisi un nouveau personnage
			if (TourSuivant) {	
				size_t vectorSize = m_vector.size();
				size_t fullTeamSize = m_vector.at(0).size();
				//On choisi le Personnage dont ca va être le tour
				for (int i = 0; i < vectorSize; i++) {
					for (int j = 0; j < fullTeamSize; j++) {
						if (m_vector.at(i).at(j)->GetVie() != 0) {					//Si le personnage n'est pas mort
							if (!vitesseReference) {								//On le choisi comme valeur de référence si il n'y en a pas déjà
								vitesse = m_vector.at(i).at(j)->GetVitesse();
								vitesseReference = 1;
							}
							else {
								if (vitesse > m_vector.at(i).at(j)->GetVitesse()) {	//Si un personnage a une vitesse inférieure, on le met comme référence.
									vitesse = m_vector.at(i).at(j)->GetVitesse();
									vitesseIdentique = 0;
									personnageChoisi = m_vector.at(i).at(j);
									joueur = i;
								}
								if (vitesse == m_vector.at(i).at(j)->GetVitesse()) {//Si il a la même vitesse que la plus petite vitesse on incrémente la variable indiquant que deux personnages ont une vitesses identique.
									personnageChoisi = nullptr;
									vitesseIdentique++;
								}
							}
						}
					}
				}
				if (vitesseIdentique != 0) {//Si deux personnages (ou plus) ont la meme vitesse
					int choixPersonnage = rand() % vitesseIdentique;
					vitesseIdentique = 0;

					for (int i = 0; i < vectorSize; i++) {
						for (int j = 0; j < fullTeamSize; j++) {
							if (m_vector.at(i).at(j)->GetVie() != 0) {					//Si le personnage n'est pas mort
								if (vitesse == m_vector.at(i).at(j)->GetVitesse()) {	//Si il a la même vitesse que la plus petite vitesse on incrémente la variable indiquant que deux personnages ont une vitesses identique.
									if (vitesseIdentique == choixPersonnage) {			//Si le personnage est celui choisi par le tirage au sort.
										personnageChoisi = m_vector.at(i).at(j);
										joueur = i;
									}
									vitesseIdentique++;
								}
							}
						}
					}
				}
				
				for (int i = 0; i < vectorSize; i++) {
					for (int j = 0; j < fullTeamSize; j++) {
						if (m_vector.at(i).at(j)->GetVie() != 0) {	//Si le personnage n'est pas mort on met a jour sa vitesse
							m_vector.at(i).at(j)->SetVitesse(m_vector.at(i).at(j)->GetVitesse()-vitesse);
						}
					}
				}

				personnageChoisi->SetVitesse(personnageChoisi->GetVitesseBase());
				personnageChoisi->DebuterTour();
				vitesseIdentique = 0;
				vitesseReference = 0;
			}
			
			personnageChoisi->Print();

			std::cout << "\n\nQue souhaitez vous faire ?";
			std::cout << "\n  1. Attaquer sans arme.";
			std::cout << "\n  2. Attaquer avec arme.";
			std::cout << "\n  3. Utiliser une capacite speciale.";

			std::cout << "\n\n\n";
			std::cin >> choix;


			switch (choix) {
			case 1:
				TourSuivant = Attaquer(personnageChoisi, (joueur+1)%2, 0);
				break;
				
			case 2:
				TourSuivant = Attaquer(personnageChoisi, (joueur+1)%2, 1);
				break;

			case 3:
				//TourSuivant = Special(personnageChoisi, joueur);
				break;

			default:
				TourSuivant = 0;
				break;
			}
		//}
	}
	return Rejouer();
}

int Jeu::Attaquer(CCharacter* ccharacter, int equipe, int arme)
{
	int choix = 0;
	int quit = 0;
	int tableau[3] = { -1,-1,-1 };

	while (!quit) {
		std::cout << "\n\n\n\n\n\n\n\n\n\n----------------------------------------------------------------------------------------------------------------------";
		std::cout << "\n---------------------------------------------------Cible de l'attaque-------------------------------------------------";
		std::cout << "\n----------------------------------------------------------------------------------------------------------------------\n";
		size_t fullTeamSize = m_vector.at(equipe).size();
		int nbAfficher = 0;
		int nbFurtif = 0;
		int nbHurlement = 0;
		int numeroPersonnage = 0;
		
		//Récupère le nombre de personnages furtifs et le nombre de personnages a afficher
		for (int j = 0; j < fullTeamSize; j++) {
			if (m_vector.at(equipe).at(j)->GetVie() != 0) {
				nbAfficher++;
				if (m_vector.at(equipe).at(j)->GetClasse() == "Voleur") {
					CRogue* ptrVoleur = dynamic_cast<CRogue*>(m_vector.at(equipe).at(j));
					if (ptrVoleur->GetNbToursFurtif() > 0) {
						nbFurtif++;
					}
				}
				if (m_vector.at(equipe).at(j)->GetClasse() == "Guerrier") {
					CWarrior* ptrGuerrier = dynamic_cast<CWarrior*>(m_vector.at(equipe).at(j));
					if (ptrGuerrier->GetNbToursHurlement() > 0) {
						nbHurlement++;
					}
				}
			}
		}	 

		//Si au moins un personnage adverse, on l'affiche
		if (nbHurlement != 0) {
			nbAfficher = 0;
			for (int j = 0; j < fullTeamSize; j++) {
				if (m_vector.at(equipe).at(j)->GetVie() != 0) {
					if (m_vector.at(equipe).at(j)->GetClasse() == "Guerrier") {
						CWarrior* ptrGuerrier = dynamic_cast<CWarrior*>(m_vector.at(equipe).at(j));
						if (ptrGuerrier->GetNbToursHurlement() <= 0) {
							tableau[nbAfficher] = j;
							nbAfficher++;
							std::cout << "\nPersonnage adverse numero " << nbAfficher << " : \n";
							m_vector.at(equipe).at(j)->Print();
						}
					}
				}
				std::cout << "\n";
			}
		}
		else {
			//Si il n'y a que des voleurs furtifs, on les affiche 
			if (nbAfficher - nbFurtif == 0) {
				nbAfficher = 0;
				for (int j = 0; j < fullTeamSize; j++) {
					if (m_vector.at(equipe).at(j)->GetVie() != 0) {
						tableau[nbAfficher] = j;
						nbAfficher++;
						std::cout << "\nPersonnage adverse numero " << nbAfficher << " : \n";
						m_vector.at(equipe).at(j)->Print();
					}
					std::cout << "\n";
				}
			}

			//Sinon on affiche que les personnages adverses non furtifs
			else {
				nbAfficher = 0;
				for (int j = 0; j < fullTeamSize; j++) {
					if (m_vector.at(equipe).at(j)->GetVie() != 0) {
						if (m_vector.at(equipe).at(j)->GetClasse() == "Voleur") {
							CRogue* ptrVoleur = dynamic_cast<CRogue*>(m_vector.at(equipe).at(j));
							if (ptrVoleur->GetNbToursFurtif() <= 0) {
								tableau[nbAfficher] = j;
								nbAfficher++;
								std::cout << "\nPersonnage adverse numero " << nbAfficher << " : \n";
								m_vector.at(equipe).at(j)->Print();
							}
						}
						else {
							tableau[nbAfficher] = j;
							nbAfficher++;
							std::cout << "\nPersonnage adverse numero " << nbAfficher << " : \n";
							m_vector.at(equipe).at(j)->Print();
						}
					}
					std::cout << "\n";
				}
			}
		}
		

		std::cout << "\nChoix numero " << nbAfficher+1 << " : revenir au menu precedent.";

		std::cout << "\n\nQuel personnage souhaitez vous attaquer ?\n";
		std::cin >> choix;
		choix--;
		if (choix < nbAfficher && choix > -1) {
			if (arme == 0)
				ccharacter->AttaquerSansArme(m_vector.at(equipe).at(tableau[choix]));
			else
				ccharacter->AttaquerAvecArme(m_vector.at(equipe).at(tableau[choix]));
			return 1;
		}
		else {
			if (choix == nbAfficher) {
				quit = 1;
			}
		}
	}
	return 0;
}

int Jeu::Rejouer() {

	int choix = 0;
	int quit = 0;

	while (!quit) {
		std::cout << "\n\nQue souhaitez vous faire ?";
		std::cout << "\n  1. Rejouer une partie en conservant les parametres d'equipe de chaque joueur.";
		std::cout << "\n  2. Revenir au menu principal.";
		std::cout << "\n  3. Quitter le jeu.";

		std::cout << "\n\nQuelle option choisissez vous ? \n";
		std::cin >> choix;

		switch (choix) {
		case 1:
			quit = 1;
			return 0;
			break;

		case 2:
			quit = 1;
			return 1;
			break;

		case 3:
			quit = 1;
			return 2;
			break;

		default:
			break;
		}
	}
}

//Fontions annexes 
void Jeu::PrintJoueur(int equipe)
{
	std::cout << "\n\tPersonnages du joueur " << equipe + 1 << " :";
	std::vector<CCharacter*>::iterator it;
	int x = 1;

	for (it = m_vector.at(equipe).begin(); it != m_vector.at(equipe).end(); it++) {
		std::cout << "\n\n\tPersonnage " << x << " : ";
		(*it)->Print();
		std::cout << "\n";
		x++;
	}
}
void Jeu::EnleverCharacter(CCharacter* ccharacter, int equipe)
{

	if (ccharacter == nullptr)
		return;

	std::vector<CCharacter*>::iterator it;

	for (it = m_vector.at(equipe).begin(); it != m_vector.at(equipe).end(); it++)
	{
		if (*it == ccharacter)
		{
			delete* it;
			m_vector.at(equipe).erase(it);
			break;
		}
	}
}
int Jeu::VerifierMorts(int equipe) {
	size_t fullTeamSize = m_vector.at(0).size();
	int nbMorts = 0;
	for (int j = 0; j < fullTeamSize; j++) {
		if (m_vector.at(equipe).at(j)->GetVie() == 0) {
			nbMorts++;
			if (nbMorts == 3) {
				return equipe;
			}
		}
	}
	
	return 0;
}