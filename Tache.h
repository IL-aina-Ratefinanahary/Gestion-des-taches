#ifndef TACHE_H
#define TACHE_H

#include <string>

class Tache {
private:
    int identifiant;
    std::string titre;
    std::string description;
    std::string dateCreation;
    std::string dateEcheance;
    std::string statut;

public:
    Tache(int id, const std::string& title, const std::string& desc, const std::string& creationDate, const std::string& finishDate, const std::string& status);
    // Getters
    int get_identifiant() const;
    std::string get_titre() const;
    std::string get_description() const;
    std::string get_dateCreation() const;
    std::string get_dateEcheance() const;
    std::string get_statut() const;

    // Setters
    void set_identifiant(int id);
    void set_titre(const std::string& title);
    void set_description(const std::string& desc);
    void set_dateCreation(const std::string& creationDate);
    void set_dateEcheance(const std::string& finishDate);
    void set_statut(const std::string& status);

    void afficherTache() const;

    // methode utilisee pour respecter l'affichage attendu
    void secondeAffiche() const;
};

#endif // TACHE_H

