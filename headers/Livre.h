#ifndef LIVRE_H
#define LIVRE_H

#include <string>
#include <iostream>

using namespace std;

class Bibliotheque;

enum Etat {
    Libre,
    Emprunte
};

class Livre {
protected:
    int code;
    string auteur;
    string titre;
    string editeur;
    string ISBN;
    string typepublic;
    int pret;
    Etat etat;
    Bibliotheque* BibliothequeOrigine;

public:
    Livre(int code, const string& auteur, const string& titre, const string& editeur,
          const string& ISBN, const string& typepublic, Bibliotheque* BibliothequeOrigine);

    virtual ~Livre();

    virtual void afficher() const;
    void emprunter();
    void rendre();

    string getTitre() const;

    const string& getISBN() const;
    int getPret() const;
    void setPret(int i);
    Etat getEtat() const;
    const int getCode() const;
    Bibliotheque* getBibliothequeOrigine() const;

    virtual string getCategorie() const;
};

#endif
