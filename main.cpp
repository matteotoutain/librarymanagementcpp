#include <iostream>
#include <vector>
#include "Bibliotheque.cpp"
#include "Livre.cpp"
#include "Roman.cpp"
#include "BandeDessinee.cpp"
#include "Album.cpp"
#include "PieceTheatre.cpp"
#include "RecueilPoesie.cpp"
#include "Adherent.cpp"
#include <list>
using namespace std;

// Fonction pour afficher les bibliothèques disponibles
void afficherBibliotheques(const vector<Bibliotheque*>& bibliotheques) {
    cout << "\n=== Bibliothèques disponibles ===\n";
    for (size_t i = 0; i < bibliotheques.size(); ++i) {
        cout << i + 1 << ". " << bibliotheques[i]->getNom() << "\n";
    }
}

void listerLivresAdherent(const Adherent& adherent) {
    cout << "\n=== Livres empruntés par " << adherent.getNom() << " ===\n";

    // Vérifie si l'adhérent a des livres empruntés
    if (adherent.getLivresEmpruntes().empty()) {
        cout << "Aucun livre emprunté.\n";
        return;
    }

    // Affiche tous les livres empruntés avec le code du livre
    for (size_t i = 0; i < adherent.getLivresEmpruntes().size(); ++i) {
        cout << "ID: " << adherent.getLivresEmpruntes()[i]->getCode()
                  << " - " << adherent.getLivresEmpruntes()[i]->getTitre() << "\n";
    }
}


// Fonction pour afficher les livres disponibles dans la bibliothèque
void afficherLivres(const Bibliotheque& b) {
    int choixAction;
    cout << "\n1. Afficher tous les livres\n";
    cout << "2. Afficher les bandes dessinées\n";
    cout << "3. Afficher les recueils de poésie\n";
    cout << "4. Afficher les romans\n";
    cout << "5. Afficher les pièces de théatres\n";
    cout << "6. Afficher les albums\n";
    cout << "Votre choix : ";
    cin >> choixAction;

    switch (choixAction) {
        case 1:
            cout << "\n=== Livres disponibles dans " << b.getNom() << " ===\n";
            for (auto livre : b.getLivres()) {
                livre->afficher();
                cout << "================\n";
            }
            break;
        case 2:
            cout << "\n=== Bandes dessinées disponibles dans " << b.getNom() << " ===\n";
            for (auto livre : b.getLivres()) {
                if (livre->getCategorie() == "BandeDessinee") {
                    livre->afficher();
                    cout << "================\n";
                }
            }
            break;
        case 3:
            cout << "\n=== Recueils de poésie disponibles dans " << b.getNom() << " ===\n";
            for (auto livre : b.getLivres()) {
                if (livre->getCategorie() == "RecueilPoesie") {
                    livre->afficher();
                    cout << "================\n";
                }
            }
            break;
        case 4:
            cout << "\n=== Romans disponibles dans " << b.getNom() << " ===\n";
            for (auto livre : b.getLivres()) {
                if (livre->getCategorie() == "Roman") {
                    livre->afficher();
                    cout << "================\n";
                }
            }
            break;
        case 5:
            cout << "\n=== Pièces de théatres disponibles dans " << b.getNom() << " ===\n";
            for (auto livre : b.getLivres()) {
                if (livre->getCategorie() == "PieceTheatre") {
                    livre->afficher();
                    cout << "================\n";
                }
            }
            break;
        case 6:
            cout << "\n=== Albums disponibles dans " << b.getNom() << " ===\n";
            for (auto livre : b.getLivres()) {
                if (livre->getCategorie() == "Album") {
                    livre->afficher();
                    cout << "================\n";
                }
            }
            break;
        default:
            cout << "Choix invalide.\n";
            break;
    }
}
// Fonction pour afficher les adhérents de la bibliothèque
void afficherAdherents(const vector<Adherent*>& adherents, const Bibliotheque& b){
    cout << "\n=== Adhérents de " << b.getNom() << " ===\n";
    for (size_t i = 0; i < adherents.size(); ++i) {
        if (adherents[i]->getBibliotheque() == &b) {
            cout << adherents[i]->getNom() << " " << adherents[i]->getPrenom()
                      << " (ID: " << adherents[i]->getId() << ")\n";
        }
    }
}
void emprunterLivre(vector<Adherent*>& adherents, Bibliotheque& b) {
    int adherentChoisi;
    afficherAdherents(adherents, b);
    cout << "Sélectionnez l'adhérent : ";
    cin >> adherentChoisi;

    if (adherentChoisi < 1) {
        cout << "Choix invalide.\n";
        return;
    }

    Adherent* adherent = adherents[adherentChoisi - 1];
    afficherLivres(b);

    int choixLivre;
    cout << "Sélectionnez le livre à emprunter (code du livre) : ";
    cin >> choixLivre;

    if (choixLivre < 1) {
        cout << "Choix invalide.\n";
        return;
    }

    auto livre = b.getLivre(choixLivre);

    adherent->emprunterLivre(*livre);
    cout << "Emprunt réussi : " << livre->getTitre() << "\n";
}

