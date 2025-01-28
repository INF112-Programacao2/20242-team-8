//
// Created by Carlos_Pereira on 18/01/2025
//

#include "../include/Produto.h"
#include <iostream>
#include <thread>
#include <utility>

#include "../include/KeyboardInput.h"

Produto::Produto(std::string _nome, const int _quantidade, const std::string& nome_marca, std::string _numero, const double _minimo):
tipo_produto_produto(std::move(_nome)), quantidade(_quantidade), minimo(_minimo), marca(nome_marca), numero(std::move(_numero)){}// o atributo carrosCompativeis será atribuido apenas após utilizarmos o método criaVetorCarros()

Produto::Produto(std::string _nome, const int _quantidade, const std::string& nome_marca, std::string numero):
    tipo_produto_produto(std::move(_nome)), quantidade(_quantidade), marca(nome_marca), numero(std::move(numero)){}

void Produto::obterDados() {
    tipo_produto_produto.obterDados();
    std::cout << "Quantidade do produto: " << quantidade << '\n';
    std::cout << "Minimo permitido no estoque: " << minimo << '\n';
    std::cout << "Marca usada pelo produto: " << marca.get_nome() << '\n';
    std::cout << "Número (ID) do produto: " << numero << '\n';
};

void Produto::alterarQuantidade(const int value) { // setQuantidade()
    quantidade = value;
}

void Produto::set_numero(const std::string &num) {
    numero = num;
};

int Produto::get_quantidade() const {
    return quantidade;
};

std::string Produto::get_numero() {
    return numero;
};

void Produto::setTipo(std::string _tipo) {
    tipo = std::move(_tipo);
}

std::string Produto::defineTipo() {
    bool verificador = false;
    do{
    std::cout << "Defina o tipo do produto: " << '\n';
    std::cout << "Aperte (1) para produtos do tipo FLUIDO:" << '\n';
    std::cout << "Aperte (2) para produtos do tipo PEÇA:" << '\n';
    int opcao;
    std::cout << "-> ";
    try{
    std::cin >> opcao;
    if(opcao<1 || opcao>2){
      throw std::invalid_argument("Opcao invalida! Insira novamente!");
    }
    }
    catch (std::invalid_argument& e) {
      std::cout << e.what() << '\n';
      verificador = true;
    }
    if (opcao == 1) {
        return "Fluido";
    }
    else if (opcao == 2) {
       return "Peca";
        }
    }while(verificador);
}

std::string Produto::getTipo() {
    return tipo;
}

void Produto::criaVetorCarros() {

};

Produto::~Produto()= default;