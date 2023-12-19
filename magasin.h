//
// Created by lili3 on 19/12/2023.
//

#ifndef EASYSTORE_MAGASIN_H
#define EASYSTORE_MAGASIN_H

#include "produit.h"
#include "client.h"

#include <vector>

class Magasin {
public:
    Magasin();
    std::vector<Client> getClient() const;
    std::vector<Produit> getProduit() const;
    void ajouterProduit(Produit produit);
    Produit getProduit(std::string titre) const;
    void modifierQuantite(std::string titre, int quantite);
    void ajouterClient(Client client);
    std::string getClient(std::string index) const;
    void ajouterProduitPanier(Client& client, Produit& produit);
    void supprimerProduitPanier(Client& client, Produit& produit);
    void modifierQuantiteProduitPanier(Client& client, Produit& produit, int quantite);
private:
    std::vector<Produit> _produits;
    std::vector<Client> _clients;
    //std::vector <Commande> _commandes;
};

std::ostream& operator<<(std::ostream& os, const Magasin& magasin);

#endif //EASYSTORE_MAGASIN_H
