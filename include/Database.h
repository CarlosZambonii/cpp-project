#pragma once                 
#include <mysql.h>        
#include <string>            

class Database {
private:
    MYSQL* conn;           
    static Database* instance; 

    Database();              
    ~Database();             

public:
    static Database* getInstance(); 
    MYSQL* getConnection();         
};
