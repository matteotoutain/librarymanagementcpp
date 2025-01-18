#ifndef ROMAN_H
#define ROMAN_H

#include "Livre.h"

class Roman : public Livre {
private:
    string genre;

public:
    Roman(int code, const string& auteur, const string& titre, const string& editeur,
          const string& ISBN, const string& typePublic, const string& genre, Bibliotheque* BibliothequeOrigine);

    void afficher() const override;

    virtual string getCategorie() const override;
};

#endif
