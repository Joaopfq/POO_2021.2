#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Fone
{
    string id;
    string number;
public:
    Fone(string id = "", string number = "") {
        this->id = id;
        this->number = number;
        
    }

    static bool validate(string number) {
        if(number.find_first_not_of("0123456789") != string::npos){
            cout << "Erro, numero invalido!" << endl;
            return false;
        }
        return true;
    }

    string toString(){
        return this->id + ":" + this->number;
    }

    string getId(){
        return this->id;
    }

    void setId(string id){
        this->id = id;
    }

    string getNumber(){
        return this->number;
    }

    void setNumber(string number){
        this->number = number;
    }


};