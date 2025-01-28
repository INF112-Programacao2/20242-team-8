//
// Created by Carlos_Pereira on 18/01/2025
//

#include "../include/Manutencao.h"
#include <iostream>
#include <utility>

Manutencao::Manutencao(std::string _nomeFuncionario, std::string IDfuncionario, std::string _data, const std::string& nome_marca, const std::string& _modelo,
    const std::string& _funcao, std::string _placa, const std::string& _nome_TipoProduto, const float _minimo, const int _quantidade, std::string _numero,
    std::string _dataCompra, std::string _dataUso, std::string _localCompra, const int _quantidadeComprada, std::string IDregistro, std::string IDManutencao):
funcionario(std::move(_nomeFuncionario), std::move(IDfuncionario)), data(std::move(_data)), carro(nome_marca, _modelo, _funcao, std::move(_placa)), produto(_nome_TipoProduto, _quantidade, nome_marca, std::move(_numero), _minimo), registro(_nome_TipoProduto, _quantidade, nome_marca, std::move(_numero), std::move(_dataCompra), std::move(_localCompra), _quantidadeComprada, std::move(IDregistro)), ID_Manutencao(std::move(IDManutencao)){}


std::string Manutencao::get_IDmanutencao() {
    return ID_Manutencao;
}

void Manutencao::alterarQuantidade(const int qtd) {
    std::cout << "O serviço aumentou ou diminuiu a quantidade de itens disponiveis? ";
    std::cout << "(1) aumentou: ";
    std::cout << "(2) diminuiu: ";
    char opcao;
    std::cout << "-> "; std::cin >> opcao;
    if (opcao == '2') {
        registro.alterarQuantidadeSubtrair(qtd);
    }
    if (opcao == '1') {
        registro.alterarQuantidadeSubtrair(qtd);
    }
}

void Manutencao::registrarDataUso(const std::string& txt) {
    registro.set_dataUso(txt);
}


Manutencao::~Manutencao() = default;