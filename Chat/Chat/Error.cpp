#include"Error.hpp"

const char* Login_busy::what() const noexcept {
    return "\x1b[31mLogin_busy: Введенный вами логин занят\x1b[0m";
}

const char* Incorrect_Login_Or_Password::what() const noexcept {
    return "\x1b[31mIncorrect_Login_Or_Password: Неверный логин или пароль. Повторите попытку.\x1b[0m";
}

const char* LoginNotFound::what() const noexcept {
    return "\x1b[31mLoginNotFound: Логин не найден\x1b[0m";
}