#ifndef ALBUM_H
#define ALBUM_H

#include "Livre.h"

class Album : public Livre {
private:
    string typeIllustration;

public:
    Album(int code, const string& auteur, const string& titre, const string& editeur,
          const string& ISBN, const string& typePublic, const string& typeIllustration, Bibliotheque* BibliothequeOrigine);

    void afficher() const override;
    string getCategorie() const override;
};

#endif
