#include"Chat.hpp"

void Chat::mainMenu() {

    char operation;

    do {
        setMenuItems("Главное меню",
            "(1)Регистация",
            "(2)Авторизация",
            "(3)Выход из программы");

        std::cin >> operation;

        switch (operation) {
        case '1':
            try {
                signUp();
            }
            catch (const std::exception& ex) {
                std::cout << ex.what() << '\n';
            }
            break;
        case '2':
            try {
                authorization();
            }
            catch (const std::exception& ex) {
                std::cout << ex.what() << '\n';
            }
            break;
        case '3':
            _chatGo = false;
            break;
        default:
            std::cout << "Выбор операции не известен\n";
        }
    } while (!_currentUser && _chatGo);
}

void Chat::signUp() {
    std::string login, password, name;

    std::cout << "Введите логин: ";
    std::cin >> login;
    std::cout << "Введите пароль: ";
    std::cin >> password;
    std::cout << "Введите имя: ";
    std::cin >> name;

    if (isLogin(login) || login == "all") {
        throw Login_busy();
    }

    User user(login, password, name);
    _listOfUsers.push_back(user);
    _currentUser = std::make_shared<User>(user);
    std::cout << "Здравствуйте " << _currentUser->getName() << ", спасибо за регистрацию.\n";
}

const bool Chat::isLogin(const std::string& login) const noexcept {
    for (const auto& user : _listOfUsers) {
        if (user.getLogin() == login) { return true; }
    }
    return false;
}

void Chat::authorization() {
    std::string login, password;

    std::cout << "Введите логин: ";
    std::cin >> login;
    std::cout << "Введите пароль: ";
    std::cin >> password;

    if (!isValidLoginPassword(login, password)) {
        throw Incorrect_Login_Or_Password();
    }
}

const bool Chat::isValidLoginPassword(const std::string& login, const std::string& password) noexcept {
    for (auto user : _listOfUsers) {
        if (user.getLogin() == login && user.getPassword() == password) {
            _currentUser = std::make_shared<User>(user);
            return true;
        }
    }
    return false;
}

const bool Chat::getChatGo() const noexcept {
    return _chatGo;
}

const std::shared_ptr<User> Chat::getCurrentUser() const noexcept {
    return _currentUser;
}

void Chat::userMenu() {

    char operation;

    do {
        setMenuItems("Пользавательское меню",
            "(1)Отправить сообщение",
            "(2)Прочитать сообщения",
            "(3)Выход из чата",
            "(4)Удалить аккаунт");
        std::cout << ">> Пользователь " << _currentUser->getLogin() << " << >> ";
        std::cin >> operation;

        switch (operation) {
        case '1':
            try {
                sendMessage();
            }
            catch (const std::exception& ex) {
                std::cout << ex.what() << '\n';
            }
            break;
        case '2':
            try {
                showMessage();
            }
            catch (const std::exception& ex) {
                std::cout << ex.what() << '\n';
            }
            break;
        case '3':
            _currentUser = nullptr;
            break;
        case '4':
            deleteUser();
            break;
        default:
            std::cout << "Выбор операции не известен\n";
        }

    } while (_currentUser);
}

void Chat::sendMessage() {
    std::string to, text;

    std::cout << "Кому (логин или all) ";
    std::cin >> to;
    std::cout << "Текст сообщения: ";
    std::cin.ignore();
    std::getline(std::cin, text);

    if (!(to == "all" || isLogin(to))) { throw LoginNotFound(); }
    if (to == "all") {
        _messages.push_back(Message{ _currentUser->getLogin(), "all", text });
    }
    else {
        _messages.push_back(Message{ _currentUser->getLogin(), to, text });
    }
}

void Chat::showMessage() const noexcept {
    std::cout << std::string(5, '-') << " Chat start " << std::string(5, '-') << '\n';
    for (const auto& message : _messages) {
        if (message.getTo() == _currentUser->getLogin()) { std::cout << "(private)-> " << message.getText() << '\n'; }
        else if (message.getTo() == "all") { std::cout << "(pablic)-> " << message.getText() << '\n'; }
    }
    std::cout << std::string(5, '-') << " Chat stop " << std::string(5, '-') << '\n';
}

void Chat::deleteUser() noexcept {
    for (int i{ 0 }; i < _listOfUsers.size(); ++i) {
        if (_listOfUsers[i].getLogin() == _currentUser->getLogin()) {
            _listOfUsers.erase(_listOfUsers.begin() + i);
            _currentUser = nullptr;
            break;
        }
    }
}