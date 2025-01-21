//
// Created by Carlos_Pereira on 18/01/2025
//

#include "TipoCarro.h"
#include "Marca.h"
#include <iostream>
#include <utility>

TipoCarro::TipoCarro(const std::string& _nome, std::string _modelo, std::string _funcao):
    marca(_nome), modelo(std::move(_modelo)), funcao(std::move(_funcao)) {}

void TipoCarro::obterDados() const { //faz função de get_TipoCarro
    marca.obterDados();
    std::cout << "Modelo do carro: " << modelo << '\n';
    std::cout << "Função do carro: " << funcao << '\n';
};

void TipoCarro::set_modelo(std::string txt) {
    modelo = std::move(txt);
};

void TipoCarro::set_funcao(std::string txt) {
    funcao = std::move(txt);
};

std::string TipoCarro::get_modelo() {
    return modelo;
};

std::string TipoCarro::get_funcao() {
    return funcao;
};

TipoCarro::~TipoCarro() = default;