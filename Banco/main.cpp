#include <iostream>
#include <sstream>
#include "BankAgency.hpp"



BankAgency bank;

int main(){

    while(true) {
        std::string line;
        std::getline(std::cin, line);
        std::stringstream ss(line);
        std::string cmd;
        ss >> cmd;
        if (cmd == "end") {
            break;
        } else if (cmd == "add") {
            bank.addClient("Joao");
            bank.addClient("Pedro");
        } else if (cmd == "show") {
            cout << bank.toString();
        } else {
            std::cout << "Comando nao existe" << std::endl;
        }
    }
}