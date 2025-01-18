#ifndef PIECETHEATRE_H
#define PIECETHEATRE_H

#include "Livre.h"

class PieceTheatre : public Livre {
private:
    string siecle;

public:
    PieceTheatre(int code, const string& auteur, const string& titre, const string& editeur,
                 const string& ISBN, const string& typePublic, const string& siecle, Bibliotheque* BibliothequeOrigine);

    void afficher() const override;

    virtual string getCategorie() const override;
};

#endif