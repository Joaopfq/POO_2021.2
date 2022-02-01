#include "Fone.hpp"

using namespace std;

class Contato
{
    string name;
    vector<Fone> fones;
    protected:string prefix = "-";

public:
    Contato(vector<Fone> fones, string name = "") {
        this->fones = fones;
        this->name = name;
    }

    void addFone(Fone fone){
        if(fone.validate(fone.getNumber())){
            this->fones.push_back(fone);
        }
    }

    void rmFone(int index){
        for(int i = 0; i < (int)fones.size(); i++){
            if(i == index){
                this->fones.erase(fones.begin() + index);
            }
        }
    }

    string toString(){
        string str;
        for(int i = 0; i < (int)fones.size(); i++){
            str = " [" + to_string(i) + ":" + this->fones[i].toString() + "] ";
        }
        return  this->prefix + this->name + str;
    }

    string getName(){
        return this->name;
    }

    void setName(string name){
        this->name = name;
    }

    vector<Fone> getFones(){
        return this->fones;
    }

};