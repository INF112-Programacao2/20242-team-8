#include <iostream>
#include "Interface.h"
#include "Banco.h"

#ifndef EXECUCAO_H
#define EXECUCAO_H

class Execucao{

    private:



    public:

        static void telaInicial();
        
        //-------------------------------
        static void telaProduto();
        
        static void telaAdicionarProduto();
        static void telaAdicionarNovoProduto();
        static void telaAdicionarProdutoExistente();
        static void telaConferirEstoque();
        static void telaRemoverProduto();
        static void telaAlterarDadosProduto();

        //--------------------------------
        static void telaVeiculo();
        static void telaAdicionarVeiculo();
        static void telaConferirVeiculosCadastrados();
        static void telaModificarVeiculos();
        static void telaAlterarVeiculos();
        static void telaExcluirVeiculo();

        //--------------------------------
        static void telaFuncionario();
        static void telaAdicionarFuncionario();
        static void telaConferirFuncionarios();
        static void telaModificarFuncionarios();
        static void telaAlterarFuncionario();
        static void telaDeletarFuncionario();
        
        //-------------------------------
        static void telaManutencao();
        static void telaAdicionarManutencao();
        static void telaConferirManutencoes();
        static void telaModificarManutencao();
        static void telaAlterarManutencao();
        static void telaDeletarManutencao();
        

};

#endif //EXECUCAO_H