#include "Parsing.h"


void Parsing::LectureArmes() {
	std::string line;
	std::ifstream myFile("data\\weapons.jdc");
	if (myFile.is_open())
	{
		int i = 0;
		//statistiques liées à l'arme
		std::string type = "";
		std::string nom = "";
		int degats = 0;
		float critique = 0;
		float bonusDegatsArme = 0;

		//statistiques liées aux personnage porteur
		int vie = 0;
		float esquive = 0;
		int vitesse = 0;
		int attaque = 0;
		int defense = 0;
		int agilite = 0;
		int intelligence = 0;
		int caracArme = 0;

		while (myFile >> line) {
			if (line != "EndWeapon") {
				if (line == "Type" || line == "Nom" || line == "Degat" || line == "Critique" || line == "HP" || line == "Attack" || line == "Defense" || line == "Agilite" || line == "Intelligence" || line == "Fleche" || line == "Durabilite" || line == "Cout") {
					if (line == "Type") {
						myFile >> type;
					}
					if (line == "Nom") {
						myFile >> nom;
					}
					if (line == "Degat") {
						myFile >> degats;
					}
					if (line == "Critique") {
						myFile >> critique;
					}
					if (line == "HP") {
						myFile >> vie;
					}
					if (line == "Attack") {
						myFile >> attaque;
					}
					if (line == "Defense") {
						myFile >> defense;
					}
					if (line == "Agilite") {
						myFile >> agilite;
					}
					if (line == "Intelligence") {
						myFile >> intelligence;
					}
					if (line == "Fleche" || line == "Durabilite" || line == "Cout") {
						myFile >> caracArme;
					}
				}
				else {
					nom += " " + line;
				}
			}
			else {
				if (type == "Baton") {
					CStaff *a = new CStaff(type, nom, degats, critique, bonusDegatsArme, vie, esquive, vitesse, attaque, defense, agilite, intelligence, caracArme);
					m_weapon.push_back(a);
				}
				if (type == "Dague") {
					CDagger *a = new CDagger(type, nom, degats, critique, bonusDegatsArme, vie, esquive, vitesse, attaque, defense, agilite, intelligence, caracArme);
					m_weapon.push_back(a);
				}
				if (type == "Epee") {
					CSword *a = new CSword(type, nom, degats, critique, bonusDegatsArme, vie, esquive, vitesse, attaque, defense, agilite, intelligence, caracArme);
					m_weapon.push_back(a);
				}
				if (type == "Arc") {
					CBow *a = new CBow(type, nom, degats, critique, bonusDegatsArme, vie, esquive, vitesse, attaque, defense, agilite, intelligence, caracArme);
					m_weapon.push_back(a);
				}
				
				//statistiques liées à l'arme
				type = "";
				nom = "";
				degats = 0;
				critique = 0;
				bonusDegatsArme = 0;

				//statistiques liées aux personnage porteur
				vie = 0;
				esquive = 0;
				vitesse = 0;
				attaque = 0;
				defense = 0;
				agilite = 0;
				intelligence = 0;
				caracArme = 0;

			}
		}
		myFile.close();
	}
	else
		std::cout << "Impossible d’ouvrir le fichier \n";

}

void Parsing::LecturePersonnages() {
	std::string line;
	std::ifstream myFile("data\\characters.jdc");
	if (myFile.is_open())
	{
		std::string classe = "";
		std::string nom = "";
		int vie = 0;
		float esquive = 0;
		int vitesse = 0;
		int attaque = 0;
		int defense = 0;
		int agilite = 0;
		int intelligence = 0;
		float special = 0;

		while (myFile >> line) {
			if (line != "EndCharacter") {
				if (line == "Classe" || line == "Nom" || line == "HP" || line == "Dodge" || line == "Vitesse" || line == "Attaque" || line == "Defense" || line == "Agilite" || line == "Intelligence" || line == "Special") {
					if (line == "Classe") {
						myFile >> classe;
					}
					if (line == "Nom") {
						myFile >> nom;
					}
					if (line == "HP") {
						myFile >> vie;
					}
					if (line == "Dodge") {
						myFile >> esquive;
					}
					if (line == "Vitesse") {
						myFile >> vitesse;
					}
					if (line == "Attaque") {
						myFile >> attaque;
					}
					if (line == "Defense") {
						myFile >> defense;
					}
					if (line == "Agilite") {
						myFile >> agilite;
					}
					if (line == "Intelligence") {
						myFile >> intelligence;
					}
					if (line == "Special") {
						myFile >> special;
					}
				}
				else {
					nom += " " + line;
				}
			}
			else {
				if (classe == "Mage") {
					CMage *a = new CMage(nom, vie, nullptr, esquive, vitesse, attaque, defense, agilite, intelligence);
					m_character.push_back(a);
				}
				if (classe == "Voleur") {
					CRogue *a = new CRogue(nom, vie, nullptr, esquive, vitesse, attaque, defense, agilite, intelligence, special);
					m_character.push_back(a);
				}
				if (classe == "Guerrier") {
					CWarrior *a = new CWarrior(nom, vie, nullptr, esquive, vitesse, attaque, defense, agilite, intelligence, special);
					m_character.push_back(a);
				}
				if (classe == "Archer") {
					CArcher *a = new CArcher(nom, vie, nullptr,esquive, vitesse, attaque, defense, agilite, intelligence);
					m_character.push_back(a);
				}



				classe = "";
				nom = "";
				vie = 0;
				esquive = 0;
				vitesse = 0;
				attaque = 0;
				defense = 0;
				agilite = 0;
				intelligence = 0;
				special = 0;

			}
		}
		myFile.close();
	}
	else
		std::cout << "Impossible d’ouvrir le fichier \n";

}

Parsing::Parsing()
{
	LectureArmes();
	LecturePersonnages();
}

Parsing::~Parsing()
{
}

CCharacter* Parsing::ChooseCharacter(int numero)
{
	CCharacter* res = nullptr;

	for (size_t i = 0; i < m_character.size(); i++)
	{
		if (i == numero)
		{
			res = m_character.at(i);
		}
	}

	return res;
}

void Parsing::PrintCharacter()
{
	int j = 1;
	for (size_t i = 0; i < m_character.size(); i++)
	{
		std::cout << "\n\nChoix : " << j;
		m_character.at(i)->print();
		j++;
	}

	std::cout << "\n\nChoix : " << j << " ";
	std::cout << "\n\tRevenir aux parametres du joueur.";
}

void Parsing::PrintWeapon()
{
	int j = 1;
	for (size_t i = 0; i < m_weapon.size(); i++)
	{
		std::cout << "\n\nChoix : " << j;
		m_weapon.at(i)->print();
		j++;
	}

	std::cout << "\n\nChoix : " << j << " ";
	std::cout << "\n\tRevenir aux parametres du joueur.";

}

int Parsing::GetWeaponSize() {
	return m_weapon.size();
}

int Parsing::GetCharacterSize() {
	return m_character.size();
}
