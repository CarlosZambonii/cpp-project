#include "UserDAO.h"
#include <iostream>
#include <memory>       
#include <cassert>
#include <random>
#include <sstream>
#include <iomanip>

static auto generate_uuid = []() -> std::string {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 15);
    std::uniform_int_distribution<> dis2(8, 11);

    std::stringstream ss;
    ss << std::hex << std::nouppercase;
    for (int i = 0; i < 8; i++) ss << dis(gen);
    ss << "-";
    for (int i = 0; i < 4; i++) ss << dis(gen);
    ss << "-4"; 
    for (int i = 0; i < 3; i++) ss << dis(gen);
    ss << "-";
    ss << dis2(gen); 
    for (int i = 0; i < 3; i++) ss << dis(gen);
    ss << "-";
    for (int i = 0; i < 12; i++) ss << dis(gen);
    return ss.str();
};

void UserDAO::create(const User& user) {
    MYSQL* conn = Database::getInstance()->getConnection();

    auto esc = [conn](const std::string& s) {
        std::string out;
        out.resize(s.size() * 2 + 1);
        unsigned long len = mysql_real_escape_string(conn, out.data(), s.c_str(),
                                                     static_cast<unsigned long>(s.size()));
        out.resize(len);
        return out;
    };

    std::string id = generate_uuid(); 
    std::string q = "INSERT INTO users (id, name, email, password) VALUES ('" +
                    id + "', '" +
                    esc(user.getName()) + "', '" +
                    esc(user.getEmail()) + "', '" +
                    esc(user.getPassword()) + "')";

    if (mysql_query(conn, q.c_str())) {
        std::cerr << "Erro ao inserir usuário: " << mysql_error(conn) << "\n";
    } else {
        std::cout << "Usuário cadastrado com sucesso! (UUID: " << id << ")\n";
    }
}

std::vector<User> UserDAO::readAll() {
    MYSQL* conn = Database::getInstance()->getConnection();
    std::vector<User> users;

    if (mysql_query(conn, "SELECT id, name, email, password FROM users")) {
        std::cerr << "Erro ao listar usuários: " << mysql_error(conn) << "\n";
        return users;
    }

    auto res_deleter = [](MYSQL_RES* r) { if (r) mysql_free_result(r); };
    std::unique_ptr<MYSQL_RES, decltype(res_deleter)>
        res(mysql_store_result(conn), res_deleter);

    if (!res) return users;

    MYSQL_ROW row;
    while ((row = mysql_fetch_row(res.get()))) {
        users.emplace_back(User(row[0], row[1], row[2], row[3]));
    }

    return users;
}

void UserDAO::update(const User& user) {
    MYSQL* conn = Database::getInstance()->getConnection();

    auto esc = [conn](const std::string& s) {
        std::string out;
        out.resize(s.size() * 2 + 1);
        unsigned long len = mysql_real_escape_string(conn, out.data(), s.c_str(),
                                                     static_cast<unsigned long>(s.size()));
        out.resize(len);
        return out;
    };

    std::string q = "UPDATE users SET name='" + esc(user.getName()) +
                    "', email='" + esc(user.getEmail()) +
                    "', password='" + esc(user.getPassword()) +
                    "' WHERE id='" + user.getId() + "'";

    if (mysql_query(conn, q.c_str())) {
        std::cerr << "Erro ao atualizar usuário: " << mysql_error(conn) << "\n";
    } else {
        std::cout << "Usuário atualizado com sucesso!\n";
    }
}

void UserDAO::remove(const std::string& id) {
    MYSQL* conn = Database::getInstance()->getConnection();
    std::string q = std::string("DELETE FROM users WHERE id='") + id + "'";
    if (mysql_query(conn, q.c_str())) {
        std::cerr << "Erro ao deletar usuário: " << mysql_error(conn) << "\n";
    } else {
        std::cout << "Usuário removido com sucesso!\n";
    }
}