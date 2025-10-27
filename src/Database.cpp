#include "Database.h"        
#include <iostream>          

Database* Database::instance = nullptr; 

Database::Database() {
    conn = mysql_init(nullptr);                           
    if (!conn) {                                          
        std::cerr << "Erro ao inicializar MySQL.\n";
        std::exit(1);                                    
    }

    if (!mysql_real_connect(conn,
                            "your id mysql",               
                            "root",                       
                            "your password",                   
                            "your database",               
                            "your port (remove " ")",                         
                            nullptr,                     
                            0)) {                         
        std::cerr << "Erro de conexão: " << mysql_error(conn) << "\n";
        std::exit(1);
    }
}

Database::~Database() {
    if (conn) mysql_close(conn);    
}

Database* Database::getInstance() {
    if (!instance) {                
        instance = new Database();
    }
    return instance;                
}

MYSQL* Database::getConnection() {
    return conn;                   
}
