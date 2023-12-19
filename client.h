//
// Created by lili3 on 19/12/2023.
//

#ifndef EASYSTORE_CLIENT_H
#define EASYSTORE_CLIENT_H

#include "produit.h"

#include <string>
#include <vector>

class Client {
public:
    Client (std::string nom, std::string prenom, std::string identifiant, std::vector<Client>& tabIdentifiant);
    std::string getNom() const;
    std::string getPrenom() const;
    std::string getIdentifiant() const;
    std::vector<Produit> getPanier() const;
    bool identifiantValide(std::vector<Client> tabIdentifiant, std::string indentifiant) const;
    void ajouterProduit(Produit produit);
    void viderPanier();
    float calculerTotalPanier() const;
    void modifierQuantiteProduit(Produit produit, int quantite);
    void supprimerProduit(Produit produit);

private:
    std::string _nom;
    std::string _prenom;
    std::string _identifiant;
    std::vector<Produit> _panier;
};

std::ostream& operator<<(std::ostream& os, const Client& client);

#endif //EASYSTORE_CLIENT_H
