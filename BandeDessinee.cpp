#include "headers\BandeDessinee.h"
#include <iostream>

BandeDessinee::BandeDessinee(int code, const string& auteur, const string& titre, const string& editeur,
                             const string& ISBN, const string& typepublic, const string& dessinateur, Bibliotheque* BibliothequeOrigine)
    : Livre(code, auteur, titre, editeur, ISBN, typepublic, BibliothequeOrigine), dessinateur(dessinateur) {}

void BandeDessinee::afficher() const {
    Livre::afficher();
    cout << "Dessinateur: " << dessinateur << endl;
}

string BandeDessinee::getCategorie() const {
    return "BandeDessinee";
}
