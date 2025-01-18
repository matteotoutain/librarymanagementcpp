#include "headers/Adherent.h"
#include <iostream>

using namespace std;

Adherent::Adherent(const string& nom, const string& prenom, const string& adresse,
                   int numeroAdherent, int nbLivresAutorises, Bibliotheque* bibliotheque)
    : nom(nom), prenom(prenom), adresse(adresse), numeroAdherent(numeroAdherent),
      nbLivresAutorises(nbLivresAutorises), bibliotheque(bibliotheque) {}

vector<Livre *> Adherent::getLivresEmpruntes() const { return livresEmpruntes; }

void Adherent::emprunterLivre(Livre& livre) {
    if (livre.getEtat() != Libre) {
        throw runtime_error("Le livre n'est pas disponible.");
    }
    if (livresEmpruntes.size() >= nbLivresAutorises) {
        throw runtime_error("Limite d'emprunt atteinte.");
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
    throw runtime_error("Livre non trouvé dans la liste des empruntés.");
}

void Adherent::afficherLivres() const {
    for (const auto& livre : livresEmpruntes) {
        livre->afficher();
    }
}

int Adherent::getId() const {
    return numeroAdherent;
}
string Adherent::getNom() const {
    return nom;
}

string Adherent::getPrenom() const {
    return prenom;
}

Bibliotheque* Adherent::getBibliotheque() const {
    return bibliotheque;  // Retourne le pointeur vers la bibliothèque
}
