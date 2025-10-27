#pragma once
#include "User.h"
#include "Database.h"
#include <vector>
#include <string>

class UserDAO {
public:
    void create(const User& user);             
    std::vector<User> readAll();               
    void update(const User& user);             
    void remove(const std::string& id);       
};
