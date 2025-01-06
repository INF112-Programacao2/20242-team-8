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
    void alterarQuantidade();
    void registrarDataUso();
};



#endif //MANUTENCAO_H
