//
// Created by viniciuskl on 06/01/25.
//

#ifndef REGISTRO_H
#define REGISTRO_H
#include <string>

#include "Produto.h"


class Registro {
private:
    Produto *produto;
    std::string dataCompra;
    std::string dataUso;
    std::string localCompra;
    int quantidadeComprada;
    std::string ID_Registro;
public:
    Registro(std::string _nome, int quantidade, std::string nome_marca, std::string numero, std::string _dataCompra, std::string _localCompra, int _quantidadeComprada, std::string IDregistro);
    void alterarQuantidade(int qtd); //set quantidade
    void alterarQuantidadeAcrescentar(int qtd); //soma
    void alterarQuantidadeSubtrair(int qtd); //subtrai
    void set_dataCompra(const std::string &txt);
    void set_dataUso(const std::string &txt);
    void set_localCompra(const std::string &txt);
    void set_ID(const std::string &_ID);
    std::string get_dataCompra();
    std::string get_dataUso();
    std::string get_localCompra();
    int get_quantidadeComprada() const;
    std::string get_IDregistro();
    ~Registro();
};



#endif //REGISTRO_H
