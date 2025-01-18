#include "headers\RecueilPoesie.h"
#include <iostream>

RecueilPoesie::RecueilPoesie(int code,
                             const string& auteur,
                             const string& titre,
                             const string& editeur,
                             const string& ISBN,
                             const string& typePublic,
                             const string& typeVers,
                             Bibliotheque* BibliothequeOrigine) : Livre(code, auteur, titre, editeur, ISBN, typePublic, BibliothequeOrigine), typeVers(typeVers) {}

void RecueilPoesie::afficher() const {
    Livre::afficher();
    cout << "Type de vers: " << typeVers << endl;
}
string RecueilPoesie::getCategorie() const {
    return "RecueilPoesie";
}
