//
// Created by Carlos_Pereira on 18/01/2025
//

#include "Produto.h"
#include <iostream>

Produto::Produto(std::string _nome, float _minimo, int _quantidade, std::string nome_marca, std::string _numero) { // o atributo carrosCompativeis será atribuido apenas após utilizarmos o método criaVetorCarros()
    tipo.set_nome(_nome);
    quantidade = _quantidade;
    marca.set_nome(nome_marca);
    numero = _numero;
    // o que fazer com o _mínimo??
}

Produto::Produto() {}

void Produto::obterDados() {
    std::cout << "Nome do produto: " << tipo.get_nome() << '\n';
    std::cout << "Quantidade do produto: " << quantidade << '\n';
    std::cout << "Marca usada pelo produto " << marca.get_nome() << '\n';
    std::cout << "Número (ID) do produto " << numero << '\n';
};

void Produto::alterarQuantidade(int value) { // setQuantidade()
    quantidade = value;
    return;
}

void Produto::set_numero(std::string num) {
    numero = num;
    return;
};

int Produto::get_quantidade() {
    return quantidade;
};

std::string Produto::get_numero() {
    return numero;
};

void Produto::criaVetorCarros() {
    // ??
};

Produto::~Produto() {
    // delete carrosCompativeis
};