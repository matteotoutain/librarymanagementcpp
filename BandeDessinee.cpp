#include "headers\BandeDessinee.h"
#include <iostream>

BandeDessinee::BandeDessinee(const std::string& code, const std::string& auteur, const std::string& titre, const std::string& editeur,
                             const std::string& ISBN, const std::string& typepublic, const std::string& dessinateur, Bibliotheque* BibliothequeOrigine)
    : Livre(code, auteur, titre, editeur, ISBN, typepublic, BibliothequeOrigine), dessinateur(dessinateur) {}

void BandeDessinee::afficher() const {
    Livre::afficher();
    std::cout << "Dessinateur: " << dessinateur << std::endl;
}
