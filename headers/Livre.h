#ifndef LIVRE_H
#define LIVRE_H

#include <string>
#include <iostream>

// Déclaration anticipée de la classe Bibliotheque
class Bibliotheque;

enum Etat {
    Libre,
    Emprunte
};

class Livre {
protected:
    std::string code;
    std::string auteur;
    std::string titre;
    std::string editeur;
    std::string ISBN;
    std::string typepublic;
    int pret;
    Etat etat;
    Bibliotheque* BibliothequeOrigine;

public:
    // Constructeur prenant l'ID de la bibliothèque d'origine
    Livre(const std::string& code, const std::string& auteur, const std::string& titre, const std::string& editeur,
          const std::string& ISBN, const std::string& typepublic, Bibliotheque* BibliothequeOrigine)
        : code(code), auteur(auteur), titre(titre), editeur(editeur), ISBN(ISBN), typepublic(typepublic),
          etat(Libre), BibliothequeOrigine(BibliothequeOrigine) {}

    virtual ~Livre() {}

    virtual void afficher() const {
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


    void emprunter() {
        if (etat == Libre) {
            etat = Emprunte;
        } else {
            throw std::runtime_error("Le livre n'est pas disponible pour emprunt.");
        }
    }

    void rendre() {
        if (etat == Emprunte) {
            etat = Libre;
        } else {
            throw std::runtime_error("Le livre n'a pas été emprunté.");
        }
    }

    const std::string& getISBN() const { return ISBN; }
    int getPret() const { return pret; }
    void setPret(int i) { pret = i; }
    Etat getEtat() const { return etat; }
    const std::string& getCode() const { return code; }

    Bibliotheque* getBibliothequeOrigine() const { return BibliothequeOrigine; }  // Méthode pour obtenir l'ID de la bibliothèque d'origine
};

#endif
