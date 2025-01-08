#ifndef RECUEILPOESIE_H
#define RECUEILPOESIE_H

#include "Livre.h"

class RecueilPoesie : public Livre {
private:
    std::string typeVers;

public:
    RecueilPoesie(const int code, const std::string& auteur, const std::string& titre, const std::string& editeur,
                  const std::string& ISBN, const std::string& typeVers, Bibliotheque* BibliothequeOrigine);

    void afficher() const override;
};

#endif
