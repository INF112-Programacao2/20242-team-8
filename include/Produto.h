//
// Created by viniciuskl on 06/01/25.
//

#ifndef PRODUTO_H
#define PRODUTO_H
#include "Marca.h"
#include "TipoCarro.h"
#include "TipoProduto.h"
#include <string>

#include "Fluido.h"
#include "Peca.h"

class Produto {
private:
    TipoProduto tipo_produto_produto;
    std::string tipo{}; //FLUIDO OU PECA //usar string compare
    int quantidade;
    double minimo{};
    Marca marca;
    TipoCarro* carrosCompativeis{};
    std::string numero;
public:
    //o atributo carrosCompativeis será atribuido apenas após utilizarmos o método criaVetorCarros()
    Produto(std::string _nome, int _quantidade, const std::string &nome_marca, std::string _numero, double _minimo);
    Produto(std::string _nome, int _quantidade, const std::string& nome_marca, std::string numero);
    void obterDados();
    std::string getTipo();
    void setTipo(std::string _tipo);
    static std::string defineTipo();
    void alterarQuantidade(int value); //set_quantidade
    void set_numero(const std::string &num);
    int get_quantidade() const;
    std::string get_numero();
    void criaVetorCarros();
    ~Produto();
};



#endif //PRODUTO_H
