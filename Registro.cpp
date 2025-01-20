//
// Created by Carlos_Pereira on 18/01/2025
//

#include "Registro.h"
#include <iostream>

Registro::Registro(std::string _dataCompra, std::string _dataUso, std::string _localCompra, int _quantidadeComprada, std::string IDregistro) {
    dataCompra = _dataCompra;
    dataUso = _dataUso;
    localCompra = _localCompra;
    quantidadeComprada = _quantidadeComprada;
    ID_Registro = IDregistro;
};

Registro::Registro() {}

void Registro::alterarQuantidade(int qtd) { // função set()
    quantidadeComprada = qtd;
    return;
};

void Registro::set_dataCompra(std::string txt) {
    dataCompra = txt;
    return;
};

void Registro::set_ID(std::string txt) {
    ID_Registro = txt;
    return;
}

void Registro::set_dataUso(std::string txt) {
    dataUso = txt;
    return;
};

void Registro::set_localCompra(std::string txt) {
    localCompra = txt;
    return;
};

std::string Registro::get_dataCompra() {
    return dataCompra;
};

std::string Registro::get_dataUso() {
    return dataUso;
};

std::string Registro::get_localCompra() {
    return localCompra;
};

int Registro::get_quantidadeComprada() {
    return quantidadeComprada;
};

std::string Registro::get_IDregistro() {
    return ID_Registro;
};

Registro::~Registro() {}