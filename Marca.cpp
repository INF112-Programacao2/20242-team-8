//
// Created by Carlos_Pereira on 18/01/2025
//

#include "Marca.h"
#include <iostream>

Marca::Marca(const std::string &_nome) {
    nome = _nome;
};

void Marca::obterDados() const { // função de getMarca()
    std::cout << "Nome da Marca: " << nome << '\n';
};

void Marca::set_nome(const std::string &txt) {
    nome = txt;
};

std::string Marca::get_nome() {
    return nome;
};

Marca::~Marca() = default;