-- Seleciona o banco (já criado pelo compose)
USE login_system;

-- Concede permissão total ao root para conexões de outros containers Docker
GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' IDENTIFIED BY 'Xzone123' WITH GRANT OPTION;

-- Atualiza privilégios imediatamente
FLUSH PRIVILEGES;

-- Confirma que a tabela users foi criada
CREATE TABLE IF NOT EXISTS users (
    id VARCHAR(36) PRIMARY KEY,
    name VARCHAR(50) NOT NULL,
    email VARCHAR(100) NOT NULL,
    password VARCHAR(100) NOT NULL
);
