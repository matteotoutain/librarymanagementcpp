#include "headers\PieceTheatre.h"
#include <iostream>

PieceTheatre::PieceTheatre(int code, const string& auteur, const string& titre, const string& editeur,
                           const string& ISBN, const string& typePublic, const string& siecle, Bibliotheque* BibliothequeOrigine)
    : Livre(code, auteur, titre, editeur, ISBN, typePublic, BibliothequeOrigine), siecle(siecle) {}

void PieceTheatre::afficher() const {
    Livre::afficher();
    cout << "Siècle     : " << siecle << endl;
}


string PieceTheatre::getCategorie() const {
    return "PieceTheatre";
}

