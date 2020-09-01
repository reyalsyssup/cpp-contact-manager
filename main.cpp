#include <iostream>
#include <string>
#include <regex>

const std::regex emailPattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

void toLowercase(std::string &string, int length) {
    for(int i = 0; i < length; i++) {
        string[i] = tolower(string[i]);
    }
}

void getEmail(std::string &email) {
    std::cout << "Enter new contact's email > ";
    std::cin >> email;
    // check new contact's email using regex
    if(!std::regex_match(email, emailPattern)) {
        std::cout << "Invalid Email Format" << std::endl;
        getEmail(email);
    }
    toLowercase(email, email.length());
}

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
            std::cout << "To leave a field blank, type: null\n";
            std::cout << "First name of new contact > ";
            std::cin >> firstName;
            std::cout << "Last name of new contact > ";
            std::cin >> lastName;
            getEmail(email);
            std::cout << "Phone number of new contact > ";
            std::cin >> phoneNum;
            
            toLowercase(firstName, firstName.length());
            toLowercase(lastName, lastName.length());

            std::cout << firstName;
            return 0;
        }
    }
}