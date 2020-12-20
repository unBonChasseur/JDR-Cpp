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
				while (quitGame == 0) {
					quitGame = LancerPartie();
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
			break;

		default:
			break;
		}

	}
	ViderVariables();
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
void Jeu::RemplacerPersonnage(int equipe)
{
	int choix = 0;
	int quit = 0;

	while (!quit) {
		PrintJoueur(equipe);
		std::cout << "\n\n\tQuel est le personnage que vous souhaitez echanger ?\n\t";
		std::cin >> choix;

		if (choix > 0 && choix <= m_vector.at(equipe).size()) {
			choix--;
			int choix2;
			m_parsing.at(equipe)->PrintCharacter();
			std::cout << "\n\n\tPar quel personnage souhaitez vous le remplacer ?\n\t";
			std::cin >> choix2;

			if (choix2 > 0 && choix2 <= m_parsing.at(equipe)->GetCharacterSize()) {
				choix2--;
				//On récupère le personnage, lui enlève l'équipement et le remet dans la liste du parsing puis on le delete du vector du joueur 
				
				m_parsing.at(equipe)->AjouterCharacter(m_vector.at(equipe).at(choix));
				m_vector.at(equipe).erase(m_vector.at(equipe).begin()+choix);
				m_vector.at(equipe).push_back(m_parsing.at(equipe)->ChooseCharacter(choix2));
				m_parsing.at(equipe)->EnleverCharacter(m_parsing.at(equipe)->ChooseCharacter(choix2));
				
			}
			else 
				std::cout << "\n\n\t Choix de personnage incorrect.\n";
			
		}
		else 
			std::cout << "\n\n\t Choix de personnage incorrect.\n";
		quit = 1;
	}
}
void Jeu::RemplacerArme(int equipe)
{
	int choix = 0;
	int quit = 0;

	while (!quit) {
		std::cout << "\n\n\n\n\n\n\n\n\n\n----------------------------------------------------------------------------------------------------------------------";
		std::cout << "\n---------------------------------------------------Remplacer une arme-------------------------------------------------";
		std::cout << "\n----------------------------------------------------------------------------------------------------------------------\n";
		PrintJoueur(equipe);
		std::cout << "\n\n\tQuel est le personnage dont vous souhaitez changer l'equipement ?\n\t";
		std::cin >> choix;

		if (choix > 0 && choix <= m_vector.at(equipe).size()) {
			choix--;
			CCharacter* character = m_vector.at(equipe).at(choix);
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
			m_parsing.at(equipe)->PrintWeapon(type1, type2);

			std::cout << "\n\n\tQuelle arme souhaitez vous lui donner ?\n\t";
			std::cin >> choix;
			
			if (choix > 0 && choix <= m_parsing.at(equipe)->GetWeaponSize(type1, type2)) {
				CWeapon* weapon = m_parsing.at(equipe)->ChooseWeapon(type1, type2, choix);
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

	int gagnant = 2;
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
		for (int i = 0; i < m_vector.size(); i++) {
			gagnant = VerifierMorts(i);
			if (gagnant != 2) {
				std::cout << "\n\n\n\n\n\n\n\n\n\n----------------------------------------------------------------------------------------------------------------------";
				std::cout << "\n----------------------------------------------------Fin de la partie--------------------------------------------------";
				std::cout << "\n----------------------------------------------------------------------------------------------------------------------\n";
				std::cout << "\n\n\n\t\t\t Felicitations : Le joueur " << gagnant+1 << " a gagne.";
				quit = 1;
			}
		}
		if (quit != 1) {

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
								personnageChoisi = m_vector.at(i).at(j);
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
							m_vector.at(i).at(j)->SetVitesse(m_vector.at(i).at(j)->GetVitesse() - vitesse);
						}
					}
				}

				personnageChoisi->SetVitesse(personnageChoisi->GetVitesseBase());
				std::cout << "\n\n\n\n\n\n\n\n\n\n----------------------------------------------------------------------------------------------------------------------";
				std::cout << "\n------------------------------------------------Debut du tour : joueur " << joueur + 1 << "----------------------------------------------";
				std::cout << "\n----------------------------------------------------------------------------------------------------------------------\n";
				personnageChoisi->DebuterTour();
				vitesseIdentique = 0;
				vitesseReference = 0;
			}
			else {
				std::cout << "\n\n\n\n\n\n\n\n\n\n----------------------------------------------------------------------------------------------------------------------";
				std::cout << "\n------------------------------------------------Continuite du tour joueur " << joueur + 1 << "-------------------------------------------";
				std::cout << "\n----------------------------------------------------------------------------------------------------------------------\n";
			}
			if (personnageChoisi->GetVie() == 0) {
				std::cout << "\nVotre personnage est mort du poison au debut de ce tour.";
			}
			else {
				personnageChoisi->Print();

				std::cout << "\n\nQue souhaitez vous faire ?";
				std::cout << "\n  1. Attaquer sans arme.";
				std::cout << "\n  2. Attaquer avec arme.";
				std::cout << "\n  3. Utiliser une capacite speciale.";
				std::cout << "\n  4. Afficher les equipes.";

				std::cout << "\n\n\n";
				std::cin >> choix;
				switch (choix) {
				case 1 :
					TourSuivant = Attaquer(personnageChoisi, (joueur + 1) % 2, 0);
					break;

				case 2 :
					TourSuivant = Attaquer(personnageChoisi, (joueur + 1) % 2, 1);
					break;

				case 3 :
					TourSuivant = Special(personnageChoisi, joueur);
					break;

				case 4 : 
					TourSuivant = 0;
					PrintJoueur(0);
					PrintJoueur(1);
					break;

				default:
					TourSuivant = 0;
					break;
				}
			}
		}
	}
	return Rejouer();
}
int Jeu::Attaquer(CCharacter* ccharacter, int equipe, int arme)
{
	int choix = 0;
	int quit = 0;
	int tableau[3] = { -1,-1,-1 };
	int nbRetourne = 0;
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
						if (ptrGuerrier->GetNbToursHurlement() > 0) {
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
							if (ptrVoleur->GetNbToursFurtif() == 0) {
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
			if (arme == 0) {			//Si on utilise pas d'arme
				nbRetourne = ccharacter->AttaquerSansArme(m_vector.at(equipe).at(tableau[choix]));//Si l'attaque a ete effectuee, passe nbRetourne a 1
				quit = 1;
			}
			else {						//Si on utilise une arme
				nbRetourne = ccharacter->AttaquerAvecArme(m_vector.at(equipe).at(tableau[choix]));//Si l'attaque a ete effectuee, passe nbRetourne a 1
				quit = 1;
			}
			
		}
		else {
			if (choix == nbAfficher) {
				quit = 1;
			}
		}
	}
	return nbRetourne;
}
int Jeu::Special(CCharacter* ccharacter, int equipe)
{
	int choix = 0;
	int quit = 0;
	int nbRetourne = 0;
	int nbAfficher = 0;
	int tableau[3] = {-1,-1,-1};

	while (!quit) {
		std::cout << "\n\n\n\n\n\n\n\n\n\n----------------------------------------------------------------------------------------------------------------------";
		std::cout << "\n---------------------------------------------------Capacite speciale--------------------------------------------------";
		std::cout << "\n----------------------------------------------------------------------------------------------------------------------\n";
		
		if (ccharacter->GetClasse() == "Voleur") {
			CRogue* rogue = dynamic_cast<CRogue*>(ccharacter);
			std::cout << "\n\nQue souhaitez vous faire ?";
			std::cout << "\n  1. Vous rendre furtif.";
			std::cout << "\n  2. Revenir au menu precedent.";

			std::cout << "\n\n\n";
			std::cin >> choix;
			switch (choix) {
			case 1:
				if (rogue->GetCDFurtif() == 0) {
					rogue->Furtivite();
					nbRetourne = 1;
					quit = 1;
				}
				else {
					std::cout << "\nVous ne pouvez pas vous rendre furtif car cette compétence est en cooldown : " << rogue->GetCDFurtif() << " tour(s) avant la prochaine utilisation.";
				}
				break;
			
			case 2 :
				quit = 1;
				break;

			default:
				
				break;
			}
		}
		
		if (ccharacter->GetClasse() == "Guerrier") {
			CWarrior* warrior = dynamic_cast<CWarrior*>(ccharacter);
			std::cout << "\n\nQue souhaitez vous faire ?";
			std::cout << "\n  1. Utiliser un hurlement.";
			std::cout << "\n  2. Reparer une arme (melee uniquement).";
			std::cout << "\n  3. Revenir au menu precedent.";

			std::cout << "\n\n\n";
			std::cin >> choix;
			switch (choix) {
			case 1:
				if (warrior->GetCDHurlement() == 0) {
					warrior->Hurler();
					nbRetourne = 1;
					quit = 1;
				}
				else {
					std::cout << "\nVous ne pouvez pas vous rendre furtif car cette compétence est en cooldown : " << warrior->GetCDHurlement() << " tour(s) avant la prochaine utilisation.";
				}
				break;

			case 2:
				for (int j = 0; j < m_vector.at(equipe).size(); j++) {
					if (m_vector.at(equipe).at(j)->GetVie() != 0) {
						tableau[nbAfficher] = j;
						nbAfficher++;
						std::cout << "\nPersonnage allie numero " << nbAfficher << " : \n";
						m_vector.at(equipe).at(j)->Print();
					}
					std::cout << "\n";
				}
				std::cout << "\nChoix numero " << nbAfficher + 1 << " : revenir au menu precedent.";

				std::cout << "\n\nL'arme de quel personnage souhaitez vous reparer ?\n";
				std::cin >> choix;
				choix--;

				if (choix < nbAfficher && choix > -1) {
					nbRetourne = warrior->ReparerArme(m_vector.at(equipe).at(tableau[choix]));
					quit = 1;
				}
				else {
					if (choix != nbAfficher + 1)
						std::cout << "\nChoix incorrect.";
				}

				break;

			case 3:
				quit = 1;
				break;

			default:
				break;
			}
		}

		if (ccharacter->GetClasse() == "Mage") {
			CMage* mage = dynamic_cast<CMage*>(ccharacter);
			std::cout << "\n\nQue souhaitez vous faire ?";
			std::cout << "\n  1. Regenerer son mana.";
			std::cout << "\n  2. Soigner un allie.";
			std::cout << "\n  3. Enchanter l'arme d'un allie.";
			std::cout << "\n  4. Revenir au menu precedent.";

			std::cout << "\n\n\n";
			std::cin >> choix;
			switch (choix) {
			case 1:
				
				mage->RegenererMana();
				nbRetourne = 1;
				quit = 1;
				break;

			case 2:
				if (mage->GetCDSoin() == 0) {
					nbAfficher = 0;
					for (int j = 0; j < m_vector.at(equipe).size(); j++) {
						if (m_vector.at(equipe).at(j)->GetVie() != 0) {
							tableau[nbAfficher] = j;
							nbAfficher++;
							std::cout << "\nPersonnage allie numero " << nbAfficher << " : \n";
							m_vector.at(equipe).at(j)->Print();
						}
						std::cout << "\n";
					}
					std::cout << "\nChoix numero " << nbAfficher + 1 << " : revenir au menu precedent.";

					std::cout << "\n\nQuel personnage souhaitez vous soigner ?\n";
					std::cin >> choix;
					choix--;

					if (choix < nbAfficher && choix > -1) {
						nbRetourne = mage->Soigner(m_vector.at(equipe).at(tableau[choix]));
						quit = 1;
					}
					else {
						if(choix != nbAfficher+1)
							std::cout << "\nChoix incorrect.";
					}
				}
				else {
					std::cout << "\nVous ne pouvez pas soigner un allie car cette compétence est en cooldown : " << mage->GetCDSoin() << " tour(s) avant la prochaine utilisation.";
				}
				break;

			case 3:
				if (mage->GetCDEnchantement() == 0) {
					nbAfficher = 0;
					for (int j = 0; j < m_vector.at(equipe).size(); j++) {
						if (m_vector.at(equipe).at(j)->GetVie() != 0) {
							tableau[nbAfficher] = j;
							nbAfficher++;
							std::cout << "\nPersonnage allie numero " << nbAfficher << " : \n";
							m_vector.at(equipe).at(j)->Print();
						}
						std::cout << "\n";
					}
					std::cout << "\nChoix numero " << nbAfficher + 1 << " : revenir au menu precedent.";

					std::cout << "\n\nQuelle arme souhaitez vous enchanter ?\n";
					std::cin >> choix;
					choix--;

					if (choix < nbAfficher && choix > -1) {
						nbRetourne = mage->Enchanter(m_vector.at(equipe).at(tableau[choix]));
						quit = 1;
					}
					else {
						if (choix != nbAfficher + 1)
							std::cout << "\nChoix incorrect.";
					}
				}
				else {
					std::cout << "\nVous ne pouvez pas soigner un allie car cette compétence est en cooldown : " << mage->GetCDEnchantement() << " tour(s) avant la prochaine utilisation.";
				}
				break;

			case 4 :
				quit = 1;
				break;

			default:
				break;
			}
		}

		if (ccharacter->GetClasse() == "Archer") {
			CArcher* archer = dynamic_cast<CArcher*>(ccharacter);
			std::cout << "\n\nQue souhaitez vous faire ?";
			std::cout << "\n  1. Viser.";
			std::cout << "\n  2. Guerir du poison un allie.";
			std::cout << "\n  3. Revenir au menu precedent.";

			std::cout << "\n\n\n";
			std::cin >> choix;
			switch (choix) {
			case 1:

				nbRetourne = archer->Viser();
				quit = 1;
				break;

			case 2:
				if (archer->GetNbGuerison() != 0) {
					int nbAfficher = 0;
					for (int j = 0; j < m_vector.at(equipe).size(); j++) {
						if (m_vector.at(equipe).at(j)->GetVie() != 0 && m_vector.at(equipe).at(j)->IsEmpoisonne()) {
							tableau[nbAfficher] = j;
							nbAfficher++;
							std::cout << "\nPersonnage allie numero " << nbAfficher << " : \n";
							m_vector.at(equipe).at(j)->Print();
						}
						std::cout << "\n";
					}
					std::cout << "\nChoix numero " << nbAfficher + 1 << " : revenir au menu precedent.";

					std::cout << "\n\nQuel personnage souhaitez vous soigner du poison ?\n";
					std::cin >> choix;
					choix--;

					if (choix < nbAfficher && choix > -1) {
						archer->GuerirPoison(m_vector.at(equipe).at(tableau[choix]));
						nbRetourne = 1;
						quit = 1;
					}
					else {
						if (choix != nbAfficher + 1)
							std::cout << "\nChoix incorrect.";
					}
				}
				else {
					std::cout << "\nVous ne pouvez plus soigner d'allie du poison de la partie avec ce personnage.";
				}
				break;

			case 3:
				quit = 1;
				break;

			default:
				break;
			}
		}

	}
	return nbRetourne;
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

		if (choix > 0 && choix <= 3) {
			quit = 1;
		}
	}
	choix--;
	for (int i = 0; i < m_vector.size(); i++) {
		for (int j = 0; j < m_vector.at(i).size();j++){
			m_vector.at(i).at(j)->Reinitialiser();
			m_vector.at(i).at(j)->Print();
		}
	}
	return choix;
}

//Fontions annexes 
void Jeu::PrintJoueur(int equipe)
{
	std::cout << "\n----------------------------------------------------------------------------------------------------------------------";
	std::cout << "\n-------------------------------------------------Personnages du joueur "<< equipe+1 <<"-----------------------------------------------";
	std::cout << "\n----------------------------------------------------------------------------------------------------------------------\n";
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
			m_vector.at(equipe).erase(it);
			delete* it;
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
	
	return 2;
}
