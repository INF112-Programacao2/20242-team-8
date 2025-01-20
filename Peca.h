//
// Created by viniciuskl on 06/01/25.
//

#ifndef PECA_H
#define PECA_H
#include "TipoProduto.h"


class Peca : public TipoProduto{
private:
    int quantidade_minima;
public:
    Peca(std::string _nome, int _quantidade_minima);
    void set_quantidade_minima();
    int get_quantidade_minima();
    ~Peca();
};



#endif //PECA_H
