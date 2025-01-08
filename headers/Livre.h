#ifndef LIVRE_H
#define LIVRE_H

#include <string>
#include <iostream>

class Bibliotheque;

enum Etat {
    Libre,
    Emprunte
};

class Livre {
protected:
    int code;
    std::string auteur;
    std::string titre;
    std::string editeur;
    std::string ISBN;
    std::string typepublic;
    int pret;
    Etat etat;
    Bibliotheque* BibliothequeOrigine;

public:
    Livre(int code, const std::string& auteur, const std::string& titre, const std::string& editeur,
          const std::string& ISBN, const std::string& typepublic, Bibliotheque* BibliothequeOrigine);

    virtual ~Livre();

    virtual void afficher() const;
    void emprunter();
    void rendre();

    std::string getTitre() const;

    const std::string& getISBN() const;
    int getPret() const;
    void setPret(int i);
    Etat getEtat() const;
    const int getCode() const;
    Bibliotheque* getBibliothequeOrigine() const;
};

#endif
