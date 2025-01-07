#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H

#include "Livre.h"
#include <list>
#include <stdexcept>

class Bibliotheque {
private:
    std::string nom;
    std::string adresse;
    std::list<Livre*> livres;

public:
    Bibliotheque(const std::string& nom, const std::string& adresse)
        : nom(nom), adresse(adresse) {}

    ~Bibliotheque() {
        for (auto livre : livres) {
            delete livre;
        }
    }

    void ajouterLivre(Livre* livre) {
        livres.push_back(livre);
    }

    void afficherLivres() const {
        for (const auto& livre : livres) {
            livre->afficher();
            std::cout << "-------------------------" << std::endl;
        }
    }

    Livre* trouverLivre(const std::string& ISBN) {
        for (auto& livre : livres) {
            if (livre->getISBN() == ISBN) {
                return livre;
            }
        }
        throw std::runtime_error("Livre non trouvé.");
    }

    void echangerLivre(Bibliotheque& autreBibliotheque, const std::string& ISBN) {
        Livre* livre = trouverLivre(ISBN);
        autreBibliotheque.ajouterLivre(livre);
        livres.remove(livre);
    }
};

#endif
