//
// Created by viniciuskl on 23/01/25.
//
#include <iostream>
#include "Banco.h"

#include <limits>

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
void testeEntrada(int &valor, int limitesup) {
    bool testeVariavel = false;
    do{
        testeVariavel = false;
        try{
            std::cin >> valor;
            if (std::cin.fail()) {
                std::cin.clear(); // Limpa o estado de erro de cin
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta o restante da entrada
                throw std::invalid_argument("Entrada inválida! Digite um número inteiro.\n");
            }
            if(valor <= 0 || valor > limitesup){
                throw std::invalid_argument("Opcao invalida!\n");
            }
        }
        catch(std::exception &e){
            std::cout << e.what();
            std::cout << "Selecione uma opcao valida: ";
            testeVariavel = true;
        }
    }while(testeVariavel);
}

void Banco::adicionarProdutoNovo() {
    if (conectaBD()) {
        std::string nomeProduto, nomeMarcaProduto, numeroProduto, dataCompra, localCompra;
        int quantidadeProduto;
        std::string texto1 = "Insira os seguintes dados: \n";
        std::cout << texto1 << std::endl;
        std::string texto2 = "Insira o nome do produto: ";
        std::cout << texto2 << std::endl;
        Acessibilidade::colocaTexto(texto1);
        Acessibilidade::colocaTexto(texto2);
        std::cin.ignore();
        std::getline(std::cin, nomeProduto);

        std::string texto = "Insira o tipo do produto: \n";
        std::cout << texto << std::endl;
        Acessibilidade::colocaTexto(texto);
        std::string tipoProduto = Produto::defineTipo();

        std::string texto3 = "Insira a quantidade do produto: ";
        std::cout << texto3 << std::endl;
        Acessibilidade::colocaTexto(texto3);
        std::cin >> quantidadeProduto;

        std::cin.ignore();
        std::string texto4 = "Insira o nome da marca referente aos veículos compatíveis com o produto: ";
        std::cout << texto4 << std::endl;
        Acessibilidade::colocaTexto(texto4);
        std::getline(std::cin, nomeMarcaProduto);

        std::string texto5 = "Insira o número do produto: ";
        std::cout << texto5 << std::endl;
        Acessibilidade::colocaTexto(texto5);
        std::getline(std::cin, numeroProduto);

        Produto p(nomeProduto, quantidadeProduto, nomeMarcaProduto, numeroProduto);

        std::string criaMarca = "INSERT OR IGNORE INTO MARCA (IDMARCA, nome) VALUES (NULL, '" + nomeMarcaProduto + "');";
        if (!db.executeQuery(criaMarca)) {
            std::string erro1 = "Falha ao Registrar a Marca!";
            std::cerr << erro1 << std::endl;
            Acessibilidade::colocaTexto(erro1);
            return;
        }

        std::string idMarca;
        std::string selectQuery = "SELECT IDMARCA FROM MARCA WHERE nome = '" + nomeMarcaProduto + "'";
        db.getFirstColumnValue(selectQuery, idMarca);

        std::string insertDataTipoProduto = "INSERT INTO TIPOPRODUTO (IDTIPOPRODUTO, nome, tipo) VALUES (NULL, '" + nomeProduto + "', '" + tipoProduto + "');";

        if (!db.executeQuery(insertDataTipoProduto)) {
            std::string erro2 = "Falha ao inserir dados do produto!";
            std::cerr << erro2 << std::endl;
            Acessibilidade::colocaTexto(erro2);
            return;
        }

        std::string idTipoProduto;
        std::string selectQueryTipoProduto = "SELECT IDTIPOPRODUTO FROM TIPOPRODUTO WHERE nome = '" + nomeProduto + "'";
        db.getFirstColumnValue(selectQueryTipoProduto, idTipoProduto);

        std::string insertProduto = "INSERT INTO PRODUTO (IDPRODUTO, quantidade, numero, ID_MARCA, ID_TIPOPRODUTO) VALUES (NULL, " + std::to_string(quantidadeProduto) + ", '" + numeroProduto + "', " + (idMarca) + ", " + (idTipoProduto) + ");";
        if (!db.executeSelectQuery(insertProduto)) {
            std::string erro3 = "Falha ao inserir produto!";
            std::cerr << erro3 << std::endl;
            Acessibilidade::colocaTexto(erro3);
        }

        std::string texto6 = "Insira a data da compra : ";
        std::cout << texto6 << std::endl;
        Acessibilidade::colocaTexto(texto6);
        std::cout << "(Formato: DD/MM/AA)";
        std::getline(std::cin, dataCompra);

        std::string texto7 = "Insira o local da compra: ";
        std::cout << texto7 << std::endl;
        Acessibilidade::colocaTexto(texto7);
        std::getline(std::cin, localCompra);

        std::string idProduto;
        std::string selectQueryProduto = "SELECT IDPRODUTO FROM PRODUTO WHERE ID_TIPOPRODUTO = '" + idTipoProduto + "'";
        db.getFirstColumnValue(selectQueryProduto, idProduto);

        std::string insertRegistro = "insert into REGISTRO (IDREGISTRO, dataCompra, localCompra, quantidadeComprada, ID_PRODUTO) values (NULL, '" + dataCompra + "', '" + localCompra + "', " + std::to_string(quantidadeProduto) + ", " + idProduto + ");";
        if (!db.executeQuery(insertRegistro)) {
            std::string erro4 = "Falha ao inserir dados do registro!";
            std::cerr << erro4 << std::endl;
            Acessibilidade::colocaTexto(erro4);
            return;
        }

        std::string select = "SELECT PRODUTO.IDPRODUTO as ID_PRODUTO, TIPOPRODUTO.nome as NOME_TIPO_PRODUTO, MARCA.nome as NOME_MARCA, TIPOPRODUTO.tipo as TIPO, PRODUTO.numero as NUMERO_PRODUTO, PRODUTO.quantidade as QUANTIDADE_PRODUTO, REGISTRO.dataCompra as DATA_DE_COMPRA, REGISTRO.localCompra as LOCAL_DE_COMPRA from PRODUTO inner join main.MARCA on MARCA.IDMARCA = PRODUTO.ID_MARCA inner join main.REGISTRO on PRODUTO.IDPRODUTO = REGISTRO.ID_PRODUTO inner join main.TIPOPRODUTO on TIPOPRODUTO.IDTIPOPRODUTO = PRODUTO.ID_TIPOPRODUTO;";
        if (!db.executeSelectQuery(select)) {
            std::string erro5 = "Falha ao executar consulta SELECT!";
            std::cerr << erro5 << std::endl;
            Acessibilidade::colocaTexto(erro5);
        }

        std::cout.flush();
    }
    else {
        std::string erro6 = "Falha ao conectar ao banco de dados!";
        std::cerr << erro6 << std::endl;
        Acessibilidade::colocaTexto(erro6);
        exit(1);
    }
}

