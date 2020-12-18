#include "CWarrior.h"

CWarrior::CWarrior():CCharacter()
{
	m_CDHurlement = 0;
	m_parade = 0;
	m_hurlement = 0;
	m_classe = "Guerrier";
}

CWarrior::CWarrior(std::string nom, int vie, CWeapon* weapon, float esquive, int vitesse, int attaque, int defense, int agilite, int intelligence, float parade)
	:CCharacter(nom, vie, weapon, esquive, vitesse, attaque, defense, agilite, intelligence),
	m_CDHurlement(0),
	m_parade(parade),
	m_hurlement(0)
{
	m_classe = "Guerrier";
}

CWarrior::~CWarrior()
{
}

float CWarrior::GetCaracPartic()
{
	return m_parade;
}

void CWarrior::AttaquerAvecArme(CCharacter* cible)
{
	if (!cible->Esquiver()) {																				//Si l'esquive adverse échoue ( inférieure au nombre random tiré au dessus
		float coeff = 0.85 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (1.0 - 0.85)));	//calcul du coeff
		int p_degats = 7 * ((m_attaque+m_weapon->CalculerDegats()) / cible->GetDefense()) * coeff;				//calcul des dégats																				//on transforme les dégats en valeur négative
		cible->SetVie(-p_degats);		
		std::cout << "\nL'adversaire prend " << p_degats << " points de dégat.";
	}
	else {
		std::cout << "\n" << cible->GetNom() << " a esquive.";												//on informe l'utilisateur que l'adversaire a esquivé
	}
	
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

int CWarrior::Esquiver()
{
	float randEsquive = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	if (m_weapon->GetType() == "Epee")
		return randEsquive <= m_esquive + m_parade;

	return randEsquive <= m_esquive;
}

void CWarrior::Hurler()
{
	m_CDHurlement = 4;
	int randNum = rand() % (2 - 1 + 1) + 1;
	m_hurlement = randNum;
}

void CWarrior::ReparerArme(CCharacter* allie)
{
	CWeapon* weaponAllie = allie->GetWeapon();
	if(weaponAllie->GetNom() == "Epee" || weaponAllie->GetNom() == "Dague")
		allie->GetWeapon()->Reparer();
}

void CWarrior::Print()
{
	std::cout << "\n\tClasse guerrier";
	std::cout << "\n\t\tNom : " << m_nom;
	std::cout << "\n\t\tVie : " << m_vie;
	std::cout << "\n\t\tEsquive : " << m_esquive;
	std::cout << "\n\t\tVitesse : " << m_vitesseBase;
	std::cout << "\n\t\tAttaque : " << m_attaque;
	std::cout << "\n\t\tDefense : " << m_defense;
	std::cout << "\n\t\tAgilite : " << m_agilite;
	std::cout << "\n\t\tIntelligence : " << m_intelligence;
	std::cout << "\n\t\tParade : " << m_parade;
	if (m_weapon == nullptr) 
		std::cout << "\n\t\tArme equipee : Aucune";
	
	else {
		std::cout << "\n\t\tArme equipee : \n";
		m_weapon->print();
	}
}
