//
// Created by viniciuskl on 23/01/25.
//
#include <iostream>
#include "Banco.h"

#include "Carro.h"
#include "DatabaseConnection.h"
#include "Produto.h"
#include "Acessibilidade.h"

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
        std::string nomeProduto, nomeMarcaProduto, numeroProduto, dataCompra, localCompra;
        int quantidadeProduto;
        std::string texto1 = "Insira os seguintes dados: \n";
        std::string texto2 = "Insira o nome do produto: ";
        Acessibilidade::colocaTexto(texto1);
        Acessibilidade::colocaTexto(texto2);
        std::cin.ignore();
        std::getline(std::cin, nomeProduto);

        std::string texto = "Insira o tipo do produto: \n";
        Acessibilidade::colocaTexto(texto);
        std::string tipoProduto = Produto::defineTipo();

        std::string texto3 = "Insira a quantidade do produto: ";
        Acessibilidade::colocaTexto(texto3);
        std::cin >> quantidadeProduto;

        std::cin.ignore();
        std::string texto4 = "Insira o nome da marca referente aos veículos compatíveis com o produto: ";
        Acessibilidade::colocaTexto(texto4);
        std::getline(std::cin, nomeMarcaProduto);

        std::string texto5 = "Insira o número do produto: ";
        Acessibilidade::colocaTexto(texto5);
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

        std::string texto6 = "Insira a data da compra (formato: DD/MM/AA) : ";
        Acessibilidade::colocaTexto(texto6);
        std::getline(std::cin, dataCompra);

        std::string texto7 = "Insira o local da compra: ";
        Acessibilidade::colocaTexto(texto7);
        std::getline(std::cin, localCompra);

        std::string idProduto;
        std::string selectQueryProduto = "SELECT IDPRODUTO FROM PRODUTO WHERE ID_TIPOPRODUTO = '" + idTipoProduto + "'";
        db.getFirstColumnValue(selectQueryProduto, idProduto);

        std::string insertRegistro = "insert into REGISTRO (IDREGISTRO, dataCompra, localCompra, quantidadeComprada, ID_PRODUTO) values (NULL, '" + dataCompra + "', '" + localCompra + "', " + std::to_string(quantidadeProduto) + ", " + idProduto + ");";
        if (!db.executeQuery(insertRegistro)) {
            std::cerr << "Falha ao inserir dados do registro!" << std::endl;
            return;
        }

        // executa a querry SELECT
        std::string select = "SELECT PRODUTO.IDPRODUTO as ID_PRODUTO, TIPOPRODUTO.nome as NOME_TIPO_PRODUTO, MARCA.nome as NOME_MARCA, TIPOPRODUTO.tipo as TIPO, PRODUTO.numero as NUMERO_PRODUTO, PRODUTO.quantidade as QUANTIDADE_PRODUTO, REGISTRO.dataCompra as DATA_DE_COMPRA, REGISTRO.localCompra as LOCAL_DE_COMPRA from PRODUTO inner join main.MARCA on MARCA.IDMARCA = PRODUTO.ID_MARCA inner join main.REGISTRO on PRODUTO.IDPRODUTO = REGISTRO.ID_PRODUTO inner join main.TIPOPRODUTO on TIPOPRODUTO.IDTIPOPRODUTO = PRODUTO.ID_TIPOPRODUTO;";
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
        std::string select = "SELECT PRODUTO.IDPRODUTO as ID_PRODUTO, TIPOPRODUTO.nome as NOME_TIPO_PRODUTO, MARCA.nome as NOME_MARCA, TIPOPRODUTO.tipo as TIPO, PRODUTO.numero as NUMERO_PRODUTO, PRODUTO.quantidade as QUANTIDADE_PRODUTO, REGISTRO.dataCompra as DATA_DE_COMPRA, REGISTRO.localCompra as LOCAL_DE_COMPRA from PRODUTO inner join main.MARCA on MARCA.IDMARCA = PRODUTO.ID_MARCA inner join main.REGISTRO on PRODUTO.IDPRODUTO = REGISTRO.ID_PRODUTO inner join main.TIPOPRODUTO on TIPOPRODUTO.IDTIPOPRODUTO = PRODUTO.ID_TIPOPRODUTO;";
        if (!db.executeSelectQuery(select)) {
            std::cerr << "Falha ao executar consulta SELECT!" << std::endl;
        }
        std::cout.flush();
        //

        std::string idProduto;
        std::string texto = "Qual o ID do produto a ser alterado?";
        Acessibilidade::colocaTexto(texto);
        std::cout << "Qual o ID do produto a ser alterado? \n";
        std::cout << "-> ";
        std::cin >> idProduto;

        std::string quantidade;
        std::string texto1 = "Qual a quantidade a ser adicionada?";
        Acessibilidade::colocaTexto(texto1);
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
        std::string texto2 = "Qual a quantidade a ser adicionada?";
        Acessibilidade::colocaTexto(texto2);
        std::cout << "Novos Dados após a alteraçao: \n";
        std::string texto3 = "Novos Dados após a alteraçao:";
        Acessibilidade::colocaTexto(texto3);
        std::string select2 = "SELECT PRODUTO.IDPRODUTO as ID_PRODUTO, TIPOPRODUTO.nome as NOME_TIPO_PRODUTO, MARCA.nome as NOME_MARCA, TIPOPRODUTO.tipo as TIPO, PRODUTO.numero as NUMERO_PRODUTO, PRODUTO.quantidade as QUANTIDADE_PRODUTO, REGISTRO.dataCompra as DATA_DE_COMPRA, REGISTRO.localCompra as LOCAL_DE_COMPRA from PRODUTO inner join main.MARCA on MARCA.IDMARCA = PRODUTO.ID_MARCA inner join main.REGISTRO on PRODUTO.IDPRODUTO = REGISTRO.ID_PRODUTO inner join main.TIPOPRODUTO on TIPOPRODUTO.IDTIPOPRODUTO = PRODUTO.ID_TIPOPRODUTO where IDPRODUTO = " + idProduto + ";";
        if (!db.executeSelectQuery(select2)) {
            std::cerr << "Falha ao executar consulta SELECT!" << std::endl;
        }
    }
    else {
        std::cerr << "Falha ao conectar ao banco de dados!" << std::endl;
        exit(1);
    }
}