void Banco::adicionarProdutoExistente() {
    if (conectaBD()) {
        std::string select = "SELECT PRODUTO.IDPRODUTO as ID_PRODUTO, TIPOPRODUTO.nome as NOME_TIPO_PRODUTO, MARCA.nome as NOME_MARCA, TIPOPRODUTO.tipo as TIPO, PRODUTO.numero as NUMERO_PRODUTO, PRODUTO.quantidade as QUANTIDADE_PRODUTO, REGISTRO.dataCompra as DATA_DE_COMPRA, REGISTRO.localCompra as LOCAL_DE_COMPRA from PRODUTO inner join main.MARCA on MARCA.IDMARCA = PRODUTO.ID_MARCA inner join main.REGISTRO on PRODUTO.IDPRODUTO = REGISTRO.ID_PRODUTO inner join main.TIPOPRODUTO on TIPOPRODUTO.IDTIPOPRODUTO = PRODUTO.ID_TIPOPRODUTO;";
        if (!db.executeSelectQuery(select)) {
            std::string erro1 = "Falha ao executar consulta SELECT!";
            std::cerr << erro1 << std::endl;
            Acessibilidade::colocaTexto(erro1);
        }
        std::cout.flush();

        std::string idProduto;
        std::string texto = "Qual o ID do produto a ser alterado?";
        std::cout << texto << "\n";
        Acessibilidade::colocaTexto(texto);

        std::string seta = "->";
        std::cout << seta;
        Acessibilidade::colocaTexto(seta);
        std::cin >> idProduto;

        std::string texto1 = "Qual a quantidade a ser adicionada?";
        std::cout << texto1 << "\n";
        Acessibilidade::colocaTexto(texto1);

        std::cout << seta;
        Acessibilidade::colocaTexto(seta);
        std::string quantidade;
        std::cin >> quantidade;

        std::string qtd;
        std::string selectQueryTipoProduto = "SELECT quantidade FROM PRODUTO WHERE IDPRODUTO = '" + idProduto + "'";
        db.getFirstColumnValue(selectQueryTipoProduto, qtd);

        int novaQuantidade = stoi(quantidade) + stoi(qtd);
        std::string novaQTD = std::to_string(novaQuantidade);

        std::string atualizaQuant = "update PRODUTO set quantidade = " + novaQTD + " where IDPRODUTO=" + idProduto + ";";
        if (!db.executeQuery(atualizaQuant)) {
            std::string erro2 = "Falha ao inserir dados do produto!";
            std::cerr << erro2 << std::endl;
            Acessibilidade::colocaTexto(erro2);
            return;
        }

        std::string quebraLinha = "\n";
        std::cout << std::endl;
        Acessibilidade::colocaTexto(quebraLinha);

        std::string texto3 = "Novos Dados após a alteração:";
        std::cout << texto3 << "\n";
        Acessibilidade::colocaTexto(texto3);

        std::string select2 = "SELECT PRODUTO.IDPRODUTO as ID_PRODUTO, TIPOPRODUTO.nome as NOME_TIPO_PRODUTO, MARCA.nome as NOME_MARCA, TIPOPRODUTO.tipo as TIPO, PRODUTO.numero as NUMERO_PRODUTO, PRODUTO.quantidade as QUANTIDADE_PRODUTO, REGISTRO.dataCompra as DATA_DE_COMPRA, REGISTRO.localCompra as LOCAL_DE_COMPRA from PRODUTO inner join main.MARCA on MARCA.IDMARCA = PRODUTO.ID_MARCA inner join main.REGISTRO on PRODUTO.IDPRODUTO = REGISTRO.ID_PRODUTO inner join main.TIPOPRODUTO on TIPOPRODUTO.IDTIPOPRODUTO = PRODUTO.ID_TIPOPRODUTO where IDPRODUTO = " + idProduto + ";";
        if (!db.executeSelectQuery(select2)) {
            std::string erro3 = "Falha ao executar consulta SELECT!";
            std::cerr << erro3 << std::endl;
            Acessibilidade::colocaTexto(erro3);
        }
    }
    else {
        std::string erro4 = "Falha ao conectar ao banco de dados!";
        std::cerr << erro4 << std::endl;
        Acessibilidade::colocaTexto(erro4);
        exit(1);
    }
}

void Banco::conferirEstoque() {
    if (conectaBD()) {
        std::string select = "SELECT PRODUTO.IDPRODUTO as ID_PRODUTO, TIPOPRODUTO.nome as NOME_TIPO_PRODUTO, MARCA.nome as NOME_MARCA, TIPOPRODUTO.tipo as TIPO, PRODUTO.numero as NUMERO_PRODUTO, PRODUTO.quantidade as QUANTIDADE_PRODUTO, REGISTRO.dataCompra as DATA_DE_COMPRA, REGISTRO.localCompra as LOCAL_DE_COMPRA from PRODUTO inner join main.MARCA on MARCA.IDMARCA = PRODUTO.ID_MARCA inner join main.REGISTRO on PRODUTO.IDPRODUTO = REGISTRO.ID_PRODUTO inner join main.TIPOPRODUTO on TIPOPRODUTO.IDTIPOPRODUTO = PRODUTO.ID_TIPOPRODUTO;";
        if (!db.executeSelectQuery(select)) {
            std::string erro1 = "Falha ao executar consulta SELECT!";
            std::cerr << erro1 << std::endl;
            Acessibilidade::colocaTexto(erro1);
        }
        std::cout.flush();
    }
    else {
        std::string erro2 = "Falha ao conectar ao banco de dados!";
        std::cerr << erro2 << std::endl;
        Acessibilidade::colocaTexto(erro2);
        exit(1);
    }
}

void Banco::removerProduto() {
    if (conectaBD()) {
        std::string select = "SELECT PRODUTO.IDPRODUTO as ID_PRODUTO, TIPOPRODUTO.nome as NOME_TIPO_PRODUTO, MARCA.nome as NOME_MARCA, TIPOPRODUTO.tipo as TIPO, PRODUTO.numero as NUMERO_PRODUTO, PRODUTO.quantidade as QUANTIDADE_PRODUTO, REGISTRO.dataCompra as DATA_DE_COMPRA, REGISTRO.localCompra as LOCAL_DE_COMPRA from PRODUTO inner join main.MARCA on MARCA.IDMARCA = PRODUTO.ID_MARCA inner join main.REGISTRO on PRODUTO.IDPRODUTO = REGISTRO.ID_PRODUTO inner join main.TIPOPRODUTO on TIPOPRODUTO.IDTIPOPRODUTO = PRODUTO.ID_TIPOPRODUTO;";
        if (!db.executeSelectQuery(select)) {
            std::string erro1 = "Falha ao executar consulta SELECT!";
            std::cerr << erro1 << std::endl;
            Acessibilidade::colocaTexto(erro1);
        }

        std::string productID, ID_TIPOPRODUTO;
        std::cout.flush();

        std::string quebraLinha = "\n";
        std::cout << std::endl;
        Acessibilidade::colocaTexto(quebraLinha);

        std::string texto = "DIGITE O NUMERO DO ID DO PRODUTO A SER REMOVIDO:";
        std::cout << texto << std::endl;
        Acessibilidade::colocaTexto(texto);

        std::string seta = "->";
        std::cout << seta;
        Acessibilidade::colocaTexto(seta);
        std::cin >> productID;

        std::string querryID_TIPOPRODUTO = "select PRODUTO.ID_TIPOPRODUTO from PRODUTO where IDPRODUTO = " + productID + ";";
        db.getFirstColumnValue(querryID_TIPOPRODUTO, ID_TIPOPRODUTO);

        std::string remove1 = "DELETE FROM PRODUTO WHERE IDPRODUTO = " + productID + ";";
        std::string remove2 = "DELETE FROM TIPOPRODUTO WHERE IDTIPOPRODUTO = " + ID_TIPOPRODUTO + ";";
        std::string remove3 = "DELETE FROM REGISTRO WHERE ID_PRODUTO = " + productID + ";";

        if (!db.executeSelectQuery(remove1) && !db.executeSelectQuery(remove2) && !db.executeSelectQuery(remove3)) {
            std::string erro2 = "Falha ao executar consulta SELECT!";
            std::cerr << erro2 << std::endl;
            Acessibilidade::colocaTexto(erro2);
        }
        else {
            std::cout << std::endl;
            Acessibilidade::colocaTexto(quebraLinha);

            std::string sucesso = "Produto removido com sucesso!";
            std::cout << sucesso << "\n";
            Acessibilidade::colocaTexto(sucesso);
        }
    }
    else {
        std::string erro3 = "Falha ao conectar ao banco de dados!";
        std::cerr << erro3 << std::endl;
        Acessibilidade::colocaTexto(erro3);
        exit(1);
    }
}

