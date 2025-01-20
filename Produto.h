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
    TipoCarro* carrosCompativeis;
    std::string numero;
public:
    Produto(std::string _nome, float _minimo, int _quantidade, std::string nome_marca, std::string _numero); //o atributo carrosCompativeis será atribuido apenas após utilizarmos o método criaVetorCarros()
    Produto();
    void obterDados();
    void alterarQuantidade(int value); //set_quantidade
    void set_numero(std::string num);
    int get_quantidade();
    std::string get_numero();
    void criaVetorCarros();
    ~Produto();
};



#endif //PRODUTO_H
