#pragma once
#include<string>

class User final {
public:
    User(const std::string& login, const std::string& password, const std::string& name);

    const std::string getLogin() const noexcept;

    void setPassword(const std::string& pass) noexcept;
    const std::string& getPassword() const noexcept;

    void setName(const std::string& name) noexcept;
    const std::string& getName() const noexcept;

private:
    std::string _login;
    std::string _password;
    std::string _name;
};
