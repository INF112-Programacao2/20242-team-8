//
// Created by Carlos_Pereira on 18/01/2025
//

#include "TipoCarro.h"
#include "Marca.h"
#include <iostream>

TipoCarro::TipoCarro(std::string _nome, std::string _modelo, std::string _funcao) {
    marca.set_nome(_nome);
    modelo = _modelo;
    funcao = _funcao;
};

TipoCarro::TipoCarro() {}

void TipoCarro::obterDados() { //faz função de get_TipoCarro
    std::cout << "Marca do carro: " << marca.get_nome() << '\n';
    std::cout << "Modelo do carro: " << modelo << '\n';
    std::cout << "Função do carro: " << funcao << '\n';
    return;
};

void TipoCarro::set_modelo(std::string txt) {
    modelo = txt;
    return;
};

void TipoCarro::set_funcao(std::string txt) {
    funcao = txt;
    return;
};

std::string TipoCarro::get_modelo() {
    return modelo;
};

std::string TipoCarro::get_funcao() {
    return funcao;
};

TipoCarro::~TipoCarro() {};