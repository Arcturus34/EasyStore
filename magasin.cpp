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
    os << "Clients : " << std::endl;
    for(auto i=0; i<magasin.getClient().size(); i++){
        os << "    " <<magasin.getClient()[i].getNom() << " " << magasin.getClient()[i].getPrenom() << " " << magasin.getClient()[i].getIdentifiant() << std::endl;
    }
    os << "Produits : " << std::endl;
    for(auto i=0; i<magasin.getProduit().size(); i++){
        if(magasin.getProduit()[i].getQuantite() > 1) {
            os << "    " <<magasin.getProduit()[i].getTitre() << " " << magasin.getProduit()[i].getPrix() << " euros "<< magasin.getProduit()[i].getQuantite() << " exemplaires" << std::endl;
        }
        else{
            os << "    " <<magasin.getProduit()[i].getTitre() << " " << magasin.getProduit()[i].getPrix() << " euros "<< magasin.getProduit()[i].getQuantite() << " exemplaire" << std::endl;
        }
    }
    os << "Commandes : " << std::endl;
    for(auto i=0; i<magasin.getCommande().size(); i++){
        os << "    Client: " <<magasin.getCommande()[i].getClient().getNom() << " " << magasin.getCommande()[i].getClient().getPrenom() << " " << magasin.getCommande()[i].getClient().getIdentifiant();
        os << " / Produits:";
        for(auto j=0; j<magasin.getCommande()[i].getClient().getPanier().size(); j++){
            if(j == magasin.getCommande()[i].getClient().getPanier().size()-1){
                os << " "<< magasin.getCommande()[i].getClient().getPanier()[j].getTitre();
            }
            else {
                os << " " << magasin.getCommande()[i].getClient().getPanier()[j].getTitre() << " ,";
            }
        }
        os << " / Prix: " << magasin.getCommande()[i].getClient().calculerTotalPanier() << " euros";
        os << " / Status: " << magasin.getCommande()[i].getLivraison() << std::endl;
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

void Magasin::ajouterClient(Client client) {
    _clients.push_back(client);
}

std::string Magasin::getClient(std::string index) const {
    bool test = false;
    for(auto i=0; i<_clients.size(); i++){
        if(_clients[i].getIdentifiant() == index || _clients[i].getNom() == index){
            std::cout<< _clients[i].getNom() + " " + _clients[i].getPrenom()+ " " + _clients[i].getIdentifiant()<<std::endl;
            test = true;
        }
    }
    if(test == false) {
        std::cout << "Client non trouve" << std::endl;
    }
}

void Magasin::ajouterProduitPanier(Client& client, Produit& produit) {
    bool test = false;
    for (auto i = 0; i < _produits.size(); i++) {
        if (_produits[i].getTitre() == produit.getTitre()) {
            test = true;
        }
    }
    if(test == false){
        std::cout << "Produit non trouve" << std::endl;
    }
    else{
        test = false;
        for(auto i=0; i<_clients.size(); i++){
            if(_clients[i].getIdentifiant() == client.getIdentifiant()){
                client.ajouterProduit(produit);
                test = true;
            }
        }
        if(test == false){
            std::cout << "Client non trouve" << std::endl;
        }
    }
}

void Magasin::supprimerProduitPanier(Client& client, Produit& produit) {
    bool test = false;
    for(auto i=0; i<_produits.size(); i++){
        if(_produits[i].getTitre() == produit.getTitre()){
            test = true;
        }
    }
    if(test == false){
        std::cout << "Produit non trouve" << std::endl;
    }
    else {
        test = false;
        for (auto i = 0; i < _clients.size(); i++) {
            if (_clients[i].getIdentifiant() == client.getIdentifiant()) {
                client.supprimerProduit(produit);
                test = true;
                break;
            }
        }
        if (test == false) {
            std::cout << "Client non trouve" << std::endl;
        }
    }
}

void Magasin::modifierQuantiteProduitPanier(Client& client, Produit& produit, int quantite) {
    bool test = false;
    for(auto i=0; i<_produits.size(); i++){
        if(_produits[i].getTitre() == produit.getTitre()){
            test = true;
        }
    }
    if(test == false){
        std::cout << "Produit non trouve" << std::endl;
    }
    else {
        test = false;
        for (auto i = 0; i < _clients.size(); i++) {
            if (_clients[i].getIdentifiant() == client.getIdentifiant()) {
                client.modifierQuantiteProduit(produit, quantite);
                test = true;
                break;
            }
        }
        if (test == false) {
            std::cout << "Client non trouve" << std::endl;
        }
    }
}

std::vector<Commande> Magasin::getCommande() const {
    return _commandes;
}

void Magasin::validerCommande(Client& client) {
    bool test = false;
        for (auto i = 0; i < _clients.size(); i++) {
            if (_clients[i].getIdentifiant() == client.getIdentifiant()) {
                Commande commande(client);
                _commandes.push_back(commande);
                client.viderPanier();
                test = true;
                break;
            }
        }
        if (test == false) {
            std::cout << "Client non trouve" << std::endl;
        }
}