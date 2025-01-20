//
// Created by Carlos_Pereira on 18/01/2025
//

#include "Fluido.h"
#include <iostream>

Fluido::Fluido(std::string _nome, double _volume_minimo, char _unidade):
    TipoProduto(_nome), volume_minimo(_volume_minimo) , unidade(_unidade) {}

void Fluido::set_volume_minimo(double num) {
    volume_minimo = num;
    return;
};

void Fluido::set_unidade(char c) {
    unidade = c;
    return;
};

double Fluido::get_volume_minimo() {
    return volume_minimo;
};

char Fluido::get_unidade() {
    return unidade;
};

Fluido::~Fluido() {};