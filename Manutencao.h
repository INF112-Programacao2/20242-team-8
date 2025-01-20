//
// Created by viniciuskl on 06/01/25.
//

#ifndef MANUTENCAO_H
#define MANUTENCAO_H
#include "Funcionario.h"
#include <string>

#include "Carro.h"
#include "Produto.h"
#include "Registro.h"

class Manutencao {
private:
    Funcionario funcionario;
    std::string data;
    Carro carro;
    Produto produto;
    Registro registro;
    std::string ID_Manutencao;
public:
    Manutencao(std::string _nomeFuncionario, std::string IDfuncionario, std::string _data, std::string nome_marca, std::string _modelo,
        std::string _funcao, std::string _placa, std::string _nome_TipoProduto, float _minimo, int _quantidade, std::string _numero,
        std::string _dataCompra, std::string _dataUso, std::string _localCompra, int _quantidadeComprada, std::string IDregistro, std::string IDManutencao);
    void alterarQuantidade();
    void registrarDataUso();
    std::string get_IDmanutencao();
    ~Manutencao();
};

#endif //MANUTENCAO_H
