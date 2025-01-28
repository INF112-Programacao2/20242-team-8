#include "Execucao.h"
#include <iostream>
#include "../include/Banco.h"

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
    Banco::adicionarProdutoNovo();
};

void Execucao::telaAdicionarProdutoExistente(){
    Banco::adicionarProdutoExistente();
};

void Execucao::telaConferirEstoque(){
    Banco::conferirEstoque();
};

void Execucao::telaRemoverProduto(){
    Banco::removerProduto();
};

void Execucao::telaAlterarDadosProduto(){
    Banco::alterarDadosProduto();
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
    Banco::adicionarVeiculo();
};

void Execucao::telaConferirVeiculosCadastrados(){
    Banco::conferirVeiculoCadastrado();
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
    Banco::modificarDadosVeiculo();
};

void Execucao::telaExcluirVeiculo(){
    Banco::removerVeiculo();
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
    Banco::adicionarFuncionario();
};

void Execucao::telaConferirFuncionarios(){
    Banco::conferirFuncionarioCadastrado();
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
    Banco::alterarFuncionario();
};

void Execucao::telaDeletarFuncionario(){
    Banco::removerFuncionario();
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
    Banco::adicionarManutencao();
};

void Execucao::telaConferirManutencoes() {
    Banco::conferirManutencao();
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
    Banco::alterarManutencao();
};

void Execucao::telaDeletarManutencao() {
    Banco::removerRegistroManutencao();
};