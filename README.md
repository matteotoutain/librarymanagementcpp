# librarymanagementcpp

## Fonctionnalités implémentées :

### Afficher tous les livres ou par catégorie dans une bibliothèque

La bibliothèque peut afficher tous ses livres avec la méthode afficherLivres(). Elle peut également afficher les livres par catégorie avec un filtrage spécifique.

### Un adhérent peut emprunter un livre en donnant son code

Cette fonctionnalité est gérée par la méthode emprunterLivre() de la classe Adherent. Un adhérent peut emprunter un livre en utilisant son code ISBN.
### Un adhérent ne doit pas pouvoir emprunter plus de livres qu’il n’en a le droit

Cela est contrôlé dans la méthode emprunterLivre(), où on vérifie si l'adhérent a atteint sa limite d'emprunts autorisés.
### Un adhérent ne doit pas pouvoir emprunter un livre non libre

L'état du livre est vérifié dans emprunterLivre(). Un livre doit être "libre" pour pouvoir être emprunté.
### Une bibliothèque ne doit pas pouvoir prêter un livre non libre

Cela est vérifié à l'intérieur de la méthode emprunterLivre() de la bibliothèque, qui vérifie si le livre est "libre".
### Un adhérent peut rendre un livre

La méthode rendreLivre() de la classe Adherent permet à un adhérent de rendre un livre emprunté.
### Une bibliothèque peut demander un livre à une autre bibliothèque en donnant son ISBN

La méthode echangerLivre() de la classe Bibliotheque permet à une bibliothèque de demander un livre à une autre bibliothèque en donnant l'ISBN.
### Une bibliothèque peut acheter un nouveau livre

La méthode ajouterLivre() permet à une bibliothèque d'ajouter un nouveau livre.
### Une bibliothèque peut supprimer un livre, en donnant son code, soit parce qu’il est perdu, soit parce qu’il part au pilon

La méthode supprimerLivre() permet de supprimer un livre de la bibliothèque en fonction de son code.
### Une bibliothèque peut rendre les livres prêtés qui ne sont pas empruntés

Se fait par la même méthode qu'en emprunt un livre à une autre bibliothèque.

### Relations

Une Bibliothèque contient plusieurs Livres (relation de composition).
Un Livre est associé à une Bibliothèque d'origine.
Un Adherent peut emprunter plusieurs Livres (relation d'agrégation).
Les sous-classes de Livre héritent de la classe abstraite Livre.
