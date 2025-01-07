//
// Created by viniciuskl on 06/01/25.
//

#ifndef FLUIDO_H
#define FLUIDO_H
#include "TipoProduto.h"


class Fluido: public TipoProduto{
private:
    double volume_minimo;
    char unidade;
public:
    Fluido(std::string _nome, double _volume_minimo, char _unidade);
    double set_volume_minimo(double num);
    char set_unidade(char c);
    void get_volume_minimo();
    void get_unidade();
    ~Fluido();
};



#endif //FLUIDO_H
