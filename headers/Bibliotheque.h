#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H

#include "Livre.h"
#include <list>
#include <stdexcept>
#include <string>
#include <iostream>

class Bibliotheque {
private:
    std::string nom;
    std::string adresse;
    std::list<Livre*> livres;
    int id;

public:
    Bibliotheque(int id, const std::string& nom, const std::string& adresse);
    ~Bibliotheque();

    void ajouterLivre(Livre* livre);
    void afficherLivres() const;

    Livre *getLivre(int Code);

    Livre* trouverLivre(const std::string& ISBN);
    void echangerLivre(Bibliotheque& autreBibliotheque, const std::string& ISBN);
    void supprimerLivre(int code);
    void rendreLivresPretes();
    std::string getNom() const;
    const std::list<Livre*>& getLivres() const;

    int getId() const;
};

#endif
