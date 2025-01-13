/*
Nom et prenom:  RATEFINANAHARY IL'aina
Code permanent: RATI24030207

Nom et prenom:  Diallo Salifou
Code permanent: DIAS05020209

Nom et prenom:  Barry Aminata
Code permanent: BARA29569508
*/

#include <iostream>
#include "tache.h"
#include "utilisateur.h"
#include "GestionnairedeFichiers.h"
class Test {
public:
    static void lancerTests() {
        // Test 1: Cr�ation et affichage d'une t�che
        Tache tache1(1, "Acheter du pain", "Aller a la boulangerie", "01/10/2023", "01/10/2023", "En cours");
        tache1.afficherTache();
        // Test 2: Cr�ation d'un utilisateur et ajout d'une t�che
        Utilisateur utilisateur("John Doe", "john.doe@example.com");
        utilisateur.ajouterTache(tache1);
        utilisateur.afficherToutesLesTaches();
        // Test 3: Sauvegarde des t�ches dans un fichier
        GestionnaireDeFichiers::sauvegarderTaches(utilisateur);
        // Test 4: Chargement des t�ches depuis un fichier
        Utilisateur utilisateur2("John Doe", "john.doe@example.com");
        GestionnaireDeFichiers::chargerTaches(utilisateur2);
        utilisateur2.afficherToutesLesTaches();
    }
};
int main() {
    Test::lancerTests();
    return 0;
}


