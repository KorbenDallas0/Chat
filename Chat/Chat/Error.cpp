#include"Error.hpp"

const char* Login_busy::what() const noexcept {
    return "\x1b[31mLogin_busy: ��������� ���� ����� �����\x1b[0m";
}

const char* Incorrect_Login_Or_Password::what() const noexcept {
    return "\x1b[31mIncorrect_Login_Or_Password: �������� ����� ��� ������. ��������� �������.\x1b[0m";
}

const char* LoginNotFound::what() const noexcept {
    return "\x1b[31mLoginNotFound: ����� �� ������\x1b[0m";
}