void Banco::alterarDadosProduto() {
    if (conectaBD()) {
        std::string select = "SELECT PRODUTO.IDPRODUTO as ID_PRODUTO, TIPOPRODUTO.nome as NOME_TIPO_PRODUTO, MARCA.nome as NOME_MARCA, TIPOPRODUTO.tipo as TIPO, PRODUTO.numero as NUMERO_PRODUTO, PRODUTO.quantidade as QUANTIDADE_PRODUTO, REGISTRO.dataCompra as DATA_DE_COMPRA, REGISTRO.localCompra as LOCAL_DE_COMPRA from PRODUTO inner join main.MARCA on MARCA.IDMARCA = PRODUTO.ID_MARCA inner join main.REGISTRO on PRODUTO.IDPRODUTO = REGISTRO.ID_PRODUTO inner join main.TIPOPRODUTO on TIPOPRODUTO.IDTIPOPRODUTO = PRODUTO.ID_TIPOPRODUTO;";
        if (!db.executeSelectQuery(select)) {
            std::string erro1 = "Falha ao executar consulta SELECT!";
            std::cerr << erro1 << std::endl;
            Acessibilidade::colocaTexto(erro1);
        }

        std::string idProduto;
        std::string quebraLinha = "\n";
        std::cout << std::endl;
        Acessibilidade::colocaTexto(quebraLinha);

        std::string texto = "Qual o ID do produto que deseja alterar?";
        std::cout << texto << "\n";
        Acessibilidade::colocaTexto(texto);

        std::string seta = "->";
        std::cout << seta;
        Acessibilidade::colocaTexto(seta);
        std::cin >> idProduto;

        std::string produtoSelecionado = "PRODUTO SELECIONADO:";
        std::cout << produtoSelecionado << "\n";
        Acessibilidade::colocaTexto(produtoSelecionado);

        std::string select1 = "SELECT PRODUTO.IDPRODUTO as ID_PRODUTO, TIPOPRODUTO.nome as NOME_TIPO_PRODUTO, MARCA.nome as NOME_MARCA, TIPOPRODUTO.tipo as TIPO, PRODUTO.numero as NUMERO_PRODUTO, PRODUTO.quantidade as QUANTIDADE_PRODUTO, REGISTRO.dataCompra as DATA_DE_COMPRA, REGISTRO.localCompra as LOCAL_DE_COMPRA from PRODUTO inner join main.MARCA on MARCA.IDMARCA = PRODUTO.ID_MARCA inner join main.REGISTRO on PRODUTO.IDPRODUTO = REGISTRO.ID_PRODUTO inner join main.TIPOPRODUTO on TIPOPRODUTO.IDTIPOPRODUTO = PRODUTO.ID_TIPOPRODUTO where IDPRODUTO = " + idProduto + ";";
        if (!db.executeSelectQuery(select1)) {
            std::string erro2 = "Falha ao executar consulta SELECT!";
            std::cerr << erro2 << std::endl;
            Acessibilidade::colocaTexto(erro2);
        }

        std::cout << std::endl;
        Acessibilidade::colocaTexto(quebraLinha);

        int opcao;
        std::string texto1 = "Qual informação deseja trocar:";
        std::cout << texto1 << "\n";
        Acessibilidade::colocaTexto(texto1);

        std::string opcoes = "(1) NOME DO PRODUTO\n(2) QUANTIDADE\n(3) NUMERO DO PRODUTO\n(4) TIPO DO PRODUTO\n(5) DATA DE COMPRA\n(6) LOCAL DE COMPRA";
        std::cout << opcoes << "\n";
        Acessibilidade::colocaTexto(opcoes);
        std::cout << seta;
        Acessibilidade::colocaTexto(seta);
        testeEntrada(opcao, 6);

        if (opcao == 1) {
            std::string ID_TIPOPRODUTO;
            std::string querryID_TIPOPRODUTO = "select PRODUTO.ID_TIPOPRODUTO from PRODUTO where IDPRODUTO = " + idProduto + ";";
            db.getFirstColumnValue(querryID_TIPOPRODUTO, ID_TIPOPRODUTO);

            std::string nomeNovo;
            std::string texto3 = "Digite o novo nome do produto:";
            std::cout << texto3 << "\n";
            Acessibilidade::colocaTexto(texto3);

            std::cout << seta;
            Acessibilidade::colocaTexto(seta);
            std::cin.ignore();
            std::getline(std::cin, nomeNovo);

            std::string querry = "update TIPOPRODUTO set nome = '" + nomeNovo + "' where IDTIPOPRODUTO = " + ID_TIPOPRODUTO + ";";
            if (!db.executeQuery(querry)) {
                std::string erro3 = "Falha ao alterar dados do produto!";
                std::cerr << erro3 << std::endl;
                Acessibilidade::colocaTexto(erro3);
                return;
            }
            else {
                std::cout << std::endl;
                Acessibilidade::colocaTexto(quebraLinha);
                std::string sucesso = "Produto alterado com sucesso!";
                std::cout << sucesso << "\n";
                Acessibilidade::colocaTexto(sucesso);
            }
        }
        else if (opcao == 2) {
            std::string qtd;
            std::string texto4 = "Digite a nova quantidade:";
            std::cout << texto4 << "\n";
            Acessibilidade::colocaTexto(texto4);

            std::cout << seta;
            Acessibilidade::colocaTexto(seta);
            std::cin >> qtd;

            std::string querry1 = "update PRODUTO set quantidade = " + qtd + " where IDPRODUTO = " + idProduto + ";";
            if (!db.executeQuery(querry1)) {
                std::string erro4 = "Falha ao alterar dados do produto!";
                std::cerr << erro4 << std::endl;
                Acessibilidade::colocaTexto(erro4);
                return;
            }
            else {
                std::cout << std::endl;
                Acessibilidade::colocaTexto(quebraLinha);
                std::string sucesso = "Produto alterado com sucesso!";
                std::cout << sucesso << "\n";
                Acessibilidade::colocaTexto(sucesso);
            }
        }
        else if (opcao == 3) {
            std::string texto5 = "Digite o novo numero:";
            std::cout << texto5 << "\n";
            Acessibilidade::colocaTexto(texto5);

            std::cout << seta;
            Acessibilidade::colocaTexto(seta);
            std::string num;
            std::cin >> num;

            std::string querry2 = "update PRODUTO set numero = '" + num + "' where IDPRODUTO = " + idProduto + ";";
            if (!db.executeQuery(querry2)) {
                std::string erro5 = "Falha ao alterar dados do produto!";
                std::cerr << erro5 << std::endl;
                Acessibilidade::colocaTexto(erro5);
                return;
            }
            else {
                std::cout << std::endl;
                Acessibilidade::colocaTexto(quebraLinha);
                std::string sucesso = "Produto alterado com sucesso!";
                std::cout << sucesso << "\n";
                Acessibilidade::colocaTexto(sucesso);
            }
        }
        else if (opcao == 4) {
            std::string ID_TIPOPRODUTO1;
            std::string querryID_TIPOPRODUTO1 = "select PRODUTO.ID_TIPOPRODUTO from PRODUTO where IDPRODUTO = " + idProduto + ";";
            db.getFirstColumnValue(querryID_TIPOPRODUTO1, ID_TIPOPRODUTO1);

            std::string texto6 = "Digite o novo tipo do produto:";
            std::cout << texto6 << "\n";
            Acessibilidade::colocaTexto(texto6);

            std::string opcoesTipo = "(1) PEÇA\n(2) FLUIDO";
            std::cout << opcoesTipo << "\n";
            Acessibilidade::colocaTexto(opcoesTipo);

            std::cout << seta;
            Acessibilidade::colocaTexto(seta);
            int opcao1;
            testeEntrada(opcao1, 2);
            std::string novoTipo;
            if (opcao1 == 1) {
                novoTipo = "'Peça'";
            }
            else if (opcao1 == 2) {
                novoTipo = "'Fluido'";
            }

            std::string querry3 = "update TIPOPRODUTO set tipo = " + novoTipo + " where IDTIPOPRODUTO = " + ID_TIPOPRODUTO1 + ";";
            if (!db.executeQuery(querry3)) {
                std::string erro6 = "Falha ao alterar dados do produto!";
                std::cerr << erro6 << std::endl;
                Acessibilidade::colocaTexto(erro6);
                return;
            }
            else {
                std::cout << std::endl;
                Acessibilidade::colocaTexto(quebraLinha);
                std::string sucesso = "Produto alterado com sucesso!";
                std::cout << sucesso << "\n";
                Acessibilidade::colocaTexto(sucesso);
            }
        }
        else if (opcao == 5) {
            std::string texto7 = "Digite a nova data de compra:";
            std::cout << texto7 << "\n";
            Acessibilidade::colocaTexto(texto7);

            std::cout << seta;
            Acessibilidade::colocaTexto(seta);
            std::string novaDataCompra;
            std::cin.ignore();
            std::getline(std::cin, novaDataCompra);

            std::string querry4 = "update REGISTRO set dataCompra = '" + novaDataCompra + "' where ID_PRODUTO = " + idProduto + ";";
            if (!db.executeQuery(querry4)) {
                std::string erro7 = "Falha ao alterar dados do produto!";
                std::cerr << erro7 << std::endl;
                Acessibilidade::colocaTexto(erro7);
                return;
            }
            else {
                std::cout << std::endl;
                Acessibilidade::colocaTexto(quebraLinha);
                std::string sucesso = "Data de compra alterada com sucesso!";
                std::cout << sucesso << "\n";
                Acessibilidade::colocaTexto(sucesso);
            }
        }
        else if (opcao == 6) {
            std::string texto8 = "Digite o novo local de compra:";
            std::cout << texto8 << "\n";
            Acessibilidade::colocaTexto(texto8);

            std::cout << seta;
            Acessibilidade::colocaTexto(seta);
            std::string novoLocalCompra;
            std::cin.ignore();
            std::getline(std::cin, novoLocalCompra);

            std::string querry5 = "update REGISTRO set localCompra = '" + novoLocalCompra + "' where ID_PRODUTO = " + idProduto + ";";
            if (!db.executeQuery(querry5)) {
                std::string erro8 = "Falha ao alterar dados do produto!";
                std::cerr << erro8 << std::endl;
                Acessibilidade::colocaTexto(erro8);
                return;
            }
            else {
                std::cout << std::endl;
                Acessibilidade::colocaTexto(quebraLinha);
                std::string sucesso = "Local de compra alterado com sucesso!";
                std::cout << sucesso << "\n";
                Acessibilidade::colocaTexto(sucesso);
            }
        }
    }
    else {
        std::string erro9 = "Falha ao conectar ao banco de dados!";
        std::cerr << erro9 << std::endl;
        Acessibilidade::colocaTexto(erro9);
        exit(1);
    }
}

