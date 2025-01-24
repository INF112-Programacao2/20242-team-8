#include <iostream>
#include "Interface.h"

class Execucao{

    private:



    public:

        void telaInicial();
        
        //-------------------------------
        void telaProduto();
        
        void telaAdicionarProduto();
        void telaAdicionarNovoProduto();
        void telaAdicionarProdutoExistente();
        void telaConferirEstoque();
        void telaRemoverProduto();
        void telaAlterarDadosProduto();

        //--------------------------------
        void telaVeiculo();
        void telaAdicionarVeiculo();
        void telaConferirVeiculosCadastrados();
        void telaModificarVeiculos();
        void telaAlterarVeiculos();
        void telaExcluirVeiculo();

        //--------------------------------
        void telaFuncionario();
        void telaAdicionarFuncionario();
        void telaConferirFuncionarios();
        void telaModificarFuncionarios();
        void telaAlterarFuncionario();
        void telaDeletarFuncionario();
        
        //-------------------------------
        void telaManutencao();
        void telaAdicionarManutencao();
        void telaConferirManutencoes();
        void telaModificarManutencao();
        void telaAlterarManutencao();
        void telaDeletarManutencao();
        

};