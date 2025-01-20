//
// Created by viniciuskl on 06/01/25.
//

#ifndef MENSAGEM_H
#define MENSAGEM_H
#include "Manutencao.h"
#include <string>

class Mensagem {
private:
    Manutencao manutencao_;
    std::string conteudo;
public:
    Mensagem(std::string _nomeFuncionario, std::string IDfuncionario, std::string _data, const std::string& nome_marca, const std::string& _modelo,
    const std::string& _funcao, std::string _placa, const std::string& _nome_TipoProduto, float _minimo, int _quantidade, std::string _numero,
    std::string _dataCompra, std::string _dataUso, std::string _localCompra, int _quantidadeComprada, std::string IDregistro, std::string IDManutencao);
    void exibirMensagem();
    void gera_conteudo(std::string txt);
    std::string getConteudo();
    ~Mensagem();
};



#endif //MENSAGEM_H
