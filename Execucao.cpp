#include "Execucao.h"
#include <iostream>

void Execucao::telaInicial(){
    int valor;
    valor = Interface::exibirMenuPrincipal();
    switch(valor){
    case 1:
        Execucao::telaProduto();
        break;
    case 2:
        Execucao::telaVeiculo();
        break;
    case 3:
        Execucao::telaFuncionario();
        break;
    case 4:
        Execucao::telaManutencao();
        break;
    case 5:
        exit(0);
        break;
    }
}

void Execucao::telaProduto(){
    int valor;
    valor = Interface::exibirSubcategoriaProduto();
    switch(valor){
    case 1:
        Execucao::telaAdicionarProduto();
        break;
    case 2:
        Execucao::telaConferirEstoque();
        break;
    case 3:
        Execucao::telaExcluirProduto();
        break;
    case 4:
        Execucao::telaAlterarDados();
        break;
    case 5:
        Execucao::telaInicial();
        break;
    }
};