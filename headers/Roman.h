#ifndef ROMAN_H
#define ROMAN_H

#include "Livre.h"

class Roman : public Livre {
private:
    std::string genre;

public:
    Roman(const std::string& code, const std::string& auteur, const std::string& titre, const std::string& editeur,
          const std::string& ISBN, const std::string& genre)
        : Livre(code, auteur, titre, editeur, ISBN, "Littérature"), genre(genre) {}

    void afficher() const override {
        Livre::afficher();
        std::cout << "Genre: " << genre << std::endl;
    }
};

#endif
