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
    void alterarQuantidade();
};



#endif //REGISTRO_H
