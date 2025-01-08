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
    Mensagem();
    void exibirMensagem();
    void set_conteudo(std::string txt);
    std::string get_conteudo();
    ~Mensagem();
};



#endif //MENSAGEM_H
