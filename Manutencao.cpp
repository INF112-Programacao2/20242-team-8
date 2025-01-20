//
// Created by Carlos_Pereira on 18/01/2025
//

#include "Manutencao.h"
#include <iostream>
#include <utility>

Manutencao::Manutencao(std::string _nomeFuncionario, std::string IDfuncionario, std::string _data, const std::string& nome_marca, const std::string& _modelo,
    const std::string& _funcao, std::string _placa, const std::string& _nome_TipoProduto, const float _minimo, const int _quantidade, std::string _numero,
    std::string _dataCompra, std::string _dataUso, std::string _localCompra, const int _quantidadeComprada, std::string IDregistro, std::string IDManutencao):
funcionario(std::move(_nomeFuncionario), std::move(IDfuncionario)), data(std::move(_data)), carro(nome_marca, _modelo, _funcao, std::move(_placa)), produto(_nome_TipoProduto, _minimo, _quantidade, nome_marca, std::move(_numero)), registro(std::move(_dataCompra), std::move(_dataUso), std::move(_localCompra), _quantidadeComprada, std::move(IDregistro)), ID_Manutencao(std::move(IDManutencao)){}

std::string Manutencao::get_IDmanutencao() {
    return ID_Manutencao;
}

Manutencao::~Manutencao() = default;