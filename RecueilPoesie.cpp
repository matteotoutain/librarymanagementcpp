#include "headers\RecueilPoesie.h"
#include <iostream>

RecueilPoesie::RecueilPoesie(const std::string& code,
                             const std::string& auteur,
                             const std::string& titre,
                             const std::string& editeur,
                             const std::string& ISBN,
                             const std::string& typeVers,
                             Bibliotheque* BibliothequeOrigine) : Livre(code, auteur, titre, editeur, ISBN, "Poésie", BibliothequeOrigine), typeVers(typeVers) {}

void RecueilPoesie::afficher() const {
    Livre::afficher();
    std::cout << "Type de vers: " << typeVers << std::endl;
}
