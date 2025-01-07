#ifndef BANDEDESSINEE_H
#define BANDEDESSINEE_H

#include "Livre.h"

class BandeDessinee : public Livre {
private:
    std::string dessinateur;

public:
    BandeDessinee(const std::string& code, const std::string& auteur, const std::string& titre, const std::string& editeur,
                  const std::string& ISBN, const std::string& typepublic, const std::string& dessinateur)
        : Livre(code, auteur, titre, editeur, ISBN, typepublic), dessinateur(dessinateur) {}

    void afficher() const override {
        Livre::afficher();
        std::cout << "Dessinateur: " << dessinateur << std::endl;
    }
};

#endif