void Banco::adicionarFuncionario() {
    if (conectaBD()) {
        std::string nome;

        std::string texto1 = "Insira o nome do funcionario:\n";
        std::cout << texto1 << " ";
        Acessibilidade::colocaTexto(texto1);
        std::cin.ignore();
        std::getline(std::cin, nome);

        std::string insert = "INSERT INTO FUNCIONARIO (IDFUNCIONARIO, nome) values (NULL, '" + nome + "');";
        if (!db.executeQuery(insert)) {
            std::string erro1 = "Falha!";
            std::cerr << erro1 << std::endl;
            Acessibilidade::colocaTexto(erro1);
            return;
        }
        std::cout.flush();
    }
    else {
        std::string erro2 = "Falha ao conectar ao banco de dados!";
        std::cerr << erro2 << std::endl;
        Acessibilidade::colocaTexto(erro2);
        exit(1);
    }
}

void Banco::conferirFuncionarioCadastrado() {
    if (conectaBD()) {
        std::string select = "SELECT IDFUNCIONARIO AS ID_do_Funcionario, nome as Nome FROM FUNCIONARIO;";
        if (!db.executeSelectQuery(select)) {
            std::string erro1 = "Falha!";
            std::cerr << erro1 << std::endl;
            Acessibilidade::colocaTexto(erro1);
            return;
        }
        std::cout.flush();
    }
    else {
        std::string erro2 = "Falha ao conectar ao banco de dados!";
        std::cerr << erro2 << std::endl;
        Acessibilidade::colocaTexto(erro2);
        exit(1);
    }
}

void Banco::removerFuncionario() {
    if (conectaBD()) {
        std::string mostrafucionario = "SELECT IDFUNCIONARIO AS ID_do_Funcionario, nome as Nome FROM FUNCIONARIO;";
        if (!db.executeSelectQuery(mostrafucionario)) {
            std::string erro1 = "Falha!";
            std::cerr << erro1 << std::endl;
            Acessibilidade::colocaTexto(erro1);
            return;
        }
        std::cout.flush();

        std::string id;
        std::string texto1 = "Digite o ID do funcionario a ser removido:\n";
        std::cout << texto1 << "\n";
        Acessibilidade::colocaTexto(texto1);

        std::string seta = "->";
        std::cout << seta;
        Acessibilidade::colocaTexto(seta);
        std::cin >> id;

        std::string texto2 = "Selecionado:\n";
        std::cout << texto2 << " ";
        Acessibilidade::colocaTexto(texto2);

        std::string confirmacao = "SELECT IDFUNCIONARIO AS ID_do_Funcionario, nome as Nome FROM FUNCIONARIO WHERE IDFUNCIONARIO = " + id + ";";
        if (!db.executeSelectQuery(confirmacao)) {
            std::string erro2 = "Falha!";
            std::cerr << erro2 << std::endl;
            Acessibilidade::colocaTexto(erro2);
            return;
        }
        std::cout.flush();

        std::string texto3 = "Confirma?\n1 - Sim\n2 - Nao\n";
        std::cout << texto3;
        Acessibilidade::colocaTexto(texto3);

        int confirmacaoNUM;
        std::cin >> confirmacaoNUM;

        if(confirmacaoNUM == 2) {
            exit(1);
        }

        std::string exclusao = "delete FROM FUNCIONARIO WHERE IDFUNCIONARIO = " + id + ";";
        if (!db.executeQuery(exclusao)) {
            std::string erro3 = "Falha ao excluir funcionario!";
            std::cerr << erro3 << std::endl;
            Acessibilidade::colocaTexto(erro3);
            return;
        }
        else {
            std::string sucesso = "Funcionario excluido com sucesso!";
            std::cout << sucesso << " ";
            Acessibilidade::colocaTexto(sucesso);
        }
    }
    else {
        std::string erro4 = "Falha ao conectar ao banco de dados!";
        std::cerr << erro4 << std::endl;
        Acessibilidade::colocaTexto(erro4);
        exit(1);
    }
}

