#include <chrono>
#include <iostream>
#include <thread>
#include "../include/DatabaseConnection.h"
#include "../include/KeyboardInput.h"
#include "../include/Produto.h"
#include "../include/TextToVoice.h"
#include "../include/Banco.h"
#include "../include/Execucao.h"
#include "../include/Acessibilidade.h"

/*
void detectarTeclas() {
    KeyboardInput kb;
    std::cout << "Pressione teclas (ESC para sair)...\n";

    while(true) {
        if (kb.kbhit()) {
            int tecla = kb.getch();
            if (tecla != -1) {
                std::cout << "Tecla pressionada: " << kb.getTeclaDescricao(tecla) << std::endl;

                if (tecla == 27) {  // ESC
                    std::cout << "Programa encerrado!\n";
                    break;
                }
            }
        }
        // Pequena pausa para reduzir uso de CPU
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}
*/

int main() {
    char acessbilidade;
    bool resp=false;
    std::cout << "Deseja utilizar a acessibilidade de voz (s/n) ?";
    std::cin >>  acessbilidade;
    if (acessbilidade == 's') {
        resp = true;
    }
    if (acessbilidade == 'n') {
        resp = false;
    }
    std::cin.ignore();

    Acessibilidade::setAciona(resp);
    Execucao::telaInicial();
    //Banco::adicionarProdutoExistente();
    //Banco::conferirEstoque();
    //Banco::removerProduto();
    //Banco::alterarDadosProduto();
    //Banco::adicionarVeiculo();
    //Banco::conferirVeiculoCadastrado();
    //Banco::removerVeiculo();
    //Banco::modificarDadosVeiculo();
    //Banco::adicionarManutencao();
    //Banco::conferirManutencao();
    //Banco::removerRegistroManutencao();
    //Banco::alterarManutencao();
    //Produto p("Jorge e matheus", 42, "Cristiano Araujo", "220222", 75.4);

    /*
    // Cria objeto de conexão com o banco
    DatabaseConnection db("DATABASE.sqlite");
    
    // Tenta estabelecer conexão com o banco
    if (!db.connect()) {
        std::cerr << "Falha ao conectar ao banco de dados!" << std::endl;
        return 1;  // Retorna código de erro
    }


/*
    // Define query SQL para criar tabela de usuários
    std::string createTable = "CREATE TABLE IF NOT EXISTS usuarios ("
                            "id INTEGER PRIMARY KEY AUTOINCREMENT,"  // ID auto incrementável
                            "nome TEXT NOT NULL,"                    // Nome (não pode ser nulo)
                            "idade INTEGER);";                       // Idade

    // Tenta criar a tabela
    if (db.executeQuery(createTable)) {
        std::cout << "Tabela criada com sucesso!" << std::endl;
        
        // Se a tabela foi criada com sucesso, tenta inserir dados
        std::string insertData = "INSERT INTO usuarios (nome, idade) VALUES ('João', 25);";
        if (db.executeQuery(insertData)) {
            std::cout << "Dados inseridos com sucesso!" << std::endl;
        }
    }

    std::string apagaTabela = "DROP TABLE IF EXISTS usuarios";
    if (db.executeQuery(apagaTabela)) {
        std::cout << "Tabela apagada com sucesso!" << std::endl;
    }

    p.obterDados();
    std::cout << std::endl;
    p.defineTipo();
    std::cout << std::endl;
    std::cout << p.getTipo();
    std::cout << std::endl;
/*
    // Define a mensagem que será lida em voz alta
    const std::string message = "A seguir, um comando pedirá para que teclas sejam pressionadas. Pressione-as!";

    // Chama a função que converte o texto em fala
    TextToVoice::speak(message);

    detectarTeclas();
*/
    //const std::string message = "(1) - alterar dados do veículo: ";

    // Chama a função que converte o texto em fala
    //TextToVoice::speak(message);
    return 0;
}
