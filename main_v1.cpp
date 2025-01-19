#include <iostream>
#include "Bibliotheque.cpp"
#include "Livre.cpp"
#include "PieceTheatre.cpp"
#include "RecueilPoesie.cpp"
#include "Roman.cpp"
#include "BandeDessinee.cpp"
#include "Album.cpp"
#include "Adherent.cpp"

int main() {
    Bibliotheque b1(1, "Bibliothèque Centrale", "12 rue Victor Hugo");
    Bibliotheque b2(2, "Bibliothèque de la Ville", "38 avenue de la Liberté");

    PieceTheatre piece(1, "Molière", "Le Malade Imaginaire", "Gallimard", "9782070360027", "Tout public", "17e", &b1);
    RecueilPoesie recueil(2, "Charles Baudelaire", "Les Fleurs du Mal", "Hachette", "9782012789123", "Adulte", "Vers", &b1);
    Roman roman(3, "J.K. Rowling", "Harry Potter et la Coupe de Feu", "Gallimard Jeunesse", "9782070584621", "Ados", "Fantastique", &b2);
    BandeDessinee bd(4, "Hergé", "Tintin et le Lotus Bleu", "Casterman", "9782203001078", "Jeunesse", "Hergé", &b1);
    Album album(5, "Collectif", "Atlas des Animaux", "Nathan", "9782092789123", "Tout public", "Photos", &b2);

    b1.ajouterLivre(&piece);
    b1.ajouterLivre(&recueil);
    b1.ajouterLivre(&bd);
    b2.ajouterLivre(&roman);
    b2.ajouterLivre(&album);

    Adherent adherent1("Richard", "Timothée", "3 Avenue de la libération", 1, 2, &b1);
    Adherent adherent2("Toutain", "Matteo", "12 Rue du Coq", 2, 3, &b2);

    std::cout << "=== Livres dans la Bibliothèque de Paris ===" << std::endl;
    b1.afficherLivres();
    std::cout << "\n=== Livres dans la Bibliothèque de Lyon ===" << std::endl;
    b2.afficherLivres();

    try {
        std::cout << "\nAdhérent 1 emprunte 'Le Malade Imaginaire'..." << std::endl;
        adherent1.emprunterLivre(piece);
        std::cout << "Emprunt réussi !" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Erreur : " << e.what() << std::endl;
    }

    try {
        std::cout << "\nAdhérent 1 emprunte 'Les Fleurs du Mal'..." << std::endl;
        adherent1.emprunterLivre(recueil);
        std::cout << "Emprunt réussi !" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Erreur : " << e.what() << std::endl;
    }

    try {
        std::cout << "\nAdhérent 1 essaie d'emprunter un troisième livre..." << std::endl;
        adherent1.emprunterLivre(bd);
    } catch (const std::exception& e) {
        std::cout << "Erreur : " << e.what() << std::endl;
    }

    std::cout << "\n=== Livres empruntés par Jean Dupont ===" << std::endl;
    adherent1.afficherLivres();

    try {
        std::cout << "\nAdhérent 1 rend 'Le Malade Imaginaire'..." << std::endl;
        adherent1.rendreLivre(piece);
        std::cout << "Retour réussi !" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Erreur : " << e.what() << std::endl;
    }

    try {
        std::cout << "\nÉchanger 'Harry Potter et la Coupe de Feu' avec la Bibliothèque de Paris..." << std::endl;
        b2.echangerLivre(b1, "9782070584621");
        std::cout << "Échange effectué avec succès." << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Erreur : " << e.what() << std::endl;
    }

    try {
        std::cout << "\nSuppression du livre 'Tintin et le Lotus Bleu' de la Bibliothèque de Paris..." << std::endl;
        b1.supprimerLivre(4);
        std::cout << "Suppression réussie." << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Erreur : " << e.what() << std::endl;
    }

    std::cout << "\n=== Livres dans la Bibliothèque de Paris après modifications ===" << std::endl;
    b1.afficherLivres();
    std::cout << "\n=== Livres dans la Bibliothèque de Lyon après modifications ===" << std::endl;
    b2.afficherLivres();

    return 0;
}
