#include <iostream>

#include "headers\Bibliotheque.h"
#include "headers\Livre.h"

int main() {
    // Création de bibliothèques
    Bibliotheque b1(1, "Bibliothèque de Paris", "123 Rue de Paris");
    Bibliotheque b2(2, "Bibliothèque de Lyon", "456 Rue de Lyon");

    // Création de livres
    Livre* livre1 = new Livre("001", "Victor Hugo", "Les Misérables", "Gallimard", "9782070210744", "Adulte", &b1);
    Livre* livre2 = new Livre("002", "J.K. Rowling", "Harry Potter à l'école des sorciers", "Bloomsbury", "9780747532699", "Jeunesse",  &b1);
    Livre* livre3 = new Livre("003", "George Orwell", "1984", "Secker & Warburg", "9780451524935", "Adulte",  &b2);

    // Ajouter les livres aux bibliothèques
    b1.ajouterLivre(livre1);
    b1.ajouterLivre(livre2);
    b2.ajouterLivre(livre3);

    // Afficher les livres de la bibliothèque 1
    std::cout << "Livres de la Bibliothèque de Paris:" << std::endl;
    b1.afficherLivres();

    // Essayer d'emprunter un livre
    try {
        std::cout << "\nEmprunter 'Les Misérables'..." << std::endl;
        livre1->emprunter();
        std::cout << "Livre emprunté avec succès." << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Erreur: " << e.what() << std::endl;
    }

    // Essayer d'emprunter un livre déjà emprunté
    try {
        std::cout << "\nEssayer d'emprunter à nouveau 'Les Misérables'..." << std::endl;
        livre1->emprunter();
        std::cout << "Livre emprunté avec succès." << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Erreur: " << e.what() << std::endl;
    }


    // Afficher les livres de la bibliothèque 1
    std::cout << "Livres de la Bibliothèque de Paris:" << std::endl;
    b1.afficherLivres();

    // Rendre le livre
    try {
        std::cout << "\nRendre 'Les Misérables'..." << std::endl;
        livre1->rendre();
        std::cout << "Livre rendu avec succès." << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Erreur: " << e.what() << std::endl;
    }

    // Afficher les livres après emprunt et retour
    std::cout << "\nLivres de la Bibliothèque de Paris après emprunt et retour:" << std::endl;
    b1.afficherLivres();

    // Echanger un livre entre bibliothèques
    try {
        std::cout << "\nEchanger '1984' avec la Bibliothèque de Paris..." << std::endl;
        b2.echangerLivre(b1, "9780451524935");
        std::cout << "Echange effectué avec succès." << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Erreur: " << e.what() << std::endl;
    }

    // Afficher les livres après l'échange
    std::cout << "\nLivres de la Bibliothèque de Paris après échange:" << std::endl;
    b1.afficherLivres();
    std::cout << "\nLivres de la Bibliothèque de Lyon après échange:" << std::endl;
    b2.afficherLivres();

    // Supprimer un livre de la bibliothèque
    try {
        std::cout << "\nSuppression du livre 'Harry Potter à l'école des sorciers'..." << std::endl;
        b1.supprimerLivre("002");
        std::cout << "Livre supprimé avec succès." << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Erreur: " << e.what() << std::endl;
    }

    // Afficher les livres après suppression
    std::cout << "\nLivres de la Bibliothèque de Paris après suppression:" << std::endl;
    b1.afficherLivres();

    // Tester la gestion des livres prêtés mais non empruntés
    try {
        std::cout << "\nRetour des livres prêtés mais non empruntés..." << std::endl;
        b1.rendreLivresPretes();
        std::cout << "Livres prêtés rendus avec succès." << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Erreur: " << e.what() << std::endl;
    }


    // Afficher les livres des deux bibliothèques
    std::cout << "Livres de la Bibliothèque de Paris:" << std::endl;
    b1.afficherLivres();

    std::cout << "Livres de la Bibliothèque de Lyon:" << std::endl;
    b2.afficherLivres();
    return 0;
}
