#include "Paciente.hpp"
#include "Medico.hpp"
#include "Hospital.hpp"
#include <sstream>

string Paciente::getId(){
    return this->sender;
}

void Paciente::addMedico(Medico* medico){
    this->medicos.insert({medico->getId(), medico});
}

void Paciente::removerMedico(string idMedico){
    this->medicos.erase(idMedico);
}

map<string, Medico*> Paciente::getMedicos(){
    return this->medicos;
}

string Paciente::getDiagnostico(){
    return this->diagnostico;
}

string Paciente::toString(){
    string str = "Medicos:\n";

    for(auto medico : medicos){
        str = str + "\t[" + medico.second->getId() + ", " + medico.second->getClasse() + "]\n";
    }

    return str;
}


Hospital hospital;
Paciente yoo("yoo", "covid");
Medico hansuke("hansuke", "neuro");

int main(){
    while(true) {
        std::string line;
        std::getline(std::cin, line);
        std::stringstream ss(line);
        std::string cmd;
        ss >> cmd;
        if (cmd == "end") {
            break;
        } else if (cmd == "addMed") {
            hospital.addMedico(&hansuke);
            
        } else if (cmd == "addPac") {
            hospital.addPaciente(&yoo);
            
        } else if (cmd == "Vinc") {
            hospital.vincular(hansuke.getId(), yoo.getId());
            
        } else if (cmd == "rmMed") {
            hospital.removerMedico(hansuke.getId());

        } else if (cmd == "rmPac") {
            hospital.removerPaciente(yoo.getId());
            
        } else if (cmd == "show") {
            cout << hospital.toString() << endl;
      
        } else if (cmd == "showP") {
            cout << hansuke.toString() << endl;
      
        } else if (cmd == "showM") {
            cout << yoo.toString() << endl;
      
        } else {
            cout << "Comando nao existe" << endl;
        }
    }
}