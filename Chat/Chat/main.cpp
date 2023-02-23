#include"Chat.hpp"
#include <Windows.h>

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Chat chat;

    while (chat.getChatGo()) {

        chat.mainMenu();

        while (chat.getCurrentUser()) {
            chat.userMenu();
        }
    }
}