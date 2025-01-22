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
    Mensagem(std::string nomeFuncionario, std::string idFuncionario, std::string dataManutencao, std::string nomeCarro,
        std::string modeloCarro, std::string funcaoCarro, std::string PlacaCarro, std::string nomeTipoProduto, int quantidadeProduto, std::string numeroProduto, std::string dataCompraRegistro,
        std::string dataUsoRegistro, std::string localCompraRegistro, int quantidadeCompradaRegistro, std::string idRegistro, std::string idManutencao);
    void exibirMensagem();
    void gera_conteudo(std::string txt);
    ~Mensagem();
};



#endif //MENSAGEM_H
