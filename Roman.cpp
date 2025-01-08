#include "headers\Roman.h"
#include <iostream>

Roman::Roman(const std::string& code, const std::string& auteur, const std::string& titre, const std::string& editeur,
             const std::string& ISBN, const std::string& genre, Bibliotheque* BibliothequeOrigine)
    : Livre(code, auteur, titre, editeur, ISBN, "Littérature", BibliothequeOrigine), genre(genre) {}

void Roman::afficher() const {
    Livre::afficher();
    std::cout << "Genre: " << genre << std::endl;
}
