#include <iostream>
#include "GestionnaireDeFichiers.h"
#include <fstream>
#include <sstream>

using namespace std;

//Sauvegarder les taches
void GestionnaireDeFichiers::sauvegarderTaches(const Utilisateur& utilisateur) {
    // specifier dans quel fichier ecrire
    ofstream fichier("taches_utilisateur.txt");

    if (fichier.is_open()) {
        cout << "--- Sauvegarde des taches dans le fichier ---"<<endl;
        /*
            ce boucle permet d'ecrire dans le fichier tous les informations de la tache
            ici on a encore utilise les type auto car tache varie a etre string ou int selon le type de donnees a ecrire dans le fichier
        */
        for (const auto& tache : utilisateur.getListeTaches()) {
            fichier << "Identifiant : " << tache.get_identifiant() << endl;
            fichier << tache.get_titre() << endl;
            fichier << tache.get_description() << endl;
            fichier << tache.get_dateCreation() << endl;
            fichier << tache.get_dateEcheance() << endl;
            fichier << tache.get_statut() << endl;
        }

        cout << "Les taches de l'utilisateur John Doe ont ete sauvegardees avec succes."<<endl;
        fichier.close();
    }
    else {
        cout << "Impossible d'ouvrir le fichier pour sauvegarder les taches." << endl;
    }
}




// Charger les taches
void GestionnaireDeFichiers::chargerTaches(Utilisateur & utilisateur) {
    //indiquer que la lecture se fait a partir de ce fichier
    ifstream fichier("taches_utilisateur.txt");

    if (fichier.is_open()) {
        string ligne;
        vector<Tache> taches;

        cout << "--- Chargement des taches depuis le fichier ---" << endl;
        while (getline(fichier, ligne)) {
            // Lire l'identifiant de la tâche
            int identifiant;
            /*
                lire chaque ligne de notre code tant que le fichier n'est pas termine
                extraire les informations du fichier
            */
            if (ligne.find("Identifiant : ") != string::npos) {
                istringstream(ligne.substr(14)) >> identifiant;
                // Lire les autres informations de la tâche
                string titre, description, dateCreation, dateEcheance, statut;
                getline(fichier, titre);
                getline(fichier, description);
                getline(fichier, dateCreation);
                getline(fichier, dateEcheance);
                getline(fichier, statut);

                /*
                    Construire la tâche
                    Stocker les informations lus dans un objet tache
                    le mettre dans le vecteur taches apres
                */ 
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
        cout << "Le fichier de sauvegarde des taches n'existe pas." << endl;
    }
}