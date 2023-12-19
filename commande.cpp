//
// Created by lili3 on 19/12/2023.
//

#include "commande.h"

#include <iostream>

Commande::Commande(Client client) {
    _client = client;
    _produits = client.getPanier();
    _livraison = false;
}

Client Commande::getClient() const {
    return _client;
}

std::vector<Produit> Commande::getProduits() const {
    return _produits;
}

bool Commande::getLivraison() const {
    if(_livraison == true){
        std::cout<< "Commande livree" << std::endl;
    }
    else{
        std::cout<< "Commande non livree" << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Commande& commande){
    os << "Client : " << commande.getClient().getNom() << " " << commande.getClient().getPrenom() << " " << commande.getClient().getIdentifiant() << std::endl;
    os << "Produits : " << std::endl;
    for(auto i=0; i<commande.getProduits().size(); i++){
            os << "    " <<commande.getProduits()[i].getTitre() << " " << commande.getProduits()[i].getPrix() << " euros "<< std::endl;
        }
    os << "Status : " << commande.getLivraison() << std::endl;
    return os;
}