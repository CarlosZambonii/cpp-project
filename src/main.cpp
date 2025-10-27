#include "UserDAO.h"
#include <iostream>
#include <limits>
#include <chrono>
#include <ctime>
#include <iomanip>

auto writeLog = [](const std::string& msg) {
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    std::tm* tm = std::localtime(&t);
    std::cout << "[" << std::put_time(tm, "%Y-%m-%d %H:%M:%S") << "] "
              << msg << std::endl;
};

static std::string readLine(const char* label) {
    std::cout << label;
    std::string s;
    std::getline(std::cin, s);
    return s;
}

int main() {
    UserDAO dao;
    std::vector<User> users; 

    int opcao = -1;

    do {
        std::cout << "\n===== MENU =====\n"
                  << "1. Criar usuário\n"
                  << "2. Listar usuários\n"
                  << "3. Atualizar usuário (por número)\n"
                  << "4. Remover usuário (por número)\n"
                  << "0. Sair\n> ";

        if (!(std::cin >> opcao)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada inválida.\n";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (opcao == 1) {
            std::string nome = readLine("Nome: ");
            std::string email = readLine("Email: ");
            std::string senha = readLine("Senha: ");
            dao.create(User("0", nome, email, senha));
            writeLog("Usuário criado: " + nome + " <" + email + ">");
        }

        else if (opcao == 2) {
            users = dao.readAll();
            std::cout << "\n--- USUÁRIOS ---\n";
            int i = 1;
            for (const auto& u : users) {
                std::cout << i++ << ". Nome: " << u.getName()
                          << " | Email: " << u.getEmail()
                          << " | UUID: " << u.getId() << "\n";
            }
            if (users.empty()) std::cout << "(vazio)\n";
            writeLog(std::to_string(users.size()) + " usuários listados");
        }

        else if (opcao == 3) {
            if (users.empty()) {
                std::cout << "Liste os usuários primeiro (opção 2).\n";
                continue;
            }
            int idx;
            std::cout << "Número do usuário a atualizar: ";
            std::cin >> idx;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (idx < 1 || idx > users.size()) {
                std::cout << "Número inválido.\n";
                continue;
            }

            User user = users[idx - 1];
            std::string nome = readLine("Novo nome: ");
            std::string email = readLine("Novo email: ");
            std::string senha = readLine("Nova senha: ");

            user.setName(nome);
            user.setEmail(email);
            user.setPassword(senha);

            dao.update(user);
            writeLog("Usuário atualizado: " + user.getId());
        }

        else if (opcao == 4) {
            if (users.empty()) {
                std::cout << "Liste os usuários primeiro (opção 2).\n";
                continue;
            }
            int idx;
            std::cout << "Número do usuário a remover: ";
            std::cin >> idx;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (idx < 1 || idx > users.size()) {
                std::cout << "Número inválido.\n";
                continue;
            }

            dao.remove(users[idx - 1].getId());
            writeLog("Usuário removido: " + users[idx - 1].getId());
        }

        else if (opcao == 0) {
            writeLog("Encerrando o programa.");
        }

        else {
            std::cout << "Opção inválida.\n";
            writeLog("Tentativa de opção inválida: " + std::to_string(opcao));
        }

    } while (opcao != 0);

    return 0;
}
