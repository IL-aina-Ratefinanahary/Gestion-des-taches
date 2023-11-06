#include <iostream>
#include "Tache.h"
#include "Utilisateur.h"
#include "GestionnaireDeFichiers.h"
class Test {
public:
    static void lancerTests() {
        // Test 1: Création et affichage d'une tâche
        Tache tache1(1, "Acheter du pain", "Aller a la boulangerie", "01/10/2023", "01/10/2023", "En cours");
        tache1.afficherTache();
        // Test 2: Création d'un utilisateur et ajout d'une tâche
        Utilisateur utilisateur("John Doe", "john.doe@example.com");
        utilisateur.ajouterTache(tache1);
        utilisateur.afficherToutesLesTaches();
        // Test 3: Sauvegarde des tâches dans un fichier
        GestionnaireDeFichiers::sauvegarderTaches(utilisateur);
        // Test 4: Chargement des tâches depuis un fichier
        Utilisateur utilisateur2("John Doe", "john.doe@example.com");
        GestionnaireDeFichiers::chargerTaches(utilisateur2);
        utilisateur2.afficherToutesLesTaches();
    }
};
int main() {
    Test::lancerTests();
    return 0;
}


