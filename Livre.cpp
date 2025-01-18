#include "headers\Livre.h"

using namespace std;

Livre::Livre(const int code, const string& auteur, const string& titre, const string& editeur,
             const string& ISBN, const string& typepublic, Bibliotheque* BibliothequeOrigine)
    : code(code), auteur(auteur), titre(titre), editeur(editeur), ISBN(ISBN), typepublic(typepublic),
      pret(0), etat(Libre), BibliothequeOrigine(BibliothequeOrigine) {}

Livre::~Livre() {}

string Livre::getTitre() const { return titre; }

void Livre::afficher() const {
    cout << "Code       : " << code << endl;
    cout << "Titre      : " << titre << endl;
    cout << "Auteur     : " << auteur << endl;
    cout << "Etat       : "
              << (etat == Libre ? "Libre"
                  : (etat == Emprunte ? "Emprunté" : "N/A"))
              << endl;
    cout << "Prété      : "
              << (pret == 1 ? "Oui"
                  : (pret == 0 ? "Non" : "N/A"))
              << endl;
}

void Livre::emprunter() {
    if (etat == Libre) {
        etat = Emprunte;
    } else {
        throw runtime_error("Le livre n'est pas disponible pour emprunt.");
    }
}

void Livre::rendre() {
    if (etat == Emprunte) {
        etat = Libre;
    } else {
        throw runtime_error("Le livre n'a pas été emprunté.");
    }
}

const string& Livre::getISBN() const {
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

string Livre::getCategorie() const {
    return "N/A";
}
