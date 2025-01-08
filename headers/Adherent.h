#ifndef ADHERENT_H
#define ADHERENT_H

#include "Livre.h"
#include "Bibliotheque.h"  // Inclure la bibliothèque pour avoir accès à la classe Bibliotheque
#include <vector>
#include <string>

class Adherent {
private:
    std::string nom;
    std::string prenom;
    std::string adresse;
    int numeroAdherent;
    int nbLivresAutorises;
    std::vector<Livre*> livresEmpruntes;
    Bibliotheque* bibliotheque;  // Pointeur vers la bibliothèque de l'adhérent

public:
    Adherent(const std::string& nom, const std::string& prenom, const std::string& adresse,
             int numeroAdherent, int nbLivresAutorises, Bibliotheque* bibliotheque);

    void emprunterLivre(Livre& livre);
    void rendreLivre(Livre& livre);
    void afficherLivres() const;
    int getId() const;
    std::string getNom() const;
    std::string getPrenom() const;
    Bibliotheque* getBibliotheque() const;  // Accesseur pour la bibliothèque
    std::vector<Livre *> getLivresEmpruntes() const ;

    ~Adherent() = default;
};

#endif
