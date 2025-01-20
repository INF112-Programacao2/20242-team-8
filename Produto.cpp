//
// Created by Carlos_Pereira on 18/01/2025
//

#include "Produto.h"
#include <iostream>
#include <utility>

Produto::Produto(const std::string& _nome, float _minimo, int _quantidade, const std::string& nome_marca, std::string _numero):
tipo(_nome), quantidade(_quantidade), marca(nome_marca), numero(std::move(_numero)){}// o atributo carrosCompativeis será atribuido apenas após utilizarmos o método criaVetorCarros()

void Produto::obterDados() {
    tipo.obterDados();
    std::cout << "Quantidade do produto: " << quantidade << '\n';
    std::cout << "Marca usada pelo produto " << marca.get_nome() << '\n';
    std::cout << "Número (ID) do produto " << numero << '\n';
};

void Produto::alterarQuantidade(int value) { // setQuantidade()
    quantidade = value;
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