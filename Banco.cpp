//
// Created by viniciuskl on 23/01/25.
//
#include <iostream>
#include "Banco.h"

#include "DatabaseConnection.h"
#include "Produto.h"

DatabaseConnection db("DATABASE.sqlite");

bool conectaBD() {
    // Tenta estabelecer conexão com o banco
    if (!db.connect()) {
        return false;
    }
    return true;
}

void Banco::adicionarProdutoNovo() {
    if (conectaBD()) {
        std::string nomeProduto, nomeMarcaProduto, numeroProduto;
        int quantidadeProduto;


        std::cout << "Insira os seguintes dados: \n";
        std::cout << "Insira o nome do produto: ";
        std::getline(std::cin, nomeProduto);

        std::string tipoProduto = Produto::defineTipo();

        std::cout << "Insira a quantidade do produto: ";
        std::cin >> quantidadeProduto;

        std::cin.ignore();
        std::cout << "Insira o nome da marca referente aos veículos compatíveis com o produto: ";
        std::getline(std::cin, nomeMarcaProduto);

        std::cout << "Insira o número do produto: ";
        std::getline(std::cin, numeroProduto);

        // Se o banco foi conectado, tenta inserir dados
        Produto p(nomeProduto, quantidadeProduto, nomeMarcaProduto, numeroProduto);

        //registramos, inicialmente, uma marca
        std::string criaMarca = "INSERT OR IGNORE INTO MARCA (IDMARCA, nome) VALUES (NULL, '" + nomeMarcaProduto + "');";
        if (!db.executeQuery(criaMarca)) {
            std::cerr << "Falha ao Registrar a Marca!" << std::endl;
            return;
        }
        //guardamos o id referente a ela
        std::string idMarca;
        std::string selectQuery = "SELECT IDMARCA FROM MARCA WHERE nome = '" + nomeMarcaProduto + "'";
        db.getFirstColumnValue(selectQuery, idMarca);

        //EXECUTA O INSERT
        std::string insertDataTipoProduto = "INSERT INTO TIPOPRODUTO (IDTIPOPRODUTO, nome, tipo) VALUES (NULL, '" + nomeProduto + "', '" + tipoProduto + "');";

        // Executa a consulta INSERT e verifica seu resultado
        if (!db.executeQuery(insertDataTipoProduto)) {
            std::cerr << "Falha ao inserir dados do produto!" << std::endl;
            return;
        }
        //guardamos o id referente a ela
        std::string idTipoProduto;
        std::string selectQueryTipoProduto = "SELECT IDTIPOPRODUTO FROM TIPOPRODUTO WHERE nome = '" + nomeProduto + "'";
        db.getFirstColumnValue(selectQueryTipoProduto, idTipoProduto);
        //FIM DE EXECUTA INSERT
        std::string insertProduto = "INSERT INTO PRODUTO (IDPRODUTO, quantidade, numero, ID_MARCA, ID_TIPOPRODUTO) VALUES (NULL, " + std::to_string(quantidadeProduto) + ", '" + numeroProduto + "', " + (idMarca) + ", " + (idTipoProduto) + ");";
        if (!db.executeSelectQuery(insertProduto)) {
            std::cerr << "Falha ao inserir produto!" << std::endl;
        }

        // executa a querry SELECT
        std::string select = "SELECT * from PRODUTO inner join MARCA M on M.IDMARCA = PRODUTO.ID_MARCA inner join TIPOPRODUTO T on T.IDTIPOPRODUTO = PRODUTO.ID_TIPOPRODUTO;";
        if (!db.executeSelectQuery(select)) {
            std::cerr << "Falha ao executar consulta SELECT!" << std::endl;
        }

        std::cout.flush(); // Certifica que a saída seja exibida
        //FIM DO EXECUTA A QUERRY SELECT

    }
    else {
        std::cerr << "Falha ao conectar ao banco de dados!" << std::endl;
        exit(1);
    }
}

void Banco::adicionarProdutoExistente() {
    if (conectaBD()) {
        //CHAMA UM SELECT GERAL
        std::string select = "select PRODUTO.IDPRODUTO as ID, TIPOPRODUTO.nome as Nome_Do_Produto ,MARCA.nome as Nome_Da_Marca, PRODUTO.quantidade as Quantidade_Disponivel, PRODUTO.numero as Numero_Do_Produto from MARCA inner join PRODUTO on MARCA.IDMARCA = PRODUTO.ID_MARCA inner join TIPOPRODUTO on PRODUTO.ID_TIPOPRODUTO = TIPOPRODUTO.IDTIPOPRODUTO;";
        if (!db.executeSelectQuery(select)) {
            std::cerr << "Falha ao executar consulta SELECT!" << std::endl;
        }
        std::cout.flush();
        //

        std::string idProduto;
        std::cout << "Qual o ID do produto a ser alterado? \n";
        std::cout << "-> ";
        std::cin >> idProduto;

        std::string quantidade;
        std::cout << "Qual a quantidade a ser adicionada? \n";
        std::cout << "-> ";
        std::cin >> quantidade;

        std::string qtd;
        std::string selectQueryTipoProduto = "SELECT quantidade FROM PRODUTO WHERE IDPRODUTO = '" + idProduto + "'";
        db.getFirstColumnValue(selectQueryTipoProduto, qtd);

        int novaQuantidade = stoi(quantidade) + stoi(qtd);
        std::string novaQTD = std::to_string(novaQuantidade);

        std::string atualizaQuant= "update PRODUTO set quantidade = " + novaQTD +  " where IDPRODUTO=" + idProduto + ";";
        if (!db.executeQuery(atualizaQuant)) {
            std::cerr << "Falha ao inserir dados do produto!" << std::endl;
            return;
        }
        std::cout << std::endl;
        std::cout << "Novos Dados após a alteraçao: \n";
        std::string select2 = "select PRODUTO.IDPRODUTO as ID, TIPOPRODUTO.nome as Nome_Do_Produto ,MARCA.nome as Nome_Da_Marca, PRODUTO.quantidade as Quantidade_Disponivel, PRODUTO.numero as Numero_Do_Produto from MARCA inner join PRODUTO on MARCA.IDMARCA = PRODUTO.ID_MARCA inner join TIPOPRODUTO on PRODUTO.ID_TIPOPRODUTO = TIPOPRODUTO.IDTIPOPRODUTO where IDPRODUTO = " + idProduto + ";";
        if (!db.executeSelectQuery(select2)) {
            std::cerr << "Falha ao executar consulta SELECT!" << std::endl;
        }
    }
    else {
        std::cerr << "Falha ao conectar ao banco de dados!" << std::endl;
        exit(1);
    }
}



