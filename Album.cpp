#include "headers\Album.h"
#include <iostream>

Album::Album(int code, const string& auteur, const string& titre, const string& editeur,
             const string& ISBN, const string& typePublic, const string& typeIllustration, Bibliotheque* BibliothequeOrigine)
    : Livre(code, auteur, titre, editeur, ISBN, typePublic, BibliothequeOrigine), typeIllustration(typeIllustration) {}

void Album::afficher() const {
    Livre::afficher();
    cout << "Type d'illustration: " << typeIllustration << endl;
}

string Album::getCategorie() const {
    return "Album";
}
