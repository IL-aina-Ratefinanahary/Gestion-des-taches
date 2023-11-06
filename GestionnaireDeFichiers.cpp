#include <iostream>
#include "GestionnaireDeFichiers.h"
#include <fstream>
#include <sstream>

using namespace std;

//Sauvegarder les taches
void GestionnaireDeFichiers::sauvegarderTaches(const Utilisateur& utilisateur) {
    std::ofstream fichier("taches_utilisateur.txt");

    if (fichier.is_open()) {
        cout << "--- Sauvegarde des taches dans le fichier ---"<<endl;
        for (const auto& tache : utilisateur.getListeTaches()) {
            fichier << "Identifiant : " << tache.getIdentifiant() << std::endl;
            fichier << tache.getTitre() << std::endl;
            fichier << tache.getDescription() << std::endl;
            fichier << tache.getDateCreation() << std::endl;
            fichier << tache.getDateEcheance() << std::endl;
            fichier << tache.getStatut() << std::endl;
        }

        cout << "Les taches de l'utilisateur John Doe ont ete sauvegardees avec succes."<<endl;
        fichier.close();
    }
    else {
        std::cout << "Impossible d'ouvrir le fichier pour sauvegarder les taches." << std::endl;
    }
}




// Charger les taches
void GestionnaireDeFichiers::chargerTaches(Utilisateur & utilisateur) {
    std::ifstream fichier("taches_utilisateur.txt");

    if (fichier.is_open()) {
        std::string ligne;
        std::vector<Tache> taches;

        cout << "--- Chargement des taches depuis le fichier ---" << endl;
        while (std::getline(fichier, ligne)) {
            // Lire l'identifiant de la tâche
            int identifiant;
            if (ligne.find("Identifiant : ") != std::string::npos) {
                std::istringstream(ligne.substr(14)) >> identifiant;
                // Lire les autres informations de la tâche
                std::string titre, description, dateCreation, dateEcheance, statut;
                std::getline(fichier, titre);
                std::getline(fichier, description);
                std::getline(fichier, dateCreation);
                std::getline(fichier, dateEcheance);
                std::getline(fichier, statut);

                // Construire la tâche
                Tache tache(identifiant, titre, description, dateCreation, dateEcheance, statut);
                taches.push_back(tache);
            }
        }

        // Mettre à jour la liste des tâches de l'utilisateur
        for (const Tache& tache : taches) {
            utilisateur.ajouterTache(tache);
        }

        cout << "Les taches de l'utilisateur John Doe ont ete chargees avec succes." << endl;

        fichier.close();
    }
    else {
        std::cout << "Le fichier de sauvegarde des taches n'existe pas." << std::endl;
    }
}