#include <iostream>

using namespace std;

#include "Tache.h"

Tache::Tache(int id, const std::string& title, 
    const std::string& desc, const std::string& creationDate, 
    const std::string& dueDate, const std::string& status)
    : identifiant(id), 
    titre(title), 
    description(desc), 
    dateCreation(creationDate), 
    dateEcheance(dueDate), 
    statut(status) {}

// Getters
int Tache::getIdentifiant() const {
    return identifiant;
}

std::string Tache::getTitre() const {
    return titre;
}

std::string Tache::getDescription() const {
    return description;
}

std::string Tache::getDateCreation() const {
    return dateCreation;
}

std::string Tache::getDateEcheance() const {
    return dateEcheance;
}

std::string Tache::getStatut() const {
    return statut;
}

// Setters
void Tache::setIdentifiant(int id) {
    identifiant = id;
}

void Tache::setTitre(const std::string& title) {
    titre = title;
}

void Tache::setDescription(const std::string& desc) {
    description = desc;
}

void Tache::setDateCreation(const std::string& creationDate) {
    dateCreation = creationDate;
}

void Tache::setDateEcheance(const std::string& dueDate) {
    dateEcheance = dueDate;
}

void Tache::setStatut(const std::string& status) {
    statut = status;
}



// Définition de la méthode afficherTache
void Tache::afficherTache() const {
    std::cout << "--- Affichage de la tache --- " <<endl;
    std::cout << "ID : " << identifiant << std::endl;
    std::cout << "Titre : " << titre << std::endl;
    std::cout << "Description : " << description << std::endl;
    std::cout << "Date de debut : " << dateCreation << std::endl;
    std::cout << "Date de fin : " << dateEcheance << std::endl;
    std::cout << "Statut : " << statut << std::endl;
}

void Tache::secondeAffiche() const {
    std::cout << identifiant <<") [" << statut <<"] " << titre <<" - " << description <<" (" << dateCreation << " - " << dateEcheance <<") "<< endl ;
}