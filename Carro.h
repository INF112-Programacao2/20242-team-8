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
    Carro(std::string _nome, std::string _modelo, std::string _funcao, std::string placa);
    Carro();
    void obterDados(); //faz papel de get_carro (fazer chamada dos outros obterdados() aqui)
    void set_placa(std::string txr);
    std::string get_placa();
    ~Carro();
};



#endif //CARRO_H
