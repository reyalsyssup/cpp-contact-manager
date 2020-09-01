#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <vector>

const std::regex emailPattern("^([a-zA-Z0-9_\\-\\.]+)@([a-zA-Z0-9_\\-\\.]+)\\.([a-zA-Z]{2,5})$");

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
            std::string fullName, email, phoneNum;
            std::cout << "To leave a field blank, type: null\n";
            std::cout << "Full name of new contact > ";
            // using cin.ignore() to ignore the newline created by the previous input
            std::cin.ignore();
            std::getline(std::cin, fullName);
            getEmail(email);
            // wont check phone number format using regex due to different countries having different formats for phone numbers
            std::cout << "Phone number of new contact > ";
            std::cin >> phoneNum;
            toLowercase(fullName, fullName.length());
            
            // write new contact to contacts file
            std::ofstream file("contacts.txt", std::ios::app);
            if(!file.is_open()) {
                std::cout << "Failed to write new contact to save file\n";
                break;
            }
            file << fullName << std::endl;
            file << email << std::endl;
            file << phoneNum << std::endl;
            file << std::endl;
        } else if(option == "find") {
            std::vector<std::string> lines;
            std::string line;
            std::ifstream file("contacts.txt");
            while(getline(file, line)) {
                lines.push_back(line);
            }
            std::string option;
            std::cout << "Search by name, email, or phone number? [name|email|phone] > ";
            std::cin >> option;
            if(option == "name") {
                std::string name;
                std::cout << "Enter the name to be searched > ";
                std::cin.ignore();
                std::getline(std::cin, name);
                // skip every 4 lines to get name of contact
                for(int i = 0; i < lines.size(); i += 4) {
                    if(lines[i] == name) {
                        std::cout << lines[i] << "\n" << lines[i+1] << "\n" << lines[i+2] << "\n";
                        break;
                    }
                    std::cout << "Unable to find that contact\n";
                }
            } else if(option == "email") {
                std::string email;
                std::cout << "Enter the email to be searched > ";
                std::cin.ignore();
                std::getline(std::cin, email);
                
                // skip every 4 lines to get email of contact
                for(int i = 1; i < lines.size(); i += 4) {
                    if(lines[i] == email) {
                        std::cout << lines[i-1] << "\n" << lines[i] << "\n" << lines[i+1] << "\n";
                        break;
                    }
                    std::cout << "Unable to find that contact\n";
                }
            } else if(option == "phone") {
                std::string phone;
                std::cout << "Enter the phone number to be searched > ";
                std::cin.ignore();
                std::getline(std::cin, phone);
                
                // skip every 4 lines to get phone of contact
                for(int i = 2; i < lines.size(); i += 4) {
                    if(lines[i] == phone) {
                        std::cout << lines[i-2] << "\n" << lines[i-1] << "\n" << lines[i] << "\n";
                        break;
                    }
                    std::cout << "Unable to find that contact\n";
                }
            }
        }
    }
}