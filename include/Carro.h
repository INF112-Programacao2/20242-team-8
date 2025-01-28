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
    Carro(const std::string& _nome, const std::string& _modelo, const std::string& _funcao, std::string placa);
    void obterDados() const; //faz papel de get_carro (fazer chamada dos outros obterdados() aqui)
    void set_placa(std::string txr);
    std::string get_placa();
    ~Carro();
};



#endif //CARRO_H
