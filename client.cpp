//
// Created by lili3 on 19/12/2023.
//

#include "client.h"
#include <iostream>

Client::Client(std::string nom, std::string prenom, std::string identifiant, std::vector<Client>& tabIdentifiant) {
    if(identifiantValide(tabIdentifiant, identifiant)){
        _nom = nom;
        _prenom = prenom;
        _identifiant = identifiant;
        tabIdentifiant.push_back(*this);
    }
    else {
        std::cout << "Identifiant invalide" << std::endl;
    }
}

Client::Client() {}

std::string Client::getNom() const {
    return _nom;
}

std::string Client::getPrenom() const {
    return _prenom;
}

std::string Client::getIdentifiant() const {
    return _identifiant;
}

bool Client::identifiantValide(std::vector<Client> tabIdentifiant, std::string identifiant) const{
    for (int i = 0; i < tabIdentifiant.size(); i++) {
        if (tabIdentifiant[i].getIdentifiant() == identifiant) {
            return false;
        }
    }
    return true;
}

void Client::ajouterProduit(Produit produit) {
    _panier.push_back(produit);
}

std::vector<Produit> Client::getPanier() const {
    return _panier;
}

float Client::calculerTotalPanier() const {
    float total = 0;
    for(auto i=0; i<_panier.size(); i++){
        total += _panier[i].getPrix();
    }
    return total;
}

std::ostream& operator<<(std::ostream& os, const Client& client){
    os << "Nom : " << client.getNom() << std::endl;
    os << "Prenom : " << client.getPrenom() << std::endl;
    os << "Identifiant : " << client.getIdentifiant() << std::endl;
    os << "Panier :" << std::endl;
    for(auto i=0; i<client.getPanier().size(); i++){
        os << "    " <<client.getPanier()[i].getTitre() << " " << client.getPanier()[i].getPrix()<<" euros"<< std::endl;
    }
    os << "    Prix total du panier : " << client.calculerTotalPanier() << " euros";
    return os;
}

void Client::viderPanier() {
    _panier.clear();
}

void Client::modifierQuantiteProduit(Produit produit, int quantite) {
    bool test = false;
    for(auto i=0; i<_panier.size(); i++){
        if(_panier[i].getTitre() == produit.getTitre()){
            _panier.erase(_panier.begin()+i);
            test = true;
        }
    }
    if(test == true){
        for(auto i=0; i<quantite; i++){
            _panier.push_back(produit);
            }
        }
    else{
        std::cout << "Produit non trouve" << std::endl;
    }
}

void Client::supprimerProduit(Produit produit) {
    bool test = false;
    for(auto i=0; i<_panier.size(); i++){
            if (_panier[i].getTitre() == produit.getTitre()) {
                _panier.erase(_panier.begin() + i);
                test = true;
                break;
            }
    }
    if(test == false){
        std::cout << "Produit non trouve" << std::endl;
    }
}