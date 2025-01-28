#include "../include/Execucao.h"
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
    Execucao::telaInicial();
};

void Execucao::telaAdicionarProdutoExistente(){
    Banco::adicionarProdutoExistente();
    Execucao::telaInicial();

};

void Execucao::telaConferirEstoque(){
    Banco::conferirEstoque();
    Execucao::telaInicial();

};

void Execucao::telaRemoverProduto(){
    Banco::removerProduto();
    Execucao::telaInicial();

};

void Execucao::telaAlterarDadosProduto(){
    Banco::alterarDadosProduto();
    Execucao::telaInicial();

};

//-------------------------------------------------

void Execucao::telaVeiculo(){
    int valor;
    valor = Interface::exibirSubcategoriaVeiculos();
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
    Execucao::telaInicial();

};

void Execucao::telaConferirVeiculosCadastrados(){
    Banco::conferirVeiculoCadastrado();
    Execucao::telaInicial();
};

void Execucao::telaModificarVeiculos(){
int valor;
    valor = Interface::subcategoriaModificarVeiculo();
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
    Execucao::telaInicial();

};

void Execucao::telaExcluirVeiculo(){
    Banco::removerVeiculo();
    Execucao::telaInicial();
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
    Execucao::telaInicial();

};

void Execucao::telaConferirFuncionarios(){
    Banco::conferirFuncionarioCadastrado();
    Execucao::telaInicial();
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
    Execucao::telaInicial();
};

void Execucao::telaDeletarFuncionario(){
    Banco::removerFuncionario();
    Execucao::telaInicial();
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
    Execucao::telaInicial();
};

void Execucao::telaConferirManutencoes() {
    Banco::conferirManutencao();
    Execucao::telaInicial();
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
    Execucao::telaInicial();
};

void Execucao::telaDeletarManutencao() {
    Banco::removerRegistroManutencao();
    Execucao::telaInicial();
};