void Banco::alterarFuncionario() {
    if (conectaBD()) {
        std::string mostrafucionario = "SELECT IDFUNCIONARIO AS ID_do_Funcionario, nome as Nome FROM FUNCIONARIO;";
        if (!db.executeSelectQuery(mostrafucionario)) {
            std::cerr << "Falha!" << std::endl;
            std::string erro = "Falha!";
            Acessibilidade::colocaTexto(erro);
            return;
        }
        std::cout.flush();
        std::string id;
        std::cout << "Digite o ID do funcionario a ser removido:\n ->";
        std::string textoID = "Digite o ID do funcionario a ser removido:\n ->";
        Acessibilidade::colocaTexto(textoID);
        std::cin >> id;

        std::cout << "Selecionado: ";
        std::string textoSelecionado = "Selecionado: ";
        Acessibilidade::colocaTexto(textoSelecionado);

        std::string confirmacao = "SELECT IDFUNCIONARIO AS ID_do_Funcionario, nome as Nome FROM FUNCIONARIO WHERE IDFUNCIONARIO = " + id + ";";
        if (!db.executeSelectQuery(confirmacao)) {
            std::cerr << "Falha!" << std::endl;
            std::string erro = "Falha!";
            Acessibilidade::colocaTexto(erro);
            return;
        }
        std::cout.flush();

        std::cout << "Digite o novo nome: \n";
        std::string textoNovoNome = "Digite o novo nome: ";
        Acessibilidade::colocaTexto(textoNovoNome);
        std::string novonome;
        std::cin >> novonome;

        std::string trocanome = "update FUNCIONARIO set nome = '" + novonome + "' where IDFUNCIONARIO = " + id + ";";
        if (!db.executeQuery(trocanome)) {
            std::cerr << "Falha!" << std::endl;
            std::string erro = "Falha!";
            Acessibilidade::colocaTexto(erro);
            return;
        } else {
            std::cout << "Nome alterado com sucesso!\n";
            std::string sucesso = "Nome alterado com sucesso!";
            Acessibilidade::colocaTexto(sucesso);
        }
    } else {
        std::cerr << "Falha ao conectar ao banco de dados!" << std::endl;
        std::string erro = "Falha ao conectar ao banco de dados!";
        Acessibilidade::colocaTexto(erro);
        exit(1);
    }
}

void Banco::adicionarVeiculo() {
    if (conectaBD()) {
        std::string nomeMarcaVeiculo, modeloVeiculo, funcaoVeiculo, placaVeiculo;

        std::cout << "Insira os seguintes dados: \n";
        std::string textoDados = "Insira os seguintes dados: ";
        Acessibilidade::colocaTexto(textoDados);

        std::cout << "Insira o nome da marca do veiculo: ";
        std::string textoMarca = "Insira o nome da marca do veiculo: ";
        Acessibilidade::colocaTexto(textoMarca);
        std::cin.ignore();
        std::getline(std::cin, nomeMarcaVeiculo);

        std::cout << "Insira o modelo do veiculo: ";
        std::string textoModelo = "Insira o modelo do veiculo: ";
        Acessibilidade::colocaTexto(textoModelo);
        std::getline(std::cin, modeloVeiculo);

        std::cout << "Insira a funçao do veiculo: ";
        std::string textoFuncao = "Insira a funçao do veiculo: ";
        Acessibilidade::colocaTexto(textoFuncao);
        std::getline(std::cin, funcaoVeiculo);

        std::cout << "Insira a placa do veiculo: ";
        std::string textoPlaca = "Insira a placa do veiculo: ";
        Acessibilidade::colocaTexto(textoPlaca);
        std::getline(std::cin, placaVeiculo);

        Carro c(nomeMarcaVeiculo, modeloVeiculo, funcaoVeiculo, placaVeiculo);

        std::string criaMarca = "INSERT OR IGNORE INTO MARCA (IDMARCA, nome) VALUES (NULL, '" + nomeMarcaVeiculo + "');";
        if (!db.executeQuery(criaMarca)) {
            std::cerr << "Falha ao Registrar a Marca!" << std::endl;
            std::string erro = "Falha ao Registrar a Marca!";
            Acessibilidade::colocaTexto(erro);
            return;
        }

        std::string idMarca;
        std::string selectQuery = "SELECT IDMARCA FROM MARCA WHERE nome = '" + nomeMarcaVeiculo + "'";
        db.getFirstColumnValue(selectQuery, idMarca);

        std::string insertDataTipoCarro = "INSERT INTO TIPOCARRO (IDTIPOCARRO, nome, funcao, ID_MARCA) VALUES (NULL, '" + modeloVeiculo + "', '" + funcaoVeiculo + "', '" + idMarca + "');";
        if (!db.executeQuery(insertDataTipoCarro)) {
            std::cerr << "Falha ao inserir dados do veículo. Conexão com o banco de dados fechada.";
            std::string erro = "Falha ao inserir dados do veiculo!";
            Acessibilidade::colocaTexto(erro);
            return;
        }

        std::string idTipoCarro;
        std::string selectQueryTipoCarro = "SELECT IDTIPOCARRO FROM TIPOCARRO WHERE nome = '" + modeloVeiculo + "'";
        db.getFirstColumnValue(selectQueryTipoCarro, idTipoCarro);

        std::string insertCarro = "INSERT INTO CARRO (IDCARRO, placa, ID_TIPOCARRO) VALUES (NULL, '" + placaVeiculo + "', '" + idTipoCarro + "');";
        if (!db.executeSelectQuery(insertCarro)) {
            std::cerr << "Falha ao inserir carro!" << std::endl;
            std::string erro = "Falha ao inserir carro!";
            Acessibilidade::colocaTexto(erro);
            return;
        }

        std::string select = "SELECT CARRO.IDCARRO AS ID_VEICULO, TIPOCARRO.nome AS NOME_VEICULO, MARCA.nome AS MARCA_VEICULO, CARRO.placa AS PLACA_VEICULO, TIPOCARRO.funcao AS FUNCAO_VEICULO FROM CARRO INNER JOIN TIPOCARRO on TIPOCARRO.IDTIPOCARRO = CARRO.ID_TIPOCARRO inner join MARCA on MARCA.IDMARCA = TIPOCARRO.ID_MARCA;";
        if (!db.executeSelectQuery(select)) {
            std::cerr << "Falha ao executar consulta SELECT!" << std::endl;
            std::string erro = "Falha ao executar consulta SELECT!";
            Acessibilidade::colocaTexto(erro);
        }

        std::cout.flush();
    } else {
        std::cerr << "Falha ao conectar ao banco de dados!" << std::endl;
        std::string erro = "Falha ao conectar ao banco de dados!";
        Acessibilidade::colocaTexto(erro);
        exit(1);
    }
}

void Banco::conferirVeiculoCadastrado() {
    if (conectaBD()) {
        // Chama select para mostrar todos os veículos
        std::string select = "SELECT CARRO.IDCARRO AS ID_VEICULO, TIPOCARRO.nome AS NOME_VEICULO, MARCA.nome AS MARCA_VEICULO, CARRO.placa AS PLACA_VEICULO, TIPOCARRO.funcao AS FUNCAO_VEICULO FROM CARRO INNER JOIN TIPOCARRO on TIPOCARRO.IDTIPOCARRO = CARRO.ID_TIPOCARRO inner join MARCA on MARCA.IDMARCA = TIPOCARRO.ID_MARCA;";
        if (!db.executeSelectQuery(select)) {
            std::string erro = "Falha ao executar consulta SELECT!";
            std::cerr << erro << std::endl;
            Acessibilidade::colocaTexto(erro);
        }
        std::cout.flush();
    } else {
        std::string erro = "Falha ao conectar ao banco de dados!";
        std::cerr << erro << std::endl;
        Acessibilidade::colocaTexto(erro);
        exit(1);
    }
}

