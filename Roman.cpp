#include "headers\Roman.h"
#include <iostream>

Roman::Roman(int code, const string& auteur, const string& titre, const string& editeur,
             const string& ISBN, const string& typePublic, const string& genre, Bibliotheque* BibliothequeOrigine)
    : Livre(code, auteur, titre, editeur, ISBN, typePublic, BibliothequeOrigine), genre(genre) {}

void Roman::afficher() const {
    Livre::afficher();
    cout << "Genre      : " << genre << endl;
}


string Roman::getCategorie() const {
    return "Roman";
}
