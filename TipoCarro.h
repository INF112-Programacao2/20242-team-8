//
// Created by viniciuskl on 06/01/25.
//

#ifndef TIPOCARRO_H
#define TIPOCARRO_H
#include "Marca.h"


class TipoCarro {
private:
    Marca marca;
    std::string modelo;
    std::string funcao;
public:
    TipoCarro(std::string _nome, std::string _modelo, std::string _funcao);
    void obterDados(); //faz função do get_TipoCarro
    std::string set_modelo(std::string txt);
    std::string set_funcao(std::string txt);
    void get_modelo();
    void get_funcao();
    ~TipoCarro();
};



#endif //TIPOCARRO_H
