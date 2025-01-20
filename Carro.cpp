//
// Created by Carlos_Pereira on 18/01/2025
// 

#include "Carro.h"
#include <string>
#include <iostream>

Carro::Carro(std::string _nome, std::string _modelo, std::string _funcao, std::string _placa) {
    // marca?
    tipoCarro.set_modelo(_modelo);
    tipoCarro.set_funcao(_funcao);
    placa = _placa;
};

Carro::Carro() {}

Carro::~Carro() {}

void Carro::obterDados() {

}; //faz papel de get_carro (fazer chamada dos outros obterdados() aqui)

void Carro::set_placa(std::string txr) {
    placa = txr;
};

std::string Carro::get_placa() {
    return placa;
};