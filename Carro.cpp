//
// Created by Carlos_Pereira on 18/01/2025
// 

#include "Carro.h"
#include <string>
#include <iostream>
#include <utility>

Carro::Carro(const std::string& _nome, const std::string& _modelo, const std::string& _funcao, std::string placa):
    tipoCarro(_nome, _modelo, _funcao), placa(std::move(placa)) {}

Carro::~Carro()= default;

void Carro::obterDados() const {
    tipoCarro.obterDados();
    std::cout << "Placa do veiculo: " << placa << "\n";
}; //faz papel de get_carro (fazer chamada dos outros obterdados() aqui)

void Carro::set_placa(std::string txr) {
    placa = std::move(txr);
};

std::string Carro::get_placa() {
    return placa;
};