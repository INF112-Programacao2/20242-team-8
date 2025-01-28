//
// Created by Carlos_Pereira on 18/01/2025
//

#include "../include/Fluido.h"
#include <iostream>
#include <utility>

Fluido::Fluido(std::string _nome, const double _volume_minimo, const char _unidade):
    TipoProduto(std::move(_nome)), volume_minimo(_volume_minimo) , unidade(_unidade) {}

void Fluido::set_volume_minimo(const double num) {
    volume_minimo = num;
};

void Fluido::set_unidade(const char c) {
    unidade = c;
};

double Fluido::get_volume_minimo() const {
    return volume_minimo;
};

char Fluido::get_unidade() const {
    return unidade;
};

Fluido::~Fluido() = default;