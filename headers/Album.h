#ifndef ALBUM_H
#define ALBUM_H

#include "Livre.h"

class Album : public Livre {
private:
    std::string typeIllustration;

public:
    Album(const std::string& code, const std::string& auteur, const std::string& titre, const std::string& editeur,
          const std::string& ISBN, const std::string& typeIllustration, Bibliotheque* BibliothequeOrigine)
        : Livre(code, auteur, titre, editeur, ISBN, "Album", BibliothequeOrigine), typeIllustration(typeIllustration) {}

    void afficher() const override {
        Livre::afficher();
        std::cout << "Type d'illustration: " << typeIllustration << std::endl;
    }
};

#endif
