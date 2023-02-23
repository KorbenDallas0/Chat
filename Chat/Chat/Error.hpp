#pragma once
#include<exception>

class Login_busy final : public std::exception {
public:
    const char* what() const noexcept override;
};

class Incorrect_Login_Or_Password final : public std::exception {
public:
    const char* what() const noexcept override;
};

class LoginNotFound final : public std::exception {
public:
    const char* what() const noexcept override;
};