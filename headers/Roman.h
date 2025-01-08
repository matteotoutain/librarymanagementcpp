#ifndef ROMAN_H
#define ROMAN_H

#include "Livre.h"

class Roman : public Livre {
private:
    std::string genre;

public:
    Roman(const int code, const std::string& auteur, const std::string& titre, const std::string& editeur,
          const std::string& ISBN, const std::string& genre, Bibliotheque* BibliothequeOrigine);

    void afficher() const override;
};

#endif
