#include <iostream>
#include <vector>
#include "Bibliotheque.cpp"
#include "Livre.cpp"
#include "Adherent.cpp"
#include <list>

// Fonction pour afficher les bibliothèques disponibles
void afficherBibliotheques(const std::vector<Bibliotheque*>& bibliotheques) {
    std::cout << "\n=== Bibliothèques disponibles ===\n";
    for (size_t i = 0; i < bibliotheques.size(); ++i) {
        std::cout << i + 1 << ". " << bibliotheques[i]->getNom() << "\n";
    }
}

void listerLivresAdherent(const Adherent& adherent) {
    std::cout << "\n=== Livres empruntés par " << adherent.getNom() << " ===\n";

    // Vérifie si l'adhérent a des livres empruntés
    if (adherent.getLivresEmpruntes().empty()) {
        std::cout << "Aucun livre emprunté.\n";
        return;
    }

    // Affiche tous les livres empruntés avec le code du livre
    for (size_t i = 0; i < adherent.getLivresEmpruntes().size(); ++i) {
        std::cout << "ID: " << adherent.getLivresEmpruntes()[i]->getCode()
                  << " - " << adherent.getLivresEmpruntes()[i]->getTitre() << "\n";
    }
}


// Fonction pour afficher les livres disponibles dans la bibliothèque
void afficherLivres(const Bibliotheque& b) {
    std::cout << "\n=== Livres disponibles dans " << b.getNom() << " ===\n";
    for (auto livre : b.getLivres()) {
        livre->afficher();
    }
}

// Fonction pour afficher les adhérents de la bibliothèque
void afficherAdherents(const std::vector<Adherent*>& adherents, const Bibliotheque& b) {
    std::cout << "\n=== Adhérents de " << b.getNom() << " ===\n";
    for (size_t i = 0; i < adherents.size(); ++i) {
        if (adherents[i]->getBibliotheque() == &b) {
            std::cout << adherents[i]->getNom() << " " << adherents[i]->getPrenom()
                      << " (ID: " << adherents[i]->getId() << ")\n"; // Ajout de l'ID de l'adhérent
        }
    }
}
void emprunterLivre(std::vector<Adherent*>& adherents, Bibliotheque& b) {
    int adherentChoisi;
    afficherAdherents(adherents, b);
    std::cout << "Sélectionnez l'adhérent : ";
    std::cin >> adherentChoisi;

    if (adherentChoisi < 1) {
        std::cout << "Choix invalide.\n";
        return;
    }

    Adherent* adherent = adherents[adherentChoisi - 1];
    afficherLivres(b);

    int choixLivre;
    std::cout << "Sélectionnez le livre à emprunter (code du livre) : ";
    std::cin >> choixLivre;

    if (choixLivre < 1) {
        std::cout << "Choix invalide.\n";
        return;
    }

    auto livre = b.getLivre(choixLivre);

    adherent->emprunterLivre(*livre);
    std::cout << "Emprunt réussi : " << livre->getTitre() << "\n";
}

// Fonction pour échanger un livre
void echangerLivre(Bibliotheque& b1, Bibliotheque& b2) {
    afficherLivres(b1);
    int choixLivre;
    std::cout << "Sélectionnez le livre à échanger (code du livre) : ";
    std::cin >> choixLivre;

    if (choixLivre < 1) {
        std::cout << "Choix invalide.\n";
        return;
    }

    auto livre = b1.getLivre(choixLivre);
    b1.echangerLivre(b2, livre->getISBN());
}

// Fonction pour rendre un livre à la bibliothèque
void rendreLivre(Adherent& adherent, Bibliotheque& bibliotheque) {
    // Lister les livres empruntés par l'adhérent
    std::cout << "\n=== Livres empruntés par " << adherent.getNom() << " ===\n";
    for (auto livre : adherent.getLivresEmpruntes()) {
        std::cout << "Livre: " << livre->getCode() << " - " << livre->getTitre() << "\n";
    }

    int choixLivre;
    std::cout << "Sélectionnez le livre à rendre (code du livre) : ";
    std::cin >> choixLivre;

    if (choixLivre < 1 || choixLivre > adherent.getLivresEmpruntes().size()) {
        std::cout << "Choix invalide.\n";
        return;
    }

    Livre* livreARendre = adherent.getLivresEmpruntes()[choixLivre - 1];
    adherent.rendreLivre(*livreARendre);
    std::cout << "Livre rendu avec succès : " << livreARendre->getTitre() << "\n";
}

