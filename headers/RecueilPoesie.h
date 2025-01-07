#ifndef RECUEILPOESIE_H
#define RECUEILPOESIE_H

#include "Livre.h"

class RecueilPoesie : public Livre {
private:
    std::string typeVers;

public:
    RecueilPoesie(const std::string& code, const std::string& auteur, const std::string& titre, const std::string& editeur,
                  const std::string& ISBN, const std::string& typeVers, Bibliotheque* BibliothequeOrigine)
        : Livre(code, auteur, titre, editeur, ISBN, "Poésie", BibliothequeOrigine), typeVers(typeVers) {}

    void afficher() const override {
        Livre::afficher();
        std::cout << "Type de vers: " << typeVers << std::endl;
    }
};

#endif