void Banco::removerVeiculo() {
    if (conectaBD()) {
        std::string select = "SELECT CARRO.IDCARRO AS ID_VEICULO, TIPOCARRO.nome AS NOME_VEICULO, MARCA.nome AS MARCA_VEICULO, CARRO.placa AS PLACA_VEICULO, TIPOCARRO.funcao AS FUNCAO_VEICULO FROM CARRO INNER JOIN TIPOCARRO on TIPOCARRO.IDTIPOCARRO = CARRO.ID_TIPOCARRO inner join MARCA on MARCA.IDMARCA = TIPOCARRO.ID_MARCA;";
        if (!db.executeSelectQuery(select)) {
            std::string erro = "Falha ao executar consulta SELECT!";
            std::cerr << erro << std::endl;
            Acessibilidade::colocaTexto(erro);
        }

        std::string veiculoID, ID_TIPOCARRO;
        std::cout.flush();
        std::cout << std::endl;

        std::string mensagem = "DIGITE O NUMERO DO ID DO VEICULO A SER REMOVIDO:\n-> ";
        std::cout << mensagem;
        Acessibilidade::colocaTexto(mensagem);

        std::cin >> veiculoID;

        std::string querryID_TIPOCARRO = "SELECT CARRO.ID_TIPOCARRO FROM CARRO WHERE IDCARRO = " + veiculoID + ";";
        db.getFirstColumnValue(querryID_TIPOCARRO, ID_TIPOCARRO);

        std::string remove1 = "DELETE FROM CARRO WHERE IDCARRO = " + veiculoID + ";";
        std::string remove2 = "DELETE FROM TIPOCARRO WHERE IDTIPOCARRO = " + ID_TIPOCARRO + ";";
        if (!db.executeSelectQuery(remove1) || !db.executeSelectQuery(remove2)) {
            std::string erro = "Falha ao executar consulta SELECT!";
            std::cerr << erro << std::endl;
            Acessibilidade::colocaTexto(erro);
        } else {
            std::string sucesso = "Veiculo removido com sucesso!\n";
            std::cout << std::endl;
            std::cout << sucesso;
            Acessibilidade::colocaTexto(sucesso);
        }
    } else {
        std::string erro = "Falha ao conectar ao banco de dados!";
        std::cerr << erro << std::endl;
        Acessibilidade::colocaTexto(erro);
        exit(1);
    }
}

void Banco::modificarDadosVeiculo() {
    if (conectaBD()) {
        std::string select = "SELECT CARRO.IDCARRO AS ID_VEICULO, TIPOCARRO.nome AS NOME_VEICULO, MARCA.nome AS MARCA_VEICULO, CARRO.placa AS PLACA_VEICULO, TIPOCARRO.funcao AS FUNCAO_VEICULO FROM CARRO INNER JOIN TIPOCARRO on TIPOCARRO.IDTIPOCARRO = CARRO.ID_TIPOCARRO inner join MARCA on MARCA.IDMARCA = TIPOCARRO.ID_MARCA;";
        if(!db.executeSelectQuery(select)) {
            std::string erro = "Falha ao executar consulta SELECT!";
            std::cerr << erro << std::endl;
            Acessibilidade::colocaTexto(erro);
        }
        std::string idVeiculo;
        std::cout << std::endl;
        std::string idPrompt = "Qual o ID do veiculo que deseja alterar? \n";
        std::cout << idPrompt;
        Acessibilidade::colocaTexto(idPrompt);
        std::string setaPrompt = "-> ";
        std::cout << setaPrompt;
        Acessibilidade::colocaTexto(setaPrompt);
        std::cin >> idVeiculo;

        std::string veicSelecionado = "VEICULO SELCIONADO: \n";
        std::cout << veicSelecionado;
        Acessibilidade::colocaTexto(veicSelecionado);

        std::string select1 = "SELECT CARRO.IDCARRO AS ID_VEICULO, TIPOCARRO.nome AS NOME_VEICULO, MARCA.nome AS MARCA_VEICULO, CARRO.placa AS PLACA_VEICULO, TIPOCARRO.funcao AS FUNCAO_VEICULO FROM CARRO INNER JOIN TIPOCARRO on TIPOCARRO.IDTIPOCARRO = CARRO.ID_TIPOCARRO inner join MARCA on MARCA.IDMARCA = TIPOCARRO.ID_MARCA where IDCARRO = " + idVeiculo + ";";
        if(!db.executeSelectQuery(select1)) {
            std::string erro = "Falha ao executar consulta SELECT!";
            std::cerr << erro << std::endl;
            Acessibilidade::colocaTexto(erro);
        }
        std::cout << std::endl;
        int opcao;
        std::string menu = "O que deseja alterar? :\n(1) NOME DO VEICULO\n(2) FUNÇAO DO VEICULO\n(3) PLACA DO VEICULO\n";
        std::cout << menu;
        Acessibilidade::colocaTexto(menu);
        std::cout << setaPrompt;
        Acessibilidade::colocaTexto(setaPrompt);
        testeEntrada(opcao, 3);

        if (opcao==1) {
            std::string ID_TIPOCARRO;
            std::string querryID_TIPOCARRO = "select CARRO.ID_TIPOCARRO from CARRO where IDCARRO = " + idVeiculo + ";";
            db.getFirstColumnValue(querryID_TIPOCARRO, ID_TIPOCARRO);
            std::string nomeNovo;
            std::string nomePrompt = "Digite o novo nome do veiculo: \n";
            std::cout << nomePrompt;
            Acessibilidade::colocaTexto(nomePrompt);
            std::cout << setaPrompt;
            Acessibilidade::colocaTexto(setaPrompt);
            std::cin.ignore();
            std::getline(std::cin, nomeNovo);
            std::string querry = "update TIPOCARRO set nome = '" + nomeNovo + "' where IDTIPOCARRO = " + ID_TIPOCARRO + ";";
            if (!db.executeQuery(querry)) {
                std::string erro = "Falha ao alterar dados do veiculo!";
                std::cerr << erro << std::endl;
                Acessibilidade::colocaTexto(erro);
                return;
            }
            else {
                std::cout << std::endl;
                std::string sucesso = "Veiculo alterado com sucesso!\n";
                std::cout << sucesso;
                Acessibilidade::colocaTexto(sucesso);
            }
        }
        else if (opcao==2) {
            std::string funcao;
            std::string funcaoPrompt = "Digite a nova funcao: \n";
            std::cout << funcaoPrompt;
            Acessibilidade::colocaTexto(funcaoPrompt);
            std::cout << setaPrompt;
            Acessibilidade::colocaTexto(setaPrompt);
            std::cin.ignore();
            std::getline(std::cin, funcao);
            std::string ID_TIPOCARRO;
            std::string querryID_TIPOCARRO = "select CARRO.ID_TIPOCARRO from CARRO where IDCARRO = " + idVeiculo + ";";
            db.getFirstColumnValue(querryID_TIPOCARRO, ID_TIPOCARRO);
            std::string querry1 = "update TIPOCARRO set funcao = '" + funcao + "' where IDTIPOCARRO = " + ID_TIPOCARRO + ";";
            if (!db.executeQuery(querry1)) {
                std::string erro = "Falha ao alterar dados do veiculo!";
                std::cerr << erro << std::endl;
                Acessibilidade::colocaTexto(erro);
                return;
            }
            else {
                std::cout << std::endl;
                std::string sucesso = "Veiculo alterado com sucesso!\n";
                std::cout << sucesso;
                Acessibilidade::colocaTexto(sucesso);
            }
        }
        else if (opcao==3) {
            std::string placa;
            std::string placaPrompt = "Digite a nova placa: \n";
            std::cout << placaPrompt;
            Acessibilidade::colocaTexto(placaPrompt);
            std::cout << setaPrompt;
            Acessibilidade::colocaTexto(setaPrompt);
            std::cin.ignore();
            std::getline(std::cin, placa);
            std::string querry2 = "update CARRO set placa = '" + placa + "' where IDCARRO = " + idVeiculo + ";";
            if (!db.executeQuery(querry2)) {
                std::string erro = "Falha ao alterar dados do veiculo!";
                std::cerr << erro << std::endl;
                Acessibilidade::colocaTexto(erro);
                return;
            }
            else {
                std::cout << std::endl;
                std::string sucesso = "Veiculo alterado com sucesso!\n";
                std::cout << sucesso;
                Acessibilidade::colocaTexto(sucesso);
            }
        }
    }
    else {
        std::string erro = "Falha ao conectar ao banco de dados!";
        std::cerr << erro << std::endl;
        Acessibilidade::colocaTexto(erro);
        exit(1);
    }
}

