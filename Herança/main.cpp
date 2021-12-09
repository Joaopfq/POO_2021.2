#include "Person.hpp"
#include <sstream>

int main(){ 
    Person pessoa(50, "Ze", "mamifero", "Animalia");

    while(true) {
        std::string line;
        std::getline(std::cin, line);
        std::stringstream ss(line);
        std::string cmd;
        ss >> cmd;
        if (cmd == "end") {
            break;
        } else if (cmd == "work") {
            pessoa.work();
        } else if (cmd == "kill") {
            pessoa.kill();
        } else if (cmd == "show") {
            cout << pessoa.toString() << endl;
        } else if (cmd == "play") {
            pessoa.play();
        } else if (cmd == "rest") {
            pessoa.rest();
        } else {
            std::cout << "Comando nao existe" << std::endl;
        }
    }
}