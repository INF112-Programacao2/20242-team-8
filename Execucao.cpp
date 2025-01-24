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

//-----------------------------------------------

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
        Execucao::telaRemoverProduto();
        break;
    case 4:
        Execucao::telaAlterarDadosProduto();
        break;
    case 5:
        Execucao::telaInicial();
        break;
    }
};

void Execucao::telaAdicionarProduto(){
    int valor; 
    valor = Interface::subcategoriaAdicionarProduto();
    switch(valor){
    case 1:
        Execucao::telaAdicionarNovoProduto();
        break;
    case 2:
        Execucao::telaAdicionarProdutoExistente();
        break;
    case 3:
        Execucao::telaProduto();
        break;
    }
}

void Execucao::telaAdicionarNovoProduto(){

};

void Execucao::telaAdicionarProdutoExistente(){

};

void Execucao::telaConferirEstoque(){

};

void Execucao::telaRemoverProduto(){

};

void Execucao::telaAlterarDadosProduto(){

};

//-------------------------------------------------

void Execucao::telaVeiculo(){
    int valor;
    valor = Interface::exibirSubcategoriaProduto();
    switch(valor){
    case 1:
        Execucao::telaAdicionarVeiculo();
        break;
    case 2:
        Execucao::telaConferirVeiculosCadastrados();
        break;
    case 3:
        Execucao::telaModificarVeiculos();
        break;
    case 4:
        Execucao::telaInicial();
        break;
    }
};

void Execucao::telaAdicionarVeiculo(){

};

void Execucao::telaConferirVeiculosCadastrados(){

};

void Execucao::telaModificarVeiculos(){
int valor;
    valor = Interface::exibirSubcategoriaProduto();
    switch(valor){
    case 1:
        Execucao::telaAlterarVeiculos();
        break;
    case 2:
        Execucao::telaExcluirVeiculo();
        break;
    case 3:
        Execucao::telaVeiculo();
        break;
    }
};

void Execucao::telaAlterarVeiculos(){

};

void Execucao::telaExcluirVeiculo(){

};

//-------------------------------------------------

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

void Execucao::telaAlterarFuncionario(){

};

void Execucao::telaDeletarFuncionario(){

};

//-----------------------------------------------

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

};

void Execucao::telaConferirManutencoes() {

};

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
};

void Execucao::telaAlterarManutencao() {

};

void Execucao::telaDeletarManutencao() {

};