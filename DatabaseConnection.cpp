#include "DatabaseConnection.h"
#include <iostream>
#include <iomanip>

// Construtor: inicializa os membros da classe
// path: caminho do arquivo do banco de dados
DatabaseConnection::DatabaseConnection(const std::string& path) :
    db(nullptr),           // Inicializa ponteiro como nulo
    dbPath(path),          // Armazena o caminho do banco
    isConnected(false) {}  // Inicializa estado da conexão como falso

// Estabelece conexão com o banco de dados
// Retorna: true se conectou com sucesso, false caso contrário
bool DatabaseConnection::connect() {
    // Verifica se já existe uma conexão ativa
    if (isConnected) {
        return true;
    }

    // Tenta abrir/criar o banco de dados
    // sqlite3_open retorna SQLITE_OK (0) em caso de sucesso
    int result = sqlite3_open(dbPath.c_str(), &db);

    // Verifica se houve erro na abertura do banco
    if (result != SQLITE_OK) {
        std::cerr << "Erro ao abrir o banco de dados: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);  // Fecha conexão em caso de erro
        db = nullptr;       // Reseta o ponteiro
        isConnected = false;
        return false;
    }

    // Marca conexão como estabelecida e retorna sucesso
    isConnected = true;
    std::cout << "Conexão com o banco de dados estabelecida com sucesso!" << std::endl;
    return true;
}

// Executa uma query SQL no banco de dados
// query: string contendo o comando SQL a ser executado
// Retorna: true se a query foi executada com sucesso, false caso contrário
bool DatabaseConnection::executeQuery(const std::string& query) {
    // Verifica se existe uma conexão ativa
    if (!isConnected || db == nullptr) {
        std::cerr << "Erro: Não há conexão ativa com o banco de dados!" << std::endl;
        return false;
    }

    // Ponteiro para mensagem de erro
    char* errorMessage = nullptr;

    // Executa a query
    // sqlite3_exec retorna SQLITE_OK (0) em caso de sucesso
    int result = sqlite3_exec(db, query.c_str(), nullptr, nullptr, &errorMessage);

    // Verifica se houve erro na execução
    if (result != SQLITE_OK) {
        std::cerr << "Erro na execução da query: "
                  << (errorMessage ? errorMessage : "Erro desconhecido") << std::endl;
        // Libera memória da mensagem de erro se existir
        if (errorMessage) {
            sqlite3_free(errorMessage);
        }
        return false;
    }
    return true;
}

int DatabaseConnection::callback_select(void* data, int argc, char** argv, char** azColName) {
    // Imprime os cabeçalhos das colunas, se esta for a primeira linha
    static bool printHeaders = true;
    if (printHeaders) {
        for (int i = 0; i < argc; i++) {
            std::cout << std::left << std::setw(20) << azColName[i];
        }
        std::cout << std::endl;
        printHeaders = false;
    }

    // Imprime os dados da linha
    for (int i = 0; i < argc; i++) {
        std::cout << std::left << std::setw(20) << (argv[i] ? argv[i] : "NULL");
    }
    std::cout << std::endl;

    return 0;
}

bool DatabaseConnection::executeSelectQuery(const std::string& query) {
    // Verifica se existe uma conexão ativa
    if (!isConnected || db == nullptr) {
        std::cerr << "Erro: Não há conexão ativa com o banco de dados!" << std::endl;
        return false;
    }

    // Ponteiro para mensagem de erro
    char* errorMessage = nullptr;

    // Executa a query SELECT
    int result = sqlite3_exec(db, query.c_str(), callback_select, nullptr, &errorMessage);

    // Verifica se houve erro na execução
    if (result != SQLITE_OK) {
        std::cerr << "Erro na execução da query: "
                  << (errorMessage ? errorMessage : "Erro desconhecido") << std::endl;
        // Libera memória da mensagem de erro se existir
        if (errorMessage) {
            sqlite3_free(errorMessage);
        }
        return false;
    }
    return true;
}

static std::string retrievedValue;

int DatabaseConnection::callback_getid(void* data, int argc, char** argv, char** azColName) {
    // guarda o valor da primeira coluna
    if (argc > 0 && argv[0]) {
        retrievedValue = argv[0];
    }
    return 0;
}

bool DatabaseConnection::getFirstColumnValue(const std::string& query, std::string& result) {
    retrievedValue.clear();

    char* errorMessage = nullptr;
    int queryResult = sqlite3_exec(db, query.c_str(), callback_getid, nullptr, &errorMessage);

    if (queryResult != SQLITE_OK) {
        std::cerr << "Erro na execução da query: "
                  << (errorMessage ? errorMessage : "Erro desconhecido") << std::endl;
        if (errorMessage) sqlite3_free(errorMessage);
        return false;
    }

    result = retrievedValue;
    return !retrievedValue.empty();
}


// Destrutor: limpa recursos quando o objeto é destruído
DatabaseConnection::~DatabaseConnection() {
    // Verifica se existe uma conexão para fechar
    if (db) {
        sqlite3_close(db);  // Fecha a conexão com o banco
        std::cout << "Conexão com o banco de dados fechada." << std::endl;
    }
}
