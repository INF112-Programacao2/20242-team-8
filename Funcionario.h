//
// Created by viniciuskl on 06/01/25.
//

#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#include <string>


class Funcionario {
private:
    std::string nome;
    std::string ID_Funcionario;
public:
    Funcionario(std::string _nome, std::string ID_funcionario);
    void exibirDados(); //get_funcionario
    std::string set_nome(std::string _nome);
    std::string set_ID_Funcionario(std::string ID);
    void get_nome();
    void get_ID_funcionario();
};



#endif //FUNCIONARIO_H
