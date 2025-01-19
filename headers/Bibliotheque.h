#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H

#include "Livre.h"
#include <list>
#include <stdexcept>
#include <string>
#include <iostream>
using namespace std;

class Bibliotheque {
private:
    string nom;
    string adresse;
    list<Livre*> livres;
    int id;

public:
    Bibliotheque(int id, const string& nom, const string& adresse);
    ~Bibliotheque();

    void ajouterLivre(Livre* livre);
    void afficherLivres() const;

    Livre *getLivre(int Code);

    Livre* trouverLivre(const string& ISBN);
    void echangerLivre(Bibliotheque& autreBibliotheque, const string& ISBN);
    void supprimerLivre(int code);
    string getNom() const;
    const list<Livre*>& getLivres() const;

    int getId() const;

    Bibliotheque& operator+=(Livre* livre);
};

#endif
