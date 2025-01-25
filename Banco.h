//
// Created by viniciuskl on 23/01/25.
//

#ifndef BANCO_H
#define BANCO_H



    class Banco {
    public:
        static void adicionarProdutoExistente();
        static void adicionarProdutoNovo();
        static void conferirEstoque();
        static void removerProduto();
        static void alterarDadosProduto(); //modificar quantidade

        static void adicionarVeiculo();
        static void conferirVeiculoCadastrado();
        static void removerVeiculo();
        static void modificarDadosVeiculo();

        static void adicionarFuncionario();
        static void conferirFuncionarioCadastrado();
        static void removerFuncionario();
        static void alterarFuncionario();

        static void adicionarManutencao();
        static void conferirManutencao();
        static void removerRegistroManutencao();
        static void alterarManutencao();
    };



#endif //BANCO_H
