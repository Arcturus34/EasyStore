//
// Created by lili3 on 19/12/2023.
//

#ifndef EASYSTORE_COMMANDE_H
#define EASYSTORE_COMMANDE_H

#include "client.h"

class Commande {
public:
    Commande(Client client);
    Client getClient() const;
    std::vector<Produit> getProduits() const;
    bool getLivraison() const;
private:
    Client _client;
    std::vector<Produit> _produits;
    bool _livraison;
};

std::ostream& operator<<(std::ostream& os, const Commande& magasin);

#endif //EASYSTORE_COMMANDE_H
