#include "headers\Album.h"
#include <iostream>

Album::Album(const std::string& code, const std::string& auteur, const std::string& titre, const std::string& editeur,
             const std::string& ISBN, const std::string& typeIllustration, Bibliotheque* BibliothequeOrigine)
    : Livre(code, auteur, titre, editeur, ISBN, "Album", BibliothequeOrigine), typeIllustration(typeIllustration) {}

void Album::afficher() const {
    Livre::afficher();
    std::cout << "Type d'illustration: " << typeIllustration << std::endl;
}
