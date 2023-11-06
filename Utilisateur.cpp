#include <iostream>
#include "Utilisateur.h"
#include "Tache.h"
using namespace std;


Utilisateur::Utilisateur(const std::string& name, const std::string& email)
    : nom(name), email(email) {
    // Ici, les paramètres du constructeur sont assignés aux attributs de la classe
}

// getter
string Utilisateur::getNom() const {
    return nom;
}

string Utilisateur::getEmail() const {
    return email;
}

const vector<Tache>& Utilisateur::getListeTaches() const {
    return listeTaches;
}

void Utilisateur::ajouterTache(const Tache& tache) {
    listeTaches.push_back(tache);
}

void Utilisateur::supprimerTache(int identifiantTache) {
    auto it = find_if(listeTaches.begin(), listeTaches.end(), [identifiantTache](const Tache& t) {
        return t.getIdentifiant() == identifiantTache;
        });

    if (it != listeTaches.end()) {
        listeTaches.erase(it);
    }
    else {
        cout << "La tache avec l'identifiant " << identifiantTache << " n existe pas." <<endl;
    }
}

void Utilisateur::afficherToutesLesTaches() const {
    cout << "--- Affichage des taches de l'utilisateur " << nom << " ---" <<endl;
    for (const auto& tache : listeTaches) {
        tache.secondeAffiche();
    }
}