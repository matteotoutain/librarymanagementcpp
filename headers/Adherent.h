#ifndef ADHERENT_H
#define ADHERENT_H

#include "Livre.h"
#include <vector>
#include <stdexcept>

class Adherent {
private:
    std::string nom;
    std::string prenom;
    std::string adresse;
    int numeroAdherent;
    int nbLivresAutorises;
    std::vector<Livre*> livresEmpruntes;

public:
    Adherent(const std::string& nom, const std::string& prenom, const std::string& adresse, int numeroAdherent, int nbLivresAutorises)
        : nom(nom), prenom(prenom), adresse(adresse), numeroAdherent(numeroAdherent), nbLivresAutorises(nbLivresAutorises) {}

    void emprunterLivre(Livre& livre) {
        if (livresEmpruntes.size() >= nbLivresAutorises) {
            throw std::runtime_error("Nombre d'emprunts autorisé dépassé.");
        }
        livre.emprunter();
        livresEmpruntes.push_back(&livre);
    }

    void rendreLivre(Livre& livre) {
        for (auto it = livresEmpruntes.begin(); it != livresEmpruntes.end(); ++it) {
            if (*it == &livre) {
                livre.rendre();
                livresEmpruntes.erase(it);
                return;
            }
        }
        throw std::runtime_error("Ce livre n'a pas été emprunté.");
    }

    void afficherLivres() const {
        for (const auto& livre : livresEmpruntes) {
            livre->afficher();
        }
    }
};

#endif
