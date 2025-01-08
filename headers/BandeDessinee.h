#ifndef BANDEDESSINEE_H
#define BANDEDESSINEE_H

#include "Livre.h"

class BandeDessinee : public Livre {
private:
    std::string dessinateur;

public:
    BandeDessinee(int code, const std::string& auteur, const std::string& titre, const std::string& editeur,
                  const std::string& ISBN, const std::string& typepublic, const std::string& dessinateur, Bibliotheque* BibliothequeOrigine);

    void afficher() const override;
};

#endif
