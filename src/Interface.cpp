//
// Created by viniciuskl on 22/01/25.
//

#include "../include/Interface.h"
#include <exception>
#include <iostream>
#include <limits>

int Interface::exibirMenuPrincipal(){
    std::cout << "---BEM VINDO---" << std::endl;
    std::cout << std::endl;
    std::cout << "SELECIONE A CATEGORIA: " << std::endl;
    std::cout << std::endl;
    std::cout << "1- PRODUTOS " << std::endl;
    std::cout << "2- VEICULOS " << std::endl;
    std::cout << "3- FUNCIONARIOS "<< std::endl;
    std::cout << "4- MANUTENCAO " << std::endl;
    std::cout << "5- SAIR " << std::endl;
    std::cout << "-> ";

    int valor;
    bool testeVariavel = false;
    do{
        testeVariavel = false;
        try{
        std::cin >> valor;
            if (std::cin.fail()) {
                std::cin.clear(); // Limpa o estado de erro de `cin`
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta o restante da entrada
                throw std::invalid_argument("Entrada inválida! Digite um número inteiro.\n");
            }
            if(valor <=0 || valor > 5){
                throw std::invalid_argument("Opcao invalida!\n");
            }
        }
        catch(std::exception &e){
            std::cout << e.what();
            std::cout << "Selecione uma opcao valida: ";
            testeVariavel = true;
        }
    }while(testeVariavel);

    return valor;
}

int Interface::exibirSubcategoriaProduto(){
    std::cout << "PRODUTOS" << std::endl;
    std::cout << std::endl;
    std::cout << "1- ADICIONAR PRODUTO " << std::endl;
    std::cout << "2- CONFERIR ESTOQUE " << std::endl;
    std::cout << "3- REMOVER PRODUTO "<< std::endl;
    std::cout << "4- ALTERAR DADOS " << std::endl;
    std::cout << "5- SAIR " << std::endl;
    std::cout << "-> ";

    
    int valor;
    bool testeVariavel = false;
    do{ 
        testeVariavel = false;
        try{
        std::cin >> valor;
            if (std::cin.fail()) {
                std::cin.clear(); // Limpa o estado de erro de `cin`
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta o restante da entrada
                throw std::invalid_argument("Entrada inválida! Digite um número inteiro.\n");
            }
            if(valor <=0 || valor > 5){
                throw std::invalid_argument("Opcao invalida!\n");
            }
        }
        catch(std::exception &e){
            std::cout << e.what();
            std::cout << "Selecione uma opcao valida: ";
            testeVariavel = true;
        }
    }while(testeVariavel);

    return valor;
}

int Interface::exibirSubcategoriaVeiculos(){
    std::cout << "VEICULOS" << std::endl;
    std::cout << std::endl;
    std::cout << "1- ADICIONAR VEICULO " << std::endl;
    std::cout << "2- CONFERIR VEICULOS CADASTRADOS " << std::endl;
    std::cout << "3- MODIFICAR VEICULO "<< std::endl;
    std::cout << "4- SAIR " << std::endl;
    std::cout << "-> ";

    
    int valor;
    bool testeVariavel = false;
    do{ 
        testeVariavel = false;
        try{
        std::cin >> valor;
            if (std::cin.fail()) {
                std::cin.clear(); // Limpa o estado de erro de `cin`
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta o restante da entrada
                throw std::invalid_argument("Entrada inválida! Digite um número inteiro.\n");
            }
            if(valor <=0 || valor > 4){
                throw std::invalid_argument("Opcao invalida!\n");
            }
        }
        catch(std::exception &e){
            std::cout << e.what();
            std::cout << "Selecione uma opcao valida: ";
            testeVariavel = true;
        }
    }while(testeVariavel);

    return valor;
}

int Interface::exibirSubcategoriaFuncionarios(){
    std::cout << "FUNCIONARIOS" << std::endl;
    std::cout << std::endl;
    std::cout << "1- ADICIONAR FUNCIONARIO " << std::endl;
    std::cout << "2- CONFERIR FUNCIONARIOS CADASTRADOS " << std::endl;
    std::cout << "3- MODIFICAR FUNCIONARIO "<< std::endl;
    std::cout << "4- SAIR " << std::endl;
    std::cout << "-> ";

    
    int valor;
    bool testeVariavel = false;
    do{ 
        testeVariavel = false;
        try{
        std::cin >> valor;
            if (std::cin.fail()) {
                std::cin.clear(); // Limpa o estado de erro de `cin`
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta o restante da entrada
                throw std::invalid_argument("Entrada inválida! Digite um número inteiro.\n");
            }
            if(valor <=0 || valor > 4){
                throw std::invalid_argument("Opcao invalida!\n");
            }
        }
        catch(std::exception &e){
            std::cout << e.what();
            std::cout << "Selecione uma opcao valida: ";
            testeVariavel = true;
        }
    }while(testeVariavel);

    return valor;
}

