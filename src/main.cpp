#include <iostream>
#include <sstream>

int print_menu() {
    int option;
    std::cout << "1. ascii to string\n";
    std::cout << "2. string to ascii\n";
    std::cout << "option: ";
    std::cin >> option;
    return option;
}

std::string ascii_to_string(const std::string& input) {
    std::istringstream iss(input);
    
    // IF IT WORKS, DONT TOUCH IT!
    std::string retval;
    int ascii;
    while(iss >> ascii) {
        retval += ascii;
    }
    
    return retval;
}

std::string string_to_ascii(const std::string& input) {
    std::stringstream retval;

    for(const auto& ch : input) {
        retval << static_cast<int>(ch) << " ";
    }

    return retval.str();
}

int main() {
    int option = print_menu();

    switch(option) {
        case 1: {
            std::cout << "input: ";
            std::string input;
            std::getline(std::cin >> std::ws, input);
            std::cout << "output: " << ascii_to_string(input) << "\n";
            break;
        }
        case 2: {
            std::cout << "input: ";
            std::string input;
            std::getline(std::cin >> std::ws, input);
            std::cout << "output: " << string_to_ascii(input) << "\n";
            break;
        }
        default: {
            std::cout << "No such option as \"" << option << "\".";
            break;
        }
    }
    return 0;
}