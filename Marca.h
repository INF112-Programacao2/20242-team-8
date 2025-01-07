//
// Created by viniciuskl on 06/01/25.
//

#ifndef MARCA_H
#define MARCA_H
#include <string>


class Marca {
private:
    std::string nome;
public:
    explicit Marca(std::string _nome);
    void obterDados(); //faz função de get_marca
    std::string set_nome(std::string txt);
    void get_nome();
    ~Marca();
};



#endif //MARCA_H
