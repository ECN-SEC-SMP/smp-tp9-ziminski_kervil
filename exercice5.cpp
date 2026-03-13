#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <string>

using namespace std;

class CSV {
  private:
	// Associe une annee a une liste d'evenements.
	map<int, list<string>> evenements;

  public:
	void ajoute_evenement(int annee, const string& evenement) {
		evenements[annee].push_back(evenement);
	}

	bool lire(const string& nom_fichier) {
		ifstream fichier(nom_fichier);

		if (!fichier) {
			cerr << "Impossible d'ouvrir le fichier en lecture : " << nom_fichier << endl;
			return false;
		}

		evenements.clear();

		string ligne;
		while (getline(fichier, ligne)) {
			if (ligne.empty()) {
				continue;
			}

			// Chaque ligne commence par l'annee, puis une ou plusieurs descriptions.
			stringstream flux(ligne);
			string annee_texte;

			if (!getline(flux, annee_texte, ';')) {
				continue;
			}

			string description;
			string morceau;
			bool premier_morceau = true;

			// Recompose la description si plusieurs segments sont presents apres l'annee.
			while (getline(flux, morceau, ';')) {
				if (morceau.empty()) {
					continue;
				}

				if (!premier_morceau) {
					description += "; ";
				}
				description += morceau;
				premier_morceau = false;
			}

			if (description.empty()) {
				continue;
			}

			ajoute_evenement(stoi(annee_texte), description);
		}

		return true;
	}

	bool ecrire(const string& nom_fichier) const {
		ofstream fichier(nom_fichier);

		if (!fichier) {
			cerr << "Impossible d'ouvrir le fichier en écriture : " << nom_fichier << endl;
			return false;
		}

		// Ecrit une ligne par evenement au format annee;description;
		for (map<int, list<string>>::const_iterator it = evenements.begin(); it != evenements.end(); ++it) {
			for (list<string>::const_iterator it_liste = it->second.begin(); it_liste != it->second.end(); ++it_liste) {
				fichier << it->first << ';' << *it_liste << ';' << '\n';
			}
		}

		return true;
	}

	void affiche() const {
		for (map<int, list<string>>::const_iterator it = evenements.begin(); it != evenements.end(); ++it) {
			cout << "--------------------------------" << endl;
			cout << it->first << endl;
			cout << "--------------------------------" << endl;

			for (list<string>::const_iterator it_liste = it->second.begin(); it_liste != it->second.end(); ++it_liste) {
				cout << *it_liste << endl;
			}
		}
	}
};

int main() {
	CSV calendrier;

	// Charge les evenements historiques depuis le fichier CSV fourni.
	if (!calendrier.lire("dates.csv")) {
		return 1;
	}

	cout << "Contenu lu depuis dates.csv" << endl;
	calendrier.affiche();

	calendrier.ajoute_evenement(2005, "ma naissance");
	calendrier.ajoute_evenement(1515, "Marignan");

	cout << endl;
	cout << "Contenu après ajout d'evenements" << endl;
	calendrier.affiche();

	// Sauvegarde le contenu actuel de la map dans un nouveau fichier CSV.
	if (!calendrier.ecrire("dates_sortie.csv")) {
		return 1;
	}

	cout << endl;
	cout << "Le fichier dates_sortie.csv a ete ecrit." << endl;

	return 0;
}
