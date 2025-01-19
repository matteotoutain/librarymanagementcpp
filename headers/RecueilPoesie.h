#ifndef RECUEILPOESIE_H
#define RECUEILPOESIE_H

#include "Livre.h"

class RecueilPoesie : public Livre {
private:
    string typeVers;

public:
    RecueilPoesie(int code, const string& auteur, const string& titre, const string& editeur,
                  const string& ISBN, const string& typePublic, const string& typeVers, Bibliotheque* BibliothequeOrigine);

    void afficher() const override;

    string getCategorie() const override;
};

#endif