void Banco::conferirEstoque(){

    if (conectaBD()) {

        //chama select para mostrar todos os produtos
        std::string select = "SELECT PRODUTO.IDPRODUTO as ID_PRODUTO, TIPOPRODUTO.nome as NOME_TIPO_PRODUTO, MARCA.nome as NOME_MARCA, TIPOPRODUTO.tipo as TIPO, PRODUTO.numero as NUMERO_PRODUTO, PRODUTO.quantidade as QUANTIDADE_PRODUTO, REGISTRO.dataCompra as DATA_DE_COMPRA, REGISTRO.localCompra as LOCAL_DE_COMPRA from PRODUTO inner join main.MARCA on MARCA.IDMARCA = PRODUTO.ID_MARCA inner join main.REGISTRO on PRODUTO.IDPRODUTO = REGISTRO.ID_PRODUTO inner join main.TIPOPRODUTO on TIPOPRODUTO.IDTIPOPRODUTO = PRODUTO.ID_TIPOPRODUTO;";
        if(!db.executeSelectQuery(select)) {
                std::cerr << "Falha ao executar consulta SELECT!" << std::endl;
        }
        std::cout.flush();

    }
    else {
        std::cerr << "Falha ao conectar ao banco de dados!" << std::endl;
        exit(1);
    }

}

void Banco::removerProduto() {
    if (conectaBD()) {
        std::string select = "SELECT PRODUTO.IDPRODUTO as ID_PRODUTO, TIPOPRODUTO.nome as NOME_TIPO_PRODUTO, MARCA.nome as NOME_MARCA, TIPOPRODUTO.tipo as TIPO, PRODUTO.numero as NUMERO_PRODUTO, PRODUTO.quantidade as QUANTIDADE_PRODUTO, REGISTRO.dataCompra as DATA_DE_COMPRA, REGISTRO.localCompra as LOCAL_DE_COMPRA from PRODUTO inner join main.MARCA on MARCA.IDMARCA = PRODUTO.ID_MARCA inner join main.REGISTRO on PRODUTO.IDPRODUTO = REGISTRO.ID_PRODUTO inner join main.TIPOPRODUTO on TIPOPRODUTO.IDTIPOPRODUTO = PRODUTO.ID_TIPOPRODUTO;";
        if(!db.executeSelectQuery(select)) {
            std::cerr << "Falha ao executar consulta SELECT!" << std::endl;
        }
        std::string productID, ID_TIPOPRODUTO;
        std::cout.flush();
        std::cout << std::endl;
        std::cout << "DIGITE O NUMERO DO ID DO PRODUTO A SER REMOVIDO: " << std::endl;
        std::string texto = "DIGITE O NUMERO DO ID DO PRODUTO A SER REMOVIDO:";
        Acessibilidade::colocaTexto(texto);
        std::cout << "-> ";
        std::cin >> productID;
        std::string querryID_TIPOPRODUTO = "select PRODUTO.ID_TIPOPRODUTO from PRODUTO where IDPRODUTO = " + productID + ";";
        db.getFirstColumnValue(querryID_TIPOPRODUTO, ID_TIPOPRODUTO);
        std::string remove1 = "DELETE FROM PRODUTO WHERE IDPRODUTO = " + productID + ";";
        std::string remove2 = "DELETE FROM TIPOPRODUTO WHERE IDTIPOPRODUTO = " + ID_TIPOPRODUTO + ";";
        std::string remove3 = "DELETE FROM REGISTRO WHERE ID_PRODUTO = " + productID + ";";
        if(!db.executeSelectQuery(remove1) && !db.executeSelectQuery(remove2) && !db.executeSelectQuery(remove3)) {
            std::cerr << "Falha ao executar consulta SELECT!" << std::endl;
        }
        else {
            std::cout << std::endl;
            std::cout << "Produto removido com sucesso!\n";
        }
    }
    else {
        std::cerr << "Falha ao conectar ao banco de dados!" << std::endl;
        exit(1);
    }
}

