#include "Database.h"
#include <iostream>
#include <cstdlib> // getenv

Database* Database::instance = nullptr;

Database::Database() {
    conn = mysql_init(nullptr);
    if (!conn) {
        std::cerr << "Erro ao inicializar MySQL\n";
        exit(1);
    }

    // ✅ Força o MySQL a usar TCP e não socket local
    mysql_options(conn, MYSQL_OPT_USE_REMOTE_CONNECTION, nullptr);

    const char* host = getenv("DB_HOST");
    const char* user = getenv("DB_USER");
    const char* pass = getenv("DB_PASS");
    const char* db   = getenv("DB_NAME");
    const char* portStr = getenv("DB_PORT");

    if (!host || !user || !pass || !db || !portStr) {
        std::cerr << "❌ Variáveis de ambiente do DB não configuradas!\n";
        exit(1);
    }

    int port = std::stoi(portStr);

    if (!mysql_real_connect(conn, host, user, pass, db, port, nullptr, 0)) {
        std::cerr << "❌ Erro de conexão: " << mysql_error(conn) << "\n";
        exit(1);
    }

    std::cout << "✅ Conectado ao banco via TCP!\n";
}

Database::~Database() {
    if (conn) mysql_close(conn);
}

Database* Database::getInstance() {
    if (!instance) instance = new Database();
    return instance;
}

MYSQL* Database::getConnection() {
    return conn;
}
