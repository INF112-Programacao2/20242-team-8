//
// Created by Carlos_Pereira on 18/01/2025
//

#include "Peca.h"
#include <iostream>

Peca::Peca(std::string _nome, int _quantidade_minima):
    TipoProduto(_nome), quantidade_minima(_quantidade_minima) {}

void Peca::set_quantidade_minima() {
    std::cin >> quantidade_minima;
    return;
};

int Peca::get_quantidade_minima() {
    return quantidade_minima;
};

Peca::~Peca() {};