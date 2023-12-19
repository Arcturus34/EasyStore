//
// Created by lili3 on 19/12/2023.
//

#include "produit.h"
#include "client.h"
#include "magasin.h"

#include <iostream>


int main() {
    std::vector<Client> identifiant;

    Magasin InterMarche;

    Client c1("Dupont", "Jean", "jdupont", identifiant);
    Client c2("Durand", "Pierre", "pdurand", identifiant);

    Produit p1("PS4", "Console de jeu de marque Sony", 10, 249.99);
    Produit p2("Xbox One", "Console de jeu de marque Microsoft", 5, 279.99);
    Produit p3("Switch", "Console de jeu de marque Nintendo", 1, 299.99);

    InterMarche.ajouterProduit(p1);
    InterMarche.ajouterProduit(p2);
    InterMarche.ajouterProduit(p3);

    c1.ajouterProduit(p1);
    c1.ajouterProduit(p2);
    c1.ajouterProduit(p3);

    c1.modifierQuantiteProduit(p1, 2);
    std::cout<< c1 << std::endl;

    return 0;
}