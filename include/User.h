#pragma once
#include <string>

class User {
private:
    std::string id;     
    std::string name;
    std::string email;
    std::string password;

public:
    User(std::string id, std::string name, std::string email, std::string password);

    std::string getId() const;
    std::string getName() const;
    std::string getEmail() const;
    std::string getPassword() const;

    void setName(std::string name);
    void setEmail(std::string email);
    void setPassword(std::string password);
};
