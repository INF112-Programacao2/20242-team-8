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
    explicit Marca(const std::string &_nome);
    void obterDados() const; //faz função de get_marca
    void set_nome(const std::string &txt);
    std::string get_nome();
    ~Marca();
};



#endif //MARCA_H
