//
// Created by Carlos_Pereira on 18/01/2025
//

#include "Manutencao.h"
#include <iostream>

Manutencao::Manutencao(std::string _nomeFuncionario, std::string IDfuncionario, std::string _data, std::string nome_marca, std::string _modelo,
    std::string _funcao, std::string _placa, std::string _nome_TipoProduto, float _minimo, int _quantidade, std::string _numero,
    std::string _dataCompra, std::string _dataUso, std::string _localCompra, int _quantidadeComprada, std::string IDregistro, std::string IDManutencao) {

    funcionario.set_nome(_nomeFuncionario);
    funcionario.set_ID_Funcionario(IDfuncionario);

    data = _data;

    // nome_marca -> carro -> tipoCarro -> Marca -> setNome()
    carro.set_placa(_placa);

    // produto -> tipoProduto -> setNome()

    registro.set_dataCompra(_dataCompra);
    registro.set_dataUso(_dataUso);
    registro.set_localCompra(_localCompra);
    registro.alterarQuantidade(_quantidadeComprada);
    registro.set_ID(IDregistro);
    ID_Manutencao = IDManutencao;
};

/*
void Manutencao::alterarQuantidade() {

};

void Manutencao::registrarDataUso() {

};
*/

std::string Manutencao::get_IDmanutencao() {
    return ID_Manutencao;
};

Manutencao::~Manutencao() {};