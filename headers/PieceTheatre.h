#ifndef PIECETHEATRE_H
#define PIECETHEATRE_H

#include "Livre.h"

class PieceTheatre : public Livre {
private:
    std::string siecle;

public:
    PieceTheatre(const int code, const std::string& auteur, const std::string& titre, const std::string& editeur,
                 const std::string& ISBN, const std::string& siecle, Bibliotheque* BibliothequeOrigine);

    void afficher() const override;
};

#endif