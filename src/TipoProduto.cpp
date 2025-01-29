//
// Created by Carlos_Pereira on 18/01/2025
//

#include "../include/TipoProduto.h"
#include <iostream>
#include <utility>

TipoProduto::TipoProduto(std::string _nome) {
    nome = std::move(_nome);
};

void TipoProduto::obterDados() const { //getDados
};

void TipoProduto::set_nome(const std::string &txt) {
    nome = txt;
};

std::string TipoProduto::get_nome() {
    return nome;
};

TipoProduto::~TipoProduto() = default;