void Banco::alterarDadosProduto() {
    if (conectaBD()) {
        std::string select = "SELECT PRODUTO.IDPRODUTO as ID_PRODUTO, TIPOPRODUTO.nome as NOME_TIPO_PRODUTO, MARCA.nome as NOME_MARCA, TIPOPRODUTO.tipo as TIPO, PRODUTO.numero as NUMERO_PRODUTO, PRODUTO.quantidade as QUANTIDADE_PRODUTO, REGISTRO.dataCompra as DATA_DE_COMPRA, REGISTRO.localCompra as LOCAL_DE_COMPRA from PRODUTO inner join main.MARCA on MARCA.IDMARCA = PRODUTO.ID_MARCA inner join main.REGISTRO on PRODUTO.IDPRODUTO = REGISTRO.ID_PRODUTO inner join main.TIPOPRODUTO on TIPOPRODUTO.IDTIPOPRODUTO = PRODUTO.ID_TIPOPRODUTO;";
        if(!db.executeSelectQuery(select)) {
            std::cerr << "Falha ao executar consulta SELECT!" << std::endl;
        }
        std::string idProduto;
        std::cout << std::endl;
        std::string texto = "Qual o ID do produto que deseja alterar?";
        std::cout << "Qual o ID do produto que deseja alterar? \n";
        std::cout << "-> ";
        std::cin >> idProduto;
        std::cout << "PRODUTO SELCIONADO: \n";
        std::string select1 = "SELECT PRODUTO.IDPRODUTO as ID_PRODUTO, TIPOPRODUTO.nome as NOME_TIPO_PRODUTO, MARCA.nome as NOME_MARCA, TIPOPRODUTO.tipo as TIPO, PRODUTO.numero as NUMERO_PRODUTO, PRODUTO.quantidade as QUANTIDADE_PRODUTO, REGISTRO.dataCompra as DATA_DE_COMPRA, REGISTRO.localCompra as LOCAL_DE_COMPRA from PRODUTO inner join main.MARCA on MARCA.IDMARCA = PRODUTO.ID_MARCA inner join main.REGISTRO on PRODUTO.IDPRODUTO = REGISTRO.ID_PRODUTO inner join main.TIPOPRODUTO on TIPOPRODUTO.IDTIPOPRODUTO = PRODUTO.ID_TIPOPRODUTO where IDPRODUTO = " + idProduto + ";";
        if(!db.executeSelectQuery(select1)) {
            std::cerr << "Falha ao executar consulta SELECT!" << std::endl;
        }
        std::cout << std::endl;
        int opcao;
        std::cout << "Qual informação deseja trocar:\n";
        std::cout << "O que deseja alterar? :\n";
        std::cout << "(1) NOME DO PRODUTO\n(2) QUANTIDADE\n(3) NUMERO DO PRODUTO\n(4) TIPO DO PRODUTO\n(5) DATA DE COMPRA\n(6) LOCAL DE COMPRA\n";
        std::cout << "-> ";
        std::cin >> opcao;
        if (opcao==1) {
            std::string ID_TIPOPRODUTO;
            std::string querryID_TIPOPRODUTO = "select PRODUTO.ID_TIPOPRODUTO from PRODUTO where IDPRODUTO = " + idProduto + ";";
            db.getFirstColumnValue(querryID_TIPOPRODUTO, ID_TIPOPRODUTO);
            std::string nomeNovo;
            std::cout << "Digite o novo nome do produto: \n";
            std::cout << "-> ";
            std::cin >> nomeNovo;
            std::string querry = "update TIPOPRODUTO set nome = '" + nomeNovo + "' where IDTIPOPRODUTO = " + ID_TIPOPRODUTO + ";";
            if (!db.executeQuery(querry)) {
                std::cerr << "Falha ao alterar dados do produto!" << std::endl;
                return;
            }
            else {
                std::cout << std::endl;
                std::cout << "Produto alterado com sucesso!\n";
            }
        }
        else if (opcao==2) {
            std::string qtd;
            std::cout << "Digite a nova quantidade: \n";
            std::cout << "-> ";
            std::cin >> qtd;
            std::string querry1 = "update PRODUTO set quantidade = " + qtd + " where IDPRODUTO = " + idProduto + ";";
            if (!db.executeQuery(querry1)) {
                std::cerr << "Falha ao alterar dados do produto!" << std::endl;
                return;
            }
            else {
                std::cout << std::endl;
                std::cout << "Produto alterado com sucesso!\n";
            }
        }
        else if (opcao==3) {
            std::string num;
            std::cout << "Digite o novo numero: \n";
            std::cout << "-> ";
            std::cin >> num;
            std::string querry2 = "update PRODUTO set numero = '" + num + "' where IDPRODUTO = " + idProduto + ";";
            if (!db.executeQuery(querry2)) {
                std::cerr << "Falha ao alterar dados do produto!" << std::endl;
                return;
            }
            else {
                std::cout << std::endl;
                std::cout << "Produto alterado com sucesso!\n";
            }
        }
        else if (opcao==4) {
            std::string ID_TIPOPRODUTO1;
            std::string querryID_TIPOPRODUTO1 = "select PRODUTO.ID_TIPOPRODUTO from PRODUTO where IDPRODUTO = " + idProduto + ";";
            db.getFirstColumnValue(querryID_TIPOPRODUTO1, ID_TIPOPRODUTO1);
            std::string novoTipo;
            std::cout << "Digite o novo tipo do produto: \n";
            std::cout << "(1) PEÇA\n(2) FLUIDO\n";
            int opcao1;
            std::cout << "-> ";
            std::cin >> opcao1;
            if (opcao1 == 1) {
                novoTipo = "'Peça'";
            }
            else if (opcao1 == 2) {
                novoTipo = "'Fluido'";
            }
            std::string querry3 = "update TIPOPRODUTO set tipo = " + novoTipo + " where IDTIPOPRODUTO = " + ID_TIPOPRODUTO1 + ";";
            if (!db.executeQuery(querry3)) {
                std::cerr << "Falha ao alterar dados do produto!" << std::endl;
                return;
            }
            else {
                std::cout << std::endl;
                std::cout << "Produto alterado com sucesso!\n";
            }
        }
        else if (opcao==5) {
            std::cout << "Digite a nova data de compra: \n";
            std::cout << "-> ";
            std::string novaDataCompra;
            std::cin.ignore();
            std::getline(std::cin, novaDataCompra);
            std::string querry4 = "update REGISTRO set dataCompra = '" + novaDataCompra + "' where ID_PRODUTO = " + idProduto + ";";
            if (!db.executeQuery(querry4)) {
                std::cerr << "Falha ao alterar dados do produto!" << std::endl;
                return;
            }
            else {
                std::cout << std::endl;
                std::cout << "data de compra alterada com sucesso!\n";
            }
        }
        else if (opcao==6) {
            std::cout << "Digite o novo local de compra: \n";
            std::cout << "-> ";
            std::string novoLocalCompra;
            std::cin.ignore();
            std::getline(std::cin, novoLocalCompra);
            std::string querry5 = "update REGISTRO set localCompra = '" + novoLocalCompra + "' where ID_PRODUTO = " + idProduto + ";";
            if (!db.executeQuery(querry5)) {
                std::cerr << "Falha ao alterar dados do produto!" << std::endl;
                return;
            }
            else {
                std::cout << std::endl;
                std::cout << "local de compra alterado com sucesso!\n";
            }
        }
    }
    else {
            std::cerr << "Falha ao conectar ao banco de dados!" << std::endl;
            exit(1);
    }
}

