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
    int id;  // Identifiant unique pour chaque bibliothèque

public:
    // Constructeur avec un id unique
    Bibliotheque(int id, const std::string& nom, const std::string& adresse)
        : id(id), nom(nom), adresse(adresse) {}

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
        livre->setPret(1);
        autreBibliotheque.ajouterLivre(livre);
        livres.remove(livre);
    }

    // Supprimer un livre par code
    void supprimerLivre(const std::string& code) {
        for (auto it = livres.begin(); it != livres.end(); ) {
            if ((*it)->getCode() == code) {
                delete *it;  // On libère la mémoire du livre
                it = livres.erase(it);  // On supprime le livre de la liste et on avance l'itérateur
            } else {
                ++it;  // On avance l'itérateur si l'élément n'est pas supprimé
            }
        }
    }

    // Rendre les livres prêtés mais non empruntés
    void rendreLivresPretes() {
        auto it = livres.begin();
        while (it != livres.end()) {
            Livre* livre = *it;

            // Vérifie si le livre est prêté
            if (livre->getPret() == 1) {
                // Récupère l'ID de la bibliothèque d'origine
                Bibliotheque* bibliothequeOrigine = livre->getBibliothequeOrigine();

                if (bibliothequeOrigine) {
                    // Transfert du livre à la bibliothèque d'origine
                    bibliothequeOrigine->ajouterLivre(livre);
                }

                // Marque le livre comme non prêté
                livre->setPret(0);

                // Supprime le livre de la bibliothèque actuelle
                it = livres.erase(it);
            } else {
                ++it;
            }
        }
    }

    int getId() const { return id; }  // Accesseur pour l'id
};

#endif
