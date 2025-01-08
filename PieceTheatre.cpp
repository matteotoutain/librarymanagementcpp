#include "headers\PieceTheatre.h"
#include <iostream>

PieceTheatre::PieceTheatre(const std::string& code, const std::string& auteur, const std::string& titre, const std::string& editeur,
                           const std::string& ISBN, const std::string& siecle, Bibliotheque* BibliothequeOrigine)
    : Livre(code, auteur, titre, editeur, ISBN, "Théâtre", BibliothequeOrigine), siecle(siecle) {}

void PieceTheatre::afficher() const {
    Livre::afficher();
    std::cout << "Siècle: " << siecle << std::endl;
}
