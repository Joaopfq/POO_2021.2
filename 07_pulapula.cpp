#include <iostream>
#include <memory>
#include <list>
#include <utility>

class Crianca{
    std::string nome;
    int idade;
public: 
    Crianca(std::string nome = "", int idade = 0): nome(nome), idade(idade) {}

    std::string pegarNome() {
        return this->nome;
    }

    int pegarIdade() {
        return this->idade;
    }

    friend std::ostream& operator<<(std::ostream& os, const Crianca& c) {
        os << c.nome << ":" << c.idade;
        return os;
    }
};

class Pulapula {
    std::list <std::shared_ptr<Crianca>> fila;
    std::list <std::shared_ptr<Crianca>> pulapula;
public:

    void chegar(std::shared_ptr<Crianca> crianca){
        this->fila.push_back(crianca);
    }

    void entrar(){
        if(this->pulapula.size() < 4) {
            if(this->fila.size() > 0) {
                auto crianca = this->fila.front();
                this->pulapula.push_back(crianca);
                this->fila.pop_back();
            }
            else {
                std::cout << "Nao tem ninguem na fila!" << std::endl;
            }
        }   
        else {
            std::cout << "O pula-pula ta cheio!" << std::endl;
        }
    }

    void sair(){
        if(this->pulapula.size() > 0) {
            this->fila.push_back(this->pulapula.front());
            this->pulapula.pop_front();
        }
        else {
            std::cout << "Nao tem ninguem no pula-pula" << std::endl;
        }

    }

    std::list <std::shared_ptr<Crianca>>::iterator procurarCrianca(std::string nome, std::list <std::shared_ptr<Crianca>> lista){
        for(auto it = lista.begin(); it != lista.end(); it++){
            if((*it)->pegarNome() == nome){
                return it;
            }
        }
        return lista.end();
    }

    void papaiChegou(std:: string nome){
        auto c_pulapula = this->procurarCrianca(nome, this->pulapula);
        auto c_fila = this->procurarCrianca(nome, this->fila);

        if(c_pulapula != this-> pulapula.end()){
            this->pulapula.erase(c_pulapula);
            
        } else if(c_fila != this-> fila.end()){
            this->fila.erase(c_fila);
        }
     }

};

Pulapula pula;

int main(){
    while(true){
        int x{};
        std::cin >> x;
        if(x == 1){
            pula.chegar(std::make_shared<Crianca>("pedrinho", 9));
            pula.chegar(std::make_shared<Crianca>("rosa", 11));
            pula.chegar(std::make_shared<Crianca>("pablo", 12));
            pula.chegar(std::make_shared<Crianca>("joao", 7));
        } else if(x == 2){
            pula.entrar();
        } else if (x == 3){
            pula.sair();
        } else if (x == 4){
            pula.papaiChegou("pedrinho");
        } else {
            std::cout << "Comando invalido" << std::endl;
        }
    }
}