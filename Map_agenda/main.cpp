#include "Contato.hpp"
#include <sstream>

int main(){

    unordered_map<string, Fone> fones;
    Contato contato(fones, "Marquin");

    while(true) {
        std::string line;
        std::getline(std::cin, line);
        std::stringstream ss(line);
        std::string cmd;
        ss >> cmd;
        if (cmd == "end") {
            break;
        } else if (cmd == "add") {
            Fone fone;
            contato.addFone(fone, "0");
        } else if (cmd == "rm") {
            contato.rmFone("0");
        } else if (cmd == "show") {
            cout << contato.toString() << endl;
        } else {
            std::cout << "Comando nao existe" << std::endl;
        }
    }
}