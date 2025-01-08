#include "headers/Adherent.h"
#include <iostream>

Adherent::Adherent(const std::string& nom, const std::string& prenom, const std::string& adresse,
                   int numeroAdherent, int nbLivresAutorises, Bibliotheque* bibliotheque)
    : nom(nom), prenom(prenom), adresse(adresse), numeroAdherent(numeroAdherent),
      nbLivresAutorises(nbLivresAutorises), bibliotheque(bibliotheque) {}

std::vector<Livre *> Adherent::getLivresEmpruntes() const { return livresEmpruntes; }

void Adherent::emprunterLivre(Livre& livre) {
    if (livre.getEtat() != Libre) {
        throw std::runtime_error("Le livre n'est pas disponible.");
    }
    if (livresEmpruntes.size() >= nbLivresAutorises) {
        throw std::runtime_error("Limite d'emprunt atteinte.");
    }
    livresEmpruntes.push_back(&livre);
    livre.emprunter();
}

void Adherent::rendreLivre(Livre& livre) {
    for (auto it = livresEmpruntes.begin(); it != livresEmpruntes.end(); ++it) {
        if (*it == &livre) {
            livresEmpruntes.erase(it);
            livre.rendre();
            return;
        }
    }
    throw std::runtime_error("Livre non trouvé dans la liste des empruntés.");
}

void Adherent::afficherLivres() const {
    for (const auto& livre : livresEmpruntes) {
        livre->afficher();
    }
}

int Adherent::getId() const {
    return numeroAdherent;
}
std::string Adherent::getNom() const {
    return nom;
}

std::string Adherent::getPrenom() const {
    return prenom;
}

Bibliotheque* Adherent::getBibliotheque() const {
    return bibliotheque;  // Retourne le pointeur vers la bibliothèque
}
