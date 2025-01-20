//
// Created by Carlos_Pereira on 18/01/2025
//

#include "Registro.h"
#include <iostream>
#include <utility>

Registro::Registro(std::string _dataCompra, std::string _dataUso, std::string _localCompra, const int _quantidadeComprada, std::string IDregistro) {
    dataCompra = std::move(_dataCompra);
    dataUso = std::move(_dataUso);
    localCompra = std::move(_localCompra);
    quantidadeComprada = _quantidadeComprada;
    ID_Registro = std::move(IDregistro);
};

void Registro::alterarQuantidade(const int qtd) { // função set()
    quantidadeComprada = qtd;
};

void Registro::set_dataCompra(const std::string &txt) {
    dataCompra = txt;
};

void Registro::set_ID(const std::string &ID) {
    ID_Registro = ID;

}

void Registro::set_dataUso(const std::string &txt) {
    dataUso = txt;
};

void Registro::set_localCompra(const std::string &txt) {
    localCompra = txt;
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

int Registro::get_quantidadeComprada() const {
    return quantidadeComprada;
};

std::string Registro::get_IDregistro() {
    return ID_Registro;
};

Registro::~Registro() = default;