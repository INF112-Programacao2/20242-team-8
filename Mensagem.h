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
    void exibirMensagem();
};



#endif //MENSAGEM_H
