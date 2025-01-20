//
// Created by viniciuskl on 06/01/25.
//

#ifndef REGISTRO_H
#define REGISTRO_H
#include <string>


class Registro {
private:
    std::string dataCompra;
    std::string dataUso;
    std::string localCompra;
    int quantidadeComprada;
    std::string ID_Registro;
public:
    Registro(std::string _dataCompra, std::string _dataUso, std::string _localCompra, int _quantidadeComprada, std::string IDregistro);
    Registro();
    void alterarQuantidade(int qtd); //set quantidade
    void set_dataCompra(std::string txt);
    void set_dataUso(std::string txt);
    void set_localCompra(std::string txt);
    void set_ID(std::string _ID);
    std::string get_dataCompra();
    std::string get_dataUso();
    std::string get_localCompra();
    int get_quantidadeComprada();
    std::string get_IDregistro();
    ~Registro();
};



#endif //REGISTRO_H
