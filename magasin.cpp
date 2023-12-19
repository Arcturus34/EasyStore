//
// Created by lili3 on 19/12/2023.
//

#include "magasin.h"

#include <iostream>

Magasin::Magasin() {}

std::vector<Client> Magasin::getClient() const {
    return _clients;
}

std::vector<Produit> Magasin::getProduit() const {
    return _produits;
}

void Magasin::ajouterProduit(Produit produit) {
    _produits.push_back(produit);
}

std::ostream& operator<<(std::ostream& os, const Magasin& magasin){
    os << "Produits : " << std::endl;
    for(auto i=0; i<magasin.getProduit().size(); i++){
        if(magasin.getProduit()[i].getQuantite() > 1) {
            os << magasin.getProduit()[i].getTitre() << " " << magasin.getProduit()[i].getPrix() << " euros "<< magasin.getProduit()[i].getQuantite() << " exemplaires" << std::endl;
        }
        else{
            os << magasin.getProduit()[i].getTitre() << " " << magasin.getProduit()[i].getPrix() << " euros "<< magasin.getProduit()[i].getQuantite() << " exemplaire" << std::endl;
        }
    }
    return os;
}

Produit Magasin::getProduit(std::string titre) const {
    for(auto i=0; i<_produits.size(); i++){
        if(_produits[i].getTitre() == titre){
            return _produits[i];
        }
    }
    std::cout << "Produit non trouve" << std::endl;
}

void Magasin::modifierQuantite(std::string titre, int quantite) {
    bool test = false;
    for(auto i=0; i<_produits.size(); i++){
        if(_produits[i].getTitre() == titre){
            _produits[i].setQuantite(quantite);
            test = true;
        }
    }
    if(test == false){
        std::cout << "Produit non trouve" << std::endl;
    }
}