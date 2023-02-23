#pragma once
#include<vector>
#include<iostream>
#include"User.hpp"
#include"Error.hpp"
#include "Message.hpp"

class Chat final {
public:
    void mainMenu() throw();
    void userMenu() throw();

    const bool& getChatGo() const noexcept;
    const std::shared_ptr<User> getCurrentUser() const noexcept;
private:
    std::vector<User> _listOfUsers;
    std::vector<Message> _messages;
    std::shared_ptr<User> _currentUser{ nullptr };
    bool _chatGo{ true };

    void signUp() throw();
    const bool& isLogin(const std::string& login) const noexcept;
    void authorization() throw();
    const bool& isValidLoginPassword(const std::string& login, const std::string& password) noexcept;
    void deleteUser() noexcept;

    void sendMessage() throw();
    void showMessage() const noexcept;

    void setMenuItems() const noexcept { std::cout << '\n'; }
    template<typename Arg, typename ... Args>
    void setMenuItems(const Arg& arg, const Args&... args) const noexcept {
        std::cout << std::string(2, '-') << ' ' << arg << ' ';
        setMenuItems(args...);
    }
};