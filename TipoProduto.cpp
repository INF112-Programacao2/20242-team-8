//
// Created by Carlos_Pereira on 18/01/2025
//

#include "TipoProduto.h"
#include <iostream>

TipoProduto::TipoProduto(std::string _nome) {
    nome = _nome;
};

TipoProduto::TipoProduto() {}

void TipoProduto::obterDados() { //getDados
    std::cout << "Nome do produto: " << nome << '\n';
    return;
};

void TipoProduto::set_nome(std::string txt) {
    nome = txt;
    return;
};

std::string TipoProduto::get_nome() {
    return nome;
};

TipoProduto::~TipoProduto() {};