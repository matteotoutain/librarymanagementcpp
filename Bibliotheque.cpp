#include "headers\Bibliotheque.h"

using namespace std;

Bibliotheque::Bibliotheque(int id, const string& nom, const string& adresse)
    : id(id), nom(nom), adresse(adresse) {}

Bibliotheque::~Bibliotheque() {
    for (auto livre : livres) {
        delete livre;
    }
}

string Bibliotheque::getNom() const { return nom; }
const list<Livre*>& Bibliotheque::getLivres() const { return livres; }

void Bibliotheque::ajouterLivre(Livre* livre) {
    livres.push_back(livre);
}

void Bibliotheque::afficherLivres() const {
    for (const auto& livre : livres) {
        livre->afficher();
        cout << "-------------------------" << endl;
    }
}

Livre* Bibliotheque::getLivre(const int Code) {
    for (auto& livre : livres) {
        if (livre->getCode() == Code) {
            return livre;
        }
    }
    throw runtime_error("Livre non trouvé.");
}

Livre* Bibliotheque::trouverLivre(const string& ISBN) {
    for (auto& livre : livres) {
        if (livre->getISBN() == ISBN) {
            return livre;
        }
    }
    throw runtime_error("Livre non trouvé.");
}

void Bibliotheque::echangerLivre(Bibliotheque& autreBibliotheque, const string& ISBN) {
    Livre* livre = trouverLivre(ISBN);
    if (livre->getEtat() == Libre) {
        if (livre->getPret() == 0) {
            livre->setPret(1);
            autreBibliotheque.ajouterLivre(livre);
            livres.remove(livre);
            cout << "Échange effectué avec succès : " << livre->getTitre() << "\n";
        }
        else {
            livre->setPret(0);
            autreBibliotheque.ajouterLivre(livre);
            livres.remove(livre);
            cout << "Retour effectué avec succès : " << livre->getTitre() << "\n";
        }
    }
    else {
        cout << "Livre en cours d'emprunt." << endl;
    }
}

void Bibliotheque::supprimerLivre(int code) {
    for (auto it = livres.begin(); it != livres.end(); ++it) {
        if ((*it)->getCode() == code) {

            livres.erase(it);  // Supprime le livre de la liste

            (*it)->~Livre();

            break;  // Sort de la boucle après la suppression
        }
    }
    cout << "Livre supprimé avec succès." << endl;
}



void Bibliotheque::rendreLivresPretes() {
    auto it = livres.begin();
    while (it != livres.end()) {
        Livre* livre = *it;

        if (livre->getPret() == 1 and livre->getEtat() == Libre) {
            Bibliotheque* bibliothequeOrigine = livre->getBibliothequeOrigine();

            if (bibliothequeOrigine) {
                bibliothequeOrigine->ajouterLivre(livre);
            }

            livre->setPret(0);

            it = livres.erase(it);
        } else {
            ++it;
        }
    }
}

int Bibliotheque::getId() const {
    return id;
}
