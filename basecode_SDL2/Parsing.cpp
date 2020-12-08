#include "Parsing.h"


void Parsing::LectureArmes(std::vector<CWeapon*> vector) {
	std::string line;
	std::ifstream myFile("data\\weapons.jdc");
	if (myFile.is_open())
	{
		//statistiques liées à l'arme
		std::string m_type = "";
		std::string m_nom = "";
		int m_degats = 0;
		float m_critique = 0;
		float m_bonusDegatsArme = 0;

		//statistiques liées aux personnage porteur
		int m_vie = 0;
		float m_esquive = 0;
		int m_vitesseBase = 0;
		int m_attaque = 0;
		int m_defense = 0;
		int m_agilite = 0;
		int m_intelligence = 0;
		int m_CaracArme = 0;

		while (myFile >> line) {
			if (line != "EndWeapon") {
				if (line == "Type" || line == "Nom" || line == "Degat" || line == "Critique" || line == "HP" || line == "Attack" || line == "Defense" || line == "Agilite" || line == "Intelligence" || line == "Fleche" || line == "Durabilite" || line == "Cout") {
					if (line == "Type") {
						myFile >> m_type;
					}
					if (line == "Nom") {
						myFile >> m_nom;
					}
					if (line == "Degat") {
						myFile >> m_degats;
					}
					if (line == "Critique") {
						myFile >> m_critique;
					}
					if (line == "HP") {
						myFile >> m_vie;
					}
					if (line == "Attack") {
						myFile >> m_attaque;
					}
					if (line == "Defense") {
						myFile >> m_defense;
					}
					if (line == "Agilite") {
						myFile >> m_agilite;
					}
					if (line == "Intelligence") {
						myFile >> m_intelligence;
					}
					if (line == "Fleche" || line == "Durabilite" || line == "Cout") {
						myFile >> m_CaracArme;
					}
				}
				else {
					m_nom += " " + line;
				}
			}
			else {
				if (m_type == "Baton") {
					CStaff a = CStaff(m_type, m_nom, m_degats, m_critique, m_bonusDegatsArme, m_vie, m_esquive, m_vitesseBase, m_attaque, m_defense, m_agilite, m_intelligence, m_CaracArme);
					vector.push_back(&a);
				}
				if (m_type == "Dague") {
					CDagger a = CDagger(m_type, m_nom, m_degats, m_critique, m_bonusDegatsArme, m_vie, m_esquive, m_vitesseBase, m_attaque, m_defense, m_agilite, m_intelligence, m_CaracArme);
					vector.push_back(&a);
				}
				if (m_type == "Epee") {
					CSword a = CSword(m_type, m_nom, m_degats, m_critique, m_bonusDegatsArme, m_vie, m_esquive, m_vitesseBase, m_attaque, m_defense, m_agilite, m_intelligence, m_CaracArme);
					vector.push_back(&a);
				}
				if (m_type == "Arc") {
					CBow a = CBow(m_type, m_nom, m_degats, m_critique, m_bonusDegatsArme, m_vie, m_esquive, m_vitesseBase, m_attaque, m_defense, m_agilite, m_intelligence, m_CaracArme);
					vector.push_back(&a);
				}

				//statistiques liées à l'arme
				m_type = "";
				m_nom = "";
				m_degats = 0;
				m_critique = 0;
				m_bonusDegatsArme = 0;

				//statistiques liées aux personnage porteur
				m_vie = 0;
				m_esquive = 0;
				m_vitesseBase = 0;
				m_attaque = 0;
				m_defense = 0;
				m_agilite = 0;
				m_intelligence = 0;
				m_CaracArme = 0;

			}
		}
		myFile.close();
	}
	else
		std::cout << "Impossible d’ouvrir le fichier \n";

}

void Parsing::LecturePersonnages(std::vector<CCharacter*> vector) {
	std::string line;
	std::ifstream myFile("data\\characters.jdc");
	if (myFile.is_open())
	{
		std::string m_classe = "";
		std::string m_nom = "";
		int m_vie = 0;
		float m_esquive = 0;
		int m_vitesse = 0;
		int m_attaque = 0;
		int m_defense = 0;
		int m_agilite = 0;
		int m_intelligence = 0;
		float m_special = 0;

		while (myFile >> line) {
			if (line != "EndCharacter") {
				if (line == "Classe" || line == "Nom" || line == "HP" || line == "Dodge" || line == "Vitesse" || line == "Attaque" || line == "Defense" || line == "Agilite" || line == "Intelligence" || line == "Special") {
					if (line == "Classe") {
						myFile >> m_classe;
					}
					if (line == "Nom") {
						myFile >> m_nom;
					}
					if (line == "HP") {
						myFile >> m_vie;
					}
					if (line == "Dodge") {
						myFile >> m_esquive;
					}
					if (line == "Vitesse") {
						myFile >> m_vitesse;
					}
					if (line == "Attaque") {
						myFile >> m_attaque;
					}
					if (line == "Defense") {
						myFile >> m_defense;
					}
					if (line == "Agilite") {
						myFile >> m_agilite;
					}
					if (line == "Intelligence") {
						myFile >> m_intelligence;
					}
					if (line == "Special") {
						myFile >> m_special;
					}
				}
				else {
					m_nom += " " + line;
				}
			}
			else {
				if (m_classe == "Mage") {
					CMage a = CMage(m_nom, m_vie, m_esquive, m_vitesse, m_attaque, m_defense, m_agilite, m_intelligence);
					vector.push_back(&a);
				}
				if (m_classe == "Voleur") {
					CRogue a = CRogue(m_nom, m_vie, m_esquive, m_vitesse, m_attaque, m_defense, m_agilite, m_intelligence, m_special);
					vector.push_back(&a);
				}
				if (m_classe == "Guerrier") {
					CWarrior a = CWarrior(m_nom, m_vie, m_esquive, m_vitesse, m_attaque, m_defense, m_agilite, m_intelligence, m_special);
					vector.push_back(&a);
				}
				if (m_classe == "Archer") {
					CArcher a = CArcher(m_nom, m_vie, m_esquive, m_vitesse, m_attaque, m_defense, m_agilite, m_intelligence);
					vector.push_back(&a);
				}

				m_classe = "";
				m_nom = "";
				m_vie = 0;
				m_esquive = 0;
				m_vitesse = 0;
				m_attaque = 0;
				m_defense = 0;
				m_agilite = 0;
				m_intelligence = 0;
				m_special = 0;

			}
		}
		myFile.close();
	}
	else
		std::cout << "Impossible d’ouvrir le fichier \n";

}



Parsing::Parsing()
{
	LectureArmes(m_weapon);
	LecturePersonnages(m_character);
}

void Parsing::PrintCharacter()
{
	std::cout << m_character.size();
	std::vector<CCharacter*>::iterator itCharacter;

	for (itCharacter = m_character.begin(); itCharacter != m_character.end(); itCharacter++) {
		(*itCharacter)->print();
	}
}

void Parsing::PrintWeapon()
{
	std::cout << m_weapon.size();
	std::vector<CWeapon*>::iterator itWeapon;
	
	for (itWeapon = m_weapon.begin(); itWeapon != m_weapon.end(); itWeapon++) {
		(*itWeapon)->print();
	}
}


