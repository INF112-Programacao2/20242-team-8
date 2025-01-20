//
// Created by viniciuskl on 05/01/25.
//

#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H

#include <sqlite3.h> // Inclusão da biblioteca SQLite3
#include <string>
    // Classe para gerenciar conexões com banco de dados SQLite
    class DatabaseConnection {
    private:
        sqlite3* db;              // Ponteiro para o objeto de conexão SQLite
        std::string dbPath;       // Caminho do arquivo do banco de dados
        bool isConnected;         // Flag para controlar o estado da conexão

    public:
        // Construtor que recebe o caminho do banco de dados
        explicit DatabaseConnection(const std::string& path);

        // Método para estabelecer conexão com o banco de dados
        bool connect();

        // Método para executar queries SQL
        bool executeQuery(const std::string& query);

        // Método para verificar se a conexão está ativa
        bool isConnectionActive() const { return isConnected; }

        // Destrutor para limpar recursos
        ~DatabaseConnection();
    };

#endif //DATABASECONNECTION_H
