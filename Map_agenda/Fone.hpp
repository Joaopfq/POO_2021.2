#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Fone
{
    string number;
public:
    Fone( string number = "") {
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
        return ":" + this->number;
    }

    string getNumber(){
        return this->number;
    }

    void setNumber(string number){
        this->number = number;
    }
};