int Interface::exibirSubcategoriaManutencao(){
    std::cout << "MANUTENCOES" << std::endl;
    std::cout << std::endl;
    std::cout << "1- ADICIONAR MANUTENCAO " << std::endl;
    std::cout << "2- CONFERIR MANUTENCOES " << std::endl;
    std::cout << "3- MODIFICAR MANUTENCAO "<< std::endl;
    std::cout << "4- SAIR " << std::endl;
    std::cout << "-> ";

    
    int valor;
    bool testeVariavel = false;
    do{ 
        testeVariavel = false;
        try{
        std::cin >> valor;
            if (std::cin.fail()) {
                std::cin.clear(); // Limpa o estado de erro de `cin`
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta o restante da entrada
                throw std::invalid_argument("Entrada inválida! Digite um número inteiro.\n");
            }
            if(valor <=0 || valor > 4){
                throw std::invalid_argument("Opcao invalida!\n");
            }
        }
        catch(std::exception &e){
            std::cout << e.what();
            std::cout << "Selecione uma opcao valida: ";
            testeVariavel = true;
        }
    }while(testeVariavel);

    return valor;
}

int Interface::subcategoriaAdicionarProduto(){
    std::cout << "ADICIONAR PRODUTOS: " << std::endl;
    std::cout << std::endl;
    std::cout << "1- ADICIONAR NOVO PRODUTO " << std::endl;
    std::cout << "2- ADICIONAR PRODUTO EXISTENTE " << std::endl;
    std::cout << "3- SAIR "<< std::endl;
    std::cout << "-> ";

    
    int valor;
    bool testeVariavel = false;
    do{
        testeVariavel = false;
        try{
        std::cin >> valor;
            if (std::cin.fail()) {
                std::cin.clear(); // Limpa o estado de erro de `cin`
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta o restante da entrada
                throw std::invalid_argument("Entrada inválida! Digite um número inteiro.\n");
            }
            if(valor <=0 || valor > 3){
                throw std::invalid_argument("Opcao invalida!\n");
            }
        }
        catch(std::exception &e){
            std::cout << e.what();
            std::cout << "Selecione uma opcao valida: ";
            testeVariavel = true;
        }
    }while(testeVariavel);

    return valor;
}

int Interface::subcategoriaModificarVeiculo(){
    std::cout << "MODIFICAR VEICULOS: " << std::endl;
    std::cout << std::endl;
    std::cout << "1- ALTERAR VEICULO " << std::endl;
    std::cout << "2- DELETAR VEICULO " << std::endl;
    std::cout << "3- SAIR "<< std::endl;
    std::cout << "-> ";

    
    int valor;
    bool testeVariavel = false;
    do{ 
        testeVariavel = false;
        try{
        std::cin >> valor;
            if (std::cin.fail()) {
                std::cin.clear(); // Limpa o estado de erro de `cin`
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta o restante da entrada
                throw std::invalid_argument("Entrada inválida! Digite um número inteiro.\n");
            }
            if(valor <=0 || valor > 3){
                throw std::invalid_argument("Opcao invalida!\n");
            }
        }
        catch(std::exception &e){
            std::cout << e.what();
            std::cout << "Selecione uma opcao valida: ";
            testeVariavel = true;
        }
    }while(testeVariavel);

    return valor;
}

int Interface::subcategoriaModificarFuncionarios(){
    std::cout << "MODIFICAR FUNCIONARIOS: " << std::endl;
    std::cout << std::endl;
    std::cout << "1- ALTERAR FUNCIONARIO " << std::endl;
    std::cout << "2- DELETAR FUNCIONARIO " << std::endl;
    std::cout << "3- SAIR "<< std::endl;
    std::cout << "-> ";

    
    int valor;
    bool testeVariavel = false;
    do{ 
        testeVariavel = false;
        try{
        std::cin >> valor;
            if (std::cin.fail()) {
                std::cin.clear(); // Limpa o estado de erro de `cin`
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta o restante da entrada
                throw std::invalid_argument("Entrada inválida! Digite um número inteiro.\n");
            }
            if(valor <=0 || valor > 3){
                throw std::invalid_argument("Opcao invalida!\n");
            }
        }
        catch(std::exception &e){
            std::cout << e.what();
            std::cout << "Selecione uma opcao valida: ";
            testeVariavel = true;
        }
    }while(testeVariavel);

    return valor;
}

int Interface::subcategoriaModificarManutencao(){
    std::cout << "MODIFICAR MANUTENCOES: " << std::endl;
    std::cout << std::endl;
    std::cout << "1- ALTERAR MANUTENCAO " << std::endl;
    std::cout << "2- DELETAR MANUTENCAO " << std::endl;
    std::cout << "3- SAIR "<< std::endl;
    std::cout << "-> ";

    
    int valor;
    bool testeVariavel = false;
    do{ 
        testeVariavel = false;
        try{
        std::cin >> valor;
            if (std::cin.fail()) {
                std::cin.clear(); // Limpa o estado de erro de `cin`
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta o restante da entrada
                throw std::invalid_argument("Entrada inválida! Digite um número inteiro.\n");
            }
            if(valor <=0 || valor > 3){
                throw std::invalid_argument("Opcao invalida!\n");
            }
        }
        catch(std::exception &e){
            std::cout << e.what();
            std::cout << "Selecione uma opcao valida: ";
            testeVariavel = true;
        }
    }while(testeVariavel);

    return valor;
}