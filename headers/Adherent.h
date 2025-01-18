#ifndef ADHERENT_H
#define ADHERENT_H

#include "Livre.h"
#include "Bibliotheque.h"  // Inclure la bibliothèque pour avoir accès à la classe Bibliotheque
#include <vector>
#include <string>

class Adherent {
private:
    string nom;
    string prenom;
    string adresse;
    int numeroAdherent;
    int nbLivresAutorises;
    vector<Livre*> livresEmpruntes;
    Bibliotheque* bibliotheque;  // Pointeur vers la bibliothèque de l'adhérent

public:
    Adherent(const string& nom, const string& prenom, const string& adresse,
             int numeroAdherent, int nbLivresAutorises, Bibliotheque* bibliotheque);

    void emprunterLivre(Livre& livre);
    void rendreLivre(Livre& livre);
    void afficherLivres() const;
    int getId() const;
    string getNom() const;
    string getPrenom() const;
    Bibliotheque* getBibliotheque() const;  // Accesseur pour la bibliothèque
    vector<Livre *> getLivresEmpruntes() const ;

    ~Adherent() = default;
};

#endif
