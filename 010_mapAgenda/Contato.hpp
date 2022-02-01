#include "Fone.hpp"
#include <unordered_map>

using namespace std;

class Contato
{
    string name;
    unordered_map<string, Fone> fones;
    protected:string prefix = "-";

public:
    Contato(unordered_map<string, Fone> fones, string name = "") {
        this->fones = fones;
        this->name = name;
    }

    void addFone(Fone fone, string id){
        if(fone.validate(fone.getNumber())){
            this->fones.insert({id, fone});
        }
    }

    void rmFone(string index){
        auto it = fones.find(index);
            if (it == fones.end()) {
                cout << "Fone nao encontrado!" << endl;
            } else {
                fones.erase(it);
                cout << "Fone removido!" << endl;
            }
    }

    string toString(){
        string str;
        for(auto& par : this->fones){
            int i = 0;
            str = " [" + to_string(i) + ":" + par.first + par.second.toString() + "] ";
            i++;
        }
        return  this->prefix + this->name + str;
    }

    string getName(){
        return this->name;
    }

    void setName(string name){
        this->name = name;
    }

    unordered_map<string, Fone> getFones(){
        return this->fones;
    }

};