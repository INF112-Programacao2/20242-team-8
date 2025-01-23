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

void Execucao::telaFuncionario(){
    int valor;
    valor = Interface::exibirSubcategoriaFuncionarios();
    switch(valor){
    case 1:
        Execucao::telaAdicionarFuncionario();
        break;
    case 2:
        Execucao::telaConferirFuncionarios();
        break;
    case 3:
        Execucao::telaModificarFuncionarios();
        break;
    case 4:
        Execucao::telaInicial();
        break;
    }
};

void Execucao::telaAdicionarFuncionario(){

};

void Execucao::telaConferirFuncionarios(){

};

void Execucao::telaModificarFuncionarios(){
    int valor;
    valor = Interface::subcategoriaModificarFuncionarios();
    switch(valor){
    case 1:
        Execucao::telaAlterarFuncionario();
        break;
    case 2:
        Execucao::telaDeletarFuncionario();
        break;
    case 3:
        Execucao::telaInicial();
        break;
    }
};

void Execucao::telaAlterarFuncionario() {

}

void Execucao::telaDeletarFuncionario() {

}

void Execucao::telaManutencao(){
    int valor;
    valor = Interface::exibirSubcategoriaManutencao();
    switch(valor){
    case 1:
        Execucao::telaAdicionarManutencao();
        break;
    case 2:
        Execucao::telaConferirManutencoes();
        break;
    case 3:
        Execucao::telaModificarManutencao();
        break;
    case 4:
        Execucao::telaInicial();
        break;
    }
};

void Execucao::telaAdicionarManutencao() {

}

void Execucao::telaConferirManutencoes() {

}

void Execucao::telaModificarManutencao() {
    int valor;
    valor = Interface::subcategoriaModificarManutencao();
    switch(valor){
    case 1:
        Execucao::telaAlterarManutencao();
        break;
    case 2:
        Execucao::telaDeletarManutencao();
        break;
    case 3:
        Execucao::telaInicial();
        break;
    }
}

void Execucao::telaAlterarManutencao() {

}

void Execucao::telaDeletarManutencao() {
    
}