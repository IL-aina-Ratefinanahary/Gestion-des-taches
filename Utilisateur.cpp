#include <iostream>
#include "Utilisateur.h"
#include "Tache.h"
using namespace std;

// Assignation des parametres du constructeur aux attributs de la classe Utilisateur
Utilisateur::Utilisateur(const string& name, const string& email)
    : nom(name), email(email) {
}

// getters
string Utilisateur::get_nom() const {
    return nom;
}

string Utilisateur::get_email() const {
    return email;
}

const vector<Tache>& Utilisateur::getListeTaches() const {
    return listeTaches;
}

// Definition de la methode ajouerTache
void Utilisateur::ajouterTache(const Tache& tache) {
    listeTaches.push_back(tache);
}


/*
    Definition de la methode supprimerTache
    Utilisation de parametre int identifiantTache pour identifier faciliment quelle tache a supprimer
*/
void Utilisateur::supprimerTache(int idTache) {
    /*
        it est notre iterateur qui va parcourir notre vecteur ListeTaches
        le type de it sera aussi deduit par le compilateur depend du type trouver dans find_if
    */
    auto it = find_if(listeTaches.begin(), listeTaches.end(), [idTache](const Tache& t) {
        return t.get_identifiant() == idTache;
        });

    // verifier si notre iterateur pointe vers la tache trouvee
    if (it != listeTaches.end()) {
        //la methode erase nous permet de la supprimer de la liste
        listeTaches.erase(it);
    }
    else {
        cout << "La tache avec l'identifiant " << idTache << " n existe pas." <<endl;
    }
}

// Definition de la methode afficherToutesLesTaches
void Utilisateur::afficherToutesLesTaches() const {
    cout << "--- Affichage des taches de l'utilisateur " << nom << " ---" <<endl;
    for (const auto& tache : listeTaches) {
        tache.secondeAffiche();
    }
}