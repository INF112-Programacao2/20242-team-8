#include <iostream>
#include "DatabaseConnection.h"
int main() {
    // Cria objeto de conexão com o banco
    DatabaseConnection db("DATABASE.sqlite");
    
    // Tenta estabelecer conexão com o banco
    if (!db.connect()) {
        std::cerr << "Falha ao conectar ao banco de dados!" << std::endl;
        return 1;  // Retorna código de erro
    }

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

    return 0;  // Retorna sucesso
}