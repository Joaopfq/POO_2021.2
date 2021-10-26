#include <iostream>
#include <algorithm>
#include <sstream>

struct Person {
    std::string name;
    int age;

    Person(std::string name = "", int age = 0) {
        this->name = name;
        this->age = age;
    }
};

struct Moto {
    int time {0};
    int power {1};
    Person* child = nullptr; 
    Moto(int pow) : power{pow} {
    }

    bool subir(Person* x) {
        if(this->child != nullptr) {
            std::cout << "A moto ta ocupada!\n";
            return false;
        }
        this->child = x;
        std::cout << "A crianca subiu na moto!\n";
        return true;
    }

    Person* descer() {
        if(this->child == nullptr ) {
            std::cout << "A moto ta livre!\n";
            return nullptr;
        }
        std::cout << "A crianca desceu da moto!\n";
        return std::exchange(this->child, nullptr);
    }

    std::string buzinar() {
        return 'p' + std::string(this->power, 'e') + 'm' ;
    }

    std::string buzinar_alto() {
        return 'p' + std::string(this->power, 'e') + std::string(5, 'e') + 'm' ;
    }

    void more_time(int time) {
        this->time++;
    }

    bool drive(int time) {
        if(this->child == nullptr) {
            std::cout << "A moto ta vazia!\n";
            return false;
        } else if(time > 0) {
            std::cout << "Dirigiu por " << time << " minuto(s)\n"; 
            return true;
        }
        std::cout << "Seu tempo acabou " << this->child->name << "! Compre mais para continuar!\n";
        return false;
    }
};

int main() {

    Moto a(1);

    while(true) {
        std::string line;
        std::getline(std::cin, line);
        std::stringstream ss(line);
        std::string cmd;
        ss >> cmd;
        if (cmd == "encerrar") {
            break;
        } else if (cmd == "dirigir") {           
            a.drive(a.time);
        } else if (cmd == "buzinar") {
            std::cout << a.buzinar() << std::endl;
        } else if (cmd == "buzinar+") {
            std::cout << a.buzinar_alto() << std::endl;
        } else if (cmd == "comprar") {
            a.more_time(a.time);
        } else if (cmd == "subir") {
            std::string name;
            int age;
            std::cin >> name >> age;
            Person* child = new Person(name, age);          
            a.subir(child);
        } else if (cmd == "descer") {
            Person* child = a.descer();
            if(child != nullptr)
                delete child;
        } else {
            std::cout << "Comando nao existe" << std::endl;
        }
    }
    
    return 0;
}