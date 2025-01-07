#ifndef LIVRE_H
#define LIVRE_H

#include <string>
#include <iostream>

enum Etat {
    Libre,
    Emprunte,
    Prete
};

class Livre {
protected:
    std::string code;
    std::string auteur;
    std::string titre;
    std::string editeur;
    std::string ISBN;
    std::string typepublic;
    Etat etat;

public:
    Livre(const std::string& code, const std::string& auteur, const std::string& titre, const std::string& editeur,
          const std::string& ISBN, const std::string& typepublic)
        : code(code), auteur(auteur), titre(titre), editeur(editeur), ISBN(ISBN), typepublic(typepublic), etat(Libre) {}

    virtual ~Livre() {}

    virtual void afficher() const {
        std::cout << "Code: " << code << "\nTitre: " << titre << "\nAuteur: " << auteur << "\nEtat: "
                  << (etat == Libre ? "Libre" : (etat == Emprunte ? "Emprunté" : "Prêté")) << std::endl;
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
    Etat getEtat() const { return etat; }
};

#endif