void Banco::adicionarManutencao() {
    if (conectaBD()) {
        std::string select = "SELECT CARRO.IDCARRO AS ID_VEICULO, TIPOCARRO.nome AS NOME_VEICULO, MARCA.nome AS MARCA_VEICULO, CARRO.placa AS PLACA_VEICULO, TIPOCARRO.funcao AS FUNCAO_VEICULO FROM CARRO INNER JOIN TIPOCARRO on TIPOCARRO.IDTIPOCARRO = CARRO.ID_TIPOCARRO inner join MARCA on MARCA.IDMARCA = TIPOCARRO.ID_MARCA;";
        if(!db.executeSelectQuery(select)) {
            std::string erro = "Falha ao executar consulta SELECT!";
            std::cerr << erro << std::endl;
            Acessibilidade::colocaTexto(erro);
        }
        std::cout << std::endl;
        std::string idPrompt = "Qual o ID do veículo a ser escolhido? \n";
        std::cout << idPrompt;
        Acessibilidade::colocaTexto(idPrompt);
        std::string setaPrompt = "-> ";
        std::cout << setaPrompt;
        Acessibilidade::colocaTexto(setaPrompt);
        std::string idVeiculo;
        std::cin >> idVeiculo;
        std::cout << std::endl;
        std::string dataPrompt = "Digite a data da manutençao: \n";
        std::cout << dataPrompt;
        Acessibilidade::colocaTexto(dataPrompt);
        std::cout << "-> ";
        Acessibilidade::colocaTexto(setaPrompt);
        std::string dataManutenao;
        std::cin.ignore();
        std::getline(std::cin, dataManutenao);

        std::string querry = "insert into MANUTENCAO (IDMANUTENCAO, dataManutencao, ID_CARRO) values (NULL, '" + dataManutenao + "', " + idVeiculo + ");";
        if (!db.executeQuery(querry)) {
            std::string erro = "Falha ao registrar manutencao!";
            std::cerr << erro << std::endl;
            Acessibilidade::colocaTexto(erro);
            return;
        }
        std::string ID_MANUTENCAO;
        std::string querryID_MANUTENCAO = "select IDMANUTENCAO from MANUTENCAO where ID_CARRO = " + idVeiculo + ";";
        db.getFirstColumnValue(querryID_MANUTENCAO, ID_MANUTENCAO);
        std::cout << std::endl;
        std::string mensagemPrompt = "Digite uma mensagem sobre a manutençao realizada: \n-> ";
        std::cout << mensagemPrompt;
        Acessibilidade::colocaTexto(mensagemPrompt);
        std::string mensagem;
        std::getline(std::cin, mensagem);
        std::string querry2 = "insert into MENSAGEM (IDMENSAGEM, conteudo, ID_MANUTENCAO) VALUES (NULL, '" + mensagem + "', " + ID_MANUTENCAO + ");";
        if (!db.executeQuery(querry2)) {
            std::string erro = "Falha ao registrar mensagem!";
            std::cerr << erro << std::endl;
            Acessibilidade::colocaTexto(erro);
            return;
        }
        else {
            std::string sucesso = "Mensagem registrada com sucesso!";
            std::cout << sucesso << std::endl;
            Acessibilidade::colocaTexto(sucesso);
        }
    }
    else {
        std::string erro = "Falha ao conectar ao banco de dados!";
        std::cerr << erro << std::endl;
        Acessibilidade::colocaTexto(erro);
        exit(1);
    }
}

void Banco::conferirManutencao() {
    if (conectaBD()) {
        std::string querry = "select MANUTENCAO.IDMANUTENCAO as 'ID DA MANUTENCAO', MANUTENCAO.dataManutencao as 'DATA DA MANUTENÇÃO' from MANUTENCAO;";
        if(!db.executeSelectQuery(querry)) {
            std::string erro = "Falha ao executar consulta SELECT!";
            std::cerr << erro << std::endl;
            Acessibilidade::colocaTexto(erro);
        }
        std::cout << std::endl;
        std::string idPrompt = "Qual o ID referente à data da manutençao desejada?\n-> ";
        std::cout << idPrompt;
        Acessibilidade::colocaTexto(idPrompt);
        std::string idManutencao;
        std::cin >> idManutencao;
        std::string ID_CARRO;
        std::string querryID_CARRO = "select ID_CARRO from MANUTENCAO where IDMANUTENCAO = " + idManutencao + ";";
        db.getFirstColumnValue(querryID_CARRO, ID_CARRO);
        std::cout << std::endl;
        std::string msgRef = "Mensagem referente: ";
        std::cout << msgRef;
        Acessibilidade::colocaTexto(msgRef);
        std::cout << std::endl;
        std::string placaRef = "Placa do veiculo referente: ";
        std::cout << placaRef;
        Acessibilidade::colocaTexto(placaRef);
        std::string querry3 = "select placa as PLACA_DO_VEICULO from CARRO where IDCARRO = " + ID_CARRO + ";";
        if(!db.executeSelectQuery(querry3)) {
            std::string erro = "Falha ao executar consulta SELECT!";
            std::cerr << erro << std::endl;
            Acessibilidade::colocaTexto(erro);
        }
        std::string querry2 = "select MENSAGEM.conteudo from MENSAGEM where ID_MANUTENCAO = " + idManutencao + ";";
        if(!db.executeSelectQuery(querry2)) {
            std::string erro = "Falha ao executar consulta SELECT!";
            std::cerr << erro << std::endl;
            Acessibilidade::colocaTexto(erro);
        }
    }
    else {
        std::string erro = "Falha ao conectar ao banco de dados!";
        std::cerr << erro << std::endl;
        Acessibilidade::colocaTexto(erro);
        exit(1);
    }
}

