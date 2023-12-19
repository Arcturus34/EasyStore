//
// Created by lili3 on 19/12/2023.
//

#include "produit.h"
#include <iostream>

Produit::Produit(std::string titre, std::string description, int quantite, float prix) {
    if (titre.empty() || description.empty() || quantite < 0 || prix < 0) {
        std::cout<<("Erreur : un des parametres est incorrect")<<std::endl;
    }
    else {
        _titre = titre;
        _description = description;
        _quantite = quantite;
        _prix = prix;
    }
}

std::string Produit::getTitre() const {
    return _titre;
}

std::string Produit::getDescription() const {
    return _description;
}

int Produit::getQuantite() const {
    return _quantite;
}

float Produit::getPrix() const {
    return _prix;
}

void Produit::setQuantite(int quantite) {
    _quantite = quantite;
}

std::ostream& operator<<(std::ostream& os, const Produit& produit) {
    os << "Titre : " << produit.getTitre() << std::endl;
    os << "Description : " << produit.getDescription() << std::endl;
    os << "Quantite : " << produit.getQuantite()<< std::endl;
    os << "Prix : " << produit.getPrix()<< " euros" << std::endl;
    return os;
}

