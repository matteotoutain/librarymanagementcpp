#ifndef ALBUM_H
#define ALBUM_H

#include "Livre.h"

class Album : public Livre {
private:
    std::string typeIllustration;

public:
    Album(int code, const std::string& auteur, const std::string& titre, const std::string& editeur,
          const std::string& ISBN, const std::string& typeIllustration, Bibliotheque* BibliothequeOrigine);

    void afficher() const override;
};

#endif
