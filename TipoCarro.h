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

    TipoCarro(const std::string &_nome, std::string _modelo, std::string _funcao);

    void obterDados() const; //faz função do get_TipoCarro
    void set_modelo(std::string txt);
    void set_funcao(std::string txt);
    std::string get_modelo();
    std::string get_funcao();
    ~TipoCarro();
};



#endif //TIPOCARRO_H
