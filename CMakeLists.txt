cmake_minimum_required(VERSION 3.26)
project(EasyStore)

set(CMAKE_CXX_STANDARD 14)

add_executable(EasyStore
        main.cpp
        produit.h
        produit.cpp
        client.h
        client.cpp
        magasin.h
        magasin.cpp
        commande.h
        commande.cpp)
