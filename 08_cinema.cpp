#include <iostream>
#include <memory>
#include <vector>
#include <sstream>

class Cliente{
    std::string telefone;
    std::string id;
public:
    Cliente(std::string telefone = "", std::string id = "") : telefone(telefone), id(id) {}

    std::string toString() {
        return this->id + ":" + this->telefone;
    }

    std::string pegarTelefone() {
        return this->telefone;
    }

    std::string pegarId() {
        return this->id;
    }

    void defineTelefone(std::string telefone) {
        this->telefone = telefone;
    }

    void defineId(std::string id) {
        this->id = id;
    }
};

class Sala{
    std::vector<std::shared_ptr<Cliente>> cadeiras;
public:
    Sala(int capacidade) : cadeiras (capacidade, nullptr) {}

    std::string toString(){
        std::stringstream ss;
        ss << "[ ";
        for (size_t i = 0; i < this->cadeiras.size(); i++) {
            if (this->cadeiras[i] == nullptr) {
                ss << "- ";
            } else {
                ss << this->cadeiras[i]->toString() << " ";
            }
        }
        ss << "]";
        return ss.str();
    }

    std::vector<std::shared_ptr<Cliente>> pegarCadeiras(){
        return this->cadeiras;
    }

    void cancelar(std::string id) {
        for (size_t i = 0; i < this->cadeiras.size(); i++){
            if (id == this->cadeiras[i]->pegarId() && this->cadeiras[i] != nullptr) {
                this->cadeiras[i] = nullptr;
                std::cout << "Reserva cancelada" << std::endl;
                break;
            } 
        }
    }

    bool reservar(std::string id, std::string telefone, int ind){
        if (this->cadeiras[ind] != nullptr || ind >= this->cadeiras.size()) {
            std::cout << "Nao foi possivel reservar" << std::endl;
            return false;
        }
        this->cadeiras[ind] = std::make_shared<Cliente>(telefone, id);
        return true;
    }

};

Sala cinema(5);

int main(){
    while(true){
        int x{};
        std::cin >> x;
        if(x == 1){
            cinema.reservar("Pedro", "3232", 0);
            cinema.reservar("Joao", "3233", 1);
            cinema.reservar("Jose", "3234", 1);
            cinema.reservar("Julia", "3235", 3);
            cinema.reservar("Victor", "3236", 4);
            std::cout <<  cinema.toString() << std::endl;
        } else if(x == 2){
            std::string id;
            std::cin >> id;
            cinema.cancelar(id);
            std::cout << cinema.toString() << std::endl;
        } 
    }
}