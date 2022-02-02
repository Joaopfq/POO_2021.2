#pragma once

#include "Medico.hpp"
#include "Paciente.hpp"

using namespace std;

class Hospital{
private:
    map<string, Paciente*> pacientes;
    map<string, Medico*> medicos;

public:
    Hospital(){

    }

    void removerPaciente(string sender){
        this->pacientes.erase(sender);
    }

    void removerMedico(string sender){
        this->medicos.erase(sender);
    }

    void addPaciente(Paciente* paciente){
        this->pacientes.insert({paciente->getId(), paciente});
    }

    void addMedico(Medico* medico){
        this->medicos.insert({medico->getId(), medico});
    }
    void vincular(string nomeMedico, string nomePaciente){
        auto medico = this->medicos.find(nomeMedico);
        auto paciente = this->pacientes.find(nomePaciente);
        medico->second->addPaciente(paciente->second);
        paciente->second->addMedico(medico->second);
    }
    
    string toString(){
        string str = "Medicos:\n";

        for(auto medico : this->medicos){
            str = str + "\t[" + medico.second->getId() + "|" + medico.second->getClasse() + ",";
        }

        str = str + "]\nPacientes:\n";

        for(auto paciente : this->pacientes){
            str = str + "\t[" + paciente.second->getId() + "]\n";
        }

        return str;
    }
};