int main() {
    // Création des bibliothèques
    std::vector<Bibliotheque*> bibliotheques;
    Bibliotheque b1(1, "Bibliothèque Centrale", "123 rue de la Bibliothèque");
    Bibliotheque b2(2, "Bibliothèque de la Ville", "456 avenue de la Culture");
    bibliotheques.push_back(&b1);
    bibliotheques.push_back(&b2);

    // Création de livres
    Livre livre1(1, "J.K. Rowling", "Harry Potter", "Gallimard", "9782070620751", "Jeunesse", &b1);
    Livre livre2(2, "George Orwell", "1984", "Seuil", "9782266210514", "Classique", &b1);
    Livre livre3(3, "Victor Hugo", "Les Misérables", "Librio", "9782704302161", "Classique", &b2);
    Livre livre4(4, "J.R.R. Tolkien", "Le Hobbit", "Pocket", "9782266226669", "Fantasy", &b2);

    b1.ajouterLivre(&livre1);
    b1.ajouterLivre(&livre2);
    b2.ajouterLivre(&livre3);
    b2.ajouterLivre(&livre4);

    // Création des adhérents
    std::vector<Adherent*> adherents;
    Adherent adherent1("Dupont", "Pierre", "12 rue de Paris", 1, 3, &b1);
    Adherent adherent2("Durand", "Marie", "34 rue de Lyon", 2, 2, &b2);
    adherents.push_back(&adherent1);
    adherents.push_back(&adherent2);

    // Interaction avec l'utilisateur
    int choixBibliotheque;
    while (true) {
        std::cout << "\nChoisissez la bibliothèque avec laquelle vous souhaitez travailler :\n";
        afficherBibliotheques(bibliotheques);
        std::cout << "3. Quitter\n";
        std::cout << "Votre choix : ";
        std::cin >> choixBibliotheque;

        if (choixBibliotheque == 3) {
            std::cout << "Au revoir!\n";
            return 0;
        }

        if (choixBibliotheque < 1 || choixBibliotheque > bibliotheques.size()) {
            std::cout << "Choix invalide.\n";
            continue;
        }

        Bibliotheque* bibliothequeActuelle = bibliotheques[choixBibliotheque - 1];
        int choixAction;
        while (true) {
            std::cout << "\nQue voulez-vous faire ?\n";
            std::cout << "1. Afficher les livres\n";
            std::cout << "2. Afficher les adhérents\n";
            std::cout << "3. Emprunter un livre\n";
            std::cout << "4. Echanger un livre entre bibliothèques\n";
            std::cout << "5. Lister les livres d'un adhérent\n";
            std::cout << "6. Rendre un livre\n";
            std::cout << "7. Rendre les livres prêtés à une autre bibliothèque\n";
            std::cout << "8. Retour à la page d'accueil\n";
            std::cout << "Votre choix : ";
            std::cin >> choixAction;

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
                    std::cout << "Choisissez la bibliothèque de destination pour l'échange :\n";
                    for (size_t i = 0; i < bibliotheques.size(); ++i) {
                        // Exclure la bibliothèque actuelle de la sélection
                        if (bibliotheques[i] != bibliothequeActuelle) {
                            std::cout << i + 1 << ". " << bibliotheques[i]->getNom() << "\n";
                        }
                    }

                    int choixBibliothequeDestination;
                    std::cout << "Votre choix : ";
                    std::cin >> choixBibliothequeDestination;

                    // Vérification de la validité du choix
                    if (choixBibliothequeDestination < 1 || choixBibliothequeDestination > bibliotheques.size() ||
                        bibliotheques[choixBibliothequeDestination - 1] == bibliothequeActuelle) {
                        std::cout << "Choix invalide.\n";
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
                    std::cout << "Choisissez un adhérent pour lister ses livres :\n";
                    for (size_t i = 0; i < adherents.size(); ++i) {
                        if (adherents[i] -> getBibliotheque() == bibliothequeActuelle) {
                            std::cout << i + 1 << ". " << adherents[i]->getNom() << " " << adherents[i]->getPrenom() << "\n";
                        }
                    }

                    int choixAdherent;
                    std::cout << "Votre choix : ";
                    std::cin >> choixAdherent;

                    // Vérification de la validité du choix
                    if (choixAdherent < 1 || choixAdherent > adherents.size()) {
                        std::cout << "Choix invalide.\n";
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
                    std::cout << "Choisissez un adhérent pour rendre un livre :\n";
                    for (size_t i = 0; i < adherents.size(); ++i) {
                        if (adherents[i] -> getBibliotheque() == bibliothequeActuelle) {
                            std::cout << i + 1 << ". " << adherents[i]->getNom() << " " << adherents[i]->getPrenom() << "\n";
                        }
                    }
                    int choixAdherent;
                    std::cout << "Votre choix : ";
                    std::cin >> choixAdherent;

                    // Vérification de la validité du choix
                    if (choixAdherent < 1 || choixAdherent > adherents.size()) {
                        std::cout << "Choix invalide.\n";
                    } else {
                        // Rendre les livres de l'adhérent sélectionné
                        rendreLivre(*adherents[choixAdherent - 1], *bibliothequeActuelle);
                    }
                }
                break;

                case 7:
                    bibliothequeActuelle->rendreLivresPretes();
                    break;
                case 8:
                    break;
                default:
                    std::cout << "Choix invalide.\n";
                    break;
            }
            if (choixAction == 8) break;
        }
    }

    return 0;
}
