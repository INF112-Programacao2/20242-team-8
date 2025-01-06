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
    void obterDados();
};



#endif //TIPOCARRO_H
