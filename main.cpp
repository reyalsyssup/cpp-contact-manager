#include <iostream>

int main() {
    std::cout << "========== Console Manager ==========" << std::endl;
    while(true) {
        std::cout << "What would you like to do? [new|find] > ";
        std::string option;
        std::cin >> option;
        if(option == "new") {
            std::string firstName;
            std::string lastName;
            std::string email;
            std::string phoneNum;
            std::cout << "First name of new contact > ";
            std:: cin >> firstName;
        }
    }
}