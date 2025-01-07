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
        if (livre.getEtat() != Libre) {
            throw std::runtime_error("Le livre n'est pas disponible.");
        }
        if (livresEmpruntes.size() >= nbLivresAutorises) {
            throw std::runtime_error("Limite d'emprunt atteinte.");
        }
        livresEmpruntes.push_back(&livre);
        livre.emprunter();
    }

    void rendreLivre(Livre& livre) {
        // Parcours manuel pour trouver et supprimer le livre de la liste des empruntés
        for (auto it = livresEmpruntes.begin(); it != livresEmpruntes.end(); ++it) {
            if (*it == &livre) {  // Compare les pointeurs
                livresEmpruntes.erase(it);  // Retire le livre de la liste
                livre.rendre();  // Change le statut du livre à "Libre"
                return;
            }
        }
        throw std::runtime_error("Livre non trouvé dans la liste des empruntés.");
    }


    void afficherLivres() const {
        for (const auto& livre : livresEmpruntes) {
            livre->afficher();
        }
    }
};

#endif