void Banco::adicionarFuncionario(){
    if (conectaBD()) {
        std::string nome;

        std::cout << "Insira o nome do funcionario: ";
        std::cin >> nome;

        std::string insert = "INSERT INTO FUNCIONARIO (IDFUNCIONARIO, nome) value (NULL, '" + nome + "');";
        if (!db.executeQuery(insert)) {
                std::cerr << "Falha!" << std::endl;
                return;
            }
        std::cout.flush();
    }
    else {
        std::cerr << "Falha ao conectar ao banco de dados!" << std::endl;
        exit(1);
    }
}

void Banco::conferirFuncionarioCadastrado(){
    if (conectaBD()) {
        std::string select = "SELECT IDFUNCIONARIO AS ID_do_Funcionario, nome as Nome FROM FUNCIONARIO;";
        if (!db.executeQuery(select)) {
                std::cerr << "Falha!" << std::endl;
                return;
            }
        std::cout.flush();
    }
    else {
        std::cerr << "Falha ao conectar ao banco de dados!" << std::endl;
        exit(1);
    }
}

void Banco::removerFuncionario(){
    if (conectaBD()) {
        std::string mostrafucionario = "SELECT IDFUNCIONARIO AS ID_do_Funcionario, nome as Nome FROM FUNCIONARIO;";
        if (!db.executeQuery(mostrafucionario)) {
                std::cerr << "Falha!" << std::endl;
                return;
        }
        std::cout.flush();
        std::string id;
        std::cout << "Digite o ID do funcionario a ser removido:\n ->";
        std::cin >> id;

        std::cout << "Selecionado: ";

        std::string confirmacao = "SELECT IDFUNCIONARIO AS ID_do_Funcionario, nome as Nome FROM FUNCIONARIO WHERE IDFUNCIONARIO = " + id + ";";
        if (!db.executeQuery(confirmacao)) {
                std::cerr << "Falha!" << std::endl;
                return;
        }
        std::cout.flush();

        std::cout << "Confirma?\n1 - Sim\n2 - Nao";

        int confirmacaoNUM;
        std::cin >> confirmacaoNUM;

        if(confirmacaoNUM == 2){
            exit(1);
        }

        std::string exclusao = "delete FROM FUNCIONARIO WHERE IDFUNCIONARIO = " + id + ";";

        if (!db.executeQuery(exclusao)) {
                std::cerr << "Falha ao excluir funcionario!" << std::endl;
                return;
        }
        else
            std::cout << "Funcionario excluido com sucesso! ";
    }
    else {
        std::cerr << "Falha ao conectar ao banco de dados!" << std::endl;
        exit(1);
    }
}

void Banco::alterarFuncionario(){
    if (conectaBD()) {
        std::string mostrafucionario = "SELECT IDFUNCIONARIO AS ID_do_Funcionario, nome as Nome FROM FUNCIONARIO;";
        if (!db.executeQuery(mostrafucionario)) {
                std::cerr << "Falha!" << std::endl;
                return;
        }
        std::cout.flush();
        std::string id;
        std::cout << "Digite o ID do funcionario a ser removido:\n ->";
        std::cin >> id;

        std::cout << "Selecionado: ";

        std::string confirmacao = "SELECT IDFUNCIONARIO AS ID_do_Funcionario, nome as Nome FROM FUNCIONARIO WHERE IDFUNCIONARIO = " + id + ";";
        if (!db.executeQuery(confirmacao)) {
                std::cerr << "Falha!" << std::endl;
                return;
        }
        std::cout.flush();

        std::cout << "Digite o novo nome: ";
        std::string novonome;
        std::cin >> novonome;

        std::string trocanome = "update FUNCIONARIO set nome = '" + novonome + "' where IDFUNCIONARIO = " + id + ";";
        if (!db.executeQuery(trocanome)) {
                std::cerr << "Falha!" << std::endl;
                return;
        }
        else
            std::cout << "Nome alterado com sucesso!\n";
    }
    else {
        std::cerr << "Falha ao conectar ao banco de dados!" << std::endl;
        exit(1);
    }
}

