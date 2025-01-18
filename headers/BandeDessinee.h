#ifndef BANDEDESSINEE_H
#define BANDEDESSINEE_H

#include "Livre.h"

class BandeDessinee : public Livre {
private:
    string dessinateur;

public:
    BandeDessinee(int code, const string& auteur, const string& titre, const string& editeur,
                  const string& ISBN, const string& typepublic, const string& dessinateur, Bibliotheque* BibliothequeOrigine);

    void afficher() const override;
    virtual string getCategorie() const override;
};


#endif