// Fonction pour échanger un livre
void echangerLivre(Bibliotheque& b1, Bibliotheque& b2) {
    afficherLivres(b1);
    int choixLivre;
    cout << "Sélectionnez le livre à échanger (code du livre) : ";
    cin >> choixLivre;

    if (choixLivre < 1) {
        cout << "Choix invalide.\n";
        return;
    }

    auto livre = b1.getLivre(choixLivre);
    b1.echangerLivre(b2, livre->getISBN());
}

// Fonction pour rendre un livre à la bibliothèque
void rendreLivre(Adherent& adherent, Bibliotheque& b1) {
    // Lister les livres empruntés par l'adhérent
    cout << "\n=== Livres empruntés par " << adherent.getNom() << " ===\n";
    for (auto livre : adherent.getLivresEmpruntes()) {
        cout << "Livre: " << livre->getCode() << " - " << livre->getTitre() << "\n";
    }

    int choixLivre;
    cout << "Sélectionnez le livre à rendre (code du livre) : ";
    cin >> choixLivre;

    if (choixLivre < 1) {
        cout << "Choix invalide.\n";
        return;
    }

    Livre* livreARendre = b1.getLivre(choixLivre);
    adherent.rendreLivre(*livreARendre);
    cout << "Livre rendu avec succès : " << livreARendre->getTitre() << "\n";
}

