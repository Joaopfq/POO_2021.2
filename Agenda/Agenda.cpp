#include "Contato.hpp"
#include <sstream>

using namespace std;

class Agenda {
    vector<Contato> contatos;

    int findPos(string name){
        for(int i = 0; i < (int)contatos.size(); i++){
            if(this->contatos[i].getName() == name){
                return i;
            }
        }
        return -1;
    }
public:
    Agenda() {}

    Contato* getContato(string name){
        for(int i = 0; i < (int)contatos.size(); i++){
            if(findPos(name) >= 0){
                return &contatos[i];
            }
        }
        return NULL; 
    }

    void addContato(Contato contato){

        if (findPos(contato.getName()) <= 0) {
            this->contatos.push_back(contato);
        }
    }

    void rmContato(string name){
        if (int pos = findPos(name) >= 0) {
            this->contatos.erase(contatos.begin() + pos);
        } else {
            cout << "Erro, contato não existe!" << endl;
        }
    }

    vector<Contato> search(string pattern){
        vector<Contato> aux;
        for(int i = 0; i < (int)contatos.size(); i++){
            string str = contatos[i].toString();
            if(str.find(pattern) != string::npos){
                aux.push_back(contatos[i]);
            }
        }
        return aux;
    }

    vector<Contato> getContatos(){
        return this->contatos;
    }

    string toString(){
        string str;
        for(int i = 0; i < (int)contatos.size(); i++){
            str = contatos[i].toString();
        }
        return str + '\n';
    }
};

int main(){

    Agenda agenda;
    vector<Fone> fones;

    while(true) {
        std::string line;
        std::getline(std::cin, line);
        std::stringstream ss(line);
        std::string cmd;
        ss >> cmd;
        if (cmd == "encerrar") {
            break;
        } else if (cmd == "add") {
            Contato contato(fones,"pedro");
            agenda.addContato(contato);
        } else if (cmd == "rm") {
            agenda.rmContato("pedr");
        } else if (cmd == "show") {
            cout << agenda.toString() << endl;
        } else {
            std::cout << "Comando nao existe" << std::endl;
        }
    }
    return 0;
}
