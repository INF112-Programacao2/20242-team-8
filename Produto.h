//
// Created by viniciuskl on 06/01/25.
//

#ifndef PRODUTO_H
#define PRODUTO_H
#include "Marca.h"
#include "TipoCarro.h"
#include "TipoProduto.h"
#include <string>

class Produto {
private:
    TipoProduto tipo;
    int quantidade;
    Marca marca;
    TipoCarro * carrosCompativeis;
    std::string numero;
public:
    void obterDados();
    void alterarQuantidade();
};



#endif //PRODUTO_H
