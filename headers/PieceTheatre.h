#ifndef PIECETHEATRE_H
#define PIECETHEATRE_H

#include "Livre.h"

class PieceTheatre : public Livre {
private:
    std::string siecle;

public:
    PieceTheatre(const std::string& code, const std::string& auteur, const std::string& titre, const std::string& editeur,
                 const std::string& ISBN, const std::string& siecle)
        : Livre(code, auteur, titre, editeur, ISBN, "Théâtre"), siecle(siecle) {}

    void afficher() const override {
        Livre::afficher();
        std::cout << "Siècle: " << siecle << std::endl;
    }
};

#endif
