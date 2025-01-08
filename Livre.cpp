#include "headers\Livre.h"

Livre::Livre(const int code, const std::string& auteur, const std::string& titre, const std::string& editeur,
             const std::string& ISBN, const std::string& typepublic, Bibliotheque* BibliothequeOrigine)
    : code(code), auteur(auteur), titre(titre), editeur(editeur), ISBN(ISBN), typepublic(typepublic),
      pret(0), etat(Libre), BibliothequeOrigine(BibliothequeOrigine) {}

Livre::~Livre() {}

std::string Livre::getTitre() const { return titre; }

void Livre::afficher() const {
    std::cout << "Code       : " << code << std::endl;
    std::cout << "Titre      : " << titre << std::endl;
    std::cout << "Auteur     : " << auteur << std::endl;
    std::cout << "Etat       : "
              << (etat == Libre ? "Libre"
                  : (etat == Emprunte ? "Emprunté" : "Prêté"))
              << std::endl;
    std::cout << "Prété      : "
              << (pret == 1 ? "Oui"
                  : (pret == 0 ? "Non" : "Erreur"))
              << std::endl;
}

void Livre::emprunter() {
    if (etat == Libre) {
        etat = Emprunte;
    } else {
        throw std::runtime_error("Le livre n'est pas disponible pour emprunt.");
    }
}

void Livre::rendre() {
    if (etat == Emprunte) {
        etat = Libre;
    } else {
        throw std::runtime_error("Le livre n'a pas été emprunté.");
    }
}

const std::string& Livre::getISBN() const {
    return ISBN;
}

int Livre::getPret() const {
    return pret;
}

void Livre::setPret(int i) {
    pret = i;
}

Etat Livre::getEtat() const {
    return etat;
}

const int Livre::getCode() const {
    return code;
}

Bibliotheque* Livre::getBibliothequeOrigine() const {
    return BibliothequeOrigine;
}
