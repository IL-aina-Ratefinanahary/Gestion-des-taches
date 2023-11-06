#ifndef GESTIONNAIREDEFICHIERS_H
#define GESTIONNAIREDEFICHIERS_H

#include "Utilisateur.h"

class GestionnaireDeFichiers {
public:
    static void sauvegarderTaches(const Utilisateur& utilisateur);
    static void chargerTaches(Utilisateur& utilisateur);
};

#endif // GESTIONNAIREDEFICHIERS_H