void Banco::adicionarVeiculo(){
    if (conectaBD()) {
        std::string nomeMarcaVeiculo, modeloVeiculo, funcaoVeiculo, placaVeiculo;
        int quantidadeProduto;


        std::cout << "Insira os seguintes dados: \n";
        std::cout << "Insira o nome da marca do veiculo: ";
        std::getline(std::cin, nomeMarcaVeiculo);

        std::cout << "Insira o modelo do veiculo: ";
        std::getline(std::cin, modeloVeiculo);

        std::cout << "Insira a funçao do veiculo: ";
        std::getline(std::cin, funcaoVeiculo);

        std::cout << "Insira a placa do veiculo: ";
        std::getline(std::cin, placaVeiculo);

        // Se o banco foi conectado, tenta inserir dados
        Carro c(nomeMarcaVeiculo, modeloVeiculo, funcaoVeiculo, placaVeiculo);

        //registramos, inicialmente, uma marca
        std::string criaMarca = "INSERT OR IGNORE INTO MARCA (IDMARCA, nome) VALUES (NULL, '" + nomeMarcaVeiculo + "');";
        if (!db.executeQuery(criaMarca)) {
            std::cerr << "Falha ao Registrar a Marca!" << std::endl;
            return;
        }
        //guardamos o id referente a ela
        std::string idMarca;
        std::string selectQuery = "SELECT IDMARCA FROM MARCA WHERE nome = '" + nomeMarcaVeiculo + "'";
        db.getFirstColumnValue(selectQuery, idMarca);

        //EXECUTA O INSERT
        std::string insertDataTipoCarro = "INSERT INTO TIPOCARRO (IDTIPOCARRO, nome, funcao, ID_MARCA) VALUES (NULL, '" + modeloVeiculo + "', '" + funcaoVeiculo + "', '" + idMarca + "');";

        // Executa a consulta INSERT e verifica seu resultado
        if (!db.executeQuery(insertDataTipoCarro)) {
            std::cerr << "Falha ao inserir dados do veiculo!" << std::endl;
            return;
        }
        //guardamos o id referente a ela
        std::string idTipoCarro;
        std::string selectQueryTipoCarro = "SELECT IDTIPOCARRO FROM TIPOCARRO WHERE nome = '" + modeloVeiculo + "'";
        db.getFirstColumnValue(selectQueryTipoCarro, idTipoCarro);
        //FIM DE EXECUTA INSERT
        std::string insertCarro = "INSERT INTO CARRO (IDCARRO, placa, ID_TIPOCARRO) VALUES (NULL, '" + placaVeiculo+ "', '" + idTipoCarro + "');";
        if (!db.executeSelectQuery(insertCarro)) {
            std::cerr << "Falha ao inserir carro!" << std::endl;
        }

        // executa a querry SELECT
        std::string select = "SELECT CARRO.IDCARRO AS ID_VEICULO, TIPOCARRO.nome AS NOME_VEICULO, MARCA.nome AS MARCA_VEICULO, CARRO.placa AS PLACA_VEICULO, TIPOCARRO.funcao AS FUNCAO_VEICULO FROM CARRO INNER JOIN TIPOCARRO on TIPOCARRO.IDTIPOCARRO = CARRO.ID_TIPOCARRO inner join MARCA on MARCA.IDMARCA = TIPOCARRO.ID_MARCA;";
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

void Banco::conferirVeiculoCadastrado() {
    if (conectaBD()) {

        //chama select para mostrar todos os veiculos
        std::string select = "SELECT CARRO.IDCARRO AS ID_VEICULO, TIPOCARRO.nome AS NOME_VEICULO, MARCA.nome AS MARCA_VEICULO, CARRO.placa AS PLACA_VEICULO, TIPOCARRO.funcao AS FUNCAO_VEICULO FROM CARRO INNER JOIN TIPOCARRO on TIPOCARRO.IDTIPOCARRO = CARRO.ID_TIPOCARRO inner join MARCA on MARCA.IDMARCA = TIPOCARRO.ID_MARCA;";
        if(!db.executeSelectQuery(select)) {
            std::cerr << "Falha ao executar consulta SELECT!" << std::endl;
        }
        std::cout.flush();

    }
    else {
        std::cerr << "Falha ao conectar ao banco de dados!" << std::endl;
        exit(1);
    }
}

void Banco::removerVeiculo() {
    if (conectaBD()) {
        std::string select = "SELECT CARRO.IDCARRO AS ID_VEICULO, TIPOCARRO.nome AS NOME_VEICULO, MARCA.nome AS MARCA_VEICULO, CARRO.placa AS PLACA_VEICULO, TIPOCARRO.funcao AS FUNCAO_VEICULO FROM CARRO INNER JOIN TIPOCARRO on TIPOCARRO.IDTIPOCARRO = CARRO.ID_TIPOCARRO inner join MARCA on MARCA.IDMARCA = TIPOCARRO.ID_MARCA;";
        if(!db.executeSelectQuery(select)) {
            std::cerr << "Falha ao executar consulta SELECT!" << std::endl;
        }
        std::string veiculoID, ID_TIPOCARRO;
        std::cout.flush();
        std::cout << std::endl;
        std::cout << "DIGITE O NUMERO DO ID DO VEICULO A SER REMOVIDO: " << std::endl;
        std::cout << "-> ";
        std::cin >> veiculoID;
        std::string querryID_TIPOCARRO = "select CARRO.ID_TIPOCARRO from CARRO where IDCARRO = " + veiculoID + ";";
        db.getFirstColumnValue(querryID_TIPOCARRO, ID_TIPOCARRO);
        std::string remove1 = "DELETE FROM CARRO WHERE IDCARRO = " + veiculoID + ";";
        std::string remove2 = "DELETE FROM TIPOCARRO WHERE IDTIPOCARRO = " + ID_TIPOCARRO + ";";
        if(!db.executeSelectQuery(remove1) && !db.executeSelectQuery(remove2)) {
            std::cerr << "Falha ao executar consulta SELECT!" << std::endl;
        }
        else {
            std::cout << std::endl;
            std::cout << "Veiculo removido com sucesso!\n";
        }
    }
    else {
        std::cerr << "Falha ao conectar ao banco de dados!" << std::endl;
        exit(1);
    }
}

void Banco::modificarDadosVeiculo() {
    if (conectaBD()) {
        std::string select = "SELECT CARRO.IDCARRO AS ID_VEICULO, TIPOCARRO.nome AS NOME_VEICULO, MARCA.nome AS MARCA_VEICULO, CARRO.placa AS PLACA_VEICULO, TIPOCARRO.funcao AS FUNCAO_VEICULO FROM CARRO INNER JOIN TIPOCARRO on TIPOCARRO.IDTIPOCARRO = CARRO.ID_TIPOCARRO inner join MARCA on MARCA.IDMARCA = TIPOCARRO.ID_MARCA;";
        if(!db.executeSelectQuery(select)) {
            std::cerr << "Falha ao executar consulta SELECT!" << std::endl;
        }
        std::string idVeiculo;
        std::cout << std::endl;
        std::cout << "Qual o ID do veiculo que deseja alterar? \n";
        std::cout << "-> ";
        std::cin >> idVeiculo;
        std::cout << "VEICULO SELCIONADO: \n";
        std::string select1 = "SELECT CARRO.IDCARRO AS ID_VEICULO, TIPOCARRO.nome AS NOME_VEICULO, MARCA.nome AS MARCA_VEICULO, CARRO.placa AS PLACA_VEICULO, TIPOCARRO.funcao AS FUNCAO_VEICULO FROM CARRO INNER JOIN TIPOCARRO on TIPOCARRO.IDTIPOCARRO = CARRO.ID_TIPOCARRO inner join MARCA on MARCA.IDMARCA = TIPOCARRO.ID_MARCA where IDCARRO = " + idVeiculo + ";";
        if(!db.executeSelectQuery(select1)) {
            std::cerr << "Falha ao executar consulta SELECT!" << std::endl;
        }
        std::cout << std::endl;
        int opcao;
        std::cout << "O que deseja alterar? :\n";
        std::cout << "(1) NOME DO VEICULO\n(2) FUNÇAO DO VEICULO\n(3) PLACA DO VEICULO\n";
        std::cout << "-> ";
        std::cin >> opcao;
        if (opcao==1) {
            std::string ID_TIPOCARRO;
            std::string querryID_TIPOCARRO = "select CARRO.ID_TIPOCARRO from CARRO where IDCARRO = " + idVeiculo + ";";
            db.getFirstColumnValue(querryID_TIPOCARRO, ID_TIPOCARRO);
            std::string nomeNovo;
            std::cout << "Digite o novo nome do veiculo: \n";
            std::cout << "-> ";
            std::cin >> nomeNovo;
            std::string querry = "update TIPOCARRO set nome = '" + nomeNovo + "' where IDTIPOCARRO = " + ID_TIPOCARRO + ";";
            if (!db.executeQuery(querry)) {
                std::cerr << "Falha ao alterar dados do veiculo!" << std::endl;
                return;
            }
            else {
                std::cout << std::endl;
                std::cout << "Veiculo alterado com sucesso!\n";
            }
        }
        else if (opcao==2) {
            std::string funcao;
            std::cout << "Digite a nova funcao: \n";
            std::cout << "-> ";
            std::cin >> funcao;
            std::string ID_TIPOCARRO;
            std::string querryID_TIPOCARRO = "select CARRO.ID_TIPOCARRO from CARRO where IDCARRO = " + idVeiculo + ";";
            db.getFirstColumnValue(querryID_TIPOCARRO, ID_TIPOCARRO);
            std::string querry1 = "update TIPOCARRO set funcao = '" + funcao + "' where IDTIPOCARRO = " + ID_TIPOCARRO + ";";
            if (!db.executeQuery(querry1)) {
                std::cerr << "Falha ao alterar dados do veiculo!" << std::endl;
                return;
            }
            else {
                std::cout << std::endl;
                std::cout << "Veiculo alterado com sucesso!\n";
            }
        }
        else if (opcao==3) {
            std::string placa;
            std::cout << "Digite a nova placa: \n";
            std::cout << "-> ";
            std::cin >> placa;
            std::string querry2 = "update CARRO set placa = '" + placa + "' where IDCARRO = " + idVeiculo + ";";
            if (!db.executeQuery(querry2)) {
                std::cerr << "Falha ao alterar dados do veiculo!" << std::endl;
                return;
            }
            else {
                std::cout << std::endl;
                std::cout << "Veiculo alterado com sucesso!\n";
            }
        }
    }
    else {
            std::cerr << "Falha ao conectar ao banco de dados!" << std::endl;
            exit(1);
    }
}

void Banco::adicionarManutencao() {
    if (conectaBD()) {
        std::string select = "SELECT CARRO.IDCARRO AS ID_VEICULO, TIPOCARRO.nome AS NOME_VEICULO, MARCA.nome AS MARCA_VEICULO, CARRO.placa AS PLACA_VEICULO, TIPOCARRO.funcao AS FUNCAO_VEICULO FROM CARRO INNER JOIN TIPOCARRO on TIPOCARRO.IDTIPOCARRO = CARRO.ID_TIPOCARRO inner join MARCA on MARCA.IDMARCA = TIPOCARRO.ID_MARCA;";
        if(!db.executeSelectQuery(select)) {
            std::cerr << "Falha ao executar consulta SELECT!" << std::endl;
        }
        std::cout << std::endl;
        std::string idVeiculo;
        std::cout << "Qual o ID do veículo a ser escolhido? \n";
        std::cout << "-> ";
        std::cin >> idVeiculo;
        std::cout << std::endl;
        std::cout << "Digite a data da manutençao: \n";
        std::cout << "-> ";
        std::string dataManutenao;
        std::cin.ignore();
        std::getline(std::cin, dataManutenao);


        std::string querry = "insert into MANUTENCAO (IDMANUTENCAO, dataManutencao, ID_CARRO) values (NULL, '" + dataManutenao + "', " + idVeiculo + ");";
        if (!db.executeQuery(querry)) {
            std::cerr << "Falha ao registrar manutencao!" << std::endl;
            return;
        }
        std::string ID_MANUTENCAO;
        std::string querryID_MANUTENCAO = "select IDMANUTENCAO from MANUTENCAO where ID_CARRO = " + idVeiculo + ";";
        db.getFirstColumnValue(querryID_MANUTENCAO, ID_MANUTENCAO);
        std::cout << std::endl;
        std::string mensagem;
        std::cout << "Digite uma mensagem sobre a manutençao realizada: \n-> ";
        std::getline(std::cin, mensagem);
        std::string querry2 = "insert into MENSAGEM (IDMENSAGEM, conteudo, ID_MANUTENCAO) VALUES (NULL, '" + mensagem + "', " + ID_MANUTENCAO + ");";
        if (!db.executeQuery(querry2)) {
            std::cerr << "Falha ao registrar mensagem!" << std::endl;
            return;
        }
        else {
            std::cout << "Mensagem registrada com sucesso!" << std::endl;
        }
    }
    else {
        std::cerr << "Falha ao conectar ao banco de dados!" << std::endl;
        exit(1);
    }
}

void Banco::conferirManutencao() {
    if (conectaBD()) {
        std::string  querry= "select MANUTENCAO.IDMANUTENCAO as 'ID DA MANUTENCAO', MANUTENCAO.dataManutencao as 'DATA DA MANUTENÇÃO' from MANUTENCAO;";
        if(!db.executeSelectQuery(querry)) {
            std::cerr << "Falha ao executar consulta SELECT!" << std::endl;
        }
        std::cout << std::endl;
        std::cout << "Qual o ID referente à data da manutençao desejada?\n-> ";
        std::string idManutencao;
        std::cin >> idManutencao;
        std::string ID_CARRO;
        std::string querryID_CARRO = "select ID_CARRO from MANUTENCAO where IDMANUTENCAO = " + idManutencao + ";";
        db.getFirstColumnValue(querryID_CARRO, ID_CARRO);
        std::cout << std::endl;
        std::cout << "Mensagem referente: ";
        std::cout << std::endl;
        std::cout << "Placa do veiculo referente: ";
        std::string querry3= "select placa as PLACA_DO_VEICULO from CARRO where IDCARRO = " + ID_CARRO + ";";
        if(!db.executeSelectQuery(querry3)) {
            std::cerr << "Falha ao executar consulta SELECT!" << std::endl;
        }
        std::string querry2 = "select MENSAGEM.conteudo from MENSAGEM where ID_MANUTENCAO = " + idManutencao + ";";
        if(!db.executeSelectQuery(querry2)) {
            std::cerr << "Falha ao executar consulta SELECT!" << std::endl;
        }
    }
    else {
        std::cerr << "Falha ao conectar ao banco de dados!" << std::endl;
        exit(1);
    }
}

void Banco::removerRegistroManutencao() {
    if (conectaBD()) {
        std::string  querry= "select MANUTENCAO.IDMANUTENCAO as 'ID DA MANUTENCAO', MANUTENCAO.dataManutencao as 'DATA DA MANUTENÇÃO' from MANUTENCAO;";
        if(!db.executeSelectQuery(querry)) {
            std::cerr << "Falha ao executar consulta SELECT!" << std::endl;
        }
        std::cout << std::endl;
        std::cout << "Qual o ID referente à data da manutençao que deseja apagar?\n-> ";
        std::string idManutencao;
        std::cin >> idManutencao;
        std::string querry1 = "delete from MANUTENCAO where IDMANUTENCAO = " + idManutencao + ";";
        std::string querry2 = "delete from MENSAGEM where ID_MANUTENCAO = " + idManutencao + ";";
        if (!db.executeQuery(querry1)) {
            std::cerr << "Falha ao remover manutençao!" << std::endl;
            return;
        }
        else {
            std::cout << "Manutençao removida com sucesso! \n";
        }
        if (!db.executeSelectQuery(querry2)) {
            std::cerr << "Falha ao remover mensagem!" << std::endl;
            return;
        }
        else {
            std::cout << "Mensagem removida com sucesso! \n";
        }
    }
    else {
        std::cerr << "Falha ao conectar ao banco de dados!" << std::endl;
        exit(1);
    }
}

void Banco::alterarManutencao() {
    if (conectaBD()) {
        std::cout << "Escolha uma opção: \n(1)ALTERAR DATA DA MANUTENÇAO\n(2)ALTERAR MENSAGEM REFERENTE\n(3)ALTERAR VEICULO REFERENTE\n-> ";
        int opcao;
        std::cin >> opcao;
        if (opcao==1) {
            std::string  querry= "select MANUTENCAO.IDMANUTENCAO as 'ID DA MANUTENCAO', MANUTENCAO.dataManutencao as 'DATA DA MANUTENÇÃO' from MANUTENCAO;";
            if(!db.executeSelectQuery(querry)) {
                std::cerr << "Falha ao executar consulta SELECT!" << std::endl;
            }
            std::cout << std::endl;
            std::cout << "Qual o ID referente à data da manutençao que deseja alterar?\n-> ";
            std::string idManutencao;
            std::cin >> idManutencao;
            std::cout << std::endl;
            std::cout << "Digite a nova data da manutencao:\n-> ";
            std::string novaData;
            std::cin.ignore();
            std::getline(std::cin, novaData);
            std::string q1 = "update MANUTENCAO set dataManutencao = '" + novaData + "' where IDMANUTENCAO = " + idManutencao + ";";
            if (!db.executeQuery(q1)) {
                std::cerr << "Falha ao alterar data da manutençao!" << std::endl;
                return;
            }
            else {
                std::cout << "Manutençao alterada com sucesso! \n";
            }
        }
        else if (opcao==2) {
            std::string  querry= "select MANUTENCAO.IDMANUTENCAO as 'ID DA MANUTENCAO', MANUTENCAO.dataManutencao as 'DATA DA MANUTENÇÃO' from MANUTENCAO;";
            if(!db.executeSelectQuery(querry)) {
                std::cerr << "Falha ao executar consulta SELECT!" << std::endl;
            }
            std::cout << std::endl;
            std::cout << "Qual o ID referente à data da manutençao que deseja alterar?\n-> ";
            std::string idManutencao;
            std::cin >> idManutencao;
            std::cout << std::endl;
            std::cout << "Digite a nova mensagem: \n";
            std::string mensagem;
            std::cin.ignore();
            std::getline(std::cin, mensagem);
            std::string q1 = "update MENSAGEM set conteudo = '" + mensagem + "' where ID_MANUTENCAO = " + idManutencao + ";";
            if (!db.executeQuery(q1)) {
                std::cerr << "Falha ao alterar mensagem da manutençao!" << std::endl;
                return;
            }
            else {
                std::cout << "Mensagem alterada com sucesso!";
            }
        }
        else if (opcao==3) {
            std::string  querry= "select MANUTENCAO.IDMANUTENCAO as 'ID DA MANUTENCAO', MANUTENCAO.dataManutencao as 'DATA DA MANUTENÇÃO' from MANUTENCAO;";
            if(!db.executeSelectQuery(querry)) {
                std::cerr << "Falha ao executar consulta SELECT!" << std::endl;
            }
            std::cout << std::endl;
            std::cout << "Qual o ID referente à data da manutençao que deseja alterar?\n-> ";
            std::string idManutencao;
            std::cin >> idManutencao;
            std::cout << std::endl;
            std::string select = "SELECT CARRO.IDCARRO AS ID_VEICULO, TIPOCARRO.nome AS NOME_VEICULO, MARCA.nome AS MARCA_VEICULO, CARRO.placa AS PLACA_VEICULO, TIPOCARRO.funcao AS FUNCAO_VEICULO FROM CARRO INNER JOIN TIPOCARRO on TIPOCARRO.IDTIPOCARRO = CARRO.ID_TIPOCARRO inner join MARCA on MARCA.IDMARCA = TIPOCARRO.ID_MARCA;";
            if(!db.executeSelectQuery(select)) {
                std::cerr << "Falha ao executar consulta SELECT!" << std::endl;
            }
            std::cout << std::endl;
            std::string idVeiculo;
            std::cout << "Qual o ID do novo veículo a ser escolhido? \n";
            std::cout << "-> ";
            std::cin >> idVeiculo;
            std::cout << std::endl;
            std::string s = "update MANUTENCAO set ID_CARRO = " + idVeiculo + " where IDMANUTENCAO = " + idManutencao + ";";
            if (!db.executeQuery(s)) {
                std::cerr << "Falha ao alterar veiculo da manutençao!" << std::endl;
                return;
            }
            else {
                std::cout << "veiculo alterado com sucesso!";
            }
        }
    }
    else {
        std::cerr << "Falha ao conectar ao banco de dados!" << std::endl;
        exit(1);
    }
}




