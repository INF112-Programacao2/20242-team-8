//
// Created by viniciuskl on 06/01/25.
//

#ifndef TIPOPRODUTO_H
#define TIPOPRODUTO_H
#include <string>

class TipoProduto {
private:
    std::string nome;
public:
    explicit TipoProduto(std::string _nome);
    TipoProduto();
    void obterDados(); //get Tipo_Produto
    void set_nome(std::string txt);
    std::string get_nome();
    ~TipoProduto();
};



#endif //TIPOPRODUTO_H
