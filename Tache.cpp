#include <iostream>

using namespace std;

#include "Tache.h"

// Definition du constructeur de la classe Tache
Tache::Tache(int id, const string& title, 
    const string& desc, const string& creationDate, 
    const string& finishDate, const string& status)
    : identifiant(id), 
    titre(title), 
    description(desc), 
    dateCreation(creationDate), 
    dateEcheance(finishDate), 
    statut(status) {}

// Getters
int Tache::get_identifiant() const {
    return identifiant;
}

string Tache::get_titre() const {
    return titre;
}

string Tache::get_description() const {
    return description;
}

string Tache::get_dateCreation() const {
    return dateCreation;
}

string Tache::get_dateEcheance() const {
    return dateEcheance;
}

string Tache::get_statut() const {
    return statut;
}

// Setters
void Tache::set_identifiant(int id) {
    identifiant = id;
}

void Tache::set_titre(const string& title) {
    titre = title;
}

void Tache::set_description(const string& desc) {
    description = desc;
}

void Tache::set_dateCreation(const string& creationDate) {
    dateCreation = creationDate;
}

void Tache::set_dateEcheance(const string& dueDate) {
    dateEcheance = dueDate;
}

void Tache::set_statut(const string& status) {
    statut = status;
}



// Définition de la méthode afficherTache
void Tache::afficherTache() const {
    cout << "--- Affichage de la tache --- " <<endl;
    cout << "ID : " << identifiant << endl;
    cout << "Titre : " << titre << endl;
    cout << "Description : " << description << endl;
    cout << "Date de debut : " << dateCreation << endl;
    cout << "Date de fin : " << dateEcheance << endl;
    cout << "Statut : " << statut << endl;
}

// Definition de la methode secondeAffiche
void Tache::secondeAffiche() const {
    cout << identifiant <<") [" << statut <<"] " << titre <<" - " << description <<" (" << dateCreation << " - " << dateEcheance <<") "<< endl ;
}