void Banco::removerRegistroManutencao() {
    if (conectaBD()) {
        std::string querry = "select MANUTENCAO.IDMANUTENCAO as 'ID DA MANUTENCAO', MANUTENCAO.dataManutencao as 'DATA DA MANUTENÇÃO' from MANUTENCAO;";
        if(!db.executeSelectQuery(querry)) {
            std::string erro = "Falha ao executar consulta SELECT!";
            std::cerr << erro << std::endl;
            Acessibilidade::colocaTexto(erro);
        }
        std::cout << std::endl;
        std::string idPrompt = "Qual o ID referente à data da manutençao que deseja apagar?\n-> ";
        std::cout << idPrompt;
        Acessibilidade::colocaTexto(idPrompt);
        std::string idManutencao;
        std::cin >> idManutencao;
        std::string querry1 = "delete from MANUTENCAO where IDMANUTENCAO = " + idManutencao + ";";
        std::string querry2 = "delete from MENSAGEM where ID_MANUTENCAO = " + idManutencao + ";";
        if (!db.executeQuery(querry1)) {
            std::string erro = "Falha ao remover manutençao!";
            std::cerr << erro << std::endl;
            Acessibilidade::colocaTexto(erro);
            return;
        }
        else {
            std::string sucesso = "Manutençao removida com sucesso! \n";
            std::cout << sucesso;
            Acessibilidade::colocaTexto(sucesso);
        }
        if (!db.executeSelectQuery(querry2)) {
            std::string erro = "Falha ao remover mensagem!";
            std::cerr << erro << std::endl;
            Acessibilidade::colocaTexto(erro);
            return;
        }
        else {
            std::string sucesso = "Mensagem removida com sucesso! \n";
            std::cout << sucesso;
            Acessibilidade::colocaTexto(sucesso);
        }
    }
    else {
        std::string erro = "Falha ao conectar ao banco de dados!";
        std::cerr << erro << std::endl;
        Acessibilidade::colocaTexto(erro);
        exit(1);
    }
}

void Banco::alterarManutencao() {
    if (conectaBD()) {
        std::string menu = "Escolha uma opção: \n(1)ALTERAR DATA DA MANUTENÇAO\n(2)ALTERAR MENSAGEM REFERENTE\n(3)ALTERAR VEICULO REFERENTE\n-> ";
        std::cout << menu;
        Acessibilidade::colocaTexto(menu);
        int opcao;
        testeEntrada(opcao, 3);
        if (opcao==1) {
            std::string querry = "select MANUTENCAO.IDMANUTENCAO as 'ID DA MANUTENCAO', MANUTENCAO.dataManutencao as 'DATA DA MANUTENÇÃO' from MANUTENCAO;";
            if(!db.executeSelectQuery(querry)) {
                std::string erro = "Falha ao executar consulta SELECT!";
                std::cerr << erro << std::endl;
                Acessibilidade::colocaTexto(erro);
            }
            std::cout << std::endl;
            std::string idPrompt = "Qual o ID referente à data da manutençao que deseja alterar?\n-> ";
            std::cout << idPrompt;
            Acessibilidade::colocaTexto(idPrompt);
            std::string idManutencao;
            std::cin >> idManutencao;
            std::cout << std::endl;
            std::string dataPrompt = "Digite a nova data da manutencao:\n-> ";
            std::cout << dataPrompt;
            Acessibilidade::colocaTexto(dataPrompt);
            std::string novaData;
            std::cin.ignore();
            std::getline(std::cin, novaData);
            std::string q1 = "update MANUTENCAO set dataManutencao = '" + novaData + "' where IDMANUTENCAO = " + idManutencao + ";";
            if (!db.executeQuery(q1)) {
                std::string erro = "Falha ao alterar data da manutençao!";
                std::cerr << erro << std::endl;
                Acessibilidade::colocaTexto(erro);
                return;
            }
            else {
                std::string sucesso = "Manutençao alterada com sucesso! \n";
                std::cout << sucesso;
                Acessibilidade::colocaTexto(sucesso);
            }
        }
        else if (opcao==2) {
            std::string querry = "select MANUTENCAO.IDMANUTENCAO as 'ID DA MANUTENCAO', MANUTENCAO.dataManutencao as 'DATA DA MANUTENÇÃO' from MANUTENCAO;";
            if(!db.executeSelectQuery(querry)) {
                std::string erro = "Falha ao executar consulta SELECT!";
                std::cerr << erro << std::endl;
                Acessibilidade::colocaTexto(erro);
            }
            std::cout << std::endl;
            std::string idPrompt = "Qual o ID referente à data da manutençao que deseja alterar?\n-> ";
            std::cout << idPrompt;
            Acessibilidade::colocaTexto(idPrompt);
            std::string idManutencao;
            std::cin >> idManutencao;
            std::cout << std::endl;
            std::string msgPrompt = "Digite a nova mensagem: \n";
            std::cout << msgPrompt;
            Acessibilidade::colocaTexto(msgPrompt);
            std::string mensagem;
            std::cin.ignore();
            std::getline(std::cin, mensagem);
            std::string q1 = "update MENSAGEM set conteudo = '" + mensagem + "' where ID_MANUTENCAO = " + idManutencao + ";";
            if (!db.executeQuery(q1)) {
                std::string erro = "Falha ao alterar mensagem da manutençao!";
                std::cerr << erro << std::endl;
                Acessibilidade::colocaTexto(erro);
                return;
            }
            else {
                std::string sucesso = "Mensagem alterada com sucesso!";
                std::cout << sucesso;
                Acessibilidade::colocaTexto(sucesso);
            }
        }
        else if (opcao==3) {
            std::string querry = "select MANUTENCAO.IDMANUTENCAO as 'ID DA MANUTENCAO', MANUTENCAO.dataManutencao as 'DATA DA MANUTENÇÃO' from MANUTENCAO;";
            if(!db.executeSelectQuery(querry)) {
                std::string erro = "Falha ao executar consulta SELECT!";
                std::cerr << erro << std::endl;
                Acessibilidade::colocaTexto(erro);
            }
            std::cout << std::endl;
            std::string idPrompt = "Qual o ID referente à data da manutençao que deseja alterar?\n-> ";
            std::cout << idPrompt;
            Acessibilidade::colocaTexto(idPrompt);
            std::string idManutencao;
            std::cin >> idManutencao;
            std::cout << std::endl;
            std::string select = "SELECT CARRO.IDCARRO AS ID_VEICULO, TIPOCARRO.nome AS NOME_VEICULO, MARCA.nome AS MARCA_VEICULO, CARRO.placa AS PLACA_VEICULO, TIPOCARRO.funcao AS FUNCAO_VEICULO FROM CARRO INNER JOIN TIPOCARRO on TIPOCARRO.IDTIPOCARRO = CARRO.ID_TIPOCARRO inner join MARCA on MARCA.IDMARCA = TIPOCARRO.ID_MARCA;";
            if(!db.executeSelectQuery(select)) {
                std::string erro = "Falha ao executar consulta SELECT!";
                std::cerr << erro << std::endl;
                Acessibilidade::colocaTexto(erro);
            }
            std::cout << std::endl;
            std::string idPrompt1 = "Qual o ID do novo veículo a ser escolhido? \n";
            std::cout << idPrompt1;
            Acessibilidade::colocaTexto(idPrompt1);
            std::string setaPrompt = "-> ";
            std::cout << setaPrompt;
            Acessibilidade::colocaTexto(setaPrompt);
            std::string idVeiculo;
            std::cin >> idVeiculo;
            std::cout << std::endl;
            std::string s = "update MANUTENCAO set ID_CARRO = " + idVeiculo + " where IDMANUTENCAO = " + idManutencao + ";";
            if (!db.executeQuery(s)) {
                std::string erro = "Falha ao alterar veiculo da manutençao!";
                std::cerr << erro << std::endl;
                Acessibilidade::colocaTexto(erro);
                return;
            }
            else {
                std::string sucesso = "veiculo alterado com sucesso!";
                std::cout << sucesso;
                Acessibilidade::colocaTexto(sucesso);
            }
        }
    }
    else {
        std::string erro = "Falha ao conectar ao banco de dados!";
        std::cerr << erro << std::endl;
        Acessibilidade::colocaTexto(erro);
        exit(1);
    }
}




