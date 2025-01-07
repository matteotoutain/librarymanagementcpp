#include <iostream>
#include "headers\Bibliotheque.h"
#include "headers\BandeDessinee.h"
#include "headers\Adherent.h"
#include "headers\RecueilPoesie.h"
#include "headers\Roman.h"
#include "headers\PieceTheatre.h"
#include "headers\Album.h"

int main() {
    try {
        // Création des bibliothèques
        Bibliotheque bibliotheque1("Bibliothèque Centrale", "1 Rue Centrale");
        Bibliotheque bibliotheque2("Bibliothèque de Quartier", "2 Rue du Quartier");

        // Création de livres
        Livre* livre1 = new BandeDessinee("001", "André Franquin", "Spirou", "Dupuis", "123-456", "Jeunesse", "Franquin");
        Livre* livre2 = new RecueilPoesie("002", "Paul Eluard", "Poèmes", "Gallimard", "789-012", "Vers");
        Livre* livre3 = new Roman("003", "Victor Hugo", "Les Misérables", "Le Livre de Poche", "345-678", "Roman historique");
        Livre* livre4 = new PieceTheatre("004", "Molière", "Le Malade imaginaire", "Flammarion", "987-654", "17ème siècle");
        Livre* livre5 = new Album("005", "Hergé", "Tintin", "Casterman", "111-222", "Dessins");

        // Ajouter des livres aux bibliothèques
        bibliotheque1.ajouterLivre(livre1);
        bibliotheque1.ajouterLivre(livre2);
        bibliotheque1.ajouterLivre(livre3);
        bibliotheque2.ajouterLivre(livre4);
        bibliotheque2.ajouterLivre(livre5);

        // Création d'un adhérent
        Adherent adh1("Dupont", "Jean", "1 Rue Adhérent", 1, 3);
        Adherent adh2("Martin", "Pierre", "2 Rue Adhérent", 2, 2);

        // Affichage des livres dans la bibliothèque
        std::cout << "Livres dans Bibliothèque Centrale:" << std::endl;
        bibliotheque1.afficherLivres();
        std::cout << "Livres dans Bibliothèque de Quartier:" << std::endl;
        bibliotheque2.afficherLivres();

        // L'adhérent 1 emprunte un livre
        std::cout << "\nAdhérent 1 emprunte un livre:" << std::endl;
        adh1.emprunterLivre(*livre1);
        adh1.afficherLivres();

        // L'adhérent 2 emprunte plusieurs livres
        std::cout << "\nAdhérent 2 emprunte plusieurs livres:" << std::endl;
        adh2.emprunterLivre(*livre2);
        adh2.emprunterLivre(*livre3);
        adh2.afficherLivres();

        // L'adhérent 1 retourne un livre
        std::cout << "\nAdhérent 1 retourne un livre:" << std::endl;
        adh1.rendreLivre(*livre1);
        adh1.afficherLivres();

        // Échange de livres entre bibliothèques
        std::cout << "\nÉchange de livres entre bibliothèques:" << std::endl;
        bibliotheque1.echangerLivre(bibliotheque2, "345-678");
        std::cout << "Livres dans Bibliothèque Centrale après échange:" << std::endl;
        bibliotheque1.afficherLivres();
        std::cout << "Livres dans Bibliothèque de Quartier après échange:" << std::endl;
        bibliotheque2.afficherLivres();

        // Test d'emprunt au-delà de la limite
        std::cout << "\nEssai d'emprunter plus de livres que la limite autorisée:" << std::endl;
        try {
            adh2.emprunterLivre(*livre4); // Ce livre ne devrait pas être emprunté car l'adhérent a déjà atteint sa limite
        } catch (const std::runtime_error& e) {
            std::cout << "Erreur: " << e.what() << std::endl;
        }

        // Test d'emprunt de livre non disponible
        std::cout << "\nEssai d'emprunter un livre déjà emprunté:" << std::endl;
        try {
            adh1.emprunterLivre(*livre2); // Ce livre est déjà emprunté par adh2, on essaye de l'emprunter à nouveau
        } catch (const std::runtime_error& e) {
            std::cout << "Erreur: " << e.what() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "Erreur: " << e.what() << std::endl;
    }

    return 0;
}
