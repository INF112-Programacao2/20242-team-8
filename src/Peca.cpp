//
// Created by Carlos_Pereira on 18/01/2025
//

#include "../include/Peca.h"
#include <iostream>

Peca::Peca(const std::string &_nome, const int _quantidade_minima):
    TipoProduto(_nome), quantidade_minima(_quantidade_minima) {}

void Peca::set_quantidade_minima() {
    std::cin >> quantidade_minima;
};

int Peca::get_quantidade_minima() const {
    return quantidade_minima;
};

void Peca::obterDados(){
    std::cout << "Nome da peca: " << get_nome();
}

Peca::~Peca() = default;