int main() {
    // Création des bibliothèques
    vector<Bibliotheque*> bibliotheques;
    Bibliotheque b1(1, "Bibliothèque Centrale", "12 rue Victor Hugo");
    Bibliotheque b2(2, "Bibliothèque de la Ville", "38 avenue de la Liberté");
    Bibliotheque b3(3, "Bibliothèque Secrète", "?");
    bibliotheques.push_back(&b1);
    bibliotheques.push_back(&b2);
    bibliotheques.push_back(&b3);

    // Création de livres
    Roman livre1(1, "J.K. Rowling", "Harry Potter", "Gallimard", "9782070620751", "Ados", "SF", &b1);
    b1.ajouterLivre(&livre1);

    Roman livre2(2, "George Orwell", "1984", "Seuil", "9782266210514", "Adulte", "Roman d'anticipation", &b1);
    b1.ajouterLivre(&livre2);

    BandeDessinee livre3(3, "Hergé", "Tintin au Tibet", "Casterman", "9782203001190", "Tout public", "Hergé", &b1);
    b1.ajouterLivre(&livre3);

    PieceTheatre livre4(4, "Jean Racine", "Phèdre", "Pocket", "9782266226670", "Tout public", "17ème", &b2);
    b2.ajouterLivre(&livre4);

    RecueilPoesie livre5(5, "Charles Baudelaire", "Les Fleurs du mal", "Gallimard", "9782266226645", "Tout public", "Vers", &b2);
    b2.ajouterLivre(&livre5);

    Album livre6(6, "Thomas Pesquet", "Terre(s)", "Michel Lafon", "9782266226675", "Tout public", "Photos", &b2);
    b2.ajouterLivre(&livre6);

    Roman livre7(7, "Victor Hugo", "Les Misérables", "Librairie Hachette", "9782010001234", "Adulte", "Drame historique", &b2);
    b2.ajouterLivre(&livre7);

    Roman livre8(8, "Mary Shelley", "Frankenstein", "Penguin Classics", "9780141439471", "Adulte", "Horreur", &b3);
    b3.ajouterLivre(&livre8);

    BandeDessinee livre9(9, "René Goscinny", "Astérix le Gaulois", "Dargaud", "9782012101234", "Tout public", "Uderzo", &b3);
    b3.ajouterLivre(&livre9);

    BandeDessinee livre10(10, "René Goscinny", "Lucky Luke: La diligence", "Dupuis", "9782800172345", "Tout public", "Morris", &b1);
    b1.ajouterLivre(&livre10);

    PieceTheatre livre11(11, "Molière", "L'Avare", "Flammarion", "9782080701213", "Tout public", "17ème", &b1);
    b1.ajouterLivre(&livre11);

    PieceTheatre livre12(12, "William Shakespeare", "Hamlet", "Oxford University Press", "9780192839283", "Adulte", "17ème", &b1);
    b1.ajouterLivre(&livre12);

    RecueilPoesie livre13(13, "Paul Verlaine", "Romances sans paroles", "Charpentier", "9782266226682", "Tout public", "Vers", &b1);
    b1.ajouterLivre(&livre13);

    RecueilPoesie livre14(14, "Arthur Rimbaud", "Une saison en enfer", "Gallimard", "9782266226699", "Adulte", "Prose", &b3);
    b3.ajouterLivre(&livre14);

    Album livre15(15, "Anne Geddes", "Little Blessings", "Sourcebooks", "9781402209515", "Tout public", "Photos", &b1);
    b1.ajouterLivre(&livre15);

    Album livre16(16, "Sebastião Salgado", "Genesis", "Taschen", "9783836538725", "Tout public", "Photos", &b3);
    b3.ajouterLivre(&livre16);


    // Création des adhérents
    vector<Adherent*> adherents;
    Adherent adherent1("Richard", "Timothée", "4 Boulevard de la Libération", 1, 3, &b1);
    Adherent adherent2("Toutain", "Matteo", "12 Rue du Coq", 2, 2, &b1);
    Adherent adherent3("Bruel", "Patrick", "7 Rue du Pocker", 3, 7, &b2);
    Adherent adherent4("Lachaud", "Philippe", "2 Avenue de Nicky Larson", 4, 2, &b2);
    Adherent adherent5("Dupont", "Emma", "45 Rue des Lilas", 5, 4, &b3);
    Adherent adherent6("Martin", "Lucas", "3 Place de la République", 6, 5, &b3);
    Adherent adherent7("Durand", "Marie", "18 Rue des Violettes", 7, 3, &b3);
    Adherent adherent8("Morel", "Julien", "21 Avenue des Champs", 8, 6, &b1);
    Adherent adherent9("Petit", "Chloé", "10 Boulevard des Roses", 9, 1, &b1);
    Adherent adherent10("Rousseau", "Thomas", "8 Rue Victor Hugo", 10, 2, &b2);
    Adherent adherent11("Lemoine", "Alice", "14 Place de la Gare", 11, 4, &b1);
    Adherent adherent12("Blanc", "Antoine", "7 Allée des Peupliers", 12, 5, &b1);

    adherents.push_back(&adherent1);
    adherents.push_back(&adherent2);
    adherents.push_back(&adherent3);
    adherents.push_back(&adherent4);
    adherents.push_back(&adherent5);
    adherents.push_back(&adherent6);
    adherents.push_back(&adherent7);
    adherents.push_back(&adherent8);
    adherents.push_back(&adherent9);
    adherents.push_back(&adherent10);
    adherents.push_back(&adherent11);
    adherents.push_back(&adherent12);

    // Interaction avec l'utilisateur
    int choixBibliotheque;
    while (true) {
        cout << "\nChoisissez la bibliothèque avec laquelle vous souhaitez travailler :\n";
        afficherBibliotheques(bibliotheques);
        cout << "0. Quitter\n";
        cout << "Votre choix : ";
        cin >> choixBibliotheque;

        if (choixBibliotheque == 0) {
            cout << "Au revoir!\n";
            return 0;
        }

        if (choixBibliotheque < 1 || choixBibliotheque > bibliotheques.size()) {
            cout << "Choix invalide.\n";
            continue;
        }

        Bibliotheque* bibliothequeActuelle = bibliotheques[choixBibliotheque - 1];
        int choixAction;
        while (true) {
            cout << "\nQue voulez-vous faire ?\n";
            cout << "1. Afficher les livres\n";
            cout << "2. Afficher les adhérents\n";
            cout << "3. Emprunter un livre\n";
            cout << "4. Echanger ou rendre un livre entre bibliothèques\n";
            cout << "5. Lister les livres d'un adhérent\n";
            cout << "6. Rendre un livre\n";
            cout << "7. Supprimer un livre\n";
            cout << "8. Retour à la page d'accueil\n";
            cout << "Votre choix : ";
            cin >> choixAction;

            switch (choixAction) {
                case 1:
                    afficherLivres(*bibliothequeActuelle);
                    break;
                case 2:
                    afficherAdherents(adherents, *bibliothequeActuelle);
                    break;
                case 3:
                    emprunterLivre(adherents, *bibliothequeActuelle);
                    break;
                case 4:
                    // Echanger un livre entre bibliothèques
                {
                    // Affichage dynamique des bibliothèques disponibles
                    cout << "Choisissez la bibliothèque de destination pour l'échange :\n";
                    for (size_t i = 0; i < bibliotheques.size(); ++i) {
                        // Exclure la bibliothèque actuelle de la sélection
                        if (bibliotheques[i] != bibliothequeActuelle) {
                            cout << i + 1 << ". " << bibliotheques[i]->getNom() << "\n";
                        }
                    }

                    int choixBibliothequeDestination;
                    cout << "Votre choix : ";
                    cin >> choixBibliothequeDestination;

                    // Vérification de la validité du choix
                    if (choixBibliothequeDestination < 1 || choixBibliothequeDestination > bibliotheques.size() ||
                        bibliotheques[choixBibliothequeDestination - 1] == bibliothequeActuelle) {
                        cout << "Choix invalide.\n";
                        } else {
                            // Echanger le livre entre bibliothèques
                            echangerLivre(*bibliothequeActuelle, *bibliotheques[choixBibliothequeDestination - 1]);
                        }
                }
                break;

                case 5:
                    // Lister les livres de l'adhérent
                {
                    // Affichage dynamique des adhérents
                    cout << "Choisissez un adhérent pour lister ses livres :\n";
                    for (size_t i = 0; i < adherents.size(); ++i) {
                        if (adherents[i] -> getBibliotheque() == bibliothequeActuelle) {
                            cout << i + 1 << ". " << adherents[i]->getNom() << " " << adherents[i]->getPrenom() << "\n";
                        }
                    }

                    int choixAdherent;
                    cout << "Votre choix : ";
                    cin >> choixAdherent;

                    // Vérification de la validité du choix
                    if (choixAdherent < 1 || choixAdherent > adherents.size()) {
                        cout << "Choix invalide.\n";
                    } else {
                        // Affichage des livres empruntés de l'adhérent sélectionné
                        listerLivresAdherent(*adherents[choixAdherent - 1]);
                    }
                }
                break;
                case 6:
                    // Rendre un livre
                {
                    // Affichage dynamique des adhérents
                    cout << "Choisissez un adhérent pour rendre un livre :\n";
                    for (size_t i = 0; i < adherents.size(); ++i) {
                        if (adherents[i] -> getBibliotheque() == bibliothequeActuelle) {
                            cout << i + 1 << ". " << adherents[i]->getNom() << " " << adherents[i]->getPrenom() << "\n";
                        }
                    }
                    int choixAdherent;
                    cout << "Votre choix : ";
                    cin >> choixAdherent;

                    // Vérification de la validité du choix
                    if (choixAdherent < 1 || choixAdherent > adherents.size()) {
                        cout << "Choix invalide.\n";
                    } else {
                        // Rendre les livres de l'adhérent sélectionné
                        rendreLivre(*adherents[choixAdherent - 1], *bibliothequeActuelle);
                    }
                }
                break;

                case 7:{
                    int choixLivre;
                    cout << "Choisissez le livre à supprimer :\n";
                    bibliothequeActuelle->afficherLivres();
                    cout << "Votre choix (ID) : ";
                    cin >> choixLivre;
                    bibliothequeActuelle->supprimerLivre(choixLivre);

                }
                    break;
                case 8:
                    break;
                default:
                    cout << "Choix invalide.\n";
                    break;
            }
            if (choixAction == 8) break;
        }
    }

}
