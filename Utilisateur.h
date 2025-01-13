#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <string>
#include <vector>
#include "Tache.h"

class Utilisateur {
private:
    std::string nom;
    std::string email;
    std::vector<Tache> listeTaches;

public:
    Utilisateur(const std::string& name, const std::string& email);
    
    // Méthodes pour gérer les tâches de l'utilisateur
    void ajouterTache(const Tache& tache);
    void supprimerTache(int idTache);
    void afficherToutesLesTaches() const;

    // Getters
    std::string get_nom() const;
    std::string get_email() const;
    const std::vector<Tache>& getListeTaches() const;
};

#endif // UTILISATEUR_H
