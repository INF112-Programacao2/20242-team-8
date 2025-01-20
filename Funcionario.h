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
    Funcionario(std::string _nome, std::string _ID_funcionario);
    Funcionario();
    void exibirDados(); //get_funcionario
    void set_nome(std::string _nome);
    void set_ID_Funcionario(std::string ID);
    std::string get_nome();
    std::string get_ID_funcionario();
    ~Funcionario();
};



#endif //FUNCIONARIO_H
