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
    Tache(int id, const std::string& title, const std::string& desc, const std::string& creationDate, const std::string& dueDate, const std::string& status);
    // Getters
    int getIdentifiant() const;
    std::string getTitre() const;
    std::string getDescription() const;
    std::string getDateCreation() const;
    std::string getDateEcheance() const;
    std::string getStatut() const;

    // Setters
    void setIdentifiant(int id);
    void setTitre(const std::string& title);
    void setDescription(const std::string& desc);
    void setDateCreation(const std::string& creationDate);
    void setDateEcheance(const std::string& dueDate);
    void setStatut(const std::string& status);

    void afficherTache() const;


    void secondeAffiche() const;
};

#endif // TACHE_H

