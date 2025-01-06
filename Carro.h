//
// Created by viniciuskl on 06/01/25.
//

#ifndef CARRO_H
#define CARRO_H
#include "TipoCarro.h"


class Carro {
private:
    TipoCarro tipoCarro;
    std::string placa;
public:
    void obterDados();
};



#endif //CARRO_H
