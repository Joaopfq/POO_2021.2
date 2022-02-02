#pragma once

#include <iostream>
#include <map>

using namespace std;

class Medico;

class Paciente{
protected:

    string sender;
    string diagnostico;
    map<string, Medico*> medicos;

public:

    Paciente(string sender, string diagnostico){
        this->sender = sender;
        this->diagnostico = diagnostico;
    }

    string getId();
    
    void addMedico(Medico* medico);

    void removerMedico(string idMedico);

    map<string, Medico*> getMedicos();

    string getDiagnostico();

    string toString();
};