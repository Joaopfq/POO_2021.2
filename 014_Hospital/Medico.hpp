#pragma once

#include <iostream>
#include "Paciente.hpp"
#include <map>


using namespace std;

class Medico{

    string sender;
    string classe;
    map<string, Paciente*> pacientes;

public:
    Medico(string sender, string classe){
        this->sender = sender;
        this->classe = classe;
    }

    string getId(){
        return this->sender;
    }

    void addPaciente(Paciente* paciente){
        
        this->pacientes.insert({paciente->getId(), paciente});
    }

    void removerPaciente(string idPaciente){
        this->pacientes.erase(idPaciente);
    }

    map<string, Paciente*> getPacientes(){
        return this->pacientes;
    };

    string getClasse(){
        return this->classe;
    }
    string toString(){
        string str = "Pacientes:\n";

        for(auto paciente : this->pacientes){
            str = str + "\t[" + paciente.second->getId() + "|" + paciente.second->getDiagnostico() + "]\n";
        }

        return str;
    }
};