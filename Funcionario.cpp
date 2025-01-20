//
// Created by Carlos_Pereira on 18/01/2025
// 

#include "Funcionario.h"
#include <string>
#include <iostream>
#include <utility>

Funcionario::Funcionario(std::string _nome, std::string _ID_funcionario) {
    nome = std::move(_nome);
    ID_Funcionario = std::move(_ID_funcionario);
};

Funcionario::~Funcionario() = default;

void Funcionario::exibirDados() const { // funciona como "get_dados()"
    std::cout << "nome do funcionário: " << nome << '\n';
    std::cout << "ID do funcionário: " << ID_Funcionario << '\n';
};

void Funcionario::set_nome(std::string _nome) {
    nome = std::move(_nome);
};

void Funcionario::set_ID_Funcionario(std::string ID) {
    ID_Funcionario = std::move(ID);
};

std::string Funcionario::get_nome() {
    return nome;
};

std::string Funcionario::get_ID_funcionario() {
    return ID_Funcionario;
};