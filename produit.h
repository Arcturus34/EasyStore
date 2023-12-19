//
// Created by lili3 on 19/12/2023.
//

#ifndef EASYSTORE_PRODUIT_H
#define EASYSTORE_PRODUIT_H

#include <string>

class Produit {
public:
    Produit(std::string titre, std::string description, int quantite, float prix);
    std::string getTitre() const;
    std::string getDescription() const;
    int getQuantite() const;
    float getPrix() const;
    void setQuantite(int quantite);

private:
    std::string _titre;
    std::string _description;
    int _quantite;
    float _prix;

};

std::ostream& operator<<(std::ostream& os, const Produit& produit);

#endif //EASYSTORE_PRODUIT_H
