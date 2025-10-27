#include "User.h"

User::User(std::string id, std::string name, std::string email, std::string password)
    : id(id), name(name), email(email), password(password) {}

std::string User::getId() const { return id; }
std::string User::getName() const { return name; }
std::string User::getEmail() const { return email; }
std::string User::getPassword() const { return password; }

void User::setName(std::string n) { name = n; }
void User::setEmail(std::string e) { email = e; }
void User::setPassword(std::string p) { password = p; }
