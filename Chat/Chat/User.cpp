#include"User.hpp"

User::User(const std::string& login, const std::string& password, const std::string& name)
    : _login{ login }, _password{ password }, _name{ name } {}

const std::string User::getLogin() const noexcept { return _login; }

void User::setPassword(const std::string& pass) noexcept { _password = pass; }
const std::string& User::getPassword() const noexcept { return _password; }

void User::setName(const std::string& name) noexcept { _name = name; }
const std::string& User::getName() const noexcept { return _name; }