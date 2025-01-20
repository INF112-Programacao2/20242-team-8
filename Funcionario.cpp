//
// Created by Carlos_Pereira on 18/01/2025
// 

#include "Funcionario.h"
#include <string>
#include <iostream>

Funcionario::Funcionario(std::string _nome, std::string _ID_funcionario) {
    nome = _nome;
    ID_Funcionario = _ID_funcionario;
};

Funcionario::Funcionario() {}

Funcionario::~Funcionario() {}

void Funcionario::exibirDados() { // funciona como "get_dados()"
    std::cout << "nome do funcionário: " << nome << '\n';
    std::cout << "ID do funcionário: " << ID_Funcionario << '\n';
    return;
};

void Funcionario::set_nome(std::string _nome) {
    nome = _nome;
    return;
};

void Funcionario::set_ID_Funcionario(std::string ID) {
    ID_Funcionario = ID;
    return;
};

std::string Funcionario::get_nome() {
    return nome;
};

std::string Funcionario::get_ID_funcionario() {
    return ID_Funcionario;
};